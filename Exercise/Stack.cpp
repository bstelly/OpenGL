#include "Stack.h"

Stack::Stack()
{
	for (int i = 0; i < 20; i++)
	{
		values[i] = 0;
	}
	count = 0;
}

Stack::~Stack()
{
	
}

bool Stack::isEmpty()
{
	return count <= 0;
}

int Stack::Top()
{
	return values[count - 1];
}

void Stack::Pop()
{
	if (count != 0)
	{
		values[count - 1] = 0;
		count -= 1;
	}
}

void Stack::Push(int value)
{
	if (count != 20)
	{
		values[count] = value;
		count += 1;
	}
}





