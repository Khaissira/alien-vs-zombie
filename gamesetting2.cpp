#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime> // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;


void displaysettings( int row,int column, int zombies)
{
cout << "Number of columns: " << row << endl;
cout << "Number of rows: " << column << endl;
cout << "Number of zombies: " << zombies << endl;
}
int main()
{
int row = 10, column = 10, zombies = 5;
char letter;

cout << "Default Game Settings" << endl;
cout << "---------------------" << endl;
displaysettings(row, column, zombies);
cout << endl;
cout << " Do you want to change the game settings? (y/n) -> " ;
if (letter == 'y')
{
    cout << endl;
    cout << "Please enter new value for number of rows, columns, and zombies(s)" << endl;
    cout << "Enter number of columns :";
    cin >> row;
    while (row % 2 == 0)
    {
        cout << " Please enter ODD NUMBER for number of columns ->";
        cin >> row;
    }
    cout << " Enter number of rows : ";
    cin >> column;
    while ( column % 2 == 0)
    {
        cout << "Please enter ODD NUMBER for number of rows ->";
        cin >> column;
    }
    cout << "Enter number of zombies :";
    cin >> zombies;
    while (zombies > 10)
    {
        cout << "Please enter values NOT MORE THAN 10 for number of zombies ->";
        cin >> zombies;
    }
     cout << endl;
    cout << "New Game Settings" << endl;
    cout << "---------------------" << endl;
    displaysettings(row, column, zombies);
    // pf::Pause();
    cout << endl;
    // test1_1(column, row);
}
else if (letter == 'n')
{
    cout << "you are not changing the default game settings." << endl;
    // pf::Pause();
    cout << endl;
    // test1_1(rows, col);
}
else
{
    cout << "Please enter either letter 'y' or 'n' only. ";
}
return 0;
}

// can use this one