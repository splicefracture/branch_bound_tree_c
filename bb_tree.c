
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "linkedlist.h"
#include "bb_tree.h"

unsigned int TREE_uid = 0;


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
	newNode->children = NULL;
	newNode->pruned = 0;
	
	return newNode;

}


void addChild(TREE* headPtr, TREE child){
		
	TREE curr = *headPtr;	
	int i, e = 0;
	LIST l, lcurr;
	
	if (isParent(headPtr,child) == 1){
		fprintf (stderr, "Directed Cycle\n");
		return;
	}
	
	child->parent = curr;
	l = createListNode(child);
		
	if (isListEmpty (curr->children)){
		curr->children = l;
	} else {
		lcurr = curr->children;
		while (lcurr != NULL){
			if(child->id == lcurr->data->id){				
				return;
			}			
			lcurr = lcurr -> next;
		}		
		insertListNode(&curr->children, l);		
	}   	
		
}


void addList(LIST* headPtr, TREE n){
	
	LIST curr = *headPtr;
	
	while(curr != NULL){
		
		if (n->id == curr->data->id){
			return;
		}
		
		curr = curr->next;
	}	
	insertListNode(headPtr,createListNode(n));
	
}



int isParent(TREE* headPtr, TREE child){
	
	TREE curr = *headPtr;
	
	while (curr != NULL){		
		if (child->id == curr->id){
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
		fprintf (stderr, "\t\t\tNo nodes here.\n");
	}else{
		printf("head \n-----\n%d   %d \n", head->id, head->data);
		printHelper(head,1);	
	}
	
}

void printHelper(TREE head, int level){

	int i;
	if (!isEmpty (head)){
		/*
		for(i = 0; i < head->childrenCount; i++){
			printf("\nlevel %d",level);
			printNode(head->children[i]);			
			printHelper(head->children[i],level+1);
		}
		*/		
	}   	
}

void printPathUp(TREE leaf){
	
	TREE curr = leaf;
	
	while (curr != NULL){
		printNode(curr);
		curr = curr->parent;
	}      
}


void findLeafs(TREE* head, LIST* leafs){
	
	int i;	
	TREE t, curr = (*head);
	LIST lcurr, n;
	
	if (curr->children==NULL){
		
		n = createListNode(curr);
		fprintf(stderr,"hey\n");
		insertListNode(leafs,n);
		
		fprintf(stderr,"dude\n");
	}else{

		lcurr = curr->children;		

		while(lcurr != NULL){	
			
			//printf("%d\n",lcurr->id);
			t = lcurr->data;			
			findLeafs(&t, leafs);						
			lcurr = lcurr->next;
		}
		
	}
}


void findPath(TREE leaf, LIST* path){

	TREE curr = leaf;	
	while (curr != NULL){
		insertListNode(path,createListNode(curr));
		curr = curr->parent;
	}	
}


void printNode(TREE p){
	
	int pid = -1;
	
	if (p->parent !=  NULL){
		pid = p->parent->id;
	}
	
	printf("\n-----------------------\n");
	printf(  "- id         %d  \n",p->id);
	printf(  "- data       %d  \n",p->data);
	printf(  "- parent id  %d  \n",pid);
	//printf(  "- # children %d  \n",p->childrenCount);	
	printf(  "-----------------------\n");
	
}

TREE findChildById(TREE* headPtr, int id){
	
	int i;
	TREE head = (*headPtr);
	LIST lcurr = head->children;
	
	while(lcurr != NULL){			
		if (lcurr->id == id){
			return lcurr->data;
		}
		lcurr = lcurr->next;
	}	
	return NULL;
}




unsigned int LIST_uid = 0;

LIST createListNode (TREE t)
{
   LIST newNode;
   
   newNode = (LIST) malloc (sizeof(LISTNODE));
   if (newNode == NULL)
   {
      fprintf (stderr, "Out of Memory - CreateNode\n");
      exit (-1);
   }

   newNode -> data = t;   
   newNode -> id   = LIST_uid++;    
   newNode -> next = NULL;
   
   return newNode;
}

void insertListNode (LIST* headPtr, LIST temp)
{
	LIST prev, curr;
	
	fprintf(stderr,"start\n");
	
	if ( isListEmpty (*headPtr)){
		fprintf(stderr,"tmp\n");
		curr = temp;
	} else {	   
		prev = NULL;		
		
		fprintf(stderr,"funk\n",curr->data->id);
		curr = *headPtr;
		
		while (curr != NULL){
			fprintf(stderr,"monkey\n",curr->data->id);
			prev = curr;
			fprintf(stderr,"xx-%d\n",curr->data->id);
			curr = curr->next;
		}
		fprintf(stderr,"1\n");
		prev -> next = temp;
		fprintf(stderr,"2\n");
	}
	
	fprintf(stderr,"outttt\n");
}

void deleteListNode (LIST* headPtr, int target)
{
   int value;
	LIST temp, prev, curr;

	if (isListEmpty (*headPtr)){
		fprintf (stderr, "Can't delete from an empty list\n");      
	}else if (target ==  (*headPtr)->id){
	   
		temp = *headPtr;		
		*headPtr = (*headPtr)->next;
		free (temp);    
		
	}else{
		
		prev = *headPtr;
		curr = (*headPtr) -> next;

		while (curr != NULL && target !=  (*headPtr)->id ){
			prev = curr;
			curr = curr -> next;
		}      
		if(curr != NULL){
			temp = curr;
			prev -> next = curr -> next;			
			free(temp);	
		}else{
			fprintf (stderr, "%d was not in the list\n", target);
      }
   }      
}

int isListEmpty (LIST head){
		
   return (head == NULL);
   
}


void printList (LIST head){
		
	LIST curr;
	if (isListEmpty (head)){
		fprintf (stderr, "\t\t\tNo nodes here.\n");
	} else {
		curr = head;		
		while (curr != NULL){
			printf("%d   ",   curr->id);
			printf("%d   \n", curr->data->id);
			curr = curr->next;
		}		
	}   
}

