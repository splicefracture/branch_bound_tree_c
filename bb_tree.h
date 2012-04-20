
#ifndef BB_TREE_H
#define BB_TREE_H

typedef struct tree_node * TREE;

typedef struct tree_node
{		
	int id;
	int data;
	
	TREE parent;
	TREE * children;
	
	int childrenCount;
	
	int pruned;
	int level;
		
}TREENODE;

TREE createHeadNode(int max);
TREE createTreeNode (int data);
void addChild(TREE* headPtr, TREE child);
void deleteChild(TREE* headPtr, int child);
int isParent(TREE* headPtr, TREE child);

int isEmpty(TREE head);

void printNode(TREE p);

TREE findChildById(TREE head, int id);


void printHelper(TREE head);
void printHeader();
void printLeafs();
void printTree(TREE head);

void printLevel(TREE head, int level);


void printLeafs(TREE head);

int isLeaf(TREE head);

TREE findNextLeaf(TREE head);

int compareTreePath(TREE curr, TREE target);

#endif
