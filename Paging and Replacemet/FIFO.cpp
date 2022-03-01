#include <iostream>
#include<bits/stdc++.h>
#include"defineFunctions.h"

using namespace std;


typedef  std::vector <int >::iterator iterate;


void FIFO(vector<int > frames, vector<int > arrayOfInputs,int noFrames)
{

    int index=0,countFault=0;
    int x=1,noFault=0;
    int prevFault=0;
    bool found;

   cout<<"Replacement Policy = FIFO"<<endl;
   cout<<"-------------------------------------"<<endl;
   cout<<"Page   "<<"Content of Frames"<<endl;
   cout<<"----   -----------------"<<endl;

    for(iterate iter = arrayOfInputs.begin(); iter != arrayOfInputs.end(); iter++)// to check element in frame or not
    {
      found=false;
      for(int j=0;j<frames.size();j++){

        if(frames[j]==*iter){
        found=true;
        x--;
        break;
        }
      }

      if (found==false){

        frames[index]=*iter ;
        countFault++; /// when countFault equals frame.size() then frame is full and now we calculate noFault pages
        index=(index+1)%noFrames;

       prevFault=noFault; /// for printing we store prevNofault to check if fault happens everytime we increament noFault so when
       /// prevFault not equal nofault so fault happens again and we print F besides page number
        if(countFault>frames.size())
        {

            noFault++;

        }
    }
      if(prevFault==noFault){
        if (*iter<10)
        {
            cout<<"0"<<*iter<< "     ";
        }
        else
        {
            cout<<*iter<< "     ";
        }
    }
    else{

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
        for(int i=0; i<min(x,(int)frames.size()); i++)
        {


            if (frames[i]<10)
            {
                cout<<"0"<<frames[i]<<" ";
            }
            else
            {
                cout<<frames[i]<<" ";

            }


      }
        cout<<endl;
        x++;
   }
        cout<<"-------------------------------------"<<endl;
        cout<<"Number of page faults = "<<noFault<<endl;

 }

