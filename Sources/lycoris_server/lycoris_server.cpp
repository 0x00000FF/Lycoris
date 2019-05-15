#include "lycoris_server.hpp"

#include <fstream>
#include <sstream>
#include <string>

namespace lycoris
{
    static const char* config_path =
#if _WIN32
        "lycoris.conf";
#else
        "/etc/lycoris.conf";
#endif

    int32_t lobby_server::exec_result()
    {
        return m_exec_result;
    }

    // ----------------------------------------------------------------

    void lobby_server::initialize()
    {
        if (!load_configuration()) return;

        begin_accept();
    }

    bool lobby_server::load_configuration()
    {
        std::ifstream config_file(config_path, std::ios::in);
        if (config_file.fail())
        {
            std::printf("Failed to read %s, server cannot be initialized\n", config_path);
            this->m_exec_result = -1;
        }

        parse_configuration(config_file);
        return (this->m_exec_result == 0);
    }

    void lobby_server::parse_configuration(std::ifstream& ifs)
    {
        std::string line;
        while (std::getline(ifs, line).good())
        {
            
        }
        
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