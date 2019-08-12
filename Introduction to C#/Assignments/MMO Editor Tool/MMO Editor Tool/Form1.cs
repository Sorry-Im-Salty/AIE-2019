using System;
using System.Drawing;
using System.IO;
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

		Entity en = new Entity();

/* ====================================================================================*/
		// Help
		private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
		{
			MessageBox.Show("This tool is used to create entities that would be added to an RPG styled game.\n\n" +
				"Entity files are saved as .xml files.\n\n" +
				"Only relevant information for the entity will be available depending on the Type and Sub-Type, which means that if you wanted to make a type of currency, the entity wouldn't need a health stat.\n\n" +
				"Users may drag and drop sprites into the box on the left, these sprite files must be .png. If the image directory cannot be found, it will display a cross.\n\n" +
				"Made by Thomas Maltezos\nEmail: thomasmaltezos00@gmail.com", "About...");
		}
/* ====================================================================================*/
		// Saving
		private void buttonSave_Click(object sender, EventArgs e)
		{
			en.nType = comboBoxType.Text;
			en.nSubType = comboBoxSubType.Text;
			en.sName = textBoxName.Text;
			en.nHealth = (int)numericUpDownHealth.Value;
			en.nSpeed = (int)numericUpDownSpeed.Value;
			en.nStrength = (int)numericUpDownStrength.Value;
			en.nRange = (int)numericUpDownRange.Value;
			en.nMagic = (int)numericUpDownMagic.Value;
			en.nAgility = (int)numericUpDownAgility.Value;
			en.nPrice = (int)numericUpDownPrice.Value;
			en.nLevelReq = (int)numericUpDownLevelReq.Value;
			en.sSprite = pictureBoxSprite.ImageLocation;

			SaveFileDialog saveFileDialogMain = new SaveFileDialog();
			saveFileDialogMain.Filter = "XML Document (*.xml)|*.xml";
			saveFileDialogMain.Title = "Save";
			saveFileDialogMain.RestoreDirectory = true;
			saveFileDialogMain.CheckPathExists = true;
			saveFileDialogMain.FileName = labelNameTitle.Text;

			if (saveFileDialogMain.ShowDialog() == DialogResult.OK)
			{
				Save(en, saveFileDialogMain.FileName);
			}
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			en.nType = comboBoxType.Text;
			en.nSubType = comboBoxSubType.Text;
			en.sName = textBoxName.Text;
			en.nHealth = (int)numericUpDownHealth.Value;
			en.nSpeed = (int)numericUpDownSpeed.Value;
			en.nStrength = (int)numericUpDownStrength.Value;
			en.nRange = (int)numericUpDownRange.Value;
			en.nMagic = (int)numericUpDownMagic.Value;
			en.nAgility = (int)numericUpDownAgility.Value;
			en.nPrice = (int)numericUpDownPrice.Value;
			en.nLevelReq = (int)numericUpDownLevelReq.Value;
			en.sSprite = pictureBoxSprite.ImageLocation;

			SaveFileDialog saveFileDialogMain = new SaveFileDialog();
			saveFileDialogMain.Filter = "XML Document (*.xml)|*.xml";
			saveFileDialogMain.Title = "Save";
			saveFileDialogMain.RestoreDirectory = true;
			saveFileDialogMain.CheckPathExists = true;
			saveFileDialogMain.FileName = labelNameTitle.Text;

			if (saveFileDialogMain.ShowDialog() == DialogResult.OK)
			{
				Save(en, saveFileDialogMain.FileName);
			}
		}

		public void Save(Entity entity, string filename)
		{
			XmlSerializer serializer = new XmlSerializer(typeof(Entity));
			StreamWriter file = new StreamWriter(filename + ".xml");
			serializer.Serialize(file, entity);
			file.Close();
		}
