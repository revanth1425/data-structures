#include<stdio.h>
#include<stdlib.h>

struct node
{int data;
 int index;
 struct node *ll; 
struct node *rl ; 
}


struct node *bst(int k){
if(mr==NULL){
nn=(struct node*)malloc(sizeof(struct node));
nn->data=k;nn->ll=NULL;nn->rl=NULL;
mr=nn;return nn;
}temp=mr;
nn=(struct node*)malloc(sizeof(struct node));
while(1){
if(temp->data>k){
    if(temp->ll==NULL){temp->ll=nn;
        break;
    }
    else{
        temp=temp->ll;
    }
}  
 else if(temp->data<k){
    if(temp->rl==NULL){temp->rl=nn;
        break;
    }
    else{
        temp=temp->rl;
    }
}  
else{free(nn);
   return;}

}

nn->data=k;nn->ll=NULL;nn->rl=NULL;
return nn;
}


void insert(int k){
     bst(k);
}












void preorder(struct node*c){
if(c==NULL){
return;
}
printf("%d\n",c->data);
preorder(c->ll);

preorder(c->rl);

}

void inorder(struct node*c){
if(c==NULL){
return;
}
inorder(c->ll);
printf("%d\n",c->data);
inorder(c->rl);

}

void postorder(struct node*c){
if(c==NULL){
return;}
postorder(c->ll);

postorder(c->rl);
printf("%d\n",c->data);
}











int main(){int d,*p;d=&p;
printf("enter the array size:\n");
scanf("%d",&d);int a[*p]; 
printf("enter the array elemrnts\n");
for(int i=0;i<d;i++){
    scanf("%d",&a[i]);
}
for(int i=0; i<d;i++){
bst(a[i])}; 
("printfenter the value to be inserted:\n");
int h;
scanf("%d",&h);
insert(h);
t=mr;
printf("preorder:\n");
preorder(t);
printf("inorder:\n");
inorder(t);
printf("postorder:\n");
postorder(t);
delete();


return 0;}