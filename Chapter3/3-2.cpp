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

class CharStack : public StackIndex
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

CharStack::CharStack() : StackIndex(defaultStack)
{
    data = new char[defaultStack];
}

CharStack::CharStack(int size) : StackIndex(size)
{
    data = new char[size];
}

CharStack::CharStack(int size, char *init) : StackIndex(size)
{
    data = new char[size];
    for (int i = 0; i < strlen(init); i++)
    {
        data[StackIndex::push()] = init[i];
    }
}

CharStack::~CharStack()
{
    delete [] data;
}

void CharStack::push(char d)
{
    data[StackIndex::push()] = d;
}

char CharStack::pop()
{
    return data[StackIndex::pop()];
}

class IntStack : public StackIndex
{
    int *data;

public:
    IntStack();
    IntStack(int size);
    ~IntStack();
    void push(int);
    int pop();
};


IntStack::IntStack() : StackIndex(defaultStack)
{
    data = new int[defaultStack];
}

IntStack::IntStack(int size) : StackIndex(size)
{
    data = new int[size];
}

IntStack::~IntStack()
{
    delete [] data;
}

void IntStack::push(int d)
{
    data[StackIndex::push()] = d;
}

int IntStack::pop()
{
    return data[StackIndex::pop()];
}