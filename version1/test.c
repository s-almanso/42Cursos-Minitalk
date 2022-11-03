#include <stdio.h>
#include <unistd.h>
int main()
{
	int i = getpid();

	printf("pid is:%d\n", i);

	return (0);
}
