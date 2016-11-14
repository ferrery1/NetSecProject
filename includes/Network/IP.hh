#ifndef IP_HH_
# define IP_HH_

# include <string>
# include <netinet/ip.h>
# include <array>
# include <map>
# include "Packet.hh"

class IPPacket : public Packet {
private:
  struct iphdr	*hdr;
  char *buf[1500];
  
public:
  IPPacket();
  ~IPPacket();
  void parsePacket(char *buf);
  void dumpHdr();
  std::string getType();
  std::array<std::string, 4> getRow();
};

#endif
