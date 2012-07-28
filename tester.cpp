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

	ifstream fin("runs.txt");
	//ifstream fout("out.txt");
	//ifstream fin("smallTest.txt");
	//const int size = 29;
	const int size = 100000;	//trouble with a million 
	int* hello = new int[size];
	//int hello[size];
	int temp;
	
	int i=0;
	 

	for(int i =0; i < size; i++)
	{
		fin >> temp;
		hello[i] = temp;
	}


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
	
	
	cout << endl 
	<< "PRINTING HELLO " << endl << endl;

	for( int i =0; i< 20;  i++)
	{
		cout << hello[i];
		cout << " " ;
		if((i+1)%6 == 0)
			cout << endl;
	}
	

	//fin.close();
	delete[] hello;

	int me;
	cin >> me;

	return 0;
}