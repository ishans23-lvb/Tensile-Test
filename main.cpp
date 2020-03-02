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

char dir[PATH_MAX+1]="";
char output_file[PATH_MAX+1]="";
static bool fcsv=false, header=false;
static int rounds=-1;


ostream& operator<<(ostream& os,const vector<int>& v);

int main(int argc,const char* argv[])
{
//    vector<vector<double>> data=csv_read(TFILE);
//    cout << data << endl << endl;
//    cout << "EM: " << get_em_naive(data) << endl;
//    cout << "EMR: " << get_em_rand(data,100) << endl;
//    cout << "EMA: " << get_em_adv(data,100) << endl << endl;
    
    print_results(TDIR,true,true);
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

