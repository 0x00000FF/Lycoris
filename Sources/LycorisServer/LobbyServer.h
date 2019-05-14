#pragma once

#include <asio.hpp>

#include <vector>
#include <memory>

namespace Lycoris
{
	struct User
	{
		asio::ip::address address;
		std::string       nickname;
		unsigned int      latency;
	};

	struct LobbyConfig
	{

	};

	class LobbyServer
	{
	public:
		static LobbyServer& GetServer();

		LobbyServer(const LobbyServer&) = delete;
		LobbyServer(LobbyServer&&) = delete;
		
	protected:
		LobbyServer();

	private:
		void LoadConfiguration();

		std::vector<User>                    m_connectedUsers;
		std::unique_ptr<LobbyConfig>         m_config;
	};

}