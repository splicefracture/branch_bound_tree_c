
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bb_tree.h"

int uid = 0;


NODEPTR createNode (int data){
	
	NODEPTR newNode;
   
	newNode = (NODEPTR) malloc (sizeof(NODE));
	if (newNode == NULL){	   
		fprintf (stderr, "Out of Memory - CreateNode\n");
		exit (-1);
	}	

	newNode->data = data;  	
	newNode->id   = uid++;
	newNode->parent = NULL;
	newNode->childrenCount = 0; 	
	newNode->children = NULL;
	
	return newNode;

}


void addChild(NODEPTR* headPtr, NODEPTR child){
		
	NODEPTR curr = *headPtr;
	NODEPTR* temp = curr->children;
	int i;
	int cnt = curr->childrenCount;
	
	if (isParent(headPtr,child) == 1){
		fprintf (stderr, "Directed Cycle\n");
		return;
	}
	
	curr->children = (NODEPTR*) malloc ((cnt+1)*sizeof(NODEPTR));
	
	if (curr->children == NULL){
		fprintf (stderr, "Out of Memory - addChild\n");
		exit (-1);
	}
	
	child->parent = curr;
	
	for(i = 0; i < cnt; i++){		
		curr->children[i] = temp[i];		
	}
	curr->children[cnt] = child;
		
	curr->childrenCount++;
	free(temp);
}

int isParent(NODEPTR* headPtr, NODEPTR child){
	
	NODEPTR curr = *headPtr;
	
	while (curr != NULL){		
		if (child->id == curr->id){
			return 1;
		}		
		curr = curr->parent;
	} 
	return 0;
}


void deleteChild (NODEPTR* headPtr, int target){
	
	  return;
}

int isEmpty (NODEPTR head){
	
   return (head == NULL);
}

int childrenCount(NODEPTR head){
	return head->childrenCount;
}



void printList (NODEPTR head){
	
	if (isEmpty(head)){
		fprintf (stderr, "\t\t\tNo nodes here.\n");
	}else{
		printf("head \n-----\n%d   %d \n", head->id, head->data);
		printHelper(head,1);	
	}
	
}

void printHelper(NODEPTR head, int level){

	int i;
	if (!isEmpty (head)){
		for(i = 0; i < head->childrenCount; i++){
			printf("\nlevel %d",level);
			printNode(head->children[i]);			
			printHelper(head->children[i],level+1);
		}		
	}   	
}

void printPathUp(NODEPTR leaf){
	
	NODEPTR curr = leaf;
	
	while (curr != NULL){
		printNode(curr);
		curr = curr->parent;
	}      
}


void findLeafs(NODEPTR* tree, NODEPTR* leafs){
	int i;
	NODEPTR head = (*tree);
	NODEPTR curr;	
	if (head->childrenCount==0){
		addChild(leafs,head);
	}else{
		for(i = 0; i < head->childrenCount; i++){			
			curr = head->children[i];
			findLeafs(&curr,leafs);
		}
	}
}


void findPath(NODEPTR leaf, NODEPTR* leafList){

	NODEPTR curr = leaf;
	
	while (curr != NULL){
		addChild(leafList,curr);
		curr = curr->parent;
	} 
}


void printNode(NODEPTR p){
	
	int pid = -1;
	
	if (p->parent !=  NULL){
		pid = p->parent->id;
	}
	
	printf("\n-----------------\n");
	printf(  "- id         %d -\n",p->id);
	printf(  "- data       %d -\n",p->data);
	printf(  "- parent id  %d -\n",pid);
	printf(  "- # children %d -\n",p->childrenCount);	
	printf(  "-----------------\n");
	
}

