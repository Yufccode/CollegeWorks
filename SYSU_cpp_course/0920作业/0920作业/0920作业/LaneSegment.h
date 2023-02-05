#pragma once

#include"Vehicle.h"

/*
2.����һ��LaneSegment�࣬������Ա������float x_, float y_, float length_, float width_��
���У�(x_, y_)��ʾ�������Ͻǵ���ʼλ�ã�length_�ֱ��ʾ�����ͳ��ȣ���λm��
Vehicle�������飻
static const int maxVehicles��ʾ���������
ʵ�ֹ��캯�������ƹ��캯�����������������У�length_��width_��Ĭ��ֵ�ֱ�Ϊ��100��3.5
ʵ�ֳ�Ա����IsInLane(const Vehicle &veh)���жϳ������Ƿ���ڳ���veh��������ڷ���1�����򷵻�0��
ʵ�ֳ�Ա����AddVehicle((Vehicle &veh)���ڵ�·�������µĳ���veh��
ʵ�ֳ�Ա����RemoveVehicle(Vehicle &veh)���ڵ�·��ɾ������veh��
*/

/// <summary>
/// ��Ϊ��ҪƵ�����ҳ����ϵĳ����Ƿ���� -- ʹ�ù�ϣ�����ڳ�������ʱ���Ч��
/// </summary>

//����ϣ��ָ��ģ��(δ�ܳɹ�ʵ��)
# if 0  //�����⻹û��� -- �Զ���������key
struct hash_name {
	size_t operator()(const Vehicle& p) const {
		return hash<float>()(p._x) ^ hash<float>()(p._y)^hash<float>()(p._vx)^ 
			hash<float>()(p._vy)^ hash<float>()(p._width)^hash<float>()(p._height);
	}
};
class LaneSegment {
private:
	float _x;
	float _y;
	float _length;
	float _width;
	//vector<Vehicle>_arr; ѡ��ʹ�ù�ϣ -- ����Ч�ʸ�
	unordered_map<Vehicle, int, hash_name>_hash;  //�����Զ������Ͳ���ֱ�ӹ�ϣ�� -- ��Ҫ����ģ�嶨��
	static const int maxVehicles;
public:
	friend struct hash_name;
	LaneSegment(float x = 0, float y = 0, float length = 100, float width = 3.5)
		:_x(x), _y(y), _length(length), _width(width) {}
	LaneSegment(LaneSegment& l)
		: _x(l._x), _y(l._y), _length(l._length), _width(l._width) {}
	~LaneSegment() {
		cout << "ɾ���ó���" << endl;
	}
	bool isInLane(const Vehicle& veh) {
		if (_hash.find(veh) != _hash.end()) { //����Ч��:O(1)
			return true;
		}
		return false;
	}
	void AddVehicle(Vehicle& veh) {
		assert(_hash.size() != maxVehicles); //�������� -- �����ټ���
		++_hash[veh];
	}
	void RemoveVehicle(Vehicle& veh) {
		assert(_hash.find(veh) != _hash.end());//����Ч��:O(1)
		--_hash[veh];
	}
	size_t size() const {
		return _hash.size();
	}
};
const int LaneSegment::maxVehicles = 10;//���10����
#endif

//ʹ��vector��ų�
class LaneSegment {
private:
	float _x;
	float _y;
	float _length;
	float _width;
public:
	vector<Vehicle>_array;
	static const int maxVehicles;
public:
	LaneSegment(float x = 0, float y = 0, float length = 100, float width = 3.5)
		:_x(x), _y(y), _length(length), _width(width) {}
	LaneSegment(LaneSegment& l)
		: _x(l._x), _y(l._y), _length(l._length), _width(l._width) {}
	~LaneSegment() {
		cout << "ɾ���ó���" << endl;
	}
	bool isInLane(const Vehicle& veh) {
		for (int i = 0; i < _array.size(); i++) {
			if (veh == _array[i])return true;//�ҵ���
		}
		return false;//�Ҳ���
	}
	void AddVehicle(Vehicle& veh) {
		assert(_array.size() != maxVehicles); //�������� -- �����ټ���
		_array.push_back(veh);
	}
	void RemoveVehicle(Vehicle& veh) {
		for (int i = 0; i < _array.size(); i++) {
			if (_array[i] == veh) {
				_array.erase(_array.begin() + i);
			}
		}
		cout << "�Ҳ����ó�" << endl;
	}
	size_t size() const { //��������
		return _array.size();
	}
};	
const int LaneSegment::maxVehicles = 10;