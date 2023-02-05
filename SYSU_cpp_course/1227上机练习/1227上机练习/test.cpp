
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;
#include<functional>
#include<numeric>
#include<fstream>


//ʹ��width����������
#if 0
int main()
{
	double values[] = { 1.23,35.36,653.7,4358.24 };
	for (size_t i = 0; i < 4; i++)
	{
		cout.width(10);
		cout << values[i] << endl;
	}
	return 0;
}
#endif



//ʹ��setw������ָ�����
#include<iomanip>
#if 0
int main()
{
	double values[] = { 1.23,35.36,653.7,4358.24 };
	string names[] = { "Zoot","Jimmy","AI","Stan" };
	for (size_t i = 0; i < 4; i++)
	{
		cout << setw(6) << names[i] << setw(10) << values[i] << endl;
	}
	return 0;
}
#endif


//setiosflags��������ppt
//�ļ��������Ա����
//open ������һ���ض��Ĵ����ļ���������
//put ��һ���ַ�д���������
//write ���ڴ��е�һ������д��һ���ļ��������
//seekp��tellp �����ļ������ڲ�ָ��
//close �ر�һ�����ؼ�����������Ĵ����ļ�

#if 0
struct Date
{
	int mon;
	int day;
	int year;
};
int main()
{
	Date dt = { 6,10,92 };
	ofstream file("data.dat", ios_base::binary);
	file.write(reinterpret_cast<char*>(&dt), sizeof(dt));
	file.close();
	return 0;
}
#endif

//�ַ��������
//ostringstream
//����ostringstream����ֵת��Ϊ�ַ���
#include<sstream>
#if 0
template<class T>
inline string toString(const T& v)
{
	ostringstream os;
	os << v;//������v��ֵд���ַ�����
	return os.str();//������������ɵ��ַ���
}
int main()
{
	string str1 = toString(5);
	cout << str1 << endl;
	string str2 = toString(1.2);
	cout << str2 << endl;
	return 0;
}
#endif

//to_string���򵥣�����ʽ���Ƚϵ�һ���൱��sprintf



//������

//Ϊ������ָ��һ����ֹ�ַ�
#if 0
int main()
{
	string line;
	cout << "Type a line terminated by '\t'" << endl;
	getline(cin, line, '\t');
	cout << line << endl;
	return 0;
}
#endif


//��һ��payroll�ļ���һ�������Ƽ�¼��һ���ṹ��
#if 0
struct SalaryInfo
{
	size_t id;
	double salary;
};
int main()
{
	SalaryInfo employee1 = { 600001,8000 };
	ofstream os("payroll", ios_base::out | ios_base::binary);
	os.write(reinterpret_cast<char*>(&employee1), sizeof(employee1));
	os.close();


	//������
	ifstream is("payroll", ios_base::in | ios_base::binary);
	if (is)
	{
		SalaryInfo employee2;
		is.read(reinterpret_cast<char*>(&employee2), sizeof(employee2));
		cout << employee2.id << " " << employee2.salary << endl;
	}
	else
	{
		cout << "ERROR:Cannot open file 'payroll'." << endl;
	}
	is.close();
	return 0;
}
#endif



//�ַ���������

//��istringstream���ַ���ת��Ϊ��ֵ
#if 0
template<class T>
inline T fromString(const string& str)
{
	istringstream is(str); //�����ַ���������
	T v;
	is >> v; //���ַ����������ж�ȡ����v
	return v;
}
int main()
{
	int v1 = fromString<int>("5");
	cout << v1 << endl;
	double v2 = fromString<double>("1.2");
	cout << v2 << endl;
	return 0;
}
#endif


//���ַ������ַ��������
//���ַ� wchar_t ����
//���ַ��� wstring ����



//�쳣����

//�����0�쳣
#if 0
int divide(int x, int y)
{
	if (y == 0)throw x;
	return x / y;
}
int main()
{
	try
	{
		cout << "5/2=" << divide(5, 2) << endl;
		cout << "8/0=" << divide(8, 0) << endl;
		cout << "7/1=" << divide(7, 1) << endl;
	}
	catch (int e)
	{
		cout << e << " is divided by zero!" << endl;
	}
	cout << "That is ok." << endl;
	return 0;
}
#endif


//�������������
#include<stdexcept>
double area(double a, double b, double c) throw (invalid_argument)
{
	//�ж������α߳��Ƿ�Ϊ��
	if (a <= 0 || b <= 0 || c <= 0)
		throw invalid_argument("the side length should be positive");
	//�ж��������Ƿ��������ǲ���ʽ
	if (a + b <= c || b + c <= a || c + a <= b)
		throw invalid_argument("the side length should be fit the triangle inequation");
	//��Heron��ʽ�������
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main()
{
	double a, b, c;
	cout << "Please inpput the side lengths of a triangle: ";
	cin >> a >> b >> c;
	try
	{
		double s = area(a, b, c);//���Լ������������
		cout << "Area:" << s << endl;
	}
	catch (const std::exception& e)
	{
		cout << "Error:" << e.what() << endl;
	}
	return 0;
}