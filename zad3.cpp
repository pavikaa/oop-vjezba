//Napiši klasu „Point2D“ koja ima dva atributa koji predstavljaju koordinate točke u
//dvodimenzionalnom Kartezijevom koordinatnom sustavu, defaultni i
//parametarski konstruktor te pristupne metode.Napiši klasu „Line“ koja
//predstavlja pravac određen s dvije točke, ima parametarski konstruktor i
//pristupne metode te metodu za ispis koja ispisuje točke koje pravac sadrži.U
//glavnoj(main()) funkciji testirati sučelja klasa kreiranjem dvaju točaka,
//instanciranjem pravca pomoću navedenih točaka te ispisom pravca prije i nakon
//promjene točaka.
#include <iostream>
using namespace std;
class Point2D
{
int x, y;
public:
Point2D();
Point2D(int, int);
int getX();
int getY();
};
Point2D::Point2D()
{
								x = 0;
								y = 0;
}
Point2D::Point2D(int x, int y)
{
								this->x = x;
								this->y = y;
}
int Point2D::getX()
{
								return x;
}
int Point2D::getY()
{
								return y;
}
class Line
{
Point2D a, b;
public:
Line();
Line(Point2D, Point2D);
void ispis();
};
Line::Line()
{
								a = Point2D();
								b = Point2D();
}
Line::Line(Point2D a, Point2D b)
{
								this->a = a;
								this->b = b;
}
void Line::ispis()
{
								cout << "Jednadzba pravca glasi: y = " << ((b.getY() - a.getY()) / (b.getX() - a.getX())) << "x + " << (-a.getX() * (b.getY() - a.getY()) / (b.getX() - a.getX())) + a.getY() << endl;
}
int main()
{
								Point2D a, b;
								a = Point2D(1, 5);
								b = Point2D(2, 6);
								Line p = Line();
								p = Line(a, b);
								p.ispis();
								return 0;
}
