//
//  files.hpp
//  TT
//
//  Created by Ishan Shah on 3/2/20.
//  Copyright © 2020 Ishan Shah. All rights reserved.
//

#ifndef files_hpp
#define files_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <vector>
#include "csv.hpp"
#include "modulus.hpp"
#include "name.hpp"
using namespace std;



void em_dir(const char* const dir,const bool fcsv=false,const bool header=false);


#endif /* files_hpp */
