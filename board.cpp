#include <iostream>
#include <iomanip>
#include <vector>
using std::cin;
using std::cout;
using std::setw;
using std::string;
using std::vector;

int getDigits(int n);

class Board
{
private:
	vector< vector<char> > board_;
	int rows_, columns_;

public:
	Board(int rows = 9, int columns = 19);

	void init(int rows, int columns);
	void display();

	int getRows();
	int getColumns();
	int getObject(int column, int row) const;

	void setRows(int new_rows);
	void setColumns(int new_columns);
	void setObject(int column, int row, char new_object);

	bool isEmpty(int row, int column);
	bool isInsideBoard(int row, int column);

	~Board();
};

Board::Board(int rows, int columns)
{
	init(rows, columns);
}

void Board::init(int rows, int columns)
{
	rows_ = rows;
	columns_ = columns;

	char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '^', 'v', '<', '>', 'h', 'p', 'r', 'H'};
	int no_of_objects = sizeof(objects);

	board_.resize(rows_);
	for (int i = 0; i < rows_; ++i)
	{
		board_[i].resize(columns_);
	}

	for (int i = 0; i < rows_; ++i)
	{
		for (int j = 0; j < columns_; ++j)
		{
			int object_no = rand() % no_of_objects;
			board_[i][j] = objects[object_no];
		}
	}
}

void Board::display()
{
	// comment this out during testing
	// system("cls"); // OR system("clear"); for Linux / MacOS

	int offset = getDigits(rows_);

	cout << "\n";
	if (columns_ * 2 > 10)
		for (int i = 0; i < (offset + columns_ - 10); i++)
			cout << " ";
	cout << ".: Alien vs Zombie :."
		 << "\n\n";

	// for each row
	for (int i = 0; i < rows_; ++i)
	{
		// display upper border of the row
		for (int count = 0; count < offset; count++)
			cout << " ";
		for (int j = 0; j < columns_; ++j)
		{
			cout << "+-";
		}
		cout << "+"
			 << "\n";

		// display row number
		cout << setw(offset) << (i + 1);

		// display cell content and border of each column
		for (int j = 0; j < columns_; ++j)
		{
			cout << "|" << board_[i][j];
		}
		cout << "|"
			 << "\n";
	}

	// display lower border of the last row
	for (int count = 0; count < offset; count++)
		cout << " ";
	for (int j = 0; j < columns_; ++j)
	{
		cout << "+-";
	}
	cout << "+"
		 << "\n";

	// display column number
	for (int count = 0; count < offset; count++)
		cout << " ";
	for (int j = 0; j < columns_; ++j)
	{
		int digit = (j + 1) / 10;
		cout << " ";
		if (digit == 0)
			cout << " ";
		else
			cout << digit;
	}
	cout << "\n";
	for (int count = 0; count < offset; count++)
		cout << " ";
	for (int j = 0; j < columns_; ++j)
	{
		cout << " " << (j + 1) % 10;
	}
	cout << "\n"
		 << "\n";
}

int Board::getRows()
{
	return rows_;
}

int Board::getColumns()
{
	return columns_;
}

int Board::getObject(int column, int row) const
{
	return board_[column - 1][row - 1];
}

void Board::setRows(int new_rows)
{
	rows_ = new_rows;
}

void Board::setColumns(int new_columns)
{
	rows_ = new_columns;
}

void Board::setObject(int column, int row, char new_object)
{
	board_[column - 1][row - 1] = new_object;
}

bool Board::isEmpty(int row, int column)
{
	if (board_[row][column] == ' ')
		return true;
	return false;
}

bool Board::isInsideBoard(int row, int column)
{
	if ((row > 0 && row <= rows_) && (column > 0 && column <= columns_))
		return true;
	return false;
}

Board::~Board()
{
}

int main()
{
	Board game;

	game.display();
	return 0;
}