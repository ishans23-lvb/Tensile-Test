//
//  files.cpp
//  TT
//
//  Created by Ishan Shah on 3/2/20.
//  Copyright © 2020 Ishan Shah. All rights reserved.
//

#include "files.hpp"

void em_dir(const char* const dir,const bool fcsv,const bool header)
{
    DIR* d=NULL;
    struct dirent* sd=NULL;
    
    if(!(d=opendir(dir)))
    {
        fprintf(stderr,"opendir(%s) failed: %s\n",dir,strerror(errno));
        abort();
    }
    
    if(header)
        printf("Temp(°C),Time(s),Direction(XY=0,Z=1),Number\n");
    
    while((sd=readdir(d)))
    {
        if(sd->d_name[0]=='.')
            continue;
        vector<int> info=get_info(sd->d_name);
        double em=0;
        for(size_t i=0;i<info.size();i++)
        {
            if(i>0)
            {
                if(fcsv)
                    printf(",");
                else
                    printf("-");
            }
            printf("%d",info[i]);
        }
        if(fcsv)
            printf(",%lf\n",em);
        else
            printf(": %lf\n",em);
    }
}
