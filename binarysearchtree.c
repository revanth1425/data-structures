#include<stdio.h>
#include<stdlib.h>

struct node
{int data;
 struct node *ll;
struct node *rl ;
}*mr=NULL,*nn,*temp,*t,*bb,*link,*zoro=NULL;


struct node *bst(int *x,int k){
if(mr==NULL){
nn=(struct node*)malloc(sizeof(struct node));
nn->data=x[k];nn->ll=NULL;nn->rl=NULL;
mr=nn;return nn;
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
else{free(nn);
   return NULL;}

}

nn->data=x[k];nn->ll=NULL;nn->rl=NULL;
return nn;
}

// traversal :
//1-> preoder, 2-> inorder, 3->postorder(COMPLETED)
//insert-> call bst , and send it as a argument(completed)
//delete->1.deleting a leaf (completed)
// 2-> deleting a node with left child only(completed)
//3-> deleting a node with right child only(completed)
//4-> deleting a node with two childs (completed)
//5->converting into a perfect binary tree
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


void insert(){
    int y[2];int *j;
    int h;y[0]=0;
    printf("enter the value to be inserted:\n");
    scanf("%d",&h);
    y[1]=h;j=y;
    bst(j,1);
}

void delete(){int q;
    printf("value to be deleted:\n");
    scanf("%d",&q);
   if(mr==NULL){ printf(" binary tree is empty");
return;
}
else if( q==mr->data && mr->ll==NULL && mr->rl==NULL){
    t=mr;
    free(t);mr=NULL;return;
}
temp=mr;

while(1){
if(temp->data>q){
    if(temp->ll==NULL){printf("element not found in bst\n");
        return;
    }
    else if(temp->ll->data==q){
       break;
    }
    else{
        temp=temp->ll;
    }
}
 else if(temp->data<q){
    if(temp->rl==NULL){printf("element not found in bst\n");
       return;
    }

    else if(temp->rl->data==q){
       break;
    }
    else{
        temp=temp->rl;
    }
}

}
if(temp->ll!=NULL && (temp->ll->ll==NULL && temp->ll->rl==NULL) && temp->ll->data==q)
{printf("deleted a leaf in bst of value %d",q);
t=temp->ll;free(t);
temp->ll=NULL;
}
else if(temp->rl!=NULL && (temp->rl->rl==NULL && temp->rl->ll==NULL) && temp->rl->data==q){
printf("deleted a leaf in bst of value %d",q);
t=temp->rl;free(t);
temp->rl=NULL;
}
else if(temp->ll!=NULL && (temp->ll->ll==NULL ) && (temp->ll->rl!=NULL )&& temp->ll->data==q){
printf("deleted a node in bst with only a right child of value %d",q);
bb=temp->ll->rl;
t=temp->ll;free(t);
temp->ll=bb;
}
else if(temp->ll!=NULL && (temp->ll->rl==NULL ) && (temp->ll->ll!=NULL )&& temp->ll->data==q){
printf("deleted a node in bst with only a left child of value %d",q);
bb=temp->ll->ll;
t=temp->ll;free(t);
temp->ll=bb;
}
else if(temp->rl!=NULL && (temp->rl->rl==NULL ) && (temp->rl->ll!=NULL )&& temp->rl->data==q){
printf("deleted a node in bst with only a left  child of value %d",q);
bb=temp->rl->ll;
t=temp->rl;free(t);
temp->rl=bb;
}
else if(temp->rl!=NULL && (temp->rl->ll==NULL ) && (temp->rl->rl!=NULL )&& temp->rl->data==q){
printf("deleted a node in bst with only a right child of value %d",q);
bb=temp->rl->rl;
t=temp->rl;free(t);
temp->rl=bb;
}
else if(temp->ll!=NULL && (temp->ll->ll!=NULL && temp->ll->rl!=NULL) && temp->ll->data==q){int k,*p,a[2];a[0]=0;
printf("deleted a node in bst of value %d with two childs, ",q);
bb=temp->ll->rl;
zoro=bb->ll;
if(zoro!=NULL){
k=bb->ll->data;a[1]=k;p=a;
bb->ll=NULL;
bb->ll=temp->ll->ll;
link=bst(p,1);

link->ll=zoro->ll;

link->rl=zoro->rl;

}

else if(zoro==NULL){bb->ll=temp->ll->ll;}
free(zoro);
t=temp->ll;

free(t);temp->ll=bb;

}
else if(temp->rl!=NULL && (temp->rl->ll!=NULL && temp->rl->rl!=NULL) && temp->rl->data==q){int k,*p,a[2];a[0]=0;

printf("deleted a node in bst of value %d with two childs, ",q);

bb=temp->rl->rl;
zoro=bb->ll;
if(zoro!=NULL){
k=bb->ll->data;a[1]=k;p=a;
bb->ll=NULL;
bb->ll=temp->rl->ll;
link=bst(p,1);

link->ll=zoro->ll;

link->rl=zoro->rl;

}

else if(zoro==NULL){bb->ll=temp->rl->ll;}
free(zoro);
t=temp->rl;

free(t);temp->rl=bb;


}

}





int main(){int *p,*w;int d; p=&d;
printf("enter the array size:\n");
scanf("%d",&d);int a[*p];
printf("enter the array elemrnts\n");
for(int i=0;i<d;i++){
    scanf("%d",&a[i]);
}
w=a;for(int i=0; i<d;i++){
bst(w,i);} insert();
t=mr;
printf("preorder:\n");
preorder(t);
printf("inorder:\n");
inorder(t);
printf("postorder:\n");
postorder(t);
delete();


return 0;}
