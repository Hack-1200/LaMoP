#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
  int kod;
  char *name;
  struct node *ll;
  struct node *rl;
} node;
node *createP();

int main(){
  node *root;
  root = createP();
  char buf[100];
  char *p = buf;
  scanf("%s",&*p);
  // char *p = fgets();
  printf("\ngood/n\n");
  printf("%s", p);
}

node *createP(){
  node *root = (node *)malloc(sizeof(node));
  root->kod = 0;
  root->name = " ";
  root->ll = NULL;
  root->rl = NULL;
  return root;
}
