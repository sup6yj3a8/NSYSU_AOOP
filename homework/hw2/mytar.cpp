//
//  mytar.cpp
//  OOP2
//
//  Created by Aaron on 2021/4/20.
//

#include "mytar.hpp"
#include <iostream>
#include <fstream>
#include <array>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

Tar::Tar(const char file[])
{
    struct TarHeader header;
    ifstream tarFile(file, ios::in);
    
    tarFile.seekg(0, ios::end);
    long long fileSize =tarFile.tellg();
    int fileBlock = getBlock(fileSize);
    tarFile.seekg(0, ios::beg);
    int currBlock = 0;
    
    while ( currBlock++ < fileBlock ) {
        tarFile.read( header.filename , 100);
        tarFile.read( header.filemode , 8);
        tarFile.read( header.userid , 8);
        tarFile.read( header.groupid , 8);
        tarFile.read( header.filesize , 12);
        tarFile.read( header.mtime , 12);
        tarFile.read( header.checksum , 8);
        tarFile.get( header.type);
        tarFile.read( header.lname , 100);

        /* USTAR Section */
        tarFile.read( header.USTAR_id , 6);
        tarFile.read( header.USTAR_ver , 2);
        tarFile.read( header.username , 32);
        tarFile.read( header.groupname , 32);
        tarFile.read( header.devmajor , 8);
        tarFile.read( header.devminor , 8);
        tarFile.read( header.prefix , 155);
        tarFile.read( header.pad , 12);

        
        if (header.filename[0] == 0) {break;}
        
        cout << getType(header.type) << getMode(header.filemode) << " ";
        cout << header.username << "/" << header.groupname << " ";
        cout << setfill(' ') << setw(6) <<getSize(header.filesize) << " ";
        printTime(header.mtime);
        cout << " " << header.filename << endl;
        
        currBlock += getBlock(getSize(header.filesize));
        tarFile.seekg(getBlock(getSize(header.filesize)) * 512, ios::cur);
    }
    tarFile.close();
}

char Tar::getType(const char &type){
    char typeList[] = {'-', ' ', 'l', ' ', ' ', 'd'};
    
    if (type - '0' >= 0 && type - '0' <= 5) {
        return typeList[type - '0'];
    }else{
        return '-';
    }
    
}

string Tar::getMode(const char mode[]){
    string str;
    for (int i=3; i<=5; ++i) {
        str += numToMode(mode[i]);
    }
    return str;
}

string Tar::numToMode(const char num){
    const array<string, 8> MODE =
    {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};
    return MODE[num - '0'];
}

long long Tar::getSize(const char oSize[]){
    return oTod(atoi(oSize));
}

int Tar::getBlock(const int &size){
    return ceil(static_cast<double>(size) / 512);
}

long long Tar::oTod(long long num8){
    long long num10 = 0;
    long long len = 1;
    for (; num8 != 0; num8 /= 10) {
        num10 += (num8 % 10) * len;
        len *= 8;
    }
    return num10;
}

void Tar::printTime(const char oTime[]){
    int monthDay[] = {0,  31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31,};
    long long time = oTod(atoll(oTime)) + 28800; // GM+08
    long long sec = time % 60;
    time /= 60;
    long long min = time % 60;
    time /= 60;
    long long hr = time % 24;
    time /= 24;
    if (hr!=0 && min!=0 && sec!=0){++time;} // 不整日進位
    time -= 14245; // 1990/1/1 -> 2009/1/1
    
    int year = 2009;
    int month = 1;
    int isLeap = 0;
    for ( ; time >= 1461; time -= 1461){year+=4;} //4 year = 1,461 days
    for ( ; time >= 366; time -= 365) {++year; ++isLeap;} // 1 year = 365 days
    for ( ; month<=12; ++month) {
        if (time >= 29 && isLeap == 3) {
            time -= 29;
        }else if( time >= monthDay[month] ){
            time -= monthDay[month];
        }else{
            break;
        }
    }
    
    cout << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0')<< time << " ";
    cout << setw(2) << setfill('0') << hr << ":" << setw(2) << setfill('0') << min;
}
