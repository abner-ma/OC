#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/param.h>
#include<sys/types.h>
#include<sys/stat.h>

int init_daemon()
{
	int pid;
	int i;
	if(pid = fork())
	{
		exit(0);
	}
	else if(pid < 0)
	{
		exit(1);
	}
	setsid();
	if(pid = fork())
	{
		exit(0);
	}
	else if(pid < 0)
	{
		exit(1);
	}
	for(i = 0;i < NOFILE;i++)
		close(i);
	chdir("/tmp");
	umask(0);
	return 0;
}
int main(int argc,char * argv)
{
    return 0;
}
