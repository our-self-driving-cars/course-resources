#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[15] = "123456789";
	char str2[10] = "*********";
	strncpy(str1, str2, 5);
	printf(str1);


	return 0;
}

