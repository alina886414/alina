#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
	int *array;//указатель на массив разделенный в общей памяти 
	int shmid;// индетефикатор области разделенной памяти
	int new = 1;//признак необходимости создания нового массива
	char pathname[] = "forftok.ipc";// файл необходимый для генератора ipc
	key_t key;//переменная ждя хранения ключа ipc
	//попытка генерации ключа ipc
	if ((key = ftok(pathname,0)) < 0) {
		printf("не удалось сгенерировать ipc-ключ \n");
		exit(-1);
	}
	 //попытка создания области разделяемой памяти 
	if((shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0) {
		//проверяем что ошибка при создания области разделяемой памяти не связанная с тем что область уже существует 
		if(errno != EEXIST) {
			printf("не удается создать область разделяемой памяти\n");
			exit(-1);
		}
		//получение индетефикатора области разделяемой памяти  если областьуже существует
		else {
			if((shmid = shmget(key, 3*sizeof(int), 0)) < 0) {
				printf("не удается создать область разделенной памяти\n");
				exit(-1);
			}
			new = 0;// установка признака уже существующей области разделяемой памяти
		}
	}
	//включение разделяемой памяти в адресное пространство текущего процесса
	if((array = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)) {
		printf("не удалость добавить разделяемую память в адресное пространнство процесса\n");
		exit(-1);
	}
	// операция над созданным массивом
	if(new) {
		array[0] = 0;
		array[1] = 1;
		array[2] = 1;
	}
	//операция над существующим массивом
	else {
		array[1] += 1;
		array[2] += 1;
	}
	printf("программа 1 бфла запущена %d раз, программа 2 - %d раз, всего - %d\n", array[0], array[1], array[2]);
	//исключение области разделяемой памяти из адресного пространства текущего проыесса
	if(shmdt(array)<0) {
		printf(" не удаеться исключить разделенную память мз адресного ространства процесса\n");
		exit(-1);
	}
	return 0;
}

