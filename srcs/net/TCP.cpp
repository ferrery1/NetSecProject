#include <map>
#include <string>
#include <iostream>
#include <arpa/inet.h>
#include <sstream>
#include "TCP.hh"

TCPPacket::TCPPacket(std::string type)
  : Packet(type) {
}

TCPPacket::~TCPPacket() {
}

void					TCPPacket::parsePacket(char *buf) {
  std::map<std::string, std::string>	parseMap;
  std::ostringstream			str;

  std::cout << "TCP Packet" << std::endl;
  this->hdr = (struct tcphdr*)buf;
  str << ntohs(this->hdr->source);
  parseMap.insert(std::pair<std::string, std::string>("Source port", str.str()));
  str.clear();
  str << ntohs(this->hdr->dest);
  parseMap.insert(std::pair<std::string, std::string>("Dest port", str.str()));
  this->contents.insert(std::pair<std::string, std::map<std::string, std::string>>("HEADER", parseMap));
}

/*std::map<std::string, std::map<std::string, std::string>> TCPPacket::getContents() {
  return (this->contents);
  }*/

