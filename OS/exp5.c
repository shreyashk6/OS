#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t pid;
    int status;
    pid = fork();
    if (pid < 0)
    {
        printf("Error:fork() failed.\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("This is the child process with pid %d\n", getpid());
        printf("The parent process has pid %d\n", getppid());

        execlp("/bin/ls", "ls", NULL);
        printf("This should not be printed if exec() is successful.\n");
    }
    else
    {
        printf("This is the parent process with pid %d\n", getpid());
        printf("The child process has pid %d\n", pid);
        wait(&status);
        printf("Child process terminated with status %d\n", status);

        return 0;
    }
}
