#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<stdbool.h>

#define SZ_MAX 5
#define PA_MAX 4


typedef struct _car//����ɹ���Ϣ 
{
    char bh[20]; //���
    char name[10]; //�������
    int year; //
    int month;//
    int day;
    char cgy[10];//�ɹ�Ա
    int num;     //����
    double dj;    //����
    char dw[5];  //������λ 
}car;

typedef struct _jd//
{
    car* lj;      //���

    int sz;

    int pa;
}jd;

void init_p(jd* p);//��������ռ�

void create_p(jd* p);//����

//void open_file(jd* p);//�����ļ�

void menu()
{
    printf("\t******�����㲿���ɹ�����******\n");
    printf("\t(1)����ɹ���Ϣ��");
    printf("\n\t(2)��ӡ�����㲿����Ϣ��");
    printf("\n\t(3)ָ���ɹ���ţ���ʾ�ɹ����㲿����Ϣ��");
    printf("\n\t(4)ָ���㲿�����ƣ���ʾ���㲿�������вɹ���Ϣ��");
    printf("\n\t(5)�����ɹ���ţ��޸Ĳɹ���Ϣ��");
    printf("\n\t(6)�����ɹ���ţ�ɾ���ɹ���Ϣ��");
    printf("\n\t(7)�������ƣ��ɹ�Ա��������ͳ�Ʋɹ���");
    printf("\n\t(0)�˳�����\n");
}

void lr(jd* p);//������¼����Ϣ

void print_branch(jd* p, int i);//��ӡ��֧


void dy(jd* p);//��������ӡ��Ϣ

void cz_bh(jd* p);//ͨ����Ų����㲿��

int search_bh(jd*p, char* bh);//����ֵ����

void search_lj(jd* p);//�����㲿��


void xg(jd* p);//�������޸��㲿����Ϣ

//void t_sc();//������ɾ���㲿����ͷ������Ϣ
//
//
//void ft_sc();//������ɾ���㲿������ͷ������Ϣ
//
//
//double  cgje();//������ͳ�Ʋɹ���� 
//
//
//void wj_bc();//�������ļ��ı���
//
//
//void wj_dq();//�������ļ��Ķ�ȡ
//
//
//void sf_nc();//�������ͷ��ڴ� 
//
//
//void check(char _bh[20]);//��֤Ψһ��

int main()
{
    int input ;
    jd p;

    init_p(&p);//��ʼ���ṹ��

    create_p(&p);//������̬�ռ�

    //open_file(&p);//�����ļ�

    do
    {
        menu();//�򿪲˵� 

        printf("���������ѡ��:");//����ѡ�� 

        scanf("%d", &input);//�Ӽ����н���һ��������ֱ�Ӳ��� 
        switch (input){
            case 1:
                lr(&p); //¼����Ϣ
                break;

            case 2:
                dy(&p);//��ӡ��Ϣ
                   break;

            case 3:
                cz_bh(&p);//ͨ����Ų����㲿��
                break;

            case 4://�����㲿��
                search_lj(&p);
                break;

            case 5:
                xg(&p); //�޸��㲿����Ϣ
                break;

            //case 6:
            //{
            //    int i;
            //    printf("�������Ǹ����ɹ���ţ�ɾ���ɹ���Ϣ\n");
            //    printf("��������Ҫɾ�����㲿���ı���Ƿ��������������㲿��(�ǻ�ֻ��һ���㲿����1�����ǰ�0):\n");
            //    scanf("%d", &i);
            //    if (i == 1)
            //    {


            //    break;
            //}

            //case 7:
            //{
            //    break;

        case 0:
            printf("��л�����´�ʹ�ã��ټ�");
            return 0;
            break;

        default:
            printf("����ǰ��������");
           
        }
    } while (input);

    return 0;
}


void init_p(jd* p) {//��ʼ���ṹ��
    p->lj = (car*)malloc(SZ_MAX*sizeof(car));//���������̬�ڴ�ռ�
    if (p->lj == NULL) {
        perror("melloc");
        return;
    }
    p->sz = 0;
    p->pa = PA_MAX;
}

