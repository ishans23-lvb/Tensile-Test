//
//  main.cpp
//  TG
//
//  Created by Ishan Shah on 12/23/19.
//  Copyright © 2019 Ishan Shah. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <getopt.h>
#include "csv.hpp"
#include "name.hpp"
using namespace std;
#define TFILE "/Users/ishanshah/Desktop/Test/Data.csv"

static const char* dir=nullptr;
static bool fcsv=false, header=false;


ostream& operator<<(ostream& os,const vector<int>& v);

int main(int argc,const char* argv[])
{
    int ch=0;
    while((ch=getopt(argc,(char**)argv,"fhd:"))!=-1)
    {
        switch(ch)
        {
            case 'f':
                fcsv=true;
                printf("csv format set\n");
                break;
            case 'h':
                header=true;
                printf("header set\n");
                break;
            case 'd':
                dir=optarg;
                printf("dir set to: %s\n",optarg);
                break;
        }
    }
    
    cout << get_info("220-2-0-3.csv") << endl;
    return 0;
}

ostream& operator<<(ostream& os,const vector<int>& v)
{
    os << "{";
    for(vector<int>::const_iterator cit=v.cbegin();cit!=v.cend();cit++)
    {
        if(cit!=v.cbegin())
            os <<", ";
        os << *cit;
    }
    os << "}";
    return os;
}

