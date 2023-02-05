
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif

/**
 * 1.��дһ����ģ��Array<class T, int SIZE>��
 * ��װ����Ԫ�أ��ṩ���򡢲��ҡ���ͺʹ�ӡ���ܡ�
 * Ȼ���������ʵ�ηֱ�Ϊint�ͣ�double�ͺ�string�͵�ģ���࣬
 * �����������ܣ���дScore�࣬����string student_id��double score�������ݳ�Ա, 
 * ����Array<Score>�ࡣ�ֹ���ʼ��3�����󣬵����������򡢲��ҡ���ͺʹ�ӡ���ܡ�.
 */

#include"Static_Array.h"
struct Score
{
	friend struct CmpScore;
protected:
	string __student_id;
	double __score;
public:
	Score()
		:__student_id("000"), __score(100) {}
	Score(const Score& s) = default;
};
struct CmpScore
{
	bool operator()(const Score& s1, const Score& s2)
	{
		return s1.__score < s2.__score;
	}
};
//���ṩScore��string����ͷº��� -- ��֧��Score���
void test1()
{
	StaticArray<double, 10>arr = { 10.0,9,7,5,3,1,2,4,6,8 };
	//StaticArray<int, 10>arr2(arr);
	//cout << endl;
	arr.sort(CmpScore());
	cout << arr;
	cout << arr.sum() << endl;
}
void test2()
{
	StaticArray<string, 10>arr = { "aba","adsf","asdf" ,"aa"};
	cout << arr;
	arr.sort(CmpScore());
	cout << arr;
	//cout << arr.sum() << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}