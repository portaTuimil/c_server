final: main.c server.c client.c 
	gcc main.c server.c client.c -o c_server

main: main.c 
	gcc -o main main.c

clean: 
	rm main 
