#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <time.h>

#include "CMap.h"

using namespace std;

int main()
{
    CWord word;
    CString* s = (CString*)( word.GetAttribute( ATT_STRING ) );
    cout << s->GetString() << endl;

    CCount* c = (CCount*)( word.GetAttribute( ATT_COUNT ) );
    cout << c->GetCount() << endl;

    return 0;
}
