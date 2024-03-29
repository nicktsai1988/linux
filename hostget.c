#include<sys/utsname.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char computer[256];
	struct utsname uts;
	if(gethostname(computer,255)!=0||uname(&uts)<0)
	{
		fprintf(stderr,"could not get host information\n");
		exit(1);
	}
	printf("computer host name is %s\n",computer);
	printf("system is %s on %s hardware\n",uts.sysname,uts.machine);
	printf("Nodename is %s \n",uts.nodename);
	printf("version is %s,%s\n",uts.release,uts.version);
	printf("Host ID is %ld\n",gethostid());
	exit(0);
}
