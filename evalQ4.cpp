#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
	string data;
	Node* next;
	Node* child;
	int stock;
	Node()
	{
		next = NULL;
		child = NULL;
	}
	Node(string s, int n)
	{
		data = s;
		stock = n;
		next = NULL;
		child = NULL;
	}
};

bool checkPresent(Node* head, string s)
{
	if(head == NULL)
	{
		return false;
	}
	Node* temp = head;
	while(temp != NULL && temp -> data != s)
	{
		temp = temp -> next;
	}
	if(temp == NULL)
	{
		return false;
	}
	return true;
}

bool isThere(Node* head, string s)
{
	if(s.length() == 2)
	{
		return checkPresent(head, s);
	}
	else if(s.length() == 4)
	{
		string ab = s.substr(0, 2);
		string cd = s.substr(2, 2);
		bool p1 = checkPresent(head, ab);
		if(p1)
		{
			Node* temp = head;
			while(temp -> data != ab)
			{
				temp = temp -> next;
			}
			return checkPresent(temp -> child, cd);
		}
		return false;
	}
	else if(s.length() == 6)
	{
		string ab = s.substr(0, 2);
		string cd = s.substr(2, 2);
		string ef = s.substr(4, 2);
		bool p1 = checkPresent(head, ab);
		if(p1)
		{
			Node* temp1 = head;
			while(temp1 -> data != ab)
			{
				temp1 = temp1 -> next;
			}
			bool p2 = checkPresent(temp1 -> child, cd);
			if(p2)
			{
				Node* temp2 = temp1 -> child;
				while(temp2 -> data != cd)
				{
					temp2 = temp2 -> next;
				}
				return checkPresent(temp2 -> child, ef);
			}
			return false;
		}
		return false;
	}
	return false;
}

int findLength(Node* head)
{
	int len = 0;
	while(head != NULL)
	{
		len++;
		head = head -> next;
	}
	return len;
}

Node* getNode(Node*& head, int pos)
{
	Node* temp = head;
	while(pos--)
	{
		temp = temp -> next;
	}
	return temp;
}

void insertAtTail(Node*& head, string s, int n)
{
	Node* new_Node = new Node(s, n);
	if(head == NULL)
	{
		head = new_Node;
	}
	else
	{
		Node* temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = new_Node;
	}
}

void deleteNode(Node*& head, string s)
{
	if(head -> data == s)
	{
		Node* temp = head;
		head = head -> next;
		delete temp;
	}
	else
	{
		Node* curr = head -> next;
		Node* prev = head;
		while(curr -> data != s)
		{
			curr = curr -> next;
			prev = prev -> next;
		}
		prev -> next = curr -> next;
		delete curr;
	}
}

void updateNode(Node*& head, string s, int n)
{
	Node* temp = head;
	while(temp -> data != s)
	{
		temp = temp -> next;
	}
	temp -> stock = temp -> stock + n;
	if(temp -> stock == 0)
	{
		deleteNode(head, temp -> data);
	}
}

void insertMainProduct(Node*& head, string ab, int n)
{
	if(!checkPresent(head, ab))
	{
		insertAtTail(head, ab, n);
	}
	else
	{
		updateNode(head, ab, n);
	}
}

void insertSubCategory(Node*& head, string ab, string cd, int n)
{
	Node* temp = head;
	while(temp -> data != ab)
	{
		temp = temp -> next;
	}
	if(!checkPresent(temp -> child, cd))
	{
		insertAtTail(temp -> child, cd, n);
	}
	else 
	{
		updateNode(temp -> child, cd, n);
	}
}

void insertSubSubCategory(Node*& head, string ab, string cd, string ef, int n)
{
	Node* temp1 = head;
	while(temp1 -> data != ab)
	{
		temp1 = temp1 -> next;
	}
	Node* temp2 = temp1 -> child;
	while(temp2 -> data != cd)
	{
		temp2 = temp2 -> next;
	}
	if(!checkPresent(temp2 -> child, ef))
	{
		insertAtTail(temp2 -> child, ef, n);
	}
	else
	{
		updateNode(temp2 -> child, ef, n);
	}
}

int findMainStock(Node*& head, string ab)
{
	Node* temp = head;
	while(temp -> data != ab)
	{
		temp = temp -> next;
	}
	return temp -> stock;
}

