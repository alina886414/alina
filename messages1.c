#include <sys/types.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define LAST_MESSAGE 255

int main() {
	int msqid;
	char pathname[] = "ftok.ipc";
	key_t key;
	int i, maxlen;
	struct mymgbuf {
		long mtype;
		char mtext[81];
	} mybuf;
	if((key = ftok(pathname, 0)) <0) {
		printf("не удалось сгенерировать айписи-ключ\n");
		exit(-1);
	}
	if((msqid = msgget(key, 0666|IPC_CREAT)) <0) {
		printf("не удалось получить дескриптор очереди сообщений\n");
		exit(-1);
	}
	while(1) {
		maxlen = 81;
		if (msgrcv(msqid, (struct msgbuf *) &mybuf, maxlen, 0, 0) < 0) {
			printf("не удалось отправить сообщение в очередь\n");
			msgctl(msqid, IPC_RMID, (struct msqid_ds *) NULL);
			exit(-1);
		}
        	if (mybuf.mtype == LAST_MESSAGE) {
                 	msgctl(msqid, IPC_RMID, (struct msqid_ds *) NULL);
                	 exit(-1);
        	}
		printf("тип сообщений = %ld, информация: %s", mybuf.mtype, mybuf.mtext);
	}
	return 0;
}
