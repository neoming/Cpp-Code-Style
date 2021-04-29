#include <string.h>
#include <iostream>

class string
{
    char *s;
    int len; // len == strlen(s)

public:
    string(int n = 80)
    {
        s = new char[n];
        s[0] = '\0';
        len = 0;
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
        s = new char[len + 1];
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

    // bug when x.concat(x,y)
    // void concat(string &a, string &b)
    // {
    //     len = a.len + b.len;
    //     delete [] s;
    //     s = new char[len+1];
    //     strcpy(s, a.s);
    //     strcpy(s, b.s);
    // }

    void concat(string &a, string &b)
    {
        len = a.len + b.len;
        char *new_s = new char[len + 1];
        strcpy(new_s, a.s);
        strcpy(new_s, b.s);
        delete[] s;
        s = new_s;
    }
};