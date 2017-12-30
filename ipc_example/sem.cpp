#if (0)
信号量集合维护
struct semid_ds {
    struct ipc_perm sem_perm;  /* Ownership and permissions */
    time_t          sem_otime; /* Last semop time */
    time_t          sem_ctime; /* Last change time */
    unsigned long   sem_nsems; /* No. of semaphores in set */
};

struct ipc_perm {
    key_t          __key; /* Key supplied to semget(2) */
    uid_t          uid;   /* Effective UID of owner */
    gid_t          gid;   /* Effective GID of owner */
    uid_t          cuid;  /* Effective UID of creator */
    gid_t          cgid;  /* Effective GID of creator */
    unsigned short mode;  /* Permissions */
    unsigned short __seq; /* Sequence number */
};

每个信号量维护
struct{
    unsigned short  semval;   /* semaphore value */
    unsigned short  semzcnt;  /* # waiting for zero */
    unsigned short  semncnt;  /* # waiting for increase */
    pid_t           sempid;   /* ID of process that did last op */
}
#endif


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define PROJ_ID     0x02

#define SHE_MODE    (IPC_CREAT | 0666)

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *arry;
};

//设置sem
int sem_setValue(int semid)
{
    int ret = 0;
    union semun unSem;
    unSem.val = 1;

    ret = semctl(semid, 0, SETVAL, unSem);
    if (ret < 0){
        perror("semctl");
        return -1;
    }
    return 0;
}

int sem_P(int semid)
{
    int ret = 0;
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1;
    sem_b.sem_flg = SEM_UNDO;

    ret = semop(semid, &sem_b, 1);
    if (ret < 0){
        perror("semop");
        return -1;
    }
    return 0;
}

int sem_V(int semid)
{
    int ret = 0;
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1;
    sem_b.sem_flg = SEM_UNDO;

    ret = semop(semid, &sem_b, 1);
    if (ret < 0){
        perror("semop");
        return -1;
    }
    return 0;
}

//shell : ./bin/sem.out 0 & ./bin/sem.out
int main(int argc, char* argv[])
{
    key_t key;
    int semid;
    int ret = 0;
    char outMess = 'X';

    //获得 key
    key = ftok("./", PROJ_ID);
    if (key == -1)
        perror("ftok");
    printf("key[0x%x]\n", key);

    semid = semget(key, 1, SHE_MODE);
    if (semid < 0){
        perror("semget");
        exit(1);
    }

    if (argc > 1)
    {
        //第一次调用，初始化信号量
        ret = sem_setValue(semid);
        if (ret < 0){
            exit(1);
        }
        outMess = '0';
        sleep(2);
    }

    for (int i = 0; i < 10; i++)
    {
        ret = sem_P(semid);
        if (ret < 0)
            exit(1);

        printf("%c", outMess);
        fflush(stdout);

        
        ret = sem_V(semid);
        if (ret < 0)
            exit(1);
        
        sleep(rand() % 2);
    }

    sleep(10);
    printf("\nfinished[%d]\n", getpid());

    if (argc > 1){
        sleep(2);
        printf("rm sem\n");
        ret = semctl(semid, 0, IPC_RMID);
        if (ret < 0){
            perror("semctl");
            exit(1);
        }
    }

    return 0;
}