#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char ch, source_file[20], target_file[20];
	FILE *source, *target;

	source = fopen("contoh.txt", "r");

	if( source == NULL )
	{
		printf("Error");
		exit(1);
	}
	
	chdir("pindahandirektori");

	target = fopen("contoh.txt", "w");
	
	if( target == NULL )
	{
		fclose(source);
		printf("Error");
		exit(1);
	}

	while( ( ch = fgetc(source) ) != EOF )
		fputc(ch, target);
	
	chdir("..");
	if (remove("contoh.txt") == 0)
		printf("berhasil dihapus");
	else
		printf("penghapusan gagal");

	printf("file berhasil dipindah\n");
	
	

	fclose(source);
	fclose(target);

	return 0;
}
