#include <algorithm>
#include <stdexcept>

template <typename Key>
class BinomialHeap
{
public:
    class IDPointer;
private:
    class Node
    {
        friend BinomialHeap;
    public:
        Key value;
        int degree = 0;
        Node *parent = nullptr;
        Node *left_sibling = nullptr;
        Node *right_sibling = nullptr;
        Node *child = nullptr;
        IDPointer *pointer = nullptr;

        Node() = default;

        Node(Key _value)
        {
            value = _value;
            pointer = new IDPointer(this);
            degree = 0;
        }

        void set_pointer(IDPointer *new_pointer)
        {
            pointer = new_pointer;
            new_pointer->change_node(this);
        }

        ~Node()
        {
            delete child;
            delete right_sibling;
            delete pointer;
        }
    };

    Node *root = nullptr;
    Node *min_node = nullptr;
    int size = 0;

    void recalc_heap()
    {
        min_node = nullptr;
        if (!root)
            return;
        while (root->parent)
        {
            root = root->parent;
        }
        while (root->left_sibling)
        {
            root = root->left_sibling;
        }
        size = 0;
        Node *current = root;
        while (current)
        {
            if (!min_node || current->value < min_node->value)
            {
                min_node = current;
            }
            current = current->right_sibling;
            size++;
        }
    }

    BinomialHeap(Node *new_root)
    {
        root = new_root;
        recalc_heap();
    }

    void sift_up(IDPointer *pointer)
    {
        while (pointer->node->parent && pointer->node->value < pointer->node->parent->value)
        {
            std::swap(pointer->node->parent->value, pointer->node->value);
            pointer->node->set_pointer(pointer->node->parent->pointer);
            pointer->node->parent->set_pointer(pointer);
        }
    }

    void cut_node(Node *node)
    {
        if (node->right_sibling)
        {
            node->right_sibling->left_sibling = nullptr;
            node->right_sibling = nullptr;
        }
        if (node->left_sibling)
        {
            node->left_sibling->right_sibling = nullptr;
            node->left_sibling = nullptr;
        }
        node->parent = nullptr;
    }

    Node* union_trees(Node *left, Node *right)
    {
        if (left->value > right->value)
        {
            std::swap(left, right);
        }
        right->parent = left;
        right->right_sibling = left->child;
        if (left->child)
        {
            left->child->left_sibling = right;
        }
        left->child = right;
        left->degree++;
        return left;
    }

    void link_nodes(Node *left, Node *right)
    {
        if (left)
        {
            left->right_sibling = right;
        }
        if (right)
        {
            right->left_sibling = left;
        }
    }

public:
    class IDPointer
    {
        friend BinomialHeap;
    public:
        IDPointer() = default;

        IDPointer(Node *new_node)
        {
            node = new_node;
        }
    private:

        Node *node = nullptr;

        void change_node(Node *new_node)
        {
            node = new_node;
        }
    };

    BinomialHeap() = default;

    BinomialHeap(Key value)
    {
        root = new Node(value);
        min_node = root;
        size = 1;
    }

    ~BinomialHeap()
    {
        delete root;
    }

    void merge(BinomialHeap<Key> *right)
    {
        recalc_heap();
        if (!right->root)
        {
            return;
        }
        if (!root)
        {
            root = right->root;
            min_node = right->min_node;
            size = right->size;
            return;
        }
        Node *current_left = root;
        Node *current_right = right->root;
        Node *prev_left;
        Node *prev_right;
        Node *next_left;
        Node *next_right;
        Node *last;
        while (current_left && current_right)
        {
            last = current_left;
            prev_left = current_left->left_sibling;
            next_left = current_left->right_sibling;
            prev_right = current_right->left_sibling;
            next_right = current_right->right_sibling;
            if (current_left->degree < current_right->degree)
            {
                current_left = next_right;
            }
            else
            {
                if (current_left->degree == current_right->degree)
                {
                    cut_node(current_left);
                    cut_node(current_right);
                    current_left = union_trees(current_left, current_right);
                    last = current_left;
                    link_nodes(prev_left, current_left);
                    link_nodes(current_left, next_left);
                    while (next_left && current_left->degree == next_left->degree)
                    {
                        prev_right = next_left->right_sibling;
                        cut_node(current_left);
                        cut_node(next_left);
                        current_left = union_trees(current_left, current_right);
                        last = current_left;
                        link_nodes(prev_left, current_left);
                        link_nodes(current_left, prev_right);
                        next_left = prev_right;
                    }
                    current_right = next_right;
                }
                else
                {
                    cut_node(current_left);
                    cut_node(current_right);
                    Node *buff = current_left;
                    current_left = current_right;
                    current_right = buff;
                    link_nodes(prev_left, current_left);
                    link_nodes(current_left, next_left);
                    link_nodes(prev_right, current_right);
                    link_nodes(current_right, next_right);
                    last = current_left;
                }
            }
            if (!current_left && current_right)
            {
                next_right = current_right->right_sibling;
                cut_node(current_right);
                link_nodes(last, current_right);
                current_left = current_right;
                current_right = next_right;
            }
        }
        recalc_heap();
        right->root = nullptr;
        right->min_node = nullptr;
        delete right;
    }

    bool is_empty() const
    {
        return size == 0;
    }

    IDPointer* insert(Key value)
    {
        BinomialHeap *new_heap = new BinomialHeap(value);
        IDPointer *result = new_heap->min_node->pointer;
        merge(new_heap);
        return result;
    }

    Key get_min() const
    {
        if (!size)
        {
            throw std::invalid_argument("Heap is empty");
        }
        return min_node->value;
    }

    void remove_node(IDPointer *pointer) {
        pointer->node->value = get_min() - 1;
        sift_up(pointer);
        link_nodes(pointer->node->left_sibling, pointer->node->right_sibling);
        Node *new_root = pointer->node->child;
        Node *current = new_root;
        while (current) {
            current->parent = nullptr;
            current = current->right_sibling;
        }
        current = new_root;
        for (int current_degree = 0; current_degree < pointer->node->degree; current_degree++) {
            current->left_sibling = current->right_sibling;
            current->right_sibling = nullptr;
            current = current->left_sibling;
        }
        for (int current_degree = 0; current_degree < pointer->node->degree - 1; current_degree++) {
            new_root->left_sibling->right_sibling = new_root;
            new_root = new_root->left_sibling;
        }
        if (!pointer->node->left_sibling)
        {
            if (!pointer->node->right_sibling)
            {
                root = new_root;
                recalc_heap();
            }
            else
            {
                root = pointer->node->right_sibling;
                merge(new BinomialHeap(new_root));
            }
        }
        else
        {
            merge(new BinomialHeap(new_root));
        }
    }

    Key extract_min()
    {
        if (!size)
        {
            throw std::invalid_argument("Heap is empty");
        }
        Key ans = min_node->value;
        remove_node(min_node->pointer);
        return ans;
    }

    void change(IDPointer *pointer, Key value)
    {
        if (pointer->node->value < value)
        {
            throw std::logic_error("value must be lower than old");
        }
        pointer->node->value = value;
        sift_up(pointer);
        recalc_heap();
    }
};
