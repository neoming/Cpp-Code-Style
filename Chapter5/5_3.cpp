

#include<fstream>

using namespace std;


class FileArray {
    friend class Index;

    FileArray &operator=(const FileArray &);

    fstream fs;

public:
    FileArray(char *fName) : fs(fName, ios::in | ios::out) {}

    Index operator[](unsigned x);
};


class Index {
    friend class FileArray;

    FileArray *fa;
    streampos filePtr;

    Index(FileArray *_fa, int x);

public:
    Index &operator=(char c);

    operator char();
};

Index::Index(FileArray *_fa, int x) {
    fa = _fa;
    filePtr = streampos(x);
}

Index& Index::operator=(char c) {
    fa->fs.seekg(filePtr,ios::beg);
    fa->fs.write(&c,1);
    fa->fs.flush();
    return *this;
}

Index::operator char() {
    char c;
    fa->fs.seekg(filePtr,ios::beg);
    fa->fs.read(&c,1);
    return c;
}

Index FileArray::operator[](unsigned int x) {
    return Index(this,x);
}