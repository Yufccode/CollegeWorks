#define _CRT_SECURE_NO_WARNINGS 1

#include"Complex.h"
#include"String.h"

#if 1 //���Ը�����
int main() {
	Complex C1(1, 0);
	C1.show();
	Complex C2(1, 1);
	C2.show();
	C1.add(C2).show();
	cout << Complex::Complex_size() << endl;

	Complex a1(1, 1);
	Complex a2(2, 2);
	Complex ret = Complex_mul(a1, a2);
	ret.show();
	//�������һЩ���� -- ����ȥ��show��add��Щ������
	//����ʹ��a+b��ʱ��abӦ�ö��ǲ���Ӱ��ģ������Ǽ���a��
	//����Ϊ�˿�������д������Ҫ����һ��<< -- ����ʹ��ģ�����
	//cout << (C1 + C2) << endl;
	Complex ret2 = C1 + C2;
	cout << ret2 << endl;

	cin >> C1;
	cout << C1 << endl;

	//������һ���˷���
	Complex b1;
	Complex b2(1, 1);
	Complex ans = b1 * b2;
	cout << ans << endl;
	return 0;
}
#endif

//����StringBad��
#if 0
int main() {
	StringBad s = "abcdefg";
	StringBad scopy = s;
	cout << s << endl;
	//���Ը�ֵ
	StringBad s2;
	s2 = s;
	cout << s2 << endl;
	return 0;
}
#endif


//����StringLeaky��
#if 0
int main() {
	EatMemory();//��������ѭ��ȥ��
	return 0;
}
#endif