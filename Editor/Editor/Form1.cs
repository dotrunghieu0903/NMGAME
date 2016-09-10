using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Collections;
using System.Drawing.Imaging;
using Editor.Tiles;

namespace Editor
{
    public partial class btn_loadBackground : Form
    {
        List<Bitmap> bitmaps = new List<Bitmap>();
        ListTiles listTiles;
        string path = "";
        public btn_loadBackground()
        {
            InitializeComponent();
        }

        OpenFileDialog imageDlg = new OpenFileDialog();
        private void btnloadbackground_Click(object sender, EventArgs e)
        {
            imageDlg.Title = "Select image";
            imageDlg.Filter = "Image|*.png;*.bmp";
            if(imageDlg.ShowDialog() == DialogResult.OK)
            {
                imgmap.Image = Image.FromFile(imageDlg.FileName);
                path = imageDlg.FileName;
                widthheight.Text = imgmap.Image.Width + "x" + imgmap.Image.Height + " (pixcels)";
                imagename.Text = imageDlg.FileName.ToString();
            }
        }

 




        private void btntitle_Click(object sender, EventArgs e)
        {
           
            frmTitle title = new frmTitle();
            if (title.ShowDialog() == DialogResult.OK)
            {
                MessageBox.Show("start " + title._width + " " + title._height);
                listTiles = new ListTiles(title._width, title._height, path);
                listTiles.createTiles();
                
                listTiles.Draw(listView1);
                MessageBox.Show("end ");
            }
            
            
        }
    }
}
