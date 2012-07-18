#include "timsort.h"
#include <iostream>

using namespace std;

int main()
{

	int hello[] = {99, 98,98,97, 95,1,8,23,4,7 };
	int size = sizeof(hello) / sizeof(int);
	for( int i =0; i< size;  i++)
	{
		cout << hello[i];
		cout << " " ;
	}
	cout << endl;
	Sort(hello, size);
	
	
	
	
	for( int i =0; i< size;  i++)
	{
		cout << hello[i];
		cout << " " ;
	}
	


	int hey;
	cin >> hey;
	return 0;
}