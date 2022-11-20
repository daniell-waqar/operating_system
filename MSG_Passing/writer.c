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
    int msgflg = IPC_CREAT| 0666;
    message_buf sbuf;

    size_t buf_length;
    int running = 1;

    // int msgflg = IPC_CREAT| 0666;
    msgid = msgget(key, msgflg);
    sbuf.msg_type = 1;
    char buffer[20];

    while(running){

        printf("Enter data: ");
        fgets(buffer, 20, stdin);
        sbuf.msg_type = 1;

        strcpy(sbuf.my_text, buffer);

        //buf_length = strlen(sbuf.my_text) + 1;

        msgsnd(msgid, &sbuf, MSGSZ, IPC_NOWAIT);

        if (strncmp (sbuf.my_text, "end",3) == 0)
        {
            running = 0;
        }

    }

   
    return 0;


}

