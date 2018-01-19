#include <iostream>
using namespace std;

struct varun          // node created
{
	int data;
	varun *next;
	varun()
	{
		data = 0;
		next = NULL;
	}
};

class kanna          // class declaration
{
private:
	varun *head, *tail;
public:
	kanna()          // constructor
	{
		head = NULL;
		tail = NULL;
		head = tail;
	}
	
	void insert(int n)     // function to insert a node at the end of the list
	{
		varun *temp = new varun;
		temp->data = n;
		temp->next = NULL;
		if (head == NULL) 
		{
			head = temp;
		}
		else 
		{
			tail->next = temp;
			tail = temp;
		}
	}
	
	void insertAt(int pos, int value)  // function to insert a node anywhere in the list
	{
		varun *previous,*current;
		varun *temp = new varun;
		current = head;
		int a=countItems();
		if(pos>a+1)
		cout<<"Exceeds number of nodes";
		else
		{
		for (int i = 1; i < pos; i++) 
		{
			previous = current;
			current = current->next;
		}
		previous->next = temp;
		temp->data = value;
		temp->next = current;
	    }
	}
	
	void display()    // function to display nodes
	{
		varun *temp = new varun;
		temp = head;
		while (temp != NULL) 
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
		
	}
	
	void deleteNode()  // function to delete node at the end
	{
		varun *previous, *current;
		previous=NULL;
		current = head;
		while(current->next != NULL) 
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
	}
	
	void deleteAt(int pos) // function to delete node at a specified position
	{
		varun *previous, *current;
		current = head;
		for (int i = 1; i < pos; i++) 
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}
	
	int countItems()     //function to count items
	{
		varun *current;
		current = head;
		int a=0;
		while(current->next!=NULL)
		{
			++a;
			current = current->next;	
		}
		cout<<a;
		return a;		
	}
};

int main()
{
	kanna a;
	a.insert(4);
	a.insert(6);
	a.insert(7);
	a.insert(12);
	a.insertAt(2,3);
	a.display();
	a.deleteNode();
	a.display();
	a.insert(3);
	a.display();
	a.deleteNode();
	a.display();
	a.deleteAt(2);
	a.display();
	a.countItems();
	return 0;
}
