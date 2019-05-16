#pragma once

#include <asio/ip/tcp.hpp>
#include <vector>

#include "lycoris_config.hpp"

namespace lycoris
{
    using asio::io_context;
    using asio::ip::tcp;
    using tcp_acceptor = asio::ip::tcp::acceptor;
    using tcp_endpoint = asio::ip::tcp::endpoint;
    using tcp_socket   = asio::ip::tcp::socket;

    class lobby_server
    {
        io_context*  m_io_context;
        tcp_acceptor m_acceptor;
        
        std::string  m_server_name, m_server_motd;
        uint16_t     m_port;
        int32_t      m_exec_result = 0;

    public:
        lobby_server(io_context& io, const lycoris_config& config, const uint16_t port) : m_acceptor(io, tcp_endpoint(tcp::v4(), port))
        {
            m_io_context = &io;

            if (config.available()) 
            {
                m_server_name = config.server_name();
                m_server_motd = config.server_motd();
                m_port = config.port_number();
            }
            else
            {
                std::fprintf(stderr, "Configuration is not available. Fatal Error.\n");
                this->m_exec_result = -2;
            }

            this->begin_accept();
        }

        lobby_server(const lobby_server&) = delete;
        lobby_server(lobby_server&&)      = delete;

        int32_t  exec_result();

    private:
        void     initialize();

        void     begin_accept();
        void     handle_accept(tcp_socket* socket, const asio::error_code&);
    };
}
