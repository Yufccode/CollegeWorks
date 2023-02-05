

/*****************************************************************//**
 * \file   PointVector.h
 * \brief  
 * 
 * \author yfc 21312780
 * \date   October 2022
 *********************************************************************/
#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<cassert>
using namespace std;

/*********************************************** Point�� ***********************************************/
struct Point {
public:
	Point(int x = 0, int y = 0)
		:_x(x), _y(y) {}
	void print() {
		cout << "(" << _x << "," << _y << ")";
	}
public:
	friend ostream& operator<<(ostream& out, Point& p);
public:
	int _x;
	int _y;
};
ostream& operator<<(ostream& out, Point& p) {
	cout << "(" << p._x << "," << p._y << ")";
	return out;
}


/*********************************************** PointVector�� ***********************************************/


//�����ʹ��ģ��
//Vector<Point>
class PointVector {
public:
	//������
	//vector�ײ���������;���ԭ��ָ�� -- ��˲���Ҫ��������������غ�����Ϊ
	typedef Point* iterator;
	typedef const Point* const_iterator;
	iterator begin() {
		return _data;
	}
	iterator end() {
		return _data + _size;
	}
	const_iterator begin()const {
		return _data;
	}
	const_iterator end()const {
		return _data + _size;
	}
	//��Ա����
	PointVector();
	PointVector(const PointVector& x);
	template<class InputIterator>    //�ṩģ�� -- const�Ŀ����� ����const��Ҳ������
	PointVector(InputIterator first, InputIterator end);
	~PointVector();
	void swap(PointVector& v);
	void reserve(size_t n);//�ṩreserve�ӿ�
	void resize(size_t n, const Point& val = Point());//�ṩresize�ӿ�
	void clear();
	void push_back(const Point& x);
	void pop_back();
	Point& at(size_t idx);//���ص�idx��Ԫ�ص�����
	size_t size()const;
	size_t capacity()const;
	bool empty()const;
	Point& front();
	Point& back();
	bool insert(size_t pos, const Point& pt);//��pos֮ǰ����һ��Point����
	bool erase(size_t pos);//ɾ��posλ�õĶ���
public:
	//���������
	PointVector& operator=(PointVector v);//�ִ�д�������ﲻ�����ã����ÿ�������
	Point& operator[](size_t pos);
	PointVector& operator+(const Point& p);
	PointVector& operator+(PointVector& v);
public:
	friend ostream& operator<<(ostream& out, PointVector& pv);
private:
	Point* _data;
	size_t _size;
	size_t _capacity;
};

/*********************************************** PointVector����ؽӿڶ��� ***********************************************/
PointVector::PointVector()
	:_size(0), _capacity(0), _data(nullptr) {}
PointVector::~PointVector() {
	delete[] this->_data;
	_size = _capacity = 0;
}
//���������俽������
template<class InputIterator> //�ṩģ�� -- const�Ŀ����� ����const��Ҳ������
PointVector::PointVector(InputIterator first, InputIterator end)
	:_size(0), _capacity(0), _data(nullptr)
{
	while (first != end) {
		push_back(*first);
		++first;
	}
}
//�ִ�д���������� -- ���õ��������乹�캯��
void PointVector::swap(PointVector& v) {
	std::swap(_data, v._data);
	std::swap(_capacity, v._capacity);
	std::swap(_size, v._size);
}
PointVector::PointVector(const PointVector& x) 
	:_size(0), _capacity(0), _data(nullptr)
{
	PointVector tmp(x.begin(), x.end());
	swap(tmp);
}



//����д����ֵ���� -- ���ã�
PointVector& PointVector::operator=(PointVector v) {
	if (this == &v)return*this;
	swap(v);//����swap����v����*this������Ϊv����ʱ���������԰�*this�ľ�����ɾ���������������Ϳ�������
	return *this;
}
Point& PointVector::operator[](size_t pos) {
	assert(pos >= 0);
	assert(pos < size());
	return _data[pos];
}
PointVector& PointVector::operator+(const Point& p) {
	//��vectorĩβ����һ��Point����
	this->push_back(p);
	return *this;
}
PointVector& PointVector::operator+(PointVector& v) {
	//��vector����appendһ��vector
	for (int i = 0; i < v.size(); i++) {
		(*this).push_back(v[i]);
	}
	return *this;
}
ostream& operator<<(ostream& out, PointVector& pv) {
	for (int i = 0; i < pv.size(); i++) {
		cout << pv[i] << " ";//��ʱ��Ҫ��Point������һ��<<
	}
	cout << endl;
	return out;
}



size_t PointVector::capacity()const {
	return this->_capacity;
}
size_t PointVector::size()const {
	return this->_size;
}
void PointVector::reserve(size_t n) {
	if (n > capacity()) {
		Point* tmp = new Point[n];
		size_t sz = size();
		if (_data) {
			for (size_t i = 0; i < sz; i++) {
				tmp[i] = _data[i];
			}
			delete[] _data;
		}
		_data = tmp;//��ֵ��_data
		_capacity = n;
		_size = sz;
	}
}
void PointVector::resize(size_t n, const Point& val) {//����ȱʡֵ����дĬ����(0,0)
	//1.����+��ʼ��
	//2.��ʼ��
	//3.ɾ������
	if (n > capacity()) {
		reserve(n);//ֱ�ӵ���reserve�ӿھ�����
	}
	if (n > size()) {
		//��ʼ����ֵ
		while (_size < n) {
			_data[_size] = val;//��ֵ
			_size++;
		}
	}
	else {
		_size = n;//ɾ��ֵ
	}
}
void PointVector::push_back(const Point& v) {
	if (_size == _capacity) {
		reserve(capacity() == 0 ? 4 : capacity() * 2);
	}
	_data[_size] = v;
	++_size;
}
void PointVector::pop_back() {
	assert(_size > 0);//Ҫ��֤��ɾ
	--_size;
}
void PointVector::clear() {
	_size = 0;
}
Point& PointVector::at(size_t idx) {
	return _data[idx];
}
bool PointVector::empty()const {
	return _size == 0;
}
Point& PointVector::front() {
	assert(_size);
	return _data[0];
}
Point& PointVector::back() {
	assert(_size);
	return _data[_size - 1];
}
//�������STL�涨ʹ�õ��������룬��Ҫע�������ʧЧ����
bool PointVector::insert(size_t pos, const Point& pt) {
	//��pos֮ǰ����һ��Point����
	assert(pos >= 0);
	assert(pos < _size);//���Ϸ���
	//��������return false
	if (_size == _capacity) {
		//����
		reserve(capacity() == 0 ? 4 : capacity() * 2);
	}
	//Ų������
	int end = _size - 1;
	
	while (end >= (int)pos) {
		_data[end + 1] = _data[end];
		end--;
	}
	_data[pos] = pt;
	_size++;
	return true;
}
bool PointVector::erase(size_t pos) {
	//ɾ��posλ�õĶ���
	assert(pos >= 0);
	assert(pos < _size);//���Ϸ���
	int begin = pos + 1;
	int end = this->_size;
	while (begin < end) {
		_data[begin - 1] = _data[begin];
		++begin;
	}
	--_size;
	return true;
}