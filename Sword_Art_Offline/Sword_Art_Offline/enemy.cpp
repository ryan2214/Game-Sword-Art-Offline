#include "enemy.h"

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
}

__ENEMY::~__ENEMY() {}