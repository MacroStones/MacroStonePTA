/*Problem Description
Give you two numbers A and B, if A is equal to B, you should print "YES", or print "NO".
Input
each test case contains two numbers A and B.
Output
for each case, if A is equal to B, you should print "YES", or print "NO".
Sample Input
1 2
2 2
3 3
4 3
Sample Output
NO
YES
YES
NO */
#include <stdio.h>
#include <string.h>
#define MAX 100000
char * first(char *a) {
	while (*a <= '0' || *a > '9' && *a != '.' && *a)
		a++;
	return a;
}
void jie(char *a) {
	while (*a) {
		if (*a == '.') {
			char *b = a + strlen(a) - 1;
			while (*b == '0')
				b--;
			if (b == a)
				*b = '\0';
			else
				*(b + 1) = '\0';
			break;
		}
		a++;
	}
}
int zhenfu(char *a) {
	if (*a == '-')
		return -1;
	return 1;
}
int main(void)
{
	char a[MAX], b[MAX];
	char *la, *lb;
	while (~scanf("%s%s", a, b)) {
		if (zhenfu(a) != zhenfu(b)) {
			puts("NO");
			continue;
		}
		la = first(a);
		lb = first(b);
		jie(la);
		jie(lb);
		puts(strcmp(la, lb) ? "NO" : "YES");
	}
	return 0;
}