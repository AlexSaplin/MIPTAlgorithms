#define __GLIBCXX_DEBUG
#include <iostream>
#include "heap.h"
#include "binomialheap.h"

using namespace std;

int main()
{
    BinomialHeap<int> a;
    BinomialHeap<int> *b = new BinomialHeap<int>();
    auto x = a.insert(23);
    auto y = a.insert(345);
    auto xx = b->insert(1);
    auto yy = b->insert(28);
    a.merge(b);
    a.change(xx, -2);
    cout << a.get_min() << "\n";
    a.change(y, 21);
    cout << a.get_min() << "\n";
    cout << a.extract_min() << "\n";
    cout << a.get_min() << "\n";
    cout << a.extract_min() << "\n";
    return 0;
}
