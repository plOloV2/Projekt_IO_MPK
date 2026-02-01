#include <cstdio>
#include <cstdlib>

// Include the cslim headers using the paths from your CMake setup
#include "CSlim/Slim.h"
#include "CSlim/Fixtures.h"
#include "Com/SocketServer.h"
#include "Com/TcpComLink.h"

// 1. Global Slim instance required for the handler
Slim * slim;

// 2. Fixture Registration
// The cslim library looks for a function called 'AddFixtures'.
// This macro defines it for you. You will register your actual classes here later.
extern "C" {
    SLIM_FIXTURES
        // Register your fixtures here later, e.g.:
        // SLIM_FIXTURE(MyCalculator)
    SLIM_END
}

// 3. Connection Handler
// This function is called by SocketServer when FitNesse connects.
// It creates the TCP link and passes it to the Slim engine.
extern "C" int connection_handler(int socket) {
    TcpComLink * comLink = TcpComLink_Create(socket);

    // Pass the connection to Slim. 
    // We pass the standard TcpComLink_send/_recv functions as callbacks.
    int result = Slim_HandleConnection(slim, (void*)comLink, TcpComLink_send, TcpComLink_recv);

    TcpComLink_Destroy(comLink);
    return result;
}

// 4. Main Entry Point
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Initialize the Slim engine
    slim = Slim_Create();

    // Create the socket server
    SocketServer* server = SocketServer_Create();

    // Register the handler defined above
    SocketServer_register_handler(server, connection_handler);

    // Start the server (this blocks until FitNesse finishes testing)
    // argv[1] is the port number passed by FitNesse
    int result = SocketServer_Run(server, argv[1]);

    // Cleanup
    SocketServer_Destroy(server);
    Slim_Destroy(slim);

    return result;
}
