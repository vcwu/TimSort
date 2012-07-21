#include "timsort.h"
#include <iostream>

using namespace std;

int main()
{

	int hello[] = {99, 98,98,97, 95,1,8,23,4,7, 
		21, 5, 987, 12, 555, 15, 
	8, 7586, 23, 235235235, 1, 23, 123, 4, 6};
	int size = sizeof(hello) / sizeof(int);
	
	for( int i =0; i< size;  i++)
	{
		cout << hello[i];
		cout << " " ;
	}
	
	cout << endl;
	Sort(hello, size);
	
	
	cout << endl << endl;
	
	for( int i =0; i< size;  i++)
	{
		cout << hello[i];
		cout << " " ;
	}
	


	int hey;
	cin >> hey;
	return 0;
}