#include<iostream>
#include<fstream>
using namespace std;

fstream myfile;

void swap(int *a, int *b)
{
    int &temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int array[], int size)
{
    myfile.open("data.txt", ios::in);
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<", ";
        myfile<<array[i]<<endl;
    }
    myfile.close();
}

void simpleBubbleSort(int array[], int size)
{
    //int i=0;
    // myfile.open("data.txt", ios::in);
    // while(myfile.eof())
    // {
    //     myfile>>array[i];
    //     i++;
    // }
    // myfile.close();
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(array[j] > array[j+1])
                {swap(&array[j], &array[j+1]);}
        }
    }
}



// node *index = new node();
// 			node *current = new node();
// 			int temp;
// 			for(int i=0;i<length;i++)
// 			{
// 				index = head;
// 				current = index->next;
// 				while(current != NULL)
// 				{
// 					if(index->data > current->data)
// 					{
// 						temp = index->data;
// 						index->data = current->data;
// 						current->data = temp;
// 					}
// 					else
// 					{
// 						index = index->next;
// 						current = current->next;
// 					}
// 				}
// 			}



