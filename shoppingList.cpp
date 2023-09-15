#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ShoppingItem {
 char name[50]; // ��Ʒ����
 int quantity; // ��Ʒ����
 struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
};

struct ShoppingItem* shoppingList = NULL; // ��ʼ�������嵥Ϊ��


void addItem(char itemName[], int itemQuantity) {
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	newItem->next=NULL;
	strcpy(newItem->name,itemName);
 	newItem->quantity=itemQuantity;
 	newItem->next=shoppingList;
	shoppingList=newItem;	
}
void removeItem(char itemName[]) {
		 struct ShoppingItem* current = shoppingList;
		 struct ShoppingItem* previous = NULL;
		 while (current != NULL) {
		 if (strcmp(current->name, itemName) == 0) {
		 if (previous != NULL) {
		 previous->next = current->next;
		 } 
		 else {
		 shoppingList = current->next;
		 }
		 free(current);
		 break;
		 }
		 previous=current;
		 current=current->next;	 
	 } 
 }
void displayList() {
	 struct ShoppingItem* current = shoppingList;
	 printf("�����嵥:\n");
	 while (current != NULL) {
	 printf("%s - ������%d\n", current->name, current->quantity);
	 current=current->next;
	 } 
}
void updateQuantity(char itemName[], int newItemQuantity) {
	 struct ShoppingItem* current = shoppingList;
	 while (current != NULL) {
		 if (strcmp(current->name, itemName) == 0) {
		 current->quantity=newItemQuantity;
		 break;
		 }
	 current = current->next;
	 } 
 }
void clearList() {
	 while (shoppingList != NULL) {
	 struct ShoppingItem*temp=shoppingList;
	 shoppingList=shoppingList->next;
	 free(temp);
	 } 
 }
int totalQuantity() {
 	struct ShoppingItem* current = shoppingList;
 	int total = 0;
	 while (current != NULL) {
     total+=current->quantity; 
	 current=current->next;
	 }
 	return total;
}

void findItem(char itemName[]) {
	 struct ShoppingItem* current = shoppingList;
	 printf("������Ʒ \"%s\" ��\n", itemName);
	 while (current != NULL) {
		 if (strcmp(current->name, itemName) == 0) {
		 printf("%s - ������%d\n", current->name, current->quantity);
		 return;
		 }
		 current=current->next;
	 }
	 printf("δ�ҵ���Ʒ \"%s\"��\n", itemName);
}
void sortList() {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* nextItem = NULL;
	char tempName[50];
	int tempQuantity;
	while (current != NULL) {
	nextItem = current->next;
		while (nextItem != NULL) {
			 if (strcmp(current->name, nextItem->name) > 0) {
			 // ������Ʒ��Ϣ
			strcpy(tempName,current->name);
			strcpy(current->name,nextItem->name);
			strcpy(nextItem->name,tempName);
			
			 tempQuantity = current->quantity;
			 current->quantity = nextItem->quantity;
			 nextItem->quantity = tempQuantity;
			}
	 		nextItem = nextItem->next;
		}	
	 	current = current->next;
	} 
 }
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
	struct ShoppingItem* current = *list1;
	// ��������һ�������嵥��ĩβ
	while(current->next!=NULL){
		current=current->next;
	}
	// ���ڶ��������嵥���ӵ���һ���嵥��ĩβ
	current->next = *list2;
	*list2 = NULL; // ��յڶ��������嵥��ͷָ�룬��ֹ����
}
void deleteItem(char itemName[], int deleteAll) {
struct ShoppingItem* current = shoppingList;
struct ShoppingItem* prev = NULL;
	 while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			if (prev == NULL) {
			 	// ���Ҫɾ�����ǵ�һ���ڵ�
				struct ShoppingItem* temp = shoppingList;
			 	shoppingList=shoppingList->next; 
				free(temp);
				if (!deleteAll) break;
			} 
			else {
				// ���Ҫɾ���Ĳ��ǵ�һ���ڵ�
				prev->next=current->next;
				free(current);
				current = prev->next;
				if (!deleteAll) break;
				}
		}
		else{
		 prev = current;
		 current = current->next;
		}
	}
}
struct ShoppingItem* create(){
	printf("�����Ʒ�������嵥,����0����\n");
	struct ShoppingItem* head=NULL,*q=NULL;	
	while(1){
		struct ShoppingItem* p = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
		p->next=NULL;
		scanf("%s",p->name);
		if(p->name[0]=='0')break;
		scanf(" %d",&p->quantity);
		if(head==NULL){
			head=p;
			q=head;
			head->next=NULL; 
		}
		else{
			q->next=p;
			q=p;
		}
	}
	return head;
}
int main()
{
	char Name[50];
	int num, itemQuantity,newItemQuantity,deleteAll;
	printf("��ѡ����Ĳ�����\n");
	printf("��������1�������Ʒ�������嵥������0�������\n");
	printf("��������2���ӹ����嵥���Ƴ���Ʒ\n");
	printf("��������3���鿴�����嵥\n") ;
	printf("��������4���޸Ĺ����嵥����Ʒ����Ʒ������\n");
	printf("��������5����չ����嵥\n");
	printf("��������6: ���㹺���嵥����Ʒ��������\n");
	printf("��������7�����ҹ����嵥�е���Ʒ\n") ;
	printf("��������8���������嵥\n");
	printf("��������9���ϲ������嵥\n");
	printf("��������10��ɾ�������嵥�е���Ʒ\n");
	printf("��������0���˳�����\n"); 
	
	scanf("%d",&num);
	while(num!='0'){
		if(num==1){
			while(1){
			scanf("%s ",Name);
			if(Name[0]=='0')break;
			scanf("%d",&itemQuantity);	
			addItem(Name,itemQuantity);				
			}

		}
		else if(num==2){
			scanf("%s",Name);
			removeItem(Name);
		}
		else if(num==3){
			displayList();
		}
		else if(num==4){
			scanf("%s %d",Name,&newItemQuantity);
			updateQuantity(Name,newItemQuantity);
		}
		else if(num==5){
			clearList();
		}
		else if(num==6){
			printf("�����嵥����Ʒ������%d\n",totalQuantity());
		}
		else if(num==7){
			scanf("%s",Name);
			findItem(Name);
		}
		else if(num==8){
			sortList();
			displayList();
		}
		else if(num==9){
			struct ShoppingItem * list2=create(); 
			mergeLists(&shoppingList,&list2);
			displayList();
		}
		else if(num==10){
			printf("��ֱ�������Ҫɾ�������嵥�е���Ʒ���ƣ��Լ�ѡ��ɾ������һ������ȫ��������0����ɾ��һ��������1����ɾ�����У�\n");
			scanf("%s %d",Name,&deleteAll);
			deleteItem(Name,deleteAll);
			displayList();
		}
		else{
			printf("��л����ʹ�ã��ڴ������´ι���\n!");
			break; 
		}
		scanf("%d",&num);
	}
	return 0;
}

