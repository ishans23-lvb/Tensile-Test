//
//  csv.hpp
//  TT
//
//  Created by Ishan Shah on 2/26/20.
//  Copyright © 2020 Ishan Shah. All rights reserved.
//

#ifndef csv_hpp
#define csv_hpp

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

#define MAX_LINE_SIZE 4096LU
const char delim[]=" \t\r\n";


vector<vector<double>> csv_read(const char* file);
ostream& operator<<(ostream& os,const vector<vector<double>>& v);

#endif /* csv_hpp */
