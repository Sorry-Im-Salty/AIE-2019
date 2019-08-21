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
			pictureBoxSprite.DragDrop += new DragEventHandler(pictureBoxSprite_DragDrop);
			pictureBoxSprite.DragEnter += new DragEventHandler(pictureBoxSprite_DragEnter);
			pictureBoxSprite.AllowDrop = true;
			Entity[] pointlessArray = new Entity[10];

			for (int i = 0; i < 10; i++)
			{
				pointlessArray[i] = en;
			}
		}

		Entity en = new Entity();
/* ====================================================================================*/
		// Search and Sort
		public int LinearSearch(int[] data, int value)
		{
			int n = data.Length;
			for (int i = 0; i < n; i++)
			{
				if (data[i] == value)
					return i;
			}
			return -1;
		}

		public void BubbleSort(int[] data)
		{
			int temp;
			for (int i = 0; i < data.Length - 1; i++)
			{
				for (int j = 0; j < data.Length - i - 1; j++)
				{
					if (data[j] > data[j + 1])
					{
						temp = data[j];
						data[j] = data[j + 1];
						data[j + 1] = temp;
					}
				}
			}
		}
		private void buttonSearchAndSort_Click(object sender, EventArgs e)
		{
			int[] intArray = { 55, 32, 54, 57, 12, 6, 99 };
			Console.WriteLine("This is the current data in the array : ");
			Console.WriteLine(intArray[0]); Console.WriteLine(intArray[1]); Console.WriteLine(intArray[2]);
			Console.WriteLine(intArray[3]); Console.WriteLine(intArray[4]); Console.WriteLine(intArray[5]);
			Console.WriteLine(intArray[6]);

			Console.WriteLine("Search Algorithm shows that the value of 54 is located within the array : "); Console.WriteLine(LinearSearch(intArray, 54));
			Console.WriteLine("The Sorting Algorithm : "); BubbleSort(intArray);
			Console.WriteLine(intArray[0]); Console.WriteLine(intArray[1]); Console.WriteLine(intArray[2]);
			Console.WriteLine(intArray[3]); Console.WriteLine(intArray[4]); Console.WriteLine(intArray[5]);
			Console.WriteLine(intArray[6]);
		}

		/* ====================================================================================*/
		// Help
		private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
		{
			MessageBox.Show("This tool is used to create entities that would be added to an RPG styled game.\n\n" +
				"Entity files are saved as .xml files.\n\n" +
				"Only relevant information for the entity will be available depending on the Type and Sub-Type, which means that if you wanted to make a type of currency, the entity wouldn't need a health stat.\n\n" +
				"Users may drag and drop sprites into the box on the left, these sprite files are recommended to be .png but can also be .jpeg. If the image directory cannot be found, it will display a cross.\n\n" +
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
			StreamWriter file = new StreamWriter(filename);
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
				if (en.nHealth > 100)
				{
					en.nHealth = 100;
					numericUpDownHealth.Value = en.nHealth;
				}
				else
					numericUpDownHealth.Value = en.nHealth;
				if (en.nSpeed > 100)
				{
					en.nSpeed = 100;
					numericUpDownSpeed.Value = en.nSpeed;
				}
				else
					numericUpDownSpeed.Value = en.nSpeed;
				if (en.nStrength > 100)
				{
					en.nStrength = 100;
					numericUpDownStrength.Value = en.nStrength;
				}
				else
					numericUpDownStrength.Value = en.nStrength;
				if (en.nRange > 100)
				{
					en.nRange = 100;
					numericUpDownRange.Value = en.nRange;
				}
				else
					numericUpDownRange.Value = en.nRange;
				if (en.nMagic > 100)
				{
					en.nMagic = 100;
					numericUpDownMagic.Value = en.nMagic;
				}
				else
					numericUpDownMagic.Value = en.nMagic;
				if (en.nAgility > 100)
				{
					en.nAgility = 100;
					numericUpDownAgility.Value = en.nAgility;
				}
				else
					numericUpDownAgility.Value = en.nAgility;
				if (en.nPrice > 1000000)
				{
					en.nPrice = 1000000;
					numericUpDownPrice.Value = en.nPrice;
				}
				else
					numericUpDownPrice.Value = en.nPrice;
				if (en.nLevelReq > 100)
				{
					en.nLevelReq = 100;
					numericUpDownLevelReq.Value = en.nLevelReq;
				}
				else
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
				if (en.nHealth > 100)
				{
					en.nHealth = 100;
					numericUpDownHealth.Value = en.nHealth;
				}
				else
					numericUpDownHealth.Value = en.nHealth;
				if (en.nSpeed > 100)
				{
					en.nSpeed = 100;
					numericUpDownSpeed.Value = en.nSpeed;
				}
				else
					numericUpDownSpeed.Value = en.nSpeed;
				if (en.nStrength > 100)
				{
					en.nStrength = 100;
					numericUpDownStrength.Value = en.nStrength;
				}
				else
					numericUpDownStrength.Value = en.nStrength;
				if (en.nRange > 100)
				{
					en.nRange = 100;
					numericUpDownRange.Value = en.nRange;
				}
				else
					numericUpDownRange.Value = en.nRange;
				if (en.nMagic > 100)
				{
					en.nMagic = 100;
					numericUpDownMagic.Value = en.nMagic;
				}
				else
					numericUpDownMagic.Value = en.nMagic;
				if (en.nAgility > 100)
				{
					en.nAgility = 100;
					numericUpDownAgility.Value = en.nAgility;
				}
				else
					numericUpDownAgility.Value = en.nAgility;
				if (en.nPrice > 1000000)
				{
					en.nPrice = 1000000;
					numericUpDownPrice.Value = en.nPrice;
				}
				else
					numericUpDownPrice.Value = en.nPrice;
				if (en.nLevelReq > 100)
				{
					en.nLevelReq = 100;
					numericUpDownLevelReq.Value = en.nLevelReq;
				}
				else
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

		private void pictureBoxSprite_DragEnter(object sender, DragEventArgs e)
		{
			if (e.Data.GetDataPresent(DataFormats.FileDrop))
				e.Effect = DragDropEffects.All;
			else
				e.Effect = DragDropEffects.None;
		}

		private void pictureBoxSprite_DragDrop(object sender, DragEventArgs e)
		{
			string[] s = (string[])e.Data.GetData(DataFormats.FileDrop, false);
			for (int i = 0; i < s.Length; i++)
			{
				pictureBoxSprite.ImageLocation = s[i];
				pictureBoxSprite.Image = Image.FromFile(pictureBoxSprite.ImageLocation);
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
