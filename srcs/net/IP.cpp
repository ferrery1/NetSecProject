#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include "Frame.hh"
#include "IP.hh"

IPPacket::~IPPacket() {
}

IPPacket::IPPacket() {
  
}

void IPPacket::parsePacket(char *buf) {
  std::cout << "LOL" << std::endl;
  std::map<std::string, std::string> parseMap;
  int i;
  
  this->hdr = (struct iphdr*)buf;
  for (i = 0; i < 60; ++i) {
    if (Frame::tab_tcpip[i].proto_ID == this->hdr->protocol)
      break;
  }
  //  IPPacket *tmp = (IPPacket)(this->_tab_tcpip[i].type)
  //  IPPacket p = *(this->_tab_tcpip[i]).type;
  //printf("p: %p, ptr: %p\n", p, *(this->_tab_tcpip[i].type));
  std::string str;

  //  str << "IP" << this->hdr->version;
  parseMap.insert(std::pair<std::string, std::string>("IP version", str));
  str.clear();
  //  str << "test" << std::endl;
  //str << ((unsigned int)(this->hdr->ihl)) * 4;
  //parseMap.insert("IP Header Length", str);
  str.clear();
  //str << (unsigned int)this->hdr->tos
  // parseMap.(TOS);
  // parseMap (length);
  // TTL;
  // Protocol;
  // Checksum;
  // Source IP;
  // Dest IP;
  // this->contents.insert;
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
  std::array<std::string, 4> row;
  sockaddr_in src, dst;
  memset(&src, 0, sizeof(src));
  src.sin_addr.s_addr = this->hdr->saddr;
  memset(&dst, 0, sizeof(dst));
  dst.sin_addr.s_addr = this->hdr->daddr;
 
  row[0] = inet_ntoa(src.sin_addr);
  row[1] = inet_ntoa(dst.sin_addr);  
  int i;

  for (i = 0; i < 60; ++i) {
    if (this->_tab_tcpip[i].proto_ID == this->hdr->protocol)
      break;
  }
  row[2] = this->_tab_tcpip[i].name;
  row[3] = this->size;
  return (row);
}

std::string IPPacket::getType() {
  return ("IP");
}

