#ifndef PACKET_HH_
# define PACKET_HH_

# include <array>
# include <string>
# include "NetObj.hh"
//# include "Proto.hh"


class Packet : public NetObj {
protected:
  void	*hdr;
  int	size;
  //  Proto *prot;
  /*  Packet *_unknownPacket;
  UDPPacket *_udp;
  TCPPacket *_tcp;
  ICMPPacket *_icmp;
  IPPacket *_ip;
  IPV6Packet *_ipv6;  */

public:
  Packet();
  ~Packet();
  virtual void parsePacket(char *buf);
  //  virtual void dumpHdr();
  virtual std::array<std::string, 4> getRow();
  void setNum(int num);
  virtual std::string getType();
};

#endif
