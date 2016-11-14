#ifndef ARP_HH_
# define ARP_HH_


# include <netinet/if_ether.h>  //For ETH_P_ALL

# include <string>
# include <map>
# include "Packet.hh"

# define REQUEST_STR	"ARP request"
# define REPLY_STR	"ARP reply"

class ARPPacket : public Packet {
private:
  //  struct arphdr *hdr;
  struct __attribute__((packed)) arp_hdr {
    uint16_t arp_hdw;
    uint16_t arp_prot;
    u_char arp_hdwl;
    u_char arp_protl;
    uint16_t arp_opcode;
    u_char sha[6];      /* Sender hardware address */
    u_char spa[4];      /* Sender IP address       */
    u_char tha[6];      /* Target hardware address */
    u_char tpa[4];      /* Target IP address       */
  };
  struct arp_hdr *hdr;
  std::map<int, std::string> opcStrings;
  
public:
  ARPPacket();
  ~ARPPacket();
  void parsePacket(char *buf);
  void dumpHdr();
  
};

#endif
