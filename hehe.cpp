#include <iostream>
using std::cout;

int no_of_digits(int n)
{
	int count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return count;
}

int main()
{
	int a;
	a = no_of_digits(12189);
	cout << a << "\n";
}