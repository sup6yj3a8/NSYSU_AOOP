//
//  mytar.hpp
//  OOP2
//
//  Created by Aaron on 2021/4/20.
//

#ifndef mytar_hpp
#define mytar_hpp

#include <stdio.h>
#include <string>

struct TarHeader {
    char filename[100];
    char filemode[8];
    char userid[8];
    char groupid[8];
    char filesize[12];
    char mtime[12];
    char checksum[8];
    char type;
    char lname[100];
    
    /* USTAR Section */
    char USTAR_id[6];
    char USTAR_ver[2];
    char username[32];
    char groupname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
    char pad[12];
};

class Tar{
public:
    Tar(const char file[]);
    
    char getType(const char &type);
    std::string getMode(const char mode[]);
    long long getSize(const char oSize[]);
    int getBlock(const int &size);
    
    std::string numToMode(const char num);
    long long oTod(long long num8);
    void printTime(const char oTime[]);
};

#endif /* mytar_hpp */
