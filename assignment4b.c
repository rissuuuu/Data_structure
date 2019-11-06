#include<signal.h>
char *tempfile = "temp.XXXXXX";

main(){
	
	extern onintr();
	if(signal(SIGINT,SIG_IGN)!=SIG_IGN)
		signal(SIGINT,onintr);
	printf("Making file \n");
	mktemp(tempfile);
	exit(0);
}
onintr(){	
	unlink(tempfile);
	exit(1);
}