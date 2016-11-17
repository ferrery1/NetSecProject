#include <iostream>
# include <netinet/if_ether.h>
//# include "Packet.hh"
# include "ARP.hh"
# include "UDP.hh"
# include "IP.hh"
# include "ICMP.hh"
# include "TCP.hh"
# include "IPv6.hh"
//#include "Packet.hh"
#include "Frame.hh"

Frame::Frame(int pNum, int fSize)
  : _num(pNum), _size(fSize) {

}

int Frame::getPNum() {
  return (this->_num);
}

void		Frame::parseFrame(char *buf) {
  int		i;
  Packet	*p;
  int		type;
  std::string	name;


  std::cout << "BEGINNING OF FRAME" << std::endl;
  this->ethHdr = (struct ethhdr*)buf;
  type = ntohs(ethHdr->h_proto);
  for (i = 0; (type != this->_frameProt[i].proto_ID) && (this->_frameProt[i].proto_ID != -1); i++);
  name = this->_frameProt[i].name;

  switch (type) {
  case ETH_P_IP:
    p = new IPPacket(name);
    break;
  case ETH_P_ARP:
    p = new ARPPacket(name);
    break;
  case ETH_P_IPV6:
    p = new IPV6Packet(name);
    break;
  default:
    p = new Packet(name);
    break;
  };
  p->parsePacket((buf + sizeof(struct ethhdr)));

  //  this->contents.insert(p->getContents());
  std::cout << "END OF FRAME" << std::endl;
}

Frame::~Frame() {

}

std::map<std::string, std::map<std::string, std::string>> Frame::getContents() {
  return (this->contents);
}
// std::map<std::string, NetObj> Frame::getContent() {
  
// }
