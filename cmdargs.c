#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[], char *envp[]) {
	int i;
	printf("Колличество аргументов: %d\n\n", argc);
	if (argc<1) {
	//	for (int i=0; i<argc; i++) {
		printf("Error\n");
	//	printf("аргумент %d: %s\n", i, argv[i]);
		exit(-1);
	}
	else if (argc == 1) {
		while(envp[i]!=NULL) {
		printf("%s\n", envp[i]);
		i++;
		}
	}
	else {
		for(i = 0; i<argc; i++) {
			printf("аргумент %d: %s\n", i, argv[i]);
		}
	}
	return 0;
}
