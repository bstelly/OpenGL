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

struct Cat
{
	char m_Name;
	int m_Age;
	void Name(char name)
	{
		m_Name = name;
	}
};

int main()
{
	Cat cats[26];
	int current = 97;
	int count = 0;
	while (count != 26)
	{
		if(count % 2)
		{
			cats[count].Name(current - 32);
		}
		else
		{
			cats[count].Name(current);
		}
		count += 1;
		current += 1;
	}
}