using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace MapEditor
{
    class QuadNode
    {
        public const int MIN_SIZE_OF_NODE = 520;

        public int _id; //Id của node
        public Rectangle _bounds; // vị trí của node
        public int level;
        public List<MyObject> _listObject; // Danh sách các đối tượng trong node
        public QuadNode _nodeTL; // Node con left top
        public QuadNode _nodeTR; // Node con right top
        public QuadNode _nodeBL; // Node con left bottom
        public QuadNode _nodeBR; // Node con right bottom

        public QuadNode(int id, int level, Rectangle bounds)
        {
            this._id = id;
            this.level = level;
            this._bounds = bounds;
            this._listObject = new List<MyObject>();
        }

        public void buildQuadNode(List<MyObject> listObject)
        {
            //if (Rectangle.Intersect(this.m_Bounds, _obj.m_Bounds).Height == 0) //Kiểm tra bounds của Object và Node có tiếp xúc không
            //    return;
            if (listObject.Count == 0)
                return;
            if (this._bounds.Height > MIN_SIZE_OF_NODE) //  Kiểm tra kích thước node có vượt giới hạn hay không
            {
                _nodeTL = new QuadNode(this._id * 10 + 1, this.level + 1, new Rectangle(this._bounds.X, this._bounds.Y, this._bounds.Width / 2, this._bounds.Height / 2));
                _nodeTR = new QuadNode(this._id * 10 + 2, this.level + 1, new Rectangle(this._bounds.X + this._bounds.Width / 2, this._bounds.Y, this._bounds.Width / 2, this._bounds.Height / 2));
                _nodeBL = new QuadNode(this._id * 10 + 3, this.level + 1, new Rectangle(this._bounds.X, this._bounds.Y + this._bounds.Height / 2, this._bounds.Width / 2, this._bounds.Height / 2));
                _nodeBR = new QuadNode(this._id * 10 + 4, this.level + 1, new Rectangle(this._bounds.X + this._bounds.Width / 2, this._bounds.Y + this._bounds.Height / 2, this._bounds.Width / 2, this._bounds.Height / 2));

                clip(listObject, _nodeTL);
                clip(listObject, _nodeTR);
                clip(listObject, _nodeBL);
                clip(listObject, _nodeBR);

                _nodeTL.buildQuadNode(_nodeTL._listObject);
                _nodeTR.buildQuadNode(_nodeTR._listObject);
                _nodeBL.buildQuadNode(_nodeBL._listObject);
                _nodeBR.buildQuadNode(_nodeBR._listObject);

                this._listObject.Clear();
            }
            else
                return; //Nếu kích thước của node <= MINSIZEOFNODE => đây là node lá
        }
        public void clip(List<MyObject> listObject, QuadNode node)
        {
            foreach (MyObject objectItem in listObject)
            {
                int temp = Rectangle.Intersect(objectItem.Rectangle, node._bounds).Height;
                if (Rectangle.Intersect(objectItem.Rectangle, node._bounds).Height != 0)
                {
                    node._listObject.Add(objectItem);
                }
            }
        }
    }
}
