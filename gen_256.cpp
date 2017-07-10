#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main(){
    short * memdata = new short[256];
    for (int i =0 ;i < 256;i++){
        memdata[i] = i;
    }
    int fd = open("./memdata.bin",O_WRONLY|O_CREAT|O_TRUNC,0600);
    write(fd,memdata,sizeof(short)*256);
    close(fd);

    return 0;
}
