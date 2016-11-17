#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include "IPv6.hh"

IPV6Packet::IPV6Packet(std::string type)
  : Packet(type) {
}

IPV6Packet::~IPV6Packet() {
}

void IPV6Packet::parsePacket(char *buf) {
  this->hdr = (struct ipv6hdr*)buf;
}
