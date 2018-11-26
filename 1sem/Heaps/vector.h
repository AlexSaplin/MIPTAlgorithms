#include <exception>

template<class T>
class Vector
{
private:
	T* array;
	int sz;
	int max_size;
	void inc_sz()
	{
		max_size <<= 1;
		T* narray = new T[2 * sz];
		memcpy(narray, array, sizeof array);
		delete array;
		array = narray;
	} 
public:
	Vector()
	{
		sz = 0;
		array = new T[1];
	}
	int get_size()
	{
		return sz;
	}
	void push_back(int value)
	{
		if (max_size == sz)
		{
			inc_sz();
		}
		array[sz++] = value;
	}
	void pop_back()
	{
		--sz;
		if (sz < 0)
		{
			throw std::out_of_range("Cannot pop_back from empty Vector");
		}
	}
	T& operator[](int id)
	{
		if (id < -sz || id >= sz)
		{
			throw std::out_of_range("Out of range");
		}
		return id >= 0 ? array[id] : array[sz + id];
	}
};
