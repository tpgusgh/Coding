#include <stdio.h>
#include <stdlib.h>
typedef int element;
//0) Node구조체 작성
typedef struct Node{
	int data;
	struct Node *next;
}Node;
void printList(Node* head){
	Node *p; //1)처음위치부터 출력;
	if (head == NULL) return;
	p = head -> next;
	do {
		if(p == NULL) break;
		//2)데이터 출력
		printf("%d->",p->data);
		//3)ptr을 다음 주소로 저장
		p = p-> next;
	} while(p != head);   //4)조건

  //5) 마지막 노드 출력
	printf("%d->",p -> data);
	printf("\n");
}
Node* insertFirst(Node* head, element data){
	Node* node = (Node*)malloc(sizeof(Node));//Node 동적할당
	node->data = data;//
	if (head == NULL){
		head=node;// head의 주소로 새로운노드의 주소 저장
		node->next= head;//새로운노드의 다음 주소로 head 저장
	}
	else{
		node->next = head -> next;//새로운노드의 다음 주소로 head 저장	 
		head->next = node;//head의 다음노드 주소로 새로운노드의 주소 저장
	}
	return head;
}
Node* insertLast(Node* head, element data){
	Node* node = (Node*)malloc(sizeof(Node));//Node 동적할당
	node->data =data;
	if (head == NULL){
		head=node;// head의 주소로 새로운노드의 주소 저장
		node->next=head;//새로운노드의 다음 주소로 head 저장
	}
	else{
		node->next = head -> next;//
		head->next = node;//
		head =  node;//
	}
	return head;
}
int main() {
	Node *head=NULL;
	printf("처음위치에 연결\n");
	for(int i = 1;i< 5;i++){
		head = insertFirst(head,i);//첫위치에 삽잆하는 함수 호출	
	}
	printList(head);
	printf("마지막위치에 연결\n");
	for(int i = 11;i< 15;i++){
		head = insertLast(head,i);//마지막 위치에 삽입하는 함수 호출	
	}
	printList(head);

	return 0;
}


