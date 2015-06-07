#include "enemy.h"
#include "mainframe.h"

__ENEMY::__ENEMY() :__PLAYER()
{
	teleport(500, 400);            //初始化__ENEMY数据
	setDir(0);
	setMaxHp(100);
	setHp(50);
	setAttack(10);
	setSpd(10);     //单位px
	setSkillState(0);
	setSkillType(0);
	addEnemyAmount();
}

__ENEMY::~__ENEMY() 
{
	redEnemyAmount();
}

void __ENEMY::addEnemyAmount()
{
	enemyAmount++;
}

void __ENEMY::redEnemyAmount()
{
	enemyAmount--;
}

int __ENEMY::getEnemyAmount()
{
	return enemyAmount;
}