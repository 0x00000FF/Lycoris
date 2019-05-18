using System;
using System.Runtime.InteropServices;

namespace LycorisServer.Core
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine($"Lycoris Netplay Server\n{RuntimeInformation.OSDescription}\n====");
            LobbyServer.Begin(args);
        }
    }
}
