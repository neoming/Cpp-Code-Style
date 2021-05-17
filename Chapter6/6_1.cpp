extern "C"{
    DIR *opendir();
    dirent *readdir(DIR*);
    long telldir(DIR*);
    void seekdir(DIR*, long );
    void closedir(DIR*);
}

class Directory{
    DIR *dir;
public:
    Directory(char*);
    ~Directory();
    const char *name();
    long tell();
    void seek(long);
};

Directory::Directory(char * path) {
     dir = opendir(path);
}

Directory::~Directory() {
    closedir(dir);
}

const char *Directory::name() {
    dirent *d = readdir(dir);
    return d ? d->d_name : NULL;
}

long Directory::tell() {
    return telldir(dir);
}

void Directory::seek(long loc) {
    seekdir(dir,loc);
}