all: exServerSocket exClientSocket sin_nombre escritor lector escritor_v2 lector_socket escritor_socket

escritor_socket: escritor_socket.c
	gcc -o escritor_socket escritor_socket.c

lector_socket: lector_socket.c
	gcc -o lector_socket lector_socket.c

escritor_v2: escritor_v2.c
	gcc -o escritor_v2 escritor_v2.c

escritor: escritor.c
	gcc -o escritor escritor.c

lector: lector.c
	gcc -o lector lector.c

sin_nombre: sin_nombre.c
	gcc -o sin_nombre sin_nombre.c

exServerSocket: exServerSocket.c socketMng.o
	gcc -o exServerSocket exServerSocket.c socketMng.o

exClientSocket: exClientSocket.c socketMng.o
	gcc -o exClientSocket exClientSocket.c socketMng.o

socketMng.o: socketMng.c
	gcc -c socketMng.c

clean: 
	rm -f exServerSocket exClientSocket socketMng.o sin_nombre escritor lector escritor_v2 lector_socket escritor_socket
