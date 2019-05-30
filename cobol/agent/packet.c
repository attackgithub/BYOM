#include "packet.h"
#include <stdlib.h>
#define HEADER_LENGTH 8

struct CobolPacket * cobol_packet_new(uint32_t PacketType)
{
#if _WIN64 || _WIN32
    struct CobolPacket *pkt = calloc(1, sizeof(struct CobolPacket));
#else
    struct CobolPacket *pkt = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
	sizeof(CobolPacket));
#endif
    if (pkt != NULL) {
	pkt->hdr.Type   = (uint32_t)PacketType;
	pkt->hdr.Length = (uint32_t)8;
    }
    return pkt;
}
