using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor
{
    public partial class input1 : Form
    {
        public int col = 0;
        public int row = 0;
        public input1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                col = Int16.Parse(txt_columns.Text);
                row = Int16.Parse(txt_rows.Text);
                this.DialogResult = DialogResult.OK;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Input not null!", "Error input", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
