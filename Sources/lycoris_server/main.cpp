#include <asio/io_context.hpp>
#include <iostream>

#include "lobby_server.hpp"
#include "lycoris_config.hpp"

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

    lycoris::lycoris_config config;
    lycoris::lobby_server server(io, config, 5000);

    return server.exec_result();
}