#include <stdio.h>
#include <signal.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/termios.h>

int main()
{
<<<<<<< HEAD
	int cpid;/* 保存子进程的id号 */
	int ppid;/* 保存父进程的id号 */
	char buf[256];
  
	ppid=getpid();//得到近程号
=======
	int cpid;/* 淇濆瓨瀛愯繘绋嬬殑id鍙� */
	int ppid;/* 淇濆瓨鐖惰繘绋嬬殑id鍙� */
	char buf[256];
  
	char *prog_argv[2];
	prog_argv[0] = "/usr/bin/vi";
	prog_argv[1] = NULL;
	
	pid_t spid = tcgetsid(0);

	ppid=getpid();//寰楀埌杩戠▼鍙�
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
		/* 使子进程所在的进程组成为前台进程组，然后执行vi */
		setpgid(0,0);
		tcsetpgrp(0,getpid());
		execvp("/bin/vi","vi",NULL);
		exit(-1);
	}
   
	fprintf(stdout,"ID(parent)=%d\n",ppid);
	setpgid(cpid,cpid);/* 设置进程组 */
	tcsetpgrp(0,cpid);/* 设置控制终端为子进程拥有 */
	waitpid(cpid,NULL,0);/* 父进程等待子进程执行完毕，所在进程组成为前台进程组 */
	tcsetpgrp(0,ppid);

	//父进程等待终端输入，然后回显
=======
		/* 浣垮瓙杩涚▼鎵�鍦ㄧ殑杩涚▼缁勬垚涓哄墠鍙拌繘绋嬬粍锛岀劧鍚庢墽琛寁i */
		//setpgid(0,0);
		tcsetpgrp(0,getpid());
		int ret = execv(prog_argv[0], prog_argv);
		fprintf(stdout, "fuck");
		exit(-1);
	}
  	signal(SIGTTOU, SIG_IGN); 
	fprintf(stdout,"ID(parent)=%d\n",ppid);
	setpgid(cpid,cpid);/* 璁剧疆杩涚▼缁� */
	tcsetpgrp(0,cpid);/* 璁剧疆鎺у埗缁堢涓哄瓙杩涚▼鎷ユ湁 */
	waitpid(cpid,NULL,0);/* 鐖惰繘绋嬬瓑寰呭瓙杩涚▼鎵ц瀹屾瘯锛屾墍鍦ㄨ繘绋嬬粍鎴愪负鍓嶅彴杩涚▼缁� */
	setpgid(0,ppid);

	int ret = tcsetpgrp(0,ppid);

	//鐖惰繘绋嬬瓑寰呯粓绔緭鍏ワ紝鐒跺悗鍥炴樉
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
