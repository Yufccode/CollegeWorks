#define _CRT_SECURE_NO_WARNINGS 1

/*
4 ����ϰ
1. ��дһ����ΪPerson����Ա�࣬�洢��Ա�������������סַ��Ϣ��
Ϊ���Person�������ȷ�Ĺ��캯����ʼ�������ԣ�
���ṩ����ʹ���ܹ�����������סַ���Լ���ӡ������סַ��ͨ����Ա����ʵ�֣�
2. Ϊ����ʵ��Ĭ�Ϲ��캯���͸��ƹ��캯����
Ĭ�Ϲ��캯��ʹ�������趨��һ��ֵ��ʼ����Ա������
���ƹ��캯�����Դ�ӡһЩ��Ϣ�������۲츴�ƹ���ķ���
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Person {
public:
	friend std::ostream& operator<<(std::ostream& out, const Person& p);
	friend std::istream& operator>>(std::istream& in, Person& p);
	~Person() { cout << "������Person����������" << endl; }
	Person(string name = "С��", size_t age = 10, string addr = "����")
		:_name(name), _age(age), _addr(addr) {}
	Person(Person& p) {
		this->_name = p._name;
		this->_age = p._age;
		this->_addr = p._addr;
		cout << "������Person�Ŀ������캯��" << endl;
	}
	//��ӡ��Ϣ��һ�ַ�ʽ��get_peoinfo()
	//�ڶ��ַ�ʽ������������ȡ����
	void get_peoinfo() {
		cout << "-------------" << endl;
		cout << "����Ϊ��" << this->_name << endl;
		cout << "����Ϊ:" << this->_age << endl;
		cout << "��ַΪ:" << this->_addr << endl;
		cout << "-------------" << endl;
	}
	//�޸���ϵ�˵�ַ��Ҳ����д�������������ʽ��
	Person& modify_info(string newname, size_t newage, string newaddr) {
		//p����������main�����Դ����÷���
		this->_name = newname;
		this->_age = newage;
		this->_addr = newaddr;
		return *this;
	}
	//��ֵ����(����Ĭ�����ɵ�)
	Person& operator=(Person& p) {
		this->_name = p._name;
		this->_age = p._age;
		this->_addr = p._addr;
		cout << "�����˸�ֵ����" << endl;
		return *this;
	}

private:
	string _name;
	size_t _age;
	string _addr;
};
ostream& operator<<(std::ostream& out, const Person& p) {
	//��Ҫ��λprivate���� -- ���ó���Ԫ
	out << "-------------" << endl;
	out << "����Ϊ��" << p._name << endl;
	out << "����Ϊ:" << p._age << endl;
	out << "��ַΪ:" << p._addr << endl;
	out << "-------------" << endl;
	return out;
}
std::istream& operator>>(std::istream& in, Person& p) {
	//����������
	cout << "����������:";
	in >> p._name;
	cout << "����������:";
	in >> p._age;
	cout << "�������ַ:";
	in >> p._addr;
	cout << "����ɹ���" << endl;
	return in;
}




Person func(Person pp) {
	//��ֵ���ã�����ÿ������� -- ��� -- �β�ѹջ
	//��ֵ���أ�Ҳ����ÿ������� -- ���ؿ���ѹջ
	return pp;
}
void test1() {
	Person p;
	Person p1("����", 20, "����");
	p.get_peoinfo();
	p1.get_peoinfo();
	Person p2 = p1;
	p2.get_peoinfo();
	func(p);
	p2.get_peoinfo();
	p2.modify_info("����", 30, "�人").get_peoinfo();
}
void test2() {
	//�ڶ��ִ�ӡ��ʽ����������ȡ������
	Person p("����", 20, "����");
	cout << p << endl;
	cin >> p;
}
void test3() {
	Person p("����", 70, "�人");
	Person p2;
	p2 = p;
	cout << p2 << endl;
}
int main() {
	//test1();
	//test2();
	test3();
	return 0;
}