
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#include"FileQuery.h"
#include <fstream>
#include <iostream>
#include <string>
#include <direct.h>
using namespace std;
#elif
#endif

void query(FileQuery& fq)
{
	while (1)
	{
		string str;
		cout << "��������Ҫ��ѯ�ĵ���(����q�˳���ѯ):";
		cin >> str;
		if (str == "q")break;
		fq.Find(str);
	}
}

/**
 * �������ڵ��õ�ʱ���Ƿֱ���õ� -- ����һ�δ�ӡ̫�ණ��
 * ��ʦ�����Ҫ���Էֱ�ȡ���ӿڵ��õ�ע�ͼ���~.
 * �������ɼ�txt�ļ�
 */
void runFileQuery(ifstream& infile)
{
	//start the sys!
	FileQuery sys(infile);
	//sys.print_sentences();
	//sys.print_sentences_ascend();
	//sys.print_word_count();
	//cout << "------------------ ��ӡƵ��ǰ5�ߵĵ��� ------------------" << endl;
	//sys.print_top_world_context(5);
	//cout << "------------------ ��ӡƵ��ǰ4�ߵĵ��� ------------------" << endl;
	//sys.print_top_world_context(4);
	//cout << "------------------ ��ӡƵ��ǰ3�ߵĵ��� ------------------" << endl;
	//sys.print_top_world_context(3);
	//sys.Find("the");
	//query(sys);
	sys.Replace("the", "xxx");
	sys.Replace("my", "__my__");
	sys.Replace("o", "__o__");
	sys.Replace("kajfkasf", "adfasdf");//�������Ҳ����õ���
	query(sys);
	//cout << endl;
	//FileQuery sys2(sys);
	//sys2.Find("her");//���Կ���֤�� -- ����ɹ�
	cout << endl;
}

int main(int argc, char** argv)
{
	// open the file from which user will query words
	if (argc >= 2) 
	{
		ifstream infile(argv[1]);
		if (infile.is_open()) 
		{
			runFileQuery(infile);
		}
		else 
		{
			cerr << "Failed opening input file!" << endl;
			return -1;
		}
	}
	else {
		cerr << "No input file name!" << endl;
	}
	return 0;
}