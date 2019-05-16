#include "lobby_server.hpp"

#include <fstream>
#include <sstream>
#include <string>

namespace lycoris
{
    int32_t lobby_server::exec_result()
    {
        return m_exec_result;
    }

    // ----------------------------------------------------------------

    void lobby_server::begin_accept()
    {
        
    }

    // tcp_socket* parameter will be replaced with shared_ptr<lycoris::tcp_connection>
    void lobby_server::handle_accept(tcp_socket* socket, const asio::error_code&)
    {

    }
}