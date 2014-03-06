//
//  CAnalysis.cpp
//  Words
//
//  Created by Philippe Groarke on 2014-03-04.
//  Copyright (c) 2014 Groarke & Co. All rights reserved.
//

#include "CAnalysis.h"

CAnalysis::CAnalysis(CMap& map)
{
	DEBUG_FCT

    _map = &map;
}

void CAnalysis::PrintMostUsed(const int &num)
{
	DEBUG_FCT

    vector< pair<CTYPE> > myVec(_map->GetMap().begin(), _map->GetMap().end());

    sort( myVec.begin(), myVec.end(), &orderCMapByCount );

    cout << endl << setw(15) << left << "Count" << "Word" << endl;
        cout << setw(15) << left << "-----" << "----" << endl;
    for (int i = 0; i < num; ++i)
    {
        cout << setw(15) << left << myVec[i].second.GetWord().GetCount()
            << myVec[i].first << endl;
    }

    cout << endl;
}

void CAnalysis::PrintSorted(ostream& stream)
{
	DEBUG_FCT

	vector< pair<CTYPE> > myVec(_map->GetMap().begin(), _map->GetMap().end());
	sort(myVec.begin(), myVec.end(), &orderCMapByCount);

	stream << setw(8) << left << "Count" << "Word" << endl;
	stream << setw(8) << left << "-----" << "----" << endl;
	
	for (auto n : myVec)
	{
		stream << setw(5) << right << n.second.GetWord().GetCount() << setfill(' ')
			 << "   " << n.first << endl;
	}
	stream << endl;
}

