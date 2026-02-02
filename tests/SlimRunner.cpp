#include <cstdio>
#include <cstdlib>

#include "CSlim/Slim.h"
#include "CSlim/Fixtures.h"
#include "Com/SocketServer.h"
#include "Com/TcpComLink.h"

Slim * slim;

extern "C" {
    SLIM_FIXTURES
        SLIM_FIXTURE(ModyfikujRozklad)
    SLIM_END
}

extern "C" int connection_handler(int socket) {
    TcpComLink * comLink = TcpComLink_Create(socket);
    int result = Slim_HandleConnection(slim, (void*)comLink, TcpComLink_send, TcpComLink_recv);
    TcpComLink_Destroy(comLink);
    return result;
}

int main(int argc, char** argv) {

    if(argc < 2) {
        printf("usage: %s <port>\n", argv[0]);
        return 1;
    }

    printf("Starting SlimRunner on port: %s\n", argv[argc-1]);
    
    slim = Slim_Create();
    SocketServer* server = SocketServer_Create();
    SocketServer_register_handler(server, connection_handler);

    int result = SocketServer_Run(server, argv[argc-1]);

    SocketServer_Destroy(server);
    Slim_Destroy(slim);

    return result;
}
