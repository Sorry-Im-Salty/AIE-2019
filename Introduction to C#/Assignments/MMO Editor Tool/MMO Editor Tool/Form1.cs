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

/* ====================================================================================*/
		// Saving
		private void buttonSave_Click(object sender, EventArgs e)
		{
			Entity m_Entity = new Entity();
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

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Entity m_Entity = new Entity();
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
			Entity m_Entity = new Entity();
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
			Entity m_Entity = new Entity();
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
		// Name Label / Assign Name
		private void textBoxName_TextChanged(object sender, EventArgs e)
		{
			Entity m_Entity = new Entity();
			m_Entity.setName(textBoxName.Text);
			labelNameTitle.Text = m_Entity.getName();
		}
		// Assign Health
		private void numericUpDownHealth_ValueChanged(object sender, EventArgs e)
		{
			Entity m_Entity = new Entity();
			m_Entity.setHealth((int)numericUpDownHealth.Value);
		}
		// Assign Speed
		private void numericUpDownSpeed_ValueChanged(object sender, EventArgs e)
		{
			Entity m_Entity = new Entity();
			m_Entity.setSpeed((int)numericUpDownSpeed.Value);
		}
		// Assign Strength
		private void numericUpDownStrength_ValueChanged(object sender, EventArgs e)
		{
			Entity m_Entity = new Entity();
			m_Entity.setStrength((int)numericUpDownStrength.Value);
		}
		// Assign Range
		private void numericUpDownRange_ValueChanged(object sender, EventArgs e)
		{
			Entity m_Entity = new Entity();
			m_Entity.setRange((int)numericUpDownRange.Value);
		}
		// Assign Magic
		private void numericUpDownMagic_ValueChanged(object sender, EventArgs e)
		{
			Entity m_Entity = new Entity();
			m_Entity.setMagic((int)numericUpDownMagic.Value);
		}
		// Assign Agility
		private void numericUpDownAgility_ValueChanged(object sender, EventArgs e)
		{
			Entity m_Entity = new Entity();
			m_Entity.setAgility((int)numericUpDownAgility.Value);
		}
		// Assign Price
		private void numericUpDownPrice_ValueChanged(object sender, EventArgs e)
		{
			Entity m_Entity = new Entity();
			m_Entity.setPrice((int)numericUpDownPrice.Value);
		}
		// Assign Level Req
		private void numericUpDownLevelReq_ValueChanged(object sender, EventArgs e)
		{
			Entity m_Entity = new Entity();
			m_Entity.setLevelReq((int)numericUpDownLevelReq.Value);
		}
	}
}
