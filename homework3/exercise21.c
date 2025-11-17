#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = shm_open("/my_shm", O_RDWR, 0666);
    char *ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("Child sees: %s\n", ptr);
    strcpy(ptr, "Modified by child!");

    munmap(ptr, size);
    close(fd);
    return 0;
}
