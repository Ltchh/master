#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PEO_E 5
#define CAP_Y 4


typedef struct strudent {
	char name[20];
	int age;
	char gender[2];
	char number[15];
}strudent;

typedef struct class {
	strudent* stru;
	int people;
	int capacity; //开辟空间满后的增加数量
}class;

void initnumber(class* number);
void addnumber(class* number);
