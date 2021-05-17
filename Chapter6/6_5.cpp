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
    char *errStr;
public:
    Directory(char*, int *error = NULL);
    ~Directory();
    const char *name();
    long tell();
    void seek(long);
    const char *error();
};

Directory::Directory(char * path, int *error) {
    errStr = NULL;
    dir = opendir(path);
    if(!dir){
        if(errno > 0 && errno< sys_nerr){
            errStr = sys_errlist[errno];
        }else{
            errStr = "unknow error";
        }
        errno = 0;
    }
}

Directory::~Directory() {
    if(dir)
        closedir(dir);
}

const char *Directory::name() {
    if(!dir)
        return NULL;
    dirent *d = readdir(dir);
    if(!d)
        return NULL;
    strcpy(nameCopy, d->d_name);
    return nameCopy;
}

long Directory::tell() {
    return dir?telldir(dir):0;
}

void Directory::seek(long loc) {
    if(dir)
        seekdir(dir,loc);
}