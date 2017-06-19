#include "stdafx.h"

using namespace std;

#define INIT(name) \
    extern void INIT_FUNCTION_##name(); \
    class INIT_##name \
    { \
    public: \
        INIT_##name() { \
            printf("Initing %s\n", #name); \
            INIT_FUNCTION_##name(); \
        } \
    } INIT_INSTANCE_##name; \
    void INIT_FUNCTION_##name()

INIT(WSADATA){
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    printf("WSADATA Global Inited!");
}

bool XSOCKS::SetAuth(LPCTSTR user, LPCTSTR pwd){
    CSocksMgr::GetInstanceRef().SetAuth(user, pwd);
    return true;
}

bool XSOCKS::Forward(int port){
    return CSocksMgr::GetInstanceRef().Begin(port);
}

bool XSOCKS::Reverse(LPCSTR ip, int port){
    return CSocksMgr::GetInstanceRef().Begin(ip, port);
}

bool XSOCKS::Redirct(LPCSTR srcIp, int srcPort, LPCSTR destIp, int destPort){
    return CSocksMgr::GetInstanceRef().Begin(srcIp, srcPort, destIp, destPort);
}

bool XSOCKS::Tunnel(int srcPort, int destPort){
    return CTunnel::GetInstanceRef().Begin(srcPort, destPort);
}
