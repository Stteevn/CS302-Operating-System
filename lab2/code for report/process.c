#include <stdio.h>
#include <signal.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/termios.h>

int main()
{
<<<<<<< HEAD
	int cpid;/* �����ӽ��̵�id�� */
	int ppid;/* ���游���̵�id�� */
	char buf[256];
  
	ppid=getpid();//�õ����̺�
=======
	int cpid;/* 保存子进程的id号 */
	int ppid;/* 保存父进程的id号 */
	char buf[256];
  
	char *prog_argv[2];
	prog_argv[0] = "/usr/bin/vi";
	prog_argv[1] = NULL;
	
	pid_t spid = tcgetsid(0);

	ppid=getpid();//得到近程号
>>>>>>> 608322e088af48bad43f7e3bd06e95d1dbd917d1
	cpid=fork();
  
	if (cpid<0)
		exit(-1);
<<<<<<< HEAD
    
=======
  	  
>>>>>>> 608322e088af48bad43f7e3bd06e95d1dbd917d1
	if (!cpid)
	{
		fprintf(stdout,"ID(child)=%d\n",getpid());

<<<<<<< HEAD
		/* ʹ�ӽ������ڵĽ������Ϊǰ̨�����飬Ȼ��ִ��vi */
		setpgid(0,0);
		tcsetpgrp(0,getpid());
		execvp("/bin/vi","vi",NULL);
		exit(-1);
	}
   
	fprintf(stdout,"ID(parent)=%d\n",ppid);
	setpgid(cpid,cpid);/* ���ý����� */
	tcsetpgrp(0,cpid);/* ���ÿ����ն�Ϊ�ӽ���ӵ�� */
	waitpid(cpid,NULL,0);/* �����̵ȴ��ӽ���ִ����ϣ����ڽ������Ϊǰ̨������ */
	tcsetpgrp(0,ppid);

	//�����̵ȴ��ն����룬Ȼ�����
=======
		/* 使子进程所在的进程组成为前台进程组，然后执行vi */
		//setpgid(0,0);
		tcsetpgrp(0,getpid());
		int ret = execv(prog_argv[0], prog_argv);
		fprintf(stdout, "fuck");
		exit(-1);
	}
  	signal(SIGTTOU, SIG_IGN); 
	fprintf(stdout,"ID(parent)=%d\n",ppid);
	setpgid(cpid,cpid);/* 设置进程组 */
	tcsetpgrp(0,cpid);/* 设置控制终端为子进程拥有 */
	waitpid(cpid,NULL,0);/* 父进程等待子进程执行完毕，所在进程组成为前台进程组 */
	setpgid(0,ppid);

	int ret = tcsetpgrp(0,ppid);

	//父进程等待终端输入，然后回显
>>>>>>> 608322e088af48bad43f7e3bd06e95d1dbd917d1
	while(1)
	{
		memset(buf, 0, 256);
		fgets(buf, 256, stdin);
		puts("ECHO: ");
		puts(buf);
		puts("\n");
	}

	return 0;
}
