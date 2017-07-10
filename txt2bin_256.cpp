#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;


int string2buffer(char* ss,char * buffer);


int main(int argn, char* argv[]){
    ifstream fin(argv[1]);
    ofstream fout("output",ios::binary);
    char buffer[65];
	char buffer_bin[33];
    buffer_bin[64] = 0;
    buffer[32] = 0;
	while (!fin.eof()){
		fin >> buffer;
        cout << buffer << endl;
		string2buffer(buffer,buffer_bin);
		fout.write(buffer_bin,sizeof(char)*32);
	}
	fout.close();
	fin.close();
    return 0;
}

int string2buffer(char* ss,char * buffer){
    for (int i = 0,j = 31; i < 64; ){
		char tmp = 0;
        cout << int(ss[i]) << " ";
		if(ss[i] - '0' < 0xa){
			tmp = ((ss[i] - '0') << 4);
		}else {
			tmp = ((ss[i] - 'a' + 0xa) << 4);
		}
		++i;
        cout << int(ss[i]) << " ";
		if(ss[i] - '0' < 0xa){
			tmp |= ((ss[i] - '0'));
		}else {
			tmp |= ((ss[i] - 'a' + 0xa));
		}
		++i;
        cout << i  <<"   "; 
        cout << hex << int(tmp) <<endl;
		buffer[j] = tmp;
        j --;
    }
    return 0;
}

