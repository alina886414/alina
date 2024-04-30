#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
//создаем массив из двух элементов для  хранения файловдискрипторов для чтения и записи
	int fd1[2], fd2[2];
	pid_t result;
	size_t size;
	char string1[] = "hello, child!", string2[] = "hello, parent!";
	char resstring1[13], resstring2[14];
	if(pipe(fd1) < 0) {
		printf("не получилось создать pipe\n");
//возврат признака аварийного завершения программы (-1)
		exit(-1);
	}
	if (pipe(fd2)<0) {
		printf("не получилось создать pipe\n");
//возврат признака аварийного завершения программы (-1)
		exit(-1);
	}
	result = fork();
	if (result<0) {
		printf("ошибка выполнения fork()\n");
		exit(-1);
	}
	else if (result>0) {
		if (close(fd1[0])<0) {
			printf("ошибка при закрытии pipe на чтение\n");
			exit(-1);	
		}
		if (close(fd2[0])<0) {
                        printf("ошибка при закрытии pipe на чтение\n");
			exit(-1);
		}
		size = write(fd1[1], string1, 13);
		//проверка колличества байт, записанных в строку
		if (size != 13) {
			printf("can't write all string\n");
			exit(-1);
		}
		printf("процесс родитель записал информацию в pipe и заканчиват работут");
		size = read(fd2[0], resstring2, 14);
		//проверка колличества байт, записанных в строку
		if (size !=14) {
			printf("can't read string\n");
			exit(-1);
		}
		printf("информация от дочернего процесса:");
		for (int i=0; i < 14; i++) printf("%c", resstring2[i]);
		printf("\n");
		if (close(fd1[0])<0) {
                        printf("can't close output strea\n");
                        exit(-1);       
                }
                if (close(fd2[0])<0) {
                        printf("can't close output stream\n");
			exit(-1);
                }
	}
	else {
		if(close(fd1[1])<0) {
			printf("can't close output stream\n");
			exit(-1);
		}
		if(close(fd2[1])<0) {
                        printf("can't close input stream\n");
                        exit(-1);
                }
		size = read(fd1[0], resstring2, 13);
		//закрытие pipe для записи
		if (size !=13) {
			printf("can't read string\n");
			exit(-1);
		}
		printf("Информация от родителя:");
		for (int i=0; i < 13; i++) printf("%c", resstring1[i]);
                printf("\n");
		size = write(fd2[1], string2, 14);
		//проверка колличества байт, записанных в строку
		if (size != 14) {
			printf("can't write all string\n");
			exit(-1);
		}
		printf("child wrote information in pipe\n");
		//проверка колличества байт,прочитанных в pipe
		if(close(fd1[1])<0) {
                        printf("can't close input stream\n");
                        exit(-1);
                }
                if(close(fd2[1])<0) {
                        printf("can't close output stream\n");
                        exit(-1);
                }
	}
	return 0;
}

	
