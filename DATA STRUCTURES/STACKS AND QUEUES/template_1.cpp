#include <iostream>
#include "template_1_class.cpp"
using namespace std;
 
int main()
{
    Pair<int,int> p1;
    p1.setX(10);
    p1.setY(20);

    cout << p1.getX() << " " << p1.getY() << endl;

    //creating object in objext

   Pair<Pair<int,int>,int> p2;
   p2.setY(30);
   p2.setX(p1);
   cout << p2.getX().getX() << " " << p2.getX().getY() << " " << p2.getY() << endl;

   cout << endl;

   Pair<int,char> p3;
   p3.setX(40);
   p3.setY('c');

   Pair<Pair<int,char>,double> p4;
   p4.setY(7.7);
   p4.setX(p3);
   cout << p4.getX().getX() << " " << p4.getX().getY() << " " << p4.getY() << endl;
    
}
