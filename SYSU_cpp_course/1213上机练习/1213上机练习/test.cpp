
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus

#include<string>
#include<functional>
#include<map>
#include<unordered_map>
using namespace std;
#include<iostream>
#include<algorithm>
#include<unordered_set>

#elif
#endif

#if 0
//���һ��������Ҫ�ṩһ������
void show_list3() {}
template<typename T, typename... Args>
void show_list3(T value, Args ... args)
{
	cout << value << " ";
	show_list3(args...);//�ݹ����
}
//�Ľ����show_list()
void show_list() {}
template<typename T>
void show_list(const T& val)
{
	cout << val << endl;
}
template<typename T, typename ...Args>
void show_list(const T& val, const Args&...args)
{
	cout << val << " ";
	show_list(args...);
}
int main()
{
	int n = 14;
	double x = 2.7;
	string mr = "Mr";
	//show_list3(n, x);
	//cout << endl;
	//show_list3(x * x, '!', 7, mr);
	show_list(n, x);
	cout << endl;
	show_list(x * x, '!', 7, mr);
	return 0;
}
#endif


//STL���
#if 0
int main()
{
	//const int N = 5;
	vector<int>s = { 1,2,3,4,5 };
	//��s.begin()~s.end()֮���������һ��negate<int>(ȡ��)����֮�������cout����
	transform(s.begin(), s.end(), ostream_iterator<int>(cout, " "), negate<int>());//negate<int>()��һ���º���
	return 0;
}
#endif


//mySort
#if 0
template<class T,class input_iterator,class output_iterator>
void mySort(input_iterator first, input_iterator last, output_iterator result)
{
	//�Ȱ�����Ķ����浽vector����ȥ��Ȼ������
	vector<T>s;
	for (; first != last; ++first)
	{
		s.push_back(*first);
	}
	sort(s.begin(), s.end());//��s��������
	copy(s.begin(), s.end(), result);//������õ�vector������������ϣ������������������������Ҳ������cout������
}
int main()
{
	//unordered_multiset<int>set = { 1,2,3,4,5,1,2,3,12 };
	unordered_set<int>set = { 1,2,3,4,5,1,2,3,12 };
	vector<int>arr(set.size() + 1); arr[0] = 100;
	//��set.begin()~set.end()�����ݷŵ�arr.begin()+1��λ��ȥ
	mySort<int>(set.begin(), set.end(), arr.begin() + 1);
	for (const auto& e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
#if 0
	mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
	//��stdin�������������Ϊһ�������� -- stdout�ϵ�������Ϊһ�������
	cout << endl;
#endif
	return 0;
}
#endif


//�����ж��뼸��ʵ�����ֱ�ƽ�������
double square(double x) { return x * x; }
int main()
{
	unordered_set<int>s = { 1,2,1,2,3,4,5 };
	transform(s.begin(), s.end(), ostream_iterator<double>(cout, " "), square);//square����һ���º���
	return 0;
}