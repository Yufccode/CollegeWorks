#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;


/*
1.����һ��Point�࣬������Ա����float x_, float y_��
��ʾ��Ķ�ά����(x, y)��ʵ�ֳ�Ա����GetDistance(Point &p)��
��������֮��ľ��롣ʵ�ֳ�Ա����GetMidPoint(Point &p)����������֮����е㡣
����ʵ��Point��Ĺ��캯�������ƹ��캯��������������
*/
class Point {
private:
	float _x;
	float _y;
public:
	friend class Line;
	friend class Rectangle;
	friend ostream& operator<<(ostream& out, const Point& p);
	friend istream& operator>>(istream& in, Point& p);
	Point(float x = 0, float y = 0)//ȫȱʡĬ�Ϲ���
		:_x(x), _y(y) {}
	~Point() {
		cout << "ɾ����(" << _x << "," << _y << ")" << endl;
	}
	//��������
	Point(const Point& p) //���
		:_x(p._x), _y(p._y)
	{}
	float GetDistance(const Point& p) {
		float distance = sqrt(pow(this->_x - p._x, 2) + pow(this->_y - p._y, 2));
		return distance;
	}
	Point GetMidPoint(const Point& p) {//ֻ�ܴ�ֵ����
		Point mid;
		mid._x = (this->_x + p._x) / 2.0f;
		mid._y = (this->_y + p._y) / 2.0f;
		return mid;
	}
};
//�����
ostream& operator<<(ostream& out, const Point& p) {
	out << "(" << p._x << "," << p._y << ")";
	return out;
}
//���� -- �ı�һ����
istream& operator>>(istream& in, Point& p) { //ǳ������������Ȼ�Ĳ���
	float x = 0;
	float y = 0;
	cin >> x >> y;
	p._x = x;
	p._y = y;
	return in;
}