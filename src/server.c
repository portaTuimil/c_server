#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h> 
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "connection.h" 

int handle_client(int clientSocket);

void run_server(const ConnectionConfig *config) {
  int serverSocketD = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in servAddr;

  servAddr.sin_family = AF_INET;
  servAddr.sin_port = htons(config->port);
  servAddr.sin_addr.s_addr = INADDR_ANY;

  bind(serverSocketD, (struct sockaddr*)&servAddr, sizeof(servAddr));
  listen(serverSocketD, 1);
  
  while(1){
    int clientSocket = accept(serverSocketD, NULL, NULL);
    if (clientSocket == -1) {
            perror("Accept failed");
            continue;
    }
    handle_client(clientSocket);
  }
  close(serverSocketD);
  return;
}

int handle_client(int clientSocket){
  char htmlBody[] = "<html>"
                    "<head><title>My C Web Server</title></head>"
                    "<body>"
                    "<h1>Success!</h1>"
                    "<p>This page was served entirely using raw C sockets.</p>"
                    "</body>"
                    "</html>";

  char httpResponse[4096];
  snprintf(httpResponse, sizeof(httpResponse),
                 "HTTP/1.1 200 OK\r\n"
                 "Content-Type: text/html\r\n"
                 "Content-Length: %zu\r\n"
                 "Connection: close\r\n"
                 "\r\n"
                 "%s",
                 strlen(htmlBody), htmlBody);

  send(clientSocket, httpResponse, strlen(httpResponse), 0);
  close(clientSocket);
}
