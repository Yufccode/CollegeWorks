


/*****************************************************************//**
 * \file   Student.h
 * \brief  
 * 
 * \author yfc 21312780
 * \date   October 2022
 *********************************************************************/


#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<cassert>
using namespace std;


/*********************************************** Student�� ***********************************************/

class Student {
private:
	static const size_t maxCourses = 3;
private:
	int _id;
	string _name;
	string _courseNames[maxCourses];
	double _grades[maxCourses];
	size_t _cnt_Course;
public:
	friend class StudentClass;
	friend bool ascending(const Student* first, const Student* second);
	friend bool descending(const Student* first, const Student* second);
	friend ostream& operator<<(ostream& out, const Student& st);
public:
	Student();
	Student(int id, string name, string* courseNames, double* grades, size_t size);
	Student(const Student& s);
	~Student();
	Student& operator=(const Student& s);
	bool AddCourse(const string& courseName, double grade);
	void SetGrade(const string& courseName, double grade);
	double GetGrade(const string& courseName) const;
	double GetAverageGrade()const;
	void ShowGrades()const;
};

/*********************************************** Student����ؽӿڶ��� ***********************************************/

Student::Student()
	:_cnt_Course(0)
{
	//�Ѿ������ռ���
	//_courseNames = new string[maxCourses];
	//_grades = new double[maxCourses];
}
Student::Student(int id, string name, string* courseNames, double* grades, size_t size)
	:_id(id), _name(name), _cnt_Course(size)
{
#if 0 //err ����memcpy -- memcpy�������string�ĸ�ֵ -- ��Խ�����
	memcpy(_courseNames, courseNames, sizeof(string) * maxCourses);
	memcpy(_grades, grades, sizeof(double) * maxCourses);
#endif
	for (int i = 0; i < maxCourses; i++) {
		_courseNames[i] = courseNames[i];
	}
	for (int i = 0; i < maxCourses; i++) {
		_grades[i] = grades[i];
	}
}
Student::Student(const Student& s) {
	//��������
	this->_id = s._id;
	this->_name = s._name;
#if 0//err
	memcpy(this->_courseNames, s._courseNames, sizeof(string) * maxCourses);
	memcpy(this->_grades, s._grades, sizeof(double) * maxCourses);
#endif
	for (int i = 0; i < maxCourses; i++) {
		_courseNames[i] = s._courseNames[i];
	}
	for (int i = 0; i < maxCourses; i++) {
		_grades[i] = s._grades[i];
	}
	this->_cnt_Course = s._cnt_Course;
}
Student::~Student() {//����
	_id = 0;
	_name.clear();
	_cnt_Course = 0;
}
Student& Student::operator=(const Student& s) {
	if (this == &s)return*this;
	this->_id = s._id;
	this->_name = s._name;
	//memcpy(this->_courseNames, s._courseNames, sizeof(string) * maxCourses);
	//memcpy(this->_grades, s._grades, sizeof(double) * maxCourses);
	for (int i = 0; i < maxCourses; i++) {
		_courseNames[i] = s._courseNames[i];
	}
	for (int i = 0; i < maxCourses; i++) {
		_grades[i] = s._grades[i];
	}
	this->_cnt_Course = s._cnt_Course;
	return *this;
}
bool Student::AddCourse(const string& courseName, double grade) {
	if (_cnt_Course == maxCourses) {
		cout << "�γ�����!" << endl;
		return false;
	}
	string tmp = courseName;
	_courseNames[_cnt_Course] = tmp;//
	_grades[_cnt_Course] = grade;
	cout << "��ӳɹ�" << endl;
	++_cnt_Course;
	return true;
}
void Student::SetGrade(const string& courseName, double grade) {
	//���ҵ���ΪcoureName�Ŀγ�����Ӧ���±�
	int idx = 0;
	for (; idx < 3; idx++) {
		if (this->_courseNames[idx] == courseName)break;
	}
	if (idx == 3) {
		cout << "�Ҳ����ÿγ���Ϣ" << endl;
		return;
	}
	this->_grades[idx] = grade;
	cout << "�޸ĳɹ�" << endl;
}
double Student::GetGrade(const string& courseName) const {
	for (int i = 0; i < 3; i++) {
		if (this->_courseNames[i] == courseName) {
			return this->_grades[i];
		}
	}
	cout << "�Ҳ����ÿγ���Ϣ" << endl;
	return -1;//�Ҳ����ÿγ���Ϣ
}
double Student::GetAverageGrade()const {
	double grade_sum = 0;
	for (int i = 0; i < this->_cnt_Course; i++) {
		grade_sum += this->_grades[i];
	}
	return grade_sum / this->_cnt_Course;
}
void Student::ShowGrades()const {
	cout << "=====================================" << endl;
	cout << "Name:" << this->_name << endl;
	cout << "id:" << this->_id << endl;
	for (int i = 0; i < this->_cnt_Course; i++) {
		cout << this->_courseNames[i] << ":" << this->_grades[i] << endl;
	}
	cout << "=====================================" << endl;
}
//��������ȡ
ostream& operator<<(ostream& out, const Student& st) {
	cout << "=====================================" << endl;
	cout << "Name:" << st._name << endl;
	cout << "id:" << st._id << endl;
	for (int i = 0; i < st._cnt_Course; i++) {
		cout << st._courseNames[i] << ":" << st._grades[i] << endl;
	}
	cout << "=====================================" << endl;
	return out;
}



