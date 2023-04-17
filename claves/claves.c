/*pendiente*/

int is_value1_valid(char *value1) {
    if (strlen(value1) > 256) {
        return -1;
    }
    return 0;
}

int client_init() {
    return 0;
}


int client_set_value(int key, char *value1, int value2, double value3) {
    int error = is_value1_valid(value1);
    if (error != 0) {
        return error;
    }
    return 0;
}

int client_get_value(int key, char *value1, int *value2, double *value3) {
    return 0;
}

int client_modify_value(int key, char *value1, int value2, double value3) {
    int error = is_value1_valid(value1);
    if (error != 0) {
        return error;
    }
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
