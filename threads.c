#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int a = 0;//инициализация глобальной чтатической перменной, доступной из каждого thread
//ф-ия вфыполняющаяся в рамках второго thread
void *mythread(void  *dummy) {
	pthread_t mythid;
	mythid = pthread_self();//индетификатор thread -  для каждого имеет свое значение
	a = a+1;
	printf("Thread %ld, Результат вычисления a = %d\n", mythid, a);//печать индетефикатора текущего thread и значения гьлобальной переменной
	return NULL;
}

int main() {
	pthread_t thid, mythid;
	int result;
	result = pthread_create(&thid, (pthread_attr_t *)NULL, mythread, NULL);//создание нового thread при помощи вызова функции mythread
	if(result != 0) {
		printf("ошибка при создании нового thread\'a, возвращение значения = %d\n",result);
		exit(-1);

	}
	printf("Thread создан, thid = %ld\n", thid);
	mythid = pthread_self();//создание в переменной mythid индетефикатора главного thread
	a = a+1;
	printf("Thread %ld, результат вычисления a = %d\n", mythid, a);
	pthread_join(thid, (void **)NULL);//ожидание завершения порожденного thread
	return 0;
}
