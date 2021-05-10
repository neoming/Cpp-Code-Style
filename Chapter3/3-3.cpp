#include <assert.h>
#include <string.h>

class StackIndex
{
    int top;
    int size;

public:
    StackIndex(int sz);
    ~StackIndex();
    int push();
    int pop();
};

StackIndex::StackIndex(int sz)
{
    top = 0;
    size = sz;
}

StackIndex::~StackIndex()
{
}

int StackIndex::push()
{
    assert(top < size);
    return top++;
}

int StackIndex::pop()
{
    assert(top > 0);
    return --top;
}

const int defaultStack = 128;

class CharStack
{
    char *data;
    StackIndex index;

public:
    CharStack();
    CharStack(int size);
    CharStack(int size, char *init);
    ~CharStack();
    void push(char);
    char pop();
};

CharStack::CharStack() : index(defaultStack)
{
    data = new char[defaultStack];
}

CharStack::CharStack(int size) : index(size)
{
    data = new char[size];
}

CharStack::CharStack(int size, char *init) : index(size)
{
    data = new char[size];
    for (int i = 0; i < strlen(init); i++)
    {
        data[index.push()] = init[i];
    }
}

CharStack::~CharStack()
{
    delete[] data;
}

void CharStack::push(char d)
{
    data[index.push()] = d;
}

char CharStack::pop()
{
    return data[index.pop()];
}

class IntStack
{
    int *data;
    StackIndex index;

public:
    IntStack();
    IntStack(int size);
    ~IntStack();
    void push(int);
    int pop();
};

IntStack::IntStack() : index(defaultStack)
{
    data = new int[defaultStack];
}

IntStack::IntStack(int size) : index(size)
{
    data = new int[size];
}

IntStack::~IntStack()
{
    delete[] data;
}

void IntStack::push(int d)
{
    data[index.push()] = d;
}

int IntStack::pop()
{
    return data[index.pop()];
}