#include "timsort.h"
#include <iostream>

using namespace std;

int main()
{

	int hello[] = {5,8,23,4,7, 99};
	int size = sizeof(hello) / sizeof(int);
	for( int i =0; i< size;  i++)
	{
		cout << hello[i];
		cout << " " ;
	}
	cout << endl;
	Sort(hello, 6);
	
	
	
	
	for( int i =0; i< size;  i++)
	{
		cout << hello[i];
		cout << " " ;
	}
	


	int hey;
	cin >> hey;
	return 0;
}