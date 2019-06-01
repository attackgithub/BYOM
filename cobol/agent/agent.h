#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <stdbool.h>

struct Configuration
{
    char     UserAgent;
    char     Host;
    unsigned short Port;
    char     Path;
};

struct Cobol
{
    struct Configuration *Config;
    struct CobolHttp {
	void *hInternetConfig;
	void *hInternetConnection;
	int (*init)(struct Cobol *c);
	int (*request)(struct Cobol *c, bool Method, char *Data, unsigned long *Length);
    } *HttpTransport;
    struct CobolCommand {
	struct CobolCommand *next;
	char  *CommandName;
	char  *CommandDesc;
	void (*cb)(void *pkt);
    } *Commands;
    int NumberCommands;
};
