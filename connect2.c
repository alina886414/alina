#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//подключение библиотеки для управления файлами
#include <fcntl.h>
int main () {
	int fd; //файловый дескриптор
	size_t size;//размер в байтах строки
	char string[]="group 3.120.2.21";
//открытие файла на запись, если файла не существует, то он будет с правами доступа 0666
	if((fd = open("file1.txt", O_WRONLY|O_CREAT, 0666))<0){
		printf("ошибка при открытии файла на запись\n");
		exit(-1);
	}
//чтение из файла в строку string
	size=(fd, string, 17);
	if (size !=17){
		printf("не удалось записать строку в файл\n");
		exit(-1);
	}
//закрытие файла
	if (close(fd)<0){
		printf("не удалось закрыть файл\n");
		exit(-1);
	}
	return 0;
}

