using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ComponentModel;

namespace Editor.Tiles
{
    class Tile
    {
        int _id;
        string _name;
        Rectangle _srcRect;

        public Tile()
        {
            _id = -1;
            _name = "null";
            _srcRect = new Rectangle(0, 0, 8, 8);
        }

        public Tile(int id, string name, Rectangle srcRect)
        {
            _id = id;
            _name = name;
            _srcRect = srcRect;
        }

        public Tile(int id, string name, int x, int y, int width, int height)
        {
            _id = id;
            _name = name;
            _srcRect = new Rectangle(x, y, width, height);
        }



        public ListViewItem tileItem
        {
            get
            {
                ListViewItem item = new ListViewItem();
                item.ImageIndex = this._id;
                return item;
            }
        }


        // auto code
        public int Id
        {
            get
            {
                return _id;
            }

            set
            {
                _id = value;
            }
        }

        public string Name
        {
            get
            {
                return _name;
            }

            set
            {
                _name = value;
            }
        }

        public Rectangle SrcRect
        {
            get
            {
                return _srcRect;
            }

            set
            {
                _srcRect = value;
            }
        }
        public event PropertyChangedEventHandler PropertyChanged;

        protected void OnProPertyChanged(PropertyChangedEventArgs args)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, args);
            }
        }
    }
}