/* ====================================================================================*/
		// Opening
		private void buttonOpen_Click(object sender, EventArgs e)
		{
			OpenFileDialog openFileDialogMain = new OpenFileDialog();
			openFileDialogMain.Filter = "XML Document|*.xml";
			openFileDialogMain.Title = "Open";
			openFileDialogMain.ShowDialog();

			if (openFileDialogMain.FileName != "")
			{
				Open(en, openFileDialogMain.FileName);

				comboBoxType.Text = en.nType;
				comboBoxSubType.Text = en.nSubType;
				textBoxName.Text = en.sName;
				numericUpDownHealth.Value = en.nHealth;
				numericUpDownSpeed.Value = en.nSpeed;
				numericUpDownStrength.Value = en.nStrength;
				numericUpDownRange.Value = en.nRange;
				numericUpDownMagic.Value = en.nMagic;
				numericUpDownAgility.Value = en.nAgility;
				numericUpDownPrice.Value = en.nPrice;
				numericUpDownLevelReq.Value = en.nLevelReq;
				pictureBoxSprite.ImageLocation = en.sSprite;
			}
		}

		private void openToolStripMenuItem_Click(object sender, EventArgs e)
		{
			OpenFileDialog openFileDialogMain = new OpenFileDialog();
			openFileDialogMain.Filter = "XML Document|*.xml";
			openFileDialogMain.Title = "Open";
			openFileDialogMain.ShowDialog();

			if (openFileDialogMain.FileName != "")
			{
				Open(en, openFileDialogMain.FileName);

				comboBoxType.Text = en.nType;
				comboBoxSubType.Text = en.nSubType;
				textBoxName.Text = en.sName;
				numericUpDownHealth.Value = en.nHealth;
				numericUpDownSpeed.Value = en.nSpeed;
				numericUpDownStrength.Value = en.nStrength;
				numericUpDownRange.Value = en.nRange;
				numericUpDownMagic.Value = en.nMagic;
				numericUpDownAgility.Value = en.nAgility;
				numericUpDownPrice.Value = en.nPrice;
				numericUpDownLevelReq.Value = en.nLevelReq;
				pictureBoxSprite.ImageLocation = en.sSprite;
			}
		}

		public void Open(Entity entity, string filename)
		{
			XmlSerializer serializer = new XmlSerializer(typeof(Entity));
			StreamReader file = new StreamReader(filename);
			en = (Entity)serializer.Deserialize(file);
			file.Close();
		}
/* ====================================================================================*/
		// Import Sprite
		private void buttonImportSprite_Click(object sender, EventArgs e)
		{
			OpenFileDialog openFileDialogMain = new OpenFileDialog();
			openFileDialogMain.Filter = "PNG File|*.png";
			openFileDialogMain.Title = "Import Sprite";
			openFileDialogMain.ShowDialog();

			if (openFileDialogMain.FileName != "")
			{
				pictureBoxSprite.Image = Image.FromFile(openFileDialogMain.FileName);
				pictureBoxSprite.ImageLocation = openFileDialogMain.FileName;
			}
		}
/* ====================================================================================*/
		// New File
		private void newToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (MessageBox.Show("Are you sure you want to create a new entity? All unsaved changed will be lost.", "Warning", MessageBoxButtons.OKCancel) == DialogResult.OK)
			{
				comboBoxSubType.Items.Clear();
				comboBoxSubType.Enabled = false;
				comboBoxType.SelectedIndex = -1;
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
				numericUpDownPrice.Value = 0;
				numericUpDownPrice.Enabled = false;
				numericUpDownLevelReq.Value = 0;
				numericUpDownLevelReq.Enabled = false;
				textBoxName.Text = "";
				pictureBoxSprite.ImageLocation = "";
				pictureBoxSprite.Image = null;
			}
		}
/* ====================================================================================*/
		// Assign Type
		private void comboBoxType_SelectedIndexChanged(object sender, EventArgs e)
		{
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
			// Item Selected 
			if (comboBoxType.SelectedIndex == 0)
			{
				// Weapon Selected
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
				// Tool Selected
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
				// Ore Selected
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
				// Wood Selected
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
				// Currency Selected
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
				// Misc Selected
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
			// Character Selected
			else if (comboBoxType.SelectedIndex == 1)
			{
				// Enemy Selected
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
				// Neutral Selected
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
				// Friendly Selected
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
				// Shop Selected
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
		// Name Label
		private void textBoxName_TextChanged(object sender, EventArgs e)
		{
			labelNameTitle.Text = textBoxName.Text;
		}
	}
}
