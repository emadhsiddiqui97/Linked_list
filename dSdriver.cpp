#include<iostream>
#include<fstream>
#include"linkedList.h"
#include"sort.h"
#include"randomNumberGenerator.h"
using namespace std;

int main()
{
    
    fstream myfile;
    int option = 0;
    char genNewData = 'N';
    cout<<"Data structures:"<<endl;
    cout<<"1. Singly Linked List"<<endl;
    cout<<"2. Array"<<endl;
    cout<<"Option: ";
    cin>>option;
    switch (option)
    {
        case 1:
        {
            linked_list list;
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
        case 2:
        {
            int size=60, i=0;
            int array[60] = {0};
            cout<<"\n\nGenerate new data ?(Y/N): ";
            cin>>genNewData;
            if(genNewData == 'Y' || genNewData == 'y')
            {
                i=0;
                cout<<"\n\nGENERATING NEW DATA\n\n";
                generateRandomNumbers();
                int temp = 0;
                myfile.open("data.txt", ios::in);
                while(!myfile.eof())
                {
                    myfile>>array[i];
                    i++;
                }
                myfile.close();

            }
            else
            {
                i=0;
                int temp = 0;
                myfile.open("data.txt", ios::in);
                while(!myfile.eof())
                {
                    myfile>>array[i];
                    i++;
                }
                myfile.close();
            }
            cout<<"\nChoose sorting method"<<endl;
            cout<<"1. Simple bubble sort"<<endl;
            cout<<"Option: ";
            cin>>option;
            switch (option)
            {
            case 1:
                {
                    int size = sizeof(array)/sizeof(array[0]);
                    cout<<array[0];
                    simpleBubbleSort(array, size);
                    cout<<"Sorted data: "<<endl;
                    for(int j=0;j<size;j++)
                        cout<<array[i]<<", ";
                    break;
                }
                
            
            default:
                break;
            }
            break;
        }
    }
    return 0;
}