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
            ((System.ComponentModel.ISupportInitialize)(this.imgmap)).BeginInit();
            this.SuspendLayout();
            // 
            // btnloadbackground
            // 
            this.btnloadbackground.Location = new System.Drawing.Point(37, 42);
            this.btnloadbackground.Name = "btnloadbackground";
            this.btnloadbackground.Size = new System.Drawing.Size(105, 34);
            this.btnloadbackground.TabIndex = 0;
            this.btnloadbackground.Text = "Load Background";
            this.btnloadbackground.UseVisualStyleBackColor = true;
            this.btnloadbackground.Click += new System.EventHandler(this.btnloadbackground_Click);
            // 
            // imgmap
            // 
            this.imgmap.Location = new System.Drawing.Point(185, 42);
            this.imgmap.Name = "imgmap";
            this.imgmap.Size = new System.Drawing.Size(1138, 411);
            this.imgmap.TabIndex = 1;
            this.imgmap.TabStop = false;
            // 
            // btntitle
            // 
            this.btntitle.Location = new System.Drawing.Point(37, 97);
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
            this.listView1.LabelEdit = true;
            this.listView1.Location = new System.Drawing.Point(13, 148);
            this.listView1.MultiSelect = false;
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(166, 305);
            this.listView1.TabIndex = 5;
            this.listView1.UseCompatibleStateImageBehavior = false;
            // 
            // btn_loadBackground
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1350, 729);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.imagename);
            this.Controls.Add(this.widthheight);
            this.Controls.Add(this.btntitle);
            this.Controls.Add(this.imgmap);
            this.Controls.Add(this.btnloadbackground);
            this.Name = "btn_loadBackground";
            this.Text = "Editor";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            ((System.ComponentModel.ISupportInitialize)(this.imgmap)).EndInit();
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
    }
}

