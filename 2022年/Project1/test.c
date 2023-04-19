#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
struct a {
	int aa;
	char b;
};
int main() {

	struct a c = { 0 };

	printf("%d\n", sizeof(struct a));
	printf("%d\n", sizeof(c));
	return 0;
}
