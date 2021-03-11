#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

struct DynArray {
	int* data;
	int size;
	int capacity;
};

DynArray Create(int initialCapacity = 2) {
	DynArray da;
	da.capacity = initialCapacity;
	da.size = 0;
	da.data = new int[initialCapacity];
	return da;
}

void Resize(DynArray& da) {
	da.capacity *= 2;
	int* oldData = da.data;
	da.data = new int[da.capacity];
	for (int i = 0; i < da.capacity / 2; i++)
	{
		da.data[i] = oldData[i];
	}
	delete[] oldData;
}

void PushBack(DynArray& da, int element) {
	if (da.size == da.capacity)
	{
		Resize(da);
	}
	da.data[da.size++] = element;
}

void PopBack(DynArray& da) {
	da.size--;
}

void Remove(DynArray& da, int index) {
	assert(index >= 0 && index < da.size);
	for (int i = index; i < da.size - 1; ++i)
	{
		da.data[i] = da.data[i + 1];
	}
	da.size--;
}

int Get(const DynArray& da, int index) {
	assert(index >= 0 && index < da.size);
	return da.data[index];
}

void Print(const DynArray& da) {
	cout << "DynArray: \n";
	cout << "\tsize: " << da.size << endl;
	cout << "\telements: \n";
	for (int i = 0; i < da.size; ++i)
	{
		cout << "\t\t" << Get(da, i) << endl;
	}
}

int main()
{
	DynArray da = Create(5);
	PushBack(da, 2);
	PushBack(da, 3);
	PushBack(da, 4);
	PushBack(da, 22);
	PushBack(da, 3345);
	PushBack(da, 434);
	Print(da);
	Remove(da, 0);
	PopBack(da);
	Print(da);




}
