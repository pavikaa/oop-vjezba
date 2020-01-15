using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LV7_Zad_2
{
    public partial class Form1 : Form
    {
        Graphics g;
        bool check = false;
        Pen pen;
        public void update()
        {
            float width = hS.Value;
            if (red.Checked)
            {
                pen=new Pen(Color.Red, width);
                check = true;
            }
            if (blue.Checked)
            {
                pen=new Pen(Color.Blue, width);
                check = true;
            }
            if (green.Checked)
            {
                pen=new Pen(Color.Green, width);
                check = true;
            }
        }
        public Form1()
        {
            InitializeComponent();
            g = pbDrawing.CreateGraphics();
        }
    private void pbDrawing_Click(object sender, EventArgs e)
        {
            update();
        }

        private void pbDrawing_MouseUp_1(object sender, MouseEventArgs e)
        {
            
            if (circle.Checked&&check)
            {
                update();
                Circle c = new Circle();
                c.draw(g, pen, e.X, e.Y);
            }
            if (square.Checked && check)
            {
                update();
                Square s = new Square();
                s.draw(g,pen,e.X,e.Y);
            }
            if (triangle.Checked && check)
            {
                update();
                Triangle t = new Triangle();
                t.draw(g, pen, e.X, e.Y);
            }
        }

        private void hS_Scroll(object sender, ScrollEventArgs e)
        {

        }

        private void close_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
    class Circle:IDrawable
    {
        int r;
        public Circle()
        {
            r = 100;
        }
        public void draw(Graphics g, Pen p, int x, int y)
        {
            g.DrawEllipse(p, x, y, r, r);
        }
    }  
    class Square:IDrawable
    {
        public void draw(Graphics g, Pen p, int x, int y)
        {
            Point point1 = new Point(x, y);
            Point point2 = new Point(x+100, y);
            Point point3 = new Point(x+100, y+100);
            Point point4 = new Point(x, y+100);
            Point[] squarePoints =
             {
                 point1,
                 point2,
                 point3,
                 point4
             };
            g.DrawPolygon(p,squarePoints);
        }
    }
    class Triangle:IDrawable
    {
        public void draw(Graphics g, Pen p, int x, int y)
        {
            Point point1 = new Point(x, y);
            Point point2 = new Point(x + 150, y);
            Point point3 = new Point(x + 75, y - 120);
            Point[] trianglePoints =
             {
                 point1,
                 point2,
                 point3
             };
            g.DrawPolygon(p, trianglePoints);
        }
    }
    interface IDrawable
    {
        void draw(Graphics g, Pen p, int x, int y);
    }
   
}
