#include <string.h>
#include <iostream>

class string
{
    char *s;
    int len;

public:
    string()
    {
        s = new char[80];
        len = 80;
    }

    string(int n)
    {
        s = new char[n];
        len = n;
    }

    string(char *p)
    {
        len = strlen(p);
        s = new char[len + 1];
        strcpy(s, p);
    }

    string(string &str)
    {
        len = str.len;
        s = new char[len];
        strcpy(s, str.s);
    }

    ~string()
    {
        delete[] s;
    }

    void assign(char *str)
    {
        strcpy(s, str);
        len = strlen(str);
    };

    void print()
    {
        std::cout << s << "\n";
    }

    void concat(string &a, string &b)
    {
        len = a.len + b.len;
        s = new char[len];
        strcpy(s, a.s);
        strcpy(s, b.s);
    }
};