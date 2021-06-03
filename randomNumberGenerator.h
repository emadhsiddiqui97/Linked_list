#include<iostream>
#include<fstream>
#include<math.h>
#include<time.h>
#include<string.h>
using namespace std;


int randomNumber()
{
    srand(time(NULL));
    int num = rand() % 100 + 1;
    return num;
}
void generateRandomNumbers()
{
    fstream myfile;
    int randNum[100];
    bool unique = true;
    int num = 0, temp = 0;
    string loading = "[          ]";
    for(int i=0;i<100;i++)
    {
        if(i==0)
        {
            randNum[i] = randomNumber();
            cout<<"\r\nProgress: "<<loading<<"\t"<<i+1<<"%";
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
                cout<<"Progress: "<<loading<<"\t"<<i+1<<"%";
            }
        }
        if(i%10 == 0)
        {
            loading[(i/10)+1] = '#';
        }
    }
    cout<<endl;
    myfile.open("data.txt", ios::out);
    for(int i=0;i<100;i++)
    {myfile<<randNum[i]<<endl;}
    myfile.close();
}