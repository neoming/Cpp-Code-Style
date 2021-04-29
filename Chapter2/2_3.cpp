#include <string.h>

class SimpleString
{
    char *_string;
    int _length;

public:
    SimpleString();
    SimpleString(const char *);
    SimpleString(SimpleString &s);
    ~SimpleString();

    const char *string() const;
    SimpleString &operator=(const char *);
    SimpleString &operator=(const SimpleString &);
};

char *
Strdup(const char *s)
{
    char *s2 = new char[strlen(s) + 1];
    strcpy(s2, s);
    return s2;
}

SimpleString::SimpleString()
{
    _string = 0;
    _length = 0;
}

SimpleString::~SimpleString()
{
    delete[] _string;
}

SimpleString::SimpleString(SimpleString &s)
{
    if (s._string)
    {
        _string = Strdup(s._string);
        _length = s._length;
    }
    else
    {
        _string = 0;
        _length = 0;
    }
}

SimpleString::SimpleString(const char *s)
{
    _string = s ? Strdup(s) : 0;
    _length = s ? strlen(s) : 0;
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
    delete [] _string;
    _string = s?Strdup(s):0;
    _length = s?strlen(s):0;
    return *this;
}


SimpleString&
SimpleString::operator=(const SimpleString& s)
{
    delete [] _string;
    _string = s._string ? Strdup(s._string) : 0;
    _length = _string? s._length : 0;
    return *this;
}