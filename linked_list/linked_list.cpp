#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

class linked_list {
	private:
		node *head, *tail;
	public:
		linked_list()
		{
			head = NULL;
			tail = NULL;
		}
		

		void add_node(int n)
		{
			node *tmp = new node;
			tmp->data = n;
			tmp->next = NULL;
			
			
			//If this is the first node
			if(head == NULL)
			{
				head = tmp;
				tail = tmp;
			}
			//if already node is present
			else
			{
				tail->next = tmp;
				tail = tail->next;
			}	
		} 
		
		void display_nodes()
		{
			node *temp;
			temp = head;
			
			while(temp != NULL)
			{
				cout << temp->data  <<endl;
				temp = temp->next;
			}
		}

		static void concat_lists(node *a, node *b)
		{
			if(a != NULL && b != NULL)
			{
				if(a->next == NULL)
					a->next = b;
				else
					concat_lists(a->next, b);
			}
			else
			{
				cout << "Either one of the list is NULL !!!!!" << endl;
			}
		}

		node* get_head(){
			return head;
		}

		void insert_at(int v, int p)
		{
			node *tmp = new node;
			tmp->data = v;
			tmp->next = NULL;
			if(p == 1)
			{
				tmp->next = head;
				head = tmp;
			}
			else
			{
				node *current = head;
				for(int i = 1; i < p -1; i++)
				{
					current = current->next;
				}

				tmp->next = current->next;
				current->next = tmp;
			}
		}

		void delete_node(int p)
		{
			node *tmp, *prev;
			tmp = head;
			if(p == 1)
			{
				//tmp = head;
				head = tmp->next;
			}
			else
			{
				for(int i = 1; i < p; i++)
				{
					prev = tmp;
					tmp = tmp->next;
				}
				prev->next = tmp->next;
			}
			delete tmp;
		}
		
		void delete_key(int k)
		{
			node *tmp, *prev;
			tmp = head;
			
			//Key is the first node
			if(tmp->data == k && tmp != NULL)
			{
				head = tmp->next;
				delete tmp;
				return;
			}	
			while( tmp-> next != NULL && tmp->data != k)
			{
				prev = tmp;
				tmp = tmp->next;
			}
			
			// Key not found
			if(tmp == NULL)
			{
				cout << "Key is not present in the list" << endl;
				return;
			}
			prev->next = tmp->next;
			delete tmp;
			
		}

		int display_length()
		{
			node *tmp;
			int length = 0;
			tmp = head;
			while(tmp != NULL)
			{
				length++;
				tmp = tmp->next;
			}
			return length;
		}

		void search_key(int k)
		{
			node *tmp = head;
			int found = 0, round = 0;
			while(tmp != NULL)
			{
				if( tmp->data == k )
				{
					found = 1;
					cout << "Key found at location " << round + 1;
					return;
				}
				round++;
				tmp = tmp->next;
			}
			if(found == 0)
			{
				cout << "Key is not present and search failed " << endl;
			}
		}
};

int main(){
	cout << "Listing the first list nodes" << endl;
	linked_list l;
	l.add_node(1);
	l.add_node(2);
	l.add_node(3);
	l.add_node(4);
	l.add_node(5);
l.display_nodes();
	//cout << "Listing the second list nodes" << endl;
	//linked_list h;
	//h.add_node(6);
//	h.add_node(7);
	//h.add_node(8);
	//h.add_node(9);
	//h.add_node(10);
	//h.display_nodes();
	//cout << "Now the result of concatination " << endl;
	//h.concat_lists(l.get_head(), h.get_head());
//	l.display_nodes();
//	cout << "Adding node at 6th position and displaying the new list" << endl;
//	l.insert_at(0, 6);
//	l.display_nodes();
//	cout << "Adding node at 1st position and displaying the new list" << endl;
//	l.insert_at(15, 1);
//	l.display_nodes();
//	l.delete_node(1);
//	cout << "List after deleting the 1st node "<< endl;
//	l.display_nodes();
//	cout << "List after deleting at position 2 "<< endl;
//	l.delete_node(2);
	//l.display_nodes();
	//l.delete_node(5);
//	l.delete_key(3);
//	l.delete_key(1);
//	l.delete_key(5);

	cout << "length of the list is " << l.display_length() << endl;
	l.display_nodes();
	cout << "Searching the list " << endl;
	l.search_key(3);
	l.search_key(5);
	l.search_key(13);
	return 0;
}
