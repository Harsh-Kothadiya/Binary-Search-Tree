//bineary  search  tree
#include<iostream>
#include<conio.h>
using namespace std;

struct BST //BST : bineary search tree
{
	int info;
	struct BST *LPTR,*RPTR;
};
typedef struct BST node;
node *ROOT=NULL;
node *travel=NULL;


/*---------------function declaretion-----------------------*/
void insert(int);
void Pre_Order(node *);
void In_Order(node *);
void Post_Order(node *);
void DISPLAY();
void SEARCH();
/*-------------------main function(part)--------------------------*/
int main()
{
	int choice;
	do
	{
		cout<<"\n\n--------------------MENU------------------------------------------------------------------------------------------------------------------------------------------------";
		cout<<"\n\n\t ENTER-1 : INSERT ";
		cout<<"\n\n\t ENTER-2 : DISPLAY ";
		cout<<"\n\n\t ENTER-3 : SEARCH ";
		cout<<"\n\n\t ENTER-4 : EXIT ";
		cout<<"\n\n\n\t ENTER YOUR CHOICE : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1 :
				cout<<"\n\n\t ENTER A VALUE : ";
				int v;
				cin>>v;
				insert(v);
				break;
			
			case 2 :
				DISPLAY();
				break;
				
			case 3 :
				SEARCH();
				break;
			
			case 4 :
				break;
			default :
				cout<<"\n\n\t IN_VALIED CHOICE...";
		}
	}while(choice!=4);
	getch();
	return 0;
}

/*--------------function defintion------------------------------------------*/

void insert(int value)
{
	node *n;  // n : new node addressh  storing pointer
	n=new node;
	n->info=value;
	n->LPTR=NULL;
	n->RPTR=NULL;
	
	if(ROOT==NULL)
		ROOT=n;
	else
	{
		travel=ROOT;
		do
		{
			if( (travel->info) > (n->info) )
			{
				if(travel->LPTR==NULL)
				{
					travel->LPTR=n;
					break;
				}
					
					travel=travel->LPTR;
			}
		    if( (travel->info) < (n->info) )
			{
				if(travel->RPTR==NULL)
				{
					travel->RPTR=n;
					break;
				}
				
					travel=travel->RPTR;
				
			}
		}while((travel->LPTR!=NULL) || (travel->RPTR!=NULL) );
		if(travel->info > n->info)
			travel->LPTR=n;
		if(travel->info < n->info)
			travel->RPTR=n;
	}
	
}
void Pre_Order(node *ROOT)
{
	if(ROOT!=NULL)
	{
		cout<<ROOT->info<<"\t";
		Pre_Order(ROOT->LPTR);
		Pre_Order(ROOT->RPTR);
	}
}

void In_Order(node *ROOT)
{
	if(ROOT!=NULL)
	{
		In_Order(ROOT->LPTR);
		cout<<ROOT->info<<"\t";
		In_Order(ROOT->RPTR);
	}
}

void Post_Order(node *ROOT)
{
	if(ROOT!=NULL)
	{
		Post_Order(ROOT->LPTR);
		Post_Order(ROOT->RPTR);
		cout<<ROOT->info<<"\t";
	}
}
void DISPLAY()
{
	if(ROOT==NULL)
		cout<<"\n\n\t TREE IS EMPTY...";
	else
	{
		int choice_1;
		cout<<"\n\n\n----------MENU-------------\n\n";
		cout<<"\n\n\t ENTER-1 : PRE-ORDER ";
		cout<<"\n\n\t ENTER-2 : IN-ORDER ";
		cout<<"\n\n\t ENTER-3 : POST-ORDER ";
		cout<<"\n\n ENTER YOUR CHOICE : ";
		cin>>choice_1;
		switch(choice_1)
		{
			case 1 :
					cout<<"\n\n\n DISPLAY VALUE BY PRE-ORDER \n\n";
					Pre_Order(ROOT);
				break;
			case 2 :
					cout<<"\n\n\n DISPLAY VALUE BY IN-ORDER \n\n";
					In_Order(ROOT);
				break;
			case 3 :
					cout<<"\n\n\n DISPLAY VALUE BY POST-ORDER \n\n";
					Post_Order(ROOT);
				break;
			default :
				cout<<"\n\n\t IN_VALIED CHOICE...";
		}
	
	}
	
}

void SEARCH()
{
	if(ROOT==NULL)
		cout<<"\n\n TREE IS EMPTY...";
	else
	{
		cout<<"\n\n AVALIABLE VALUE IN TREE \n\n";
		In_Order(ROOT);
		int s_val;// s_val:search value
		cout<<"\n\n\t ENTER A SEARCH VALUE : ";
		cin>>s_val;
		node *t;
		t=ROOT;
		int a=0;
		while(t!=NULL)
		{
			if(t->info == s_val)
			{
				a=1;
				break;
			}
			else if(t->info > s_val)
				t=t->LPTR;
			else  // else if(t->info < s_val)
				t=t->RPTR;
		}
		
		if(a==1)
			cout<<"\n\n\n VALUE IS FIND ";
		else
			cout<<"\n\n\n VALUE IS NOT FIND ";
	}
}

