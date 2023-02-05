#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<cassert>
#include<functional>

using namespace std;

/*
1.����һ��Vehicle�࣬������Ա������float x_, float y_, float vx _, float vy_, 
	float width_, float height_�Լ�static int vCount_����ʾ�Ѿ������ĳ������������
���У�(x_, y_)��ʾ�������ĵĳ�ʼλ�����꣬��λm��(vx_,vy_)��ʾ�����ĳ�ʼ�ٶȣ�
	��λm/s��width_��height_�ֱ��ʾ�����Ŀ�ͳ�����λm��
ʵ��Vehicle��Ĺ��캯�������ƹ��캯��������������
	���У�vx_��vy_��Ĭ��ֵ�ֱ�Ϊ��6��0��width��height��Ĭ��ֵ�ֱ�Ϊ2��4
ʵ��void Display()��������ʽ����������Ϣ��
ʵ�ֳ�Ա����IsCollision(const Vehcile &veh)���ж������Ƿ��복��veh��������ײ��
	���������ײ���򷵻�1�����򷵻�0��
*/

/// <summary>
/// �������_vy��Ϊ0��������б�ŵ���
/// </summary>
class Vehicle {
private:
	float _x;
	float _y;
	float _vx;
	float _vy;
	float _width;
	float _height;
public:
	static int _vCount;
public:
	friend struct hash_name;
	friend ostream& operator<<(ostream& out, Vehicle& v);
	Vehicle(float x = 0, float y = 0, float vx = 6, float vy = 0, float width = 2, float height = 4)
		:_x(x), _y(y), _vx(vx), _vy(vy), _width(width), _height(height)
	{
		_vCount++;
	}
	~Vehicle() {
		//cout << "ɾ���ó�����Ϣ" << endl;
		--_vCount;
	}
	Vehicle(const Vehicle& v)
		:_x(v._x), _y(v._y), _vx(v._vx), _vy(v._vy), _width(v._width), _height(v._height) {
		_vCount++;
	}
	//չʾ������Ϣ
	//1.this->Display()
	//2.operator<<
	void Display() {
		cout << "----------------------------" << endl;
		cout << "�������ĵ�λ��Ϊ:(" << _x << "," << _y << ")��" << endl;
		cout << "�����ٶ�Ϊ:(" << _vx << "," << _vy << ")" << endl;
		cout << "�������Ϊ:" << _width << endl;
		cout << "��������Ϊ:" << _height << endl;
		cout << "----------------------------" << endl;
	}
	bool isCollision(const Vehicle& veh)const {
		///�ּ��輴ʹ����y���������ٶ� -- ����Ҳ��ֱ��
		float y1_g = this->_y + this->_width / 2.0;
		float y1_m = this->_y - this->_width / 2.0;
		float y2_g = veh._y + veh._width / 2.0;
		float y2_m = veh._y - veh._width / 2.0;

		float x1_g = this->_x + this->_height / 2.0;
		float x1_m = this->_x - this->_height / 2.0;
		float x2_g = veh._x + veh._height / 2.0;
		float x2_m = veh._x - veh._height / 2.0;
		//һ�������ص������
		if (x1_g <= x2_g && x1_g >= x2_m && y1_g <= y2_g && y1_g >= y2_m)return true;
		if (x1_g <= x2_g && x1_g >= x2_m && y1_m <= y2_g && y1_m >= y2_m)return true;
		if (x1_m <= x2_g && x1_m >= x2_m && y1_m <= y2_g && y1_m >= y2_m)return true;
		if (x1_m <= x2_g && x1_m >= x2_m && y1_g <= y2_g && y1_g >= y2_m)return true;
		return false;
	}
	bool operator==(const Vehicle& v) const {
		return v._x == _x && v._y == _y && v._vx == _vx && v._vy == _vy && v._width == _width && v._height == _height;
	}
};
int Vehicle::_vCount = 0;//static�����������ʼ��
ostream& operator<<(ostream& out, Vehicle& v) {
	cout << "----------------------------" << endl;
	cout << "�������ĵ�λ��Ϊ:(" << v._x << "," << v._y << ")��" << endl;
	cout << "�����ٶ�Ϊ:(" << v._vx << "," << v._vy << ")" << endl;
	cout << "�������Ϊ:" << v._width << endl;
	cout << "��������Ϊ:" << v._height << endl;
	cout << "----------------------------" << endl;
	return out;
}