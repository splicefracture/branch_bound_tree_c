#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bb_tree.h"


void main(){
	
	NODEPTR head = createNode(-1);
	
	NODEPTR c1 = createNode(23525);
	NODEPTR c2 = createNode(7447555);
	NODEPTR c3 = createNode(2634);
	NODEPTR c4 = createNode(377554);
	
	NODEPTR gc1 = createNode(3634);
	NODEPTR gc2 = createNode(3744);
	NODEPTR gc3 = createNode(999493);
	
	
	NODEPTR leafs = createNode(-1);;
	
	
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
	
	printList(leafs);
	
}
