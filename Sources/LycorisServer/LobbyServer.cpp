#include "LobbyServer.h"

namespace Lycoris
{

#ifdef _WIN32
	static const char* configPath = "lycoris.conf";
#else
	static const char* configPath = "/etc/lycoris.conf";
#endif

	LobbyServer& LobbyServer::GetServer()
	{
		static std::unique_ptr<LobbyServer> serverInstance(new LobbyServer);

		return *serverInstance;
	}

	LobbyServer::LobbyServer()
	{
		LoadConfiguration();

		while (true)
		{

		}
	}

	// ---------------- Private Methods ----------------

	void LobbyServer::LoadConfiguration()
	{
		this->m_config = std::make_unique<LobbyConfig>();

	}

}