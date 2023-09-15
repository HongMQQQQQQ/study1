#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ShoppingItem {
	
	char name[50]; // 商品名称
	int quantity; // 商品数量
	struct ShoppingItem* next; // 指向下一个节点的指针
 
};
struct ShoppingItem* shoppingList = NULL; // 初始化购物清单为空
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
	printf("输入序号选择操作：\n 0.tuichu\n1.addItem\n2.removeItem\n3.displayList\n4.updateQuantity\n5.clearList\n6.totalQuantity\n7.findItem\n8.sortList\n9.mergeLists\n10.deleteItem\n");
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

//1. 添加商品到购物清单：
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
 	else//头插
	{
	 	newItem->next=shoppingList;
		shoppingList=newItem;
	} 

 
}

//2. 从购物清单中移除商品：
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

//3. 查看购物清单：
void displayList() {
 	struct ShoppingItem* current = shoppingList;
 	printf("购物清单:\n");
 	while (current != NULL) {
 		printf("%s - 数量：%d\n", current->name, current->quantity);
 		current=current->next;
 		}
}

//4. 修改购物清单中商品的数量：
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

//5. 清空购物清单：
void clearList() {
 	while (shoppingList != NULL) {
 		struct ShoppingItem *temp=shoppingList;
 		shoppingList=shoppingList->next;
 		free(temp);
 	}
}

//6. 计算购物清单中商品的总数量：
int totalQuantity() {
 	struct ShoppingItem* current = shoppingList;
 	int total = 0;
 	while (current != NULL) {
 		total+=current->quantity;
 		current=current->next; 
 	}
 	return total;
}

//7. 查找购物清单中的商品：
void findItem(char itemName[]) {
 	struct ShoppingItem* current = shoppingList;
 	printf("查找商品 \"%s\" ：\n", itemName);
 	while (current != NULL) {
 		if (strcmp(current->name, itemName) == 0) {
 			printf("%s - 数量：%d\n", current->name, current->quantity);
 			return;
 		}
 		current=current->next; 
 	}
 	printf("未找到商品 \"%s\"。\n", itemName);
}

//8. 排序购物清单：
void sortList() {
 	struct ShoppingItem* current = shoppingList;
 	struct ShoppingItem* nextItem = NULL;
 	char tempName[50];
 	int tempQuantity;
 	while (current != NULL) {
 		nextItem = current->next;
 		while (nextItem != NULL) {
 			if (strcmp(current->name, nextItem->name) > 0) {
 			// 交换商品信息
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

//9. 合并购物清单：
//假设你有两个不同的购物清单，你希望将它们合并成一个。
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
 	struct ShoppingItem* current = *list1;

 	// 遍历到第一个购物清单的末尾
 	while(current->next)
 	{
 		current=current->next;
 	}
 	//补充循环语句；
 	// 将第二个购物清单连接到第一个清单的末尾
 	current->next = *list2;
 	*list2 = NULL; // 清空第二个购物清单的头指针，防止误用
}

//10. 删除购物清单中的商品：
//实现一个函数，可以根据商品名称删除购物清单中的商品项。如果有多个相同名称的商品，可以选择删除其中一个或全部。
void deleteItem(char itemName[], int deleteAll) {
 	struct ShoppingItem* current = shoppingList;
 	struct ShoppingItem* prev = NULL;
 	while (current != NULL) {
 		if (strcmp(current->name, itemName) == 0) {
 			if (prev == NULL) {
 			// 如果要删除的是第一个节点
 			struct ShoppingItem* temp = shoppingList;
 			shoppingList=shoppingList->next;
 			free(temp);
 			if (!deleteAll) break;
 			} 
	 		else {
 				// 如果要删除的不是第一个节点
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
 	else//头插
	{
	 	newItem->next=shoppingList2;
		shoppingList2=newItem;
	} 

 
}
