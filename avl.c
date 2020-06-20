#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node *left,*right;
	int H;
}node;

int height(node *T)
{
	int A,B;
	if(T==NULL)
		return(0);

	if(T->left==NULL)
		A=0;
	else
		A=1+T->left->H;

	if(T->right==NULL)
		B=0;
	else
		B=1+T->right->H;

	if(A>B)
		return(A);
	else
	      return(B);
}

node * rightrotation(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->H=height(x);
	y->H=height(y);
	return(y);
}
node * leftrotation(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->H=height(x);
	y->H=height(y);

	return(y);
}

node * RRI(node *T)
{
	T=leftrotation(T);
    printf("RRI rotation done\n");
	return(T);
}

node * LLI(node *T)
{
	T=rightrotation(T);
    printf("LLI rotation done\n");
	return(T);
}

node * LRI(node *T)
{
	T->left=leftrotation(T->left);
    printf("RLI rotation done\n");
	T=rightrotation(T);
    printf("RRI rotation done\n");

	return(T);
}

node * RLI(node *T)
{
	T->right=rightrotation(T->right);
    printf("RRI rotation done\n");
	T=leftrotation(T);
    printf("RLI rotation done\n");
	return(T);
}

int balancefactor(node *T)
{
	int A,B;
	if(T==NULL)
		return(0);

	if(T->left==NULL)
		A=0;
	else
		A=1+T->left->H;

	if(T->right==NULL)
		B=0;
	else
		A=1+T->right->H;
	return(A-B);
}

void inorder(node *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf("%d(balancefactor=%d)",T->data,balancefactor(T));
		inorder(T->right);
	}
}

node * insert(node *T,int x)
{
	if(T==NULL)
	{
		T=(node*)malloc(sizeof(node));
		T->data=x;
		T->left=NULL;
		T->right=NULL;
	}
	else
		if(x > T->data)
		{
			T->right=insert(T->right,x);
			if(balancefactor(T)==-2)
				if(x>T->right->data)
					T=RRI(T);
				else
					T=RLI(T);
		}
		else
			if(x<T->data)
			{
				T->left=insert(T->left,x);
				if(balancefactor(T)==2)
					if(x < T->left->data)
						T=LLI(T);
					else
						T=LRI(T);
			}

		T->H=height(T);

		return(T);
}

int main()
{
	node *root=NULL;
	int x,n,i,o;
	do
	{
		printf("\n1)Create:");
		printf("\n2)Print:");
		printf("\n3)Quit:");
		printf("\n\nEnter Your Choice:");
		scanf("%d",&o);

		switch(o)
		{
			case 1: printf("\nEnter no. of elements:");
					scanf("%d",&n);
					printf("\nEnter tree data:");
					root=NULL;
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						root=insert(root,x);
					}
					break;

			case 2: printf("\n\n Inorder sequence:\n");
					inorder(root);
					printf("\n");
					break;
		}
	}while(o!=3);

	return 0;
}
