#include <fstream>

using namespace std;
class FileArray : public fstream
{
    streampos filePtr;

public:
    FileArray(char *fName) : fstream(fName, ios::in | ios::out) {}
    FileArray &operator[](unsigned x)
    {
        filePtr = streampos(x);
        return *this;
    }
    FileArray &operator=(char buf)
    {
        seekp(filePtr, ios::beg);
        write(&buf, 1);
        flush();
        return *this;
    }
    operator char()
    {
        char buf;
        seekg(filePtr, ios::beg);
        read(&buf, 1);
        return buf;
    }
};

int main()
{
    FileArray source("input.txt"), dest("output.txt");
    char c;
    int i,j,n;
    c = source[j];
}