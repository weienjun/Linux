#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid = vfork();//父子进程共用一块内存空间，栈帧结构等

	if(pid < 0)
	{
		perror("vfork");
		exit(0);
	}

	if(pid == 0)
	{
		printf("子进程：pid = %d ppid = %d\n",getpid(),getppid());
		sleep(1);
	//	exit(0);//不加exit时，子进程退出后栈帧空间被销毁，父进程在执行时出错(无栈帧空间).
	}

	else//pid > 0
	{
		printf("父进程：pid = %d ppid = %d\n",getpid(),getppid());
		sleep(3);
	}
	return 0;
}
