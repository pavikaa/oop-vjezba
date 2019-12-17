using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lv6zad2
{
    public partial class Form1 : Form
    {
        List<Kontakt> listKontakti = new List<Kontakt>();
        string path = "D:\\kontakti.txt";
        bool check=false;
        int i;
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool empty = false;
            if (textBox1.Text == "" || textBox2.Text == "" || textBox3.Text == "")
            {
                empty = true;
                MessageBox.Show("Neko od polja ostalo je prazno.");
            }
            else
                empty = false;

            if (!empty)
            {
                Kontakt K = new Kontakt(textBox1.Text, textBox2.Text, textBox3.Text);
                listKontakti.Add(K);
                lb_Kontakti.DataSource = null;
                lb_Kontakti.DataSource = listKontakti;
            }
        }

        private void lb_Kontakti_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            using (System.IO.StreamReader reader = new System.IO.StreamReader(@path))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    string[] parts = line.Split('\t');
                    Kontakt K = new Kontakt(parts[0], parts[1], parts[2]);
                    listKontakti.Add(K);
                }
                lb_Kontakti.DataSource = null;
                lb_Kontakti.DataSource = listKontakti;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            using (System.IO.StreamWriter write = new System.IO.StreamWriter(@path))
            {
                foreach (Kontakt k in listKontakti)
                {
                    {
                        write.WriteLine(k.ToString());
                    }
                }
            }
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            i = 0;
            check = false;
            foreach (Kontakt k in listKontakti)
            {
                if (k.ToString().Contains(textBox4.Text))
                {
                    check = true;
                    MessageBox.Show("Pronađen. " + listKontakti[i]);
                }
                i++;
            }
            if (!check)
            MessageBox.Show("Nije pronađen.");
        }
        class Kontakt
        {
            #region data_members
            private string ime;
            private string prezime;
            private string brojTelefona;
            #endregion
            #region public_methods
            public Kontakt()
            {
                ime = "Ivan";
                prezime = "Ivanić";
                brojTelefona = "0000000000";
            }
            public Kontakt(string i, string p, string b)
            {
                ime = i;
                prezime = p;
                brojTelefona = b;
            }
            public override string ToString()
            {
                return ime + "\t" + prezime + "\t" + brojTelefona;
            }
            #endregion
        }
    }
}
