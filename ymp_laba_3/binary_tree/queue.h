#pragma once
#include <iostream>
#include "Tree.h"
#include "pair.h"

using QInfo = Pair;

class queue
{
private:
	static const int maxCount = 100;
	QInfo elements[maxCount];
	int first, last;
public:
	queue();
	bool empty();
	bool full();
	void push(QInfo elem);
	QInfo pop();
};

queue::queue(): first(0), last(-1) {}

bool queue::empty()
{
	return last == -1;
}

bool queue::full()
{
	return last - first == maxCount - 1;
}

void queue::push(QInfo elem)
{
	// очередь у правого края - сдвиг влево
	if (last == maxCount - 1)
	{
		for (int i = first; i <= last; ++i)
			elements[i - first] = elements[i];
		last = last - first;
		first = 0;
	}
	elements[++last] = elem;
}
QInfo queue::pop()
{
	QInfo elem = elements[first];
	if (first == last)
	{
		first = 0;
		last = -1;
	}
	else
		++first;
	return elem;
}