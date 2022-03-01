#include <iostream>
#include<bits/stdc++.h>
#include"defineFunctions.h"

using namespace std;


typedef  std::vector <int >::iterator iterate;


void CLOCK(vector<int> frames,vector<int> arrayOfInputs,int noFrames)
{

    vector<int> bit(noFrames);
    int x=1,index=0;
    int y=1;
    int pointer=0;
    int noFault=0;
    int startElement=0;
    int prevFault=0;
    bool found,foundFull;



    cout<<"Replacement Policy = CLOCK"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Page   "<<"Content of Frames"<<endl;
    cout<<"----   -----------------"<<endl;

    for(iterate iter = arrayOfInputs.begin(); iter != arrayOfInputs.end(); iter++)
    {
        found=false;
        foundFull=false;
        if (startElement==0)  //for inserting first element in frames
        {

            frames[index]=*iter;
            bit[index]=1;
            index=(index+1)%noFrames;
            pointer=(pointer+1)%noFrames;
            startElement++;


        }
        else if(x<frames.size())  // if frames not full check wether page in frames so found =true and check if used bit=0
            // change it to bit=1
        {
            for(int i=0; i<index; i++)
            {

                if(frames[i]==*iter)
                {
                    found=true;
                    y--;
                    x--;
                    if(bit[i]==0)
                    {
                        bit[i]=1;


                    }
                }

            }
            if(found==false) //page not in frame so insert it
            {
                frames[index]=*iter;
                bit[index]=1;
                index=(index+1)%noFrames;
                pointer=(pointer+1)%noFrames;

            }
            x++;
        }
        else //frames full
        {

            for(int i=0; i<frames.size(); i++)// check page found in frames or not and check its usedbit
            {

                if(frames[i]==*iter)
                {
                    foundFull=true;
                    if(bit[i]==0)
                    {
                        bit[i]=1;

                    }

                }
            }
            if(foundFull==false)//element not found in frames so we replace
            {
                prevFault=noFault; //for printing F besides page
                if(bit[pointer]==0)
                {

                    frames[pointer]=*iter;
                    bit[pointer]=1;
                    pointer=(pointer+1)%noFrames;
                    noFault++;



                }
                else
                {
                    bit[pointer]=0;
                    pointer=(pointer+1)%noFrames;
                    while(bit[pointer])
                    {
                        bit[pointer]=0;
                        pointer=(pointer+1)%noFrames;

                    }
                    frames[pointer]=*iter;
                    bit[pointer]=1;
                    pointer=(pointer+1)%noFrames;
                    noFault++;

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
            prevFault=noFault;
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
