#ifndef SERVER_H
#define SERVER_H

#include "global.h"

class server{
    private:

        int server_port;
        int server_sockfd;
        string server_ip;
        static vector<bool> sock_arr;
        static unordered_map<string,int> name_sock_map;//名字和套接字描述符
        static pthread_mutex_t name_sock_mutx;//互斥锁，锁住需要修改name_sock_map的临界区
		static unordered_map<int,set<int>> group_map;
		static pthread_mutex_t group_mutx;
    public:
        server(int port,string ip);
        ~server();
        void run();
        static void RecvMsg(int conn);
        static void HandleRequest(int conn,string str,tuple<bool,string,string,int,int> &info);
};
#endif