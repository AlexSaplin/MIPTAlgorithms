#include <stdexcept>
template <typename T>
class vector
{
private:

    void reduce_vector()
    {
        T *new_vector = new T[array_size / 2];
        array_size = array_size / 2;
        for (int i = 0; i < current_size; i++)
        {
            new_vector[i] = array[i];
        }
        delete[](array);
        array = new_vector;
    }

    void expand_vector()
    {
        T *new_vector = new T[array_size * 2 + 1];
        array_size = array_size * 2 + 1;
        for (int i = 0; i < current_size; i++)
        {
            new_vector[i] = array[i];
        }
        delete[](array);
        array = new_vector;
    }


public:

    T *array;
    int array_size = 0;
    int current_size = 0;
    ~vector()
    {
        delete[](array);
    }

    int size()
    {
        return current_size;
    }

    void swap(int pos_first, int pos_second)
    {
        T buff = array[pos_first];
        array[pos_first] = array[pos_second];
        array[pos_second] = array[pos_first];
    }

    T &operator[](int index)
    {
        if (0 > index || index >= current_size)
        {
            throw std::out_of_range("No such element in vector");
        }
        return array[index];
    }

    void push_back(T value)
    {
        if (current_size >= array_size)
        {
            expand_vector();
        }
        array[current_size++] = value;
    }

    void pop_back()
    {
        if (current_size == 0)
        {
            throw std::logic_error("Vector is empty");
        }
        current_size--;
        if (4 * current_size < array_size)
        {
            reduce_vector();
        }
    }

};
