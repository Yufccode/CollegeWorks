#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif

#include"Student.h"
#include"PointVector.h"
#include"SparseMatrix.h"

#if 1
bool ascending(const Student* first, const Student* second) {
	return first->_id < second->_id;
}
bool descending(const Student* first, const Student* second) {
	return first->_id > second->_id;
}
int main() {
	string courseNames1[] = {"Robotics","C++","Math"};
	string courseNames2[] = { "Robotics","C++","" };//��"" -- ����string�Ĺ��캯����������
	double BobGrade[] = { 99.1,88.7 };
	double JohnGrade[] = { 100.0,89.7,78.0 };
	double AliceGrade[] = { 45,0,90.5,99.2 };
	//Student(int id, string name, string* courseNames, double* grades, size_t size)
	//��ʼ�������˵ĳɼ�
	Student Bob(102, "Bob", courseNames2, BobGrade, 2);
	Bob.ShowGrades();
	Student John(101, "John", courseNames1, JohnGrade, 3);
	John.ShowGrades();
	Student Alice(103, "Alice", courseNames1, AliceGrade, 3);
	Alice.ShowGrades();

	//��Bob���Math��Ŀ
	Bob.AddCourse("Math", 90.0);
	Bob.ShowGrades();

	//��Bob��Math�ĳ�70��
	Bob.SetGrade("xxx", 30);
	Bob.SetGrade("Math", 70);
	Bob.ShowGrades();

	//���ҿγ̷���
	Bob.GetGrade("xxx");//����Ҳ��� -- ��ӡ������Ϣ
	cout << Bob.GetGrade("Math") << endl;//70
	
	//������˿γ�ƽ����
	cout << "Bob���ſε�ƽ����Ϊ:" << endl;
	cout << Bob.GetAverageGrade() << endl;

	cout << endl << endl << endl;

	//����StudentClass��
	//StudentClass(string code, Student** students, size_t cnt_stu)
	Student* student[] = { &Bob,&John ,&Alice };
	StudentClass s("22", student, 3);

	//void Addstudent(const Student * student)
	//�������ѧ����Ϣ
	//Student(int id, string name, string* courseNames, double* grades, size_t size)
	Student Sam(100, "Sam", courseNames1, JohnGrade, 3);
	s.Addstudent(&Sam);
	s.ShowStudent(101);//����idΪ101��ѧ����Ϣ
	cout << endl << endl << endl;
	cout << "�����������Ľ��" << endl;
	s.ShowStudentByIdOrder(descending);
	cout << endl << endl;
	s.showStudentCount();//չʾѧ������
	cout << endl;

	//ʹ�õ�������ӡ����ѧ�������
	StudentClass::iterator it = s.begin();
	while (it != s.end()) {
		cout << *it << endl;
		it++;
	}
	return 0;
}
#endif


#if 0
int main() {

	PointVector pvec;
	if (pvec.empty()) {
		cout << "empty point vector!" << endl;
	}

	cout << endl;
	for (int i = 0; i < 20; i++) {
		pvec.push_back(Point(i, i));
		cout << "size=" << pvec.size() << "capacity=" << pvec.capacity() << endl;
	}

	cout << endl;
	pvec.front().print();
	pvec.back().print();


	PointVector pvec1(pvec);
	cout << pvec1 << endl;

	PointVector pvec2;
	pvec2 = pvec1;
	for (size_t j = 0; j < pvec2.size(); j++) {
		cout << pvec2.at(j)._x << " " << pvec2[j]._y << endl;
	}

	pvec.insert(0, Point(100, 100));
	cout << pvec << endl;
	pvec.erase(pvec.size() / 2);
	cout << pvec << endl;
	cout << pvec1 + pvec2 << endl;


	//���Ե�����
	PointVector::iterator it = pvec.begin();
	while (it != pvec.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}
#endif



#if 0
int main() {
#if 0
	cout << "======== ���Կ������� ========" << endl;
	vector<vector<double>>arr = { {1, 2, 3}, { 2,0,4 } ,{1,0,1} };
	SparseMatrix sm(arr);
	SparseMatrix sm2 = sm;
	sm.output_Matrix_by_vector();
	cout << endl;
	sm2.output_Matrix_by_vector();
#endif
#if 1
	vector<vector<double>>arr = { {1, 2, 3}, { 2,0,4 } ,{1,0,1} };
	SparseMatrix sm(arr);
	sm.output_Matrix_by_vector();
	cout << endl;
	vector<vector<double>>arr2 = { {1,0,0},{1,0,0},{1,0,0} };
	SparseMatrix sm2(arr2);
	sm2.output_Matrix_by_vector();
	cout << endl;
	sm.subtract(sm2);
	sm.output_Matrix_by_vector();

	cout << "============== �������� ==============" << endl;
	sm.output_Matrix_by_vector();
	cout << endl;
	sm2.output_Matrix_by_vector();
	cout << endl;
#if 1 //BUG
	vector<vector<double>>arr3 = { {0,0,0},{0,0,0},{0,0,0} };
	SparseMatrix sm3(arr3);
	sm3 = sm + sm2;
	sm3.output_Matrix_by_vector();
#endif
	cout << "=============== �������������� ==================" << endl;
	vector<vector<double>>arr5 = { {1, 2, 3}, { 2,0,4 } ,{1,0,1} };
	SparseMatrix sm5(arr);
	cout << sm5 << endl;
	cout << "=============== ����get/set ====================" << endl;
	vector<vector<double>>arr6 = { {1, 2, 3}, { 2,0,4 } ,{1,0,1} };
	SparseMatrix sm6(arr6);
	cout << sm6 << endl;
	cout << sm6.get(1, 2) << endl;
	sm6.set(1, 2, 0);
	sm6.set(1, 3, 100);
	cout << sm6 << endl;
#endif
	return 0;
}
#endif