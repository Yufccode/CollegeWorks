#pragma once

#include"Shape.h"
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

class ShapeFile
{
public:
	using ptr_shape = shared_ptr<Shape>;
	using ptr_point = shared_ptr<Point>;
	//���ļ���״̬
	enum Entry_status
	{
		null,POINTS, CIRCLE, POLYGON
	};
public:
	Entry_status cur_status = null;
protected:
	//�����ַ�����һЩ�ӿ�
	double find_first_digit(const string& str);
	double find_last_digit(const string& str);
	vector<int> get_idx(const string& str);
	void erase_the_first_idx(string& arr);
public:
	ShapeFile(ifstream& infile);
	ShapeFile(const ShapeFile& sf) = delete;//������������
	~ShapeFile() = default;//ʹ��������ָ�� -- ֱ����������
	void Generate();
	void Print();
protected:
	int ExtractPoints(const string& line, vector<Point>& pts) {}//ʹ����������������ʵ��
	vector<ptr_point>__points;
	vector<ptr_shape>__shape;
	vector<ptr_shape>__compositeShape;
};