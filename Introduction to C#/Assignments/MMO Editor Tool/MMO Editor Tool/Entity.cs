using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MMO_Editor_Tool
{
	public class Entity
	{
		public string nType { get; set; }
		public string nSubType { get; set; }
		public string sName { get; set; }
		public int nHealth { get; set; }
		public int nSpeed { get; set; }
		public int nStrength { get; set; }
		public int nRange { get; set; }
		public int nMagic { get; set; }
		public int nAgility { get; set; }
		public int nPrice { get; set; }
		public int nLevelReq { get; set; }
		public string sSprite { get; set; }
	}
}