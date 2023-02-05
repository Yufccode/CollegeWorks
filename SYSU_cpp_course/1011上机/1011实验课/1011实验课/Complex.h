#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

//������Complex���ʵ�����鲿��Ϊint��������
class Complex {
private:
	int _real_part;
	int _imaginary_part;
	double _mod;
	static int _complex_size;
public:
	friend ostream& operator<<(ostream& out, Complex& c);
	friend istream& operator>>(istream& in, Complex& c);
public:
	friend Complex Complex_mul(Complex& c1, Complex& c2);
	Complex(int real_part = 0, int imaginary_part = 0)
		:_real_part(real_part), _imaginary_part(imaginary_part) {
		_mod = sqrt(pow(_real_part, 2) + pow(_imaginary_part, 2));
		_complex_size++;
	}
	~Complex() {
		cout << "ɾ���ø�������" << endl;
		_complex_size--;
	}
	Complex(const Complex& c)
		:_real_part(c._real_part), _imaginary_part(c._imaginary_part) {
		_mod = sqrt(pow(_real_part, 2) + pow(_imaginary_part, 2));
		_complex_size++;
	}
	Complex& add(Complex& c) {
		this->_real_part = this->_real_part + c._real_part;
		this->_imaginary_part = this->_imaginary_part + c._imaginary_part;
		return *this;
		//���Դ����÷��أ�C1������ʱ����
	}
	Complex operator+(const Complex& c)const {
		int real_part = this->_real_part + c._real_part;
		int imaginary_part = this->_imaginary_part + c._imaginary_part;
		Complex ans(real_part, imaginary_part);
		return ans;
		//���Դ����÷��أ�C1������ʱ����
	}
	Complex operator*(const Complex& c1)const {
		int real_ret = c1._real_part * _real_part - c1._imaginary_part * _imaginary_part;
		int img_ret = c1._imaginary_part * _real_part + c1._real_part * _imaginary_part;
		Complex ans(real_ret, img_ret);
		//����������ܴ����÷��� -- ��Ϊ����ʱ���� -- ��Ҫ���ÿ�������
		return ans;
	}
	Complex& operator=(Complex& c) {
		this->_real_part = c._real_part;
		this->_imaginary_part = c._imaginary_part;
		return *this;
	}
	static size_t Complex_size() {
		return _complex_size;
	}
	void show() {
		//�������ӡ���Ը����ۣ�������ʹ��ϰ��
		//ʵ���鲿��Ϊ��
		if (this->_imaginary_part && this->_real_part) {
			if (this->_imaginary_part != 1) {
				cout << "{" << _real_part << "+" << _imaginary_part << "i" << "}" << endl;
			}
			else {
				cout << "{" << _real_part << "+i" << "}" << endl;
			}
		}
		//�鲿Ϊ0
		else if (this->_imaginary_part == 0 && this->_real_part) {
			cout << "{" << _real_part << "}" << endl;
		}
		//ʵ��Ϊ0
		else if (this->_imaginary_part && this->_real_part == 0) {
			if (this->_imaginary_part == 1) {
				cout << "{i}" << endl;
			}
			else {
				cout << "{" << _imaginary_part << "i" << "}" << endl;
			}
		}
		else {
			cout << "{0}" << endl;
		}
	}
};
Complex Complex_mul(Complex& c1, Complex& c2) {
	int real_ret = c1._real_part * c2._real_part - c1._imaginary_part * c2._imaginary_part;
	int img_ret = c1._imaginary_part * c2._real_part + c1._real_part * c2._imaginary_part;
	Complex ans(real_ret, img_ret);
	//����������ܴ����÷��� -- ��Ϊ����ʱ���� -- ��Ҫ���ÿ�������
	return ans;
}
int Complex::_complex_size = 0;
ostream& operator<<(ostream& out, Complex& c) {
	//�������ӡ���Ը����ۣ�������ʹ��ϰ��
//ʵ���鲿��Ϊ��
	if (c._imaginary_part && c._real_part) {
		if (c._imaginary_part != 1) {
			cout << "{" << c._real_part << "+" << c._imaginary_part << "i" << "}" << endl;
		}
		else {
			cout << "{" << c._real_part << "+i" << "}" << endl;
		}
	}
	//�鲿Ϊ0
	else if (c._imaginary_part == 0 && c._real_part) {
		cout << "{" << c._real_part << "}" << endl;
	}
	//ʵ��Ϊ0
	else if (c._imaginary_part && c._real_part == 0) {
		if (c._imaginary_part == 1) {
			cout << "{i}" << endl;
		}
		else {
			cout << "{" << c._imaginary_part << "i" << "}" << endl;
		}
	}
	else {
		cout << "{0}" << endl;
	}
	return out;
}
istream& operator>>(istream& in, Complex& c) {
	int img = 0;
	int real = 0;
	cin >> real >> img;
	double mod = sqrt(pow(real, 2) + pow(img, 2));
	c._real_part = real;
	c._imaginary_part = img;
	c._mod = mod;
	return in;
}