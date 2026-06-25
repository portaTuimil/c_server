#include <stdio.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include "connection.h"

int main(int argc, char *argv[]){
  ConnectionConfig config ={
    .mode = CLIENT_MODE,
    .ip_address = "127.0.0.1",
    .port = 9001
  };

  for(int arg = 1; arg<argc; arg++){
    if (argv[arg][0] != '-') continue;
    switch (argv[arg][1]) {
      case 's': config.mode = SERVER_MODE; break;
      case 'c': config.mode = CLIENT_MODE; break;
      case 'a': 
        if (argv[arg + 1]) {
          config.ip_address = argv[arg + 1]; 
          arg++; 
        } else {
          fprintf(stderr, "Error: -a requires an IP address.\n");
          exit(EXIT_FAILURE);
        }
        break;      
      default: 
        fprintf(stderr, "Usage: %s [-s] [-c] [-a ip_address]\n", argv[0]);
          exit(EXIT_FAILURE);
    }  
  }

  if (config.mode == SERVER_MODE){
    run_server(&config);
  } else{
    run_client(&config);
  }

  return 0;
}
