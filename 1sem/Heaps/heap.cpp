#include "vector.h"

template<class T>
class Heap
{
private:
    
    Vector<T> v;
    
    void sift_up(Node *vertex)
    {
        if (vertex->parent == vertex)
        {
            return;
        }
        if (vertex->parent->value > vertex->value)
        {
            swap(vertex->parent, vertex);
            sift_up(vertex->parent);
        }
    }
    
    void sift_down(Node *vertex)
    {
        Node *min_vertex = vertex;
        if (vertex->left != NULL && vertex->left->value < min_vertex->value)
        {
            min_vertex = vertex->left;
        }
        if (vertex->right != NULL && vertex->right->value < min_vertex->value)
        {
            min_vertex = vertex->right;
        }
        if (min_vertex != vertex)
        {
            sift_down(min_vertex);
        }
    }

public:
    
};