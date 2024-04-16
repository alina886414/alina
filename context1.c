// программа для одинаковой работы процесса родителя и процесса ребенка

//родключение библиотек

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// главная функция программы 
int main(int argc, char *argv[], char *envp[]) {
	int result;
	result = execle("/bin/cat","/bin/cat", "fork1.c", 0, envp);
	printf("ошибка при выполнении системного вызова execle()\n");
	exit(-1);
	return 0;
}
