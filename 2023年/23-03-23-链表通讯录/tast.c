#include "contacts.h"


//system("pause");//��ͣ
//system("cls");//����

void neum() {
	printf("\n*********************\n");
	printf("**    ** 1.ADD     **\n");
	printf("** ͨ ** 2.DELETE  **\n");
	printf("**    ** 3.MODIFY  **\n");
	printf("** Ѷ ** 4.QUERY   **\n");
	printf("**    ** 5.SORT    **\n");
	printf("** ¼ ** 6.DISPLAY **\n");
	printf("**    ** 0.EXIT    **\n");
	printf("*********************\n");
}

int main() {

	Contacts_n* head=NULL;
	head=create_heap(head);

	Contacts_file(head);
	int function;

	do {
		neum();

		printf("��ѡ��:");
		scanf("%d", &function);

		switch (function) {
		case ADD:
			Contacts_ADD(head);
			
			window();
			break;

		case DELETE:
			contacts_delete(head);
			window();
			break;

		case MODIFY:
			contacts_modify(head);
			window();
			break;

		case QUERY:
			contacts_query(head);
			window();
			
			break;

		case SORT:
			Constacts_SORT_1(head);
			window();
			break;

		case DISPLAY:
			Contacts_DISPLAY(head);
			window();
			break;

		case EXIT:
			Contacts_exit(head);
			printf("\n ****�˳� �ɹ�****\n");
			break;

		default:
			printf("\n ****ѡ�� ����****\n");
		}

	} while (function);

	return 0;
}