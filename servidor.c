#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include "operaciones/operaciones.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include "mensaje.h"

// threads and mutexes' global variables
pthread_cond_t cond_message;
pthread_mutex_t mutex_message, mutex_executing;
int not_message_copied = 1;
char buffer[1024];


// function to process the message and execute the requested operation
void process_message(struct message *msg) {
    struct message msg_resp = *msg;
    // copy the descriptor to a local variable
    int s_local;
    pthread_mutex_lock(&mutex_message);
    // copy the message to the global variable
    s_local = msg_resp.s;
    not_message_copied = 0;
    pthread_cond_signal(&cond_message);
    pthread_mutex_unlock(&mutex_message);

    pthread_mutex_init(&mutex_executing, NULL);
    pthread_mutex_lock(&mutex_executing);
    int err, res;
    int data = 0;

    switch (msg_resp.op) {
        case 1:
            res = init();
            break;
        case 2:
            res = set_value(msg_resp.key, msg_resp.value1, msg_resp.value2, msg_resp.value3);
            break;
        case 3:
            res = get_value(msg_resp.key, msg_resp.value1, &msg_resp.value2, &msg_resp.value3);
            data = 1;
            break;
        case 4:
            res = modify_value(msg_resp.key, msg_resp.value1, msg_resp.value2, msg_resp.value3);
            break;
        case 5:
            res = delete_value(msg_resp.key);
            break;
        case 6:
            res = exist(msg_resp.key);
            break;
        case 7:
            res = copy_key(msg_resp.key, msg_resp.key2);
            break;
        default:
            res = -1;
            break;
    }
    pthread_mutex_unlock(&mutex_executing);

    // send the response to the client
    
    pthread_exit(NULL);
}


int main(int argc, char *argv[]) {
    return 0;
}
