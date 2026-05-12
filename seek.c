#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 


int main(){
     
   if(lseek(STDIN_FILENO,0,SEEK_SET) == -1){
        printf("Cannot Seek"); 
   }
   else {
    printf("Can be seek");
   }

    return 0;
}