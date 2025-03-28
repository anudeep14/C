#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

  pid_t pid = fork(); // child process gets created here
//both parent and child process executes the program separately.

  if(pid < 0) {
    printf("Creating process using fork failed");
    return -1;
  } else if (pid == 0) {
    sleep(1);
    printf("Child process. My PID: %d , Parent PID: %d\n", getpid(), getppid());
  } else {
    printf("Parent process. My PID %d, Child PID: %d\n", getpid(), pid);
    wait(NULL); //parent process waits till child is done executing
  }

  printf("This region runs in both processes. PID: %d\n",getpid());
  return 0;
}

/* expected output
Parent process. My PID 64863, Child PID: 64864
Child process. My PID: 64864 , Parent PID: 64863
This region runs in both processes. PID: 64864
This region runs in both processes. PID: 64863 */
