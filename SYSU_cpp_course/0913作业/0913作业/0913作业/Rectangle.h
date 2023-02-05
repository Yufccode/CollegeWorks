#pragma once

#include"Line.h"

/*
3. ����һ��Rectangle�࣬�����ĸ�Line����
ʵ�ֹ���͸��ƹ��캯����ʵ�����ܳ�������
�Լ�draw()��ͼ������ģ�⼴�ɣ�
*/

class Rectangle {
private:
	Line _line1;//1
	Line _line2;//2
	Line _line3;//1
	Line _line4;//2
	bool is_rectangle_Valid() {
		float x1 = _line1._start._x;
		float y1 = _line1._start._y;
		float x2 = _line2._start._x;
		float y2 = _line2._start._y; 
		float x3 = _line3._start._x;
		float y3 = _line3._start._y;
		float x4 = _line4._start._x;
		float y4 = _line4._start._y;
		//�ĸ��������
		float x0 = (x1 + x2 + x3 + x4) / 4.0;
		float y0 = (y1 + y2 + y3 + y4) / 4.0;
		float dist1_square = pow(abs(x0 - x1), 2) + pow(abs(y0 - y1), 2);
		float dist2_square = pow(abs(x0 - x2), 2) + pow(abs(y0 - y2), 2);
		float dist3_square = pow(abs(x0 - x3), 2) + pow(abs(y0 - y3), 2);
		float dist4_square = pow(abs(x0 - x4), 2) + pow(abs(y0 - y4), 2);
		return (dist1_square == dist2_square && dist2_square == dist3_square 
			&& dist3_square == dist4_square)
			? true : false;
	}
public:
	//���ζ������ɲ������޲δ���
	Rectangle(const Line& l1, const Line& l2, const Line& l3, const Line& l4)
		:_line1(l1), _line2(l2), _line3(l3), _line4(l4)
	{
		//�������Ƿ�Ϸ�
		if (!is_rectangle_Valid()) {
			cout << "�þ��ζ��󲻺Ϸ�!" << endl;
			exit(-1);//ֱ���˳�����
			//Rectangle::~Rectangle();//ֱ������
		}
	}
	~Rectangle() {
		cout << "���ٸþ��ζ���" << endl;
	}
	Rectangle(const Rectangle& r) 
		:_line1(r._line1),_line2(r._line2),_line3(r._line3),_line4(r._line4)
	{}
	void draw() {
		cout << "#########################" << endl;
		cout << "������������߷ֱ�Ϊ��" << endl;
		cout << _line1 << _line2 << _line3 << _line4 << endl;
		cout << "#########################" << endl;
	}
};