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
    vector<vector<char>> map_; // convention to put trailing underscore
    int row_, column_;          // to indicate private data
public:
    gameboard(int row = 19, int column = 3);
    void init(int row, int column);
    void display() const;
    
    int getrow() const;
    int getcolumn() const;

    char getObject(int x, int y) const;

    void setObject(int x, int y, char ch);

    bool isEmpty(int x, int y);
    bool isInsideMap(int x, int y);
};
bool gameboard::isEmpty(int x, int y)
{
    return (map_[column_ - y][x - 1] == ' ');
}
bool gameboard::isInsideMap(int x, int y)
{
    return (x > 0 && x <= row_ && y > 0 && y <= column_);
}
void gameboard::setObject(int x, int y, char ch)
{
    map_[column_ - y][x - 1] = ch;
}
char gameboard::getObject(int x, int y) const
{
  
     return map_[column_- y][(x - 1)];
}
int gameboard::getrow() const
{
    return row_; // row is local variable
}
int gameboard::getcolumn() const
{
    return column_;
}
gameboard::gameboard(int row, int column)
{
    init(row, column);
}
void gameboard::init(int row, int column)
{
    row_ = row;
    column_ = column;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'X', '#', '@', '$'};
    int noOfObjects = 10; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(column_); // create empty rows
    for (int i = 0; i < column_; ++i)
    {
        map_[i].resize(row_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < column_; ++i)
    {
        for (int j = 0; j < row_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}
void gameboard::display() const
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " =       Alien vs Zombie       =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    // for each row
    for (int i = 0; i < column_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < row_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(1) << (column_ - i);
        // display cell content and border of each column
        for (int j = 0; j < row_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << " ";
    for (int j = 0; j < row_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << " ";
    for (int j = 0; j < row_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < row_; ++j) // j= 0,... 14
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}
class Rover
{
private:
    int x_, y_;
    char heading_; // either '^', '>', '<' or 'v'
public:
    Rover();
    void land(gameboard &gameboard);
    int getX() const;
    int getY() const;
    void turnLeft(gameboard &gameboard);
    void turnRight(gameboard &gameboard);
    void move(gameboard &gameboard);
    char getHeading() const;
};
Rover::Rover()
{
}
void Rover::land(gameboard &gameboard)
{
    char possibleHeading[] = {'^', '>', '<', 'v'};
    x_ = rand() % gameboard.getrow() + 1;
    y_ = rand() % gameboard.getcolumn() + 1;
    heading_ = possibleHeading[rand() % 4];
    gameboard.setObject(x_, y_, heading_);
}
int Rover::getX() const
{
    return x_;
}
int Rover::getY() const
{
    return y_;
}
char Rover::getHeading() const
{
    return heading_;
}
void test2_1()
{
    gameboard gameboard;
    Rover curiosity;
    curiosity.land(gameboard);
    gameboard.display();
    cout << "Status of the rover:" << endl
         << " Location: (" << curiosity.getX() << ", " << curiosity.getY() << ")"

         << endl

         << " Heading: " << curiosity.getHeading() << endl;
}
void Rover::turnLeft(gameboard &gameboard)
{
    switch (heading_)
    {
        case '^':
            heading_ = '<';
            break;
        case '>':
            heading_ = '^';
            break;
        case '<':
            heading_ = 'v';
            break;
        case 'v':
            heading_ = '>';
            break;
    }
}
void Rover::turnRight(gameboard &gameboard)
{
    switch (heading_)
    {
        case '^':
            heading_ = '>';
            break;
        case '>':
            heading_ = 'v';
            break;
        case '<':
            heading_ = '^';
            break;
        case 'v':
            heading_ = '<';
            break;
    }
}
void Rover::move(gameboard &gameboard)
{
    switch (heading_)
    {
        case '^':
            if(y_ > 0) //Checking if rover is not going out of the grid
                y_--;
            break;
        case '>':
            if(x_ < gameboard.getrow())
                x_++;
            break;
        case '<':
            if(x_ > 0)
                x_--;
            break;
        case 'v':
            if(y_ < gameboard.getcolumn())
                y_++;
            break;
    }
    gameboard.setObject(x_, y_, heading_);
}

void test2_2()
{
    gameboard gameboard;

    Rover curiosity;

    curiosity.land(gameboard);

    gameboard.display();
    // system("pause");

    curiosity.turnLeft(gameboard);
    gameboard.display();
    // system("pause");

    curiosity.move(gameboard);
    gameboard.display();
    // system("pause");

    curiosity.move(gameboard);
    gameboard.display();
    // system("pause");

    curiosity.turnRight(gameboard);
    gameboard.display();
    // system("pause");

    curiosity.move(gameboard);
    gameboard.display();
}
void test2_3()
{
    gameboard gameboard;
    gameboard.display();
    int x, y;
    char obj;
    x = 2;
    y = 10;
    obj = gameboard.getObject(x, y);
    cout << "Object at column " << x << " and row " << y << " is ["
         << obj << "]" << endl;
}
int main()
{
    srand(1); // use this for fixed map during testing
    // srand(time(NULL)); // try this for random map
    // test1_1();
    // test1_3();
    // test1_4();
    // test1_5();
    // test1_6();
    // test2_1();
    // test2_2();
    test2_3();
}
