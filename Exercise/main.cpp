void ReverseArray(int array1[], int array2[], int size)
{
	int count = size - 1;
	for (int i = 0; i <= size; i++)
	{
		array2[i] = array1[count];
		count -= 1;
	}
}



int main()
{
	int myArray[] ={ 1, 2, 3, 4 };
	int reversedArray[4];
	ReverseArray(myArray, reversedArray, sizeof(myArray)/sizeof(int));
	
}
