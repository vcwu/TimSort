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
A record, keeping track of index and length. 
Used in the merging stack to keep track of sorted runs.
*/
struct record
{
	int index, length;
	record(int i = 0, int l= 0) : index(i), length(l) {}
	

};


/**
mergify

Takes two records and merges em. Uses mergeUp and mergeDown.
*/
template <typename T>
record mergify(T data[], record r1, record r2);

/**
happyStack

When the stack is not happy, it must be collapsed until it is happy.
Ensures that we are merging together runs of roughly same size.
The stack is only happy when
1. Len(A) >= Len(B) + Len(C)
2. Len(B) > Len (C)

*/
int happyStack(vector<record>* cake);


/**
Inserts a record onto the stack. 
Automatically handles collapsing the stack.

*/
template <typename T>
void insert(T data[], vector<record>* cake, int begin, int size);




template <typename T>
void Sort(T data[], int arrSize) 
{


	//Where we stores our runs.
	vector<record>* cake = new vector<record>;

	int index1 = 0;
	int size1 = 10;
	int index2 = size1;
	int size2= arrSize-size1;  
	int runSize = arrSize;
	//reverseElem(data, begin, runSize);

	

	/*
	//Testing Mergify

	cout << "Before mergify " << endl;
	for( int i =0; i< arrSize;  i++)
	{
		
		cout << data[i];
		cout << " " ;
	}

	
	//mergify(data, record(index2, size2), record(index1, size1));
	mergify(data, record(index1, size1), record(index2, size2));
	cout<< endl << endl << "after mergify " << endl;
	for( int i =0; i< arrSize;  i++)
	{	
		cout << data[i];
		cout << " " ;
	}
	*/

	/*
	//Testing Insertion sort, Merge up and down

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
	 
	*/


	/*
	Step through array, and process.
	*/

	
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
		
		//making it easy. Chop up into minrun stuff, 
		//put on the vector.
		insertionSort(data, index, minRun);
		insert(data, cake, index, minRun);
		//cake->push_back(record(index, minRun));
		index += minRun;
	}
	
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
	
};

template <typename T>
void mergeUp(T data[], int begin1, int size1, int begin2, int size2)
{
	//Naive merge base taken from 
	//"Data Structures And Algorithms in C++ " by Adam Drozdek
  	// 9.3.4, page 364

	//Hmmm. should i use vector or not?
	T* arr2  = new T[size2];

	for(int i =begin2; i< begin2+size2; i++)
	{
		arr2[i-begin2] = data[i];
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
		for(int i  = i3; i2 >= 0  ; i-- )
		{
			data[i] = arr2[i2--];
		}
	}
	else
		for(int i = i3; i1 >= begin1; i--)
		{
			data[i] = data[i1--];
		}
		
	delete [] arr2; 

	
}

int happyStack(vector<record>* cake)
{
	/*
	Returns an int - 
	0 if stack is happy,
	1 if invariant 1 violated, 
	2 if invariant 2 violated.
	This way, won't have to re check which invariant is violated
	in order to do an appropriate merge.
	*/
	
	int size = cake->size();

	//Sorting complete!
	if (size == 1)
		return 0;
	else if (size == 2)
	{
		if( (*cake)[1].length >= (*cake)[0].length  )
			return 2;
		else
			return 0;
	}
	else
	{
		if(!((*cake)[size-3].length >= 
			(*cake)[size-2].length + (*cake)[size-1].length))
			return 1;
		else if(!((*cake)[size-2].length > (*cake)[size-1].length))
			return 2;
		else
			return 0;
	}
	
}

template <typename T>
void insert(T data[], vector<record>* cake, int begin, int size)
{
	
	cake->push_back(record(begin, size));
	
	//Check the invariants. Collapse stack as long as needed.
	int happy = happyStack(cake);
	while(happy != 0)
	{
		int cakeSize = cake->size();
		// A B C <== top of stack
		record c((*cake)[cakeSize-1]);
		record b((*cake)[cakeSize-2]);
		
		record shiny;
		//First invariant is violated. 
		//B merges with shorter of A and C.
		if(happy == 1)
		{
			record a((*cake)[cakeSize-3]);
			cake->pop_back();
			cake->pop_back();
			if(c.length > a.length)
			{
				cake->pop_back();
				shiny = mergify(data, a, b);	
				//now to fill cake back up, with shiny replacing
				//a and b
				cake->push_back(shiny);
				cake->push_back(c);
			}
			else
			{
				shiny = mergify(data, c, b);
				cake->push_back(shiny);
			}
		}
		else
		{
			cake->pop_back();
			cake->pop_back();
			shiny = mergify(data, c, b);
			cake->push_back(shiny);
		}
		happy = happyStack(cake);
		cout << "Checking happiness..." << endl;
	}
}

template <typename T>
record mergify(T data[], record r1, record r2)
{
	//Depending on whether the shorter run is earlier
	// or later  we'll either merge UP or merge DOWN.

	record ans;
	ans.length = r1.length + r2.length;

	if(r1.index < r2.index)
	{
		ans.index = r1.index;
		if(r1.length <r2.length)
			mergeDown(data, r1.index, r1.length, r2.index, r2.length);
		else
			mergeUp(data, r1.index, r1.length, r2.index, r2.length);
	}
	else if(r2.index < r1.index)
	{
		ans.index = r2.index;
		if(r2.length <r1.length)
			mergeDown(data, r2.index, r2.length, r1.index, r1.length);
		else
			mergeUp(data, r2.index, r2.length, r1.index, r1.length);
	}
	
	return ans;
}
