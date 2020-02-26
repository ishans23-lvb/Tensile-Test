//
//  name.cpp
//  TT
//
//  Created by Ishan on 2/26/20.
//  Copyright © 2020 Ishan. All rights reserved.
//

#include "name.hpp"

static const char delim[]="-.";
static bool validate_seg(const char seg[4096]);

//temp(°C)-time(hrs)-direction(xy=0, z=1)-number.csv
//Direction: xy=0, z=1
vector<int> get_info(const char* file_name)
{
    vector<int> info;
    char seg[4096];
    const char* start=file_name;
    
    while(*start)
    {
        size_t len=strcspn(start,delim);
        assert(len<sizeof(seg)-1);
        
        memset(seg,0,sizeof(seg));
        memcpy(seg,start,len);
        assert(validate_seg(seg));
        
        int val=0;
        sscanf(seg,"%d",&val);
        info.push_back(val);
        
        if(start[len]=='.' || !start[len])
            break;
        
        start+=(len+1);
    }
    
    assert(info.size()==4);
    return info;
}

static bool validate_seg(const char seg[4096])
{
    bool end=false;
    for(int i=0;i<4096;i++)
    {
        if(!end)
        {
            if( seg[i] && (seg[i]<'0' || seg[i]>'9'))
                return false;
            if(!seg[i])
                end=true;
        }
        else
        {
            if(seg[i])
                return false;
        }
    }
    
    return true;
}
