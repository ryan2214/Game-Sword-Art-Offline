#pragma once

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef class __SKILLLIST
{
public:							/*构造析构函数*/
	__SKILLLIST();				//默认是空
	~__SKILLLIST();
public:
	int getDM(int);		                  //获取技能伤害倍数
	const string getSkillName(int) const; //获取技能名称
	static bool ableToCast(int);          //判断是否能够释放（cooldown&距离）
protected:						
	int skillNumber;                      //技能编号
	string English;                       //技能名称
	int damageMultiply;                   //技能伤害倍数
	int castDistance;                     //技能释放距离
}skillList;