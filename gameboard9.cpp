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
};
gameboard::gameboard(int row, int column)
{
    init(row, column);
}
void gameboard::init(int row, int column)
{
    row_ = row;
    column_ = column;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'h', 'r', 'p', 'v', '<', '>', '^'};
    int noOfObjects = 13; // number of objects in the objects array
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
    // set the center of the map to 'A'
    map_[column_/2][row_/2] = 'A';
}
void gameboard::display() const
{
     // comment this out during testing
    cout << "                                         " << endl;
    cout << "         .: Alien vs Zombie :.           " << endl;
    cout << "                                         " << endl;
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
    for (int j = 0; j < row_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}
void charattributes() // int r, int c, int z
{
    int z = 3;
    int life[] = {50, 100, 100, 150, 150, 200, 250, 300};
    int numoflife = 8;

    int zombattack[] = {5, 10, 10, 15, 20, 25, 30};
    int numofzombatt = 7;

    int range[] = {1, 2, 3, 4, 5};
    int numofrange = 5;

    cout << "Alien    : Life 100 , Attack " << endl;
    for (int w = 0; w < z; ++w)
    {
        int objlife = rand() % numoflife;
        int objzomatt = rand() % numofzombatt;
        int objrange = rand() % numofrange;
        cout << "Zombie " << w + 1 << " : Life " << life[objlife] << ", Attack " << zombattack[objzomatt] << ", Range " << range[objrange] << endl;
    }
}
void test1_1()
{
    gameboard gameboard;
    gameboard.display();
}
int main()
{
    srand(1); // use this for fixed map during testing
    srand(time(NULL)); // try this for random map
    test1_1();
}
