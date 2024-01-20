//подключение библиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//главная ф-ия программы 
int main() {
//объявление пременной
        pid_t getpid(void);
        pid_t getppid(void);
//системный вызов getuid()
        pid = getpid();
//системный вызов getgid()
        ppid = getppid();
        printf("ид. пользователь: %d\n", pid);
        printf("ид. группы пользователя: %d\n", ppid);
//возврат значения "0' из главной ф-ии
        return 0;
}
