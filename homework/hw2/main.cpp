//
//  main.cpp
//  OOP2
//
//  Created by Aaron on 2021/4/19.
//

#include <iostream>
#include "mytar.hpp"

using namespace std;
int isTar(const char fileName[]);

int main(int argc, char *argv[]) {
    if ( isTar(argv[1]) ) {
        Tar a(argv[1]);
    }else{
        cout << "mytar: " << argv[1] << ": Cannot open: No such file or directory" << endl;
        cout << "mytar: Error is not recoverable: exiting now" << endl;
    }
}

int isTar(const char fileName[]){
    const char tarName[] = {".tar"};
    int isTarFile = 0;
    int last = 0;
    while (fileName[last++] != 0) {} // Find the last index of fileName
    last -= 2; // Shift left 2 position
    
    // Is the file a tar file?
    int j=3;
    for (int i=last; i>last-4; --i) {
        if (fileName[i] == tarName[j]) {++isTarFile;}
        --j;
    }
    
    return isTarFile == 4 ? 1 : 0;
}
