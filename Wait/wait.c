#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>

int main()
{
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("子进程：pid = %d ppid = %d\n",getpid(),getppid());
		sleep(3);
		exit(0);
	}
	else
	{
		int id = wait(NULL);//等待子进程退出，获取退出信息，否则3s后子进程程退出，父进程未退出，子进程变为僵尸进程
		printf("等待的结果：id = %d\n",id);
		while(1)
		{
			printf("父进程：pid = %d ppid = %d\n",getpid(),getppid());
			sleep(2);
		}
	}
	
	return 0;
}
