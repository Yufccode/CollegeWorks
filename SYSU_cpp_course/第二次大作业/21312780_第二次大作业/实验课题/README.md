

## FileQueryʵ��˼·

## �ص�
	�ù�ϣ��洢������Ϣ -- ����֧�ֿ��ٶ�β���
	�ص��Ż��˲��ҵ�Ч��
	�����ȶ��д洢������Ϣ -- ֧�ֿ��ٽ��topK����

### ϵͳ���
`vector<pair<string,int>>_sentences;`
	ʹ��vector��������о��ӣ����˳�����������
	����pair<string,int>
	string��ŵ��Ǿ���
	int��ŵ��Ǹþ������ڵ��к�

`unordered_map<string, multiset<size_t>*>__hash_map`;
	�ù�ϣ�������о��Ӻ����о����кŵļ��ϣ�����һ���п��ܴ�����ͬ�ĵ��ʣ����Կ���ʹ��multiset������set����ʱmultiset->size()���ǵ��ʳ��ֵĴ���
	���ù�ϣ������ò��Ҹ��ӶȽ�ΪO(1)
`priority_queue<pair<string, multiset<size_t>*>, deque<pair<string, multiset<size_t>*>>, cmp> __string_heap;`
	ʹ��һ�����ȶ��д��`pair<string, multiset<size_t>*`
	���Խ���topK�����ʱ�临�Ӷ�

## ����ӿ�
### print_sentences()�ӿ�
	ֱ�Ӵ�ӡ_sentences����Ϣ����
### print_sentences_ascend()�ӿ�
	����һ����ʱ����sort_v�����ṩһ���º���sort_cmp������std::sort����
	������ӡ��Ϣ
### print_word_count()
	����__hash_mapֱ�Ӵ�ӡ����
### print_top_world_context()
	����һ����ʱ����tmpΪ__string_heap�Ŀ��� -- ���Ӷ�ΪO(n) nΪ���ʸ���
	��tmp����3��pop()���� -- ���Ӷ�ΪO(logn)
	����ÿ��top()�õ��Ľṹ �ֱ���ContextResults������д�ӡ
### Find()
	��ϣ����� -- O(1)
	�ҵ��Ľ������ContextResults������д�ӡ
### Replace()
	��ϣ����� -- O(1)
	�ҵ���ֱ�ӶԹ�ϣ��erase��insert
	Ȼ�����³�ʼ��__string_heap��__hash_map���ֱ����__init_heap()��__update_vector()�ӿڣ�

## ���ڽӿں�����
### struct cmp{};
	���ȶ�������Ҫ�ķº���
### processing_sentences()
	�и�ÿһ�е��ַ��� -- �Ѿ����г����ŵ�vector����
### __print_sentences()
	��ӡ������Ϣ
### __init_hash_table()
	��ʼ����ϣ��
	�þ��ӹ���istringstream���� -- �и��ÿ�����ʼ���
### __init_heap()
	��ʼ�����ȶ���
	�ýӿڲ�ֹ�ǹ��캯��ʱ���� -- ���һ��ʼҪ��Ҫ��յ�ǰ��
### __replace_word()
	�Ѿ����еĵ��������滻
	ͨ������istringstream�����и�����ʼ���
### __update_vector()
	Replace�ӿ�ʱҪ���õĽӿ�
	ѭ����vector<>������ַ����ֱ����__replace_word()��������

## ContextResults��
### ������
	vector<pair<string, int>> _sen; ʹ��vector��������о��ӣ����˳�����������
	string _word;//Ŀ�굥��
	set<size_t>_lines_number;//���ֵ��к�
	size_t _times;//��������ȫ�ĵĳ��ִ���

## �����ӿ�
### clearup_the_string()
	���ַ������б���������˳�
### print()
	��ӡ�����ģ�ͨ������get_context()��������ĵĵ���
### print_every_sentence()
	��ӡһ��������
### get_context()
	���һ�����ʵ�������