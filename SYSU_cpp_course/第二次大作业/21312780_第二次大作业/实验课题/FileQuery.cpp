
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif

#include"FileQuery.h"



//�����ӿ�
void clearup_the_string(string& s)
{
	size_t i = 0;
	while (s[i] == ' ')i++;
	string tmp;
	for (; i < s.size(); i++)
	{
		if (ispunct(s[i]))continue;
		tmp += tolower(s[i]);
	}
	s = tmp;//��tmp����s
}
vector<string> get_context(const string& arr, const string& target)
{
	//Ŀ�꣺
	//��arr���string����ȡtarget��������
	vector<string>ret(3);//Ҫ���ص�������
	istringstream line(arr);
	string word;
	vector<string>words;
	while (line >> word)
	{
		words.push_back(word);
	}
	auto it = find(words.begin(), words.end(), target);
	if (it == words.end())return ret;
	if (words.size() > 1)
	{
		if (it == words.begin())
		{
			ret[0] = "";
			ret[1] = *it;
			ret[2] = *(it + 1);
		}
		else if (it == words.end() - 1)
		{
			ret[0] = *(it - 1);
			ret[1] = *it;
			ret[2] = "";
		}
		else
		{
			ret[0] = *(it - 1);
			ret[1] = *it;
			ret[2] = *(it + 1);
		}
	}
	//����þ���ֻ��һ�����ʣ��Ҹõ��ʾ���target��ֻ����һ������
	else if (word.size() == 1)
	{
		ret[0] = "";
		ret[1] = *it;
		ret[2] = "";
	}
	return ret;
}
ostream& print(ostream& out, const ContextResults& cr)
{
	cout << cr._word << endl;//��ӡ�õ���
	cout << "occurances:" << cr._times << endl;//��ӡ���ִ���
	for (auto e : cr._lines_number)
	{
		//��e��һ������������Ҫ�ľ���
		//cr._sen;��cr._sen��������к� = e�ľ���
		for (size_t i = 0; i < cr._sen.size(); i++)
		{
			if (cr._sen[i].second == e)
			{
				vector<string>ret = get_context(cr._sen[i].first, cr._word);
				if (ret[0].size() == 0 && ret[1].size() == 0 && ret[2].size() == 0)continue;
				cout << "  " << "(line:" << e << ")" << ret[0] << " " << ret[1] << " " << ret[2] << endl;
			}
		}
	}
	return out;
}
ostream& print_every_sentence(ostream& out, const ContextResults& cr)
{
	cout << cr._word << endl;
	cout << "occurance:" << cr._times << endl;
	for (auto& e : cr._lines_number)
	{
		//e : �к�
		for (size_t i = 0; i < cr._sen.size(); i++)
		{
			if (cr._sen[i].second == e)
			{
				//��ӡ�þ���
				cout << "  " << "(line:" << e << ")" << cr._sen[i].first << endl;
			}
		}
	}
	return out;
}



