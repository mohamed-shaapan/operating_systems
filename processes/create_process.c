// import libraries
// *******************************************
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


// main function
// *******************************************
void main(char **args, int background_flag){

    pid_t pid;
    int status;

    pid = fork();
    
    // child process___________________________
    if (pid == 0) {
      if (execvp(args[0], args) == -1) {
        perror("lsh");
      }
      exit(EXIT_FAILURE);

    // error forking___________________________
    } else if (pid < 0) {
      perror("lsh");

    // parent process__________________________
    } else{
      
      if (background_flag==0){
        do {
          waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
      } else {

        // let program run in background
      }
      
    }

}




