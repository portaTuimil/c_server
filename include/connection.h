#ifndef CONNECTION_H
#define CONNECTION_H

typedef struct {
    enum {SERVER_MODE, CLIENT_MODE} mode;
    const char * ip_address; 
    int port;
} ConnectionConfig;

void run_server(const ConnectionConfig *config);
void run_client(const ConnectionConfig *config);

#endif
