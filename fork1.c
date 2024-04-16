// программа для одинаковой работы процесса родителя и процесса ребенка

//родключение библиотек

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// главная функция программы 
int main() {
	// объявление переменных 
	pid_t procid,parentid; // инд.процесса
	pid_t result; // результат системного вызова fork()
	int a=0; // переменная для проверки  процесса родителя и процесаа ребенка
	result = fork();
	if (result < 0) {
		printf("ошибка при выполнении fork()\n");
		exit(-1);
	}
	else if (result == 0) {
		a = a+1;
		procid = getpid(); // получение инд. текущего процесса
		parentid = getppid(); // получение инд. родительского процесса 
		printf("инд.процесса: %d, инд. родителя: %d, значение переменной a: %d\n", procid, parentid, a);
	}
	else {
		a = a + 555;	
        	procid = getpid(); // получение инд. текущего процесса
    	        parentid = getppid(); // получение инд. родительского процесса 
	        printf("инд.процесса: %d, инд. родителя: %d, значение переменной a: %d\n", procid, parentid, a);

        }
	return 0;
}
