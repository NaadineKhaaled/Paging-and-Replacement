#include <iostream>
#include<bits/stdc++.h>
#include"defineFunctions.h"

using namespace std;
typedef  std::vector <int >::iterator iterate;

int main()
{


    int n,m;
    int counter=0;
    string alg;
    vector<int > arrayOfInputs;
    cin>>n; //no of frames
    vector<int > frames(n);
    cin>>alg; // algorithm
    cin>>m; //array of elements
    counter++;

    while(m>=0)
    {
        arrayOfInputs.push_back(m);
        cin>>m;
        counter++;
    }
    counter--; // for eleminating count of element -1

    if(alg=="FIFO")
    {

        FIFO(frames,arrayOfInputs,n);

    }
     else if(alg=="LRU")
    {

        LRU(frames,arrayOfInputs,n);

    }
      else if(alg=="CLOCK")
    {

        CLOCK(frames,arrayOfInputs,n);

    }
     else
    {
       vector<int> arr(counter);
       int i=0;
       for(iterate iter = arrayOfInputs.begin(); iter != arrayOfInputs.end(); iter++)
       {
          arr[i]=*iter;
          i++;
       }
       OPTIMAL(frames,arr,n);
    }

    return 0;
}
