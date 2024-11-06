#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	int d;
	char s[1];
	char str[1];
	char *st = NULL;

	int ret = strcspn(st, "");
	printf("%d\n", ret);
	
	return 0;
}
