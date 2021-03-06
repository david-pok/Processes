// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child here\n");
        // char *args[] = {"ls", "-l", NULL}; //execvp example
        // execvp("/bin/ls", args);           //execvp example
        // execl("/bin/ls", "ls", "-l", NULL);   //execl example
        execlp("ls", "ls", "-l", NULL);       //execlp example
    } else {
        int wc = wait(NULL);
        printf("parent here\n");
    }
    return 0;
}
// v will take an array parameter to specify the argv[] array of the new program.
// l will take the arguments of the new program as a variable-length argument list to the function itself.
// e will take an extra argument to provide the environment of the new program; otherwise, the program inherits the current process's environment.