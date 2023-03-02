#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;
// CLASS BOARD
class Board
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int row_, column_;
    int zombierow, zombiecol;
    int alienrow_, aliencol_;           // added variables to store current position of the alien
    int prev_alienrow_, prev_aliencol_; // added variables to store previous position of the alien

public:
    void init(int row, int column, int zombie_row, int zombie_col, int num_zombies);
    void display() const;
    void setObject(int col, int row, char object);
    void moveAlien(int dx, int dy);
};

void Board::setObject(int col, int row, char object)
{
    map_[row][col] = object;
}

// CREATE EMPTY ROWS & RESIZE IT AND PUT RANDOM CHAR INTO THE ARRAY VECTOR
void Board::init(int row, int column, int zombie_row, int zombie_col, int num_zombies)
{
    row_ = row;
    column_ = column;
    zombierow = zombie_row;
    zombiecol = zombie_col;
    char objects[] = {' ', ' ', ' ', 'h', 'r', 'p', '>', '<', '^', 'v'};
    char alien[] = {'A'};
    char zombie[] = {'Z'};
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
    // set the center of the map to 'A'
    map_[column_ / 2][row_ / 2] = 'A';
    alienrow_ = column_ / 2; // initialize current position of the alien
    aliencol_ = row_ / 2;
    prev_alienrow_ = alienrow_; // initialize previous position of the alien
    prev_aliencol_ = aliencol_;

    // randomly place the zombies on the board
    int zombies_placed = 0;
    while (zombies_placed < num_zombies)
    {
        int x = rand() % row_;
        int y = rand() % column_;
        if (map_[y][x] == ' ')
        {
            map_[y][x] = 'Z';
            zombies_placed++;
        }
    }

    // place the zombie on the board
    map_[zombie_row][zombie_col] = 'Z';
}

// DISPLAY BOARD
void Board::display() const
{
    cout << "                                         " << endl;
    cout << "         .: Alien vs Zombie :.           " << endl;
    cout << "                                         " << endl;
    cout << endl;
    // for each row
    for (int i = 0; i < column_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < row_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (i + 1);
        // display cell content and border of each column
        for (int j = 0; j < row_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < row_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << "  ";
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
    cout << "  ";
    for (int j = 0; j < row_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;

         
}
void Board::moveAlien(int dx, int dy)
{
    // Find the current position of the alien
    int x = aliencol_;
    int y = alienrow_;
    int new_x = x + dx;
    int new_y = y + dy;

    // Check if the new position is inside the board and not blocked by a zombie
    if (new_x >= 0 && new_x < row_ && new_y >= 0 && new_y < column_ && map_[new_y][new_x] != 'Z')
    {
        prev_alienrow_ = alienrow_; // store previous position of the alien
        prev_aliencol_ = aliencol_;
        alienrow_ = new_y; // update current position of the alien
        aliencol_ = new_x;
        map_[y][x] = '.';
        map_[alienrow_][aliencol_] = 'A';
    }
}
void charattributes() // declare function with void return type and no parameters
{
    int z = 3;                                            // initialize the number of zombies to generate
    int life[] = {50, 100, 100, 150, 150, 200, 250, 300}; // array of possible life values for zombies
    int numoflife = 8;                                    // the number of possible life values

    int zombiettack[] = {5, 10, 10, 15, 20, 25, 30}; // array of possible attack values for zombies
    int numofzombie = 7;                             // the number of possible attack values

    int range[] = {1, 2, 3, 4, 5}; // array of possible range values for zombies
    int numofrange = 5;            // the number of possible range values

    // print the attributes of the Alien character
    cout << "Alien    : Life 100 , Attack " << endl;

    // generate the attributes for each zombie and print them
    for (int w = 0; w < z; w++)
    {
        int zombie_life = life[rand() % numoflife];
        int zombie_attack = zombiettack[rand() % numofzombie];
        int zombie_range = range[rand() % numofrange];

        cout << "Zombie " << (w + 1) << ": Life " << zombie_life
             << " , Attack " << zombie_attack << " , Range " << zombie_range << endl;
    }
}

// CALLING DISPLAY FUNCTION
void displayBoard(int row, int column, int zombie_row, int zombie_col, int num_zombies)
{
    Board board;
    board.init(row, column, zombie_row, zombie_col, num_zombies);
    board.display();
}

// ACCEPT ODD NUMBERS
void oddNumbers(int &a)
{
    do
    {
        cin >> a;
        if (a & 2 != 0 && a != 1)
        {
            break;
        }
        else
        {
            cout << " Please enter ODD number only except 1! => ";
        }
    } while (a % 2 == 0 || a == 1);
    return;
}

int main()
{
    srand(1);          // use this for fixed map during testing
    srand(time(NULL)); // try this for random map

    int row, column;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> column;

    Board board;
    int zombie_row = rand() % row, zombie_col = rand() % column;
    int num_zombies;
    cout << "Enter the number of zombies to put on the board: ";
    cin >> num_zombies;
    board.init(row, column, zombie_row, zombie_col, num_zombies);
    board.display();

    bool quit = false;
    while (!quit)
    {
        char command;
        cout << "Enter command : ";
        cin >> command;
        switch (command)
        {
        case '^':
            board.moveAlien(0, -1);
            break;
        case '<':
            board.moveAlien(-1, 0);
            break;
        case 'v':
            board.moveAlien(0, 1);
            break;
        case '>':
            board.moveAlien(1, 0);
            break;
        case 'q':
            quit = true;
            break;
        default:
            cout << "Invalid command" << endl;
            break;
        }
        board.display();
    }

    charattributes();

    return 0;
}