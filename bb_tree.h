
typedef struct node * NODEPTR;

typedef struct node{
	
	int id;
	int data;
	
	int childrenCount;
	
	NODEPTR parent;
	
	NODEPTR* children;
	
}NODE;

NODEPTR createNode (int data);

void addChild(NODEPTR* headPtr, NODEPTR child);
void deleteChild(NODEPTR* headPtr, int child);

int isParent(NODEPTR* headPtr, NODEPTR child);

int isEmpty(NODEPTR head);

void printList(NODEPTR head);
void printHelper(NODEPTR head, int level);

void printPathUp(NODEPTR leaf);
