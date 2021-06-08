#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
		node(){}
};

class linked_list
{
	public:
	node *head, *tail;
	int length = 0;
		linked_list()
		{
			head = NULL;
			tail = NULL;
		}
		node* returnHead()
		{
			return head;
		}
		void insertAtEnd(int new_data)
		{
			node *temp = new node();
			temp->data = new_data;
			temp->next = NULL;
			if(head == NULL)
			{
				head = temp;
				tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = tail->next;
			}
		}
		void traverse()
		{
			int count = 0;
			if(head == NULL)
			{
				cout<<"List is empty"<<endl;
			}
			node *temp = head;
			while(temp != NULL)
			{
				cout<<temp->data<<", ";
				temp = temp->next;
				count++;
			}
			length = count;
			cout<<"\nNumber of elements: "<<count<<endl;
		}
		void insertAtFront(int new_data)
		{
			node *temp = new node();
			if(head == NULL)
			{
				head = temp;
				temp->data = new_data;
				temp->next = NULL;
				tail = temp;
			}
			else
			{
				temp->next = head;
				temp->data = new_data;
				head = temp;
			}
		}
		void insertAtPosition(int pos, int new_data)
		{

			int count = 1;
			node *new_node = new node();
			node *temp = new node();
			temp = head;
			while(count != pos)
			{
				temp = temp->next;
				count++;
			}
			new_node->data = new_data;
			new_node->next = temp->next;
			temp->next = new_node;

		}
		void deleteFirst()
		{
			if(head == NULL){return;}
			else if(head == tail)
			{
				node *temp = new node();
				temp = head;
				head = NULL;
				tail = NULL;
				delete temp;
			}
			else
			{
				node *temp = new node();
				temp = head;
				head = head->next;
				delete temp;
			}
		}
		void deleteLast()
		{
			node *temp = new node();
			temp = head;
			while(temp->next->next != NULL)
				{temp = temp->next;}
			tail = temp;
			tail->next = NULL;
			temp = NULL;
			delete temp;
		}
		void deletePosition(int pos)
		{
			int count = 1;
			node *temp = new node();
			node *temp2 = new node();
			temp = head;
			while(count != pos-1)
				{temp = temp->next;count++;}
			temp2 = temp;
			temp2->next = temp->next->next;
			temp = NULL;
			delete temp;
		}
		int maximum()
		{
			int max = 0;
			node *temp = new node();
			temp = head;
			while(temp != NULL)
			{
				if(temp->data > max)
					{max = temp->data;}
				temp = temp->next;
			}
			return max;
		}
		node *reverseLL(node *temp)
		{
			if (temp == NULL) 
            	return NULL; 
			if (temp->next == NULL) { 
				head = temp; 
				return temp; 
			} 
			node* temp2 = reverseLL(temp->next); 
			temp2->next = temp; 
			temp->next = NULL; 
			return temp; 
		}
		void sort()
		{
			node *index = new node();
			node *current = new node();
			int temp;
			for(int i=0;i<length-1;i++)
			{
				index = head;
				current = index->next;
				for(int j=0;j<length-1;j++)
				{
					if(index->data > current->data)
					{
						temp = index->data;
						index->data = current->data;
						current->data = temp;
					}
					else
					{
						index = index->next;
						current = current->next;
					}
				}
			}

		}
		float average()
		{
			node *temp = new node();
			float avg = 0;
			temp = head;
			while(temp != NULL)
			{
				avg += temp->data;
				temp = temp->next;
			}
			return avg/length;
		}
		void createList(linked_list *obj)
		{
			int elements = 0, number = 0;
			cout<<"Create a linked list\n";
			cout<<"Enter number of elements: ";
			cin>>elements;
			length = elements;
			for(int i=0;i<elements;i++)
			{
				cout<<"Enter number: ";
				cin>>number;
				obj->insertAtEnd(number);
			}
			//print data
			system("cls");
			cout<<"Data: ";
			obj->traverse();
		}
};	