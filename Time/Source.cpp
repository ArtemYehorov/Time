#include"Time.h"

int main()
{
	Time a;
	Time b;
	if (a > b)
	{
		cout << "Yeeees!\n";
	}
	else
	{
		cout << "Noooo((!\n";
	}

	a = a + 75600;

	b.Print();
	cout << "\n";
	a.Print();

	cin >> a >> b;
	cout << a << "\n" << b;
}