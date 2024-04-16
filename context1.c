

//родключение библиотек

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// главная функция программы 
int main(int argc, char *argv[], char *envp[]) {
	int result;
	//запуск программы cat с аргументами  "fork1.c"
	result = execle("/bin/cat","/bin/cat", "fork1.c", 0, envp);
	//printf() выполняется в случае ошибки
	printf("ошибка при выполнении системного вызова execle()\n");
	exit(-1);
	return 0; //никогда не выполняется
}
