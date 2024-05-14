#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
	int semid;//индетефикатор ipc массива симафора 
	char pathname[] = "forftok.ipc";//файл используемый ждя генерации айписи ключа
	key_t key;//айписи ключ
	struct sembuf mybuf;//структура для задания опреации над семафором
	//гнерация айписи ключа
	if ((key = ftok(pathname, 0)) < 0) {
		printf("не удалось сгенерировать ipc-ключ\n");
		exit(-1);
	}
	//получение доступа к массиву семафорапо айиписи ключу
	if((semid = semget(key, 1, 0666 | IPC_CREAT)) < 0) {
		printf("не удалось ПОЛУЧИТЬ ДОСТУП К МАССИВУ СИМАФОРА\n");
		exit(-1);
	}
	//заполняем структуру майбуф кодами операции семаформами 
	mybuf.sem_op = -1;
	mybuf.sem_flg = 0;
	mybuf.sem_num = 0;
	//выполнение операций
	if(semop(semid, &mybuf, 1) < 0) {
		printf("не удалось выполнить опрацию над семафором 0\n");
		exit(-1);
	}
	printf("условие установлено\n");
	return 0;
}
