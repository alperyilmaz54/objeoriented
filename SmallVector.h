//ALPER YILMAZ
//150160702
#ifndef SMALL_VECTOR
#define SMALL_VECTOR

class SmallVector {

	int bufferStatic[32];				// 
	int* bufferDynamic;
	int count=0,j = 0; // for buffers
public:
	SmallVector();
	SmallVector(int*, int);
	SmallVector(const SmallVector&); //Copy Constructer
	int& operator[](int);
	int pop_back();
	void push_back(int); 
	void push_back(const int*, int);
	int getSize() const;
	int &operator[](int)const;
	SmallVector operator+(const SmallVector &c) const;
	//~SmallVector();
	SmallVector reverse();
	SmallVector operator*(int);
	int operator=(int);


};
SmallVector::SmallVector(int *temp, int num)   // Constructer  for SmallVector which has arguments
{

	if (num>32)
		bufferDynamic = new int[num - 32];

	for (int x = 0; x < num; x++)
	{
		push_back(temp[x]);

	}

}

void SmallVector::push_back(int data){  // I push the all items to buffers' last element

	if (count<32)
	{
		bufferStatic[count] = data;

	}
	else
	{

		bufferDynamic[j] = data;
		j++;
	}
	count++;
}
void SmallVector::push_back(const int*temp, int size)  //This is for push a couple of element
{
	if (count + size <= 32)
	{
		for (int i = 0; i < size; i++)
		{
			bufferStatic[count + i] = temp[i];

		}
		count = count + size;
	}
	else
	{
		for (int j = 0; j < size; j++)
		{
			bufferDynamic[count + j] = temp[j];

		}
		count = count + size;
	}

}


int SmallVector::pop_back()       // Delete the last element of array
{
	if (count <= 32)
	{
		return bufferStatic[count];

		bufferStatic[count] = 0;
		count--;
	}
	if (count > 32)
	{
		return bufferDynamic[count - 32];
		bufferDynamic[count - 32] = 0;
		count--;
	}
	}
int& SmallVector::operator[](int x)     // Overloading Subscirpt operator
{ 
	
	int *dizi;
	dizi = new int[count];
	if (count <= 32)
	{
		for (int k = 0; k < count; k++)
			dizi[k] = bufferStatic[k];
	}
	else
	{
		for (int k = 0; k < 32; k++)
			dizi[k] = bufferStatic[k];
		for (int m = 32; m < count; m++)
			dizi[m] = bufferDynamic[m - 32];
	}

	if (x >= 0 &&x>=32)
		return bufferDynamic[x-32];

	if (x >= 0 && x<32)
		return bufferStatic[x];
	
	else
		return dizi[count + x];
		
	}
	


SmallVector SmallVector:: operator*(int a)		 //Overloading the * operator for Replicate the array
{
	const int size = count;
	int *dizi,*dizi2;
	const int* tempArr;
	dizi = new int[count];
	tempArr = new int[size];
	
	
	if (count <= 32)
	{
		for (int k = 0; k < count; k++)
			dizi[k] = bufferStatic[k];
	}
	else
	{
		for (int k = 0; k < 32; k++)
			dizi[k] = bufferStatic[k];
		for (int m = 32; m < count; m++)
			dizi[m] = bufferDynamic[m - 32];
	}
tempArr = dizi;


	if (count>32)
	bufferDynamic = new int[a];

	for (int i = 1; i < a; i++)
	{
		push_back(tempArr,size);
	}
	dizi2 = new int[count];
	if (count <= 32)
	{
		for (int k = 0; k < count; k++)
			dizi2[k] = bufferStatic[k];
	}
	else
	{
		for (int k = 0; k < 32; k++)
			dizi2[k] = bufferStatic[k];
		for (int m = 32; m < count; m++)
			dizi2[m] = bufferDynamic[m - 32];
	}

	
	return SmallVector(dizi2,count);
}

SmallVector::SmallVector(const SmallVector &copyObj)   // Copy Constructer	
{
	count = copyObj.count;
	if (count<=32)
	for (int i = 0; i < count;i++)
	{
		bufferStatic[i] = copyObj.bufferStatic[i];
	
	}
	else {

		bufferDynamic = new int[count-32];
		for (int i = 0; i < 32; i++)
		{
			bufferStatic[i] = copyObj.bufferStatic[i];

		}
		for (int j = 32; j < count; j++)
		{
			bufferDynamic[j-32] = copyObj.bufferDynamic[j-32];
		}
	}

}

SmallVector SmallVector::operator+(const SmallVector &c) const   // Addition of two SmallVector
{
	int *tempDizi;
	
	tempDizi = new int[count];
	if (count <= 32)
	{
		for (int k = 0; k < count; k++)
			tempDizi[k] = bufferStatic[k];
	}
	else
	{
		for (int k = 0; k < 32; k++)
			tempDizi[k] = bufferStatic[k];
		for (int m = 32; m < count; m++)
			tempDizi[m] = bufferDynamic[m - 32];
	}

	int *cDizi;

	cDizi = new int[c.count];
	if (c.count <= 32)
	{
		for (int k = 0; k < c.count; k++)
			cDizi[k] = c.bufferStatic[k];
	}
	else
	{
		for (int k = 0; k < 32; k++)
			cDizi[k] = c.bufferStatic[k];
		for (int m = 32; m < count; m++)
			cDizi[m] = c.bufferDynamic[m - 32];
	}
	int *totalDizi;
	totalDizi = new int[count + c.count];
	for (int i = 0; i < count; i++)
		totalDizi[i] = tempDizi[i];
	for (int j = count; j < count + c.count; j++)
		totalDizi[j] = cDizi[j - count];

	return SmallVector(totalDizi, count + c.count);
}

SmallVector SmallVector::reverse(){   // Reversing of  SmallVector
	int *tempDizi;
	int temp;
	tempDizi = new int[count];
	if (count <= 32)
	{
		for (int k = 0; k < count; k++)
			tempDizi[k] = bufferStatic[k];
	}
	else
	{
		for (int k = 0; k < 32; k++)
			tempDizi[k] = bufferStatic[k];
		for (int m = 32; m < count; m++)
			tempDizi[m] = bufferDynamic[m - 32];
	}

	for (int i = 0; i < count / 2; i++)  
	{
		int temp = tempDizi[i];
		tempDizi[i] = tempDizi[count - i - 1];
		tempDizi[count - i - 1] = temp;
	}

	return SmallVector(tempDizi, count);
}

int SmallVector::getSize()const{			// Number of element
	return count;
}


SmallVector::SmallVector()			//Constructer an empty vector
{
	for (int i = 0; i < 32; i++)
		bufferStatic[i] = 0;

}



int &SmallVector::operator[](int index) const    // Overloading of [] operator for print function
{
	int *dizi;
	dizi = new int[count];
	if (count <= 32)
	{
		for (int k = 0; k < count; k++)
			dizi[k] = bufferStatic[k];
	}
	else
	{
		for (int k = 0; k < 32; k++)
			dizi[k] = bufferStatic[k];
		for (int m = 32; m < count; m++)
			dizi[m] = bufferDynamic[m - 32];
	}

	if (index >= 0)
		return dizi[index];
	else
		return dizi[count + index];
}
int SmallVector::operator=(int x)  // Overloading of  Assignment operator
{
	return x;
}

#endif SMALL_VECTOR