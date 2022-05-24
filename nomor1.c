#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd, size;
    char *c = (char *) calloc(100, sizeof (char));

    fd = open("bab9.txt", O_RDONLY);
    if (fd < 0){
        perror("Error");
        exit(1);
    }

    size = read(fd, c, 20);
    c[size]= '\0';
    printf("Isi file tersebut ialah: %s", c);
}
