#pragma once

#include <asio/ip/tcp.hpp>
#include <vector>

namespace lycoris
{
	using asio::io_context;
	using asio::ip::tcp;
	using tcp_acceptor = asio::ip::tcp::acceptor;
	using tcp_endpoint = asio::ip::tcp::endpoint;
	using tcp_socket   = asio::ip::tcp::socket;

	class lobby_server
	{
		tcp_acceptor m_acceptor;
		uint16_t     m_port;
		int32_t      m_exec_result = 0;

	public:
		lobby_server(io_context& io, const uint16_t port) : m_acceptor(io, tcp_endpoint(tcp::v4(), port)) 
		{
			m_port = port;
			this->initialize();
		}

		lobby_server(const lobby_server&) = delete;
		lobby_server(lobby_server&&)      = delete;

		int32_t  exec_result();

	private:
		void     initialize();
		bool     load_configuration();
		void     parse_configuration(std::ifstream& ifs);

		void     begin_accept();
		void     handle_accept();
	};
}
