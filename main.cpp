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
#include "csv.hpp"
using namespace std;
#define TFILE "/Users/ishanshah/Desktop/Test/Data.csv"


int main(void)
{
    cout << csv_read(TFILE) << endl;
}





