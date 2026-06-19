#include <stdio.h>
#include <stdlib.h>
#include "connection.h"
void run_client(const ConnectionConfig *config) {
    printf("Starting client mode...\n");
    printf("Connecting to server at IP: %s\n", config->ip_address);
}