void create_p(jd* p) {//�жϿռ��Ƿ񹻴洢
    car* tmp = NULL;
    if (p->sz == p->pa) {
        tmp = (car*)realloc(p->lj, (p->sz + PA_MAX) * sizeof(jd));
        if (tmp != NULL) {
            p->lj = tmp;
            p->pa += SZ_MAX;
        }
        else {
            perror("realloc");
            return 0;
        }
    }
}

//void open_file(jd* p) {//�����ļ�
//    FILE* pta = fopen("car_Procurement.txt", "r");//���ļ�
//    if (pta == NULL) {
//        perror("open_file");
//        return;
//    }
//    car tmp;
//    while (fread(&tmp, sizeof(car), 1, pta)) {//����һ���µı�����ȡ��ȡ���ļ�����Ϣ
//        p->lj[p->sz] = tmp;
//        create_p(p);
//        p->sz++;
//    }
//    fclose(pta);//�ر��ļ�
//    pta = NULL;
//}



void lr(jd* p) {//¼����Ϣ


    while (true) {
        int i = 0;
        char *bh; //���
 
        printf("��������    (����:1 2 3):"); scanf("%s", p->lj[p->sz].bh); //���
        if (p->sz > 0) {
           bh = p->lj[p->sz].bh;
           i = search_bh(p, bh);
           
           if (i >= 0) {
               printf("�����!");
           }
           else
               break;
        }
        if (p->sz == 0)
            break;
    }

    printf("�������㲿������(����:xxx):"); scanf("%s", p->lj[p->sz].name); //����
    
    while (true) {
        int i = 0;
        printf("���������     (����:2010/12/01):"); scanf("%d/%d/%d", &(p->lj[p->sz].year), &(p->lj[p->sz].month), &(p->lj[p->sz].day)); //����

            if ((p->lj[p->sz].month) == 2) {//���� 2��
                 if ((p->lj[p->sz].year) % 4 == 0 || (p->lj[p->sz].year) % 400 == 0 && (p->lj[p->sz].year) % 100 != 0) {
                     if ((p->lj[p->sz].day) < 29 && (p->lj[p->sz].day) > 0)
                        break;
                 }
            }

           else if ((p->lj[p->sz].month) == 2) {//ƽ����
                if ((p->lj[p->sz].day) < 28&& (p->lj[p->sz].day)>0)
                    break;
           }

           else if ((p->lj[p->sz].month) == 4 || (p->lj[p->sz].month) == 6 || (p->lj[p->sz].month) == 9 || (p->lj[p->sz].month) == 11) {//С��

                if ((p->lj[p->sz].day) <= 30&& (p->lj[p->sz].day)>0)
                    break;
           }

           else if ((p->lj[p->sz].month) == 1 || (p->lj[p->sz].month) == 3 || (p->lj[p->sz].month) == 5 || (p->lj[p->sz].month) == 7 || (p->lj[p->sz].month) == 8 || (p->lj[p->sz].month) == 10 || (p->lj[p->sz].month) == 12) {

                if ((p->lj[p->sz].day) <= 31&& (p->lj[p->sz].day)>0) //����
                    break;
           }

            printf("�������!\n");
        
    }
    
    printf("������ɹ�Ա����  (����:����):"); scanf("%s", p->lj[p->sz].cgy);//�ɹ�Ա 


    printf("������ɹ�����     (����:2):"); scanf("%d", &(p->lj[p->sz].num));//���� 


    printf("�������㲿������  (����:2.00):"); scanf("%lf", &(p->lj[p->sz].dj));//����


    printf("�������㲿������λ(����:SF):"); scanf("%s", p->lj[p->sz].dw); //��λ 

    printf("�㲿����Ϣ¼��ɹ�!\n");
    p->sz++;
    system("pause");
    system("cls");//����

}

void print_branch(jd* p, int i) {//��ӡ��֧
    
    printf("%-4s\t %-4s\t %d/%d/%d\t %s\t %-4d\t %-4.1lf\t %-4s\t\n",
        p->lj[i].bh,
        p->lj[i].name,
        p->lj[i].year,
        p->lj[i].month,
        p->lj[i].day,
        p->lj[i].cgy,
        p->lj[i].num,
        p->lj[i].dj,
        p->lj[i].dw);

}

