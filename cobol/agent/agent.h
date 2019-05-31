#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

//#include "packet.h"
#include <stdbool.h>
#include <stdint.h>
// Probably gonna end up doing executable patching. Maybe XOR'ing it as well,
// but we'll discuss that when we get there.
struct Configuration
{
    char     UserAgent;			//! User-Agent
    char     Host;			//! Host in unsigned long format or uint32_t (was DWORD). Hrm.
    uint16_t Port;			//! Port in unsigned short or uint16_t (was USHORT);. Hrm
    char     Path;			//! Path to send POST/GET requests
};

struct Cobol
{
    struct Configuration *Config;
    struct CobolHttp {
	void *hInternetConfig;     			//! InternetOpenA() return pointer
	void *hInternetConnection; 			//! InternetConnectA() return pointer.
	int (*init)(struct Cobol *c);			//! Initialiazes handles.
	int (*request)(struct Cobol *c, bool Method, char *Data, uint32_t *Length);
    } *HttpTransport;
    struct CobolCommand {
	struct CobolCommand *next;			//! Next structure pointer.
	char  *CommandName;				//! Command Name! Name of the command string.
	char  *CommandDesc;				//! Description in help text.
	void (*cb)(void *pkt);   		//! Cobol Packet! Probably gonna do a basic LTV (Length-Type-Value). (-NOT_IMPLEMENTED-).
    } *Commands;
    int NumberCommands;
};
