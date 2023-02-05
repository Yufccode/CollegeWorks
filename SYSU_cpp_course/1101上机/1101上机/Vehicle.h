#pragma once


#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
#include<functional>
#include<numeric>
using namespace std;


//��ĿҪ�������һ�����μ̳�
class Vehicle {
public:
	size_t maxSpeed = 0;
	size_t Weight = 0;
public:
	Vehicle() = default;
	Vehicle(const Vehicle& v) = default;
	~Vehicle() = default;
public:
	virtual void run() {
		cout << "Vehicle::run()" << endl;
	}
	virtual void stop() {
		cout << "Vehicle::stop()" << endl;
	}
};
class Bicycle :virtual public Vehicle {
public:
	size_t height = 0;
	virtual void run() {
		cout << "Bicycle::run()" << endl;
	}
	virtual void stop() {
		cout << "Bicycle::stop()" << endl;
	}
};
class Automobile :virtual public Vehicle {
public:
	size_t seatCount = 0;
	virtual void run() {
		cout << "Automobile::run()" << endl;
	}
	virtual void stop() {
		cout << "Automobile::stop()" << endl;
	}
};
class Motocycle :public Bicycle, public Automobile {
public:
	void run() {
		cout << "Motocycle::run()" << endl;
	}
	void stop() {
		cout << "Motocycle::stop()" << endl;
	}
};


void test_Vehicle() {
	Vehicle v;
	Automobile a;
	Motocycle m;
	//��������̳л���������ԺͶ���������
	m.maxSpeed = 10;//��ʱ��maxSpeed����ͬһ��������
	//m.run();
	//������Բ����麯��������̬
	Vehicle* pv = &m;//�������һ����Ƭ
	pv->run();//��̬����
	cout << endl;
}