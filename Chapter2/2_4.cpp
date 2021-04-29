#include <string.h>

class SimpleString
{
    char *_string;
    void duplicate(const char *);
public:
    SimpleString();
    SimpleString(const char *);
    SimpleString(SimpleString &s);
    ~SimpleString();

    const char *string() const;
    SimpleString &operator=(const char *);
    SimpleString &operator=(const SimpleString &);
};

void
SimpleString::duplicate(const char *s)
{
    if(s)
    {
        _string = new char[strlen(s)+ 1];
        strcpy(_string,s);
    }
    else
    {
        _string = 0;
    }
}

SimpleString::SimpleString()
{
    _string = 0;
}

SimpleString::~SimpleString()
{
    delete[] _string;
}

SimpleString::SimpleString(SimpleString &s)
{
    duplicate(s._string);
}

SimpleString::SimpleString(const char *s)
{
    duplicate(s);
}

const char *
SimpleString::string()
    const
{
    return _string;
}

SimpleString&
SimpleString::operator=(const char *s)
{
    char* pre_string = _string;
    duplicate(s);
    delete [] pre_string;
    return *this;
}


SimpleString&
SimpleString::operator=(const SimpleString& s)
{
    if(this == &s)
        return *this;
    return operator=(s._string);
}