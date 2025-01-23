#include<stdio.h>
#include<malloc.h>
struct node{//creatinf a node having multiple arguments
	int data;
	struct node*left;//strutue varibale/pointer of its own type
	struct node*right;
};
struct node*createnode(int data){//creating a node
	struct node*n=(struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;	
}
void insert(struct node*root,int key){//creating a fucntion to insert a node in the (IF BST)exits 
	struct node*prev=NULL;//follower of the root pointer which actually insert the node

	if(root==NULL){
		return;
	}
	while(root!=NULL){
		prev=root;
		if(root->data==key){
			printf("the tree is not BST and the data cant be inserted in the tree");
			return ;
		}
		
		if(root->data>key){
			root=root->left;
			
		}
		if(root->data<key){
			root=root->right;
			
		}
		
	}
	struct node*ne=createnode(key);//the node we want to insert

	if(prev->data>key){
		prev->left=ne;
	}
	else{
	prev->right=ne;
		
	}
}

int main(){
	struct node*p=createnode(5);
	struct node*p1=createnode(3);
	struct node*p2=createnode(7);
	struct node*p3=createnode(2);
	struct node*p4=createnode(4);
	p->left=p1;
	p->right=p2;
	p1->right=p4;
	p1->left=p3;
	int key;
	
	printf("enter the element to be inserted in the bst");
	scanf("%d",&key);
	insert(p,key);
return 0;
}
