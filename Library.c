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

	printf("몇 권을 추가하시겠습니까?: ");
	scanf("%d", &a);

	for (int i = 0; i < a; i++) {

		char name[20];
		char auther[20];
		char year[5];


		printf("%d번쨰 책의 정보를 입력하시오\n", i + 1);

		printf("책의 이름은?: ");
		scanf("%s", name);


		printf("저자의 이름은?: ");
		scanf("%s", auther);


		printf("발행 년도는?: ");
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
	printf("1. 책 목록 보여주기\n");
	printf("2. 책 추가하기\n");
	printf("3. 책 삭제하기\n");
	printf("4. 책 빌리기\n");
	printf("5. 책 반납하기\n");
	printf("6. 책 데이터 저장\n");
	printf("7. 종료하기\n");
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

	printf("몇 권을 입력하실 겁니까?: ");
	scanf("%d", &a);

	struct Node* newNode;
	for (int i = 0; i < a; i++) {
		printf("%d번째 책 정보를 입력하시오\n", i+1);
		char name[20];
		char auther[20];
		char year[5];

		printf("책 이름은? : ");
		scanf("%s", name);

		printf("책 저자는? : ");
		scanf("%s", auther);

		printf("책 발행년도는? : ");
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
	printf("저장을 완료했습니다.\n");
}

struct Node* openfile(struct Node* list_head)
{
	struct Node* new_node;
	FILE* fp = fopen("data.txt", "r+");
	if (fp == NULL) {
		printf("파일을 열 수 없습니다.\n");
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
	printf("파일을 불러왔습니다.\n");
	return list_head;
}

void Delbook(struct Node* list_head)
{
	struct Node* tmp = list_head;

	char name[20];
	printf("삭제하고 싶은 책이름 : ");
	scanf("%s", name);

	while (list_head != NULL) {
		if (strcmp(list_head->book_name, name) == 0) {
			tmp->next = list_head->next;
			free(list_head);
		}
		tmp = list_head;
		list_head = list_head->next;
	}
	printf("단어를 삭제했습니다.\n");
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
		printf("원하시는 서비스를 고르세요: ");
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