#pragma once

#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <assert.h>
using namespace std;


void clearup_the_string(string& s);
class ContextResults
{
private:
	vector<pair<string, int>> _sen;//��ָ�� -- ���⿽��
	string _word;//Ŀ�굥��
	set<size_t>_lines_number;//���ֵ��к�
	size_t _times;//��������ȫ�ĵĳ��ִ���
public:
	friend ostream& print(ostream& out, const ContextResults& cr);
	friend ostream& print_every_sentence(ostream& out, const ContextResults& cr);
public:
	ContextResults(vector<pair<string, int>> arr, string word, set<size_t>lines_number, size_t times)
		:_sen(arr), _word(word), _lines_number(lines_number), _times(times)
	{}
	ContextResults(const ContextResults& cr) = default;
	~ContextResults() = default;
};
vector<string> get_context(const string& arr, const string& target);
ostream& print(ostream& out, const ContextResults& cr);
ostream& print_every_sentence(ostream& out, const ContextResults& cr);

class FileQuery
{
private:
	void processing_sentences(string& s, int num);
	//Ϊ������������ӡʱ���Ը��øú��� -- ��װ��һ��	__print_sentences()
	void __print_sentences(vector<pair<string, int>>& print_arr);
	void __init_hash_table(string& s, size_t line_num);
	void __init_heap();
	void __replace_word(string& s, const string& oldStr, const string& newStr);
	void __update_vector(const string& oldStr, const string& newStr);
	inline static bool sort_cmp(const pair<string, int>& e1, const pair<string, int>& e2)
	{
		return e1.first < e2.first;
	}
public:
	FileQuery(ifstream& input_file);
	~FileQuery();
	FileQuery(const FileQuery& fq); //�����������
	//��ӡ���еľ���
	void print_sentences();
	//�������ӡ���еľ���
	void print_sentences_ascend();
	//��ӡÿ�����ʳ��ֵĴ���
	void print_word_count();
	//��ӡ��Ƶ��ߵ�n�����ʣ���ÿ�����ʴ�ӡ���иõ��ʳ��ֵ�������
	void print_top_world_context(int n);
	//���Ұ����õ��ʵľ��ӣ���ӡ����
	void Find(const string& str);
	//�����е���old�滻��new�����Խ��������3������
	void Replace(const string& oldstr, const string& newstr);
private:
	//���ȶ�����Ҫ�ķº���
	struct cmp
	{
		inline bool operator()(const pair<string, multiset<size_t>*>& e1, 
			const pair<string, multiset<size_t>*>& e2) const
		{
			return e1.second->size() < e2.second->size();
		}
	};
private:
	vector<string>sentences_;//������о���
	vector<pair<string,int>>_sentences;//��ž��Ӻ����Ӧ���к� -- ����ĿҪ�� -- ������Ӷ���һ��vector<string>sentences_
	//��Ϊһ�����ʿ���һ�г��ֶ�� -- ����ʹ��multiset
	unordered_map<string, multiset<size_t>*>__hash_map;//use hash_table to save lines number
	//�ù�ϣ������ò��� -- O(1)
	priority_queue<pair<string, multiset<size_t>*>, 
		deque<pair<string, multiset<size_t>*>>, cmp> __string_heap;
	//�ö� -- ������topK����
};

/**
 * ʵ��һ����FileQuery��ӵ��˽�г�Աstd::vector<std::string> sentences_��ʵ�����¹���.
 * ��ȡһ��ָ���ı��ļ�poem.txt������¼���ı�������poem.txt��
 */