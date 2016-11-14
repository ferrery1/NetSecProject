#ifndef ICMP_HH_
# define ICMP_HH_

# include <netinet/ip_icmp.h>
# include "Packet.hh"


class ICMPPacket : public Packet {
  //struct icmphdr *hdr;
};

#endif
