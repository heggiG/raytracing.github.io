
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        pid = getpid();
        pid_t ppid = getppid();
        printf("This is child process (pid=%d) with parent %d.\n", pid, ppid);
        sleep(5);
        exit(0);
    } else if (pid > 0) {
        pid = getpid();
        printf("This is the parent process with process id %d.\n", pid);
        pid = wait(NULL);
        if (pid == -1) {
            printf("Wait failed.\n");
            exit(1);
        }
        printf("Child %d finished.\n", pid);
        exit(1);
    } else {
        printf("fork failed.\n");
        exit(1);
    }

}

