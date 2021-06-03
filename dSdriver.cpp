#include<iostream>
#include<fstream>
#include"linkedList.h"
//#include"sort.h"
#include"randomNumberGenerator.h"
using namespace std;

int main()
{
    linked_list list;
    fstream myfile;
    int option = 0;
    char genNewData = 'N';
    cout<<"Data structures:"<<endl;
    cout<<"1. Singly Linked List"<<endl;
    cout<<"Option: ";
    cin>>option;
    switch (option)
    {
        case 1:
        {
            cout<<"\n\nGenerate new data ?(Y/N): ";
            cin>>genNewData;
            if(genNewData == 'Y' || genNewData == 'y')
            {
                cout<<"\n\nGENERATING NEW DATA\n\n";
                generateRandomNumbers();
                int temp = 0;
                myfile.open("data.txt", ios::in);
                while(!myfile.eof())
                {
                    myfile>>temp;
                    list.insertAtEnd(temp);
                }
                myfile.close();
                list.deleteLast();
                list.traverse();
            }
            else
            {
                int temp = 0;
                myfile.open("data.txt", ios::in);
                while(!myfile.eof())
                {
                    myfile>>temp;
                    list.insertAtEnd(temp);
                }
                myfile.close();
                list.deleteLast();
                list.traverse();
                list.sort();
                list.traverse();
            }
            break;
        }
    }
}