#include <stdio.h>
#include<stdlib.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
  enum {SERVER_MODE, CLIENT_MODE} mode = CLIENT_MODE;
  const char * ip_address= "127.0.0.1";

  for(int arg = 1; arg<argc; arg++){
    if (argv[arg][0] != '-') continue;
    switch (argv[arg][1]) {
      case 's': mode = SERVER_MODE; break;
      case 'c': mode = CLIENT_MODE; break;
      case 'a': 
        if (argv[arg + 1]) {
          ip_address = argv[arg + 1]; 
          arg++; // Crucial: skip the IP string so the loop doesn't read it next
        } else {
          fprintf(stderr, "Error: -a requires an IP address.\n");
          exit(EXIT_FAILURE);
        }
        break;      
      default: 
        fprintf(stderr, "Usage: %s [-ilw] [file...]\n", argv[0]);
          exit(EXIT_FAILURE);
    }
  }
  return 0;
}
