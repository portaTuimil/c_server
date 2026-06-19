final: ./src/main.c ./src/server.c ./src/client.c 
	gcc ./src/main.c ./src/server.c ./src/client.c -Iinclude -o c_server

clean: 
	rm c_server 
