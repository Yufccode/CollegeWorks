#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
#include<assert.h>
using namespace std;
#elif
#endif

enum Sex
{
	MALE = 0, FEMALE = 1
};


/**
 * ����һ��Person������࣬�����������Ա�Ȼ������ԣ��Լ����ɴ��麯��Work, Run��.
 */
class Person
{
public:
	virtual void Work()const = 0;
	virtual void Run()const = 0;
public:
	Person(string name, Sex sex)
		:_name(name), _sex(sex) {}
	Person(const Person& p) = default;
	~Person() = default;
	virtual void get_person_info() const 
	{}
protected:
	string _name;
	Sex _sex;
};

/**
 * ����һ��������Student���������ѧУ���꼶�����ԣ�����µ��麯��Study��ReportGrades��
 */
class Student :public Person
{
public:
	Student(string name, Sex sex, string school, string grade)
		:Person(name, sex), _school(school), _grade(grade) {}	
	Student(const Student& s) = default;
	~Student() = default;
public:
	virtual void Work()const
	{
		cout << "Student::Work()" << endl;
	}
	virtual void Run()const
	{
		cout << "Student::Run()" << endl;
	}
	virtual void Study()const
	{
		cout << "Student::Study()" << endl;
	}
	virtual void ReportGrades()const
	{
		cout << "Student::ReportGrades()" << endl;
	}
	virtual void set_info()
	{
		//�����ö�̬��StudentҲ���Զ�����һ��set_info
		cout << "CollegeStudent::set_grade() called" << endl;
		cout << "please input the name:"; cin >> this->_name;
		cout << "please input the sex(male/female)";
		string sex_tmp;
		cin >> sex_tmp;
		if (sex_tmp == "male")this->_sex = MALE;
		else if (sex_tmp == "female")this->_sex = FEMALE;
		else assert(false);//��������
		cout << "please input the school name:"; cin >> this->_school;
		cout << "please input the grade name"; cin >> this->_grade;
	}
public:
	virtual void get_person_info() const
	{
		cout << "======================================" << endl;
		cout << "Student::_name" << " " << this->_name << endl;
		cout << "Student::_sex" << " " << this->_sex << endl;
		cout << "Student::_school" << " " << this->_school << endl;
		cout << "Student::_grade" << " " << this->_grade << endl;
		cout << "Student::function call:" << endl;
		this->Work();
		this->Run();
		this->Study();
		this->ReportGrades();
		//this->set_grade(); //��ʱ�������� -- Ӱ���ӡ������
		cout << "======================================" << endl;
	}
protected:
	string _school;
	string _grade;
};



/**
 * ����һ��CollegeStudent�������࣬�������רҵ��ѧ�����ŵ�����.
 */
class CollegeStudent :public Student
{
public:
	CollegeStudent(string name, Sex sex, string school,
		string grade, string major, string student_organizations)
		:Student(name, sex, school, grade), _major(major), 
		_student_organizations(student_organizations) {}
	CollegeStudent(const CollegeStudent& cs) = default;
	~CollegeStudent() = default;
public:
	virtual void set_grade() //��д�����麯��
	{
		cout << "CollegeStudent::set_grade() called" << endl;
		cout << "please input the name:"; cin >> this->_name;
		cout << "please input the sex(male/female)";
		string sex_tmp;
		cin >> sex_tmp;
		if (sex_tmp == "male")this->_sex = MALE;
		else if (sex_tmp == "female")this->_sex = FEMALE;
		else assert(false);//��������
		cout << "please input the school name:"; cin >> this->_school;
		cout << "please input the grade name"; cin >> this->_grade;
		cout << "please input the major"; cin >> this->_major;
		cout << "please input the student organizations"; cin >> this->_student_organizations;
	}
public:
	virtual void Work()const
	{
		cout << "CollegeStudent::Work()" << endl;
	}
	virtual void Run()const
	{
		cout << "CollegeStudent::Run()" << endl;
	}
	virtual void Study()const
	{
		cout << "CollegeStudent::Study()" << endl;
	}
	virtual void ReportGrades()const
	{
		cout << "CollegeStudent::ReportGrades()" << endl;
	}
public:
	virtual void get_person_info()const
	{
		cout << "======================================" << endl;
		cout << "CollegeStudent::_name" << " " << this->_name << endl;
		cout << "CollegeStudent::_sex" << " " << this->_sex << endl;
		cout << "CollegeStudent::_school" << " " << this->_school << endl;
		cout << "CollegeStudent::_grade" << " " << this->_grade << endl;
		cout << "CollegeStudent::_major" << " " << this->_major << endl;
		cout << "CollegeStudent::_student_organizations" << " " << this->_student_organizations << endl;
		cout << "CollegeStudent::function call:" << endl;
		this->Work();
		this->Run();
		this->Study();
		this->ReportGrades();
		//this->set_grade(); //��ʱ�������� -- Ӱ���ӡ������
		cout << "======================================" << endl;
	}
protected:
	string _major;
	string _student_organizations;
};

/**
 * ʵ��һ��report(const Person *)��������ӡ���ö�����������ԣ������������к���.
 * ����Ϊ�˴�ӡ�������� -- ���������set_grade()�ӿ�
 */
void report(const Person* pPerson)
{
	cout << typeid(*pPerson).name() << endl;//��ӡ������
	pPerson->get_person_info();
	cout << endl << endl;
}

/**
 * main�����ʵ����2��Student����2��CollegeStudent���󣬴����һ���������棬Ȼ��ѭ������report������.
 */
int main()
{
	Student s1("James", MALE, "NBA", "18");
	Student s2("Curry", MALE, "NBA", "14");
	CollegeStudent cs1("Jack", MALE, "SYSU", "1","Math","baseball");
	CollegeStudent cs2("Sam", FEMALE, "SYSU", "2", "Chinese", "basketball");
	Student* student_info_list[] = { &s1,&s2,&cs1,&cs2 };
	for (auto e : student_info_list)
	{
		report(e);
	}
	return 0;
}