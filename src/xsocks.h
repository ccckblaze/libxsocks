#include "stdafx.h"

namespace XSOCKS{
    bool SetAuth(LPCTSTR user, LPCTSTR pwd);

    bool Forward(int port);

    bool Reverse(LPCSTR ip, int port);

    bool Redirct(LPCSTR srcIp, int srcPort, LPCSTR destIp, int destPort);

    bool Tunnel(int srcPort, int destPort);
}
