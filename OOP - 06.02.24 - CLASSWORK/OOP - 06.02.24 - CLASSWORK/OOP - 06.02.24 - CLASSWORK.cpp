#include <iostream>
#include <ctime>
using namespace std;

class ArrayList // Vector
{
	unsigned int size = 0; // количество действительно присутствующих элементов в контейнере
	unsigned int capacity = 10; // ёмкость (вместительность, запас памяти)
	int* data = nullptr; // указатель на динамический массив целых чисел

public:

	ArrayList(const ArrayList& original)
	{
		this->size = original.size;
		this->capacity = original.capacity;
		this->data = new int[original.size];

		for (int i = 0; i < size; i++)
		{
			this->data[i] = original.data[i];
		}
	}

	ArrayList() : ArrayList(10)
	{
		// cout << "C-TOR WITHOUT PARAMS!\n";
	}

	ArrayList(unsigned int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new int[capacity];
		// cout << "C-TOR WITH PARAMS!\n";
	}

	~ArrayList()
	{
		// cout << "DESTRUCTOR!\n";
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	void PushBack(int value)
	{
		EnsureCapacity(); // проверка, хватит ли места для нового элемента
		data[size] = value;
		size++;
	}

	void PushFront(int value)
	{
		EnsureCapacity();
		for (int i = size; i > 0; i--) // i = 1
		{
			data[i] = data[i - 1]; // data[1] = data[0]
		}
		data[0] = value;
		size++;
	}

	void EnsureCapacity()
	{
		if (size < capacity)return;

		int* temp = new int[size * 2];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[]data;
		data = temp;

		capacity *= 2;
	}


	void Clear()
	{
		size = 0;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Print() const
	{
		if (IsEmpty())
		{
			cout << "Vector is empty.\n";
			return;
		}

		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
	}

	// ...остальные методы...

	void SetCapacity(unsigned int capacity)
	{
		this-> capacity = capacity;
	}
	unsigned int GetCapacity()
	{
		return capacity;
	}

	unsigned int GetSize()
	{
		return size;
	}

	void RemoveAt(unsigned short index)
	{
		if (index >= size)
		{
			cout << "Index out of bounds\n";
			return;
		}
		int* temp = new int[size - 1];
		for (int i = 0, j = 0; i < size; i++)
		{
			if (i != index)
			{
				temp[j++] = data[i];
			}
		}
		delete[] data;
		size--;
		data = temp;
	}

	void PopFront()
	{
		if (size == 0)
		{
			cout << "Vector is empty.\n";
			return;
		}

		for (int i = 0; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}
		size--;
	}

	void PopBack()
	{
		if (size == 0)
		{
			cout << "Vector is empty.\n";
			return;
		}
		size--;
	}

	void RandomFill(int size)
	{
		EnsureCapacity(); 
		for (int i = 0; i < size; i++)
		{
			data[i] = rand() % 12;
		}
		this->size = size;
	}

	void Insert(int index, int value)//index - индекс куда вставить значение, value - непорсредственно наше значение
	{
		if (index < 0 || index > size)
		{
			cout << "Invalid index\n";
			return;
		}
		EnsureCapacity();

		for (int i = size; i > index; i--)
		{
			data[i] = data[i - 1];
		}
		data[index] = value;
		size++;
	}


};

unsigned int operator == (ArrayList& a, ArrayList& b)
{
	return a.GetSize() == b.GetSize();
}

ostream& operator << (const ostream& i, ArrayList& d)
{
	d.Print();
	return cout;
}

istream& operator >> (istream& is, ArrayList& arr)
{
	cout << "Enter array: ";
	int answear;
	cin >> answear;
	arr.PushFront(answear);
	return cin;
}
int main()
{
	srand(time(NULL));

	ArrayList ar;
	//ar.Print();

	//ar.PushBack(1);
	//ar.PushBack(2);
	//ar.PushBack(3);
	//ar.PushBack(4);
	//ar.PushBack(5);
	//ar.PushBack(6);
	//ar.PushBack(7);
	//ar.PushBack(8);
	//ar.PushBack(9);
	//ar.PushBack(10);
	//ar.PushBack(11);
	//ar.Print();
	//ar.RemoveAt(5);
	//ar.Print();

	//ar.PushFront(1);
	//ar.PushFront(2);
	//ar.PushFront(3);
	//ar.PushFront(4);
	//ar.PushFront(5);
	//ar.PushFront(6);
	//ar.PushFront(7);
	//ar.PushFront(8);
	//ar.PushFront(9);
	//ar.PushFront(10);
	//ar.PushFront(11);
	////ar.RandomFill(11);
	////ar.Insert(2, 12);
	//

	////ArrayList copy;
	////copy = ar;
	////copy.Print();
	//ArrayList arr;
	//arr.PushFront(1);
	//arr.PushFront(2);
	//arr.PushFront(3);
	//arr.PushFront(4);
	//arr.PushFront(5);
	//arr.PushFront(6);
	//arr.PushFront(7);
	//arr.PushFront(8);
	//arr.PushFront(9);
	//arr.PushFront(10);
	//arr.PushFront(11);

	////if (arr == ar)
	////{
	////	cout << "==";
	////}

	//ar.PushBack(1);
	//ar.PushBack(12);

	////
	////ar.Print();
	//cin >> ar;
	//cout << ar;

}