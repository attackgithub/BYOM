#include "agent.h"
#include <wininet.h>

INT wininet_init(struct Cobol *c)
{
    HANDLE hInternet = InternetOpenA(&c->Config->UserAgent,
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

VOID WininetConfigureCallback(struct Cobol *c)
{
    c->HttpTransport->init = (void *)wininet_init;
    return;
}
