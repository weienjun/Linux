#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int tmp = 0;

void Fork()//子进程创建pcb，虚表，空间，父子进程相互独立
{
	pid_t pid= fork();
	if(pid == 0)//子进程
	{
		tmp = 100;
		printf("child pid = %d  ppid = %d  tmp = %d\n",getpid(),getppid(),tmp);
		sleep(1);
		exit(0);//退出子进程
	}	
	else 
	{
		printf("parent pid = %d  ppid = %d  tmp = %d\n",getpid(),getppid(),tmp);
		sleep(5);
//		exit(0);//退出父进程
	}
}
//注：函数中子进程退出，父进程不退出----父进程继续执行main函数中的语句，执行一次
//    函数中的父，子进程都未退出--------父，子进程都继续执行main函数中的语句，执行两次
//    函数中的父进程退出，子进程未退出--子进程继续执行mian函数中的代码，执行一次，但子进程变为孤儿进程

void Vfork()//子进程只创建pcb，共享空间，数据
{
	pid_t pid = vfork();
	
	if(pid == 0)//子进程
	{
		tmp = 0;
		printf("child pid = %d  ppid = %d  tmp = %d\n",getpid(),getppid(),tmp);
		sleep(1);
		exit(0);//退出子进程
	}	
	else 
	{
		printf("parent pid = %d  ppid = %d  tmp = %d\n",getpid(),getppid(),tmp);
		sleep(5);
	}
}


int main()
{	
	printf("fork\n");
	Fork();
	sleep(10);
	printf("vfork\n");
	Vfork();
	return 0;
}

/*
int main()
{
//	pid_t pid = fork();
	printf("A");
//	sleep(3);
	pid_t pid2 = fork();
	printf("B\n");
	return 0;
}

*/
