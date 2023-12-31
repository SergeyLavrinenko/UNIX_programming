#include <stdio.h>
#include "sys/wait.h"

#include <sys/mman.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <semaphore.h>
#include <ctime>

#include "../my_shm.h"
int child(void);
int parent(pid_t);

struct shmstruct {
    unsigned long time_stamp;
    char msg[1000];
};

unsigned long temp_timestamp = 0;


struct shmstruct *ptr;
int main()
{
    unsigned long time;

    int shm_fd;
    pid_t cpid, pid;
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    ptr = (struct shmstruct *) mmap(0, SHM_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    close(shm_fd);
    mlock(ptr, SHM_SIZE);
    
    while(1){
        if(temp_timestamp != ptr -> time_stamp){
            pid_t pid = getpid();
            temp_timestamp = ptr -> time_stamp;
            
            printf("%ld read: %s\n", (long)pid, ptr->msg);
        }
        sleep(1);
    }

    munmap(ptr, SHM_SIZE);
    shm_unlink(SHM_NAME);
    return 0;
}

