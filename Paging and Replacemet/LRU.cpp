#include <iostream>
#include<bits/stdc++.h>
#include"defineFunctions.h"

using namespace std;


typedef  std::vector <int >::iterator iterate;


void LRU(vector<int> frames,vector<int> arrayOfInputs,int noFrames)
{
    int timee=1;
    int noFault=0;
    int prevFault=0;
    bool found;
    vector<pair<int,pair<int,int>>> v;
    vector<pair<int,pair<int,int>>> v2;


    cout<<"Replacement Policy = LRU"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Page   "<<"Content of Frames"<<endl;
    cout<<"----   -----------------"<<endl;

    priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >pq;
    // pair<int,pair<int,int>
    //      time   element, order
    int order = 1;
    for(iterate iter = arrayOfInputs.begin(); iter != arrayOfInputs.end(); iter++)
    {
        found=false;

        if(pq.empty()) //for inserting first element and saving its order for replacing it
            //with another element to take its order in printing
        {

            pair<int,pair<int,int>> p;
            p.first=timee++;
            p.second.first=*iter;
            p.second.second = order++;
            pq.push(p);

        }

        else
        {

         while(!pq.empty())
            {

                pair<int,pair<int,int>> current = pq.top();
                pq.pop();
                if(current.second.first == *iter) //check if element exists and inc its time to be MostRecentlyUsed
                {

                    current.first = timee++;
                    v.push_back(current);
                    found = true;
                    break;
                }
                else
                {
                    v.push_back(current);
                }
            }
            for(auto pair : v)
            {
                pq.push(pair);
            }
            if(found == false) //if element not in frames
            {
                if(pq.size()<noFrames) // if there's enough place in frames we insert the element in min heap(priority_queue)
                {

                    pair<int,pair<int,int>> p1;
                    p1.first=timee++; // inc time so the inserted element be the MRU
                    p1.second.first=*iter;
                    p1.second.second = order++;
                    pq.push(p1);
                }
                else //no space in frames so we chose the leastRecentlyUsed element from time by eliminating top of
                    // priority_queue and replace it by taking its Order to print it in its same position

                {
                    prevFault=noFault; //for printing F besides page number
                    int prevOder = pq.top().second.second;
                    pq.pop();
                    pair<int,pair<int,int>> p2;
                    noFault++;
                    p2.first=timee++;
                    p2.second.first=*iter;
                    p2.second.second = prevOder;
                    pq.push(p2);

                }
            }

        }
        if(prevFault==noFault)
        {
            if (*iter<10)
            {
                cout<<"0"<<*iter<< "     ";
            }
            else
            {
                cout<<*iter<< "     ";
            }
        }
        else
        {

            if (*iter<10)
            {
                cout<<"0"<<*iter<<" F"<< "   ";
            }
            else
            {
                cout<<*iter<< "   ";
            }
            prevFault=noFault; // update prevFault value

        }
        vector<pair<int,pair<int,int>>> to_print;
        while(!pq.empty())
        {
            pair<int,pair<int,int>> top = pq.top();
            pq.pop();
            to_print.push_back(top);

        }
        sort(to_print.begin(),to_print.end(), [](auto a, auto b)
        {
            return a.second.second<b.second.second;
        });


        for(auto top : to_print)
        {
            if (top.second.first<10)
            {
                cout<<"0"<<top.second.first<<" ";
            }
            else
            {
                cout<<top.second.first<<" ";

            }
            v2.push_back(top);
        }
        for(auto pair : v2)
        {
            pq.push(pair);
        }
        cout<<endl;

        v.clear();
        v2.clear();
        to_print.clear();
    }


    cout<<"-------------------------------------"<<endl;
    cout<<"Number of page faults = "<<noFault<<endl;
}





/* vector<int> priorityArray(noFrames);
      int index=0,initialCounter=0,x=1;
      bool flag,startingFlag;
      int lru,currentIndex;

      typedef  std::vector <int >::iterator iterate;

      for(iterate iter = arrayOfInputs.begin(); iter != arrayOfInputs.end(); iter++)
      {
          flag=1,startingFlag=1;;

          if(initialCounter<frames.size())
          {
              initialCounter++;

              for(int j=0; j<index; j++)
              {
                if(*iter==frames[j])
                  {
                      startingFlag=0;
                      priorityArray[j]--;
                      x--;
                      initialCounter--;
                      for(int i=0; i<index; i++)
                      {

                          if(j!=i)
                          {
                              priorityArray[i]++;
                          }
                      }
                  }
              }
              if (startingFlag){

                  frames[index]=*iter;
                  priorityArray[index]=1;

                  for(int i=0; i<index; i++)
                  {

                      priorityArray[i]++;

                  }
                  index=(index+1)%noFrames;
                 }
          }
          else
          {

              for(int j=0; j<frames.size(); j++)
              {

                  if(*iter==frames[j])
                  {
                      priorityArray[j]--;
                      flag=0;
                      for(int i=0; i<frames.size(); i++)
                      {

                          if(j!=i)
                          {
                              priorityArray[i]++;
                          }
                      }
                      break;
                  }
              }

              if(flag)
              {
                  lru=priorityArray[0];
                  currentIndex=0;

                  for(int i=1; i<frames.size(); i++)
                  {
                      if(lru<priorityArray[i])
                      {
                            lru=priorityArray[i];
                          currentIndex=i;
                      }
                  }
                  frames[currentIndex]=*iter;
                  priorityArray[currentIndex]=1;

                  for(int i=0; i<frames.size(); i++)
                  {

                      if(i!=currentIndex)
                      {
                          priorityArray[i]++;
                      }
                  }


              }
          }

    */
