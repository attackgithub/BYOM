#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// Probably gonna end up doing executable patching. Maybe XOR'ing it as well,
// but we'll discuss that when we get there.
typedef struct _CobolConfiguration
{
    CHAR UserAgent;		//! User-Agent
    CHAR Host;			//! Host in unsigned long format or uint32_t (was DWORD). Hrm.
    WORD Port;			//! Port in unsigned short or uint16_t (was USHORT);. Hrm
    CHAR Path;			//! Path to send POST/GET requests
} Configuration;

struct Cobol
{
    struct Configuration *Config;
    struct _CobolHttp {
	HANDLE hInternetConfig;     		//! InternetOpenA() return pointer
	HANDLE hInternetConnection; 		//! InternetConnectA() return pointer.
	INT   (*init)(struct Cobol *c);		//! Initialiazes handles.
	PVOID (*request)(struct Cobol *c);	//! connect()-esq runtime callback. Likely will change, just an idea to pull straght from runtime (-NOT_IMPLEMENTED-).
    } *HttpTransport;
    struct _CobolCommand {
	struct _CobolCommand *next;		//! Next structure pointer.
	PCHAR CommandName;			//! Command Name! Name of the command string.
	void (*cb)(VOID);   			//! Cobol Packet! Probably gonna do a basic LTV (Length-Type-Value). (-NOT_IMPLEMENTED-).
    } *Commands;
    INT NumberCommands;
};
