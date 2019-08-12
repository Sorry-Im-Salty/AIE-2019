using System;

class Player : MarshalByRefObject
{
	public void SayHello(string text)
	{
			Console.WriteLine("The client says: " + text);
	}
}
