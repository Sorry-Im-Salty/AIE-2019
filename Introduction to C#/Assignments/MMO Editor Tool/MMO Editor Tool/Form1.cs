using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace MMO_Editor_Tool
{	
	public partial class formMain : Form
	{
		public formMain()
		{
			InitializeComponent();
		}

		Entity m_Entity = new Entity();
/* ====================================================================================*/
		// Saving
		private void buttonSave_Click(object sender, EventArgs e)
		{
			SaveFileDialog saveFileDialogMain = new SaveFileDialog();
			saveFileDialogMain.Filter = "XML File|*.xml";
			saveFileDialogMain.Title = "Save";
			saveFileDialogMain.ShowDialog();

				XmlSerializer serializer = new XmlSerializer(typeof(Entity));
				using (FileStream fs = new FileStream("data.xml", FileMode.Create))
				{
					serializer.Serialize(fs, m_Entity);
				}
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			SaveFileDialog saveFileDialogMain = new SaveFileDialog();
			saveFileDialogMain.Filter = "XML File|*.xml";
			saveFileDialogMain.Title = "Save";
			saveFileDialogMain.ShowDialog();

			if (saveFileDialogMain.FileName != "")
			{
				XmlSerializer serializer = new XmlSerializer(typeof(Entity));
				StreamWriter file = new StreamWriter("Entity.xml");
				serializer.Serialize(file, m_Entity);
				file.Close();
			}
		}
/* ====================================================================================*/
		// Opening
		private void buttonOpen_Click(object sender, EventArgs e)
		{
			OpenFileDialog openFileDialogMain = new OpenFileDialog();
			openFileDialogMain.Filter = "XML File|*.xml";
			openFileDialogMain.Title = "Open";
			openFileDialogMain.ShowDialog();

			if (openFileDialogMain.FileName != "")
			{
				XmlSerializer serializer = new XmlSerializer(typeof(Entity));
				StreamReader file = new StreamReader("Entity.xml");
				m_Entity = (Entity)serializer.Deserialize(file);
				file.Close();
			}
		}

		private void openToolStripMenuItem_Click(object sender, EventArgs e)
		{
			OpenFileDialog openFileDialogMain = new OpenFileDialog();
			openFileDialogMain.Filter = "XML File|*.xml";
			openFileDialogMain.Title = "Open";
			openFileDialogMain.ShowDialog();

			if (openFileDialogMain.FileName != "")
			{
				XmlSerializer serializer = new XmlSerializer(typeof(Entity));
				StreamReader file = new StreamReader("Entity.xml");
				m_Entity = (Entity)serializer.Deserialize(file);
				file.Close();
			}
		}
		/* ====================================================================================*/
		// Assign Type
		private void comboBoxType_SelectedIndexChanged(object sender, EventArgs e)
		{
			m_Entity.setType(comboBoxType.SelectedIndex);

			if (comboBoxType.SelectedIndex == 0)
			{
				comboBoxSubType.Items.Clear();
				comboBoxSubType.Enabled = true;
				comboBoxSubType.Items.Add("Weapon");
				comboBoxSubType.Items.Add("Tool");
				comboBoxSubType.Items.Add("Ore");
				comboBoxSubType.Items.Add("Wood");
				comboBoxSubType.Items.Add("Currency");
				comboBoxSubType.Items.Add("Misc");
			}
			if (comboBoxType.SelectedIndex == 1)
			{
				comboBoxSubType.Items.Clear();
				comboBoxSubType.Enabled = true;
				comboBoxSubType.Items.Add("Enemy");
				comboBoxSubType.Items.Add("Neutral");
				comboBoxSubType.Items.Add("Friendly");
				comboBoxSubType.Items.Add("Shop");
			}
		}
		// Assign SubType
		private void comboBoxSubType_SelectedIndexChanged(object sender, EventArgs e)
		{
			m_Entity.setSubType(comboBoxSubType.SelectedIndex);

			if (comboBoxType.SelectedIndex == 0)
			{
				if (comboBoxSubType.SelectedIndex == 0)
				{
					numericUpDownHealth.Value = 0;
					numericUpDownHealth.Enabled = false;
					numericUpDownSpeed.Enabled = true;
					numericUpDownStrength.Enabled = true;
					numericUpDownRange.Enabled = true;
					numericUpDownMagic.Enabled = true;
					numericUpDownAgility.Value = 0;
					numericUpDownAgility.Enabled = false;
					numericUpDownPrice.Enabled = true;
					numericUpDownLevelReq.Enabled = true;
				}
				if (comboBoxSubType.SelectedIndex == 1)
				{
					numericUpDownHealth.Value = 0;
					numericUpDownHealth.Enabled = false;
					numericUpDownSpeed.Enabled = true;
					numericUpDownStrength.Value = 0;
					numericUpDownStrength.Enabled = false;
					numericUpDownRange.Value = 0;
					numericUpDownRange.Enabled = false;
					numericUpDownMagic.Value = 0;
					numericUpDownMagic.Enabled = false;
					numericUpDownAgility.Value = 0;
					numericUpDownAgility.Enabled = false;
					numericUpDownPrice.Enabled = true;
					numericUpDownLevelReq.Enabled = true;
				}
				if (comboBoxSubType.SelectedIndex == 2)
				{
					numericUpDownHealth.Value = 0;
					numericUpDownHealth.Enabled = false;
					numericUpDownSpeed.Value = 0;
					numericUpDownSpeed.Enabled = false;
					numericUpDownStrength.Value = 0;
					numericUpDownStrength.Enabled = false;
					numericUpDownRange.Value = 0;
					numericUpDownRange.Enabled = false;
					numericUpDownMagic.Value = 0;
					numericUpDownMagic.Enabled = false;
					numericUpDownAgility.Value = 0;
					numericUpDownAgility.Enabled = false;
					numericUpDownPrice.Enabled = true;
					numericUpDownLevelReq.Enabled = true;
				}
				if (comboBoxSubType.SelectedIndex == 3)
				{
					numericUpDownHealth.Value = 0;
					numericUpDownHealth.Enabled = false;
					numericUpDownSpeed.Value = 0;
					numericUpDownSpeed.Enabled = false;
					numericUpDownStrength.Value = 0;
					numericUpDownStrength.Enabled = false;
					numericUpDownRange.Value = 0;
					numericUpDownRange.Enabled = false;
					numericUpDownMagic.Value = 0;
					numericUpDownMagic.Enabled = false;
					numericUpDownAgility.Value = 0;
					numericUpDownAgility.Enabled = false;
					numericUpDownPrice.Enabled = true;
					numericUpDownLevelReq.Enabled = true;
				}
				if (comboBoxSubType.SelectedIndex == 4)
				{
					numericUpDownHealth.Value = 0;
					numericUpDownHealth.Enabled = false;
					numericUpDownSpeed.Value = 0;
					numericUpDownSpeed.Enabled = false;
					numericUpDownStrength.Value = 0;
					numericUpDownStrength.Enabled = false;
					numericUpDownRange.Value = 0;
					numericUpDownRange.Enabled = false;
					numericUpDownMagic.Value = 0;
					numericUpDownMagic.Enabled = false;
					numericUpDownAgility.Value = 0;
					numericUpDownAgility.Enabled = false;
					numericUpDownPrice.Enabled = true;
					numericUpDownLevelReq.Value = 0;
					numericUpDownLevelReq.Enabled = false;
				}
				if (comboBoxSubType.SelectedIndex == 5)
				{
					numericUpDownHealth.Enabled = true;
					numericUpDownSpeed.Enabled = true;
					numericUpDownStrength.Enabled = true;
					numericUpDownRange.Enabled = true;
					numericUpDownMagic.Enabled = true;
					numericUpDownAgility.Enabled = true;
					numericUpDownPrice.Enabled = true;
					numericUpDownLevelReq.Enabled = true;
				}
			}
			else if (comboBoxType.SelectedIndex == 1)
			{
				if (comboBoxSubType.SelectedIndex == 0)
				{
					numericUpDownHealth.Enabled = true;
					numericUpDownSpeed.Enabled = true;
					numericUpDownStrength.Enabled = true;
					numericUpDownRange.Enabled = true;
					numericUpDownMagic.Enabled = true;
					numericUpDownAgility.Enabled = true;
					numericUpDownPrice.Value = 0;
					numericUpDownPrice.Enabled = false;
					numericUpDownLevelReq.Value = 0;
					numericUpDownLevelReq.Enabled = false;
				}
				if (comboBoxSubType.SelectedIndex == 1)
				{
					numericUpDownHealth.Enabled = true;
					numericUpDownSpeed.Enabled = true;
					numericUpDownStrength.Enabled = true;
					numericUpDownRange.Enabled = true;
					numericUpDownMagic.Enabled = true;
					numericUpDownAgility.Enabled = true;
					numericUpDownPrice.Value = 0;
					numericUpDownPrice.Enabled = false;
					numericUpDownLevelReq.Value = 0;
					numericUpDownLevelReq.Enabled = false;
				}
				if (comboBoxSubType.SelectedIndex == 2)
				{
					numericUpDownHealth.Enabled = true;
					numericUpDownSpeed.Enabled = true;
					numericUpDownStrength.Enabled = true;
					numericUpDownRange.Enabled = true;
					numericUpDownMagic.Enabled = true;
					numericUpDownAgility.Enabled = true;
					numericUpDownPrice.Value = 0;
					numericUpDownPrice.Enabled = false;
					numericUpDownLevelReq.Value = 0;
					numericUpDownLevelReq.Enabled = false;
				}
				if (comboBoxSubType.SelectedIndex == 3)
				{
					numericUpDownHealth.Value = 0;
					numericUpDownHealth.Enabled = false;
					numericUpDownSpeed.Value = 0;
					numericUpDownSpeed.Enabled = false;
					numericUpDownStrength.Value = 0;
					numericUpDownStrength.Enabled = false;
					numericUpDownRange.Value = 0;
					numericUpDownRange.Enabled = false;
					numericUpDownMagic.Value = 0;
					numericUpDownMagic.Enabled = false;
					numericUpDownAgility.Value = 0;
					numericUpDownAgility.Enabled = false;
					numericUpDownPrice.Enabled = true;
					numericUpDownLevelReq.Enabled = true;
				}
			}
		}
		// Name Label / Assign Name
		private void textBoxName_TextChanged(object sender, EventArgs e)
		{
			m_Entity.setName(textBoxName.Text);
			labelNameTitle.Text = m_Entity.getName();
		}
		// Assign Health
		private void numericUpDownHealth_ValueChanged(object sender, EventArgs e)
		{
			m_Entity.setHealth((int)numericUpDownHealth.Value);
		}
		// Assign Speed
		private void numericUpDownSpeed_ValueChanged(object sender, EventArgs e)
		{
			m_Entity.setSpeed((int)numericUpDownSpeed.Value);
		}
		// Assign Strength
		private void numericUpDownStrength_ValueChanged(object sender, EventArgs e)
		{
			m_Entity.setStrength((int)numericUpDownStrength.Value);
		}
		// Assign Range
		private void numericUpDownRange_ValueChanged(object sender, EventArgs e)
		{
			m_Entity.setRange((int)numericUpDownRange.Value);
		}
		// Assign Magic
		private void numericUpDownMagic_ValueChanged(object sender, EventArgs e)
		{
			m_Entity.setMagic((int)numericUpDownMagic.Value);
		}
		// Assign Agility
		private void numericUpDownAgility_ValueChanged(object sender, EventArgs e)
		{
			m_Entity.setAgility((int)numericUpDownAgility.Value);
		}
		// Assign Price
		private void numericUpDownPrice_ValueChanged(object sender, EventArgs e)
		{
			m_Entity.setPrice((int)numericUpDownPrice.Value);
		}
		// Assign Level Req
		private void numericUpDownLevelReq_ValueChanged(object sender, EventArgs e)
		{
			m_Entity.setLevelReq((int)numericUpDownLevelReq.Value);
		}
	}
}
