namespace Editor
{
    partial class btn_loadBackground
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
            this.btnloadbackground = new System.Windows.Forms.Button();
            this.imgmap = new System.Windows.Forms.PictureBox();
            this.btntitle = new System.Windows.Forms.Button();
            this.widthheight = new System.Windows.Forms.Label();
            this.imagename = new System.Windows.Forms.Label();
            this.listView1 = new System.Windows.Forms.ListView();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.loadMap = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.pictureResult = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.imgmap)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureResult)).BeginInit();
            this.SuspendLayout();
            // 
            // btnloadbackground
            // 
            this.btnloadbackground.Location = new System.Drawing.Point(26, 26);
            this.btnloadbackground.Name = "btnloadbackground";
            this.btnloadbackground.Size = new System.Drawing.Size(105, 34);
            this.btnloadbackground.TabIndex = 0;
            this.btnloadbackground.Text = "Load Image";
            this.btnloadbackground.UseVisualStyleBackColor = true;
            this.btnloadbackground.Click += new System.EventHandler(this.btnloadbackground_Click);
            // 
            // imgmap
            // 
            this.imgmap.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.imgmap.Location = new System.Drawing.Point(195, 42);
            this.imgmap.Name = "imgmap";
            this.imgmap.Size = new System.Drawing.Size(1128, 475);
            this.imgmap.TabIndex = 1;
            this.imgmap.TabStop = false;
            // 
            // btntitle
            // 
            this.btntitle.Location = new System.Drawing.Point(26, 81);
            this.btntitle.Name = "btntitle";
            this.btntitle.Size = new System.Drawing.Size(105, 32);
            this.btntitle.TabIndex = 2;
            this.btntitle.Text = "Title";
            this.btntitle.UseVisualStyleBackColor = true;
            this.btntitle.Click += new System.EventHandler(this.btntitle_Click);
            // 
            // widthheight
            // 
            this.widthheight.AutoSize = true;
            this.widthheight.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.widthheight.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.widthheight.Location = new System.Drawing.Point(1197, 26);
            this.widthheight.Name = "widthheight";
            this.widthheight.Size = new System.Drawing.Size(0, 13);
            this.widthheight.TabIndex = 3;
            this.widthheight.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // imagename
            // 
            this.imagename.AutoSize = true;
            this.imagename.Location = new System.Drawing.Point(182, 26);
            this.imagename.Name = "imagename";
            this.imagename.Size = new System.Drawing.Size(0, 13);
            this.imagename.TabIndex = 4;
            // 
            // listView1
            // 
            this.listView1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.listView1.LabelEdit = true;
            this.listView1.Location = new System.Drawing.Point(0, 532);
            this.listView1.MultiSelect = false;
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(1350, 197);
            this.listView1.TabIndex = 5;
            this.listView1.UseCompatibleStateImageBehavior = false;
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.groupBox1.AutoSize = true;
            this.groupBox1.Controls.Add(this.loadMap);
            this.groupBox1.Controls.Add(this.btnSave);
            this.groupBox1.Controls.Add(this.btnloadbackground);
            this.groupBox1.Controls.Add(this.btntitle);
            this.groupBox1.Location = new System.Drawing.Point(12, 26);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(20);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(10);
            this.groupBox1.Size = new System.Drawing.Size(170, 491);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Control Menu";
            // 
            // loadMap
            // 
            this.loadMap.Location = new System.Drawing.Point(26, 186);
            this.loadMap.Name = "loadMap";
            this.loadMap.Size = new System.Drawing.Size(105, 31);
            this.loadMap.TabIndex = 4;
            this.loadMap.Text = "Load map";
            this.loadMap.UseVisualStyleBackColor = true;
            this.loadMap.Click += new System.EventHandler(this.loadMap_Click);
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(26, 129);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(105, 32);
            this.btnSave.TabIndex = 3;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // pictureResult
            // 
            this.pictureResult.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureResult.Location = new System.Drawing.Point(195, 137);
            this.pictureResult.Name = "pictureResult";
            this.pictureResult.Size = new System.Drawing.Size(1128, 380);
            this.pictureResult.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureResult.TabIndex = 7;
            this.pictureResult.TabStop = false;
            // 
            // btn_loadBackground
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1350, 729);
            this.Controls.Add(this.pictureResult);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.imagename);
            this.Controls.Add(this.widthheight);
            this.Controls.Add(this.imgmap);
            this.Name = "btn_loadBackground";
            this.Text = "Editor";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            ((System.ComponentModel.ISupportInitialize)(this.imgmap)).EndInit();
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureResult)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnloadbackground;
        private System.Windows.Forms.PictureBox imgmap;
        private System.Windows.Forms.Button btntitle;
        private System.Windows.Forms.Label widthheight;
        private System.Windows.Forms.Label imagename;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button loadMap;
        private System.Windows.Forms.PictureBox pictureResult;
    }
}

