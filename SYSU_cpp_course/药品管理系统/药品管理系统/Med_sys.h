#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<memory.h>


//��ʾһ������Ľڵ�
enum Administration
{
	Take_orally, //�ڷ�
	external	//����
};
struct ListNode //�ṹ���ڲ��ĳ�Ա��Ӧ��ʹ��һ��__��Ϊ��ͷ���������õ�ϰ��
{
	//�����������д�ã���ʵ���е��ַ����鶼Ӧ��malloc���� -- �����ǿ��ռ䵽ջ��
	char __drug_name[20];
	size_t __id;
	Administration adm_type;//���÷�ʽ -- ������һ��ö��
	char __effect[20];
	char __side_effect[20];
	struct ListNode* __next;
};

typedef struct ListNode Med_Node;

Med_Node* CreatList(Med_Node* head)
{
	//��ʼ������
}
void DestroyList(Med_Node* head)
{
	//��������
}
void modify_info(Med_Node* head)
{
	//�޸�ҩ����Ϣ
	//����ѭ���޸�
	//˼·��
	//������ҩƷ���� -- �������в���(���ҿ��Ը�������findϵ�еĺ���)�Ƿ���ڣ���������ڣ���ӡ��������...����������ڣ��޸�

	//��ӡ���޸ĳɹ���
}
void input_info(Med_Node* head)
{
	//����ҩ����Ϣ
	//����ѭ������


	//����ɹ���
}

//���
Med_Node* find_by_name(Med_Node* head)
{
	//ͨ��ҩƷ�������
}
Med_Node* find_by_id(Med_Node* head)
{
	//ͨ��ҩƷ��Ų���
}
Med_Node* find_by_classes(Med_Node* head)
{
	//ͨ��ҩƷ������в���
}
Med_Node* find_by_effect(Med_Node* head)
{
	//ͨ����/�����ò���
}
void print_info(Med_Node* node)
{

}
void print(Med_Node* head)
{

}