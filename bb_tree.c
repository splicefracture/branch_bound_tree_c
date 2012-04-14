
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bb_tree.h"


unsigned int LIST_uid = 0;
unsigned int TREE_uid = 0;

LIST leafs;




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
	LIST l2, l, lcurr;
	
	if (isParent(headPtr,child) == 1){
		//fprintf (stderr, "Directed Cycle\n");
		return;
	}
	
	child->parent = curr;
	l = createListNode(child);	
	l2 = createListNode(child);
	
	insertListNode(&curr->children, l);			
		
	insertListNode(&leafs,l2);	
	if (curr != NULL){
		
		//printf("%d\n",curr->id);
		deleteListNode(&leafs, curr->id);
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

LIST getLeafs(){
	return leafs;
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
		fprintf (stderr, "\t\t\tNo nodes here.\n");
	}else{
		
		printf("head \n----------------------------------------------\ntree id\tdata\n");
		printf("%d\t%d \n", head->id, head->data);
		printHelper(head,1);	
	}
	
}

void printHelper(TREE head, int level){

	int i;
	LIST curr;
	
	if (!isEmpty (head)){
	
		printList(head->children);
	
		curr = head->children;

		while(!isListEmpty(curr)){
			printHelper(curr->data,level+1);
			curr = curr->next;
		}
	}   	
}

void printPathUp(TREE leaf){
	
	TREE curr = leaf;
	
	while (curr != NULL){
		printNode(curr);
		curr = curr->parent;
	}      
}


void findPath(TREE leaf, LIST* path){

	TREE curr = leaf;	
	while (curr != NULL){
		addList(path,curr);		
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
		
	if ( isListEmpty (*headPtr)){
		(*headPtr) = temp;
	} else {	   
		prev = NULL;
		curr = (*headPtr);				
		while (curr != NULL){			
			prev = curr;
			curr = curr->next;			
		}		
		prev -> next = temp;
	}
}

void deleteListNode (LIST* headPtr, int target)
{
	LIST temp, prev, curr;

	if (isListEmpty (*headPtr)){		
		//fprintf (stderr, "Can't delete from an empty list\n");      
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
			//fprintf (stderr, "%d was not in the list\n", target);
		}
	}      
}

int isListEmpty (LIST head){
		
   return (head == NULL);
   
}


void printList (LIST head){
		
	LIST curr;
	if (isListEmpty (head)){
		//fprintf (stderr, "\t\t\tNo nodes here.\n");
	} else {
		curr = head;		

		printf("-----------------------------------------------\n");
		printf("list id\t\ttree id\t\ttree parent id\n");
		while (curr != NULL){
			printf("%d\t\t",   curr->id);
			printf("%d\t\t",   curr->data->id);
			printf("%d\t\t\n", curr->data->parent->id);
			curr = curr->next;
		}
		printf("-----------------------------------------------\n");
	}   
}


void printLeafs(){
	printList(leafs);
}
