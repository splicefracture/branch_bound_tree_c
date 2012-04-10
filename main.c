#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bb_tree.h"

void main(){
	
	TREE head = createTreeNode(-1);
	
	TREE c1 = createTreeNode(23525);
	TREE c2 = createTreeNode(7447555);
	TREE c3 = createTreeNode(2634);
	TREE c4 = createTreeNode(377554);
	
	TREE gc1 = createTreeNode(3634);
	TREE gc2 = createTreeNode(3744);
	TREE gc3 = createTreeNode(999493);
	
	
	LIST leafs;
	
	
	addChild(&c1,gc1);
	addChild(&c1,gc2);
	addChild(&c1,gc3);
	
	addChild(&head,c1);
	addChild(&head,c2);
	addChild(&head,c3);
	addChild(&head,c4);
	
	//printPathUp(gc3);
	//printList(head);
	
	findLeafs(&head, &leafs);
	
	//printList(leafs);
	
	/*
	printNode(gc3);
	printNode(gc2);
	printNode(gc1);
	printNode(c4);
	printNode(c3);
	printNode(c2);
	printNode(c1);
	
	printNode(head);
	*/
}
