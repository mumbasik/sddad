#include <iostream>
using namespace std;
class Point
{
	int x;
	int y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Point& operator+=(const Point& obj) {
		this->x += obj.x;
		this->y += obj.y;
		return *this;

	}

	Point& operator=(const int obj)
	{
		this->x = obj;
		y = obj;
		return *this;
	}


	int GetX() { return x; }
	int GetY() { return y; }

	friend ostream& operator<<(ostream& os, const Point& X);

};
template<typename T>
class DynArray
{
	T* arr;
	int size;
public:
	DynArray(int sizeP)
		: arr{ new T[sizeP] }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}
	DynArray() : DynArray(5) {}
	DynArray(const DynArray& object)
		: arr{ new T[object.size] }, size{ object.size }
	{
		std::cout << "DynArr copy constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}
	T getElem(int idx) { return arr[idx]; }
	void setElem(int idx, T val) { arr[idx] = val; }
	void print();
	void randomize();
	void summa() {
		T summ = T();
		for (int i = 0; i < size; i++) {
			summ += arr[i];
		}
		cout << "Summa: " << summ << endl;
	}
	~DynArray()
	{
		delete[] arr; std::cout << "DynArr destructed for"
			<< size << " elements, for"
			<< this << '\n';
	}



};
template<typename T>
void DynArray<T>::print()
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
template<typename T>
void DynArray<T>::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}
ostream& operator<<(ostream& os, const Point& X) {
	os << "X: " << X.x << ", Y: " << X.y;
	return os;
}
int main()
{
	int sum = 0;


	DynArray<int> ar1{ 10 };
	ar1.randomize();
	std::cout << "ar1 elements: ";
	ar1.print();
	ar1.summa();
	DynArray<double> ar2{ 11 };
	std::cout << "ar2 elements: ";
	ar2.randomize();
	ar2.print();
	ar2.summa();
	DynArray<char> ar3{ 3 };
	std::cout << "ar3 elements: ";
	ar3.randomize();
	ar3.print();
	ar3.summa();

	DynArray<Point> ar4{ 5 };
	ar4.randomize();
	ar4.print();
	ar4.summa();
	return 0;
}