void dy(jd* p)//��ӡ��Ϣ
{
    printf("**************************************************************\n");
    printf("*\t               ��ӭʹ�������㲿������ϵͳ            *\n");
    printf("**************************************************************\n");

    printf("*���\t*����\t*����\t        *�ɹ�Ա\t*����\t*����\t*��λ*\n");
    printf("**************************************************************\n");

    //��������
    for (int i = 0; i < p->sz; i++) {

        print_branch(p, i);//��ӡ��֧
      
        printf("\n");
    }
  
    system("pause");
    system("cls");//����
}

int search_bh(jd* p, char* bh) {//����ֵ����
    for (int i = 0; i < p->sz;  i++) {
        if (strcmp(p->lj[i].bh, bh) == 0)
            return i;
    }
    return -1;
}

void cz_bh(jd* p) {//ͨ����Ų����㲿��

    char bh[20]; //���

    printf("�������ѯ�ı��:"); scanf("%s", bh);

    int tmp=search_bh(p, bh);//����ֵ����

    if (tmp < 0) {//δ�ҵ�
        printf("δ�����Ҫ��ѯ�ı��!\n");
    }
    else if(tmp >= 0) {//�ҵ�
        printf("**************************************************************\n");
        printf("*\t               ��ӭʹ�������㲿������ϵͳ            *\n");
        printf("**************************************************************\n");

        printf("*���\t*����\t*����\t        *�ɹ�Ա\t*����\t*����\t*��λ*\n");
        printf("**************************************************************\n");
        print_branch(p, tmp);//��ӡ��֧
    }
        
    system("pause");
    system("cls");//����
}

void search_lj(jd* p) {//�����㲿��
    char name[10]; //�������
    printf("�������㲿������:"); scanf("%s", name);
    printf("**************************************************************\n");
    printf("*\t               ��ӭʹ�������㲿������ϵͳ            *\n");
    printf("**************************************************************\n");

    printf("*���\t*����\t*����\t        *�ɹ�Ա\t*����\t*����\t*��λ*\n");
    printf("**************************************************************\n");

    int num=0;//����
    for (int i = 0; i < p->sz; i++) {
        if (strcmp(p->lj[i].name, name) == 0) {
            print_branch(p, i);
            num++;
        }
    }
    if (num == 0)
        printf("δ��Ӵ��㲿��!\n");

    system("pause");
    system("cls");//����
}

void xg(jd* p) {//�������޸��㲿����Ϣ
    char bh[20]; //���
    printf("��������Ҫ�޸ĵı��:"); scanf("%s", bh);
    

    int tmp=search_bh(p, bh);//����ֵ����

    if (tmp < 0) {//δ�ҵ�
        printf("δ�����Ҫ�޸ĵı��!\n");
    }
    else if (tmp >= 0) {//�ҵ�
        printf("��������    (����:1 2 3):"); scanf("%s", p->lj[tmp].bh); //���
        printf("�������㲿������(����:xxx):"); scanf("%s", p->lj[tmp].name); //����
        printf("���������     (����:2010/12/01):"); scanf("%d/%d/%d", &(p->lj[tmp].year), &(p->lj[tmp].month), &(p->lj[tmp].day)); //����
        printf("������ɹ�Ա����  (����:����):"); scanf("%s", p->lj[tmp].cgy);//�ɹ�Ա 
        printf("������ɹ�����     (����:2):"); scanf("%d", &(p->lj[tmp].num));//���� 
        printf("�������㲿������  (����:2.00):"); scanf("%lf", &(p->lj[tmp].dj));//����
        printf("�������㲿������λ(����:SF):"); scanf("%s", p->lj[tmp].dw); //��λ 

        printf("�㲿����Ϣ�޸ĳɹ�!\n");

        system("pause");
        system("cls");//����
    }


}



