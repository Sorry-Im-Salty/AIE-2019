#pragma once

class player
{
public:
	player(); // Contructor.
	~player(); // Destructor.
	int getHealth(); // Returns the player's health.
	int getDamage(); // Returns the player's damage.
	int getBlockDamage(); // Returns the player's block damage.
	int getStamina(); // Returns the player's stamina.
	int getBandage(); // Returns the number of bandages the player has.
	void setHealth(int nHealth); // Sets the player's health.
	void setStamina(int nStamina); // Sets the player's stamina.
	void setBandage(int nBandage); // Sets the player's bandage number.
	void setDamage(int nDamage); // Sets the player's damage.
	void setBlockDamage(int nBlockDamage); // Sets the player's block damage.

private:
	int m_nHealth; // Health.
	int m_nDamage; // Damage.
	int m_nBlockDamage; // Block Damage.
	int m_nStamina; // Stamina.
	int m_nBandage; // Bandages.
};