//родключение библиотек

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// главная функция программы 
int main(int argc, char *argv[], char *envp[]) {
	int result1;
	// объявление переменных 
	pid_t procid,parentid; // инд.процесса
	pid_t result; // результат системного вызова fork()
	int a=0; // переменная для проверки  процесса родителя и процесаа ребенка
	result1 = fork();
	if (result < 0) {
		printf("ошибка при выполнении fork()\n");
		exit(-1);
	}
	else if (result == 0) {
		a = a+1;
		procid = getpid(); // получение инд. текущего процесса
		parentid = getppid(); // получение инд. родительского процесса 
		printf("инд.процесса: %d, инд. родителя: %d, значение переменной a: %d\n", procid, parentid, a);
		result1 = execle("/bin/cat","/bin/cat", "fork1.c", 0, envp);
       		printf("ошибка при выполнении системного вызова execle()\n");
       		exit(-1);
	
	}
	else {
		a = a + 555;	
        	procid = getpid(); // получение инд. текущего процесса
    	        parentid = getppid(); // получение инд. родительского процесса 
	        printf("инд.процесса: %d, инд. родителя: %d, значение переменной a: %d\n", procid, parentid, a);

        }
	return 0;
}
