/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "claves.h"

bool_t
xdr_op3_1_argument (XDR *xdrs, op3_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->key))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->arg2, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->value2))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->value3))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_op6_1_argument (XDR *xdrs, op6_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->key))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->arg2, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->value2))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->value3))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_op7_1_argument (XDR *xdrs, op7_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->key1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->key2))
		 return FALSE;
	return TRUE;
}
