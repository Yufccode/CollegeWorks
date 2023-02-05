#pragma once

#include<iostream>
using namespace std;



/**
 * 1. ����һ������Point����ʾƽ���ϵ�һ���㣬��������double x_, double y_���ṩ��ӡ����Print()��
 * �ṩһ��Move(double xoffset, double yoffset)��������ʾƽ��ƫ����(xoffset, yoffset)..
 */
class Circle;
class Polygon;
class Shape;
typedef shared_ptr<Shape> ptr_shape;
class Point
{
public:
	friend class Edge;
	friend class Circle;
	friend class Polygon;
	friend ostream& operator<<(ostream& out, const Point& p);
	friend ptr_shape operator&(const ptr_shape& ptr1, const ptr_shape& ptr2);
	friend ptr_shape operator|(const ptr_shape& ptr1, const ptr_shape& ptr2);
protected:
	double _x;
	double _y;
public:
	Point(double x = 0, double y = 0)
		:_x(x), _y(y) {}
	Point(const Point& p) = default;
	~Point() = default;
public:
	void Print() const
	{
		cout << "(" << this->_x << "," << this->_y << ")";
	}
	void Move(double xoffset, double yoffset)
	{
		this->_x += xoffset;
		this->_y += yoffset;
	}
};

/**
 * ����һ������Edge��
 * ����һ���ߵ�����Point�˵㣬
 * �ṩ�󳤶�Length()�ʹ�ӡPrint()������
 * ��ӡ������Ҫ����Point�����ش�ӡ���ܡ�
 */
class Edge
{
public:
	friend class Polygon;
	friend ptr_shape operator&(const ptr_shape& ptr1, const ptr_shape& ptr2);
	friend ptr_shape operator|(const ptr_shape& ptr1, const ptr_shape& ptr2);
protected:
	Point _point1;
	Point _point2;
public:
	Edge(const Point& p1 = Point(), const Point& p2 = Point())
		:_point1(p1), _point2(p2) {}
	Edge(const Edge& e) = default;
	~Edge() = default;
public:
	//��ĿҪ��Print()��Ҫ����<class Point>��Print
	double Length() const
	{
		return sqrt(pow(_point1._x - _point2._x, 2) + pow(_point1._y - _point2._y, 2));
	}
	void Print() const
	{
		double length = this->Length();
		cout << endl;
		cout << "��һ���˵�Ϊ" << _point1 << endl;
		cout << "�ڶ����˵�Ϊ" << _point2 << endl;
		cout << "����Ϊ" << length << endl;
		cout << endl;
	}
	void Move(double xoffset = 0, double yoffset = 0)
	{
		_point1.Move(xoffset, yoffset);//����Point��һЩ����
		_point2.Move(xoffset, yoffset);
	}
};