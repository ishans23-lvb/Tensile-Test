//
//  csv.cpp
//  TT
//
//  Created by Ishan Shah on 2/26/20.
//  Copyright © 2020 Ishan Shah. All rights reserved.
//

#include "csv.hpp"
using namespace std;

static bool validate_line(const char* line,long len);
static pair<long,bool> read_line(FILE* f,char line[MAX_LINE_SIZE])
{
    char* ptr=line;
    char c=0;
    long len=0;
    bool eof=false;
    
    memset(line,0,MAX_LINE_SIZE);
    while(((c=fgetc(f))>0) && c!='\n')
    {
        len++;
        if(len>4096)
        {
            fprintf(stderr,"Error: Line exceeds %lu(MAX_LINE SIZE)\nline: ( %s )\n",MAX_LINE_SIZE,line);
            abort();
        }
        *(ptr++)=c;
    }
    
    if(ferror(f))
    {
        fprintf(stderr,"fgetc Error: %s\nline: %s\n",strerror(errno),line);
        abort();
    }
    
    eof=feof(f);
    
    if(c<0 && !eof)
    {
        fprintf(stderr,"Error: read neg char!\nline: %s\n",line);
        abort();
    }
    if(!eof && c!='\n')
    {
        fprintf(stderr,"Error: line read stop read: %d(%c)\n",c,c);
    }
    
    return eof ? pair<long,bool>(len,true) : pair<long,bool>(len,false);
}

static vector<double> parse_line(const char* line,long len)
{
    vector<double> v;
    const char* ptr=line;
    
    assert(validate_line(line,len));
    while(ptr && (ptr-line)<len)
    {
        double val=0;
        ptr+=strspn(ptr,delim);
        sscanf(ptr,"%lf",&val);
        v.push_back(val);
        ptr=strchr(ptr,',');
        ptr= ptr ? ptr+1 : ptr;
    }
    
    return v;
}

vector<vector<double>> csv_read(const char* file)
{
    vector<vector<double>> v;
    vector<double> ldata;
    FILE* f=NULL;
    char line[MAX_LINE_SIZE+1];
    pair<long,bool> ret;
              
    
    if(!(f=fopen(file,"r")))
    {
        fprintf(stderr,"fopen(%s): %s\n",file,strerror(errno));
        abort();
    }
    
    memset(line,0,sizeof(line));
    while(!(ret=read_line(f,line)).second)
    {
        assert(ret.first<=sizeof(line)-1);
        assert(!line[ret.first] && !line[sizeof(line)-1]);
        if(!validate_line(line,ret.first))
        {
            cerr << "Line: ( " << string(line,ret.first) << " ) is invalid" << endl;
            abort();
        }
        
        ldata=parse_line(line,ret.first);
        
        if(ldata.size()>0)
            v.push_back(ldata);
        
        memset(line,0,sizeof(line));
    }
    
    if(ret.second)
    {
        assert(ret.first<=sizeof(line)-1);
        assert(!line[ret.first] && !line[sizeof(line)-1]);
        assert(validate_line(line,ret.first));
        
        ldata=parse_line(line,ret.first);
        
        if(ldata.size()>0)
            v.push_back(ldata);
    }
    else
    {
        fprintf(stderr,"file read termianted without eof!\n");
        abort();
    }
    
    if(fclose(f)<0)
    {
        perror("fclose");
        abort();
    }
    return v;
}

static bool validate_line(const char* line,long len)
{
    for(long i=0;i<len;i++)
    {
        if((line[i]<'0' || line[i]>'9') && line[i]!='-' && line[i]!='+' && line[i]!='.' && line[i]!=',' && line[i]!=' ' && line[i]!='\t' && line[i]!='\r' && line[i]!='e' && line[i]!='E')
        {
            return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& os,const vector<double>& v)
{
    os << "{ ";
    for(vector<double>::const_iterator cit=v.cbegin();cit!=v.cend();cit++)
    {
        if(cit!=v.cbegin())
            os << ", ";
        os << *cit;
    }
    os << " }";
    
    return os;
}


ostream& operator<<(ostream& os,const vector<vector<double>>& v)
{
    for(vector<vector<double>>::const_iterator cit=v.cbegin();cit!=v.cend();cit++)
    {
        os << *cit << endl;
    }
    return os;
}
