#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int num = 0;
int main()
{
	pid_t pid = fork();
	if(pid == 0)
	{
		num = 100;
		while(1)//每隔2s打印一次子进程信息
		{
			printf("子进程num = %d pid = %d ppid = %d\n",num,getpid(),getppid());
			sleep(2);//父进程退出后子进程变为孤儿进程，ppid = 1
		}
	}

	if(pid > 0)
	{
		printf("父进程num = %d pid = %d ppid = %d\n",num,getpid(),getppid());
		sleep(3);//3s后父进程退出
	}

	if(pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	return 0;
} 

//查看进程信息： ps axu | grep 进程名
//退出(杀死)进程：kill -9 进程pid

