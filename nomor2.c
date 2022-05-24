#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    char ch, source_file[20], target_file[20];
    FILE *source, *target;

    source = fopen("TugasBab9.txt", "r");

    if( source == NULL )
    {
        printf("Error");
        exit(1);
    }

    target = fopen("copy_of_TugasBab9.txt", "w");

    if( target == NULL )
    {
        fclose(source);
        printf("Error");
        exit(1);
    }

    while( ( ch = fgetc(source) ) != EOF )
        fputc(ch, target);
    
    printf("File berhasil di copy\n");

    fclose(source);
    fclose(target);

    return 0;
}
