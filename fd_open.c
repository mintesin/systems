#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc , char *argv[]){ 
    int val;
    /*Verifying if the input is correct */
    if(argc != 2){
        perror("usage: a.out <descriptor#>");
        return 1;
    } 
/*Getting the file flag using fcntl */
if((val = fcntl(atoi(argv[1]),F_GETFL,0))<0){

        fprintf(stderr,"fcntl Error for file fd: %d \n",atoi(argv[1]));
        return 1;
    }
    /*Outputing the flag extarceted.*/
    switch(val & O_ACCMODE){

        case O_RDONLY: printf("Read Only flag \n");
                        break;
        case O_WRONLY: printf("write only flag \n");
                       break;
        case O_RDWR: printf("Writing and Reading \n");
                      break;
        default: perror("Unknown access Mode \n");

    } 
    /*Checking if the flag is append */
    if(val & O_APPEND){
        printf("Appending \n");
    }
    /*checking if the flag is NONBLOCK*/
    if(val & O_NONBLOCK){
        printf("Non Blocking \n");
    }
/*Checking if the flag is syncronizing */
if(val & O_SYNC ){
        printf("Synchronizing \n");
    }
    /*
    *Checking for standard POSIX feature exposure.
    *Checking for definion of O_FSYNC
    *Checking for O_FSYNC is not an alais for O_SYNC.
    */
    #if !defined (POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != SYNC ) 
        if(val & O_FSYNC )
        { 
                
                printf("It is synchronous writes");
        }
    #endif 

    return 0;
}
