#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
//非阻塞式
int main()
{
	pid_t pid = fork();

	if(pid == -1)
	{
		perror("fork");
		exit(-1);
	}

	if(pid == 0)
	{
		printf("子进程：pid = %d\n",getpid());
		sleep(10);
		exit(10);
	}

	else
	{
		printf("父进程：pid = %d\n",getpid());
	
		pid_t pid2 = fork();//子进程2先退出，后子进程1退出。
		printf("子进程2：pid = %d\n",pid2);

		int st;
		pid_t ret;
		do{
			//轮询遍历，等待子进程退出，防止子进程变为僵尸进程
			ret = waitpid(-1,&st,WNOHANG);//-1-->等待所有子进程，WNOHANG-->非阻塞式等待
			if(ret == 0)
			{
				printf("子进程在运行继续等待：pid = %d\n",getpid());//父进程继续执行，打印父进程pid
				sleep(1);
			}
			else if(ret > 0)
				printf("退出的子进程：ret = %d\n",ret);
			else // < 0 -->无所需等待的进程
			{
				printf("子进程未退出完\n");
				break;
			}
		}while(1);//子进程未退出
		//子进程退出
		if(ret == pid && WIFEXITED(st))//正常退出？
			printf("退出码 = %d\n",WEXITSTATUS(st));//正常退出，打印退出码
		else//异常退出
			printf("终止信号 = %d\n",st & 0x7F);
	}
}
