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
*/
template <typename T>
void insert(stack< pair <int, int> >* cake, int begin, int size);

template <typename T>
void Sort(T data[], int arrSize) 
{


	//Where we stores our runs.
	stack< pair <int, int> >* cake;

	int begin = 0;
	int runSize = arrSize;
	reverseElem(data, begin, runSize);



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
	for(int i = 0; i < size/2; i++)
	{
		T temp = argh[index+i];
		argh[index+i] = argh [end-i];
		argh [end -i] = temp;
	}

};


/*
template <typename T>
void insert(stack< pair <int, int> >* cake, int begin, int size)
{
	
	cake->push(pair(begin, size));
};
*/