#include <stdio.h>
#include <stdlib.h>

#define	PRACTICE

#pragma warning (disable: 4326 4996 6011 6031)

typedef struct node {
	int nData;
	struct node *link;
}	Node, *NodePtr;

void main()
{
	NodePtr Create2(void);
	NodePtr Create5(void);
	NodePtr CreateN(int nCtr);
	void PrintList(NodePtr pList);
	void FreeList(NodePtr pList);

	NodePtr pHead;
#ifndef PRACTICE
	pHead = Create2();	// Create5();
	PrintList(pHead);
	FreeList(pHead);
#else
	while (1) {
		printf("? ");
		int nCtr;
		scanf("%d", &nCtr);
		if (nCtr <= 0)
			break;
		pHead = CreateN(nCtr);
		PrintList(pHead);
		FreeList(pHead);
		putchar('\n');
	}
	printf("Bye, ...\n\n");
#endif
}

NodePtr Create2()
{
	NodePtr pFirst, pSecond;
	// first node
	pFirst = (NodePtr)malloc(sizeof(Node));
	pFirst->nData = 10;
	// second node
	pSecond = (NodePtr)malloc(sizeof(Node));
	pSecond->nData = 20;
	pFirst->link = pSecond;
	// end
	pSecond->link = NULL;
	return pFirst;
}

NodePtr Create5()
{
	NodePtr pFirst, pNew, pLast;
	// first node
	pFirst = (NodePtr)malloc(sizeof(Node));
	pFirst->nData = 10;
	pLast = pFirst;
	// second node
	pNew = (NodePtr)malloc(sizeof(Node));
	pNew->nData = 20;
	pLast = pLast->link = pNew;
	// third node
	pNew = (NodePtr)malloc(sizeof(Node));
	pNew->nData = 30;
	pLast = pLast->link = pNew;
	// fourth node
	pNew = (NodePtr)malloc(sizeof(Node));
	pNew->nData = 40;
	pLast = pLast->link = pNew;
	// fifth node
	pNew = (NodePtr)malloc(sizeof(Node));
	pNew->nData = 50;
	pLast = pLast->link = pNew;
	// end
	pLast->link = NULL;
	return pFirst;
}

NodePtr CreateN(int nCtr)
{
	NodePtr pFirst, pNode, pLast;
	// first
	pFirst = (NodePtr)malloc(sizeof(Node));
	pFirst->nData = 1;
	pLast = pFirst;
	// from 2 to nCtr
	for (int i = 2; i <= nCtr; i++) {
		pNode = (NodePtr)malloc(sizeof(Node));
		pNode->nData = i;
		pLast = pLast->link = pNode;
	}
	pLast->link = NULL;
	return pFirst;
}

void PrintList(NodePtr pList)
{
	NodePtr ptr = pList;
	while (ptr) {
		printf("%d ", ptr->nData);
		ptr = ptr->link;
	}
	putchar('\n');
}

void FreeList(NodePtr pList)
{
	if (pList) {
		FreeList(pList->link);
		delete pList;
	}
}
