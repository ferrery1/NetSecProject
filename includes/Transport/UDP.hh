#ifndef UDP_HH_
# define UDP_HH_

# include <netinet/udp.h>
# include "Packet.hh"

class UDPPacket : public Packet {
private:
  udphdr	*hdr;
  public:
  UDPPacket(std::string name);
  ~UDPPacket();
  void		parsePacket(char *buf);
  std::map<std::string, std::map<std::string, std::string>> getContents();
};

#endif
