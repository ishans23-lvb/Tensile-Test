//
//  modulus.hpp
//  TT
//
//  Created by Ishan on 2/26/20.
//  Copyright © 2020 Ishan. All rights reserved.
//

#ifndef modulus_hpp
#define modulus_hpp

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

double get_em_naive(const vector<vector<double>>& er_data);
double get_em_rand(const vector<vector<double>>& er_data,const int rounds=100);
double get_em_adv(const vector<vector<double>>& er_data,const int adv=10);


#endif /* modulus_hpp */
