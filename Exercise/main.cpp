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