CC = gcc
CLAVES_PATH = claves
SOCKETS_PATH = sockets
CFLAGS = -lrt -g -I/usr/include/tirpc
LDFLAGS = -lnsl -lpthread -ldl -ltirpc
OBJS = servidor libclaves.so cliente cliente2
BIN_FILES = servidor cliente cliente2
SERVER_OBJS = servidor.o operaciones/operaciones.o claves_svc.o claves_xdr.o
CLIENT_OBJS = claves/claves.o claves_xdr.o claves_clnt.o
CLIENT1 = cliente.o
CLIENT2 = cliente2.o
LIB_OBJS = claves/claves.o

all: $(OBJS)

libclaves.so: claves/claves.o $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -fPIC -c -o $<
	$(CC) $(LDFLAGS) -shared -o $@ $(LIB_OBJS) -lrt

servidor: $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $@.out $(LDFLAGS)

cliente: $(CLIENT1) libclaves.so
	$(CC) $(CFLAGS) $(CLIENT1) $(CLIENT_OBJS) -o $@.out $(LDFLAGS) -L. -lclaves

cliente2: $(CLIENT2) libclaves.so
	$(CC) $(CFLAGS) $(CLIENT2) $(CLIENT_OBJS) -o $@.out $(LDFLAGS) -L. -lclaves

clean:
	rm -f $(BIN_FILES) *.out *.o *.so $(CLAVES_PATH)/*.o data.txt

re:	clean all

.PHONY: all libclaves.so servidor cliente cliente2 clean re