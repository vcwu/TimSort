/*
Victoria Wu 
CS 352
Summer '12

Implement Timsort.
*/

#include "timsort.h"
#include <iostream>
#include <fstream>
#include "stopwatch.h"
#include "mergeSort.h"

using namespace std;

int main()
{

	string name = "Duplicates.txt";
	//ifstream fin(name);
	ofstream fout("Runs_Output.txt");
	ifstream fin("smallTest.txt");
	//const int size = 10000000;
	const int size = 10;
	//const int size = 200;	//trouble with a million 
	int* hello = new int[size];
	//int hello[size];
	int temp;
	
	int i=0;
	 

	vector <int > data;

	for(int i =0; i < size; i++)
	{
		//fin >> temp;
		hello[i] = 7-(7%(i+1));
		if(i < 100)
			data.push_back(temp);
	}
	//**/
	
	/*
	Stopwatch watch;

	fout << "Sorting ... Increasing!" << endl;
	fout << "===========================" << endl;

	int lower = 100;
	for(int i = 100; i <= 10000000; i*=10)
	{
		cout << "One Run " << i<< endl;
		fout << endl <<"Size: " << i << endl;

		watch.start();
		Sort(hello, i);
		watch.stop();

		double time = watch.get_end_time() - watch.get_init_time();
		fout << "Timsort: " << time << endl;
			
		
		for(int x = lower; x < i ; x ++)
			data.push_back(hello[x]);
		lower = i;

		watch.reset();
		watch.start();
		mergesort(data);
		watch.stop();

		time = watch.get_end_time() - watch.get_init_time();
		fout << "mergesort: " << time << endl;
	}
	
	fout.close();
	cout << "DONE!!! " <<endl;
	int* gallop = new int[505];
	//**/
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
	// 0->500 || 100 200 300 400 500
	//in order to force gallopLeft to continue
	int num = 0;
	for(int i =0; i < 505; i++)
	{
		
		if(i < 500)
			gallop[i] = i;
		else
		{
			gallop[i] = num;
			num+=100;
		}
	}

	/*
	 for( int i =0; i< 505;  i++)
	{
		cout << gallop[i];
		cout << " " ;
		if((i+1)%9 == 0)
			cout << endl;
	}
	*/
	//Sort(gallop, 505);
	/*
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