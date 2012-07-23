//#include "timsort.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	/*
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
	
	*/

	ifstream fin("C:\\Users\\vptarmigan\\Downloads\\runs\\random.txt");
	//ifstream fin("random.txt");
	const int size = 10;
	int hello[size];
	int temp;
	
	int i=0;
	 

	
	for( int i =0; i< size;  i++)
	{
		cout << hello[i];
		cout << " " ;
		if((i+1)%6 == 0)
			cout << endl;
	}
	

	//Sort(hello, size);
	
	for( int i =0; i< size;  i++)
	{
		cout << hello[i];
		cout << " " ;
		if((i+1)%6 == 0)
			cout << endl;
	}
	

	fin.close();


	int hey;
	cin >> hey;
	return 0;
}