#include <iostream>
#include<bits/stdc++.h>
#include"defineFunctions.h"

using namespace std;
typedef  std::vector <int >::iterator iterate;

void OPTIMAL(vector<int> frames,vector<int> vect,int noFrames)
{

    int index=0,countFault=0;
    int startElement=0;
    int x=1,y=1,noFault=0;
    int prevFault=0;
    bool found,foundFull;

    cout<<"Replacement Policy = OPTIMAL"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Page   "<<"Content of Frames"<<endl;
    cout<<"----   -----------------"<<endl;

    for(int i=0; i<vect.size(); i++) // to check element in frame or not
    {
        found=false;
        foundFull=false;
        if(startElement==0)  //no element inserted yet
        {

            frames[index]=vect[i];
            index=(index+1)%noFrames;
            startElement++;
        }
        else if(x<frames.size())
        {
            //there are elements in frame

            for(int k=0; k<index; k++)
            {
                //check if element in frames

                if(frames[k]==vect[i])
                {
                    found=true;
                    x--;
                    y--;
                    break;
                }

            }
            if(found==false)
            {

                frames[index]=vect[i];
                index=(index+1)%noFrames;


            }
            x++;
        }
        else  //frame full
        {
            for(int m=0; m<frames.size(); m++) //check if page already exists in frame or not
            {

                if(frames[m]==vect[i])
                {
                    foundFull=true;
                }
            }
             if (foundFull==false){ //we replace the page in frame that will not be used for
                                    //the longest period of time in the future

                prevFault=noFault;
                int IterNumberCheck=i+1;
                int currentIndex = -1;
                int farthest = IterNumberCheck;
                int j;
                for (int l = 0; l < frames.size(); l++)
                {
                    for ( j =IterNumberCheck; j <vect.size(); j++)
                    {
                        if (frames[l] == vect[j])
                        {
                            if (j > farthest)
                            {
                                farthest = j;
                                currentIndex = l;
                            }
                            break;
                        }
                    }


                    if (j == vect.size())//page is not  used in future so we replace its index with the new page refrenced
                    {
                        currentIndex=l;
                        break;
                    }

                }
                if(currentIndex==-1)  //no page in frames used in future so we replace it with index=0
                {

                    frames[0]=vect[i];
                    noFault++;

                }
                else //replace this page in frame which is not used in future
                {

                    frames[currentIndex]=vect[i];
                    noFault++;

                }
              }

            }
            if(prevFault==noFault)
            {
                if (vect[i]<10)
                {
                    cout<<"0"<<vect[i]<< "     ";
                }
                else
                {
                    cout<<vect[i]<< "     ";
                }
            }
            else
            {

                if (vect[i]<10)
                {
                    cout<<"0"<<vect[i]<<" F"<< "   ";
                }
                else
                {
                    cout<<vect[i]<< "   ";
                }
                prevFault=noFault; // update prevFault value

            }
            for(int i=0; i<min(y,(int)frames.size()); i++)
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
            y++;
        }

        cout<<"-------------------------------------"<<endl;
        cout<<"Number of page faults = "<<noFault<<endl;

    }
