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
        string fileName = "";
        string folder = "";
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
                
               // listTiles.Draw(listView1);
                MessageBox.Show("end ");
            }
            
            
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                Console.WriteLine(listTiles.getListTile());
            }
            catch
            {
                MessageBox.Show("Don't has tiles!");
                return;
            }
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Title = "Choose where the file will be saved!";
            saveFileDialog.DefaultExt = "txt";

            saveFileDialog.Filter = "Text files (*.txt)|*.txt";
            DialogResult result = saveFileDialog.ShowDialog();
            
            if (result == DialogResult.OK)
            {
                fileName = Path.GetFileNameWithoutExtension(saveFileDialog.FileName);
                folder = Path.GetDirectoryName(saveFileDialog.FileName);
                listTiles.SaveFile(fileName, folder);
                
            }
        }

        private void loadMap_Click(object sender, EventArgs e)
        {
            OpenFileDialog oFile = new OpenFileDialog();
            oFile.Title = "Choose file maxtrix";
            oFile.Filter = "Text files (*.txt)|*.txt";
            DialogResult result = oFile.ShowDialog();
            
            if(result == DialogResult.OK || File.Exists(oFile.FileName))
            {
                String pathPNG = Path.GetDirectoryName(oFile.FileName) + "\\" + Path.GetFileNameWithoutExtension(oFile.FileName) + ".png";
                if(!File.Exists(pathPNG))
                {
                    MessageBox.Show("can not find " + pathPNG);
                }
                imgmap.Image = Image.FromFile(pathPNG);
                widthheight.Text = imgmap.Image.Width + "x" + imgmap.Image.Height + " (pixcels)";
                imagename.Text = pathPNG;
                int col = 0;
                int row = 0;
                int _width;
                int _height;
                int[,] maxtrix;
                using (StreamReader file = new StreamReader(oFile.FileName))
                {
                    var parts = file.ReadLine().Trim().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int n = Int32.Parse(parts[0]); // number of tiles
                    col = Int32.Parse(parts[1]);
                    row = Int32.Parse(parts[2]);
                    _width = Int32.Parse(parts[3]);
                    _height = Int32.Parse(parts[4]);
                    maxtrix = new int[row, col];
                    for (int r = 0; r < row; r++)
                    {
                        int c = 0;
                        foreach(string value in file.ReadLine().Trim().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries))
                        {
                            maxtrix[r, c++] = Int32.Parse(value);
                        }
                    }
                    file.Close();
                }

                for (int r = 0; r < row; r++)
                {
                    for (int c = 0; c < col; c++)
                    {
                        Console.Write("{0,4}", maxtrix[r, c]);
                    }
                    Console.WriteLine();
                }
                listTiles = new ListTiles(_width, _height, pathPNG);
                listTiles.createTiles();
                listTiles.Draw(listView1);
                Bitmap bit = new Bitmap( col * _width, row * _height);
                Bitmap src = listTiles.getImage();
                for (int r = 0; r < row; r++)
                {
                    for (int c = 0; c < col; c++)
                    {
                        //get bitmap
                        for(int i = 0; i < _width; i++)
                        {
                            for(int j = 0; j < _height;j++)
                            {
                                Color color = new Color();
                                color = src.GetPixel(maxtrix[r, c] * _width + i, j);
                                bit.SetPixel(c * _width + i, r * _height + j, color);
                            }
                        }
                    }
                }
                pictureResult.Image = bit;
            }
        }

        private void imgmap_Click(object sender, EventArgs e)
        {

        }
    }
}
