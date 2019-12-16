#include<iostream>
#include<conio.h>
using namespace std;

class queue {
private:
	struct node{
		int key[9],root;
		string move;
		node* next;
	}*head,*tail;
	int displacements(node* temp)
	{
		int count=0;
		for (int i = 1; i < 9; i++)
		{
			if (temp->key[i] != i)
				count++;
		}
		return count;
	}
	void process(node* temp, int count)
	{
		int displaced[4];
		bool check = true;
		for (int i = 0; i < 9; i++)
		{
			if (temp->key[i] != i)
			{
				check = false;
				break;
			}
		}
		if(count != 0)
			cout << "\n\nMove number "<<count<<", The blank space was moved " << temp->move;
		cout << "\n";
		for (int i = 0; i < 9; i++)
		{
			if(temp->key[i] != 0)
				cout << temp->key[i] << "  ";
			else	
				cout<<"-  ";	
			if (i == 2 || i == 5 || i == 8)
				cout << "\n";
		}
		if (check == true)
			{
				return;	
			}
		count++;
		if (temp->root == 0)
		{
			node* temp1 = new node, * temp2 = new node;
			for (int i = 0; i < 9; i++)
			{
				temp1->key[i] = temp->key[i];
				temp2->key[i] = temp->key[i];
			}
			temp1->move = "right";
			temp1->key[0] = temp1->key[1];
			temp1->key[1] = 0;
			temp1->root = 1;
			if (temp->move == "left")
				displaced[0] = 999;
			else
				displaced[0] = displacements(temp1);
			temp2->move = "down";
			temp2->key[0] = temp2->key[3];
			temp2->key[3] = 0;
			temp2->root = 3;
			if (temp->move == "up")
				displaced[1] = 999;
			else
				displaced[1] = displacements(temp2);
			if (displaced[0] < displaced[1])
				process(temp1,count);
			else
				process(temp2, count);
		}
		else if (temp->root == 1)
		{
			node* temp1 = new node, * temp2 = new node, * temp3 = new node;
			for (int i = 0; i < 9; i++)
			{
				temp1->key[i] = temp->key[i];
				temp2->key[i] = temp->key[i];
				temp3->key[i] = temp->key[i];
			}
			temp1->move = "right";
			temp1->key[1] = temp1->key[2];
			temp1->key[2] = 0;
			temp1->root = 2;
			if (temp->move == "left" )
				displaced[0] = 999;
			else
				displaced[0] = displacements(temp1);
			temp2->move = "down";
			temp2->key[1] = temp2->key[4];
			temp2->key[4] = 0;
			temp2->root = 4;
			if (temp->move == "up")
				displaced[1] = 999;
			else
				displaced[1] = displacements(temp2);
			temp3->move = "left";
			temp3->key[1] = temp3->key[0];
			temp3->key[0] = 0;
			temp3->root = 0;
			if (temp->move == "right" )
				displaced[2] = 999;
			else
				displaced[2] = displacements(temp3);
			if (displaced[0] < displaced[1] && displaced[0] < displaced[2])
				process(temp1, count);
			else if (displaced[1] < displaced[0] && displaced[1] < displaced[2])
				process(temp2, count);
			else if(displaced[2] < displaced[0] && displaced[2] < displaced[1])
				process(temp3, count);
			else if (displaced[0] == displaced[1] && displaced[0] < displaced[2])
				process(temp2, count);
			else if (displaced[0] == displaced[2] && displaced[0] < displaced[2])
				process(temp1, count);
			else if (displaced[1] == displaced[2] && displaced[1] < displaced[0])
				process(temp3, count);
			else
				process(temp3, count);
		}
		else if (temp->root == 2)
		{
			node* temp1 = new node, * temp2 = new node;
			for (int i = 0; i < 9; i++)
			{
				temp1->key[i] = temp->key[i];
				temp2->key[i] = temp->key[i];
			}
			temp1->move = "left";
			temp1->key[2] = temp1->key[1];
			temp1->key[1] = 0;
			temp1->root = 1;
			if (temp->move == "right")
				displaced[0] = 999;
			else
				displaced[0] = displacements(temp1);
			temp2->move = "down";
			temp2->key[2] = temp2->key[5];
			temp2->key[5] = 0;
			temp2->root = 5;
			if (temp->move == "up")
				displaced[1] = 999;
			else
				displaced[1] = displacements(temp2);
			if (displaced[0] < displaced[1])
				process(temp1, count);
			else
				process(temp2, count);
		}
		else if (temp->root == 3)
		{
			node* temp1 = new node, * temp2 = new node, * temp3 = new node;
			for (int i = 0; i < 9; i++)
			{
				temp1->key[i] = temp->key[i];
				temp2->key[i] = temp->key[i];
				temp3->key[i] = temp->key[i];
			}
			temp1->move = "right";
			temp1->key[3] = temp1->key[4];
			temp1->key[4] = 0;
			temp1->root = 4;
			if (temp->move == "left")
				displaced[0] = 999;
			else
				displaced[0] = displacements(temp1);
			temp2->move = "down";
			temp2->key[3] = temp2->key[6];
			temp2->key[6] = 0;
			temp2->root = 6;
			if (temp->move == "up")
				displaced[1] = 999;
			else
				displaced[1] = displacements(temp2);
			temp3->move = "up";
			temp3->key[3] = temp3->key[0];
			temp3->key[0] = 0;
			temp3->root = 0;
			if (temp->move == "down")
				displaced[2] = 999;
			else
				displaced[2] = displacements(temp3);
			if (displaced[0] < displaced[1] && displaced[0] < displaced[2])
				process(temp1, count);
			else if (displaced[1] < displaced[0] && displaced[1] < displaced[2])
				process(temp2, count);
			else if (displaced[2] < displaced[0] && displaced[2] < displaced[1])
				process(temp3, count);
			else if (displaced[0] == displaced[1] && displaced[0] < displaced[2])
				process(temp1, count);
			else if (displaced[0] == displaced[2] && displaced[0] < displaced[2])
				process(temp3, count);
			else if (displaced[1] == displaced[2] && displaced[1] < displaced[0])
				process(temp2, count);
			else
				process(temp1, count);
		}
		else if (temp->root == 4)
		{
			node* temp1 = new node, * temp2 = new node, * temp3 = new node, * temp4 = new node;
			for (int i = 0; i < 9; i++)
			{
				temp1->key[i] = temp->key[i];
				temp2->key[i] = temp->key[i];
				temp3->key[i] = temp->key[i];
				temp4->key[i] = temp->key[i];
			}
			temp1->move = "left";
			temp1->key[4] = temp1->key[3];
			temp1->key[3] = 0;
			temp1->root = 3;
			if (temp->move == "right")
				displaced[0] = 999;
			else
				displaced[0] = displacements(temp1);
			temp2->move = "right";
			temp2->key[4] = temp2->key[5];
			temp2->key[5] = 0;
			temp2->root = 5;
			if (temp->move == "left")
				displaced[1] = 999;
			else
				displaced[1] = displacements(temp1);
			temp3->move = "down";
			temp3->key[4] = temp3->key[7];
			temp3->key[7] = 0;
			temp3->root = 7;
			if (temp->move == "up")
				displaced[2] = 999;
			else
				displaced[2] = displacements(temp3);
			temp4->move = "up";
			temp4->key[4] = temp4->key[1];
			temp4->key[1] = 0;
			temp4->root = 1;
			if (temp->move == "down")
				displaced[3] = 999;
			else
				displaced[3] = displacements(temp3);
			if (displaced[0] < displaced[1] && displaced[0] < displaced[2] && displaced[0] < displaced[3])
				process(temp1, count);
			else if (displaced[1] < displaced[0] && displaced[1] < displaced[2] && displaced[1] < displaced[3])
				process(temp2, count);
			else if (displaced[2] < displaced[0] && displaced[2] < displaced[1] && displaced[2] < displaced[3])
				process(temp3, count);
			else if (displaced[3] < displaced[0] && displaced[3] < displaced[1] && displaced[3] < displaced[2])
				process(temp4, count);
			else if (displaced[0] == displaced[1] && displaced[0] < displaced[2] && displaced[0] < displaced[3])
				process(temp1, count);
			else if (displaced[0] == displaced[2] && displaced[0] < displaced[1] && displaced[0] < displaced[3])
				process(temp3, count);
			else if (displaced[0] == displaced[3] && displaced[0] < displaced[1] && displaced[0] < displaced[2])
				process(temp4, count);
			else if (displaced[1] == displaced[3] && displaced[1] < displaced[2] && displaced[1] < displaced[0])
				process(temp2, count);
			else if (displaced[1] == displaced[2] && displaced[1] < displaced[0] && displaced[1] < displaced[3])
				process(temp2, count);
			else if (displaced[2] == displaced[3] && displaced[2] < displaced[1] && displaced[2] < displaced[0])
				process(temp3, count);
			else if (displaced[0] == displaced[1] && displaced[0] == displaced[2] && displaced[0] < displaced[3])
				process(temp1, count);
			else if (displaced[3] == displaced[1] && displaced[3] == displaced[2] && displaced[3] < displaced[0])
				process(temp4, count);
			else if (displaced[0] == displaced[2] && displaced[0] == displaced[3] && displaced[0] < displaced[1])
				process(temp4, count);
			else
				process(temp4, count);
		}
		else if (temp->root == 5)
		{
			node* temp1 = new node, * temp2 = new node, * temp3 = new node;
			for (int i = 0; i < 9; i++)
			{
				temp1->key[i] = temp->key[i];
				temp2->key[i] = temp->key[i];
				temp3->key[i] = temp->key[i];
			}
			temp1->move = "left";
			temp1->key[5] = temp1->key[4];
			temp1->key[4] = 0;
			temp1->root = 4;
			if (temp->move == "right")
				displaced[0] = 999;
			else
				displaced[0] = displacements(temp1);
			temp2->move = "down";
			temp2->key[5] = temp2->key[8];
			temp2->key[8] = 0;
			temp2->root = 8;
			if (temp->move == "up")
				displaced[1] = 999;
			else
				displaced[1] = displacements(temp2);
			temp3->move = "up";
			temp3->key[5] = temp3->key[2];
			temp3->key[2] = 0;
			temp3->root = 2;
			if (temp->move == "down")
				displaced[2] = 999;
			else
				displaced[2] = displacements(temp3);
			if (displaced[0] < displaced[1] && displaced[0] < displaced[2])
				process(temp1, count);
			else if (displaced[1] < displaced[0] && displaced[1] < displaced[2])
				process(temp2, count);
			else if (displaced[2] < displaced[0] && displaced[2] < displaced[1])
				process(temp3, count);
			else if (displaced[0] == displaced[1] && displaced[0] < displaced[2])
				process(temp1, count);
			else if (displaced[0] == displaced[2] && displaced[0] < displaced[2])
				process(temp3, count);
			else if (displaced[1] == displaced[2] && displaced[1] < displaced[0])
				process(temp2, count);
			else
				process(temp3, count);
		}
		else if (temp->root == 6)
		{
			node* temp1 = new node, * temp2 = new node;
			for (int i = 0; i < 9; i++)
			{
				temp1->key[i] = temp->key[i];
				temp2->key[i] = temp->key[i];
			}
			temp1->move = "right";
			temp1->key[6] = temp1->key[7];
			temp1->key[7] = 0;
			temp1->root = 7;
			if (temp->move == "left")
				displaced[0] = 999;
			else
				displaced[0] = displacements(temp1);
			temp2->move = "up";
			temp2->key[6] = temp2->key[3];
			temp2->key[3] = 0;
			temp2->root = 3;
			if (temp->move == "down")
				displaced[1] = 999;
			else
				displaced[1] = displacements(temp2);
			if (displaced[0] < displaced[1])
				process(temp1, count);
			else
				process(temp2, count);
		}
		else if (temp->root == 7)
		{
			node* temp1 = new node, * temp2 = new node, * temp3 = new node;
			for (int i = 0; i < 9; i++)
			{
				temp1->key[i] = temp->key[i];
				temp2->key[i] = temp->key[i];
				temp3->key[i] = temp->key[i];
			}
			temp1->move = "left";
			temp1->key[7] = temp1->key[6];
			temp1->key[6] = 0;
			temp1->root = 6;
			if (temp->move == "right")
				displaced[0] = 999;
			else
				displaced[0] = displacements(temp1);
			temp2->move = "right";
			temp2->key[7] = temp2->key[8];
			temp2->key[8] = 0;
			temp2->root = 8;
			if (temp->move == "left")
				displaced[1] = 999;
			else
				displaced[1] = displacements(temp2);
			temp3->move = "up";
			temp3->key[7] = temp3->key[4];
			temp3->key[4] = 0;
			temp3->root = 4;
			if (temp->move == "down")
				displaced[2] = 999;
			else
				displaced[2] = displacements(temp2);
			if (displaced[0] < displaced[1] && displaced[0] < displaced[2])
				process(temp1, count);
			else if (displaced[1] < displaced[0] && displaced[1] < displaced[2])
				process(temp2, count);
			else if (displaced[2] < displaced[0] && displaced[2] < displaced[1])
				process(temp3, count);
			else if (displaced[0] == displaced[1] && displaced[0] < displaced[2])
				process(temp1, count);
			else if (displaced[0] == displaced[2] && displaced[0] < displaced[2])
				process(temp3, count);
			else if (displaced[1] == displaced[2] && displaced[1] < displaced[0])
				process(temp2, count);
			else
				process(temp2, count);
		}
		else if (temp->root == 8)
		{
			node* temp1 = new node, * temp2 = new node;
			for (int i = 0; i < 9; i++)
			{
				temp1->key[i] = temp->key[i];
				temp2->key[i] = temp->key[i];
			}
			temp1->move = "left";
			temp1->key[8] = temp1->key[7];
			temp1->key[7] = 0;
			temp1->root = 7;
			if (temp->move == "right")
				displaced[0] = 999;
			else
				displaced[0] = displacements(temp1);
			temp2->move = "up";
			temp2->key[8] = temp2->key[5];
			temp2->key[5] = 0;
			temp2->root = 5;
			if (temp->move == "down")
				displaced[1] = 999;
			else
				displaced[1] = displacements(temp2);
			if (displaced[0] < displaced[1])
				process(temp1, count);
			else
				process(temp2, count);
		}
	}
public:
	queue()
	{
		head = NULL;
		tail = NULL;
	}
	void insert(int puzzle[9],int blank)
	{
		int count;
		if (head == NULL)
		{
			node* temp = new node;
			for (int i = 0; i < 9; i++)
			{
				temp->key[i] = puzzle[i];
			}
			temp->next = NULL;
			temp->root = blank;
			temp->move = "none";
			head = temp;
			tail = temp;
			process(temp, 0);

		}
	}
};

int main()
{
	int puzzle[9], root, end[9] = { 0,1,2,3,4,5,6,7,8 };
	bool exists[9] = {false,false,false,false,false,false,false,false,false};
	queue myqueue;
	for (int i = 0; i < 9; i++)
	{
		cout << "\nEnter " << i + 1 << " value (Enter 0 for the blank place): ";
		cin >> puzzle[i];
		while (puzzle[i] < 0 || puzzle[i] > 8)
		{
			cout << "\nInvalid input, please re-enter: ";
			cin >> puzzle[i];
		}
		while (exists[puzzle[i]] == true)
		{
			cout << "\nNumber already inserted, please re-enter: ";
			cin >> puzzle[i];
		}
		exists[puzzle[i]] = true;
		if (puzzle[i] == 0)
			root = i;
	}
	myqueue.insert(puzzle, root);
	getch();
}
