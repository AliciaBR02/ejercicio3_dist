/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "claves.h"
#include "operaciones/operaciones.h"

bool_t
server_init_1_svc(int *result, struct svc_req *rqstp)
{
	bool_t retval;
	
	retval = TRUE;
	*result = init();
	return retval;
}

bool_t
server_exist_1_svc(int key, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */
	retval = TRUE;
	*result = exist(key);
	return retval;
}

bool_t
server_set_value_1_svc(int key, char *value1, int value2, double value3, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */
	retval = TRUE;
	*result = set_value(key, value1, value2, value3);
	return retval;
}

bool_t
server_get_value_1_svc(int key, respuesta *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */
	retval = TRUE;
	result->result = get_value(key, result->value1, &result->value2, &result->value3);

	return retval;
}

bool_t
server_delete_value_1_svc(int key, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */
	retval = TRUE;
	*result = delete_value(key);

	return retval;
}

bool_t
server_modify_value_1_svc(int key, char *arg2, int value2, double value3, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */
	retval = TRUE;
	*result = modify_value(key, arg2, value2, value3);

	return retval;
}

bool_t
server_copy_key_1_svc(int key1, int key2, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */
	retval = TRUE;
	*result = copy_key(key1, key2);
	return retval;
}

int
claves_1_freeresult (SVCXPRT *transp, xdrproc_t xdr_result, caddr_t result)
{
	xdr_free (xdr_result, result);

	/*
	 * Insert additional freeing code here, if needed
	 */

	return 1;
}
