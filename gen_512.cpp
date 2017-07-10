#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int buffer2string(char * buffer,char ss[513]);

int main(int argn, char* argv[]){
    if(argn <= 2){
        cout << "expect 2 input data names, input and output dile names" << endl;
    }
    ifstream fin(argv[1],ios::binary);
    ofstream fout(argv[2]);
    char* buffer = new char[64];
    char ss[129];
    int addr = 0;
    while (!fin.eof()){
        for (int i =0 ;i < 64;i++){
            buffer[i] = 0;
        }
        fin.read(buffer,sizeof(char)*64);
        buffer2string(buffer,ss);
        fout <<  hex << addr;
        fout << " : ";
        fout << ss << endl;
        addr += 0x40;
    }
    fin.close();
    fout.close();

    return 0;
}

int buffer2string(char * buffer,char ss[129]){
    ss[128] = 0;
    for (int i = 0,j = 127; i < 64; i++){
        ss[j--] = (buffer[i] & 0xf) < 0xa ?  (buffer[i] & 0xf) + '0':  (buffer[i] & 0xf) - 0xa +'a';     
        ss[j--] = ((buffer[i] >> 4) & 0xf) < 0xa ?  ((buffer[i]>>4) & 0xf) + '0':  ((buffer[i]>>4) & 0xf) - 0xa +'a';     
    }
    return 0;
}
