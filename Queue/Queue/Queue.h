#pragma once
#pragma once
#include "stdafx.h"
#include <iostream>

template <class t_data>
class Queue
{
private:

	const int size;		// const int почему
	int head, tail;

public:

	t_data *queuePtr;
	Queue(int = 10);	// конструктор класса
	~Queue();			// деструктор класса

	bool Full();
	void Push(t_data &);
	void Delete(bool all);
	void ShowHeadOrTail(bool position);
	void PrintQueue();
};
template <class t_data>

Queue<t_data>::Queue(int queueSize) :size(queueSize), head(1), tail(1)		// конструктор по умолчанию
{
	queuePtr = new t_data[size];
}
template<typename t_data>			// деструктор класса Queue
Queue<t_data>::~Queue()
{
	delete[] queuePtr;
}
template<typename t_data>
bool Queue<t_data>::Full() //проверка очереди на пустоту
{
	if (tail == head) return true;
	else return false;
}
template <class t_data>
void Queue<t_data>::Push(t_data& newValue)
{
	int a = tail % (size + 1) + 1;
	if (a == head)
	{
		int value;
		std::cout << "Queue is full!press 1 to show head value or 2 to show all values" << "\n";
		std::cin >> value;
		switch (value)
		{
		case(1):
		{
			std::cout << "You chose to show head value" << "\n";
			Delete(true);
			break;
		}
		case(2):
		{
			std::cout << "You chose to show all values" << "\n";
			Delete(false);
			break;
		}
		default:
		{
			std::cout << "Error" << "\n";
			break;
		}
		}


	}


	queuePtr[tail - 1] = newValue;
	tail = tail % (size + 1) + 1;

}
template <class t_data>
void Queue<t_data>::Delete(bool showAll)
{
	bool not = showAll;
	if (not)
	{
		t_data headValue = queuePtr[head++ - 1];
		std::cout << "Deleted pos.num:" << head - 1 << "  = " << headValue << "\n";
		head = head % size;

	}
	else
	{
		for ((head - 1); (head - 1) < (tail - 1); head++)
		{
			t_data headValue = queuePtr[head - 1];
			std::cout << "Deleted pos.num:" << head << "  = " << headValue << "\n";
			head = head % (size + 1);
		}

	}
	head = (head % (size + 1)) + 1;
	tail = (tail % (size + 1)) + 1;
}
template <class t_data>
void Queue<t_data>::ShowHeadOrTail(bool position)
{
	bool pos = position;
	if (pos)
	{
		std::cout << "Head:" << queuePtr[head - 1] << "\n";
	}
	else
	{
		std::cout << "Tail:" << queuePtr[tail - 2] << "\n";
	}
}

template <class t_data>
void Queue<t_data>::PrintQueue()
{
	int i = 0;
	if (head == tail == 1)
	{
		std::cout << " Queue is empty or looped\n";

	}
	else
	{
		int start = head - 1;
		int stop = tail - 1;
		while (start < stop)
		{
			std::cout << queuePtr[start] << " ";
			start++;
		}

		/*for (int i = tail; i >= head; i--)
		{
		std::cout << queuePtr[i] << " ";
		}*/
		std::cout << "\n";
	}
}

