//void ReverseArray(int array1[], int array2[], int size)
//{
//	int count = size - 1;
//	for (int i = 0; i <= size; i++)
//	{
//		array2[i] = array1[count];
//		count -= 1;
//	}
//}
//
//
//
//int main()
//{
//	int myArray[] ={ 1, 2, 3, 4 };
//	int reversedArray[4];
//	ReverseArray(myArray, reversedArray, sizeof(myArray)/sizeof(int));
//	
//}
//=====================================================================

//struct Cat
//{
//	char m_Name;
//	int m_Age;
//	void Name(char name)
//	{
//		m_Name = name;
//	}
//};
//
//int main()
//{
//	Cat cats[26];
//	int current = 97;
//	int count = 0;
//	while (count != 26)
//	{
//		if(count % 2)
//		{
//			cats[count].Name(current - 32);
//		}
//		else
//		{
//			cats[count].Name(current);
//		}
//		count += 1;
//		current += 1;
//	}
//}

//#include "Stack.h"
//#include <winerror.h>
//
//int main()
//{
//	Stack stack = Stack();
//	stack.isEmpty();
//
//	stack.Push(3);
//	stack.isEmpty();
//	stack.Push(5);
//	stack.Push(10);
//
//	stack.Pop();
//
//	int num = stack.Top();
//
//
//	Stack stackTwo = Stack();
//	for (int i = 0; i < 30; i++)
//	{
//		stackTwo.Push(i);
//	}
//}

//class MyClass
//{
//public:
//	const char * pointer;
//	void Method(const char * arg)
//	{
//		pointer = arg;
//	}
//};
//
//int main()
//{
//	const char * line = "Hello";
//	MyClass a = MyClass();
//	a.pointer = "Bye";
//	a.Method(line);
//	const char * ans = a.pointer;
//}

//#include <iostream>
////You are to create a class that contains a method
////and one const char* the method takes as an argument a const char*
////this method assigns its' argument to the classes member variable
////Explain what is wrong with this and fix it.
//
//class ConstMethod
//{
//private:
//	//Name:: variable
//	//Type:: const char*
//	//Description::
//	const char* dest;
//public:
//	ConstMethod();
//
//	void theMethod(const char*);
//
//};
//
//ConstMethod::ConstMethod()
//{
//
//}
//
////Name:: theMethod
////Return Type:: void
////Arguments::an unchanging pointer to an address in memory containing char type
//void ConstMethod::theMethod(const char* cptr)
//{
//	std::string src;
//	FILE* stream;
//	errno_t error = fopen_s(&stream, cptr, "r");
//	char buf[500];
//	while (std::fgets(buf, 500, stream))
//		src.append(buf);
//	const char* tmp = src.c_str();
//	memcpy(&dest, &tmp, 500);
//
//}
//
//int main()
//{
//	ConstMethod *test = new ConstMethod();
//	const char* var = "data.muh";
//	test->theMethod(var);
//}

////Summation Notation
//int Sigma(int n, int i)
//{
//	int result = 0;
//	for (int iter = i; iter <= n; iter++)
//	{
//		result += i * i;
//	}
//	return result;
//}
//
//int main()
//{
//	int answer = Sigma(5, 2);
//}

//#include "Number.h"
//
//int main()
//{
//	Number ten = Number(10);
//	ten.Add(50);
//
//}

//#include "Human.h"
//#include "Dog.h"
//// 1. What is polymorphism?
//// -Polymorphism is when an object can take different forms/types.
//
//int main()
//{
//	Entity* person;
//	Human* person = new Human("Human");
//	Dog dog = Dog("Dog");
//
//	dog = person->Polymorph();
//}

//void MultiplyArray(int inputArray[], int size, int outputArray[])
//{
//	for (int i = 0; i < size; i++)
//	{
//		outputArray[i] = inputArray[i] * i;
//	}
//}
//
//int main()
//{
//	int arrayOne[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int arrayTwo[10];
//	MultiplyArray(arrayOne, 10, arrayTwo);
//}

#include <vector>
#include <iostream>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

	//find the hourglasses
	vector<vector<int>> hourglasses(16);
	vector<int> hourglass(7);
	int row = 0;
	int col = 0;

	for (int i = 0; i < hourglasses.size(); i++)
	{
		hourglass[0] = arr[row][col];
		hourglass[1] = arr[row][col + 1];
		hourglass[2] = arr[row][col + 2];
		hourglass[3] = arr[row + 1][col + 1];
		hourglass[4] = arr[row + 2][col];
		hourglass[5] = arr[row + 2][col + 1];
		hourglass[6] = arr[row + 2][col + 2];

		hourglasses[i] = hourglass;
		
		if (col == 3)
		{
			row += 1;
			col = 0;
		}
		else
		{
			col += 1;
		}

	}

	int largestSum = -99999;
	int largestSumIndex = 0;
	int result;
	for (int i = 0; i < hourglasses.size(); i++)
	{
		result = 0;
		for (int j = 0; j < hourglasses[i].size(); j++)
		{
			result += hourglasses[i][j];
		}
		if (result >= largestSum)
		{
			largestSum = result;
			largestSumIndex = i;
		}
	}
	return largestSum;
}

int main()
{
	vector<vector<int>> arr = {
		{ -1, -1, 0, -9, -2, -2},
		{-2, -1, -6, -8, -2, -5},
		{-1, -1, -1, -2, -3, -4},
		{-1, -9, -2, -4, -4, -5},
		{-7, -3, -3, -2, -9, -9},
		{-1, -3, -1, -2, -4, -5} };

	int result = hourglassSum(arr);

	cout << result << "\n";
	return 0;
}