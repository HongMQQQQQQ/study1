#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ShoppingItem {
	
	char name[50]; // ��Ʒ����
	int quantity; // ��Ʒ����
	struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
 
};
struct ShoppingItem* shoppingList = NULL; // ��ʼ�������嵥Ϊ��
struct ShoppingItem* shoppingList2 = NULL;
void addItem(char itemName[], int itemQuantity);
void addItem2(char itemName[], int itemQuantity);
void removeItem(char itemName[]);
void displayList();
void updateQuantity(char itemName[], int newItemQuantity);
void clearList();
int totalQuantity();
void findItem(char itemName[]);
void sortList();
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2);
void deleteItem(char itemName[], int deleteAll);
int main()
{
	char name[50];
	int number,xuhao,Itemnumber;
	struct ShoppingItem *p=NULL;
	printf("�������ѡ�������\n 0.tuichu\n1.addItem\n2.removeItem\n3.displayList\n4.updateQuantity\n5.clearList\n6.totalQuantity\n7.findItem\n8.sortList\n9.mergeLists\n10.deleteItem\n");
	while(1)
	{
		scanf("%d",&xuhao);
		if(xuhao==0)
		break;
		if(xuhao==1)
		{
			printf("How many Item need to add?\n");
			scanf("%d",&Itemnumber);
			for(int i=0;i<Itemnumber;i++)
			{
				scanf("%s %d",&name,&number);
				addItem(name,number);
				
			}
//				p=shoppingList;
//				while(p)
//				{
//					p=p->next;
//					printf("%s %d\n",p->name,p->quantity);
//					
//				}					
		}
		if(xuhao==2)
		{
			scanf("%s",&name);
			removeItem(name);
		}
		
		if(xuhao==3)
		displayList();
		
		if(xuhao==4)
		{
			scanf("%s %d",&name,&number);
			updateQuantity(name, number);
		}
		
		if(xuhao==5)
		clearList();
		
		if(xuhao==6)
		{
			number=totalQuantity();
			printf("%d",number);
		}
		
		if(xuhao==7)
		{
			scanf("%s",&name);
			findItem(name);
		}
		
		if(xuhao==8)
		{
			sortList();
		}
		
		if(xuhao==9)
		{
			printf("How many Item need to add?\n");
			scanf("%d",&Itemnumber);
			for(int i=0;i<Itemnumber;i++)
			{
				scanf("%s %d",&name,&number);
				addItem2(name,number);
				
			}
			mergeLists(&shoppingList,&shoppingList2);
		}
		
		if(xuhao==10)
		{
			scanf("%s %d",&name,&number);
			deleteItem(name,number);
		}
	
	}
	
	
	
	return 0;
	
}

//1. �����Ʒ�������嵥��
void addItem(char itemName[], int itemQuantity) {
 	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 	strcpy(newItem->name,itemName);
 	newItem->quantity=itemQuantity;
 	newItem->next=NULL; 
 	if(shoppingList==NULL)
 	{
 		//shoppingList=(struct ShoppingItem *)malloc(sizeof(struct ShoppingItem));
 		shoppingList=newItem;
 		
	}
 	else//ͷ��
	{
	 	newItem->next=shoppingList;
		shoppingList=newItem;
	} 

 
}

//2. �ӹ����嵥���Ƴ���Ʒ��
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

//3. �鿴�����嵥��
void displayList() {
 	struct ShoppingItem* current = shoppingList;
 	printf("�����嵥:\n");
 	while (current != NULL) {
 		printf("%s - ������%d\n", current->name, current->quantity);
 		current=current->next;
 		}
}

//4. �޸Ĺ����嵥����Ʒ��������
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

//5. ��չ����嵥��
void clearList() {
 	while (shoppingList != NULL) {
 		struct ShoppingItem *temp=shoppingList;
 		shoppingList=shoppingList->next;
 		free(temp);
 	}
}

//6. ���㹺���嵥����Ʒ����������
int totalQuantity() {
 	struct ShoppingItem* current = shoppingList;
 	int total = 0;
 	while (current != NULL) {
 		total+=current->quantity;
 		current=current->next; 
 	}
 	return total;
}

//7. ���ҹ����嵥�е���Ʒ��
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

//8. �������嵥��
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

//9. �ϲ������嵥��
//��������������ͬ�Ĺ����嵥����ϣ�������Ǻϲ���һ����
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
 	struct ShoppingItem* current = *list1;

 	// ��������һ�������嵥��ĩβ
 	while(current->next)
 	{
 		current=current->next;
 	}
 	//����ѭ����䣻
 	// ���ڶ��������嵥���ӵ���һ���嵥��ĩβ
 	current->next = *list2;
 	*list2 = NULL; // ��յڶ��������嵥��ͷָ�룬��ֹ����
}

//10. ɾ�������嵥�е���Ʒ��
//ʵ��һ�����������Ը�����Ʒ����ɾ�������嵥�е���Ʒ�����ж����ͬ���Ƶ���Ʒ������ѡ��ɾ������һ����ȫ����
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
		else {
 			prev = current;
 			current = current->next;
 		}
 	}
}


void addItem2(char itemName[], int itemQuantity) {
 	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 	strcpy(newItem->name,itemName);
 	newItem->quantity=itemQuantity;
 	newItem->next=NULL; 
 	if(shoppingList2==NULL)
 	{
 		//shoppingList=(struct ShoppingItem *)malloc(sizeof(struct ShoppingItem));
 		shoppingList2=newItem;
 		
	}
 	else//ͷ��
	{
	 	newItem->next=shoppingList2;
		shoppingList2=newItem;
	} 

 
}
