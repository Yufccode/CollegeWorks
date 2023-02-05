#define _CRT_SECURE_NO_WARNINGS 1

#include"Vehicle.h"
#include"LaneSegment.h"
#include"RoadSegment.h"
#include<random>
void test_Vehicle() {
	Vehicle v1;
	cout << v1 << endl;
	Vehicle v2 = v1;
	cout << v2;
	cout << v2.isCollision(v1) << endl;
	cout <<"����Ŀǰ������:"<< Vehicle::_vCount << endl;
}


void test() {
	unordered_map<int, int>hash;
	vector<int>arr = { 1,2,3,4,5 };
	for (int i = 0; i < arr.size(); i++) {
		++hash[arr[i]];
	}
	cout << hash.size() << endl;
}
/*
1��	�½�RoadSegment�����¶���������������
2��	ͨ�����������ÿ����������������2����
3��	���ɹ����У����������������ײ�����������ɣ�ֱ����������ײ
4��	ɾ��������ĳ������䳵���ڵĳ���
�ļ���֯��ÿһ���඼����ʵ��Ϊh�ļ���cpp�ļ�����main�����ڲ����в��ԡ�
*/
bool is_valid(const LaneSegment& l, Vehicle v) {
	//�����ж�v�᲻���l����ĳ���ײ
	for (int i = 0; i < l._array.size(); i++) {
		if (l._array[i].isCollision(v)) {
			return false;
		}
	}
	return true;
}
void add_cars_in_lanes(LaneSegment& l, float y_min, float y_max) {
	///(y_min,y_max)��ʾ�������ϵ��µĿ��
	//�������������
	default_random_engine e(time(0));
	for (int i = 0; i < 2; i++) {//��ʾ����������
		bool flag = false;//��ʾ���ɵĳ����Ƿ�Ϸ�
		do {
			uniform_real_distribution<float>u(y_min, y_max);//y�ķ�Χ
			uniform_real_distribution<float>ux(2.0, 8.0); //x�ķ�Χ
			float x = ux(e);
			float y = u(e);
			Vehicle v(x, y);
			if (is_valid(l,v)) {
				flag = true;
				l.AddVehicle(v);//��v�ӽ�ȥ
			}
		} while (!flag);//�������Ϸ�֮��  --  ����ѭ����׼�����ɵڶ�����
	}
}
void test_homework() {
	LaneSegment l1(0, 0);
	LaneSegment l2(0, 5);
	LaneSegment l3(0, 10);
	add_cars_in_lanes(l1, 1, 2.5);
	add_cars_in_lanes(l2, 6, 7.5);//�������Χ������ -- ��Ϊ�����п��
	add_cars_in_lanes(l3, 11, 12.5);
	RoadSegment r;
	r.AddLane(&l1);
	r.AddLane(&l2);
	r.AddLane(&l3);
	r.pop_back();
}
int main() {
	//test_Vehicle();
	test_homework();
	return 0;
}