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
#include <limits.h>
#include "csv.hpp"
#include "name.hpp"
#include "modulus.hpp"
#include "files.hpp"
using namespace std;
#define TFILE "/Users/ishanshah/Desktop/Projects/TT/Tensile-Test/Output/300-2-0-2.csv"
#define TDIR "/Users/ishanshah/Desktop/Projects/TT/Tensile-Test/Output"

static char dir[PATH_MAX+1]="";
static bool fcsv=false, header=false;
static int rounds=-1;


ostream& operator<<(ostream& os,const vector<int>& v);

int main(int argc,const char* argv[])
{
    int ch=0;
    while((ch=getopt(argc,(char**)argv,"d:r:fh"))!=-1)
    {
        switch(ch)
        {
            case 'd':
            {
                memset(::dir,0,sizeof(::dir));
                strcpy(::dir,optarg);
                break;
            }
            case 'r':
            {
                sscanf(optarg,"%d",&::rounds);
                break;
            }
            case 'f':
            {
                ::fcsv=true;
                break;
            }
            case 'h':
            {
                ::header=true;
                break;
            }
            default:
                break;
        }
    }
    
    fprintf(stderr,"DIR: %s\n",::dir);
    fprintf(stderr,"csv format: %d\n",::fcsv);
    fprintf(stderr,"Headers: %d\n",::header);
    fprintf(stderr,"Rounds: %d\n\n",::rounds);
    
    print_results(::dir,::fcsv,::header);
    
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

