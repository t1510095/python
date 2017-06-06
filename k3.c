/*
プログラミング言語実験・C言語 第2回課題レポート
1510095 竹内七海
*/

//課題 3

#include <stdio.h>
#include <stdlib.h>

typedef char data_t;

typedef struct node_tag{
  data_t data;
  struct node_tag *next;
} node_t;

node_t *new_node(data_t x, node_t *p){
  node_t *temp;
  temp = (node_t *)malloc(sizeof(node_t));
  if (temp==NULL) return NULL;
  else{
    temp->data = x;
    temp->next = p;
    return temp;
  }
}

void initialize(node_t **pp){
  *pp=NULL;
}

int empty(node_t *p){
  if(p==NULL) return 1;
  else return 0;
}

data_t topdata(node_t *p){
  if (p==NULL) return '\0';
  else return p->data;
}

int push(node_t **pp, char x){
  node_t *temp;

  temp = new_node(x, *pp);
  if(temp==NULL) return 0;
  *pp=temp;
  return 1;
}

int pop (node_t **pp){
  node_t *temp;

  if(*pp!=NULL){
    temp=(*pp)->next;
    free(*pp);
    *pp=temp;
    return 1;
  }
  else return 0;
}

int rank (char a, char b){
  int x,y;

  switch(a){
  case('='):    x=0;    break;
  case('('):    x=4;    break;
  case(')'):    x=1;    break;
  case('+'):    x=2;    break;
  case('-'):    x=2;    break;
  case('*'):    x=3;    break;
  case('/'):    x=3;    break;
  default:    x=5;    break;
  }
  switch(b){
  case('='):    y=0;    break;
  case('('):    y=4;    break;
  case(')'):    y=1;    break;
  case('+'):    y=2;    break;
  case('-'):    y=2;    break;
  case('*'):    y=3;    break;
  case('/'):    y=3;    break;
  default:    y=5;    break;
  }

  if(x<=y) return 1;
  if(x>y) return -1;
}

void translate(char a[], node_t *p){
  int i=0,o;
  char t;
  while (a[i]!='\0'){
    t=a[i];
    while((empty(p)!=1)&&(topdata(p)!='(')&&(rank(t, topdata(p))==1)){
      printf("%c",topdata(p));
      pop(&p);
    }
    if(t!=')'){ push(&p, t); }
    else{ pop(&p); }
    i++;
  }
  while (empty(p)!=1){
    printf("%c",topdata(p));
    pop(&p);
  }
  printf("\n");
}
 
int main(void){
  node_t *stack;
  char s1[]="A=(B-C)/D+E*F";
  char s2[]="A=(B-C/D+E)*F";
  char s3[]="A=B-C/(D+E*F)";
  int i=0;

  initialize(&stack);
  while(s1[i]!='\0'){
    printf("%c",s1[i]);
    i++;
  }
  printf(" : ");
  translate(s1, stack);

  initialize(&stack);
  i=0;
  while(s2[i]!='\0'){
    printf("%c",s2[i]);
    i++;
  }
  printf(" : ");
  translate(s2, stack);

  initialize(&stack);
  i=0;
  while(s3[i]!='\0'){
    printf("%c",s3[i]);
    i++;
  }
  printf(" : ");
  translate(s3, stack);

  return 0;
}

/* 実行例

A=(B-C)/D+E*F : ABC-D/EF*+=
A=(B-C/D+E)*F : ABCD/-E+F*=
A=B-C/(D+E*F) : ABCDEF*+/-=

 */
