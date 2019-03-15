#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0;

	for (i=0; i<=10; i++) {
		sum += i;
		printf("%d\t", sum);
		if (i % 3 == 0) {
			printf("\n");
		}
	}
	printf("\nfinal sum %d\n", sum);

	return 0;
}
