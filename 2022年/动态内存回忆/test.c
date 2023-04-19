#define  _CRT_SECURE_NO_WARNINGS

#include"struct.h"

int main() {

	class number;

	initnumber(&number);

	addnumber(&number);

	free(number.stru);
	number.stru = NULL;

	return 0;
}
