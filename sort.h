#include<iostream>
using namespace std;

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void simpleBubbleSort(linked_list *list)
{
    node *index = new node();
    node *current = new node();
    for(int i=0;i<list->length-1;i++)
    {
        
        for(int j=0;j<list->length-1;j++)
        {
            if(list->data > list->next->data)
            {
                swap(current, next);
            }
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