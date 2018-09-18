#pragma once
class Stack
{
public:
	Stack();
	~Stack();
	bool isEmpty();
	int Top();
	void Pop();
	void Push(int value);

private:
	int values[20];
	int count;
};