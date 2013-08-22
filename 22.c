//traversing in trees.
//This program is running correctly.!!
#include<stdio.h>
#include<malloc.h>
struct tnode
{
int data;
struct tnode* left;
struct tnode* right;
}*root=NULL;

void inorder(struct tnode* p);
void preorder(struct tnode* p);
void postorder(struct tnode* p);
struct tnode* insert(struct tnode*,int data);

//------------------------------------------------------------------------------------------------------------

struct Arrayqueue{
int front,rear,capacity;
struct tnode** array;
};

struct Arrayqueue *Queue(int size)
{
struct Arrayqueue *q = malloc(sizeof(struct Arrayqueue));
q->front=q->rear=-1;
q->capacity=size;
q->array= (struct tnode**)malloc(q->capacity*sizeof(struct tnode*));
if(!q->array)
return NULL;
else
return q;
}


int Isemptyqueue(struct Arrayqueue *q)
{
return(q->front==-1);
}

int Isfullqueue(struct Arrayqueue *q)
{
return((q->rear+1)%q->capacity==q->front);
}

void enqueue(struct Arrayqueue *q,struct tnode* data)
{
if(Isfullqueue(q))
printf("\noverflow");
else
{
q->rear=(q->rear+1)%(q->capacity);
q->array[q->rear]=data;
if(q->front==-1)
q->front=q->rear;
}
}

struct tnode* dequeue(struct Arrayqueue *q)
{
struct tnode* data;
if(Isemptyqueue(q))
{
printf("\nEMPTY");
return 0;
}
else
	{
	data=q->array[q->front];
	if(q->front==q->rear)
		q->front=q->rear=-1;	
	else
		q->front=(q->front+1)%q->capacity;
return data;
	}
}

void deletequeue(struct Arrayqueue *q)
{
if(q)
{
if(q->array)
free(q->array);
free(q);
}
}

//---------------------------------------------------------------------------------------------------------------------------
main()
{

int choice=0,data;
printf("Keep entering the digits: press -1 to stop!!\n");
printf("Start entering!!\n");
scanf("%d",&data);
while(data!=-1)
	{
	root=insert(root,data);
	scanf("%d",&data);
	}
do
{
printf("1.Inorder Traversal Of Nodes\n");
printf("2.Preorder Traversal Of Nodes\n");
printf("3.Postorder Traversal Of Nodes\n");
printf("4.Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
switch(choice)
	{
	case 1:
	inorder(root);
	break;

	case 2:
	preorder(root);
	break;
	case 3:
	postorder(root);
	break;
	case 4:
	default:
	break;
	}
}while(choice<4);

}
//----------------------------------------------------------------------------------------------------------------------
//Insert Function.
struct tnode* insert(struct tnode* a,int data)
{
	
		
	struct tnode* temp;
	struct tnode* newnode;
	newnode=(struct tnode*) malloc(sizeof(struct tnode));
	newnode->left=newnode->right=NULL;
	newnode->data=data;
	if(!newnode)
			{
			printf("Memory Error\n");
			return a;
			}
	if(!a)
			{
			a=newnode;
			return a;
			}
	struct Arrayqueue *Q=Queue(20);
	enqueue(Q,a);
	while(!Isemptyqueue(Q))
	{
		temp = dequeue(Q);
		if(temp->left)
			enqueue(Q,temp->left);
		else
		{
			temp->left=newnode;
			break;		
		}
		
		if(temp->right)
			enqueue(Q,temp->right);
		else
		{
			temp->right=newnode;
			break ;		
		}
	}
	deletequeue(Q);	
	return a;
}

//Inorder.
void inorder(struct tnode* p)
{
	if(p)
	{
		inorder(p->left);
		printf("%d\n",p->data);
		inorder(p->right);
	}

}

	
void preorder(struct tnode* p)//preorder non-recursive
{
 	if(p)
	{
		printf("%d\n",p->data);
		preorder(p->left);
		preorder(p->right);
	}

}

void postorder(struct tnode* p)
{
 	if(p)
	{
		
		postorder(p->left);
		postorder(p->right);
		printf("%d\n",p->data);
	}

}

		
		

