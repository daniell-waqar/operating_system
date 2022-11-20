#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>

#define MSGSZ 218

typedef struct msg_buf
{
    long msg_type;
    char my_text[MSGSZ];

} message_buf;


int main()
{
    int msgid;
    key_t key;
    key = 1234;
    message_buf rbuf;

    int running = 1;
    char buffer[20];
    msgid = msgget(key , 0666);


    while(running){
       
        strcpy(rbuf.my_text, buffer);
        msgrcv(msgid, &rbuf, MSGSZ, 1, 0);
        printf("%s", rbuf.my_text);

        if (strncmp (rbuf.my_text, "end",3) == 0)
        {
            running = 0;
        }


    }


    
}