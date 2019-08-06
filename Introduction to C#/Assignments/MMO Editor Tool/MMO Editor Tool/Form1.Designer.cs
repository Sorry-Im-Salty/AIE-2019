namespace MMO_Editor_Tool
{
	partial class formMain
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(formMain));
			this.menuStripMain = new System.Windows.Forms.MenuStrip();
			this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
			this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.saveAsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
			this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.undoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.redoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
			this.cutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.copyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.pasteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
			this.selectAllToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.customizeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.optionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.contentsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.indexToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.searchToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
			this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.pictureBoxMain = new System.Windows.Forms.PictureBox();
			this.buttonImportSprite = new System.Windows.Forms.Button();
			this.comboBoxType = new System.Windows.Forms.ComboBox();
			this.labelNameTitle = new System.Windows.Forms.Label();
			this.labelType = new System.Windows.Forms.Label();
			this.comboBoxSubType = new System.Windows.Forms.ComboBox();
			this.labelName = new System.Windows.Forms.Label();
			this.textBoxName = new System.Windows.Forms.TextBox();
			this.labelStatsTitle = new System.Windows.Forms.Label();
			this.labelDetailsTitle = new System.Windows.Forms.Label();
			this.labelSubType = new System.Windows.Forms.Label();
			this.textBoxHealth = new System.Windows.Forms.TextBox();
			this.labelSpeed = new System.Windows.Forms.Label();
			this.textBoxStrength = new System.Windows.Forms.TextBox();
			this.labelStrength = new System.Windows.Forms.Label();
			this.textBoxSpeed = new System.Windows.Forms.TextBox();
			this.panelStats = new System.Windows.Forms.Panel();
			this.textBoxLevelReq = new System.Windows.Forms.TextBox();
			this.labelLevelReq = new System.Windows.Forms.Label();
			this.textBoxPrice = new System.Windows.Forms.TextBox();
			this.labelPrice = new System.Windows.Forms.Label();
			this.textBoxAgility = new System.Windows.Forms.TextBox();
			this.labelAgility = new System.Windows.Forms.Label();
			this.textBoxMagic = new System.Windows.Forms.TextBox();
			this.labelMagic = new System.Windows.Forms.Label();
			this.labelHealth = new System.Windows.Forms.Label();
			this.textBoxRange = new System.Windows.Forms.TextBox();
			this.labelRange = new System.Windows.Forms.Label();
			this.panelDetails = new System.Windows.Forms.Panel();
			this.buttonSave = new System.Windows.Forms.Button();
			this.buttonOpen = new System.Windows.Forms.Button();
			this.menuStripMain.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.pictureBoxMain)).BeginInit();
			this.panelStats.SuspendLayout();
			this.panelDetails.SuspendLayout();
			this.SuspendLayout();
			// 
			// menuStripMain
			// 
			this.menuStripMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.toolsToolStripMenuItem,
            this.helpToolStripMenuItem});
			this.menuStripMain.Location = new System.Drawing.Point(0, 0);
			this.menuStripMain.Name = "menuStripMain";
			this.menuStripMain.Size = new System.Drawing.Size(985, 24);
			this.menuStripMain.TabIndex = 0;
			this.menuStripMain.Text = "menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.openToolStripMenuItem,
            this.toolStripSeparator,
            this.saveToolStripMenuItem,
            this.saveAsToolStripMenuItem,
            this.toolStripSeparator1,
            this.exitToolStripMenuItem});
			this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
			this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
			this.fileToolStripMenuItem.Text = "&File";
			// 
			// newToolStripMenuItem
			// 
			this.newToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("newToolStripMenuItem.Image")));
			this.newToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.newToolStripMenuItem.Name = "newToolStripMenuItem";
			this.newToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
			this.newToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
			this.newToolStripMenuItem.Text = "&New";
			// 
			// openToolStripMenuItem
			// 
			this.openToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("openToolStripMenuItem.Image")));
			this.openToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.openToolStripMenuItem.Name = "openToolStripMenuItem";
			this.openToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
			this.openToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
			this.openToolStripMenuItem.Text = "&Open";
			// 
			// toolStripSeparator
			// 
			this.toolStripSeparator.Name = "toolStripSeparator";
			this.toolStripSeparator.Size = new System.Drawing.Size(143, 6);
			// 
			// saveToolStripMenuItem
			// 
			this.saveToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("saveToolStripMenuItem.Image")));
			this.saveToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
			this.saveToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
			this.saveToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
			this.saveToolStripMenuItem.Text = "&Save";
			// 
			// saveAsToolStripMenuItem
			// 
			this.saveAsToolStripMenuItem.Name = "saveAsToolStripMenuItem";
			this.saveAsToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
			this.saveAsToolStripMenuItem.Text = "Save &As";
			// 
			// toolStripSeparator1
			// 
			this.toolStripSeparator1.Name = "toolStripSeparator1";
			this.toolStripSeparator1.Size = new System.Drawing.Size(143, 6);
			// 
			// exitToolStripMenuItem
			// 
			this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
			this.exitToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
			this.exitToolStripMenuItem.Text = "E&xit";
			// 
			// editToolStripMenuItem
			// 
			this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.undoToolStripMenuItem,
            this.redoToolStripMenuItem,
            this.toolStripSeparator3,
            this.cutToolStripMenuItem,
            this.copyToolStripMenuItem,
            this.pasteToolStripMenuItem,
            this.toolStripSeparator4,
            this.selectAllToolStripMenuItem});
			this.editToolStripMenuItem.Name = "editToolStripMenuItem";
			this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
			this.editToolStripMenuItem.Text = "&Edit";
			// 
			// undoToolStripMenuItem
			// 
			this.undoToolStripMenuItem.Name = "undoToolStripMenuItem";
			this.undoToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Z)));
			this.undoToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
			this.undoToolStripMenuItem.Text = "&Undo";
			// 
			// redoToolStripMenuItem
			// 
			this.redoToolStripMenuItem.Name = "redoToolStripMenuItem";
			this.redoToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Y)));
			this.redoToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
			this.redoToolStripMenuItem.Text = "&Redo";
			// 
			// toolStripSeparator3
			// 
			this.toolStripSeparator3.Name = "toolStripSeparator3";
			this.toolStripSeparator3.Size = new System.Drawing.Size(141, 6);
			// 
			// cutToolStripMenuItem
			// 
			this.cutToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("cutToolStripMenuItem.Image")));
			this.cutToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.cutToolStripMenuItem.Name = "cutToolStripMenuItem";
			this.cutToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.X)));
			this.cutToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
			this.cutToolStripMenuItem.Text = "Cu&t";
			// 
			// copyToolStripMenuItem
			// 
			this.copyToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("copyToolStripMenuItem.Image")));
			this.copyToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.copyToolStripMenuItem.Name = "copyToolStripMenuItem";
			this.copyToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.C)));
			this.copyToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
			this.copyToolStripMenuItem.Text = "&Copy";
			// 
			// pasteToolStripMenuItem
			// 
			this.pasteToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("pasteToolStripMenuItem.Image")));
			this.pasteToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.pasteToolStripMenuItem.Name = "pasteToolStripMenuItem";
			this.pasteToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V)));
			this.pasteToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
			this.pasteToolStripMenuItem.Text = "&Paste";
			// 
			// toolStripSeparator4
			// 
			this.toolStripSeparator4.Name = "toolStripSeparator4";
			this.toolStripSeparator4.Size = new System.Drawing.Size(141, 6);
			// 
			// selectAllToolStripMenuItem
			// 
			this.selectAllToolStripMenuItem.Name = "selectAllToolStripMenuItem";
			this.selectAllToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
			this.selectAllToolStripMenuItem.Text = "Select &All";
			// 
			// toolsToolStripMenuItem
			// 
			this.toolsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.customizeToolStripMenuItem,
            this.optionsToolStripMenuItem});
			this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
			this.toolsToolStripMenuItem.Size = new System.Drawing.Size(47, 20);
			this.toolsToolStripMenuItem.Text = "&Tools";
			// 
			// customizeToolStripMenuItem
			// 
			this.customizeToolStripMenuItem.Name = "customizeToolStripMenuItem";
			this.customizeToolStripMenuItem.Size = new System.Drawing.Size(130, 22);
			this.customizeToolStripMenuItem.Text = "&Customize";
			// 
			// optionsToolStripMenuItem
			// 
			this.optionsToolStripMenuItem.Name = "optionsToolStripMenuItem";
			this.optionsToolStripMenuItem.Size = new System.Drawing.Size(130, 22);
			this.optionsToolStripMenuItem.Text = "&Options";
			// 
			// helpToolStripMenuItem
			// 
			this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.contentsToolStripMenuItem,
            this.indexToolStripMenuItem,
            this.searchToolStripMenuItem,
            this.toolStripSeparator5,
            this.aboutToolStripMenuItem});
			this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
			this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
			this.helpToolStripMenuItem.Text = "&Help";
			// 
			// contentsToolStripMenuItem
			// 
			this.contentsToolStripMenuItem.Name = "contentsToolStripMenuItem";
			this.contentsToolStripMenuItem.Size = new System.Drawing.Size(122, 22);
			this.contentsToolStripMenuItem.Text = "&Contents";
			// 
			// indexToolStripMenuItem
			// 
			this.indexToolStripMenuItem.Name = "indexToolStripMenuItem";
			this.indexToolStripMenuItem.Size = new System.Drawing.Size(122, 22);
			this.indexToolStripMenuItem.Text = "&Index";
			// 
			// searchToolStripMenuItem
			// 
			this.searchToolStripMenuItem.Name = "searchToolStripMenuItem";
			this.searchToolStripMenuItem.Size = new System.Drawing.Size(122, 22);
			this.searchToolStripMenuItem.Text = "&Search";
			// 
			// toolStripSeparator5
			// 
			this.toolStripSeparator5.Name = "toolStripSeparator5";
			this.toolStripSeparator5.Size = new System.Drawing.Size(119, 6);
			// 
			// aboutToolStripMenuItem
			// 
			this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
			this.aboutToolStripMenuItem.Size = new System.Drawing.Size(122, 22);
			this.aboutToolStripMenuItem.Text = "&About...";
			// 
			// pictureBoxMain
			// 
			this.pictureBoxMain.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.pictureBoxMain.Location = new System.Drawing.Point(35, 76);
			this.pictureBoxMain.Name = "pictureBoxMain";
			this.pictureBoxMain.Size = new System.Drawing.Size(367, 407);
			this.pictureBoxMain.TabIndex = 1;
			this.pictureBoxMain.TabStop = false;
			// 
			// buttonImportSprite
			// 
			this.buttonImportSprite.Location = new System.Drawing.Point(327, 489);
			this.buttonImportSprite.Name = "buttonImportSprite";
			this.buttonImportSprite.Size = new System.Drawing.Size(75, 28);
			this.buttonImportSprite.TabIndex = 2;
			this.buttonImportSprite.Text = "Import Sprite";
			this.buttonImportSprite.UseVisualStyleBackColor = true;
			// 
			// comboBoxType
			// 
			this.comboBoxType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.comboBoxType.FormattingEnabled = true;
			this.comboBoxType.Items.AddRange(new object[] {
            "Item",
            "Character"});
			this.comboBoxType.Location = new System.Drawing.Point(119, 70);
			this.comboBoxType.MaxDropDownItems = 2;
			this.comboBoxType.Name = "comboBoxType";
			this.comboBoxType.Size = new System.Drawing.Size(121, 21);
			this.comboBoxType.TabIndex = 4;
			// 
			// labelNameTitle
			// 
			this.labelNameTitle.AutoSize = true;
			this.labelNameTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelNameTitle.Location = new System.Drawing.Point(172, 42);
			this.labelNameTitle.Name = "labelNameTitle";
			this.labelNameTitle.Size = new System.Drawing.Size(90, 31);
			this.labelNameTitle.TabIndex = 5;
			this.labelNameTitle.Text = "Name";
			this.labelNameTitle.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// labelType
			// 
			this.labelType.AutoSize = true;
			this.labelType.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelType.Location = new System.Drawing.Point(12, 71);
			this.labelType.Name = "labelType";
			this.labelType.Size = new System.Drawing.Size(47, 20);
			this.labelType.TabIndex = 6;
			this.labelType.Text = "Type";
			this.labelType.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// comboBoxSubType
			// 
			this.comboBoxSubType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.comboBoxSubType.FormattingEnabled = true;
			this.comboBoxSubType.Location = new System.Drawing.Point(119, 102);
			this.comboBoxSubType.MaxDropDownItems = 2;
			this.comboBoxSubType.Name = "comboBoxSubType";
			this.comboBoxSubType.Size = new System.Drawing.Size(121, 21);
			this.comboBoxSubType.TabIndex = 9;
			// 
			// labelName
			// 
			this.labelName.AutoSize = true;
			this.labelName.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelName.Location = new System.Drawing.Point(12, 133);
			this.labelName.Name = "labelName";
			this.labelName.Size = new System.Drawing.Size(55, 20);
			this.labelName.TabIndex = 10;
			this.labelName.Text = "Name";
			this.labelName.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// textBoxName
			// 
			this.textBoxName.Location = new System.Drawing.Point(119, 133);
			this.textBoxName.Name = "textBoxName";
			this.textBoxName.Size = new System.Drawing.Size(100, 20);
			this.textBoxName.TabIndex = 11;
			// 
			// labelStatsTitle
			// 
			this.labelStatsTitle.AutoSize = true;
			this.labelStatsTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelStatsTitle.Location = new System.Drawing.Point(102, 20);
			this.labelStatsTitle.Name = "labelStatsTitle";
			this.labelStatsTitle.Size = new System.Drawing.Size(82, 31);
			this.labelStatsTitle.TabIndex = 12;
			this.labelStatsTitle.Text = "Stats";
			this.labelStatsTitle.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// labelDetailsTitle
			// 
			this.labelDetailsTitle.AutoSize = true;
			this.labelDetailsTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelDetailsTitle.Location = new System.Drawing.Point(88, 20);
			this.labelDetailsTitle.Name = "labelDetailsTitle";
			this.labelDetailsTitle.Size = new System.Drawing.Size(105, 31);
			this.labelDetailsTitle.TabIndex = 13;
			this.labelDetailsTitle.Text = "Details";
			this.labelDetailsTitle.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// labelSubType
			// 
			this.labelSubType.AutoSize = true;
			this.labelSubType.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelSubType.Location = new System.Drawing.Point(12, 103);
			this.labelSubType.Name = "labelSubType";
			this.labelSubType.Size = new System.Drawing.Size(84, 20);
			this.labelSubType.TabIndex = 14;
			this.labelSubType.Text = "Sub Type";
			this.labelSubType.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// textBoxHealth
			// 
			this.textBoxHealth.Location = new System.Drawing.Point(118, 71);
			this.textBoxHealth.Name = "textBoxHealth";
			this.textBoxHealth.Size = new System.Drawing.Size(66, 20);
			this.textBoxHealth.TabIndex = 16;
			// 
			// labelSpeed
			// 
			this.labelSpeed.AutoSize = true;
			this.labelSpeed.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelSpeed.Location = new System.Drawing.Point(9, 97);
			this.labelSpeed.Name = "labelSpeed";
			this.labelSpeed.Size = new System.Drawing.Size(61, 20);
			this.labelSpeed.TabIndex = 17;
			this.labelSpeed.Text = "Speed";
			this.labelSpeed.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// textBoxStrength
			// 
			this.textBoxStrength.Location = new System.Drawing.Point(118, 123);
			this.textBoxStrength.Name = "textBoxStrength";
			this.textBoxStrength.Size = new System.Drawing.Size(66, 20);
			this.textBoxStrength.TabIndex = 18;
			// 
			// labelStrength
			// 
			this.labelStrength.AutoSize = true;
			this.labelStrength.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelStrength.Location = new System.Drawing.Point(9, 123);
			this.labelStrength.Name = "labelStrength";
			this.labelStrength.Size = new System.Drawing.Size(79, 20);
			this.labelStrength.TabIndex = 19;
			this.labelStrength.Text = "Strength";
			this.labelStrength.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// textBoxSpeed
			// 
			this.textBoxSpeed.Location = new System.Drawing.Point(118, 97);
			this.textBoxSpeed.Name = "textBoxSpeed";
			this.textBoxSpeed.Size = new System.Drawing.Size(66, 20);
			this.textBoxSpeed.TabIndex = 20;
			// 
			// panelStats
			// 
			this.panelStats.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.panelStats.Controls.Add(this.textBoxLevelReq);
			this.panelStats.Controls.Add(this.labelLevelReq);
			this.panelStats.Controls.Add(this.textBoxPrice);
			this.panelStats.Controls.Add(this.labelPrice);
			this.panelStats.Controls.Add(this.textBoxAgility);
			this.panelStats.Controls.Add(this.labelAgility);
			this.panelStats.Controls.Add(this.textBoxMagic);
			this.panelStats.Controls.Add(this.labelMagic);
			this.panelStats.Controls.Add(this.labelHealth);
			this.panelStats.Controls.Add(this.textBoxRange);
			this.panelStats.Controls.Add(this.labelRange);
			this.panelStats.Controls.Add(this.labelStatsTitle);
			this.panelStats.Controls.Add(this.textBoxSpeed);
			this.panelStats.Controls.Add(this.textBoxStrength);
			this.panelStats.Controls.Add(this.labelStrength);
			this.panelStats.Controls.Add(this.textBoxHealth);
			this.panelStats.Controls.Add(this.labelSpeed);
			this.panelStats.Location = new System.Drawing.Point(688, 76);
			this.panelStats.Name = "panelStats";
			this.panelStats.Size = new System.Drawing.Size(274, 354);
			this.panelStats.TabIndex = 21;
			// 
			// textBoxLevelReq
			// 
			this.textBoxLevelReq.Location = new System.Drawing.Point(118, 253);
			this.textBoxLevelReq.Name = "textBoxLevelReq";
			this.textBoxLevelReq.Size = new System.Drawing.Size(66, 20);
			this.textBoxLevelReq.TabIndex = 31;
			// 
			// labelLevelReq
			// 
			this.labelLevelReq.AutoSize = true;
			this.labelLevelReq.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelLevelReq.Location = new System.Drawing.Point(9, 253);
			this.labelLevelReq.Name = "labelLevelReq";
			this.labelLevelReq.Size = new System.Drawing.Size(89, 20);
			this.labelLevelReq.TabIndex = 30;
			this.labelLevelReq.Text = "Level Req";
			this.labelLevelReq.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// textBoxPrice
			// 
			this.textBoxPrice.Location = new System.Drawing.Point(118, 227);
			this.textBoxPrice.Name = "textBoxPrice";
			this.textBoxPrice.Size = new System.Drawing.Size(66, 20);
			this.textBoxPrice.TabIndex = 30;
			// 
			// labelPrice
			// 
			this.labelPrice.AutoSize = true;
			this.labelPrice.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelPrice.Location = new System.Drawing.Point(9, 227);
			this.labelPrice.Name = "labelPrice";
			this.labelPrice.Size = new System.Drawing.Size(49, 20);
			this.labelPrice.TabIndex = 29;
			this.labelPrice.Text = "Price";
			this.labelPrice.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// textBoxAgility
			// 
			this.textBoxAgility.Location = new System.Drawing.Point(118, 201);
			this.textBoxAgility.Name = "textBoxAgility";
			this.textBoxAgility.Size = new System.Drawing.Size(66, 20);
			this.textBoxAgility.TabIndex = 28;
			// 
			// labelAgility
			// 
			this.labelAgility.AutoSize = true;
			this.labelAgility.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelAgility.Location = new System.Drawing.Point(9, 201);
			this.labelAgility.Name = "labelAgility";
			this.labelAgility.Size = new System.Drawing.Size(57, 20);
			this.labelAgility.TabIndex = 27;
			this.labelAgility.Text = "Agility";
			this.labelAgility.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// textBoxMagic
			// 
			this.textBoxMagic.Location = new System.Drawing.Point(118, 175);
			this.textBoxMagic.Name = "textBoxMagic";
			this.textBoxMagic.Size = new System.Drawing.Size(66, 20);
			this.textBoxMagic.TabIndex = 26;
			// 
			// labelMagic
			// 
			this.labelMagic.AutoSize = true;
			this.labelMagic.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelMagic.Location = new System.Drawing.Point(9, 175);
			this.labelMagic.Name = "labelMagic";
			this.labelMagic.Size = new System.Drawing.Size(56, 20);
			this.labelMagic.TabIndex = 24;
			this.labelMagic.Text = "Magic";
			this.labelMagic.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// labelHealth
			// 
			this.labelHealth.AutoSize = true;
			this.labelHealth.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelHealth.Location = new System.Drawing.Point(9, 71);
			this.labelHealth.Name = "labelHealth";
			this.labelHealth.Size = new System.Drawing.Size(62, 20);
			this.labelHealth.TabIndex = 25;
			this.labelHealth.Text = "Health";
			this.labelHealth.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// textBoxRange
			// 
			this.textBoxRange.Location = new System.Drawing.Point(118, 149);
			this.textBoxRange.Name = "textBoxRange";
			this.textBoxRange.Size = new System.Drawing.Size(66, 20);
			this.textBoxRange.TabIndex = 24;
			// 
			// labelRange
			// 
			this.labelRange.AutoSize = true;
			this.labelRange.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.labelRange.Location = new System.Drawing.Point(9, 149);
			this.labelRange.Name = "labelRange";
			this.labelRange.Size = new System.Drawing.Size(62, 20);
			this.labelRange.TabIndex = 23;
			this.labelRange.Text = "Range";
			this.labelRange.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// panelDetails
			// 
			this.panelDetails.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.panelDetails.Controls.Add(this.labelDetailsTitle);
			this.panelDetails.Controls.Add(this.labelType);
			this.panelDetails.Controls.Add(this.textBoxName);
			this.panelDetails.Controls.Add(this.labelSubType);
			this.panelDetails.Controls.Add(this.labelName);
			this.panelDetails.Controls.Add(this.comboBoxType);
			this.panelDetails.Controls.Add(this.comboBoxSubType);
			this.panelDetails.Location = new System.Drawing.Point(408, 76);
			this.panelDetails.Name = "panelDetails";
			this.panelDetails.Size = new System.Drawing.Size(274, 354);
			this.panelDetails.TabIndex = 22;
			// 
			// buttonSave
			// 
			this.buttonSave.Location = new System.Drawing.Point(770, 436);
			this.buttonSave.Name = "buttonSave";
			this.buttonSave.Size = new System.Drawing.Size(80, 37);
			this.buttonSave.TabIndex = 23;
			this.buttonSave.Text = "Save";
			this.buttonSave.UseVisualStyleBackColor = true;
			// 
			// buttonOpen
			// 
			this.buttonOpen.Location = new System.Drawing.Point(871, 436);
			this.buttonOpen.Name = "buttonOpen";
			this.buttonOpen.Size = new System.Drawing.Size(91, 37);
			this.buttonOpen.TabIndex = 24;
			this.buttonOpen.Text = "Open";
			this.buttonOpen.UseVisualStyleBackColor = true;
			// 
			// formMain
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(985, 531);
			this.Controls.Add(this.buttonOpen);
			this.Controls.Add(this.buttonSave);
			this.Controls.Add(this.panelDetails);
			this.Controls.Add(this.panelStats);
			this.Controls.Add(this.labelNameTitle);
			this.Controls.Add(this.buttonImportSprite);
			this.Controls.Add(this.pictureBoxMain);
			this.Controls.Add(this.menuStripMain);
			this.MainMenuStrip = this.menuStripMain;
			this.Name = "formMain";
			this.Text = "MMO Editor";
			this.menuStripMain.ResumeLayout(false);
			this.menuStripMain.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.pictureBoxMain)).EndInit();
			this.panelStats.ResumeLayout(false);
			this.panelStats.PerformLayout();
			this.panelDetails.ResumeLayout(false);
			this.panelDetails.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.MenuStrip menuStripMain;
		private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator;
		private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem saveAsToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
		private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem undoToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem redoToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
		private System.Windows.Forms.ToolStripMenuItem cutToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem copyToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem pasteToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
		private System.Windows.Forms.ToolStripMenuItem selectAllToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem customizeToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem optionsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem contentsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem indexToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem searchToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
		private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
		private System.Windows.Forms.PictureBox pictureBoxMain;
		private System.Windows.Forms.Button buttonImportSprite;
		private System.Windows.Forms.ComboBox comboBoxType;
		private System.Windows.Forms.Label labelNameTitle;
		private System.Windows.Forms.Label labelType;
		private System.Windows.Forms.ComboBox comboBoxSubType;
		private System.Windows.Forms.Label labelName;
		private System.Windows.Forms.TextBox textBoxName;
		private System.Windows.Forms.Label labelStatsTitle;
		private System.Windows.Forms.Label labelDetailsTitle;
		private System.Windows.Forms.Label labelSubType;
		private System.Windows.Forms.TextBox textBoxHealth;
		private System.Windows.Forms.Label labelSpeed;
		private System.Windows.Forms.TextBox textBoxStrength;
		private System.Windows.Forms.Label labelStrength;
		private System.Windows.Forms.TextBox textBoxSpeed;
		private System.Windows.Forms.Panel panelStats;
		private System.Windows.Forms.Panel panelDetails;
		private System.Windows.Forms.TextBox textBoxRange;
		private System.Windows.Forms.Label labelRange;
		private System.Windows.Forms.Label labelHealth;
		private System.Windows.Forms.TextBox textBoxMagic;
		private System.Windows.Forms.Label labelMagic;
		private System.Windows.Forms.TextBox textBoxAgility;
		private System.Windows.Forms.Label labelAgility;
		private System.Windows.Forms.TextBox textBoxLevelReq;
		private System.Windows.Forms.Label labelLevelReq;
		private System.Windows.Forms.TextBox textBoxPrice;
		private System.Windows.Forms.Label labelPrice;
		private System.Windows.Forms.Button buttonSave;
		private System.Windows.Forms.Button buttonOpen;
	}
}

