#pragma once

#include "player.h"

using namespace std;

typedef class __ENEMY:public __PLAYER
{
public:			
	__ENEMY();				
	~__ENEMY();
	static int getEnemyAmount();
protected:
	static int enemyAmount;
}enemy;