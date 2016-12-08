using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Drawing;

namespace MapEditor
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        int _row;
        int _col;
        ListImage curentSelect;
        List<MyObject> listObject;
        List<ListImage> items;
        int i = 0;
        static System.Windows.Point cusor = new System.Windows.Point(0, 0);

        public void SaveFile(string filename)
        {
            /*************** File object txt *****************/
            using (StreamWriter file = new StreamWriter(filename))
            {
                file.WriteLine(listObject.Count+ 1);
                foreach (MyObject myObject in listObject)
                {
                    file.WriteLine(myObject.id + " " + myObject.image.Id + " " + (int)myObject.rect.X + " " + (int)myObject.rect.Y + " " + (int)myObject.rect.Width + " " + (int)myObject.rect.Height );
                }
                file.Close();
            }
            /*************** File quad txt *****************/
            List<StringBuilder> listQuadNode = this.buildQuadTree();
            System.IO.TextWriter writeFile;

            String filequad = System.IO.Path.GetDirectoryName(filename)+ "//" + System.IO.Path.GetFileNameWithoutExtension(filename) + "_Quad.txt";
  
  
            if (!System.IO.File.Exists(filequad))
            {
                writeFile = new System.IO.StreamWriter(filequad, true);
            }
            else
            {
                System.IO.File.Delete(filequad);
                writeFile = new System.IO.StreamWriter(filequad, false);
            }
            int size = listQuadNode.Count;
            for (int i = 0; i < size; i++)
            {
                writeFile.WriteLine(listQuadNode[i]);
            }
        }

        private QuadTree _quadTreeRoot;
        private List<StringBuilder> buildQuadTree()
        {

            //if (tileRowIn != 0 && tileColIn != 0) {
            //    int maxSize = (this.tileRowIn * 16 > this.tileColIn * 16) ? this.tileRowIn * 16 : this.tileColIn * 16;
            //}
            //else
            //{

            //}
            double maxSize = canvas.Width > canvas.Height ? canvas.Width : canvas.Height;
            System.Drawing.Rectangle recRoot = new System.Drawing.Rectangle(0, 0, (int)maxSize, (int)maxSize);
            List<StringBuilder> listQuadNode = new List<StringBuilder>();
            _quadTreeRoot = new QuadTree(recRoot);
            _quadTreeRoot.buildQuadTree(listObject);
            _quadTreeRoot.export(_quadTreeRoot._root, listQuadNode);
            return listQuadNode;
        }

        public void Draw()
        {
            foreach(MyObject myObject in listObject)
            {
                System.Windows.Controls.Image img = new System.Windows.Controls.Image();
                Uri imageUri = new Uri(myObject.image.Path);
                BitmapImage imageBitmap = new BitmapImage(imageUri);

                img.Source = imageBitmap;
                img.Width = myObject.rect.Width;
                img.Height = myObject.rect.Height;
                img.Stretch = Stretch.Fill;

                //img.MouseRightButtonDown += img_MouseRightButtonDown;
                Canvas.SetTop(img, myObject.rect.Y );
                Canvas.SetLeft(img, myObject.rect.X );
                this.canvas.Children.Add(img);//
        
            }
        }


        public MainWindow()
        {
            InitializeComponent();
            listObject = new List<MyObject>();
            items = new List<ListImage>();
            items.Add(new ListImage(1, "ChunkOfTheCountExploding",16, 16, @"C:\Users\giapn\Desktop\NMGAME\MapEditor\MapEditor\resource\ChunkOfTheCountExploding.png"));
            items.Add(new ListImage(2, "LargeCandle",16, 32, @"C:\Users\giapn\Desktop\NMGAME\MapEditor\MapEditor\resource\LargeCandle.png"));
            items.Add(new ListImage(3, "MoneyBag100",15, 15, @"C:\Users\giapn\Desktop\NMGAME\MapEditor\MapEditor\resource\MoneyBag100.png"));
            items.Add(new ListImage(4, "MoneyBag400",15, 15, @"C:\Users\giapn\Desktop\NMGAME\MapEditor\MapEditor\resource\MoneyBag400.png"));
            items.Add(new ListImage(5, "ground", 32, 32, @"C:\Users\giapn\Desktop\NMGAME\MapEditor\MapEditor\resource\ground1.png"));
            foreach (ListImage item in items)
            {
                listBox.Items.Add(item);
            }
            //listBox.Items.Add(items;

        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            input1 input = new input1();
            DialogResult result = input.ShowDialog();
            if(result == System.Windows.Forms.DialogResult.OK)
            {
                canvas.Width = 32 * input.col;
                canvas.Height = 32 * input.row;
                _row = input.row;
                _col = input.col;
            }

            
        }


        private void canvas_MouseLeave(object sender, System.Windows.Input.MouseEventArgs e)
        {
            pointer.Content = "";
        }

        private void canvas_MouseMove(object sender, System.Windows.Input.MouseEventArgs e)
        {
            //Point p = Mouse.GetPosition(canvas);
            var relativePosition = e.GetPosition(canvas);
            //var point = PointToScreen(relativePosition);
            pointer.Content = "col:" + (int)relativePosition.X + " row:" + (int)relativePosition.Y;
        }

        private void listBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            curentSelect = (ListImage)e.AddedItems[0];
        }

        private void canvas_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if(curentSelect != null)
            {
                var relativePosition = e.GetPosition(canvas);
                var point = PointToScreen(relativePosition);
                Console.Write("cusor: ");
                Console.WriteLine(cusor);
                if (cusor.X == 0 && cusor.Y ==0 && e.LeftButton == MouseButtonState.Pressed )
                {
                    System.Windows.Forms.MessageBox.Show("set start!");
                    Console.Write("Set cusor: ");
                    cusor = relativePosition;
                    Console.WriteLine(cusor);
                    return;
                }
               if(e.RightButton == MouseButtonState.Pressed)
                {
                    System.Windows.Forms.MessageBox.Show("set end!");
                    Console.WriteLine("up");

                    
                    Console.Write("set start  = cusor =  ");
                    System.Windows.Point start = cusor;
                    Console.WriteLine(cusor);

                    System.Windows.Point end = relativePosition;
                    Console.WriteLine(curentSelect.Id);
                    Console.WriteLine(start);
                    Console.WriteLine(end);


                    Rect rect_tamp = new Rect(start, end);

                    listObject.Add(new MyObject(i++,curentSelect, rect_tamp));
                    System.Windows.Controls.Image img = new  System.Windows.Controls.Image();
                    Uri imageUri = new Uri(curentSelect.Path);
                    BitmapImage imageBitmap = new BitmapImage(imageUri);

                    img.Source = imageBitmap;
                    img.Stretch = Stretch.Fill;
                    img.Width = Math.Abs(end.X - start.X);
                    img.Height = Math.Abs(end.Y - start.Y);

                    //img.MouseRightButtonDown += img_MouseRightButtonDown;
                    Canvas.SetTop(img, start.Y);
                    Canvas.SetLeft(img, start.X);
                    this.canvas.Children.Add(img);
                    cusor.X = 0;
                    cusor.Y = 0;
                }

            }
            else
            {
                System.Windows.MessageBox.Show("no select");
            }
        }

        private void save_Click(object sender, RoutedEventArgs e)
        {
            if(listObject.Count == 0)
            {
                System.Windows.MessageBox.Show("nothing to save!");
            }
            else
            {
                SaveFileDialog saveFileDialog = new SaveFileDialog();
                saveFileDialog.Title = "Choose where the file will be saved!";
                saveFileDialog.DefaultExt = "txt";

                saveFileDialog.Filter = "Text files (*.txt)|*.txt";
                DialogResult result = saveFileDialog.ShowDialog();

                if (result == System.Windows.Forms.DialogResult.OK)
                {
                    SaveFile(saveFileDialog.FileName);
                }
            }
        }

        private void load_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog oFile = new OpenFileDialog();
            oFile.Title = "Choose file maxtrix";
            oFile.Filter = "Text files (*.txt)|*.txt";
            DialogResult result = oFile.ShowDialog();

            if (result == System.Windows.Forms.DialogResult.OK || File.Exists(oFile.FileName))
            {
                using (StreamReader file = new StreamReader(oFile.FileName))
                {
                    listObject.Clear();
                    var parts = file.ReadLine().Trim().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    _col = 224;
                    //_row = 14;
                    file.ReadLine();
                    canvas.Width = 32 * _col;
                    canvas.Height = 32 * _row;
                    string line;
                    while ((line = file.ReadLine()) != null || !file.EndOfStream)
                    {
                        var part = line.Trim().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        int id = Int32.Parse(part[0]);
                        int type = Int32.Parse(part[1]);
                        int X = Int32.Parse(part[2]);
                        int Y = Int32.Parse(part[3]);
                        int With = Int32.Parse(part[4]);
                        int Height = Int32.Parse(part[5]);
                        ListImage item = items.Find(x => x.Id == type);
                        MyObject temp = new MyObject(id, item, new Rect(X, Y, Width, Height));
                        listObject.Add(temp);
                    }
                    file.Close();
                }
                Draw();
            }
        }

        private void button_Copy_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog oFile = new OpenFileDialog();
            oFile.Title = "Choose file image";
            oFile.Filter = "image files (*.png)|*.png";
            DialogResult result = oFile.ShowDialog();
            if (result == System.Windows.Forms.DialogResult.OK || File.Exists(oFile.FileName))
            {
                ImageBrush ib = new ImageBrush();
                ib.ImageSource = new BitmapImage(new Uri(oFile.FileName, UriKind.Relative));
                canvas.Background = ib;
            }
        }

        private void canvas_MouseUp(object sender, MouseButtonEventArgs e)
        {

        }
    }

    public class ListImage
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Path { get; set; }
        public int Width;
        public int Height;
        public ListImage(int id, string name, int width, int height, string path)
        {
            this.Id = id; this.Name = name; this.Path = path; this.Width = width; this.Height = height;
        }
    }


    public class MyObject
    {
        public int id { get; set; }
        public ListImage image;
        public Rect rect;

        public MyObject(int id, ListImage _image, Rect _rect)
        {
            this.image = _image; this.rect = _rect; this.id = id;
        }

        public MyObject(int id, ListImage _image, int x, int y)
        {
            this.image = _image; this.rect.X = x;  this.rect.Y = y;  this.rect.Width = _image.Width; this.rect.Height = _image.Height; this.id = id;
        }

        public int col
        {
            get
            {
                return ((int)this.rect.X) / 16;
            }
        }

        public int row
        {
            get
            {
                return ((int)this.rect.Y) / 16;
            }
        }

        public System.Drawing.Rectangle Rectangle
        {
            get
            {
                return  new System.Drawing.Rectangle((int)rect.X, (int)rect.Y, (int)rect.Width, (int)rect.Height);
            }
        }

        
    }

    
}
