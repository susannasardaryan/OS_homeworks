#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main()
{
    const char *name = "/my_shm";
    size_t size = 4096;

    int fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, size);

    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap failed");
        return 1;
    }

    strcpy((char *)ptr, "Hello from memory!");
    printf("Virtual address: %p\n", ptr);
    pid_t id = fork();
    if (id == 0)
    {
        execl("./exercise21", "./exercise21", (char *)NULL);
    }

    wait(NULL);
    printf("Parent sees after child: %s\n", (char *)ptr);

    munmap(ptr, size);
    close(fd);
    shm_unlink(name);
    return 0;
}
