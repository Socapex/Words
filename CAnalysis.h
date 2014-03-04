//
//  CAnalysis.h
//  Words
//
//  Created by Philippe Groarke on 2014-03-04.
//  Copyright (c) 2014 Groarke & Co. All rights reserved.
//

#ifndef __Words__CAnalysis__
#define __Words__CAnalysis__

#include <iostream>
#include <iomanip>

#include "CMap.h"

using namespace std;

class CAnalysis {
public:
    CAnalysis(CMap& map);

    void PrintMostUsed(const int &num);
    CMap& GetMostUsed();


private:
    CMap* _map;
};

#endif /* defined(__Words__CAnalysis__) */
