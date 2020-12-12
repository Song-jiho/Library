#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*void addFirst(struct Node* target, char name[20], char auther[20], char year[5]) {
	struct Node* newNode = malloc(sizeof(struct Node));

	newNode->next = target->next;

	strcpy(newNode->book_name, name);
	strcpy(newNode->book_auther, auther);
	strcpy(newNode->book_year, year);

	free(newNode);

	target->next = newNode;
}

void add_book(struct Node* target, FILE* fp1) {
	int a;

	printf("�� ���� �߰��Ͻðڽ��ϱ�?: ");
	scanf("%d", &a);

	for (int i = 0; i < a; i++) {

		char name[20];
		char auther[20];
		char year[5];


		printf("%d���� å�� ������ �Է��Ͻÿ�\n", i + 1);

		printf("å�� �̸���?: ");
		scanf("%s", name);


		printf("������ �̸���?: ");
		scanf("%s", auther);


		printf("���� �⵵��?: ");
		scanf("%s", year);

		addFirst(target, name, auther, year);

		printf("=====================================\n");
	}

}*/

struct Node {

	char book_name[20];
	char book_auther[20];
	char book_year[5];
	char book_borrow[10];

	struct Book* next;

}node;

void user_interface() {
	printf("=================================\n");
	printf("1. å ��� �����ֱ�\n");
	printf("2. å �߰��ϱ�\n");
	printf("3. å �����ϱ�\n");
	printf("4. å ������\n");
	printf("5. å �ݳ��ϱ�\n");
	printf("6. å ������ ����\n");
	printf("7. �����ϱ�\n");
	printf("=================================\n");
}

void open_file(FILE* fp1) {
	int c;

	fp1 = fopen("data.txt", "r");

	while ((c = fgetc(fp1)) != EOF) {
		putchar(c);
	}
	printf("\n");
	fclose(fp1);
}

struct Node* Add_book(struct Node* list_head)
{
	int a;

	printf("�� ���� �Է��Ͻ� �̴ϱ�?: ");
	scanf("%d", &a);

	struct Node* newNode;
	for (int i = 0; i < a; i++) {
		printf("%d��° å ������ �Է��Ͻÿ�\n", i+1);
		char name[20];
		char auther[20];
		char year[5];

		printf("å �̸���? : ");
		scanf("%s", name);

		printf("å ���ڴ�? : ");
		scanf("%s", auther);

		printf("å ����⵵��? : ");
		scanf("%s", year);

		newNode = (struct Node*)malloc(sizeof(struct Node));

		strcpy(newNode->book_name, name);

		strcpy(newNode->book_auther, auther);

		strcpy(newNode->book_year, year);

		newNode->next = list_head;
		list_head = newNode;
	}
	return list_head;
}

void savefile(struct Node* list_head)
{
	struct Node* tmp;
	FILE* fp = fopen("data.txt", "w+");
	while (list_head != NULL) {
		tmp = list_head;
		fprintf(fp, "%s %s %s\n", tmp->book_name, tmp->book_auther, tmp->book_year);
		list_head = list_head->next;
	}
	fclose(fp);
	printf("������ �Ϸ��߽��ϴ�.\n");
}

struct Node* openfile(struct Node* list_head)
{
	struct Node* new_node;
	FILE* fp = fopen("data.txt", "r+");
	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.\n");
		return NULL;
	}
	while (1) {
		new_node = (struct Node*)malloc(sizeof(struct Node));
		if (feof(fp) != 0)
			break;
		fscanf(fp, "%s %s %s\n", new_node->book_name, new_node->book_auther, new_node->book_year);
		new_node->next = list_head;
		list_head = new_node;
	}
	fclose(fp);
	printf("������ �ҷ��Խ��ϴ�.\n");
	return list_head;
}

void Delbook(struct Node* list_head)
{
	struct Node* tmp = list_head;

	char name[20];
	printf("�����ϰ� ���� å�̸� : ");
	scanf("%s", name);

	while (list_head != NULL) {
		if (strcmp(list_head->book_name, name) == 0) {
			tmp->next = list_head->next;
			free(list_head);
		}
		tmp = list_head;
		list_head = list_head->next;
	}
	printf("�ܾ �����߽��ϴ�.\n");
}

void freeNodes(struct Node* head) {
	struct Node* last = head;
	struct Node* temp;

	while (last != NULL) {
		temp = last->next;
		free(last);
		last = temp;
	}
}

int main() {
	FILE* fp1;

	fp1 = fopen("data.txt", "a+");

	while (1) {
		int num;
		struct Node* head = (struct Node*)malloc(sizeof(struct Node));
		head->next = NULL;

		user_interface();
		printf("���Ͻô� ���񽺸� ������: ");
		scanf("%d", &num);
		num = (int)num;

		struct Node* curr = head->next;

		if (num == 1) {
			open_file(fp1);
			freeNodes(head);
			continue;
		}

		else if (num == 2) {
			head = Add_book(head);
			savefile(head);
			continue;
		}

		else if (num == 3) {
			Delbook(head);
			continue;
		}

		else if (num == 4) {
			continue;
		}

		else if (num == 5) {

		}

		else if (num == 6) {
			savefile(head);
			continue;
		}

		else if (num == 7) {
			break;
		}
		printf("111111111111111111111111111111\n");
		return 0;
	}
}