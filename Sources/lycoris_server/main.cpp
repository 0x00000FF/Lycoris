#include <asio/io_context.hpp>
#include <iostream>

#include "lycoris_server.hpp"

int main()
{
    std::puts("Lycoris Server for PoFV NetPlay\n"
              "By P.Knowledge(0x00000FF), Licensed under MIT\n"
              "==================================================");

    asio::io_context io;
    try   { io.run(); }
    catch (std::exception& e)
    {
        std::fprintf(stderr, "Failed to initialize IO Context for server\n=>%s", e.what());
        return -1;
    }

    lycoris::lobby_server server(io, 5000);
    return server.exec_result();
}