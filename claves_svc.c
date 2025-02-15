/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "claves.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

int
_server_init_1 (void  *argp, void *result, struct svc_req *rqstp)
{
	return (server_init_1_svc(result, rqstp));
}

int
_server_exist_1 (int  *argp, void *result, struct svc_req *rqstp)
{
	return (server_exist_1_svc(*argp, result, rqstp));
}

int
_server_set_value_1 (server_set_value_1_argument *argp, void *result, struct svc_req *rqstp)
{
	return (server_set_value_1_svc(argp->key, argp->value1, argp->value2, argp->value3, result, rqstp));
}

int
_server_get_value_1 (int  *argp, void *result, struct svc_req *rqstp)
{
	return (server_get_value_1_svc(*argp, result, rqstp));
}

int
_server_delete_value_1 (int  *argp, void *result, struct svc_req *rqstp)
{
	return (server_delete_value_1_svc(*argp, result, rqstp));
}

int
_server_modify_value_1 (server_modify_value_1_argument *argp, void *result, struct svc_req *rqstp)
{
	return (server_modify_value_1_svc(argp->key, argp->arg2, argp->value2, argp->value3, result, rqstp));
}

int
_server_copy_key_1 (server_copy_key_1_argument *argp, void *result, struct svc_req *rqstp)
{
	return (server_copy_key_1_svc(argp->key1, argp->key2, result, rqstp));
}

static void
claves_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		int server_exist_1_arg;
		server_set_value_1_argument server_set_value_1_arg;
		int server_get_value_1_arg;
		int server_delete_value_1_arg;
		server_modify_value_1_argument server_modify_value_1_arg;
		server_copy_key_1_argument server_copy_key_1_arg;
	} argument;
	union {
		int server_init_1_res;
		int server_exist_1_res;
		int server_set_value_1_res;
		respuesta server_get_value_1_res;
		int server_delete_value_1_res;
		int server_modify_value_1_res;
		int server_copy_key_1_res;
	} result;
	bool_t retval;
	xdrproc_t _xdr_argument, _xdr_result;
	bool_t (*local)(char *, void *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case server_init:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_server_init_1;
		break;

	case server_exist:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_server_exist_1;
		break;

	case server_set_value:
		_xdr_argument = (xdrproc_t) xdr_server_set_value_1_argument;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_server_set_value_1;
		break;

	case server_get_value:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_respuesta;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_server_get_value_1;
		break;

	case server_delete_value:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_server_delete_value_1;
		break;

	case server_modify_value:
		_xdr_argument = (xdrproc_t) xdr_server_modify_value_1_argument;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_server_modify_value_1;
		break;

	case server_copy_key:
		_xdr_argument = (xdrproc_t) xdr_server_copy_key_1_argument;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_server_copy_key_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	retval = (bool_t) (*local)((char *)&argument, (void *)&result, rqstp);
	if (retval > 0 && !svc_sendreply(transp, (xdrproc_t) _xdr_result, (char *)&result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	if (!claves_1_freeresult (transp, _xdr_result, (caddr_t) &result))
		fprintf (stderr, "%s", "unable to free results");

	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (CLAVES, OPERACIONESVER);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, CLAVES, OPERACIONESVER, claves_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CLAVES, OPERACIONESVER, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, CLAVES, OPERACIONESVER, claves_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CLAVES, OPERACIONESVER, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
