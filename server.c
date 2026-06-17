#include <stdio.h>
#include <stdlib.h>
#include "connection.h" 

void run_server(const ConnectionConfig *config) {
    printf("Starting server mode...\n");
    printf("Binding to IP: %s\n", config->ip_address);
    printf("Server running successfully (Simulated).\n");
}
