using System;
using System.Collections.Generic;
using System.Text;

namespace LycorisServer.Core
{
    class LobbyServer
    {
        public int ExitResult { get; set;}

        public static LobbyServer Begin(string[] args)
        {   
            var config = LobbyServerConfig.Parse(args);
            return new LobbyServer(config);
        }

        protected LobbyServer(LobbyServerConfig args)
        {

        }

        private void AcceptCallback(IAsyncResult iar)
        {

        }
    }
}
