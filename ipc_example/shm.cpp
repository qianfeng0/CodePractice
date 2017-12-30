#if (0)
共享内存维护
struct shmid_ds {
    struct ipc_perm shm_perm;    /* Ownership and permissions */
    size_t          shm_segsz;   /* Size of segment (bytes) */
    time_t          shm_atime;   /* Last attach time */
    time_t          shm_dtime;   /* Last detach time */
    time_t          shm_ctime;   /* Last change time */
    pid_t           shm_cpid;    /* PID of creator */
    pid_t           shm_lpid;    /* PID of last shmat(2)/shmdt(2) */
    shmatt_t        shm_nattch;  /* No. of current attaches */
    ...
};

#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#include <string.h>

#include <sys/ipc.h>
#include <sys/shm.h>


#define SHM_SIZE    1024

//IPC_CREAT 如果不存在就创建
//IPC_EXCL 如果已经存在则返回失败
#define SHM_MODE    (SHM_R | SHM_W | IPC_CREAT)

#define PROJ_ID     0x01

#define TAG 0X55000055

struct ShareMemory{
    uint32_t tag;
    char data[SHM_SIZE - sizeof(uint32_t)];
};

int main(int argc, char *argv[])
{
    key_t key;
    int shmid;
    void* shmaddr = NULL;
    int ret = 0;
    //获得 key
    key = ftok("./", PROJ_ID);
    if (key == -1)
        perror("ftok");
    printf("key[0x%x]\n", key);

    //创建共享内存
    shmid = shmget(key, SHM_SIZE, SHM_MODE);
    if (shmid < 0){
        perror("shmget");
        exit(1);
    }
    printf("shmid[%d]\n", shmid);

    //映射
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void*)-1){
        perror("shmat");
        exit(-1);
    }

    ShareMemory *stShm = (ShareMemory*)shmaddr;
    if (stShm->tag == TAG){
        printf("%s", (char*)stShm->data);
        return 0;
    }
    
    printf("write data in share memory\n");
    bzero(shmaddr, SHM_SIZE);

    stShm->tag = TAG;
    strcpy((char*)stShm->data, "hello\n");

    printf("enter to destory share memory...\n");
    getchar();

    //删除映射
    ret = shmdt(shmaddr);
    if (ret < 0){
        perror("shmdt");
        exit(1);
    }
    
    //删除共享内存
    ret = shmctl(shmid, IPC_RMID, NULL);
    if (ret < 0){
        perror("shmctl");
        exit(1);
    }

    return 0;
}