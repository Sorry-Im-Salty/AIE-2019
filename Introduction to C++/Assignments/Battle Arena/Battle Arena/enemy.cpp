#include "enemy.h"
#include <iostream>

enemy::enemy()
{
}

enemy::~enemy()
{
}

int enemy::getHealth()
{
	return m_nHealth;
}

int enemy::getDamage()
{
	return m_nDamage;
}

int enemy::getBlockDamage()
{
	return m_nBlockDamage;
}

int enemy::getStamina()
{
	return m_nStamina;
}

const char* enemy::getName()
{
	return m_szName;
}

void enemy::setHealth(int nHealth)
{
	m_nHealth = nHealth;
}

void enemy::setStamina(int nStamina)
{
	m_nStamina = nStamina;
}

void enemy::setDamage(int nDamage)
{
	m_nDamage = nDamage;
}

void enemy::setBlockDamage(int nBlockDamage)
{
	m_nBlockDamage = nBlockDamage;
}

void enemy::setName(const char* szName)
{
	strcpy(m_szName, szName);
}