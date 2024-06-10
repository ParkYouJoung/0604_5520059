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

		printf("\n메뉴\n");
		printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
		printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
		printf("3. 리스트 처음 노드 삭제\n");
		printf("4. 리스트 마지막 노드 삭제\n");
		printf("5. 리스트 출력\n");
		printf("6. 종료\n");
		printf("선택: \n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("추가할 숫자를 입력하세요: ");
			scanf("%d", &n);
			dinsert(head, n);
			break;
		case 2:
			printf("추가할 숫자를 입력하세요: ");
			scanf("%d", &n);
			dinsert(head->rlink->rlink, n);
			break;
		case 3: 
			printf("처음 노드가 삭제되었습니다.");
			element deleted; 
			deleted = ddelete(head, head->rlink); 
			break;
		case 4:
			printf("마지막 노드가 삭제되었습니다.");
			deleted = ddelete(head, head->llink);
			break;
		case 5:
			printf("리스트 출력");
			print_dlist(head);
			break;
		case 6:
			printf("프로그램 종료\n");
			return 0;
		default:
			printf("잘못된 선택입니다. 다시 입력해주세요");

		}
	}
	return 0;

}