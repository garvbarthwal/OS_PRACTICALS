#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {
    long type;
    char text[100];
};

int main() {
    key_t key = ftok("msgfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg m;

    msgrcv(msgid, &m, sizeof(m.text), 1, 0);

    printf("Received: %s", m.text);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
