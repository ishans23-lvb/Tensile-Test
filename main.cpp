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
                break;
            case 'h':
                header=true;
                break;
            case 'd':
                dir=optarg;
                break;
        }
    }
    
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

