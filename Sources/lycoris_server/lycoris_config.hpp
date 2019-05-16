#pragma once

#include <cstdint>
#include <fstream>

namespace lycoris
{
    struct lycoris_config_struct
    {
        std::string server_name, server_motd;
        uint32_t    m_port_number;
    };

    class lycoris_config
    {
        lycoris_config_struct config;
        bool                  config_available = false;

    public:
        lycoris_config();

        bool         available() const;
        void         parse_configuration(std::ifstream& ifs);

        uint32_t     port_number() const;
        std::string& server_name() const;
        std::string& server_motd() const;

    };
}