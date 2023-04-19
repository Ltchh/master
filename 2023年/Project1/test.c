#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<stdbool.h>

#define SZ_MAX 5
#define PA_MAX 4


typedef struct _car//定义采购信息 
{
    char bh[20]; //编号
    char name[10]; //零件名称
    int year; //
    int month;//
    int day;
    char cgy[10];//采购员
    int num;     //数量
    double dj;    //单价
    char dw[5];  //供货单位 
}car;

typedef struct _jd//
{
    car* lj;      //零件

    int sz;

    int pa;
}jd;

void init_p(jd* p);//申请堆区空间

void create_p(jd* p);//扩容

//void open_file(jd* p);//加载文件

void menu()
{
    printf("\t******汽车零部件采购程序******\n");
    printf("\t(1)输入采购信息。");
    printf("\n\t(2)打印所有零部件信息。");
    printf("\n\t(3)指定采购编号，显示采购的零部件信息。");
    printf("\n\t(4)指定零部件名称，显示该零部件的所有采购信息。");
    printf("\n\t(5)给定采购编号，修改采购信息。");
    printf("\n\t(6)给定采购编号，删除采购信息。");
    printf("\n\t(7)给定名称，采购员或日期来统计采购金额。");
    printf("\n\t(0)退出程序\n");
}

void lr(jd* p);//函数：录入信息

void print_branch(jd* p, int i);//打印分支


void dy(jd* p);//函数：打印信息

void cz_bh(jd* p);//通过编号查找零部件

int search_bh(jd*p, char* bh);//返回值查找

void search_lj(jd* p);//查找零部件


void xg(jd* p);//函数：修改零部件信息

//void t_sc();//函数：删除零部件是头结点的信息
//
//
//void ft_sc();//函数：删除零部件不是头结点的信息
//
//
//double  cgje();//函数：统计采购金额 
//
//
//void wj_bc();//函数：文件的保存
//
//
//void wj_dq();//函数：文件的读取
//
//
//void sf_nc();//函数：释放内存 
//
//
//void check(char _bh[20]);//验证唯一性

int main()
{
    int input ;
    jd p;

    init_p(&p);//初始化结构体

    create_p(&p);//创建动态空间

    //open_file(&p);//加载文件

    do
    {
        menu();//打开菜单 

        printf("请输入你的选择:");//输入选择 

        scanf("%d", &input);//从键盘中接收一个整形来直接操作 
        switch (input){
            case 1:
                lr(&p); //录入信息
                break;

            case 2:
                dy(&p);//打印信息
                   break;

            case 3:
                cz_bh(&p);//通过编号查找零部件
                break;

            case 4://查找零部件
                search_lj(&p);
                break;

            case 5:
                xg(&p); //修改零部件信息
                break;

            //case 6:
            //{
            //    int i;
            //    printf("接下来是给定采购编号，删除采购信息\n");
            //    printf("请输入需要删除的零部件的编号是否是您最后输入的零部件(是或只有一个零部件按1，不是按0):\n");
            //    scanf("%d", &i);
            //    if (i == 1)
            //    {


            //    break;
            //}

            //case 7:
            //{
            //    break;

        case 0:
            printf("感谢您的下次使用，再见");
            return 0;
            break;

        default:
            printf("您当前输入有误");
           
        }
    } while (input);

    return 0;
}


void init_p(jd* p) {//初始化结构体
    p->lj = (car*)malloc(SZ_MAX*sizeof(car));//申请堆区动态内存空间
    if (p->lj == NULL) {
        perror("melloc");
        return;
    }
    p->sz = 0;
    p->pa = PA_MAX;
}

