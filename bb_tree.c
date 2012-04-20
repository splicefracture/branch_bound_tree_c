
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bb_tree.h"

int max_children = 2;

unsigned int LIST_uid = 0;
unsigned int TREE_uid = 0;

TREE createHeadNode(int max){
	max_children = max;
	return createTreeNode (-1);
}

TREE createTreeNode (int data){
	
	TREE newNode;
   
	newNode = (TREE) malloc (sizeof(TREENODE));
	if (newNode == NULL){	   
		fprintf (stderr, "Out of Memory - CreateNode\n");
		exit (-1);
	}	

	newNode->data = data;  	
	newNode->id   = TREE_uid++;
	newNode->parent = NULL;	
	
	newNode->pruned = 0;
	
	newNode->childrenCount = 0;
	newNode->level = 0;
	
	newNode->children = (TREE*) malloc (max_children*sizeof(TREE));
	
	return newNode;

}

void addChild(TREE* headPtr, TREE child){
		
	int i;
	TREE curr = *headPtr;		
	
	if (isParent(headPtr,child) == 1){
		//fprintf (stderr, "Directed Cycle\n");
		return;
	}
	
	child->parent = curr;
	child->level = curr->level+1;

	for(i = 0; i < curr->childrenCount; i++){
		if (curr->children[i]->id == child->id){
			return;
		}
	}	
	curr->children[curr->childrenCount++] = child;	
}

int isParent(TREE* headPtr, TREE child){
	
	TREE curr = *headPtr;
	
	while (curr != NULL){		
		if (child->data == curr->data){
			return 1;
		}		
		curr = curr->parent;
	} 
	return 0;
}


void deleteChild (TREE* headPtr, int target){
	
	  return;
}

int isEmpty (TREE head){
   return (head == NULL);
}

void printTree (TREE head){
	
	if (isEmpty(head)){
		//fprintf (stderr, "\t\t\tNo nodes here.\n");
	}else{
		
		printHeader();
		printNode(head);
		printf("\n\n");
		printHelper(head);	
	}
	
}

void printHeader(){
	printf("id\tdata\tparent\tchild\tlevel\tpruned\n");
	printf("------------------------------------------------------\n");	
}

void printHelper(TREE head){

	int i;

	if (head->childrenCount == 0){
		return;
	}

	printHeader();
	for(i = 0; i < head->childrenCount; i++){		
		printNode( head->children[i]);	
	}
	printf("\n\n");
	for(i = 0; i < head->childrenCount; i++){
		printHelper(head->children[i]);			
	}

}

void printNode(TREE p){
	
	int pid;
	
	if (p->parent != NULL){
		pid = p->parent->id;
	}
	
	printf("%d\t",   p->id);
	printf("%d\t",   p->data);
	
	printf("%d\t",   pid);
	printf("%d\t",   p->childrenCount);
	printf("%d\t",   p->level);
	printf("%d\t\n",   p->pruned);
	
	
}

TREE findChildById(TREE head, int id){
	
	int i;
	TREE t;

	if (head->id == id){
		return head;
	}else{
		for(i = 0; i < head->childrenCount; i++){
			t = findChildById(head,id);			
			if (t != NULL){
				return t;
			}	
		}	
	}	
	return NULL;
}


TREE findNextLeaf(TREE head){

	int i;
	TREE t;

	if (isLeaf(head) == 1 && head->level != max_children ){
		return head;
	}else{
		for(i = 0; i < head->childrenCount; i++){
			t = findNextLeaf(head->children[i]);			
			if (t != NULL){
				return t;
			}	
		}	
	}	
	return NULL;
}

int isLeaf(TREE head){
	return (head->pruned == 0 && head->childrenCount == 0);	
}

void printLevel(TREE head, int level){
		
	int i;
	
	if (head->level == level){
		printNode(head);
	}else{
		for(i = 0; i < head->childrenCount; i++){
			printLevel(head->children[i],level);
		}	
	}
}

int compareTreePath(TREE curr, TREE target){
	
	TREE t = target;
	int exists =1;
	if(curr->level != target->level){
		return 0;
	}
	while(curr!=NULL && exists == 1){
		exists = 0;		
		while(t!=NULL){
			if (t->data == curr->data){
				exists =1;
			}
			t=t->parent;
		}
		t = target;	
		curr=curr->parent;
	}
	return exists;	
}

void printLeafs(TREE head){
	
	int i;
	
	if (head->childrenCount == 0){
		printNode(head);
	}else{
		for(i = 0; i < head->childrenCount; i++){
			printLeafs(head->children[i]);
		}	
	}
}
