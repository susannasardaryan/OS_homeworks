#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *name = "/my_shm";
    size_t size = 4096;

    int fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open failed");
        exit(1);
    }

    ftruncate(fd, size);

    char *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    strcpy(ptr, "Hello from parent!");

    printf("Parent PID %d, address: %p\n", getpid(), ptr);

    pid_t id = fork();
    if (id == 0) {
        execl("./exercise21", "./exercise21", NULL);
        perror("execl");
        _exit(1);
    }

    wait(NULL);
    printf("Parent after child: %s\n", ptr);

    munmap(ptr, size);
    close(fd);
    shm_unlink(name);

    return 0;
}
