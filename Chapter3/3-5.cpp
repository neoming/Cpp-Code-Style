#include <assert.h>

const int defaultStack = 128;

template <class T>
class Stack
{
    int size;
    int top;
    T *data;

public:
    Stack(int size = defaultStack);
    ~Stack();
    void push(T);
    T pop();
};

template <class T>
Stack<T>::Stack(int s)
{
    size = s;
    top = 0;
    data = new T[size];
}

template <class T>
Stack<T>::~Stack()
{
    delete[] data;
}

template <class T>
void Stack<T>::push(T d)
{
    assert(top < size);
    data[top++] = d;
}

template <class T>
T Stack<T>::pop()
{
    assert(top > 0);
    return data[--top];
}