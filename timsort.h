#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
/*
PRE: Array 'data' is full in at least the first ArrSize 
locations (0 to ArrSize-1, as usual). The data type is comparable, 
with all  six comparison operators (< > <= >= == != ) defined. 
POST: Data array is sorted into ascending (smallest to largest) 
order.
*/



/*
compute_minrun

Minrun is chosen from range 32 to 65, such that
arraySize/minRun <= power of two
*/
int compute_minrun(int size);

/**
reverseElem

Given a beginning index and size, changes a descending run
into an ascending run by swapping elements in place. 
*/
template <class T>
void reverseElem(T argh[], int index, int size);

/**
insertionSort

Uses insertion sort to sort a chunk of the array.
*/

template <typename T>
void insertionSort(T data[], int index, int size);


/**
mergeDown

Merges two chunks of the array together by making a copy
of the earlier chunk and merging into there starting from lo to hi.
Ideally, done in place, and with gallop mode too.
*/
template <typename T>
void mergeDown(T data[], int index1, int size1, int index2, int size2);


/**
mergeUp

Merges two chunks of the array together by making a copy
of the later chunk and merging into there starting from hi to lo.
Basically, a bacwkwards merge.
Ideally, done in place, and with gallop mode too.
*/
template <typename T>
void mergeUp(T data[], int index1, int size1, int index2, int size2);



/**
*/

template <typename T>
void insert(stack< pair <int, int> >* cake, int begin, int size);

template <typename T>
void Sort(T data[], int arrSize) 
{


	//Where we stores our runs.
	stack< pair <int, int> >* cake;

	int index1 = 0;
	int size1 = 3;
	int index2 = size1;
	int size2= arrSize-size1;  
	int runSize = arrSize;
	//reverseElem(data, begin, runSize);


	insertionSort(data, index1, size1);
	cout<< endl << "after insertion sort" << endl;
	for( int i =0; i< arrSize;  i++)
	{
		
		cout << data[i];
		cout << " " ;
	}
	insertionSort(data, index2, size2);

	cout<< endl << "after insertion sort" << endl;
	for( int i =0; i< arrSize;  i++)
	{
		
		cout << data[i];
		cout << " " ;
	}

	mergeUp(data, index1 , size1, index2, size2);

	cout<< endl << "after merging" << endl;
	for( int i =0; i< arrSize;  i++)
	{
		
		cout << data[i];
		cout << " " ;
	}
	cout << endl;

	/*
	Step through array, and process.
	*/

	/*
	enum {NONE, UP, DOWN};
	int minRun = compute_minrun(arrSize);
	int begin;			//Keep track of start of run
	int index = 0;		//Stepping through the array
	int size =0 ;		//Size of the current run
	int order = NONE;
	
	
	//Don't run off edge of array.
	//Keep going as long as there is an ORDERING, or 
	//haven't reached minRun size yet.
	
	while(index < arrSize)
	{
		//let's go for a run! 		
		
		begin = index;
							//find out if ascending or descending 
		
		while(   && (index < arrSize))
		{

		}
	}
	*/



};

int compute_minrun(int size)
{
	//take first 6 bits, if any of other bits are set then
	//adds one

	if(size <64)
		return size;
	return 64;

};

template <class T>
void reverseElem(T argh[], int index, int size)
{
	//Starting from edges, swap inwards.
	int end = index+size-1;
	T temp;
	int i ;
	for(i = 0; i < size/2; i++)
	{
		temp = argh[index+i];
		argh[index+i] = argh [end-i];
		argh [end -i] = temp;
	}

};


template <typename T>
void insertionSort(T data[], int index, int size)
{
	//InsertionSort taken from 
	//"Data Structures And Algorithms in C++ " by Adam Drozdek
	// 9.1.1, page 336

	int i , j;
	T temp;

	for(i =index; i < index+ size; i++)
	{
		temp = data[i];
		j = i;
		while(j > index && temp < data[j-1])
		{
			data [j] = data[j-1];
			j--;
		}
		data[j] = temp;

	}
};

template <typename T>
void mergeDown(T data[], int begin1, int size1, int begin2, int size2)
{
	//Naive merge base taken from 
	//"Data Structures And Algorithms in C++ " by Adam Drozdek
  	// 9.3.4, page 364

	//Make two separate arrays, to make room to write 
	//to original array.

	//Obviously, this is NOT going to work well for 
	//a lot of elements. I'll implement the inplace sort later..

	T* arr1  = new T[size1];

	for(int i =begin1; i< begin1+size1; i++)
	{
		arr1[i-begin1] = data[i];
	}
	

	//T* arr2 = new T[size2];

	int i1 = 0;			//index of first array
	int i2 = begin2;	//index of second array
	int i3 = begin1;	//index we are inserting into

	//Once we reach the end of an array...
	while(i1 < size1 && i2 < begin2+size2)
	{
		if(arr1[i1] < data[i2])
			data[i3++] = arr1[i1++];
		else
			data[i3++] = data[i2++];
	}

	//Load the remaining stuff. 
	if(i1 == size1)		//firstArray is allready in
	{	

		//copy the contents of secondArray
		for(int i = 0; i < i2-begin2; i++ )
		{
			data[i3+i] = data[i2+i];
		}
	}
	
	else
		for(int i =0; i < size1-i1; i++)
		{
			data[i3+i] = arr1[i1+i];
		}
	
	delete [] arr1;
	
}

template <typename T>
void mergeUp(T data[], int begin1, int size1, int begin2, int size2)
{
	//Naive merge base taken from 
	//"Data Structures And Algorithms in C++ " by Adam Drozdek
  	// 9.3.4, page 364

	//Hmmm. should i use vector or not?
	T* arr2  = new T[size2];

	for(int i =begin2; i< begin2+size1; i++)
	{
		arr2[i-begin1] = data[i];
	}

	int i1 = begin1+size1 -1;//end index of first array
	int i2 = size2 -1;	   	//index of second array
	int i3 = begin2+size2 -1;//index we are inserting into

	//Once we reach the end of an array...
	while(i1 >= begin1 && i2 >= 0)
	{
		if(arr2[i2] > data[i1])
			data[i3--] = arr2[i2--];
		else
			data[i3--] = data[i1--];
	}

	//Load the remaining stuff. 
	if(i1 < begin1)		//firstArray is allready in
	{	

		//copy the contents of secondArray
		for(int i  = i3; i2 >= begin2  ; i-- )
		{
			data[i] = arr2[i2--];
		}
	}
	else
		for(int i = i3; i >= size1-i1; i--)
		{
			data[i3+i] = data[i1+i];
		}
		
	delete [] arr2; 

	
}


/*
template <typename T>
void insert(stack< pair <int, int> >* cake, int begin, int size)
{
	
	cake->push(pair(begin, size));
};
*/