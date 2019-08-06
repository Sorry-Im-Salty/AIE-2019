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
			SaveFileDialog saveFileDialogMain = new SaveFileDialog();
			saveFileDialogMain.Filter = "XML File|*.xml";
			saveFileDialogMain.Title = "Save";
			saveFileDialogMain.ShowDialog();

			if (saveFileDialogMain.FileName != "")
			{
				XmlSerializer serializer = new XmlSerializer(typeof(Entity));
				StreamWriter file = new StreamWriter("Entity.xml");
				//serializer.Serialize(file, m_Entity);
				file.Close();
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
				//serializer.Serialize(file, m_Entity);
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
				//m_Entity = (Entity)serializer.Deserialize(file);
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
				//m_Entity = (Entity)serializer.Deserialize(file);
				file.Close();
			}
		}
	}
}
