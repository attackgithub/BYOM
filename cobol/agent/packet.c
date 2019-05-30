#include "packet.h"
#define HEADER_LENGTH 8

struct cobol_packet_new(uint32_t PacketType)
{
#ifndef _WIN64 || __WIN32
    struct CobolPacket *pkt = calloc(1, sizeof(CobolPacket));
#else
    struct CobolPacket *pkt = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
	sizeof(CobolPacket));
#endif
    if (pkt != NULL) {
	pkt->hdr.Type   = htonl(type);
	pkt->hdr.Length = htonl(HEADER_LENGTH);
    }
    return pkt;
}
