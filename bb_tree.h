
#ifndef BB_TREE_H
#define BB_TREE_H

typedef struct tree_node * TREE;
typedef struct list_node * LIST;

typedef struct tree_node
{		
	int id;
	int data;
	
	TREE parent;
	LIST children;
		
	int pruned;	
		
}TREENODE;

typedef struct list_node{
	
	int id;
	TREE data;
	LIST next;	

}LISTNODE;

LIST createListNode (TREE t);

void insertListNode(LIST* headPtr, LIST temp);
void deleteListNode(LIST* headPtr, int target);
int  isListEmpty(LIST head);
void printList(LIST head);

TREE createTreeNode (int data);
void addChild(TREE* headPtr, TREE child);
void deleteChild(TREE* headPtr, int child);
int isParent(TREE* headPtr, TREE child);

int isEmpty(TREE head);

LIST getLeafs();


void printNode(TREE p);
TREE findChildById(TREE* head, int id);
void addList(LIST* headPtr, TREE n);
void findLeafs(TREE tree, LIST leafs );
void findPath(TREE leaf, LIST* path );

void printLeafs();
void printTree(TREE head);
void printHelper(TREE head, int level);
void printPathUp(TREE leaf);

//TREE findChildByData(TREE* head, int data);

#endif
