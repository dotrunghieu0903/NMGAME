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

        public void SaveFile(string filename)
        {
            /*************** File txt *****************/
            using (StreamWriter file = new StreamWriter(filename))
            {
                file.WriteLine(this._col + " " + this._row);
                file.WriteLine("16 16");
                /********************************/

                foreach (MyObject myObject in listObject)
                {
                    file.WriteLine(myObject.image.Id + " " + myObject.rect.X + " " + myObject.rect.Y);
                }
                file.Close();

            }
        }

        public void Draw()
        {
            foreach(MyObject myObject in listObject)
            {
                Image img = new Image();
                Uri imageUri = new Uri(myObject.image.Path);
                BitmapImage imageBitmap = new BitmapImage(imageUri);

                img.Source = imageBitmap;
                img.Width = myObject.image.Width * 3;
                img.Height = myObject.image.Height * 3;

                //img.MouseRightButtonDown += img_MouseRightButtonDown;
                Canvas.SetTop(img, myObject.rect.Y * 3 );
                Canvas.SetLeft(img, myObject.rect.X *3 );
                this.canvas.Children.Add(img);
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
            foreach(ListImage item in items)
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
                canvas.Width = 48 * input.col;
                canvas.Height = 48 * input.row;
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
            pointer.Content = "col:" + (int)relativePosition.X/48 + " row:" + (int)relativePosition.Y/48;
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
                //var point = PointToScreen(relativePosition);

                int col = (int)relativePosition.X / 48;
                int row = (int)relativePosition.Y / 48;

                MyObject result = listObject.Find(x => x.col == col && x.row == row);
               
                if (curentSelect.Path != null && result == null)
                {
                    listObject.Add(new MyObject(curentSelect, col * 16, row * 16));
                    Image img = new Image();
                    Uri imageUri = new Uri(curentSelect.Path);
                    BitmapImage imageBitmap = new BitmapImage(imageUri);

                    img.Source = imageBitmap;
                    img.Width = curentSelect.Width * 3;
                    img.Height = curentSelect.Height * 3;

                    //img.MouseRightButtonDown += img_MouseRightButtonDown;
                    Canvas.SetTop(img, row * 48);
                    Canvas.SetLeft(img, col * 48);
                    this.canvas.Children.Add(img);
                   
                }
                else
                {
                    System.Windows.MessageBox.Show("this already exists object!");
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
                    _col = Int32.Parse(parts[0]);
                    _row = Int32.Parse(parts[1]);
                    file.ReadLine();
                    canvas.Width = 48 * _col;
                    canvas.Height = 48 * _row;
                    string line;
                    while ((line = file.ReadLine()) != null || !file.EndOfStream)
                    {
                        var part = line.Trim().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        int id = Int32.Parse(part[0]);
                        int X = Int32.Parse(part[1]);
                        int Y = Int32.Parse(part[2]);
                        ListImage item = items.Find(x => x.Id == id);
                        listObject.Add(new MyObject(item, X, Y));
                    }
                    file.Close();
                }
                Draw();
            }
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
        public ListImage image;
        public Rect rect;

        public MyObject(ListImage _image, Rect _rect)
        {
            this.image = _image; this.rect = _rect;
        }

        public MyObject(ListImage _image, int x, int y)
        {
            this.image = _image; this.rect.X = x;  this.rect.Y = y;  this.rect.Width = _image.Width; this.rect.Height = _image.Height;
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

        
    }

    
}
