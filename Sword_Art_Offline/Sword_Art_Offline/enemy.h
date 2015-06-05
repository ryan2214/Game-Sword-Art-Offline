#pragma once

#include "player.h"

using namespace std;

typedef class __ENEMY:public __PLAYER
{
public:			
	__ENEMY();				
	~__ENEMY();
	int getEnemyAmount();
	void addEnemyAmount();
	void redEnemyAmount();
protected:
	int enemyAmount;
}enemy;