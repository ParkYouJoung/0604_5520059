#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink, * rlink;
} DListNode;

void init(DListNode* phead) {
	phead->llink = phead->rlink = phead;
}

void dinsert(DListNode* before, element data) {

	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));  //<1>
	newnode->data = data;  // <1>
	newnode->llink = before;  // <2>
	newnode->rlink = before->rlink; // <3>
	//	before->rlink->llink = newnode; // <5>
	//	before->rlink = newnode; // <4>
	before->rlink = newnode; // <4>
	newnode->rlink->llink = newnode; // <5>
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf(" %d", p->data);
		if (p->rlink != phead) {
			printf(" ->");
		}
	}
	printf(" (head)\n");
}

element ddelete(DListNode* head, DListNode* removed) {
	element r;
	if (removed == head) return;
	r = removed->data;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	return r;
}

main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	int choice, data, n;

	while (1) {

		printf("\n�޴�\n");
		printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
		printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
		printf("3. ����Ʈ ó�� ��� ����\n");
		printf("4. ����Ʈ ������ ��� ����\n");
		printf("5. ����Ʈ ���\n");
		printf("6. ����\n");
		printf("����: \n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("�߰��� ���ڸ� �Է��ϼ���: ");
			scanf("%d", &n);
			dinsert(head, n);
			break;
		case 2:
			printf("�߰��� ���ڸ� �Է��ϼ���: ");
			scanf("%d", &n);
			dinsert(head->rlink->rlink, n);
			break;
		case 3: 
			printf("ó�� ��尡 �����Ǿ����ϴ�.");
			element deleted; 
			deleted = ddelete(head, head->rlink); 
			break;
		case 4:
			printf("������ ��尡 �����Ǿ����ϴ�.");
			deleted = ddelete(head, head->llink);
			break;
		case 5:
			printf("����Ʈ ���");
			print_dlist(head);
			break;
		case 6:
			printf("���α׷� ����\n");
			return 0;
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���");

		}
	}
	return 0;

}