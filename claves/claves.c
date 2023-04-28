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



int client_init() {
    CLIENT *clnt;
	enum clnt_stat retval;
	int result;

    char *ip_tuplas = getenv("IP_TUPLAS");
    if (ip_tuplas == NULL) {
        printf("Error: no se han encontrado las variables de entorno IP_TUPLAS\n");
        return -1;
    }

    clnt = clnt_create (ip_tuplas, CLAVES, OPERACIONESVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip_tuplas);
		exit (1);
    }
    retval = server_init_1(&result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
    return result;
}


int client_set_value(int key, char *value1, int value2, double value3) {
    CLIENT *clnt;
	enum clnt_stat retval;
	int result;

    result = is_value1_valid(value1);
    if (result != 0) return result;
    
    char *ip_tuplas = getenv("IP_TUPLAS");
    if (ip_tuplas == NULL) {
        printf("Error: no se han encontrado las variables de entorno IP_TUPLAS\n");
        return -1;
    }

    clnt = clnt_create (ip_tuplas, CLAVES, OPERACIONESVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip_tuplas);
		exit (1);
    }
    retval = server_set_value_1(key, value1, value2, value3, &result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
    return result;
}

int client_get_value(int key, char *value1, int *value2, double *value3) {
    CLIENT *clnt;
	enum clnt_stat retval;
	struct respuesta result;

    char *ip_tuplas = getenv("IP_TUPLAS");
    if (ip_tuplas == NULL) {
        printf("Error: no se han encontrado las variables de entorno IP_TUPLAS\n");
        return -1;
    }

    clnt = clnt_create (ip_tuplas, CLAVES, OPERACIONESVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip_tuplas);
		exit (1);
    }
    dprintf(1, "\nantes de la operacion\n");
    result.value1 = malloc(256);
    retval = server_get_value_1(key, &result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
    dprintf(1, "despues de laoperacion\n");
    strcpy(value1, result.value1);
    *value2 = result.value2;
    *value3 = result.value3;

    return result.result;
}

int client_modify_value(int key, char *value1, int value2, double value3) {
    CLIENT *clnt;
	enum clnt_stat retval;
	int result;

    result = is_value1_valid(value1);
    if (result != 0) return result;
    
    
    char *ip_tuplas = getenv("IP_TUPLAS");
    if (ip_tuplas == NULL) {
        printf("Error: no se han encontrado las variables de entorno IP_TUPLAS\n");
        return -1;
    }

    clnt = clnt_create (ip_tuplas, CLAVES, OPERACIONESVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip_tuplas);
		exit (1);
    }
    retval = server_modify_value_1(key, value1, value2, value3, &result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
    return result;
}

int client_delete_value(int key) {
    CLIENT *clnt;
	enum clnt_stat retval;
	int result;
    
    char *ip_tuplas = getenv("IP_TUPLAS");
    if (ip_tuplas == NULL) {
        printf("Error: no se han encontrado las variables de entorno IP_TUPLAS\n");
        return -1;
    }

    clnt = clnt_create (ip_tuplas, CLAVES, OPERACIONESVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip_tuplas);
		exit (1);
    }
    retval = server_delete_value_1(key, &result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
    return result;
}

int client_exist(int key) {
    CLIENT *clnt;
	enum clnt_stat retval;
	int result;
    
    char *ip_tuplas = getenv("IP_TUPLAS");
    if (ip_tuplas == NULL) {
        printf("Error: no se han encontrado las variables de entorno IP_TUPLAS\n");
        return -1;
    }

    clnt = clnt_create (ip_tuplas, CLAVES, OPERACIONESVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip_tuplas);
		exit (1);
    }
    retval = server_exist_1(key, &result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
    return result;
}

int client_copy_key(int key1, int key2) {
    CLIENT *clnt;
	enum clnt_stat retval;
	int result;
    
    char *ip_tuplas = getenv("IP_TUPLAS");
    if (ip_tuplas == NULL) {
        printf("Error: no se han encontrado las variables de entorno IP_TUPLAS\n");
        return -1;
    }

    clnt = clnt_create (ip_tuplas, CLAVES, OPERACIONESVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip_tuplas);
		exit (1);
    }
    retval = server_copy_key_1(key1, key2, &result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
    return result;
}