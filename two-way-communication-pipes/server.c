#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void reverse_string(char *);
int main() {
   int fd;
   char readbuf[80];
   int read_bytes;

   int end;
   
  
   mkfifo("one", S_IFIFO|0777);

   fd = open("one", O_RDWR);
   while(1) {
      read_bytes = read(fd, readbuf, sizeof(readbuf));
      readbuf[read_bytes] = '\0';
      printf("SERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      end = strcmp(readbuf, "abort");
          
      if (end == 0) {
         close(fd);
         break;
      }
      reverse_string(readbuf);
      printf("SERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int) strlen(readbuf));
      write(fd, readbuf, strlen(readbuf));
      /*
      sleep - This is to make sure other process reads this, otherwise this
      process would retrieve the message
      */
      sleep(2);
   }
   return 0;
}

void reverse_string(char *str) {
   int last, limit, first;
   char temp;
   last = strlen(str) - 1;
   limit = last/2;
   first = 0;
   
   while (first < last) {
      temp = str[first];
      str[first] = str[last];
      str[last] = temp;
      first++;
      last--;
   }
   return;
}