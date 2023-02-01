// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT6L
// Names: DIVYASHREE A/P SELVANYGAM | NOR KHAISSIRA BINTI KHAIRUDDIN | NABILA NADIA BINTI MD ZAID
// IDs: 1221303777 | 1221304058 | 1221303636
// Emails: 1221303777@student.mmu.edu.my | 1221304058@student.mmu.edu.my | 1221303636@student.mmu.edu.my
// Phones: 010-2342132 | 012-3342105 | 019-9120610
// *********************************************************


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()

using namespace std;

class gameboard
{
private:
vector< vector<char> > map_; // convention to put trailing underscore
int dimX_, dimY_; // to indicate private data
public:
gameboard(int dimX = 3, int dimY = 19);
void init(int dimX, int dimY);
void display() const;
int getDimX();
int getDimY();
};

int gameboard::getDimX() const
{
return dimX_;
}
int gameboard::getDimY() const
{
return dimY_;
}
void test1_3()
{
gameboard;
// gameboard.display();
cout << "Dim X = " << gameboard.getDimX() << endl;
cout << "Dim Y = " << gameboard.getDimY() << endl;
}
int main()
{
srand(1); // use this for fixed map during testing
// srand(time(NULL)); // try this for random map
// test1_1();
test1_3();
}



class gameobjects
{
private:
vector< vector<char> > map_; // convention to put trailing underscore
int dimX_, dimY_; // to indicate private data
public:
gameobjects(int dimX = 3, int dimY = 19);
void init(int dimX, int dimY);
void display() const;
int getDimX const;
int getDimY const;
char getObject(int x, int y) const;
void setObject(int x, int y)
};
void gameobjects::setObject(int x, int y, char ch )
{
map_[ ][ ] = ch;
}
void test1_5()
{
gameobjects;
int x1 = 3, y1 = 4; char ch1 = 'n1';
int x2 = 1, y2 = 6; char ch2 = 'n2';
int x3 = 2, y3 = 14; char ch3 = 'n3';
int x4 = 3, y4 = 17; char ch4 = 'n4';
int x5 = 1, y5 = 18; char ch5 = 'n5';
int x6 = 2, y6 = 10; char ch6 = 'a'
int x7 = 2, y7 = 2; char ch7 = 'r1'
int x8 = 1, y8 = 11; char ch8 = 'r2'
int x9 = 3, y9 = 11; char ch9 = 'r3'
int x10 = 2, y10 = 18; char ch10 = 'r4' 
int x11 = 3, y11 = 11; char ch11 = 'o'

Zombie.setObject(x1, y1, ch1);
Zombie.setObject(x1, y1, ch2);
Zombie.setObject(x3, y3, ch3);
Zombie.setObject(x4, y4, ch4);
Zombie.setObject(x5, y5, ch5);
Alien.setObject(x6, y6, ch6);
Rock.setObject(x7, y7, ch7)
Rock.setObject(x8, y8, ch8)
Rock.setobject(x9, y9, ch9)
Rock.setobject(x10, y10, ch10)
HiddenObject.setobject(x11, y11, ch11)


gameobjects.display();

cout << "The object " << ch1 << " is at column "
<< x << " and row " << y << endl;
cout << "The object " << ch2 << " is at column "
<< x2 << " and row " << y2 << endl;
cout << "The object " << ch3 << " is at column "
<< x3 << " and row " << y3 << endl;
cout << "The object " << ch4 << " is at column "
<< x4 << " and row " << y4 << endl;
cout << "The object " << ch5 << " is at column "
<< x5 << " and row " << y5 << endl;
cout << "The object " << ch6 << " is at column "
<< x6 << " and row " << y6 << endl;
cout << "The object " << ch7 << " is at column "
<< x7 << " and row " << y7 << endl;
cout << "The object " << ch8 << " is at column "
<< x8 << " and row " << y8 << endl;
cout << "The object " << ch9 << " is at column "
<< x9 << " and row " << y9 << endl;
cout << "The object " << ch10 << " is at column "
<< x10 << " and row " << y10 << endl;
cout << "The object " << ch11 << " is at column "
<< x11 << " and row " << y11 << endl;


}
int main()
{
srand(1); // use this for fixed map during testing
// srand(time(NULL)); // try this for random map
// test1_1();
// test1_3();
// test1_5();
test1_5();
}