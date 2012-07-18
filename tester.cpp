#include "timsort.h"
#include <iostream>

using namespace std;

int main()
{

	int hello[] = {5,8,23,4,7, 99, 78,1,21, 15};
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