#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bb_tree.h"

void main(){
	
	TREE head = createTreeNode(-1);
	
	TREE c1 = createTreeNode(11111);
	TREE c2 = createTreeNode(22222);
	TREE c3 = createTreeNode(33333);
	TREE c4 = createTreeNode(44444);
	
	TREE gc1 = createTreeNode(55555);
	TREE gc2 = createTreeNode(66666);
	TREE gc3 = createTreeNode(77777);
	
	
	LIST c;
	
	
	
	addChild(&head,c1);
	addChild(&head,c2);
	addChild(&head,c3);
	addChild(&head,c4);
	
	addChild(&c1,gc1);
	addChild(&c1,gc2);
	addChild(&c1,gc3);
	
	
	//printPathUp(gc3);
	//printList(head->children);	
	//printTree(head);
	
	printLeafs();
	
	
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
