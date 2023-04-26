#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../claves.h"


int is_value1_valid(char *value1) {
    if (strlen(value1) > 256) {
        return -1;
    }
    return 0;
}

char *get_env_variable() {
    char *ip_tuplas = getenv("IP_TUPLAS");
    if (ip_tuplas == NULL) {
        printf("Error: no se han encontrado las variables de entorno IP_TUPLAS\n");
        return NULL;
    }
    return ip_tuplas;
}

int client_init() {
    int err;
    CLIENT *clnt;
	enum clnt_stat retval;
	int result;
    char *ip_tuplas;

    
    ip_tuplas = get_env_variable();
    if (err != 0) return -1;
    clnt = clnt_create (ip_tuplas, CLAVES, OPERACIONESVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip_tuplas);
		exit (1);
    }
    dprintf(1, "cliente creado");
    retval = server_init_1(&result, clnt);
    dprintf(1, "init: %d", result);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
    return 0;
}


int client_set_value(int key, char *value1, int value2, double value3) {
    return 0;
}

int client_get_value(int key, char *value1, int *value2, double *value3) {
    return 0;
}

int client_modify_value(int key, char *value1, int value2, double value3) {
    return 0;
}

int client_delete_value(int key) {
    return 0;
}

int client_exist(int key) {
    return 0;
}

int client_copy_key(int key1, int key2) {
    return 0;
}