int findSubCategoryStock(Node*& head, string ab, string cd)
{
	Node* temp = head;
	while(temp -> data != ab)
	{
		temp = temp -> next;
	}
	temp = temp -> child;
	while(temp -> data != cd)
	{
		temp = temp -> next;
	}
	return temp -> stock;
}

int findSubSubCategoryStock(Node*& head, string ab, string cd, string ef)
{
	Node* temp = head;
	while(temp -> data != ab)
	{
		temp = temp -> next;
	}
	temp = temp -> child;
	while(temp -> data != cd)
	{
		temp = temp -> next;
	}
	temp = temp -> child;
	while(temp -> data != ef)
	{
		temp = temp -> next;
	}
	return temp -> stock;
}

void traverse(Node* head, map <string, int>& prod_to_stock, vector <string>& prods)
{
	Node* temp1 = head;
	while(temp1)
	{
		prod_to_stock[temp1 -> data] = temp1 -> stock;
		Node* temp2 = temp1 -> child;
		while(temp2)
		{
			prod_to_stock[temp1 -> data + temp2 -> data] = temp2 -> stock;
			prods.push_back(temp1 -> data + temp2 -> data);
			temp2 = temp2 -> next;
		}
		temp1 = temp1 -> next;
	}
}

void merge(Node*& head, int n, int m)
{
	Node* a = getNode(head, n);
	Node* b = getNode(head, m);
	if((a -> data)[0] != '0' || (b -> data)[0] != '0')
	{
		return;
	}
	string ab_new = (a -> data).substr(1, 1) + (b -> data).substr(1, 1);
	int stock_new = a -> stock + b -> stock;

	Node* a_cat = a -> child;
	Node* b_cat = b -> child;

	map <string, int> prod_to_stock;
	vector <string> prods;
	traverse(b_cat, prod_to_stock, prods);

	for(string x_data: prods)
	{
		int x_stock = prod_to_stock[x_data];
		string x_cd = x_data.substr(0, 2);
		string x_ef = x_data.substr(2, 2);
		insertSubCategory(head, a -> data, x_cd, x_stock);
		insertSubSubCategory(head, a -> data, x_cd, x_ef, x_stock);
	}

	sort(ab_new.begin(), ab_new.end());
	a -> data = ab_new;
	a -> stock = stock_new;
	deleteNode(head, b -> data);
}

void print(Node* head)
{
	while(head)
	{
		string ab = head -> data;
		Node* cat = head -> child;
		while(cat)
		{
			string cd = cat -> data;
			Node* sub = cat -> child;
			while(sub)
			{
				cout << ab << cd << sub -> data << " " << sub -> stock << endl;
				sub = sub -> next;
			}
			cat = cat -> next;
		}
		head = head -> next;
	}
}

int main()
{
	int q;
	cin >> q;
	Node* head = NULL;
	while(q--)
	{
		char op;
		cin >> op;
		if(op == 'I')
		{
			string s;
			int n;
			cin >> s >> n;
			string ab = s.substr(0, 2);
			string cd = s.substr(2, 2);
			string ef = s.substr(4, 2);
			if(n >= 0)
			{
				insertMainProduct(head, ab, n);
				insertSubCategory(head, ab, cd, n);
				insertSubSubCategory(head, ab, cd, ef, n);
			}
			else
			{
				insertSubSubCategory(head, ab, cd, ef, n);
				insertSubCategory(head, ab, cd, n);
				insertMainProduct(head, ab, n);
			}
		}

		else if(op == 'M')
		{
			int n, m;
			cin >> n >> m;
			n--;
			m--;
			int len = findLength(head);
			merge(head, n % len, m % len);
		}

		else if(op == 'S')
		{
			string s;
			cin >> s;
			if(!isThere(head, s))
			{
				cout << "";
			}
			else
			{
				int stock;
				if(s.length() == 2)
				{
					stock = findMainStock(head, s);
				}
				else if(s.length() == 4)
				{
					string ab = s.substr(0, 2);
					string cd = s.substr(2, 2);
					stock = findSubCategoryStock(head, ab, cd);
				}
				else if(s.length() == 6)
				{
					string ab = s.substr(0, 2);
					string cd = s.substr(2, 2);
					string ef = s.substr(4, 2);
					stock = findSubSubCategoryStock(head, ab, cd, ef);
				}
				cout << stock << endl;
			}
		}

		else if(op == 'P')
		{
			print(head);
		}
	}
}