#include <iostream>
#include <vector>
#include <string.h>
#include "../include/TCPServer.h"
void ConsoleLog(const std::string& strMsg)
{
    std::cout << "LOG: " << strMsg << std::endl;
}
int main(int argc,char * argv[])
{
    std::cout<<"tcpserver_demo "<<std::endl;
    std::string strPort = "2048";
    CTCPServer server(ConsoleLog,strPort);
    ASocket::Socket client;
    if (server.Listen(client, -1))
    {
        server.Send(client, "Hello");
        char recvBuf[1024] = { 0 };
        std::size_t buffLen = 1024;
        int nRecvLen = server.Receive(client, recvBuf, buffLen, false);
        server.Disconnect(client);
    }
    return 0;
}