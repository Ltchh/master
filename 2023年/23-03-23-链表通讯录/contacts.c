#include "contacts.h"

void window() {//ϵͳ����
	system("pause");//��ͣ
	system("cls");//����
}

Contacts_n* create_heap(Contacts_n* head) {
	
	head = MALLOC(Contacts_n);
	if (NULL == head) {
		perror("create_heap");
		return ;
	}
	head->next = NULL;
	return head;
}

void Contacts_file(Contacts_n* head) {//�����ļ�
	FILE* tmp = fopen("Contacts_F.txt", "r");//���ļ�
	if (NULL == tmp) {
		perror("contacts_file");
		return;
	}

	Contacts_n *node=NULL;
	
	node = create_heap(node);

	while (fread(&node, sizeof(Contacts_n), 1, tmp)) {//��ȡ�ļ�
		node->next = head->next;
		head->next = node;
	}

	fclose(tmp);//�ر��ļ�
	tmp = NULL;
}


int sort(Contacts_n* head){//����
	int len = 0;
	head = head->next;
	
	while (head) {
		len++;
		head = head->next;
	}
	return len;
}

void print(Contacts_n* head) {//��Ļ�����֧
	printf("%-10s %-12s %-12s %s\n",
		head->data.name,
		head->data.mobilenum,
		head->data.fixenum,
		head->data.companynum);
}

Contacts_n* query(Contacts_n* head, char* name) {//���ҷ�֧
	int len = sort(head);
	head = head->next;
	while (head) {
		if (strcmp(head->data.name, name) == 0)
			return head;
		head = head->next;
	}
	return head;
}

void Contacts_ADD(Contacts_n* head) {//����
	Contacts_n* node = NULL;
	node=create_heap(node);

	printf("name:");
	scanf("%s", node->data.name);
	printf("tele:");
	scanf("%s", node->data.mobilenum);
	printf("QQ:");
	scanf("%s", node->data.fixenum);
	printf("company tele:");
	scanf("%s", node->data.companynum);

	//�������Ľڵ�����ָ��
	node->next = head->next;
	head->next = node;
	printf("\nincrease success!\n");
}

void contacts_delete(Contacts_n* head) {//ɾ��**************������

	char name[10];
	printf("plass enter the name your wnt to delete:");
	scanf("%s", name);

	Contacts_n* perp= query(head,name);
	
	while (head->next!=perp) {//ָ�����ֱ�ӱȽ� 
			head = head->next;
	}
	head->next = perp->next;

	free(perp);
	perp = NULL;

	//else {
	//	Contacts_n* t = perp->next;

	//	perp->data = perp->next->data;//��һ�����ݴ���pfind��������
	//	perp->next = perp->next->next;//��ָ����ָ����һ��ָ����
	//	free(t);
	//	t = NULL;

	//}
}

void contacts_modify(Contacts_n* head) {//�޸ķ�֧
	char name[10];

	printf("plass enter the name your want to modify:");
	scanf("%s", name);

	Contacts_n* perp = query(head, name);
	if (perp != NULL) {
		printf("name:");
		scanf("%s", perp->data.name);
		printf("tele:");
		scanf("%s", perp->data.mobilenum);
		printf("QQ:");
		scanf("%s", perp->data.fixenum);
		printf("company tele:");
		scanf("%s", perp->data.companynum);
		printf("modified successfully!\n");
	}
	else
		printf("not found!\n");
}

void contacts_query(Contacts_n* head) {//����
	char name[10];
	printf("plass enter the name you want to queery:");
	scanf("%s", name);

	Contacts_n* perp = query(head, name);
	if (NULL == perp)
		printf("the search does not exist!\n");
	else {
		printf("%-10s %-12s %-12s %s\n", "name", "tele", "QQ", "company tele");
		print(perp);
	}
}

void Constacts_SORT(Contacts_n* head) {//������������
	int len = sort(head);
	
	Contacts_n* x, * y;

	Contacts_d perp;

	for (int i = 0; i < len - 1; i++) {	
		x = head->next;
		y = x->next;

		for (int j = 0; j < len - i - 1; j++) {
			if ((strcmp(x->data.name, y->data.name)) > 0) {
				perp = x->data;
				x->data = y->data;
				y->data = perp;
			}
			x = x->next;
			y = x->next;
		}
	}
	printf("\nsort success!\n");
}

void Constacts_SORT_1(Contacts_n* head) { //�����ַ����

	int len = sort(head);

	Contacts_n* perp, * p, * q, * t;

	for (int i = 0; i < len-1; i++){
		perp = head;
		p = head->next;
		q = p->next;//head->next->next;

		for (int j = 0; j <len-i-1; j++){
			if (strcmp(p->data.name, q->data.name)>0){//head 5>4>3>2>1>0
				perp->next = q;						  //head->next=head->next->next
															//ͷָ��->4				
				p->next = q->next;				      //head->next=head->next->next->next
															//�׽ڵ�ָ��->3
				q->next = p;						  //head->next=head->next->next
															//4�ڵ�ָ��5

				//ԭ����perp 1 - p 2 - q 3 ����� perp 1 - q 2 - p 3
				//�����Ǹ�ԭ�� perp 1 - p 2 - q 3
				t = p;
				p = q;
				q = t;
			}
			// perp 1 - p 2 - q 3 ����
			perp = perp->next;
			p = p->next;
			q = q->next;

		}

	}



}

void Contacts_DISPLAY(Contacts_n* head) {//��ʾ
	head = head->next;
	printf("%-10s %-12s %-12s %s\n", "name", "tele", "QQ", "company tele");
	while (head) {

		print(head);
		head = head->next;
		
	}

}



void Contacts_exit(Contacts_n* head) {//�˳�-����������ڴ�

	FILE* tmp=fopen("Contacts_F.txt","w");//���ļ� -д��
	if (NULL == tmp) {
		perror("Contacts_exit");
		return;
	}
	head = head->next;

	while (head){//��ȡ�ļ�
		fwrite(head, sizeof(Contacts_n), 1, tmp);
		head= head->next;
	}

	fclose(tmp); //�ر��ļ�
	tmp = NULL;


	Contacts_n* pur;
	while (head){
		pur = head;
		head = head->next;

		free(pur);
		pur = NULL;
	}
}
