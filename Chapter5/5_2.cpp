#include<fstream>
using namespace std;

class FileArray{
    fstream fs;
    streampos filePtr;

public:
    FileArray(char* fName) : fs(fName, ios::in|ios::out){}
    FileArray& operator[](unsigned x);
    FileArray& operator=(char c);
    operator char();
};

FileArray& FileArray::operator[](unsigned int x) {
    filePtr = streampos(x);
    return *this;
}

FileArray& FileArray::operator=(char c) {
    fs.seekg(filePtr,ios::beg);
    fs.write(&c,1);
    fs.flush();
    return *this;
}

FileArray::operator char() {
    char c;
    fs.seekg(filePtr,ios::beg);
    fs.read(&c,1);
    return c;
}