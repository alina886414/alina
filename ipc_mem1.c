#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
	int *array;
	int shmid;
	int new = 1;
	char pathname[] = "forftok.ipc";
	key_t key;
	if ((key = ftok(pathname,0)) < 0) {
		printf("не удалось сгенерировать ipc-ключ \n");
		exit(-1);
	}
	if((shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0) {
		if(errno != EEXIST) {
			printf("не удается создать область разделяемой памяти\n");
			exit(-1);
		}
		else {
			if((shmid = shmget(key, 3*sizeof(int), 0)) < 0) {
				printf("не удается создать область разделенной памяти\n");
				exit(-1);
			}
			new = 0;
		}
	}
	if((array = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)) {
		printf("не удалость добавить разделяемую память в адресное пространнство процесса\n");
		exit(-1);
	}
	if(new) {
		array[0] = 0;
		array[1] = 1;
		array[2] = 1;
	}
	else {
		array[1] += 1;
		array[2] += 1;
	}
	printf("программа 1 бфла запущена %d раз, программа 2 - %d раз, всего - %d\n", array[0], array[1], array[2]);
	if(shmdt(array)<0) {
		printf(" не удаеться исключить разделенную память мз адресного ространства процесса\n");
		exit(-1);
	}
	return 0;
}

