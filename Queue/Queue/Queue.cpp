// Queue ver_3_Линейные списки.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Queue.h"



int main()
{
	int length = 10;
	int value;
	Queue<int> myQueue(10);
	myQueue.PrintQueue();
	int i = 0;
	while (i++<length + 1)
	{
		std::cin >> value;
		myQueue.Push(value);
	}
	myQueue.PrintQueue();

	std::cout << "\n";
	myQueue.ShowHeadOrTail(true);
	myQueue.ShowHeadOrTail(false);
	std::cout << " \n";



	return 0;
}

