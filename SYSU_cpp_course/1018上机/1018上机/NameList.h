#pragma once


#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;

//���ԸĽ��ĵط�
//���ض�㶫��

class NameList {
public:
	NameList() {} //�Զ������ͻ�ȥ�����Լ��Ĺ��죬�������ǲ���д
	~NameList() {}//ͬ������д
	NameList(const NameList& nl) {
		this->_names = nl._names;
	}
	NameList& operator=(const NameList& nl) {
		this->_names = nl._names;
		return *this;
	}
	void addName(const string& s) {
		this->_names.push_back(s);
	}
	void deleteName(const string& s) {
		vector<string>::iterator pos = find(_names.begin(), _names.end(), s);
		if (pos == _names.end()) {
			cout << "�Ҳ���������" << endl;
			return;
		}
		_names.erase(pos);//��Ҫ��ʹ��pos -- ע�������ʧЧ
	}
	vector<string>search(const string& sub) {
		vector<string>ret;
		for (int i = 0; i < this->_names.size(); i++) {
			if (_names[i].find(sub) != _names[i].npos) {
				ret.push_back(this->_names[i]);
			}
		}
		return ret;
	}
	void print_arr(vector<string>& arr) {
		vector<string>::iterator it = arr.begin();
		while (it != arr.end()) {
			cout << *it << endl;
			it++;
		}
	}
	void print(int order = 0) {
		//1 ����
		//2 ����
		if (order == 0) {
			print_arr(this->_names);
		}
		else if (order == 1) {
			vector<string>tmp = this->_names;
			sort(tmp.begin(), tmp.end());
			print_arr(tmp);
		}
		else {
			vector<string>tmp = this->_names;
			sort(tmp.begin(), tmp.end(), greater<string>());
			print_arr(tmp);
		}
	}
private:
	vector<string>_names;
};