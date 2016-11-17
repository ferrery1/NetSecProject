

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <sstream>
#include "ARP.hh"


ARPPacket::ARPPacket(std::string type)
  : Packet(type) {
  opcStrings.insert(std::pair<int, std::string>(ARPOP_REQUEST, REQUEST_STR));
  opcStrings.insert(std::pair<int,std::string>(ARPOP_REPLY, REPLY_STR));
}

ARPPacket::~ARPPacket() {
}

void					ARPPacket::parsePacket(char *buf) {
  std::map<std::string, std::string>	parseMap;
  std::ostringstream			str;
  //memset(this->hdr, 0, sizeof(this->hdr));

  this->hdr = (struct arp_hdr*)buf;
  std::cout << "Type: " << opcStrings[htons(this->hdr->arp_opcode)] << std::endl;
  std::cout << "Sender HW address " << std::hex << + this->hdr->sha[0] << std::dec << ":" <<
    std::hex << + this->hdr->sha[1] << std::dec <<":" << 
    + this->hdr->sha[2] << ":" << 
    + this->hdr->sha[3] << ":" <<
    + this->hdr->sha[4] << ":" << 
    + this->hdr->sha[5]  << std::endl;
  std::cout << "Sender IP :" << + this->hdr->spa[0] << "." <<
    + this->hdr->spa[1] << "." << 
    + this->hdr->spa[2] << "." << 
    + this->hdr->spa[3] << std::endl;
  std::cout << "Target HW address " << this->hdr->tha[0] << ":" <<
    + this->hdr->tha[1] << ":" << 
    + this->hdr->tha[2] << ":" << 
    + this->hdr->tha[3] << ":" <<
    + this->hdr->tha[4] << ":" << 
    + this->hdr->tha[5] << std::endl;
  std::cout << "Target IP : " << + this->hdr->tpa[0] << "." <<
    + this->hdr->tpa[1] << "." << 
    + this->hdr->tpa[2] << "." << 
    + this->hdr->tpa[3] << std::endl;  
}

void ARPPacket::dumpHdr() {

  // struct sockaddr_in  src, dst;
  // memset(&src, 0, sizeof(src));
  // src.sin_addr.s_addr = this->spa;
  // memset(&dst, 0, sizeof(dst));
  // dst.sin_addr.s_addr = this->tpa;
  
  this->hdr->arp_prot;
  
  std::cout << "OPCODE :" << opcStrings[htons(this->hdr->arp_opcode)] << std::endl;


  // int i;
  // printf("Sender MAC: ");

  // for(i=0; i<6;i++)
  //   printf("%02X:", this->hdr->sha[i]);

  // printf("\nSender IP: ");

  // for(i=0; i<4;i++)
  //   printf("%d.", this->hdr->spa[i]);

  // printf("\nTarget MAC: ");

  // for(i=0; i<6;i++)
  //   printf("%02X:", this->hdr->tha[i]);

  // printf("\nTarget IP: ");

  // for(i=0; i<4; i++)
  //   printf("%d.", this->hdr->tpa[i]); 
}
