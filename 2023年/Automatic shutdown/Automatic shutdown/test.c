#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int print(int *choose_1) {
	printf("**********************************\n");
	printf("*********   1.设置关机   *********\n");
	printf("*********   2.取消关机   *********\n");
	printf("**********************************\n            ");
	
	scanf("%d", choose_1);

	return *choose_1;
}

void shutdown(int* aut_1) {

	(*aut_1) *= 60;

	if ((*aut_1) >= 21600){
		system("shutdown -s -t 21600");
	}

	 else if((*aut_1) >= 18000){
		system("shutdown -s -t 18000");
	}

	 else if ((*aut_1) >= 14400){
		system("shutdown -s -t 14400");
	}

	 else if ((*aut_1) >= 10800){
		system("shutdown -s -t 10800");
	}

	 else if ((*aut_1) >= 8200){
		system("shutdown -s -t 8200");
	}

	 else if ((*aut_1) >= 3600){
		system("shutdown -s -t 3600");
	}
	 else if ((*aut_1) >= 3000){
		system("shutdown -s -t 3000");
	}

	 else if ((*aut_1) > 2400){
		system("shutdown -s -t 2400");
	}

	 else if ((*aut_1) >= 1800){
		system("shutdown -s -t 1800");
	}
	
	 else if ((*aut_1) >= 1200){
			system("shutdown -s -t 1200");
		}

	 else if ((*aut_1) >= 0)
		{
			system("shutdown -s -t 600");
		}
		
}

int main() {
	int aut = 0;
	int choose = 0;
	choose = print(&choose);
	
	while (choose) {

		
		if (choose < 3 && choose>0) {
			switch (choose) {

				case 1:
					printf("        <设置关机时间(min)>\n            ");

					shutdown(&aut);
					break;

				case 2:
					system("shutdown -a");
					printf("            <取消关机>\n");
					break;
				default:;

			}
			break;
		}

		else {
					printf("            <重新选择>\n            ");
					scanf("%d", &choose);
		}
			
	}
	
	return 0;
}