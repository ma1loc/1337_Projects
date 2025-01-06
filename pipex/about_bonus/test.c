#include <unistd.h>
#include <stdlib.h>

int main(int c,char**i,char**l) // enviroment
{
	write(1,"hello\n",6);
	if(fork() == 0){
		execve("/bin/ls",0,l);
		exit(1);
	}
	write(1,"hello\n",6);
}