//jd* cz_bh()//ͨ����Ų����㲿��
//{
//    char cz_bh[20]; //ͨ����Ų����㲿��
//
//    printf("������������ҵ�����ı��:\n");
//    scanf("%s", cz_bh);
//
//    jd* p = g_pHead;
//    while (p != NULL)
//    {
//        if (strcmp(p->lj.bh, cz_bh) == 0) //�ᱨ���� 
//        {
//            return p;
//        }
//
//        p = p->pnext;
//    }
//    return NULL;
//}

//jd* cz_mc()//ͨ�����Ʋ����㲿��
//{
//    char cz_mc[20];
//
//    printf("������������ҵ����������:\n");
//    scanf("%s", cz_mc);
//
//    jd* p = g_pHead;
//    while (p != NULL)
//    {
//        if (strcmp(p->lj.mc, cz_mc) == 0)
//        {
//            return p;
//        }
//
//        p = p->pnext;
//    }
//    return NULL;
//}
//
//void xg()
//{
//    int i = 0;
//
//    char xg_bh[20];
//
//    printf("��������Ҫ�޸ĵ��㲿���Ĳɹ����\n");
//    scanf("%s", xg_bh);
//
//    jd* p = g_pHead;
//    while (p != NULL)
//    {
//        if (strcmp(p->lj.bh, xg_bh) == 0) //p->li.bh��xg_bh�����õȺűȽ� 
//        {
//            printf("�����������޸ĵ������Ϣ:\n�޸ı���밴1\n�޸������밴2\n�޸������밴3\n�޸Ĳɹ�Ա�밴4\n�޸������밴5\n�޸ĵ����밴6\n�޸ĵ�λ�밴7\n���Ҫȫ���޸��밴0\n");
//            scanf("%d", &i);
//
//            if (i == 1)
//            {
//                printf("���ã��������޸ĺ�ı��:\n");
//                scanf("%s", p->lj.bh);
//            }
//
//            else if (i == 2)
//            {
//                printf("���ã��������޸ĺ������:\n");
//                scanf("%s", p->lj.mc);
//            }
//
//            else if (i == 3)
//            {
//                printf("���ã���������޸�����밴1���޸��·��밴2���޸�����밴3:\n");
//                scanf("%d", &i);
//
//                if (i == 1)
//                {
//                    printf("�������޸ĺ�����:\n\t");
//                    scanf("%d", &p->lj.year);
//                }
//
//                else if (i == 2)
//                {
//                    printf("�������޸ĺ���·�:\n\t");
//                    scanf("%d", &p->lj.month);
//                }
//
//                else if (i == 3)
//                {
//                    printf("�������޸ĺ�����:\n\t");
//                    scanf("%d", &p->lj.day);
//                }
//            }
//
//            else if (i == 4)
//            {
//                printf("���ã��������޸ĺ�Ĳɹ�Ա:\n");
//                scanf("%s", p->lj.cgy);
//            }
//
//            else if (i == 5)
//            {
//                printf("���ã��������޸ĺ������:\n");
//                scanf("%d", &p->lj.num);
//            }
//
//            else if (i == 6)
//            {
//                printf("���ã��������޸ĺ�ĵ���:\n");
//                scanf("%lf", &p->lj.dj);
//            }
//
//            else if (i == 7)
//            {
//                printf("���ã��������޸ĺ�ĵ�λ:\n");
//                scanf("%s", p->lj.dw);
//            }
//
//            else if (i == 0)
//            {
//                printf("���ã��������޸ĺ�ı�� ���� ���� �ɹ�Ա ���� ���� ��λ:\n");
//                scanf("%s %s %d %d %d %s %d %lf %s", p->lj.bh, p->lj.mc, &p->lj.year, &p->lj.month, &p->lj.day, p->lj.cgy, &p->lj.num, &p->lj.dj, p->lj.dw);
//            }
//
//            else
//            {
//                printf("�Բ����������������������������");
//                system("pause");
//                break;
//            }
//
//            printf("�޸ĳɹ�\n");
//            system("pause");
//            break;
//        }
//        p = p->pnext;
//    }
//
//    if (p == NULL)
//    {
//        printf("δ���ҵ��˲ɹ���Ŷ�Ӧ�㲿����������\n");
//        system("pause");
//    }
//}
//
//void t_sc()
//{
//    jd* p1;
//    char sc_bh[20];
//    printf("������������Ҫɾ�����㲿���ı��:");
//    scanf("%s", sc_bh);
//
//    //�����ͷ��� 
//    if (strcmp(g_pHead->lj.bh, sc_bh) == 0)
//    {
//        p1 = g_pHead;            //����ͷ��� 
//        g_pHead = g_pHead->pnext;// ��ͷ���ָ����һ����� 
//        free(p1); //ɾ�������ͷ�����ڴ� ,p1��������ͷ��㣬����ͷ����Ѿ�ָ����һ����� 
//        printf("��ϲ��ɾ���ɹ�\n");
//        system("pause");
//        return;
//    }
//
//    else
//    {
//        printf("�Բ���ɾ��ʧ�ܣ�����������ı��\n");
//        system("pause");
//        return;
//    }
//}
//
//void ft_sc()
//{
//    //�������ͷ���
//    char sc1_bh[20];
//    printf("������������Ҫɾ�����㲿���ı��:");
//    scanf("%s", sc1_bh);
//    jd* p = g_pHead;
//    jd* p2;                  //p2�Ǳ��ݵ� 
//    while (p2->pnext != NULL)
//    {
//        if (strcmp(p->pnext->lj.bh, sc1_bh) == 0)
//        {
//            p2 = p->pnext;             //����ͷ��� 
//            p->pnext = p->pnext->pnext;//�м���(Ҫɾ���Ľ��)����һ�������ͷ��㣬ͷ������һ��������м�ڵ�ĺ�һ����� �����м���ָ���������� 
//            free(p2);
//        }
//
//        if (p->pnext == NULL) //�м�����ɾ��.  NULL�ᾯ�棬'0'���� ��char������ָ��������ܱȽ� 
//        {
//            printf("��ϲ���ɹ�ɾ��\n");
//            system("pause");
//            return;
//        }
//
//        p = p->pnext;
//
//        if (p->pnext == NULL)//����ѭ������ʾ���������
//        {
//            printf("�Բ���ɾ��ʧ�ܣ�����������ı��\n");
//            system("pause");
//            return;
//        }
//    }
//
//}
//
//double  cgje()
//{
//    int i = 0, j = 0;
//    double sum = 0;
//    char tj_mc[20];
//    char tj_cgy[20];
//    int tj_rq_year;
//    int tj_rq_month;
//    int tj_rq_day;
//
//    jd* p = g_pHead;
//
//    printf("��������ʲô��ͳ�Ʋɹ����(���������밴1�����ݲɹ�Ա�밴2�����ݲɹ������밴3)\n");
//    scanf("%d", &i);
//
//    if (i == 1)
//    {
//        printf("�����뱻ͳ�����������:\n");
//        scanf("%s", tj_mc);
//
//        while (p != NULL)
//        {
//            if (strcmp(tj_mc, p->lj.mc) == 0)
//            {
//                sum += p->lj.dj * p->lj.num;
//                p = p->pnext;
//            }
//
//            else if (strcmp(tj_mc, p->lj.mc) != 0)
//            {
//                printf("����������������뷵�ز˵���������ͳ��\n");
//                return 0;
//            }
//        }
//        return sum;
//    }
//
//    else if (i == 2)
//    {
//        printf("�����뱻ͳ������Ĳɹ�Ա:\n");
//        scanf("%s", tj_mc);
//
//        while (p != NULL)
//        {
//            if (strcmp(tj_cgy, p->lj.cgy) == 0)
//            {
//                sum += p->lj.dj * p->lj.num;
//                p = p->pnext;
//            }
//
//            else if (strcmp(tj_cgy, p->lj.cgy) != 0)
//            {
//                printf("������Ĳɹ�Ա�����뷵�ز˵���������ͳ��\n");
//                return 0;
//            }
//        }
//        return sum;
//    }
//
//    else if (i == 3)
//    {
//        printf("����ͳ���밴1�����·�ͳ���밴2�������ͳ���밴3\n");
//        scanf("%d", &j);
//
//        if (j == 1)
//        {
//            printf("���������һ����ܽ��(����:2022):\n");
//            scanf("%d", &tj_rq_year);
//            while (p != NULL)
//            {
//                if (tj_rq_year == p->lj.year)
//                {
//                    sum += p->lj.dj * p->lj.num;
//                    p = p->pnext;
//                }
//            }
//            return sum;
//        }
//
//        else if (j == 2)
//        {
//            printf("���������һ�µ��ܽ��(����:2022):\n");
//            scanf("%d", &tj_rq_month);
//            while (p != NULL)
//            {
//                if (tj_rq_month == p->lj.month)
//                {
//                    sum += p->lj.dj * p->lj.num;
//                    p = p->pnext;
//                }
//            }
//            return sum;
//        }
//
//        else if (j == 3)
//        {
//            printf("���������һ����ܽ��(����:2022):\n");
//            scanf("%d", &tj_rq_day);
//            while (p != NULL)
//            {
//                if (tj_rq_day == p->lj.day)
//                {
//                    sum += p->lj.dj * p->lj.num;
//                    p = p->pnext;
//                }
//            }
//            return sum;
//        }
//    }
//}
//
//void wj_bc()
//{
//    //���ļ�
//    FILE* fp = fopen("C:\\Users\\joker\\dy.data", "w");
//
//    if (fp == NULL)
//    {
//        printf("���ļ�ʧ��\n");
//        return;
//    }
//
//    jd* njd = g_pHead;
//    while (njd != NULL)
//    {
//        fwrite(&njd->lj, 1, sizeof(car), fp); //�ṹ������ ��kb ��ʲô��ʽ 
//        njd = njd->pnext;
//    }
//
//    //�ر��ļ�
//    fclose(fp);
//    printf("���ݱ���ɹ�\n");
//    system("pause");
//    system("cls");
//    return;
//}
//
//void wj_dq()
//{
//    //���ļ�
//    FILE* fp = fopen("C:\\Users\\joker\\dy.data", "r");
//    if (fp == NULL)
//    {
//        printf("��Ǹ���ļ�����Ϊ��\n");
//        return;
//    }
//
//    //���ļ�
//    car lj;
//    while (fread(&lj, 1, sizeof(car), fp)) //feof�ж��Ƿ�ĩβ ,���ǻ��һ�� 
//    {
//        //����һ���½��
//        jd* djd = (jd*)malloc(sizeof(car));
//        djd->pnext = NULL;
//
//        memcpy(djd, &lj, sizeof(lj)); //���ͷ�ļ�<string.h> 
//
//        //ͷ�巨
//        if (g_pHead == NULL) //û�н�㣬������ 
//        {
//            g_pHead = djd;
//        }
//        else                //�н��
//        {
//            djd->pnext = g_pHead;//�½�����һ��Ϊͷ���
//            g_pHead = djd;      //��ͷ���Ϊ����Ľ�� 
//        }
//    }
//
//    //�ر��ļ�
//    fclose(fp);
//    printf("�������ݳɹ���\n");
//    system("pause");
//}
//
//void sf_nc()
//{
//    jd* sf_jd = (jd*)malloc(sizeof(jd));
//    sf_jd->pnext = NULL;
//    //ͷ�巨
//    if (g_pHead == NULL) //û�н�㣬������ 
//    {
//        g_pHead = sf_jd;
//    }
//    else                //�н��
//    {
//        sf_jd->pnext = g_pHead;//�½�����һ��Ϊͷ���
//        g_pHead = sf_jd;      //��ͷ���Ϊ����Ľ�� 
//    }
//
//    while (sf_jd != NULL)
//    {
//        sf_jd = sf_jd->pnext;
//        free(sf_jd);
//    }
//}
//
//void check(char _bh[20])
//{
//    jd* p = g_pHead;
//    while (p->pnext != 0)
//    {
//        if (strcmp(p->lj.bh, _bh) == 0)
//        {
//            printf("����ظ���������\n");
//            scanf("%s", p->lj.bh);
//            check(_bh);
//        }
//        p = p->pnext;
//    }
//}
