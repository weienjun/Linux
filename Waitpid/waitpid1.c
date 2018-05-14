#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main()
{
	pid_t pid = fork();
	
	if(pid == -1)
	{
		perror("fork");
		exit(0);
	}

	if(pid == 0)
	{
		printf("子进程：pid = %d\n",getpid());
		sleep(10);
		exit(1);
	}

	else
	{
		int st;
		pid_t ret = waitpid(pid,&st,0);//0--->阻塞式
		if(ret == pid && WIFEXITED(st))//判断是否正常退出
			printf("退出码 = %d\n",WEXITSTATUS(st));//正常退出，打印退出码
		else//异常退出
			printf("终止信号 = %d\n",st & 0x7F);
		printf("父进程：pid = %d\n",getpid());
		sleep(3);
	}

}
