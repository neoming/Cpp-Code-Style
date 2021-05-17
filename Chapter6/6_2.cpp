extern "C"{
DIR *opendir();
dirent *readdir(DIR*);
long telldir(DIR*);
void seekdir(DIR*, long );
void closedir(DIR*);
}
struct dirent{
    char d_name[10+1];
};
class Directory{
    DIR *dir;
    char nameCopy[sizeof(dirent::d_name)];
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
    if(!d)
    {
        return NULL;
    }
    strcpy(nameCopy, d->d_name);
    return nameCopy;
}

long Directory::tell() {
    return telldir(dir);
}

void Directory::seek(long loc) {
    seekdir(dir,loc);
}