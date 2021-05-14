#include <fstream>
using namespace std;
class ByteFile{
    fstream fs;
public:
    ByteFile(char* fName):fs(fName,ios::in|ios::out);
    void put(unsigned int at, char c);
    char get(unsigned int at);
};

void ByteFile::put(unsigned int at, char c) {
    fs.seekg(streampos(at),ios::beg);
    fs.write(&c,1);
    fs.flush();
}

char ByteFile::get(unsigned int at) {
    char c;
    fs.seekg(streampos(at),ios::beg);
    fs.read(&c,1);
    return c;
}