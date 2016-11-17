#include <iostream>
#include "Packet.hh"

Packet::Packet(std::string type)
  : _type(type) {
}

Packet::~Packet() {
}

void Packet::parsePacket(char *buf) {
  std::cout << "Cannot parse packet from type " << this->_type << std::endl;
}

std::array<std::string, 4>  Packet::getRow() {
}

std::string Packet::getType() {
  return (this->_type);
}

std::map<std::string, std::map<std::string, std::string>> Packet::getContents() {
}
