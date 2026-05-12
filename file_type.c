/*
*file_type.c:- is for determining the type of the file using lstat (mode_t st_mode) and then it
*print out the file type 
*/

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int i=1;
    struct stat buf; //file status structure buffering
    char *ptr;  

    if(argc>1){
            while(i<argc) {
                if(lstat(argv[i],&buf)==-1){
                    fprintf(stderr,"lstat error occured");
                    i++;
                    continue;
                }
                if (S_ISREG(buf.st_mode)){
                    ptr = "Regular";
                }
                if (S_ISDIR(buf.st_mode)){
                    ptr = "Directory";
                }
                if (S_ISBLK(buf.st_mode)){
                    ptr = "Block";
                }
                if (S_ISCHR(buf.st_mode)){
                    ptr = "character";
                }
                if (S_ISFIFO(buf.st_mode)){
                    ptr = "FIFO";
                }
                if (S_ISLNK(buf.st_mode)){
                    ptr = "SYMBOLIC LINK";
                }
                if (S_ISSOCK(buf.st_mode)){
                    ptr = "Socket";
                }
                printf("The file is: %s type \n",ptr);
                i++;
        }
    
    }
    else {
        frpintf(stderr,"Please provide the required file pathname.");
    }
  return 0;
}