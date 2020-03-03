//
//  files.cpp
//  TT
//
//  Created by Ishan Shah on 3/2/20.
//  Copyright © 2020 Ishan Shah. All rights reserved.
//

#include "files.hpp"

static const vector<vector<int>> oinfo=
{
    {0,0,0,1},{0,0,0,2},{0,0,0,3},
    {0,0,1,1},{0,0,1,2},{0,0,1,3},
    
    {220,2,0,1},{220,2,0,2},{220,2,0,3},
    {220,2,1,1},{220,2,1,2},{220,2,1,3},
    {220,8,0,1},{220,8,0,2},{220,8,0,3},
    {220,8,1,1},{220,8,1,2},{220,8,1,3},
    
    {260,2,0,1},{260,2,0,2},{260,2,0,3},
    {260,2,1,1},{260,2,1,2},{260,2,1,3},
    {260,8,0,1},{260,8,0,2},{260,8,0,3},
    {260,8,1,1},{260,8,1,2},{260,8,1,3},
    
    {300,2,0,1},{300,2,0,2},{300,2,0,3},
    {300,2,1,1},{300,2,1,2},{300,2,1,3},
    {300,8,0,1},{300,8,0,2},{300,8,0,3},
    {300,8,1,1},{300,8,1,2},{300,8,1,3}
};

void print_results(const char* const dir,const bool fcsv,const bool header)
{
    vector<pair<vector<int>,double>> results=get_results(dir);
    
    for(size_t i=0;i<results.size();i++)
    {
        const vector<int>& info=results[i].first;
        for(size_t j=0;j<info.size();j++)
        {
            if(j!=0)
            {
                if(fcsv)
                    printf(",");
                else
                    printf("-");
            }
            printf("%d",info[j]);
        }
        if(fcsv)
            printf(",");
        else
            printf(": ");
        printf("%lf\n",results[i].second);
    }
}

vector<pair<vector<int>,double>> get_results(const char* const dir)
{
    DIR* d=NULL;
    struct dirent* sd=NULL;
    char full_fpath[PATH_MAX+1];
    vector<pair<vector<int>,double>> results;
    vector<pair<vector<int>,double>> sresults;
    
    
    
    if(!(d=opendir(dir)))
    {
        fprintf(stderr,"opendir(%s) failed: %s\n",dir,strerror(errno));
        abort();
    }
    
    
    while((sd=readdir(d)))
    {
        if(sd->d_name[0]=='.')
            continue;
        
        memset(full_fpath,0,sizeof(full_fpath));
        strcpy(full_fpath,dir);
        strcat(full_fpath,"/");
        strcat(full_fpath,sd->d_name);
        
        vector<int> info=get_info(sd->d_name);
        assert(info.size()==4);
        double em=get_em_from_file(full_fpath);
        results.push_back({info,em});
    }
    
    for(size_t i=0;i<(::oinfo).size();i++)
    {
        double em=0;
        bool found=false;
        
        for(size_t j=0;j<results.size();j++)
        {
            if((::oinfo)[i]==results[j].first)
            {
                found=true;
                em=results[j].second;
                break;
            }
        }
        
        if(!found)
        {
            fprintf(stderr,"\n\nError: {%d-%d-%d-%d} Not Found\n\n",::oinfo[i][0],::oinfo[i][1],::oinfo[i][2],::oinfo[i][3]);
        }
        else
        {
            sresults.push_back({(::oinfo)[i],em});
        }
    }
    
    return sresults;
}

double get_em_from_file(const char* file)
{
    vector<vector<double>> data=csv_read(file);
    
    double nem=get_em_naive(data);
    if(data.size()<1000)
    {
        return nem;
    }
    else
    {
        double rem=get_em_rand(data);
        double aem=get_em_adv(data);
        double rd= (nem-rem)>=0.0 ? (nem-rem) : (rem-nem);
        double ad= (nem-aem)>=0.0 ? (nem-aem) : (aem-nem);
        
        if(rem>0.0 && rd<10.0)
            return rem;
        else if(aem>0.0 && ad<10.0)
            return aem;
        else
            return nem;
    }
    
}

