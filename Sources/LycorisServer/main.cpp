#include <cstdio>
#include "LobbyServer.h"
using namespace std;

int main(int, char**)
{
	puts("Lycoris Server\n"
		 "A third party server for PoFV network play\n"
		 "===============================================");

	Lycoris::LobbyServer::GetServer();

	return 0;
}