void create_p(jd* p) {//判断空间是否够存储
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

//void open_file(jd* p) {//加载文件
//    FILE* pta = fopen("car_Procurement.txt", "r");//打开文件
//    if (pta == NULL) {
//        perror("open_file");
//        return;
//    }
//    car tmp;
//    while (fread(&tmp, sizeof(car), 1, pta)) {//创建一个新的变量存取读取的文件的信息
//        p->lj[p->sz] = tmp;
//        create_p(p);
//        p->sz++;
//    }
//    fclose(pta);//关闭文件
//    pta = NULL;
//}



void lr(jd* p) {//录入信息


    while (true) {
        int i = 0;
        char *bh; //编号
 
        printf("请输入编号    (例如:1 2 3):"); scanf("%s", p->lj[p->sz].bh); //编号
        if (p->sz > 0) {
           bh = p->lj[p->sz].bh;
           i = search_bh(p, bh);
           
           if (i >= 0) {
               printf("已添加!");
           }
           else
               break;
        }
        if (p->sz == 0)
            break;
    }

    printf("请输入零部件名称(例如:xxx):"); scanf("%s", p->lj[p->sz].name); //名称
    
    while (true) {
        int i = 0;
        printf("请输入年份     (例如:2010/12/01):"); scanf("%d/%d/%d", &(p->lj[p->sz].year), &(p->lj[p->sz].month), &(p->lj[p->sz].day)); //日期

            if ((p->lj[p->sz].month) == 2) {//闰年 2月
                 if ((p->lj[p->sz].year) % 4 == 0 || (p->lj[p->sz].year) % 400 == 0 && (p->lj[p->sz].year) % 100 != 0) {
                     if ((p->lj[p->sz].day) < 29 && (p->lj[p->sz].day) > 0)
                        break;
                 }
            }

           else if ((p->lj[p->sz].month) == 2) {//平二月
                if ((p->lj[p->sz].day) < 28&& (p->lj[p->sz].day)>0)
                    break;
           }

           else if ((p->lj[p->sz].month) == 4 || (p->lj[p->sz].month) == 6 || (p->lj[p->sz].month) == 9 || (p->lj[p->sz].month) == 11) {//小月

                if ((p->lj[p->sz].day) <= 30&& (p->lj[p->sz].day)>0)
                    break;
           }

           else if ((p->lj[p->sz].month) == 1 || (p->lj[p->sz].month) == 3 || (p->lj[p->sz].month) == 5 || (p->lj[p->sz].month) == 7 || (p->lj[p->sz].month) == 8 || (p->lj[p->sz].month) == 10 || (p->lj[p->sz].month) == 12) {

                if ((p->lj[p->sz].day) <= 31&& (p->lj[p->sz].day)>0) //大月
                    break;
           }

            printf("输入错误!\n");
        
    }
    
    printf("请输入采购员名称  (例如:张三):"); scanf("%s", p->lj[p->sz].cgy);//采购员 


    printf("请输入采购数量     (例如:2):"); scanf("%d", &(p->lj[p->sz].num));//数量 


    printf("请输入零部件单价  (例如:2.00):"); scanf("%lf", &(p->lj[p->sz].dj));//单价


    printf("请输入零部供货单位(例如:SF):"); scanf("%s", p->lj[p->sz].dw); //单位 

    printf("零部件信息录入成功!\n");
    p->sz++;
    system("pause");
    system("cls");//清屏

}

void print_branch(jd* p, int i) {//打印分支
    
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

void dy(jd* p)//打印信息
{
    printf("**************************************************************\n");
    printf("*\t               欢迎使用汽车零部件管理系统            *\n");
    printf("**************************************************************\n");

    printf("*编号\t*名称\t*日期\t        *采购员\t*数量\t*单价\t*单位*\n");
    printf("**************************************************************\n");

    //遍历链表
    for (int i = 0; i < p->sz; i++) {

        print_branch(p, i);//打印分支
      
        printf("\n");
    }
  
    system("pause");
    system("cls");//清屏
}

int search_bh(jd* p, char* bh) {//返回值查找
    for (int i = 0; i < p->sz;  i++) {
        if (strcmp(p->lj[i].bh, bh) == 0)
            return i;
    }
    return -1;
}

void cz_bh(jd* p) {//通过编号查找零部件

    char bh[20]; //编号

    printf("请输入查询的编号:"); scanf("%s", bh);

    int tmp=search_bh(p, bh);//返回值查找

    if (tmp < 0) {//未找到
        printf("未添加需要查询的编号!\n");
    }
    else if(tmp >= 0) {//找到
        printf("**************************************************************\n");
        printf("*\t               欢迎使用汽车零部件管理系统            *\n");
        printf("**************************************************************\n");

        printf("*编号\t*名称\t*日期\t        *采购员\t*数量\t*单价\t*单位*\n");
        printf("**************************************************************\n");
        print_branch(p, tmp);//打印分支
    }
        
    system("pause");
    system("cls");//清屏
}

void search_lj(jd* p) {//查找零部件
    char name[10]; //零件名称
    printf("请输入零部件名称:"); scanf("%s", name);
    printf("**************************************************************\n");
    printf("*\t               欢迎使用汽车零部件管理系统            *\n");
    printf("**************************************************************\n");

    printf("*编号\t*名称\t*日期\t        *采购员\t*数量\t*单价\t*单位*\n");
    printf("**************************************************************\n");

    int num=0;//计数
    for (int i = 0; i < p->sz; i++) {
        if (strcmp(p->lj[i].name, name) == 0) {
            print_branch(p, i);
            num++;
        }
    }
    if (num == 0)
        printf("未添加此零部件!\n");

    system("pause");
    system("cls");//清屏
}

void xg(jd* p) {//函数：修改零部件信息
    char bh[20]; //编号
    printf("请输入需要修改的编号:"); scanf("%s", bh);
    

    int tmp=search_bh(p, bh);//返回值查找

    if (tmp < 0) {//未找到
        printf("未添加需要修改的编号!\n");
    }
    else if (tmp >= 0) {//找到
        printf("请输入编号    (例如:1 2 3):"); scanf("%s", p->lj[tmp].bh); //编号
        printf("请输入零部件名称(例如:xxx):"); scanf("%s", p->lj[tmp].name); //名称
        printf("请输入年份     (例如:2010/12/01):"); scanf("%d/%d/%d", &(p->lj[tmp].year), &(p->lj[tmp].month), &(p->lj[tmp].day)); //日期
        printf("请输入采购员名称  (例如:张三):"); scanf("%s", p->lj[tmp].cgy);//采购员 
        printf("请输入采购数量     (例如:2):"); scanf("%d", &(p->lj[tmp].num));//数量 
        printf("请输入零部件单价  (例如:2.00):"); scanf("%lf", &(p->lj[tmp].dj));//单价
        printf("请输入零部供货单位(例如:SF):"); scanf("%s", p->lj[tmp].dw); //单位 

        printf("零部件信息修改成功!\n");

        system("pause");
        system("cls");//清屏
    }


}



//jd* cz_bh()//通过编号查找零部件
//{
//    char cz_bh[20]; //通过编号查找零部件
//
//    printf("请输入你想查找的零件的编号:\n");
//    scanf("%s", cz_bh);
//
//    jd* p = g_pHead;
//    while (p != NULL)
//    {
//        if (strcmp(p->lj.bh, cz_bh) == 0) //会报警告 
//        {
//            return p;
//        }
//
//        p = p->pnext;
//    }
//    return NULL;
//}

//jd* cz_mc()//通过名称查找零部件
//{
//    char cz_mc[20];
//
//    printf("请输入你想查找的零件的名称:\n");
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
//    printf("请输入需要修改的零部件的采购编号\n");
//    scanf("%s", xg_bh);
//
//    jd* p = g_pHead;
//    while (p != NULL)
//    {
//        if (strcmp(p->lj.bh, xg_bh) == 0) //p->li.bh与xg_bh不能用等号比较 
//        {
//            printf("请输入您想修改的零件信息:\n修改编号请按1\n修改名称请按2\n修改日期请按3\n修改采购员请按4\n修改数量请按5\n修改单价请按6\n修改单位请按7\n如果要全部修改请按0\n");
//            scanf("%d", &i);
//
//            if (i == 1)
//            {
//                printf("您好，请输入修改后的编号:\n");
//                scanf("%s", p->lj.bh);
//            }
//
//            else if (i == 2)
//            {
//                printf("您好，请输入修改后的名称:\n");
//                scanf("%s", p->lj.mc);
//            }
//
//            else if (i == 3)
//            {
//                printf("您好，如果您想修改年份请按1，修改月份请按2，修改天份请按3:\n");
//                scanf("%d", &i);
//
//                if (i == 1)
//                {
//                    printf("请输入修改后的年份:\n\t");
//                    scanf("%d", &p->lj.year);
//                }
//
//                else if (i == 2)
//                {
//                    printf("请输入修改后的月份:\n\t");
//                    scanf("%d", &p->lj.month);
//                }
//
//                else if (i == 3)
//                {
//                    printf("请输入修改后的天份:\n\t");
//                    scanf("%d", &p->lj.day);
//                }
//            }
//
//            else if (i == 4)
//            {
//                printf("您好，请输入修改后的采购员:\n");
//                scanf("%s", p->lj.cgy);
//            }
//
//            else if (i == 5)
//            {
//                printf("您好，请输入修改后的数量:\n");
//                scanf("%d", &p->lj.num);
//            }
//
//            else if (i == 6)
//            {
//                printf("您好，请输入修改后的单价:\n");
//                scanf("%lf", &p->lj.dj);
//            }
//
//            else if (i == 7)
//            {
//                printf("您好，请输入修改后的单位:\n");
//                scanf("%s", p->lj.dw);
//            }
//
//            else if (i == 0)
//            {
//                printf("您好，请输入修改后的编号 名称 日期 采购员 数量 单价 单位:\n");
//                scanf("%s %s %d %d %d %s %d %lf %s", p->lj.bh, p->lj.mc, &p->lj.year, &p->lj.month, &p->lj.day, p->lj.cgy, &p->lj.num, &p->lj.dj, p->lj.dw);
//            }
//
//            else
//            {
//                printf("对不起输入错误，请检查您的输入再重试");
//                system("pause");
//                break;
//            }
//
//            printf("修改成功\n");
//            system("pause");
//            break;
//        }
//        p = p->pnext;
//    }
//
//    if (p == NULL)
//    {
//        printf("未能找到此采购编号对应零部件，请检查编号\n");
//        system("pause");
//    }
//}
//
//void t_sc()
//{
//    jd* p1;
//    char sc_bh[20];
//    printf("请输入你所想要删除的零部件的编号:");
//    scanf("%s", sc_bh);
//
//    //如果是头结点 
//    if (strcmp(g_pHead->lj.bh, sc_bh) == 0)
//    {
//        p1 = g_pHead;            //备份头结点 
//        g_pHead = g_pHead->pnext;// 将头结点指向下一个结点 
//        free(p1); //删除就是释放这段内存 ,p1被赋予了头结点，但是头结点已经指向下一个结点 
//        printf("恭喜，删除成功\n");
//        system("pause");
//        return;
//    }
//
//    else
//    {
//        printf("对不起，删除失败，请检查你输入的编号\n");
//        system("pause");
//        return;
//    }
//}
//
//void ft_sc()
//{
//    //如果不是头结点
//    char sc1_bh[20];
//    printf("请输入你所想要删除的零部件的编号:");
//    scanf("%s", sc1_bh);
//    jd* p = g_pHead;
//    jd* p2;                  //p2是备份的 
//    while (p2->pnext != NULL)
//    {
//        if (strcmp(p->pnext->lj.bh, sc1_bh) == 0)
//        {
//            p2 = p->pnext;             //备份头结点 
//            p->pnext = p->pnext->pnext;//中间结点(要删除的结点)的上一个结点是头结点，头结点的下一个结点是中间节点的后一个结点 ，把中间结点指向第三个结点 
//            free(p2);
//        }
//
//        if (p->pnext == NULL) //中间结点已删除.  NULL会警告，'0'不会 ，char变量和指针变量不能比较 
//        {
//            printf("恭喜，成功删除\n");
//            system("pause");
//            return;
//        }
//
//        p = p->pnext;
//
//        if (p->pnext == NULL)//跳出循环，表示零件不存在
//        {
//            printf("对不起，删除失败，请检查你输入的编号\n");
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
//    printf("您想依据什么来统计采购金额(依据名称请按1，依据采购员请按2，依据采购日期请按3)\n");
//    scanf("%d", &i);
//
//    if (i == 1)
//    {
//        printf("请输入被统计零件的名称:\n");
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
//                printf("您输入的名称有误，请返回菜单后再重新统计\n");
//                return 0;
//            }
//        }
//        return sum;
//    }
//
//    else if (i == 2)
//    {
//        printf("请输入被统计零件的采购员:\n");
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
//                printf("您输入的采购员有误，请返回菜单后再重新统计\n");
//                return 0;
//            }
//        }
//        return sum;
//    }
//
//    else if (i == 3)
//    {
//        printf("按年统计请按1，按月份统计请按2，按天份统计请按3\n");
//        scanf("%d", &j);
//
//        if (j == 1)
//        {
//            printf("您想查找那一年的总金额(例如:2022):\n");
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
//            printf("您想查找那一月的总金额(例如:2022):\n");
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
//            printf("您想查找那一天的总金额(例如:2022):\n");
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
//    //打开文件
//    FILE* fp = fopen("C:\\Users\\joker\\dy.data", "w");
//
//    if (fp == NULL)
//    {
//        printf("打开文件失败\n");
//        return;
//    }
//
//    jd* njd = g_pHead;
//    while (njd != NULL)
//    {
//        fwrite(&njd->lj, 1, sizeof(car), fp); //结构体内容 几kb 以什么方式 
//        njd = njd->pnext;
//    }
//
//    //关闭文件
//    fclose(fp);
//    printf("数据保存成功\n");
//    system("pause");
//    system("cls");
//    return;
//}
//
//void wj_dq()
//{
//    //打开文件
//    FILE* fp = fopen("C:\\Users\\joker\\dy.data", "r");
//    if (fp == NULL)
//    {
//        printf("抱歉，文件内容为空\n");
//        return;
//    }
//
//    //读文件
//    car lj;
//    while (fread(&lj, 1, sizeof(car), fp)) //feof判断是否到末尾 ,但是会多一行 
//    {
//        //创建一个新结点
//        jd* djd = (jd*)malloc(sizeof(car));
//        djd->pnext = NULL;
//
//        memcpy(djd, &lj, sizeof(lj)); //添加头文件<string.h> 
//
//        //头插法
//        if (g_pHead == NULL) //没有结点，赋予结点 
//        {
//            g_pHead = djd;
//        }
//        else                //有结点
//        {
//            djd->pnext = g_pHead;//新结点的下一个为头结点
//            g_pHead = djd;      //则头结点为新设的结点 
//        }
//    }
//
//    //关闭文件
//    fclose(fp);
//    printf("加载数据成功！\n");
//    system("pause");
//}
//
//void sf_nc()
//{
//    jd* sf_jd = (jd*)malloc(sizeof(jd));
//    sf_jd->pnext = NULL;
//    //头插法
//    if (g_pHead == NULL) //没有结点，赋予结点 
//    {
//        g_pHead = sf_jd;
//    }
//    else                //有结点
//    {
//        sf_jd->pnext = g_pHead;//新结点的下一个为头结点
//        g_pHead = sf_jd;      //则头结点为新设的结点 
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
//            printf("编号重复，请重试\n");
//            scanf("%s", p->lj.bh);
//            check(_bh);
//        }
//        p = p->pnext;
//    }
//}
