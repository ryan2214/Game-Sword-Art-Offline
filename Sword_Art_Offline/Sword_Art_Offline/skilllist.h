#pragma once

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef class __SKILLLIST
{
public:							/*������������*/
	__SKILLLIST();				//Ĭ���ǿ�
	~__SKILLLIST();
public:
	int getDM(int);		                  //��ȡ�����˺�����
	const string getSkillName(int) const; //��ȡ��������
	static bool ableToCast(int);          //�ж��Ƿ��ܹ��ͷţ�cooldown&���룩
protected:						
	int skillNumber;                      //���ܱ��
	string English;                       //��������
	int damageMultiply;                   //�����˺�����
	int castDistance;                     //�����ͷž���
}skillList;