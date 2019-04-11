#include "player.h"

player::player()
{
}

player::~player()
{

}

int player::getHealth()
{
	return m_nHealth;
}

int player::getDamage()
{
	return m_nDamage;
}

int player::getBlockDamage()
{
	return m_nBlockDamage;
}

int player::getStamina()
{
	return m_nStamina;
}

int player::getBandage()
{
	return m_nBandage;
}

void player::setHealth(int nHealth)
{
	m_nHealth = nHealth;
}

void player::setStamina(int nStamina)
{
	m_nStamina = nStamina;
}

void player::setBandage(int nBandage)
{
	m_nBandage = nBandage;
}

void player::setDamage(int nDamage)
{
	m_nDamage = nDamage;
}

void player::setBlockDamage(int nBlockDamage)
{
	m_nBlockDamage = nBlockDamage;
}