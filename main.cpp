#include "./include/ClientSocket.hpp"
#include "./include/ConfigMain.hpp"
#include "./include/KqueueLoop.hpp"
#include "./include/WebServer.hpp"
#include <csignal>
#include <cstdlib>
#include <iostream>

std::map<int, IServer *> serverMap;

void                     signalHandler(int signal)
{
    std::cout << "\nsignal " << signal << " occurs. quit server.\n";

    std::map<int, IServer *>::iterator iter = serverMap.begin();
    for (; iter != serverMap.end(); iter++)
        delete iter->second;

    exit(signal);
}

int main(int argc, char *argv[], char *envp[])
{
    if (argc > 2)
        exit(1); // too many arguments error

    ConfigMain                    configMain(argv[1]);

    std::vector<Config>           confVec = configMain.getServerConfigs();
    std::vector<Config>::iterator iter    = confVec.begin();

    signal(SIGINT, signalHandler);  // Ctrl+C 시그널 핸들러 등록
    signal(SIGQUIT, signalHandler); // Ctrl+\ 시그널 핸들러 등록

    for (; iter != confVec.end(); iter++)
    {
        WebServer *temp                    = new WebServer(*iter);
        serverMap[temp->getListenSocket()] = temp;
    }

    KqueueLoop eventLoop(serverMap, envp);
    eventLoop.initServerSocket();
    eventLoop.run();
}