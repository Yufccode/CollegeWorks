


/*****************************************************************//**
 * \file   Matrix.h
 * \brief  
 * 
 * \author Administrator
 * \date   October 2022
 *********************************************************************/
#pragma once


#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;


//Ϊʲôһ�������Ҫ����һ��һά�������棿
//��һ��double**_data
//��������ָ�벻����


//���Լ����Ż��ĵط�
//1.����IO
//2.����Ĵ�ӡ��printf�õ� -- ���� -- ������


//����[][]


class Matrix {
public:
	Matrix(int sz = 0, int row = 0, int col = 0)
		:_data(nullptr), _nRows(row), _nColumns(col) {
		_data = new double[sz];//��ǰ����sz�Ŀռ�
	}
	Matrix(vector<vector<double>>arr)
		:_nRows(arr.size()), _nColumns(arr[0].size())
	{
		//��һ����άvector����
		int idx = 0;//����_data[]
		_data = new double[arr.size() * arr[0].size()];
		for (int i = 0; i < _nRows; i++) {
			for (int j = 0; j < _nColumns; j++) {
				_data[idx] = arr[i][j];
				idx++;
			}
		}
	}
	~Matrix() {
		delete[] _data;
		_nRows = 0;
		_nColumns = 0;
	}
	Matrix(const Matrix& m) {
		int sz = m._nRows * m._nColumns;
		_data = new double[sz];
		memcpy(_data, m._data, sizeof(double) * sz);
		this->_nColumns = m._nColumns;
		this->_nRows = m._nRows;
	}
	Matrix& operator=(const Matrix& m) {
		assert(m._nColumns == this->_nColumns && m._nRows == this->_nRows);//�жϲ����Ϸ���
		int sz = this->_nColumns * this->_nRows;
		memcpy(_data, m._data, sz*sizeof(double));
		return *this;
	}
	size_t nElements() {
		return this->_nColumns * this->_nRows;
	}
	size_t size() {
		return this->nElements() * sizeof(double);
	}
	double* operator[](int row) {
		assert(row && row < this->_nRows);
		return this->_data + row * this->_nColumns; //���ص�ַ����
	}
	// 1 2 3 4
	// 5 6 7 8
	void set(int x, int y, double val) {
		//��������Ϊ(x,y)��ֵ ע��,x��0��ʼ
		int idx = x * _nColumns + y;
		this->_data[idx] = val;
	}
	double get(int x, int y) {
		int idx = x * _nColumns + y;
		return _data[idx];
	}
	void print_Row(int row) {
		//���ĳ�е�ֵ
		int start = row * _nColumns;
		for (int i = 0; i < _nColumns; i++) {
			cout << _data[start++] << " ";
		}
		cout << endl;
	}
	void print_Col(int col) {
		//���ĳ�е�ֵ
		int start = col;
		for (int i = 0; i < _nRows; i++) {
			cout << _data[start] << " ";
			start += _nColumns;
		}
		cout << endl;
	}
	void print_Matrix() {
		//Ϊ�˴�ӡ����������� -- ����˫��ѭ��
		int sz = this->_nColumns * this->_nRows;
		for (int i = 0; i < _nRows; i++) {
			for (int j = 0; j < _nColumns; j++) {
				cout << _data[i * _nColumns + j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	Matrix& add(const Matrix& m) {
		assert(m._nColumns == this->_nColumns && m._nRows == this->_nRows);//�жϲ����Ϸ���
		int sz = this->_nColumns * this->_nRows;
		for (int i = 0; i < sz; i++) {
			_data[i] += m._data[i];
		}
		return *this;
	}
	Matrix& sub(const Matrix& m) {
		assert(m._nColumns == this->_nColumns && m._nRows == this->_nRows);//�жϲ����Ϸ���
		int sz = this->_nColumns * this->_nRows;
		for (int i = 0; i < sz; i++) {
			_data[i] -= m._data[i];
		}
		return *this;
	}
public:
	//����+/-
	Matrix operator+(const Matrix& m) {
		assert(m._nColumns == this->_nColumns && m._nRows == this->_nRows);//�жϲ����Ϸ���
		int sz = this->_nColumns * this->_nRows;
		Matrix ans(sz, m._nRows, m._nColumns);
		for (int i = 0; i < sz; i++) {
			ans._data[i] = m._data[i] + this->_data[i];
		}
		return ans;//���ܴ�����
	}
	Matrix operator-(const Matrix& m) {
		assert(m._nColumns == this->_nColumns && m._nRows == this->_nRows);//�жϲ����Ϸ���
		int sz = this->_nColumns * this->_nRows;
		Matrix ans(sz, m._nRows, m._nColumns);
		for (int i = 0; i < sz; i++) {
			ans._data[i] = this->_data[i] - m._data[i];
		}
		return ans;//���ܴ�����
	}
private:
	double* _data;
	size_t _nRows;
	size_t _nColumns;
};