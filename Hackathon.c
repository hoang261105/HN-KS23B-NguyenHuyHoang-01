#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}

void insertHead(Node** head, int value){
	Node* newNode = createNode(value);
	newNode->next = *head;
	*head = newNode;
}

void insertEnd(Node** head, int value){
	Node* newNode = createNode(value);
	Node* temp = *head;
	
	if(*head == NULL){
		printf("Danh sach trong\n");
		return;
	}
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertElement(Node** head, int position, int value){
	Node* newNode = createNode(value);
	Node* temp = *head;
	if(position == 0){
		*head = newNode;
		return;
	}
	
	if(position < 0 || position > sizeof(temp->data)){
		printf("Vi tri khong hop le\n");
		return;
	}
	
	for(int i=0; temp != NULL && i<position-1; i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void deleteHead(Node** head){
	if(*head == NULL) return;
	
	Node* temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

void deleteEnd(Node** head){
	Node* temp = *head;
	
	if(*head == NULL){
		printf("Danh sach trong\n");
		return;
	}
	
	if(temp->next == NULL){
		free(temp);
		*head = NULL;
		return;
	}
	
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

void deleteElement(Node** head, int value){
	Node* temp = *head;
	Node* prev = NULL;
	if(*head == NULL){
		printf("Danh sach trong\n");
		return;
	}
	
	if(temp != NULL && temp->data == value){
		*head = temp->next;
		free(temp);
		return;
	}
	
	while(temp != NULL && temp->data != value){
		prev = temp;
		temp = temp->next;
	}
	
	if(temp == NULL){
		printf("Gia tri can xoa khong hop le\n");
		return;
	}
	
	prev->next = temp->next;
	free(temp);
}

void searchElement(Node* head, int value){
	Node* temp = head;
	if(head == NULL){
		printf("Danh sach trong\n");
		return;
	}
	
	while(temp != NULL){
		if(temp->data == value){
			printf("Found\n");
			return;
		}
		temp = temp->next;
	}
	printf("Not Found\n");
}

void printList(Node* head){
	Node* temp = head;
	if(head == NULL){
		printf("Danh sach rong\n");
		return;
	}
	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main(){
	Node* head = NULL;
	int value, position;
	do{
		printf("-----------------MENU-------------------\n");
		printf("1. Them phan tu vao dau danh sach\n");
		printf("2. Them phan tu vao cuoi danh sach\n");
		printf("3. Chen phan tu vao vi tri cu the\n");
		printf("4. Xoa phan tu dau danh sach\n");
		printf("5. Xoa phan tu cuoi danh sach\n");
		printf("6. Xoa phan tu theo gia tri\n");
		printf("7. Tim kiem phan tu theo gia tri\n");
		printf("8. Hien thi danh sach lien ket\n");
		printf("0. Thoat\n");
		printf("Moi ban chon: ");
		
		int choice;
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Nhap gia tri can chen: ");
				scanf("%d", &value);
				insertHead(&head, value);
				break;
			case 2:
				printf("Nhap gia tri chen vao cuoi: ");
				scanf("%d", &value);
				insertEnd(&head, value);
				break;
			case 3:
				printf("Nhap vi tri can chen: ");
				scanf("%d", &position);
				printf("Nhap gia tri can chen: ");
				scanf("%d", &value);
				insertElement(&head, position, value);
				break;
			case 4:
				deleteHead(&head);
				break;
			case 5:
				deleteEnd(&head);
				break;
			case 6:
				printf("Nhap gia tri can xoa: ");
				scanf("%d", &value);
				deleteElement(&head, value);
				break;
			case 7:
				printf("Nhap gia tri can tim kiem: ");
				scanf("%d", &value);
				searchElement(head, value);
				break;
			case 8:
				printList(head);
				break;
			case 0:
				exit(0);
			default:
				printf("Vui long nhap lai!");
		}
	}while(1==1);
	return 0;
}
