#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class homework_Solution {
public:
	//����ת��
	void test_decimal_conversion() {
		int input = 0;
		cout << "������һ��ʮ����������:" << endl;
		cin >> std::hex >> input;
		cout << "ʮ����Ϊ" << std::dec << input << endl;
		cout << "�˽���Ϊ" << std::oct << input << endl;
	}
#if 1
	//ʵ��1
	template<class T1, class T2 = int>
	float add(T1 num1, T2 num2 = 1) {
		return num1 + num2;
	}
#endif
#if 0
	//ʵ��2
	int add(int x, int y = 1) { return x + y; }//ȱʡ����
	float add(int x, float y) { return x + y; }
	float add(float x, int y) { return x + y; }
	float add(float x, float y) { return x + y; }
#endif
};
int main() {
	//homework_Solution().test_decimal_conversion();
	int a = 1;
	int b = 2;
	float c = 3.1f;
	float d = 4.5f;
	cout << "add(a)��ֵΪ" << homework_Solution().add(a) << endl;//2
	cout << "add(a,b)��ֵΪ" << homework_Solution().add(a, b) << endl;//3
	cout << "add(a,c)��ֵΪ" << homework_Solution().add(a, c) << endl;//4.1
	cout << "add(c,a)��ֵΪ" << homework_Solution().add(c, a) << endl;//4.1
	cout << "add(c,d)��ֵΪ" << homework_Solution().add(c, d) << endl;//7.6
	return 0;
}