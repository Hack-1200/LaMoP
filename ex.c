#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int koef;
	int exp;
	struct node *next;
} node;

int max=0;
int l=1;
int i=1;
int k=0;
char c='+';
int z=0;
int maxx;

node *pop(node* root,int koef1,int exp1);
node *createList(int koef1,int exp1);
node *createPolinome(node* top,int num);
int MaxElement(node *root);
void pr(node *root);
void delFromEnd(node* root);
void Delete_Item_node(node* head,node* nextEl);
void Sum(node* head,node* la,node* cur);
void Addition_Of_Polinoms(node *head1);
void Delete_Element(node* head,node *next_node);

int main(int argc, char const *argv[])
{
    	// node *root=createList();
    	int pol;
    	node *top,*end;
    	node *root=createList(0,0);
    	top=root;
    	end=root;
    	printf("Number of polynomial member: ");
    	scanf("%d",&pol);
    	end=createPolinome(top,pol);
    	// printf("koef=%d exp=%d\n",end->koef,end->exp);
    	// printf("prrrrrrrrrrrrrrr\n");
    	pr(root);
    	int max1=MaxElement(root);
    	printf("\nmax=%d\n",max);
    	printf("vvv=%d\n",l);
    	// delFromEnd(root);
    	i=0;
      if(z > 1){
          Addition_Of_Polinoms(root);
          MaxElement(root);
          Delete_Item_node(root,root);
      }
      else
    	   Delete_Item_node(root,root);
    	// printf("good\n");
    	pr(root);
    	return 0;
}

node *createList(int koef1,int exp1){
	node *root;
	root=(node*)malloc(sizeof(node));
	root->koef=koef1;
	root->exp=exp1;
	root->next=NULL;
	return root;
}

node *pop(node* root,int koef1,int exp1){
	// if(root==NULL){
	// 	root=createList(0,0);
	// }
	node *conductor;
	conductor=root;
	conductor->next=createList(koef1,exp1);
	conductor=conductor->next;
	return conductor;
}

node *createPolinome(node* current,int num){

	if(num==0){
		printf("%d\n",num);
		return current;
	}


	int k,e;
	// current=top;
	printf("Enter coefficient: ");
	scanf("%d",&k);
	printf("Enter exponent: ");
	scanf("%d",&e);
  if(maxx < e){
    maxx = e;
    z = 1;
  }
  else if(maxx == e){
    maxx = e;
    z++;
  }



	current=pop(current,k,e);
	num--;
    current=createPolinome(current,num);
    return current;
}

void pr(node *root){
	// printf("pr is work");

		if(root->next==NULL){

			return;
		}
		root=root->next;
		printf("%dx^%d %c",root->koef, root->exp,c);

		pr(root);
}

int MaxElement(node *root){

	i++;
		if(max<root->exp){
			max=root->exp;
			// printf("%d\n",max);
		}
		if(root->next==NULL) return max;
		root=root->next;
		// max=(max<root->exp)?root->exp:max;

		max=MaxElement(root);
		return max;

}

void Delete_Item_node(node* head,node *nextEl){
  node *ptr;

  if(nextEl==NULL)
  	return;
  ptr=head;
  i++;
  printf("%d\n",i);
  if(nextEl->exp==max){
  	ptr->next=nextEl->next;
  	free(nextEl);
  }

  Delete_Item_node(nextEl,nextEl->next);

}
void Addition_Of_Polinoms(node* head1){
	node *head=head1;
	if(head->next==NULL){
		return;
	}
	Sum(head,head,head->next);
	Addition_Of_Polinoms(head->next);
	return;
}

void Sum(node* head,node* la,node* cur){
	node *current=cur;

	if(head->exp==current->exp){
		head->koef=head->koef+current->koef;
		max=current->exp;
		Delete_Element(la,current);
	}
	if(current->next==NULL)return;
	Sum(head,current,current->next);
	return;
}

void Delete_Element(node* head,node *next_node){
  node *node;

  if(next_node==NULL)
  	return;
  node=head;
  if(next_node->exp==max){
  	node->next=next_node->next;
  	free(next_node);
  	return ;
  }

  Delete_Element(next_node,next_node->next);

}
