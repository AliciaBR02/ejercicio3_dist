CC = gcc
CLAVES_PATH = claves
SOCKETS_PATH = sockets
CFLAGS = -lrt -g -I/usr/include/tirpc
LDFLAGS = -lnsl -lpthread -ldl -ltirpc
OBJS = servidor libclaves.so cliente 
BIN_FILES = servidor cliente cliente2
SERVER_OBJS = servidor.o operaciones/operaciones.o claves_svc.o claves_xdr.o
CLIENT_OBJS = cliente.o claves/claves.o claves_xdr.o claves_clnt.o
LIB_OBJS = claves/claves.o
all: $(OBJS)

libclaves.so: claves/claves.c
	$(CC) $(CFLAGS) -fPIC -c -o $<
	$(CC) $(LDFLAGS) -shared -o $@ $(LIB_OBJS) -lrt

servidor: $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $@.out $(LDFLAGS)

cliente: $(CLIENT_OBJS) libclaves.so
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $@.out $(LDFLAGS) -L. -lclaves

clean:
	rm -f $(BIN_FILES) *.out *.o *.so $(CLAVES_PATH)/*.o data.txt

re:	clean all

.PHONY: all libclaves.so servidor cliente clean re