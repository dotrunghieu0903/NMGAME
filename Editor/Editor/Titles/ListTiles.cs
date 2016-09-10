using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
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
            for(int row = 0; row < height - _height*2; row += _height -1)
                for(int col = 0; col < width - _width*2; col += _width -1)
                {
                    Tile tile = new Tile(id, "tile" + id, col, row, _width, _height);
                    if(canNotFind(tile))
                    {
                        _listTiles.Add(tile);
                        id++;
                        
                    }
                    
                }
            Console.WriteLine((_listTiles.Count-1) + " TILES");
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

        Boolean compare(Tile tile, Tile t) 
        {
            for(int i = 0; i < tile.SrcRect.Height; i++)
            {
                for(int j = 0; j < tile.SrcRect.Width;j++)
                {
                    if (_image.GetPixel(tile.SrcRect.X + i, tile.SrcRect.Y + j) != _image.GetPixel(t.SrcRect.X + i, t.SrcRect.Y + j))
                    {
                        return false;
                    }
                }
            }
            return true;
        }

    }

    
}
