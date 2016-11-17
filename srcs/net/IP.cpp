#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include "Frame.hh"
#include "IP.hh"
#include "TCP.hh"
#include "UDP.hh"

IPPacket::IPPacket(std::string type)
  : Packet(type) {
}

IPPacket::~IPPacket() {
  
}

/*IPPacket::IPPacket(const IPPacket &p) {
  }*/

void IPPacket::parsePacket(char *buf) {
  std::array<std::string, 4> row;
  std::map<std::string, std::string> parseMap;
  Packet *p;
  int i;
  std::string str;
  int type;
  std::string name;

  std::cout << "BEGINNING OF PACKET" << std::endl;
  this->hdr = (struct iphdr*)buf;
  type = this->hdr->protocol;
  for (i = 0; (type != this->_tabTcpip[i].proto_ID) && (this->_tabTcpip[i].proto_ID != -1); i++);
  name = this->_tabTcpip[i].name;
  
  switch (type) {
  case 6:
    p = new TCPPacket(name);
    break;
  case 17:
    p = new UDPPacket(name);
    break;
  default:
    p = new Packet(name);
  };
  p->parsePacket(buf + sizeof(*(this->hdr)));
  //pkt
  //p = (IPPacket)(pkt);
  //  if (p.getType() == "IP") {
  std::cout << "IP:" << this->hdr->version << std::endl;
  //}
  

  //  str << "IP" << this->hdr->version;
  // parseMap.insert(std::pair<std::string, std::string>("IP version", str));
  //str.clear();
  //  str << "test" << std::endl;
  //str << ((unsigned int)(this->hdr->ihl)) * 4;
  //parseMap.insert("IP Header Length", str);
  //str.clear();
  //str << (unsigned int)this->hdr->tos
  // parseMap.(TOS);
  // parseMap (length);
  // TTL;
  // Protocol;
  // Checksum;
  // Source IP;
  // Dest IP;
  // this->contents.insert;
  std::cout << "END OF PACKET" << std::endl;
}

void IPPacket::dumpHdr() {
      sockaddr_in src, dst;
    memset(&src, 0, sizeof(src));
    src.sin_addr.s_addr = this->hdr->saddr;
    memset(&dst, 0, sizeof(dst));
    dst.sin_addr.s_addr = this->hdr->daddr;
    std::cout << "Src " << inet_ntoa(src.sin_addr) << std::endl;
    std::cout << "Dst " << inet_ntoa(dst.sin_addr) << std::endl;
}

std::array<std::string, 4>	IPPacket::getRow() {


  sockaddr_in src, dst;
  memset(&src, 0, sizeof(src));
  src.sin_addr.s_addr = this->hdr->saddr;
  memset(&dst, 0, sizeof(dst));
  dst.sin_addr.s_addr = this->hdr->daddr;
 
  row[0] = inet_ntoa(src.sin_addr);
  row[1] = inet_ntoa(dst.sin_addr);  
  int i;
  //  IPPacket p;
  //  Proto prot;
  
  //  p = prot.getTCPIPProt(this->hdr->protocol);
  /*if (p.getType() == "IP") {
    str << "IP:" << this->hdr->version;
    }*/

  
  /*  for (i = 0; i < 60; ++i) {
      if (this->_tab_tcpip[i].proto_ID == this->hdr->protocol)
      break;
      }*/
  //  row[2] = this->_tab_tcpip[i].name;
  row[3] = this->size;
  return (row);
}

std::string IPPacket::getType() {
  return ("IP");
}

