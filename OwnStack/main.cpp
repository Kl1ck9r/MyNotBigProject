#include <iostream>
#include <string>

template<typename T>
class Vector
{
public:
	Vector();
	Vector(Vector<T>& vec);
	~Vector();

	void insert(const T& index,const T &variable);
	void reserve(int capacity);
	void push_back(T variable);
	void pop_back();
	T& front();
	T& back();
	int begin();
	int end();
	void clear();

	friend std::ostream& operator<<(std::ostream& oc, const Vector<T>& vec);
	T& operator[](int index);
	int size() { return n_size; }
	int capacity() { return n_capacity; }
	bool empty()const { return size == 0; }

private :
	T* buffer;
	int n_size;
	int n_capacity;
};

template<typename T>
Vector<T>::Vector()
{
	n_size = 0;
	n_capacity = 0;
	buffer = 0;
}

template<typename T>
Vector<T>::Vector(Vector<T>&vec)
{
	n_size = vec.n_size;
	n_capacity = vec.n_capacity;
	buffer = new T[capacity];
	for (int i = 0; i < vec.size(); i++)
		buffer[i] = vec.buffer[i];

}

template<typename T>
T& Vector<T>::operator[](int index)
{
	if (n_size < index)
		throw "Error";
	return buffer[index];
}

template<class T>
void Vector<T>::reserve(int capacity)
{
	if (buffer == 0) {
		n_size = 0;
		n_capacity = 0;
	}

	T* newBuffer = new T[capacity];
	int len = capacity <n_size ? capacity : n_size;
	for (int i = 0; i < len; i++)
		 newBuffer[i]= buffer[i];
	
	delete[]buffer;
	buffer = newBuffer;
}

template<typename T>
void Vector<T>::push_back(T variable)
{
	if (n_size >= n_capacity) // в случае когда исходного размера будет не достаточно  							
		reserve(n_capacity + 10);// reserve выделить новый объем памяти 
	buffer[n_size++] = variable;
}

template<typename T>
void Vector<T>::pop_back()
{
	n_size--;
}

template<typename T>
int Vector<T>::begin()
{
	return *buffer;
}


template<typename T>
int  Vector<T>::end()
{
	 return buffer[n_size];
}

template<typename T>
void Vector<T>::insert(const T& index, const T& variable)
{
	buffer[index] = variable;
	n_size++;
}

template<typename T>
T & Vector<T>::back()
{
	return buffer[n_size - 1];
}

template<typename T>
T& Vector<T>::front()
{
	return buffer[0];
}

template<typename T>
std::ostream& operator<<(std::ostream& oc, const Vector<T>& vec)
{
	for (const auto it : vec) {
		oc << it << "\n";
	}
	return oc;
}

template<typename T>
void Vector<T>::clear()
{
	n_size = 0;
	n_capacity = 0;
	buffer = 0;
}

template<typename T>
Vector<T>::~Vector()
{
	delete[]buffer;
}

int main(void)
{
	try {
		Vector<int> add;

		add.push_back(2);
		std::cout << add[0];
		add.insert(1, 19);

		std::cout << add[0] << " " << add[1] << " ";
		std::cout << add.back() << " ";
		std::cout << add.front() << " ";
		add.pop_back();
		add.pop_back();

		add.insert(3, 5);
		add.insert(2, 1);
		

		std::cout << "\nBegin: " << add.begin();
		std::cout << "\nEnd: " << add.end();
		add.clear();


	}
	catch (...)
	{
		std::cout << "Exception !!! \n";
	}
	
	return 0;
		
}


