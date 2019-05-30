#include <stdint.h>

struct CobolPacketHdr
{
     uint32_t Length;
     uint32_t Type;
} __attribute__((packed));

struct CobolPacket
{
     struct CobolPacketHdr hdr;
     char *buf[];
} __attribute__((packed));
