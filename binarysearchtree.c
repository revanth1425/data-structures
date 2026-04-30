#include<stdio.h>
#include<stdlib.h>

struct node
{int data;
 struct node *ll; 
struct node *rl ; 
}*mr=NULL,*nn,*temp,*t;



void bst(int *x,int k){
if(mr==NULL){
nn=(struct node*)malloc(sizeof(struct node));
nn->data=x[k];nn->ll=NULL;nn->rl=NULL;
mr=nn;return;
}temp=mr;
nn=(struct node*)malloc(sizeof(struct node));
while(1){
if(temp->data>x[k]){
    if(temp->ll==NULL){temp->ll=nn;
        break;
    }
    else{
        temp=temp->ll;
    }
}  
 else if(temp->data<x[k]){
    if(temp->rl==NULL){temp->rl=nn;
        break;
    }
    else{
        temp=temp->rl;
    }
}  

}

nn->data=x[k];nn->ll=NULL;nn->rl=NULL;

}

// traversal :
//1-> preoder, 2-> inorder, 3->postorder
//insert-> all i need to do is call bst , and input k value as d+1
//delete->1.deleting a leaf 
// 2-> deleting a node with left child only
//3-> deleting a node with right child only
//4-> deleting a node with two childs 
//converting into a perfect binary tree
void preorder(){
// go all the way to the left down and use rLR, but once i all the way down how am i gonna come up 
printf("%d",mr->data);temp=mr;

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





int main(){int *p,*w;int d; p=&d;
printf("enter the array size:\n");
scanf("%d",&d);int a[*p]; 
printf("enter the array elemrnts\n");
for(int i=0;i<d;i++){
    scanf("%d",&a[i]);
}
w=a;for(int i=0; i<d;i++){
bst(w,i);}
printf("preorder:\n");
preorder(t);t=mr;
printf("inorder:\n");
inorder(t);t=mr;
printf("postorder:\n");
postorder(t);



return 0;}
