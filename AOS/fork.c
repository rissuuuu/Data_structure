/*
1. Fork() doesnt have any arguements
2. It returns process ID of the child process
3. After creation of the process, both parent and child process start
  execution from the next instrucction.


fork()>0 sucessful
fork()<0 error
fork()==0 child process




*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
  fork();
  printf("Hello world");
}
