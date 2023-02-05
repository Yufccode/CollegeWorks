#pragma once

#include"Point.h"
/*
2. ����һ��Line�࣬������Ա����Point start_, Point end_��Color color_��
��ʾ�����߶ε������յ㣬��ɫ��ö�٣���
ʵ�����ֹ��캯����һ�����ĸ�����ֵΪ��������һ��������PointΪ������
ʵ��Line��ĸ��ƹ��캯����
*/


class Line {
private:
	enum Color {
		RED,GREEN,BLUE
	};
	Point _start;
	Point _end;
	Color _color;
public:
	friend class Rectangle;
	friend ostream& operator<<(ostream& out, Line& l);
	friend istream& operator>>(istream& in, Line& l);
	Line(float x1 = 0, float y1 = 0, float x2 = 0, float y2 = 0)
		:_color(RED)
	{
		//1.Line���ó�Point����Ԫ
		//2.����Point�ĸ�ֵ����Ҳ��
		this->_start._x = x1;
		this->_start._y = y1;
		this->_end._x = x2;
		this->_end._y = y2;
	}
	Line(const Point& p1, const Point& p2)
		:_start(p1), _end(p2), _color(RED) {}
	~Line() {
		cout << "ɾ�����߶�" << endl;
	}
	Line(const Line& line)//��������
		:_start(line._start), _end(line._end), _color(line._color) {}
	float getLineLength() {
		return _start.GetDistance(_end);
	}
};
//���һ����
//����������ȡ����
ostream& operator<<(ostream& out, Line& l) {
	cout << "----------------" << endl;
	out << "��ʼ�㣺";
	out << l._start << endl;
	out << "��ֹ�㣺";
	out << l._end << endl;
	out << "��ɫ��";
	out << l._color << endl;
	cout << "----------------" << endl;
	return out;
}
istream& operator>>(istream& in, Line& l) {
	float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	cout << "��������ʼ������:";
	cin >> x1 >> y1;
	cout << "��������ֹ������:";
	cin >> x2 >> y2;
	cout << "�޸ĳɹ�" << endl;
	return in;
}