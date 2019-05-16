#include "lycoris_config.hpp"

#include <string>

namespace lycoris 
{
    static const char* config_path =
#if _WIN32
        "lycoris.conf";
#else
        "/etc/lycoris.conf";
#endif

    lycoris_config::lycoris_config()
    {
        std::ifstream config_file(config_path, std::ios::in);
        if (config_file.fail())
        {
            std::printf("Failed to read %s, server cannot be initialized\n", config_path);
        } 
        else
        {
            parse_configuration(config_file);
            config_available = true; // This should be changed in parse_configuration
        }
    }

    bool lycoris_config::available() const
    {
        return config_available;
    }

    void lycoris_config::parse_configuration(std::ifstream & ifs)
    {
        std::string line;
        while (std::getline(ifs, line).good())
        {

        }

    }
}