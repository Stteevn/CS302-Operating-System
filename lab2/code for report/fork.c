
  #include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc,char* argv[])
{
	int pid;
<<<<<<< HEAD
	char *prog_argv[4];

	/* ���������� */
	prog_argv[0]="/bin/ls";
	prog_argv[1]="-l";
	prog_argv[2]="/";
	prog_argv[3]=NULL;
=======
	char *prog_argv[3];

	/* ���������� */
	prog_argv[0]="/usr/bin/vi";
	prog_argv[1]="vi";
	prog_argv[2]=NULL;
>>>>>>> 608322e088af48bad43f7e3bd06e95d1dbd917d1

	/* Ϊ����ls�������� */
	if ((pid=fork())<0)
	{
		perror("Fork failed");
		exit(errno);
	}

	if (!pid)/* �����ӽ��̣�ִ������ls */
	{
		printf("argc = %d, argv[0] = %s",argc,argv[0]);
<<<<<<< HEAD
		execvp(prog_argv[0],prog_argv);
=======
		int ret = execv(prog_argv[0],prog_argv);
>>>>>>> 608322e088af48bad43f7e3bd06e95d1dbd917d1
	}

	if (pid)/* ���Ǹ����̣��ȴ��ӽ���ִ�н���*/
	{
		waitpid(pid,NULL,0);
	}

	return 0;
}
