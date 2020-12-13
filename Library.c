#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int head_book;

typedef struct Node {

	char book_name[20];
	char book_auther[20];
	char book_year[5];
	char book_borrow[10];

	struct Nook* next;

}node;

struct Node* search_book(struct Node* list_head, char* name)
{
	while (list_head != NULL) {
		if (strcmp(list_head->book_name, name) == 0)
			return list_head;
		list_head = list_head->next;
	}
	return list_head;
}

void user_interface() {
	printf("=================================\n");
	printf("1. å ��� �����ֱ�\n");
	printf("2. å �߰��ϱ�\n");
	printf("3. å �����ϱ�\n");
	printf("4. å ������\n");
	printf("5. å �ݳ��ϱ�\n");
	printf("6. �����ϱ�\n");
	printf("=================================\n");
}

void txtLoad(struct Node* FirstMember) {   // MemberList.txt ���Ͽ��� ������ �ҷ����� �Լ�
	FILE* load = fopen("data.txt", "rt");
	if (load != NULL) {
		struct Node* MidNode = NULL;
		int loadfp;
		while (feof(load) == 0) {
			MidNode = (struct Node*)malloc(sizeof(struct Node));
			MidNode->next = NULL;
			fscanf(load, "%s %s %s %s\n", &MidNode->book_name, &MidNode->book_auther, &MidNode->book_year, &MidNode->book_borrow);

			if (FirstMember == NULL) {
				FirstMember = MidNode;
			}

			else {
				struct Node* temp = FirstMember;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = MidNode;
			}
		}
	}
}

void savefile(struct Node* list_head, int noin)
{
	FILE* fp = fopen("data.txt", "a+");
	while ((*list_head->book_name) != noin) {
		fprintf(fp, "\n%s %s %s %s", list_head->book_name, list_head->book_auther, list_head->book_year, list_head->book_borrow);
		list_head = list_head->next;
	}
	fclose(fp);
	printf("������ �Ϸ��߽��ϴ�.\n");
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
		char borrow[10] = " �������";

		printf("å �̸���? : ");
		scanf("%s", name);

		printf("å ���ڴ�? : ");
		scanf("%s", auther);

		printf("å ����⵵��? : ");
		scanf("%s", year);

		newNode = (struct Node*)malloc(sizeof(struct Node));

		newNode->next = list_head;
		list_head = newNode;

		strcpy(newNode->book_name, name);

		strcpy(newNode->book_auther, auther);

		strcpy(newNode->book_year, year);

		strcpy(newNode->book_borrow, borrow);

	}
	return list_head;
}

/*struct Node* Del_book(struct Node* list_head, struct Node* (*func)(struct Node*, char*))
{
	struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
	struct Node* seek = list_head;
	struct Node* seek1 = list_head;
	struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
	struct Node* newNode;

	char name[20];
	printf("������ å �̸� : ");
	scanf("%s", name);

	while (seek != NULL) {
		if (strcmp(seek, name) == 0)
			tmp = seek;
		seek = seek->next;
	}

	printf("%s\n", tmp);

	while (seek1->next != NULL) {
		if (seek1->book_name == tmp) {
			seek1 = seek1->next;
			free(seek);
			printf("���� �Ϸ�\n");
		}

		list_head = list_head->next;
		prev = seek1;
		seek1 = seek1->next;
	}
}*/

struct Node* sub(struct Node* list_head){
	FILE* fp = fopen("data.txt", "r+");
	struct Node* Temp = list_head;
	struct Node* tmp = list_head;
	char name[20];
	printf("������ å �̸� : ");
	scanf("%s", name);

	tmp = tmp->next;

	while (tmp->book_name != NULL) {
		if (strcmp(list_head->book_name, name) == 0) {
			tmp = tmp->next;
			list_head = list_head->next;
		}
		fprintf(fp, "%s %s %s %s\n", list_head->book_name, list_head->book_auther, list_head->book_year, list_head->book_borrow);
		tmp = tmp->next;
		list_head = list_head->next;
	}
	fclose(fp);
	list_head = Temp;
}

struct Node* Borrow_book(struct Node* list_head) {
	FILE* fp = fopen("data.txt", "r+");

	struct Node* tmp = list_head;
	char name[20];
	int i;
	char* pch;
	
	struct Node* Temp = list_head;

	printf("������ ���� å�̸� �Է� : ");
	scanf("%s", name);
	tmp = tmp->next;
	list_head = list_head->next;

	while (tmp != NULL) {
		if (strcmp(list_head->book_name, name) == 0){
			if (strcmp(list_head->book_borrow, "������") == 0) {
				printf("��� �����ϴ� �˼��մϴ�.\n");
				break;
			}
			else {
				pch = strstr(list_head->book_borrow, "�������");
				strncpy(pch, "������", 10);
				printf("����Ǿ����ϴ�\n");
			}
	}
		fprintf(fp, "%s %s %s %s\n", list_head->book_name, list_head->book_auther, list_head->book_year, list_head->book_borrow);
		tmp = tmp->next;
		list_head = list_head->next;
}
	fclose(fp);
	list_head = Temp;
}

struct Node* Back_book(struct Node* list_head) {
	FILE* fp = fopen("data.txt", "r+");

	struct Node* tmp = list_head;
	char name[20];
	char* pch;

	struct Node* Temp = list_head;

	printf("�ݳ��ϰ� ���� å�̸� �Է� : ");
	scanf("%s", name);
	tmp = tmp->next;
	list_head = list_head->next;

	while (tmp != NULL) {
		if (strcmp(list_head->book_name, name) == 0) {
			if (strcmp(list_head->book_borrow, "�������") == 0) {
				printf("��� �̹� �ֽ��ϴ�.\n");
				break;
			}
			else {
				pch = strstr(list_head->book_borrow, "������");
				strncpy(pch, "�������", 10);
				printf("�ݳ��Ǿ����ϴ�\n");
			}
		}
		fprintf(fp, "%s %s %s %s\n", list_head->book_name, list_head->book_auther, list_head->book_year, list_head->book_borrow);
		tmp = tmp->next;
		list_head = list_head->next;
	}
	fclose(fp);
	list_head = Temp;
}




int main(){
	FILE* fp1;
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));

	while (1) {
		int num;

		head_book = *head->book_name;

		user_interface();
		printf("���Ͻô� ���񽺸� ������: ");
		scanf("%d", &num);
		num = (int)num;

		head->next = NULL;

		txtLoad(head);

		if (num == 1) {
			fp1 = fopen("data.txt", "a+");
			open_file(fp1);
			fclose(fp1);
			continue;
		}

		else if (num == 2) {
			fp1 = fopen("data.txt", "a+");
			head = Add_book(head);
			savefile(head, head_book);
			fclose(fp1);
			continue;
		}

		else if (num == 3) {
			fp1 = fopen("data.txt", "a+");
			head = sub(head, search_book, head_book);
			fclose(fp1);
			continue;
		}

		else if (num == 4) {
			fp1 = fopen("data.txt", "a+");
			open_file(fp1);
			Borrow_book(head);
			fclose(fp1);
			continue;
		}

		else if (num == 5) {
			fp1 = fopen("data.txt", "a+");
			open_file(fp1);
			Back_book(head);
			fclose(fp1);
			continue;
		}

		else if (num == 6) {
			break;
			continue;
		}
		else {
			printf("�ٽ��Է��ϼ���\n");
			continue;
		}
	}
	free(head);
	printf("111111111111111111111111111111\n");
	return 0;
	
}