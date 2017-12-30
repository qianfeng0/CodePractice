#if (0)
struct msqid_ds {
    struct ipc_perm msg_perm;     /* Ownership and permissions */
    time_t          msg_stime;    /* Time of last msgsnd(2) */
    time_t          msg_rtime;    /* Time of last msgrcv(2) */
    time_t          msg_ctime;    /* Time of last change */
    unsigned long   __msg_cbytes; /* Current number of bytes in
                                    queue (nonstandard) */
    msgqnum_t       msg_qnum;     /* Current number of messages
                                    in queue */
    msglen_t        msg_qbytes;   /* Maximum number of bytes
                                    allowed in queue */
    pid_t           msg_lspid;    /* PID of last msgsnd(2) */
    pid_t           msg_lrpid;    /* PID of last msgrcv(2) */
};

注意 
msgsnd, msgrcv 的msgsz不算mtype的长度，只算mtext的长度。
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_FLAG    (IPC_CREAT | 0666)

#define PROJ_ID     (0x03)

#define MSG_TYPE    0x10

struct mymsg {
    long mtype;       /* message type, must be > 0 */
    char mtext[13];    /* message data */
};

int main(int argc, char* argv[])
{
    int ret = 0;
    int key;
    int msgid;

    //获得 key
    key = ftok("./", PROJ_ID);
    if (key == -1)
        perror("ftok");
    printf("key[0x%x]\n", key);

    msgid = msgget(key, MSG_FLAG);

    struct mymsg stMsg;
    stMsg.mtype = MSG_TYPE;
    snprintf(stMsg.mtext, sizeof(stMsg.mtext), "hello world!");

    ret = msgsnd(msgid, (void*)&stMsg, sizeof(stMsg.mtext), 0);
    if (ret < 0){
        perror("msgsnd");
        exit(1);
    }


    struct mymsg stMsgRcv;
    int rcvSize = 0;
    rcvSize = msgrcv(msgid, (void*)&stMsgRcv, sizeof(stMsgRcv.mtext), MSG_TYPE, 0);
    if (rcvSize < 0){
        perror("msgrcv");
        exit(1);
    }
    printf("[%d]%s\n", rcvSize, stMsgRcv.mtext);

    ret = msgctl(msgid, IPC_RMID, NULL);
    if (ret < 0){
        perror("msgctl");
        exit(1);
    }

    return 0;
}