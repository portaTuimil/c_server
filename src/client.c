#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "connection.h"
void run_client(const ConnectionConfig *config) {
  int clientSocketD = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in servAddr;

  servAddr.sin_family = AF_INET;
  servAddr.sin_port = htons(config->port); 
  servAddr.sin_addr.s_addr = inet_addr(config->ip_address);

  int connectStatus = connect(clientSocketD, (struct sockaddr*)&servAddr, sizeof(servAddr));

  if (connectStatus == -1) {
      printf("Error...\n");
  } else {
      char strData[255];
      recv(clientSocketD, strData, sizeof(strData), 0);
      printf("Message: %s\n", strData);
  }
  
  return;
}
