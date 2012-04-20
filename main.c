#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bb_tree.h"

void main(){
	
	int i,j,k, m = 12;
	
	TREE t,t2,t3, head = createHeadNode(m);
	
	for(i = 0; i < m; i++){
		addChild(&head,createTreeNode(i));		
	}

	//printf("%d\n",head->childrenCount);

	j = 1;

	for(j = 1; j < 3; j++){

		t = findNextLeaf(head,j);

		while(t != NULL){

			//printNode(t);
			
			for(i = 0; i < m; i++){
				addChild(&t,createTreeNode(i));		
			}
				
			t = findNextLeaf(head,j);	
		}
	}
	
	printTree(head);
	
}



