#include<iostream>
#include<fstream>
#include<math.h>
#include<time.h>
#include<string.h>
using namespace std;


void loadingBar(int iteration, int total)
{
    int percentage = (iteration/total)*100;
    cout<<"\r";
    cout<<"Progress "<<percentage<<"%: ";
    for(int j=0;j<percentage;j++)
        {cout<<"\u275A";}
}

int randomNumber()
{
    srand(time(NULL));
    int num = rand() % 60 + 1;
    return num;
}
void generateRandomNumbers()
{
    fstream myfile;
    int randNum[60];
    bool unique = true;
    int num = 0, temp = 0;
    int percentage = 0;
    //string loading = "[          ]";
    for(int i=0;i<60;i++)
    {
        percentage = ((i+1)*100)/60;
        if(i==0)
        {
            randNum[i] = randomNumber();
            //cout<<"\r\nProgress: "<<loading<<"\t"<<i+1<<"%";
                cout<<"\r";
                cout<<"Progress: ";
                for(int j=0;j<percentage;j++)
                {
                    cout<<"\u275A";
                }
            //loadingBar(i+1, 100);
        }
        else
        {
            do
            {
                num = randomNumber();
                if(temp != num)
                {
                    for(int j=0;j<i;j++)
                    {
                        if(randNum[j] == num)
                        {unique = false;}
                        else
                        {
                            unique = true;
                            temp = num;
                        }
                    }
                }
                else{unique = false;}
                
            }while(unique == false);
            if(unique == true)
            {
                randNum[i] = num;
                 cout<<"\r";
                 cout<<"Progress "<<percentage<<"%: ";
                 for(int j=0;j<percentage;j++)
                 {
                     cout<<"\u275A";
                 }
                //cout<<"\t"<<percentage<<"%";
                //loadingBar(i+1, 100);
            }
        }
        // if(i%10 == 0)
        // {
        //     loading[(i/10)+1] = '#';
        // }
    }
    cout<<endl;
    myfile.open("data.txt", ios::out);
    for(int i=0;i<60;i++)
    {myfile<<randNum[i]<<endl;}
    myfile.close();
}