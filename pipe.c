#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
//создаем массив из двух элементов для  хранения файловдискрипторов для чтения и записи
	int fd[2];
	size_t size;
	char string[] = "hello, world!";
	char resstring[14];
	if(pipe(fd) < 0) {
		printf("не получилось создать pipe()");
//возврат признака аварийного завершения программы (-1)
		exit(-1);
	}
	size = write(fd[1], string, 14);
//проверка колличества байт, записанных в строку с помощью write()
	if (size != 14) {
		printf("не получилось записать строку\n");
		exit(-1);
	}
	size = read(fd[0], resstring, 14);
//проверка колличества байт,прочитанных из pipe() с помощью read()
	if (size != 14) {
                printf("не получилось прочитать строку\n");
                exit(-1);
        }
	printf("%s\n", resstring);
//закрытие pipe для чтения
	if (close (fd[0]) < 0) {
		printf("не получилось закрыть входящий поток\n");
		exit(-1);
	}
//закрытие pipe для записи
	if (close (fd[1]) < 0) {
		printf("не получилось закрыть исходящий поток\n");
		exit(-1);
	}
	return 0;
}
