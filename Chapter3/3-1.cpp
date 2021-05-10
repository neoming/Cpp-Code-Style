#include <assert.h>
#include <string.h>

class Stack
{
    int top;
    int size;

protected:
    void **vec;

public:
    Stack(int sz);
    ~Stack();
    void *push();
    void *pop();
};

Stack::Stack(int sz)
{
    vec = new void *[size = sz];
    top = 0;
}

Stack::~Stack()
{
    delete[] vec;
}

void *Stack::push()
{
    assert(top < size);
    return vec[top++];
}

void *Stack::pop()
{
    assert(top > 0);
    return vec[top--];
}

const int defaultStack = 128;

class CharStack : public Stack
{
    char *data;

public:
    CharStack();
    CharStack(int size);
    CharStack(int size, char *init);
    ~CharStack();
    void push(char);
    char pop();
};

CharStack::CharStack() : Stack(defaultStack)
{
    data = new char[defaultStack];
    for (int i = 0; i < defaultStack; i++)
    {
        vec[i] = &data[i];
    }
}

CharStack::CharStack(int size) : Stack(size)
{
    data = new char[size];
    for (int i = 0; i < size; i++)
    {
        vec[i] = &data[i];
    }
}

CharStack::CharStack(int size, char *init) : Stack(size)
{
    data = new char[size];
    for (int i = 0; i < size; i++)
    {
        vec[i] = &data[i];
    }
    for (int i = 0; i < size; i++)
    {
        *((char *)Stack::push()) = init[i];
    }
}

CharStack::~CharStack()
{
    delete[] data;
}

void CharStack::push(char d)
{
    *((char *)Stack::push()) = d;
}

char CharStack::pop()
{
    return *((char *)Stack::pop());
}

class IntStack : public Stack
{
    int *data;

public:
    IntStack();
    IntStack(int size);
    ~IntStack();
    void push(int);
    int pop();
};

IntStack::IntStack() : Stack(defaultStack)
{
    data = new int[defaultStack];
    for (int i = 0; i < defaultStack; i++)
    {
        vec[i] = &data[i];
    }
}

IntStack::IntStack(int size) : Stack(size)
{
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        vec[i] = &data[i];
    }
}

IntStack::~IntStack()
{
    delete[] data;
}

void IntStack::push(int d)
{
    *((int *)Stack::push()) = d;
}

int IntStack::pop()
{
    return *((int*)Stack::pop());
}