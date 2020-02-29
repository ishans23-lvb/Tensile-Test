//
//  modulus.cpp
//  TT
//
//  Created by Ishan on 2/26/20.
//  Copyright © 2020 Ishan. All rights reserved.
//

#include "modulus.hpp"

double calc_em(const vector<double>& first,const vector<double>& second)
{
    return (second[1]-first[1])/((second[0]-first[0])/100.0);
}

double get_em_naive(const vector<vector<double>>& er_data)
{
    const vector<double>& first=er_data[0];
    const vector<double>& second=er_data.back();
    
    return calc_em(first,second);
}

double get_em_rand(const vector<vector<double>>& er_data,const int rounds)
{
    assert(er_data.size()>500);
    assert(rounds>0);
    long double sum=0;
    for(int i=0;i<rounds;i++)
    {
        long fi=rand()%er_data.size();
//        if((er_data.size()-1)-fi<100)
//            fi=((er_data.size()-1)-100);
        while(((er_data.size()-1)-fi)<100)
        {
            fi=rand()%er_data.size();
        }
        
        double em=calc_em(er_data[fi],er_data.back());
        sum+=em;
    }
    
    return sum/double(rounds);
}

double get_em_adv(const vector<vector<double>>& er_data,const int adv)
{
    assert(er_data.size()>500);
    assert(adv>0);
    assert(adv<1000);
    assert(adv<er_data.size()/2);
    long si=0, ei=er_data.size()-1;
    long double sum=0;
    
    for(int i=0;i<adv;i++)
    {
        assert(si<ei);
        
        double em=calc_em(er_data[si],er_data[ei]);
        sum+=em;
        
        si++;
        ei--;
    }
    return sum/adv;
}
