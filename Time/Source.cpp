#include"Time.h"

int main()
{
	Time a(0,58,20);
	
	for (int i = 0; i < 2000; i++)
	{
		system("cls");
		++a;
		a.Print();
		//Sleep(100);
	}
}