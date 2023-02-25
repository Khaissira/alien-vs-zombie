#include <iostream>
using std::cin;
using std::cout;
using std::string;

int getDigits(int n)
{
	int count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return count;
}

void displayHeading(string heading)
{
	cout << "\n"
		 << heading << "\n";
	for (int i = 0; i < heading.length(); i++)
		cout << "-";
	cout << "\n";
}

void displaySettings()
{
}

void displayStats()
{
}

/* Recall that Wee Hean once shared that he deems there need not be
defined a function if the function only consists of one or two lines. */
void displayMessage(string message)
{
	cout << "\n"
		 << message << "\n";
}

void command()
{
}