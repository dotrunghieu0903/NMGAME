using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Editor.Tiles
{
    class ListTiles
    {
        int _width = 8;
        int _height = 8;
        IList<Tile> _listTiles = new List<Tile>();
        Bitmap _image;

        public ListTiles()
        {
        }

        public ListTiles(int w, int h, string path)
        {
            _width = w;
            _height = h;
            _image = new Bitmap(path);
        }

        public ListTiles(int w, int h, Bitmap image)
        {
            _width = w;
            _height = h;
            _image = image;
        }

        public static ListTiles INSTANCE
        {
            get
            {
                return new ListTiles();
            }
        }


        public IList<Tile> getListTile()
        {
            return _listTiles;
        }

        public void Add(Tile tile)
        {
            _listTiles.Add(tile);
        }

        public void createTiles()
        {
            int width = _image.Width;
            int height = _image.Height;
            Console.WriteLine("image width " + width);
            Console.WriteLine("image height " + height);
            Console.WriteLine("_w " + _width);
            int id = 0;
            for(int row = 0; row < height ; row += _height)
                for(int col = 0; col < width; col += _width)
                {
                    Tile tile = new Tile(id, "tile" + id, col, row, _width, _height);
                    if(canNotFind(tile))
                    {
                        _listTiles.Add(tile);
                        id++;
                    }
                    
                }
            Console.WriteLine((_listTiles.Count) + " TILES");
            Console.WriteLine( (height/_height)*(width/_width) + " cells");
        }

        public void Draw(ListView listView)
        {
            if (listView.Items.Count > 0)
                listView.Items.Clear();
            listView.LargeImageList = this.imageList; //list bitmaps
            listView.Items.AddRange(this.listViewItems.ToArray());
        }


        //for draw: create source image
        ImageList imageList
        {
            get
            {
                ImageList list = new ImageList();
                PixelFormat format = this._image.PixelFormat;
                foreach (Tile tile in this._listTiles)
                {
                    list.Images.Add(this._image.Clone(tile.SrcRect, format));
                }
                list.ImageSize = new Size(40, 40);
                return list;
            }
        }

        //for draw: create image index
        List<ListViewItem> listViewItems
        {
            get
            {
                //code
                if (this._listTiles == null)
                    return null;
                if (this._image == null)
                    return null;
                List<ListViewItem> list = new List<ListViewItem>();
                foreach (Tile tile in this._listTiles)
                {
                    list.Add(tile.tileItem); 
                }
                return list;
            }
        }


        public Boolean canNotFind(Tile t)
        {
            if (_listTiles == null) return true;
            foreach(Tile tile in _listTiles)
            {
                if(compare(tile,t))
                {
                    return false;
                }
            }
            return true;
        }

        public int findId(Tile t)
        {
            if (_listTiles == null) return -1;
            foreach (Tile tile in _listTiles)
            {
                if (compare(tile, t))
                {
                    return tile.Id;
                }
            }
            return -1;
        }

        Boolean compare(Tile tile, Tile t) 
        {
            for(int i = 0; i < tile.SrcRect.Height; i++)
            {
                for(int j = 0; j < tile.SrcRect.Width;j++)
                {
                    try
                    {
                        if (_image.GetPixel(tile.SrcRect.X + i, tile.SrcRect.Y + j) != _image.GetPixel(t.SrcRect.X + i, t.SrcRect.Y + j))
                        {
                            return false;
                        }
                    } catch(Exception ex ) { }
                }
            }
            return true;
        }

        public void SaveFile(string fileName, string folder)
        {
            //try
            //{
                /*************** File txt *****************/
                using (StreamWriter file = new StreamWriter(folder + "//" + fileName + ".txt"))
                {
                    file.Write(this._image.Width / _width + " ");
                    file.Write(this._image.Height / _height + " ");
                    file.Write(this._width.ToString() + " ");
                    file.Write(this._height.ToString() + " ");
                    file.WriteLine();
                    /********************************/
                    int width = _image.Width;
                    int height = _image.Height;
                    int id = 0;
                    for (int row = 0; row < height; row += _height)
                    {
                        int col;
                        for (col = 0; col < width; col += _width)
                        {
                            Tile tile = new Tile(id, "tile" + id, col, row, _width, _height);
                            file.Write("{0,4}", findId(tile).ToString() + " ");
                        }
                        file.WriteLine();

                    }
                    file.Close();

                }
                MessageBox.Show("Done, file txt saved!");
                /*************** File image *****************/
                Bitmap image1 = new Bitmap(_width * (this._image.Width / _width)+ _width, _height);
                for(int index = 0; index < _listTiles.Count ; index ++)
                {
                    Console.WriteLine("Index: " + index);
                Color color = new Color();
                for (int r = 0; r < _height; r++)
                    {
                        for(int c = 0; c < _width; c++)
                        {
                            //Console.WriteLine("      (" + (_listTiles[index].SrcRect.X + r).ToString() + ";" + (_listTiles[index].SrcRect.Y + c).ToString() + ")");
                            

                            color = _image.GetPixel(_listTiles[index].SrcRect.X + r, _listTiles[index].SrcRect.Y + c);
                            //if(c == 0 || c == index*_width || r == 0 || r == _height)
                            //{
                            //    image1.SetPixel(index * _width + r, c, Color.White);
                            //} else
                            //{
                            //    image1.SetPixel(index * _width + r, c, Color.Red);
                            //}
                            image1.SetPixel(index * _width + r, c, color);
                        }
                    }
                }
                image1.Save(folder + "\\" + fileName + ".png");
                MessageBox.Show("Done, file png saved!");
            //}
            //catch
            //{
               
            //}
        }

    }

    
}
