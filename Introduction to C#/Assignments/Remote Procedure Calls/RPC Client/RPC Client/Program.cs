using System;
using System.Runtime.Remoting.Channels.Tcp;
using System.Runtime.Remoting.Channels;

class Program
{
	static void Main(string[] args)
	{
		// Create Client
		TcpClientChannel channel = new TcpClientChannel();
		ChannelServices.RegisterChannel(channel, false);

		// Get a reference to the player on the server
		string playerURL = "tcp://localhost:" + 4269 + "/" + "Player";
		Player player = (Player)Activator.GetObject(typeof(Player), playerURL);

		while (true)
		{
			Console.Write("Type a message to the server or type 'quit' to exit\n");
			string text = Console.ReadLine();

			if (text == "quit")
				break;

			// RPC: Call function on server
			player.SayHello(text);
		}
	}
}
