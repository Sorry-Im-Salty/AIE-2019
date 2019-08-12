using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels.Tcp;
using System.Runtime.Remoting.Channels;

class Program
{
	static void Main(string[] args)
	{
		// Create Server
		TcpServerChannel channel = new TcpServerChannel(4269);
		ChannelServices.RegisterChannel(channel, false);

		// Register Player
		RemotingConfiguration.RegisterWellKnownServiceType(typeof(Player), "Player", WellKnownObjectMode.SingleCall);

		Console.WriteLine("Listening to requests. Press enter to exit...");
		Console.ReadLine();

	}
}
