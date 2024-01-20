
//подключение библиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//главная ф-ия программы 
int main() {
//объявление пременной
	uid_t userid;
	gid_t groupid;
//системный вызов getuid()
	userid = getuid();
//системный вызов getgid()
	groupid = getgid();
	printf("ид. пользователь: %d\n", userid);
	printf("ид. группы пользователя: %d\n", groupid);
//возврат значения "0' из главной ф-ии
	return 0;
}
