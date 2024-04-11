#include <iostream>
#include <string.h>
#include "../include/TCPClient.h"

void ConsoleLog(const std::string& strMsg)
{
    std::cout << "LOG: " << strMsg << std::endl;
}
int main(int argc,char * argv[])
{
    std::cout<<"tcpclient_demo "<<std::endl;
    CTCPClient client(ConsoleLog);
    if (client.Connect("127.0.0.1", "2048"))
    {
        client.Send("Hello");
        char buff[1024] = { 0 };
        client.Receive(buff, 1024, false);
        std::cout << "Read: " << buff << std::endl;
        client.Disconnect();
    }
    return 0;
}