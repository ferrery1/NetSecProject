//#include <cstdint>
//#include <cstring>
#include <string>
#include <iostream>
#include <errno.h>
#include <netdb.h>

#include <linux/if_packet.h>
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/tcp.h>   //Provides declarations for tcp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <net/if.h>    //Provides declarations for ip header
#include <netinet/if_ether.h>  //For ETH_P_ALL
#include <net/ethernet.h>  //For ether_header
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "RawSocket.hh"


RawSocket::RawSocket() {
  this->nb_packet = 0;
  this->rsocket = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
  if (this->rsocket < 0) {
    perror("[RawSocket][Socket instanciation]:");
    exit(EXIT_FAILURE);
  }
  
  /*  struct ifreq ifr;
  memset(&ifr, 0, sizeof(ifr));
  strncpy((char*)ifr.ifr_name, "wlo1", IFNAMSIZ);
  if (ioctl(this->rsocket, SIOCGIFFLAGS, &ifr) == -1)  {
    perror("[RawSocket][Retrieving flags]:");
    exit(EXIT_FAILURE);
  }
  ifr.ifr_flags |= IFF_PROMISC;
  if (ioctl(this->rsocket, SIOCSIFFLAGS, &ifr) == -1)  {
    perror("[RawSocket][Setting flags]:");
    exit(EXIT_FAILURE);
    }*/
  
  // struct packet_mreq mr;
  // memset(&mr, 0, sizeof(mr));
  // mr.mr_ifindex = ifr.ifr_ifindex;
  // mr.mr_type = PACKET_MR_PROMISC;
  // if(setsockopt(this->rsocket, SOL_PACKET, PACKET_ADD_MEMBERSHIP, &mr, sizeof(mr)) < 0) {
  //   perror("[RawSocket][Setting promisc. mode]:");
  //   exit(EXIT_FAILURE);
  // }
    
}

RawSocket::~RawSocket() {
  close(this->rsocket);
  std::cout << "Done, closing socket" << std::endl;
}

void		RawSocket::AnalyzePacket(char *buf, int data_size) {
  Frame f(++nb_packet, data_size);

  f.parseFrame(buf);
  
  
  //if (i < 80 && tab[i].type != NULL) {
  //  tab[i].type->setSize(data_size);
  //tab[i].type->setHdr((buf + sizeof(struct ethhdr)));

  //  f.push(HEADER, do not forget ethhdr);
  //f.pushContent(HEADER, *tab[i].type);
  //f.setSize(data_size);
  

  // classe fille parse completement puis retourne la frame correctement créée
  
  // tab[i].type->dumpHdr();
  // tab[i].type->parse();
  //this->frames.
  //}
    
  /*  if (ntohs(ethh->h_proto) == ETH_P_ARP)
      std::cout << "ARP"  << std::endl;
      else if (ntohs(ethh->h_proto) == ETH_P_IP) {
      std::cout << "IP"  << std::endl;
    
      //    iph = (struct iphdr*)(buf + sizeof(struct ethhdr));
      sockaddr_in src, dst;
      memset(&src, 0, sizeof(src));
      src.sin_addr.s_addr = iph->saddr;
      memset(&dst, 0, sizeof(dst));
      dst.sin_addr.s_addr = iph->daddr;
      std::cout << "Src " << inet_ntoa(src.sin_addr) << std::endl;
      std::cout << "Dst " << inet_ntoa(dst.sin_addr) << std::endl;
      }
      else
      std::cout << "Unknown : " << ntohs(ethh->h_proto) << std::endl;*/
  std::cout << "################" << std::endl;
}

void			RawSocket::ReadSocket() {
  int			saddr_size;
  int			data_size;
  struct sockaddr	saddr;
  char			buf[ETH_FRAME_LEN];
  
  while (1) {
    saddr_size = sizeof(saddr);
    data_size = recvfrom(this->rsocket, buf, ETH_FRAME_LEN, 0, &saddr, (socklen_t*)&saddr_size);
    if (data_size < 0) {
      perror("[Recvfrom]:");
      exit(EXIT_FAILURE);
    }
    this->AnalyzePacket(buf, data_size);
  }
}
