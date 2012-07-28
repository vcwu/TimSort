#include "timsort.h"
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

	
	//ifstream fin("runs.txt");
	ifstream fin("smallTest.txt");
	//const int size = 29;
	const int size = 25;	//trouble with a million 
	int* hello = new int[size];
	//int hello[size];
	int temp;
	
	int i=0;
	 

	for(int i =0; i < size; i++)
	{
		fin >> temp;
		hello[i] = temp;
	}
	//**/

	int* gallop = new int[505];

	/*
	//Testing Galloping, gallopRight
	
	//Creating an array to look somewhat like
	//0->500 || 100 200 300 400 500
	//in order to force gallopRight to continue
	int num = 100;
	for(int i =0; i < 505; i++)
	{
		
		if(i< 5)
		{
			gallop[i] = num;
			num+=100;
		}
		else
			gallop[i] = i;
	}
	Sort(gallop, 505);
	
	cout << endl 
	<< "PRINTING gallop " << endl << endl;

	
	for( int i =0; i< 505;  i++)
	{
		cout << gallop[i];
		cout << " " ;
		if((i+1)%9 == 0)
			cout << endl;
	}
	//**/

	/*
	//Testing Galloping, gallopLeft
	
	//Creating an array to look somewhat like
	// 500 ->0 || 500 400 300 200 100
	//in order to force gallopLeft to continue
	int num = 500;
	for(int i =0; i < 505; i++)
	{
		
		if(i < 500)
			gallop[i] = 500-i;
		else
		{
			gallop[i] = num;
			num-=100;
		}
	}

	 for( int i =0; i< 505;  i++)
	{
		cout << gallop[i];
		cout << " " ;
		if((i+1)%9 == 0)
			cout << endl;
	}

	Sort(gallop, 505);
	
	cout << endl 
	<< "PRINTING gallop " << endl << endl;

	
	for( int i =0; i< 505;  i++)
	{
		cout << gallop[i];
		cout << " " ;
		if((i+1)%9 == 0)
			cout << endl;
	}
	//**/



	/*
	cout << "Before Sort" << endl << endl;

	for( int i =0; i< size;  i++)
	{
		cout << hello[i];
		cout << " " ;
		if((i+1)%6 == 0)
			cout << endl;
	}
	//**/

	Sort(hello, size);
	
	/*
	cout << endl 
	<< "PRINTING HELLO " << endl << endl;

	
	for( int i =0; i< size;  i++)
	{
		cout << hello[i];
		cout << " " ;
		if((i+1)%6 == 0)
			cout << endl;
	}
	//**/

	//fin.close();
	//delete[] hello;

	int me;
	cin >> me;

	return 0;
}