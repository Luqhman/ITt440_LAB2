#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void childTask(){
	char name[50];
	printf("Enter your name : ");
	scanf("%50s", name);
	printf("Name : %s\n", name);
}
void parentTask(){
	printf("Job Is Done!\n");
}


int main (){
	for (int i=0;i<4;i++){
		pid_t pid = fork();
		if (pid == 0){
			childTask();
			exit(EXIT_SUCCESS);
		}
		else {
			wait(NULL);
		}

	}
	parentTask();
	return 0;
}

