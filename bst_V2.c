#include<stdio.h>
#include<stdlib.h>

struct node
{int data;
 int index;
 struct node *ll;
struct node *rl ;
}*nn,*mr,*temp,*zoro,*t,*bb,*tempcopy;


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
   return NULL;}

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

void delete(int kill){
// go all the way left of right subtree and copy the value to the node u are deleting
if(mr==NULL){ printf(" binary tree is empty");
return;
}
else if( kill==mr->data && mr->ll==NULL && mr->rl==NULL){
 t=mr;
 free(t);mr=NULL;return;
}
temp=mr;
while(1){
if(temp->data>kill){
    if(temp->ll==NULL){printf("element not found in bst\n");
        return;
    }
    else if(temp->ll->data==kill){
       break;
    }
    else{
        temp=temp->ll;
    }
}
 else if(temp->data<kill){
    if(temp->rl==NULL){printf("element not found in bst\n");
       return;
    }

    else if(temp->rl->data==kill){
       break;
    }
    else{
        temp=temp->rl;
    }
}

}
if(temp->ll!=NULL && (temp->ll->ll==NULL && temp->ll->rl==NULL) && temp->ll->data==kill)
{printf("deleted a leaf in bst of value %d",kill);
t=temp->ll;free(t);
temp->ll=NULL;
}
else if(temp->rl!=NULL && (temp->rl->rl==NULL && temp->rl->ll==NULL) && temp->rl->data==kill){
printf("deleted a leaf in bst of value %d",kill);
t=temp->rl;free(t);
temp->rl=NULL;
}
else if(temp->ll!=NULL && (temp->ll->ll==NULL ) && (temp->ll->rl!=NULL )&& temp->ll->data==kill){
printf("deleted a node in bst with only a right child of value %d",kill);
bb=temp->ll->rl;
t=temp->ll;free(t);
temp->ll=bb;
}
else if(temp->ll!=NULL && (temp->ll->rl==NULL ) && (temp->ll->ll!=NULL )&& temp->ll->data==kill){
printf("deleted a node in bst with only a left child of value %d",kill);
bb=temp->ll->ll;
t=temp->ll;free(t);
temp->ll=bb;
}
else if(temp->rl!=NULL && (temp->rl->rl==NULL ) && (temp->rl->ll!=NULL )&& temp->rl->data==kill){
printf("deleted a node in bst with only a left  child of value %d",kill);
bb=temp->rl->ll;
t=temp->rl;free(t);
temp->rl=bb;
}
else if(temp->rl!=NULL && (temp->rl->ll==NULL ) && (temp->rl->rl!=NULL )&& temp->rl->data==kill){
printf("deleted a node in bst with only a right child of value %d",kill);
bb=temp->rl->rl;
t=temp->rl;free(t);
temp->rl=bb;
}
else if(temp->ll!=NULL && (temp->ll->ll!=NULL && temp->ll->rl!=NULL) && temp->ll->data==kill){int copy;
    zoro=temp->ll->rl;
    while(zoro->ll!=NULL){zoro=zoro->ll;}
    copy=zoro->data;tempcopy=temp->ll;
    delete(zoro->data);
    tempcopy->data=copy;

}


}









int main(){int d,kill;
printf("enter the array size:\n");
scanf("%d",&d);int a[d];
printf("enter the array elemrnts\n");
for(int i=0;i<d;i++){
    scanf("%d",&a[i]);
}
for(int i=0; i<d;i++){
bst(a[i]);}
printf("enter the value to be inserted:\n");
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
printf("enter the element to be deleted\n");
scanf("%d",&kill);
delete(kill);


return 0;}
