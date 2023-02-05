#pragma once

#include"LaneSegment.h"


/*
3.����һ��RoadSegment�࣬������
ʵ�ֹ��캯��������������
����static const int maxLanes��Ա����ʾ��󳵵�����
����Lane�������飻
ʵ�ֳ�Ա����AddLane(Lane & lane)���ڵ�·�����ӳ���lane��
*/

/*
1��	�½�RoadSegment�����¶���������������
2��	ͨ�����������ÿ����������������2����
3��	���ɹ����У����������������ײ�����������ɣ�ֱ����������ײ
4��	ɾ��������ĳ������䳵���ڵĳ���
�ļ���֯��ÿһ���඼����ʵ��Ϊh�ļ���cpp�ļ�����main�����ڲ����в��ԡ�
*/

#if 1
class RoadSegment {
public:
	RoadSegment() {}
	~RoadSegment() {}
	void AddLane(LaneSegment*lane) {
		_lane.push_back(lane);
	}
	void pop_back() {
		_lane.pop_back();
	}
private:
	vector<LaneSegment*>_lane;
public:
	static const int maxLanes;
};
const int RoadSegment::maxLanes = 10;//���10������
#endif