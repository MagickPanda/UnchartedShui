#ifndef USPLATFORM_H
#define USPLATFORM_H

///TODO: use platform-specific defines
#define US_WIN32

///imports socket related stuff in WIN platform
#ifdef US_WIN32
    #pragma comment(lib,"ws2_32.lib")
    #pragma comment  (lib,"User32.lib")
    #pragma comment  (lib,"Gdi32.lib")
#endif

#endif // USPLATFORM_H
