#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int Fork()
{
	pid_t pid = fork();

	if(pid < 0)
	{
		perror("vfork");
		exit(0);
	}

	if(pid == 0)
	{
		printf("子进程：pid = %d ppid = %d\n",getpid(),getppid());
		sleep(3);
	}

	else//pid > 0
	{
		printf("父进程：pid = %d ppid = %d\n",getpid(),getppid());
		sleep(1);
	}
	return pid;
}

int VFork()
{
	pid_t pid = vfork();

	if(pid < 0)
	{
		perror("vfork");
		exit(0);
	}

	if(pid == 0)
	{
		printf("子进程：pid = %d ppid = %d\n",getpid(),getppid());
		sleep(3);
	}

	else//pid > 0
	{
		printf("父进程：pid = %d ppid = %d\n",getpid(),getppid());
		sleep(1);
	}
	return pid;
}

int main()
{
	if(Fork() == 0)
		exit(0);

	if(VFork() == 0)
		exit(0);
	return 0;
}
