#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

template <typename T,int size>
class Array
{
private :	
	T arr[size];
public:
	 int Size() const { return size; }
	T &operator[](T index) { return arr[index]; }
	T At(T index) { return arr[index]; }
	T& back() { return arr[size-1]; }
	T &front() { return arr[0]; }
	T& operator=(T index) { return arr[index]; }

	T sum(){
		int total = 0;
		for (int i = 0; i < size; i++)
			total += arr[i];
		return total;
	}

	T empty() const {
		if (size == 0)
			return true;
		else
			return false;
	}

	T max(){
		int num = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] > num)
				num = arr[i];
		}
		return num;
	}

};

int main(void)
{
	
	Array<int, 2>variable;
	variable[0]=12;
	variable[1] = 17;
	std::cout << variable[0]<<" ";
	std::cout << variable.At(0)<<" ";
	std::cout << "\nMax: "<<variable.max();

	if (!variable.empty()) {
		std::cout <<"\nTotal:"<< variable.sum() << " ";
	}


		std::cout<<"\nFirst element: "<<variable.front();
		std::cout << "\nLast element: "<<variable.back();

		std::cout << "\nSize: " << variable.Size();
	
	 
}