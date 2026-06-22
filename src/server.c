#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h> 
#include <sys/types.h>
#include "connection.h" 

void run_server(const ConnectionConfig *config) {
  int serverSocketD = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in servAddr;

  servAddr.sin_family = AF_INET;
  servAddr.sin_port = htons(config->port);
  servAddr.sin_addr.s_addr = INADDR_ANY;

  bind(serverSocketD, (struct sockaddr*)&servAddr, sizeof(servAddr));
  listen(serverSocketD, 1);

  int clientSocket = accept(serverSocketD, NULL, NULL);
  char serMsg[255] = "Connection accepted.";
  send(clientSocket, serMsg, sizeof(serMsg), 0);

  return;
}
