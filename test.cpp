#include <iostream>
#include <iomanip>

/* 
int Pause()
{
#if defined(_WIN32)
	return std::system("pause");
#elif defined(__linux__) || defined(__APPLE__)
	return std::system(R"(read -p "Press any key to continue . . . " dummy)");
	// return 0;
#endif
}
*/

void displayHeading(std::string heading)
{
	std::cout << heading << "\n";
	for (int i = 0; i < heading.size(); i++)
		std::cout << '-';
	std::cout << "\n";
}

class Settings
{
	int totalRow_, totalColumn_, totalZombie_;

public:
	Settings(int totalRow = 5, int totalColumn = 9, int totalZombie = 1);
	void init(int totalRow, int totalColumn, int totalZombie);

	int getTotalRow() const;
	int getTotalColumn() const;
	int getTotalZombie() const;

	void setTotalRow(int n);
	void setTotalColumn(int n);
	void setTotalZombie(int n);
	
	void display();

	int inputChange();
	void change();
};

Settings::Settings(int totalRow, int totalColumn, int totalZombie)
{
	init(totalRow, totalColumn, totalZombie);
}

void Settings::init(int totalRow, int totalColumn, int totalZombie)
{
	totalRow_ = totalRow;
	totalColumn_ = totalColumn;
	totalZombie_ = totalZombie;
}

int Settings::getTotalRow() const
{
	return totalRow_;
}

int Settings::getTotalColumn() const
{
	return totalColumn_;
}

int Settings::getTotalZombie() const
{
	return totalZombie_;
}

void Settings::setTotalRow(int n)
{
	totalRow_ = n;
}

void Settings::setTotalColumn(int n)
{
	totalColumn_ = n;
}

void Settings::setTotalZombie(int n)
{
	totalZombie_ = n;
}

int Settings::inputChange()
{
	char c;
	std::cout << "Do you wish to change the game settings (y/n)? => ";
	std::cin >> c;
	if (c == 'n')
		return 0;
	else if (c == 'y')
	{
		change();
		return 1;
	}
	else
	{
		std::cout << "\nPlease enter 'y' or 'n'\n";
		inputChange();
		return 0;
	}
}

void Settings::change()
{
	int row, column, zombie;

	displayHeading("Board Settings");
	
	std::cout << "Enter number of rows => ";
	std::cin >> row;
	setTotalRow(row);
	std::cout << "Enter number of columns => ";
	std::cin >> column;
	setTotalColumn(column);
	std::cout << "Enter number of zombies => ";
	std::cin >> zombie;
	setTotalZombie(zombie);
	std::cout << "\nSettings updated.\n";
}

void Settings::display()
{
	displayHeading("Game Settings");
	
	std::cout << std::left << std::setw(20) << "Number of rows" << " : " << std::right <<std::setw(5) << getTotalRow() << "\n";
	std::cout << std::left << std::setw(20) << "Number of columns" << " : " << std::right <<std::setw(5) << getTotalColumn() << "\n";
	std::cout << std::left << std::setw(20) << "Number of zombies" << " : " << std::right <<std::setw(5) << getTotalZombie() << "\n";
	inputChange();
	// Pause();
}

int main()
{
	Settings test;
	test.display();
}