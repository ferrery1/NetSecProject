#include <iostream>
#include "Packet.hh"
#include "Frame.hh"

Frame::Frame(int pNum, int fSize)
  : _num(pNum), _size(fSize) {

}

int Frame::getPNum() {
  return (this->_num);
}

void Frame::parseFrame(char *buf) {
  int i;

  std::cout << "parsing new frame" << std::endl;
    
  this->ethHdr = (struct ethhdr*)buf;
  for (i = 0; _frameProt[i].proto_ID != -1; i++) {
    if (_frameProt[i].proto_ID == ntohs(ethHdr->h_proto))
      break;
  }
  if (_frameProt[i].proto_ID != -1) {
    Packet p = _frameProt[i].type;

    std::cout << "matching proto" << std::endl;
    p.parsePacket((buf + sizeof(struct ethhdr)));
  }
}

Frame::~Frame() {

}

std::map<std::string, NetObj> Frame::getContent() {
  
}
