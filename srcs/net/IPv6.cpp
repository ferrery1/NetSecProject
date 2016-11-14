#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include "IPv6.hh"

IPV6Packet::IPV6Packet() {
}

IPV6Packet::~IPV6Packet() {
}

void IPV6Packet::parsePacket(char *buf) {
  //  memset(this->hdr, 0, sizeof(this->hdr));
  this->hdr = (struct ipv6hdr*)buf;
}

void IPV6Packet::dumpHdr() {
  std::cout << "IPV6, in progress" << std::endl;
  //   sockaddr_in src, dst;
  // memset(&src, 0, sizeof(src));
  // src.sin_addr.s_addr = this->hdr->saddr;
  // memset(&dst, 0, sizeof(dst));
  // dst.sin_addr.s_addr = this->hdr->daddr;
  // std::cout << "Src " << inet_ntoa(src.sin_addr) << std::endl;
  // std::cout << "Dst " << inet_ntoa(dst.sin_addr) << std::endl;
}
