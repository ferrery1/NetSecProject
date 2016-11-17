#ifndef TCP_HH_
# define TCP_HH_

# include <netinet/tcp.h>
# include "Packet.hh"

class		TCPPacket : public Packet {
private:
  tcphdr	*hdr;
  public:
  TCPPacket(std::string type);
  ~TCPPacket();
  void		parsePacket(char *buf);
  //  std::map<std::string, std::map<std::string, std::string>> getContents();
};

#endif
