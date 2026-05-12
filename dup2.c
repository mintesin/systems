/*
*This function is for duplicating opened file.
*By copying the file descriptor 
*Mainly tries to implement dup2() function from the linux.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h>

#define None -999
/*
*my_dup:- takes file descriptor number and duplicate it to the least available file descriptor. 
*when it gets duplicated the new descriptor file will inherit all the modes and the O_RDWR mode wil be ignored.
*
*/
int my_dup2(int fd1) {
    int fd2=None;
   //check for the existence of fd1 and duplicate it.
    if(fcntl(fd1,F_GETFL) != -1){
        char path[64];
         sprintf(path,"/dev/fd/%d",fd1);
        fd2 =open(path, O_RDWR);
    }
    
    else {
        fprintf(2,"There is not file opend linked to the %d file descriptor",fd1);
        return EXIT_FAILURE;
}
  return fd2;
}

int main(int argc, char *argv[]){ 
    int new_fd;
    if(argc<2){
        fprintf(2,"Please provide the necessary argument: as filename, fd1, fd2");
        return EXIT_FAILURE;
    }
    new_fd = my_dup2(atoi(argv[1]));

    if(new_fd == None){
        perror("Duplicating is not successful");
        return EXIT_FAILURE;
    }
    return new_fd;
}