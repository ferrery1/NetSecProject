#ifndef IPV6_HH_
# define IPV6_HH_

# include "Packet.hh"

class IPV6Packet : public Packet {
private:
  struct ipv6hdr	*hdr;

public:
  IPV6Packet();
  ~IPV6Packet();
  void parsePacket(char *buf);
  void dumpHdr();
};

#endif
