

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    int fd = open("data1.txt", O_WRONLY);
    if (fd == -1) {
        printf("Error Occured\n");
        return 1;
    }
   
    char data[30] = "My Name is Waqar";
 

    write(fd, data,sizeof(data));
    printf("Data Written Successfully\n");
    close(fd);

    int fd1 = open("data1.txt", O_RDONLY);
    if (fd1 == -1) {
        printf("Unable to Open the File \n");
        return 1;
    }
    char buffer[40];
    read(fd1, buffer, sizeof(buffer));
    close(fd1);
    printf("%s\n", buffer);
    return 0;
    
    
}  