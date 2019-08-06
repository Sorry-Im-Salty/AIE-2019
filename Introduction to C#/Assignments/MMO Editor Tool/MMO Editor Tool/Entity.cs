using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MMO_Editor_Tool
{
	public class Entity
	{
		private int sType;
		private int sSubType;
		private string sName;
		private int nHealth;
		private int nSpeed;
		private int nStrength;
		private int nRange;
		private int nMagic;
		private int nAgility;
		private int nPrice;
		private int nLevelReq;

		public void setType(int type)
		{
			sType = type;
		}
		public int getType()
		{
			return sType;
		}

		public void setSubType(int subType)
		{
			sSubType = subType;
		}
		public int getSubType()
		{
			return sSubType;
		}

		public void setName(string name)
		{
			sName = name;
		}
		public string getName()
		{
			return sName;
		}

		public void setHealth(int health)
		{
			nHealth = health;
		}
		public int getHealth()
		{
			return nHealth;
		}

		public void setSpeed(int speed)
		{
			nSpeed = speed;
		}
		public int getSpeedh()
		{
			return nSpeed;
		}

		public void setStrength(int strength)
		{
			nStrength = strength;
		}
		public int getStrength()
		{
			return nStrength;
		}

		public void setRange(int range)
		{
			nRange = range;
		}
		public int getRange()
		{
			return nRange;
		}

		public void setMagic(int magic)
		{
			nMagic = magic;
		}
		public int getMagic()
		{
			return nMagic;
		}

		public void setAgility(int agility)
		{
			nAgility = agility;
		}
		public int getAgility()
		{
			return nAgility;
		}

		public void setPrice(int price)
		{
			nPrice = price;
		}
		public int getPrice()
		{
			return nPrice;
		}

		public void setLevelReq(int LevelReq)
		{
			 nLevelReq = LevelReq;
		}
		public int getLevelReq()
		{
			return nLevelReq;
		}
	}
}
