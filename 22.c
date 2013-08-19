//traversing in trees.
#include<stdio.h>

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
int count=0;



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

//Insert Function.
struct tnode* insert(struct tnode* a,int data)
{
	
	if(a==NULL)
	{
		a=(struct tnode*) malloc(sizeof(struct tnode));
		a->data=data;
		a->left=NULL;
		a->right=NULL;
		++count;
	}	
	

	else if(count%2!=0)//left node
	{
	a->left=insert(a->left,data);
	}
	else //right node
	{	
	a->right=insert(a->right,data);
	}
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

		
		

