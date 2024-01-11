#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t mypid;

	mypid = getpid();

	printf("%u", mypid); 
}