/*********************************************** __StudentClass_iterator�� ***********************************************/

//StudentClass������ -- ���ڱ���
template<class Ref,class Ptr> //const���Ϳ��ԣ�����const����Ҳ����
struct __StudentClass_iterator {
public:
	Ptr _pointer;
public:
	__StudentClass_iterator(Ptr pointer)
		:_pointer(pointer) {}
	//���Ƶ�����������Ϊ
	Student operator*() {
		return **(this->_pointer);//��ΪStudentClass���������ָ��
	}
	Ref operator->() {
		return *(this->_pointer);
	}
	__StudentClass_iterator& operator++() { //ǰ��++
		_pointer++;
		return *this;
	}
	__StudentClass_iterator operator++(int) { //����++
		__StudentClass_iterator tmp(*this);//��ʱ����һ�����ڵĶ���
		_pointer++;
		return tmp;
	}
	//--��ͬһ���������ظ�ʵ���ˣ����ֻ��������ò���--
	bool operator!=(const __StudentClass_iterator& it)const {
		return _pointer != it._pointer;
	}
	bool operator==(const __StudentClass_iterator& it)const {
		return _pointer == it._pointer;
	}
};



/*********************************************** StudentClass�� ***********************************************/

class StudentClass {
private:
	static const size_t maxStudents = 20;
	static size_t _studentCount;
	string _code;
	Student* _students[maxStudents];
public:
	//ֻҪ������ -- ���ǾͿ����ṩ������
	typedef __StudentClass_iterator<Student*&, Student**> iterator;
	typedef __StudentClass_iterator<const Student*&, const Student**> const_iterator;
	iterator begin() {
		return iterator(_students);
	}
	iterator end() {
		return iterator(_students + _studentCount);
	}
	const_iterator begin()const {
		return const_iterator((const Student**)_students);
	}
	const_iterator end()const {
		return const_iterator((const Student**)_students + _studentCount);
	}
public:
	StudentClass();
	StudentClass(string code, Student** students, size_t cnt_stu);
	~StudentClass();
	StudentClass(const StudentClass& sc);
	StudentClass& operator=(const StudentClass& sc);
	//��ȡ����
	void Addstudent(const Student* student);
	void ShowStudent(int id)const;
	void ShowStudentByIdOrder(bool(*compare)(const Student*, const Student*));
	static void showStudentCount() {
		cout << "�������е�ѧ������Ϊ:" << _studentCount << endl;
	}
};
size_t StudentClass::_studentCount = 0;



/*********************************************** StudentClass����ؽӿڶ��� ***********************************************/

StudentClass::StudentClass()
{
	++_studentCount;
}
StudentClass::StudentClass(string code, Student** students, size_t cnt_stu)
	:_code(code)
{
	_studentCount = cnt_stu;
	memcpy(this->_students, students, sizeof(Student*) * cnt_stu);
}
StudentClass::~StudentClass() { //����
	_studentCount = 0;
	_code.clear();
}
StudentClass::StudentClass(const StudentClass& sc) {
	++_studentCount;
	this->_studentCount = sc._studentCount;
	this->_code = sc._code;
	memcpy(this->_students, sc._students, sizeof(Student*) * sc._studentCount);
}
StudentClass& StudentClass::operator=(const StudentClass& sc) {
	if (this == &sc)return*this;
	//++_studentCount;
	this->_studentCount = sc._studentCount;
	this->_code = sc._code;
	memcpy(this->_students, sc._students, sizeof(Student*) * sc._studentCount);
	return *this;
}
//��ȡ����
void StudentClass::Addstudent(const Student* student) {
	assert(this->_studentCount != maxStudents);//�ж��Ƿ��ܷŵ���
	//Student(int id, string name, string* courseNames, double* grades, size_t size)
	Student* tmp = new Student((*student));
	this->_students[this->_studentCount] = tmp;
	++_studentCount;
}
void StudentClass::ShowStudent(int id)const {
	for (int i = 0; i < _studentCount; i++) {
		if (this->_students[i]->_id == id) {
			//չʾѧ����Ϣ
			cout << "****************************************" << endl;
			cout << "Name:" << this->_students[i]->_name << endl;
			cout << "id:" << this->_students[i]->_id << endl;
			this->_students[i]->ShowGrades();//����չʾ�ɼ��Ľӿ�
			cout << "****************************************" << endl;
			return;
		}
	}
}
void StudentClass::ShowStudentByIdOrder(bool(*compare)(const Student*, const Student*)) {
	sort(this->_students, this->_students + _studentCount, compare);
	//չʾ����ѧ����Ϣ
	for (int i = 0; i < _studentCount; i++) {
		//չʾѧ����Ϣ
		this->_students[i]->ShowGrades();//����չʾ�ɼ��Ľӿ�
	}
}