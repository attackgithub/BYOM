#include <windows.h>
#include "packet.h"
#include <stdlib.h>
#define HEADER_LENGTH 8

struct CobolPacket * cobol_packet_new(uint32_t PacketType)
{
    struct CobolPacket *pkt = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
	sizeof(struct CobolPacket));
    if (pkt != NULL) {
	pkt->hdr.Type   = (uint32_t)PacketType;
	pkt->hdr.Length = (uint32_t)HEADER_LENGTH;
    }
    return pkt;
}
