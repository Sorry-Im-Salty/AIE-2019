#pragma once

class enemy
{
public:
	enemy(); // Contructor.
	~enemy(); // Destructor.
	int getHealth(); // Returns the enemy's health.
	int getDamage(); // Returns the enemy's damage.
	int getBlockDamage(); // Returns the enemy's block damage.
	int getStamina(); // Returns the enemy's stamina.
	const char* getName(); // Returns the enemy's name.
	void setHealth(int nHealth); // Sets the enemy's health.
	void setStamina(int nStamina); // Sets the enemy's stamina.
	void setDamage(int nDamage); // Sets the enemy's damage.
	void setBlockDamage(int nBlockDamage); // Sets the enemy's block damage.
	void setName(const char* szName); // Sets the enemy's name.

private:
	int m_nHealth; // Health.
	int m_nDamage; // Damage.
	int m_nBlockDamage; // Block Damage.
	int m_nStamina; // Stamina.
	char m_szName[64]; // Name.
};