//�ڲ��ӿ�
void FileQuery::processing_sentences(string& s, int num)
{
	//����˫ָ��ָ����еľ���
	int slow = 0;
	int fast = 0;
	while (fast < s.size())
	{
		while (fast < s.size() && (s[fast] != ',' && s[fast] != '.'))
		{
			fast++;
		}
		//��ʱ��[slow,fast)֮����ַ�push��vector���� -- ͬʱ��ʼ����ϣ��
		string tmp(s.begin() + slow, s.begin() + fast);
		clearup_the_string(tmp);
		this->_sentences.push_back({ tmp,num });
		this->sentences_.push_back(tmp);
		fast++;
		slow = fast;
	}
}
void FileQuery::__print_sentences(vector<pair<string, int>>& print_arr)
{
	for (auto& e : print_arr)
	{
		cout << "(line:" << e.second << ") " << e.first << endl;
	}
}
void FileQuery::__init_hash_table(string& s, size_t line_num)
{
	istringstream line(s);
	string word;
	while (line >> word)
	{
		clearup_the_string(word);//����һ�������ַ���
		auto& lines = this->__hash_map[word];
		if (!lines)
		{
			//��һ���µ�set
			lines = new multiset<size_t>;
		}
		lines->insert(line_num);
	}
}
void FileQuery::__init_heap()
{
	//��������ȶ���
	while (!this->__string_heap.empty())
	{
		__string_heap.pop();
	}
	assert(__string_heap.size() == 0);
	//������ϣ��
	for (auto e : this->__hash_map)
	{
		//e : {string, multiset<size_t>*}
		//priority_queue<pair<string, multiset<size_t>*>, deque<pair<string, multiset<size_t>*>>, cmp()>
		//cout << typeid(e).name() << endl;
		this->__string_heap.push(e);
	}
}
void FileQuery::__replace_word(string& s, const string& oldStr, const string& newStr)
{
	vector<string>words;
	istringstream lines(s);
	string word;
	while (lines >> word)
	{
		words.push_back(word);
	}
	//�滻
	for (auto& e : words)
	{
		if (e == oldStr)e = newStr;
	}
	s.clear();
	for (auto& e : words)
	{
		s += e;
		s += ' ';
	}
}
void FileQuery::__update_vector(const string& oldStr, const string& newStr)
{
	for (size_t i = 0; i < _sentences.size(); i++)
	{
		__replace_word(sentences_[i], oldStr, newStr);
		__replace_word(_sentences[i].first, oldStr, newStr);
	}
}
FileQuery::FileQuery(ifstream& input_file)
{
	string tmp_sentence;
	size_t curent_line_num = 1;//���кż�¼һ��
	while (getline(input_file, tmp_sentence))
	{
		//�ָ�����о���
		processing_sentences(tmp_sentence, curent_line_num);//vector procesing
		//��ʱvector�Ѿ���ʼ������ -- ����Ҫ��ʼ����ϣ��
		__init_hash_table(tmp_sentence, curent_line_num);
		curent_line_num++;//�к�++
	}
	__init_heap();
}
FileQuery::~FileQuery()
{
	//ֻ��__hash_map��second����Ҫ�Լ�����
	for (auto& e : __hash_map)
	{
		auto ptr = e.second;
		delete ptr;
	}
}
FileQuery::FileQuery(const FileQuery& fq)
{
	unordered_map<string, multiset<size_t>*>tmp_hash_table;
	priority_queue<pair<string, multiset<size_t>*>, deque<pair<string, multiset<size_t>*>>, cmp> tmp_heap;
	this->_sentences = fq._sentences;//����std::vector�Ŀ�������
	for (auto e : fq.__hash_map)
	{
		auto ptr_tmp = e.second;
		auto new_ptr = new multiset<size_t>(*(e.second));
		tmp_hash_table.insert({ e.first,new_ptr });//����ϣ������µ�ָ��
		tmp_heap.push({ e.first,new_ptr });//�����ȶ��в����µ�pair
	}
	//��ֵ
	this->__hash_map = tmp_hash_table;
	this->__string_heap = tmp_heap;
}
void FileQuery::print_sentences()
{
	cout << "��ӡ���еľ���" << endl;
	__print_sentences(this->_sentences);
}
void FileQuery::print_sentences_ascend()
{
	cout << "�������ӡ���еľ���" << endl;
	vector<pair<string, int>>sort_v = this->_sentences;
	sort(sort_v.begin(), sort_v.end(), sort_cmp);
	this->__print_sentences(sort_v);
}
void FileQuery::print_word_count()
{
	//��ӡ���ʳ��ֵĴ���
	//������ϣ����
	cout << "��ӡÿ�����ʳ��ֵĴ���" << endl;
	for (auto e : this->__hash_map)
	{
		cout << e.first << ":" << e.second->size() << endl;
	}
}
void FileQuery::print_top_world_context(int n)
{
	//��ӡ���Ƶ��n������
	auto tmp = this->__string_heap;//����һ���� -- O(n)
	//priority_queue<pair<string, multiset<size_t>*>, deque<pair<string, multiset<size_t>*>>, cmp>
	//cout << typeid(tmp).name() << endl;
	//cout << endl;
	//�Ȱ�ǰn����Ƶ����ȡ����
	vector<pair<string, multiset<size_t>*>>res_arr;
	for (size_t i = 0; i < n; i++)
	{
		res_arr.push_back(tmp.top());
		tmp.pop();
	}
	for (size_t i = 0; i < res_arr.size(); i++)
	{
		//���к���ȡһ��
		set<size_t>num_arr;
		multiset<size_t>::iterator it = res_arr[i].second->begin();
		while (it != res_arr[i].second->end())
		{
			num_arr.insert(*it);
			it++;
		}
		ContextResults cr(_sentences, res_arr[i].first, num_arr, res_arr[i].second->size());
		print(cout, cr) << endl;
	}
}
void FileQuery::Find(const string& str)
{
	//�ڹ�ϣ���в��� -- ���Ӷ�ΪO(1)
	auto it = __hash_map.find(str);
	if (it == __hash_map.end())
	{
		//�Ҳ����õ���
		cerr << "�Ҳ����õ���" << endl;
		return;
	}
	//�ҵ��� *it  -- pair<string,multiset<size_t>*>
	set<size_t>lines_number(it->second->begin(), it->second->end());//���к�ȥ��һ��
	ContextResults cr(this->_sentences, it->first, lines_number, it->second->size());
	print_every_sentence(cout, cr);
}
void FileQuery::Replace(const string& oldstr, const string& newstr)
{
	bool flag = false;//�Ƿ����滻
	//�ڹ�ϣ���в��� -- ���Ӷ�ΪO(1)
	auto it = __hash_map.find(oldstr);
	if (it == __hash_map.end())
	{
		cout << "�Ҳ����õ��ʣ��޷��滻��" << endl;
		return;
	}
	auto ptr = __hash_map[oldstr];
	__hash_map.erase(oldstr);
	__hash_map.insert({ newstr,ptr });//���µĵ������²����ϣ��
	//�ѵ㣺���ڻ�Ҫά�����ȶ��кʹ���ӵ�vector
	__init_heap();//���޶������µ���һ�³�ʼ�������ˣ��ǵ���__init_heap������clear()һ��
	__update_vector(oldstr, newstr);
	cout << "�滻�ɹ�!" << endl;
}