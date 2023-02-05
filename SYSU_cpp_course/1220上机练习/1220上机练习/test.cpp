
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif


#include<vector>
#include<unordered_map>
#include<set>
#include<numeric>
#include<iostream>
#include<functional>
#include<algorithm>
#include<string>
using namespace std;


//д��1
#if 0
int mult(int x, int y) { return x * y; }
int sub(int x, int y) { return x - y; }
int main()
{
	int a[] = { 1,2,3,4,5 };
	const int N = sizeof(a) / sizeof(a[0]);
	cout << accumulate(a, a + N, 1, mult) << endl;
	cout << accumulate(a, a + N, 0, sub) << endl;
	return 0;
}
#endif

//д��2
#if 0
struct MultClass
{
	int operator()(int x, int y)const
	{
		return x * y;
	}
};
struct SubClass
{
	int operator()(int x, int y)const
	{
		return x - y;
	}
};
int main()
{
	int a[] = { 1,2,3,4,5 };
	const int N = sizeof(a) / sizeof(a[0]);
	cout << accumulate(a, a + N, 1, MultClass()) << endl;
	cout << accumulate(a, a + N, 0, SubClass()) << endl;
	return 0;
}
#endif

//���ǻ������ÿ����е�
#if 0
int main()
{
	int a[] = { 1,2,3,4,5 };
	const int N = sizeof(a) / sizeof(int);
	cout << accumulate(a, a + N, 1, multiplies<int>()) << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int arr[] = { 30,90,10,40,70,50,20,80 };
	const int N = sizeof(arr) / sizeof(arr[0]);
	vector<int>a(arr, arr + N);//Ҫ���õ��������乹��
	cout << "before sort" << endl;
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, " ")); cout << endl;//��ӡ��stdout��
	sort(a.begin(), a.end(), greater<int>());
	cout << "after sort" << endl;
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, " ")); cout << endl;//��ӡ��stdout��
	return 0;
}
#endif

//����������
//1.��������
//2.���������
//3.ָ�뺯��������

//����Ѱ�ҵ�һ������40����

//bind1st �󶨵�һ������
//bind2nd �󶨵ڶ�������
#if 0
int main()
{
	vector<int>a = { 30,90,10,40,70,50,20,80 };
	//auto p = find_if(a.begin(), a.end(),greater<int>());//err ��Ϊfind_ifֻ����һԪ��
	//���԰�һ������
	auto p = find_if(a.begin(), a.end(), bind2nd(greater<int>(), 40));
	if (p != a.end())
	{
		cout << "��һ������40d��������:" << *p << endl;
	}
	return 0;
}
#endif
//����������º�����ֹ��Ԫ�أ�

//C++�ṩ��ͨ�õĺ��� bind
//bitҲ����
#if 0
void fn(int n1, int n2, int n3) //������������ǵķº���
{
	cout << n1 << " " << n2 << " " << n3 << endl;
}
int fn2()
{
	cout << "fn2 has called" << endl; return -1;
}
int main()
{
	using namespace std::placeholders;
	auto bind_test1 = bind(fn, 1, 2, 3);//��ʱ��bind_test1���ǲ���Ϊ1,2,3�ĺ���fn
	auto bind_test2 = bind(fn, _1, _2, _3);
	auto bind_test3 = bind(fn, 0, _1, _2);
	auto bind_test4 = bind(fn, _2, 0, _1);//���ﻹ�����˲�����˳��

	bind_test1();
	bind_test2(3, 8, 24);
	bind_test2(1, 2, 3, 4, 5);//4,5�ᱻ����
	bind_test3(10, 24);//���0,10,24
	bind_test3(10, fn2());//���0,10,-1
	bind_test4(10, 24);//24,0,10
	return 0;
}
#endif
//bindȡ���ɽӿ� bind1st/bind2nd

//�����ҵ���һ������40����
#if 0
int main()
{
	using namespace std::placeholders;
	vector<int>a = { 30,90,10,40,70,50,20,80 };
	//auto p = find_if(a.begin(), a.end(),greater<int>());//err ��Ϊfind_ifֻ����һԪ��
	//���԰�һ������
	auto p = find_if(a.begin(), a.end(), bind(greater<int>(), _1, 40));
	if (p != a.end())
	{
		cout << "��һ������40d��������: " << *p << endl;
	}
	return 0;
}
#endif



//lambda���ʽ
/*
* [a]��ʾֵ���ݲ������a(������������ö��ŷָ�) 
* [=]��ʾֵ���ݲ������������б��� 
* [&a]��ʾ���ô��ݲ������a 
* [&]��ʾ���ô��ݲ������������б��� 
* [this]��ʾֵ���ݲ���ǰ��thisָ��
* [=, &a, &b]��ʾֵ���ݲ������������б���������a��b������ ���ô��ݷ�ʽ����
* [&, a, this]��ʾ���ô��ݲ������������б���������a��thisָ ����ֵ���ݷ�ʽ����
*/

//һЩ��������������
void test1()
{
	int x = 100, y = 200, z = 300;
	auto ff = [=, &y, &z](int n) //[=, &a, &b]��ʾֵ���ݲ������������б���������a��b������ ���ô��ݷ�ʽ����
	{
		cout << x << endl;
		y++; z++;
		return n * n;
	};
	cout << ff(15) << endl;
	cout << y << ", " << z << endl;
}
void test2()
{
	vector<string>words =
	{
		"abcdefadsg","abcdeasdfasdfadsfgh"
		"aabadsdcdef","aaassdafsdasddsdf",
		"aaaadfe"
	};
	//�����ַ����ĳ�������
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b)
		{ return a.size() < b.size(); });
	copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));
	cout << endl << "--------------" << endl;
	//��ȡһ����������ָ���һ������size()>=sz��Ԫ��
	int sz = 10;
	auto wc = find_if(words.begin(), words.end(), [sz](const string& a) {return a.size() > sz; });
	cout << *wc << endl;
}

int main()
{
	//test1();
	test2();
	return 0;
}


//����ָ��
//ѭ����������