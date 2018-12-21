#include <cstddef>
#include "vector.h"
template <typename Key>
class Heap
{
public:
    class IDPointer;
private:
    class Node
    {
        friend Heap;
    public:
        int index;
        Key value;
        IDPointer *pointer;

        Node() = default;

        Node(int _index, Key _value, IDPointer *_pointer)
        {
            index = _index;
            value = _value;
            pointer = _pointer;
            if (_pointer)
            {
                _pointer->change_node(this);
            }
        }

        Node &operator=(const Node current)
        {
            index = current.index;
            value = current.value;
            pointer = current.pointer;
            if (current.pointer)
            {
                current.pointer->change_node(this);
            }
            return *this;
        }

        void set_pointer(IDPointer *_pointer)
        {
            pointer = _pointer;
        }
    };

    vector<Node> h;
    int size = 1;
    int children_count = 2;

    void swap(int pos_first, int pos_second)
    {
        h[pos_first].index ^= h[pos_second].index;
        h[pos_second].index ^= h[pos_first].index;
        h[pos_first].index ^= h[pos_second].index;
        Node buff = h[pos_first];
        h[pos_first] = h[pos_second];
        h[pos_second] = h[pos_first];
    }

    void sift_up(int pos)
    {
        for (; pos != 1 && h[pos].value < h[pos / children_count].value; pos /= children_count)
        {
            swap(pos, pos / children_count);
        }
    }

    void sift_down(int pos)
    {
        while (children_count * pos < size)
        {
            int new_pos = children_count * pos;
            for (int current_pos = children_count * pos; current_pos < children_count * pos + children_count; ++current_pos)
            {
                if (h[current_pos].value < h[new_pos].value)
                {
                    new_pos = current_pos;
                }
            }
            if (h[pos].value <= h[new_pos].value)
            {
                return;
            }
            swap(pos, new_pos);
            pos = new_pos;
        }
    }



public:
    class IDPointer
    {
        friend Heap;
    public:
        IDPointer(Node *new_node)
        {
            node = new_node;
            node->set_pointer(this);
        }
    private:

        Node *node = nullptr;

        int get_index()
        {
            return node->index;
        }

        void change_node(Node *new_node)
        {
            node = new_node;
            node->set_pointer(this);
        }
    };

    Heap()
    {
        h.push_back(Node(0, 0, nullptr));
        size = 1;
        children_count = 2;
    }

    bool is_empty() const
    {
        return size == 1;
    }

    IDPointer insert(Key value)
    {
        h.push_back(Node(size, value, nullptr));
        IDPointer insert_result = IDPointer(&h[size]);
        sift_up(size);
        size++;
    }

    Key get_min()
    {
        if (size == 1)
        {
            throw std::logic_error("Heap is empty");
        }
        Key result = h[1].value;
        return result;
    }

    Key extract_min()
    {
        if (size == 1)
        {
            throw std::logic_error("Heap is empty");
        }
        Key result = h[1].value;
        swap(1, --size);
        sift_down(1);
        h.pop_back();
        return result;
    }

    void delete_node(IDPointer ptr)
    {
        int index = ptr.get_index();
        swap(index, --size);
        sift_down(index);
        h.pop_back();
    }

    void change(IDPointer ptr, Key value)
    {
        int index = ptr.get_index();
        if (h[index].value > value)
        {
            h[index].value = value;
            sift_up(index);
        }
        else
        {
            h[index].value = value;
            sift_down(index);
        }
    }

    template <class Iterator>
    Heap(Iterator begin, Iterator end)
    {
        children_count = 2;
        for (Iterator it = begin; it != end; it++)
        {
            h.push_back(Node(size, it, nullptr));
            IDPointer ptr = IDPointer(&h[size]);
            size++;
        }
        for (int i = size / children_count; i > 0; i--)
        {
            sift_down(i);
        }
    }

    void optimize(size_t insert_count, size_t extract_count)
    {
        if (extract_count == 0)
        {
            extract_count = 1;
        }
        if (children_count < insert_count / extract_count)
        {    
            children_count = insert_count / extract_count;
        }
    }

};
