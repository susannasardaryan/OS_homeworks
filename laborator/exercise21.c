#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    size_t size = 4096;

    int fd = shm_open("/my_shm", O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open (child)");
        return 1;
    }

    char *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap (child)");
        return 1;
    }

    printf("Child PID %d read: %s\n", getpid(), ptr);

    strcpy(ptr, "Modified by child!");

    munmap(ptr, size);
    close(fd);
    return 0;
}
