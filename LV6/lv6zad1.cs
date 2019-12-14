using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lv6zad1
{
    public partial class Form1 : Form
    {
        double a, b, c;
        public Form1()
        {
            InitializeComponent();
        }

        private void povrsina_Click(object sender, EventArgs e)
        {
            if (!double.TryParse(tB_a.Text, out a) || a < 0)
                MessageBox.Show("Pogrešan unos stranice a.");
            else if (!double.TryParse(tB_b.Text, out b) || b < 0)
                MessageBox.Show("Pogrešan unos stranice b.");
            else if (!double.TryParse(tB_c.Text, out c) || c < 0)
                MessageBox.Show("Pogrešan unos stranice c.");
            else if (a >= b + c || b >= a + c || c >= a + b)
            {
                MessageBox.Show("Pogrešan unos trokuta.");
            }
            else
            {
                double s = (a + b + c)/2;
                double P = System.Math.Sqrt(s * (s - a) * (s - b) * (s - c));
                rezultat.Text =P.ToString();
            }
        }

        private void pravokutan_Click(object sender, EventArgs e)
        {
            if (!double.TryParse(tB_a.Text, out a) || a < 0)
                MessageBox.Show("Pogrešan unos stranice a.");
            else if (!double.TryParse(tB_b.Text, out b) || b < 0)
                MessageBox.Show("Pogrešan unos stranice b.");
            else if (!double.TryParse(tB_c.Text, out c) || c < 0)
                MessageBox.Show("Pogrešan unos stranice c.");
            else if (a >= b + c || b >= a + c || c >= a + b)
            {
                MessageBox.Show("Pogrešan unos trokuta.");
            }
            if (a == System.Math.Sqrt(b * b + c * c) || b == System.Math.Sqrt(a * a + c * c) || c == System.Math.Sqrt(b * b + a * a))
                MessageBox.Show("Trokut je pravokutan.");
            else
                MessageBox.Show("Trokut nije pravokutan.");
        }

        private void quit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void opseg_Click(object sender, EventArgs e)
        {
            if (!double.TryParse(tB_a.Text, out a)|| a<0)
                MessageBox.Show("Pogrešan unos stranice a.");
            else if (!double.TryParse(tB_b.Text, out b)||b<0)
                MessageBox.Show("Pogrešan unos stranice b.");
            else if (!double.TryParse(tB_c.Text, out c)||c<0)
                MessageBox.Show("Pogrešan unos stranice c.");
            else if (a >= b + c || b >= a + c || c >= a + b)
            {
                MessageBox.Show("Pogrešan unos trokuta.");
            }
            else
            {
                rezultat.Text = (a + b + c).ToString();
            }
        }
    }
}
