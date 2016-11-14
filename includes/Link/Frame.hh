#ifndef FRAME_HH_
# define FRAME_HH_

# include <netinet/in.h>
# include <netinet/ip_icmp.h>
# include <netinet/udp.h>
# include <netinet/tcp.h>
# include <netinet/ip.h>
# include <netinet/if_ether.h>
# include <net/ethernet.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <map>
# include <string>
# include "NetObj.hh"
# include "Packet.hh"
# include "ARP.hh"
# include "ICMP.hh"
# include "IPv6.hh"
# include "IP.hh"
# include "UDP.hh"
# include "TCP.hh"
# define HEADER "HEADER"
# define DATA	"DATA"

class Frame {
private:
  int _num;
  int _size;
  

      
  struct ethhdr	*ethHdr;
  std::map<std::string, NetObj> content;
  std::map<std::string, std::map<std::string, std::string>> contents;
public:
    struct s_proto_obj {
    int		proto_ID;
    Packet	type;
    std::string name;
  };
  

  static const Packet _unknownPacket;
  static const ARPPacket _arp;
  static const UDPPacket _udp;
  static const TCPPacket _tcp;
  static const ICMPPacket _icmp;
  static const IPPacket _ip;
  static const IPV6Packet _ipv6;

    static const struct s_proto_obj frameProt[80] = {    
      { ETH_P_LOOP, _unknownPacket, "" },
      { ETH_P_PUP, _unknownPacket, "" },
      { ETH_P_PUPAT, _unknownPacket, "" },
      { ETH_P_TSN, _unknownPacket, "" },
      { ETH_P_IP, _ip, "" },
      { ETH_P_X25, _unknownPacket, "" },
      { ETH_P_ARP, _arp, "" },
      { ETH_P_IEEEPUP, _unknownPacket, "" },
      { ETH_P_IEEEPUPAT, _unknownPacket, "" },
      { ETH_P_DEC, _unknownPacket, "" },
      { ETH_P_DNA_DL, _unknownPacket, "" },
      { ETH_P_DNA_RC, _unknownPacket, "" },
      { ETH_P_DNA_RT, _unknownPacket, "" },
      { ETH_P_LAT, _unknownPacket, "" },
      { ETH_P_DIAG, _unknownPacket, "" },
      { ETH_P_CUST, _unknownPacket, "" },
      { ETH_P_SCA, _unknownPacket, "" },
      { ETH_P_TEB, _unknownPacket, "" },
      { ETH_P_RARP, _unknownPacket, "" },
      { ETH_P_ATALK, _unknownPacket, "" },
      { ETH_P_AARP, _unknownPacket, "" },
      { ETH_P_8021Q, _unknownPacket, "" },
      { ETH_P_IPX, _unknownPacket, "" },
      { ETH_P_IPV6, _ipv6, "" },
      { ETH_P_PAUSE, _unknownPacket, "" },
      { ETH_P_SLOW, _unknownPacket, "" },
      { ETH_P_WCCP, _unknownPacket, "" },
      { ETH_P_MPLS_UC, _unknownPacket, "" },
      { ETH_P_MPLS_MC, _unknownPacket, "" },
      { ETH_P_ATMMPOA, _unknownPacket, "" },
      { ETH_P_PPP_DISC, _unknownPacket, "" },
      { ETH_P_PPP_SES, _unknownPacket, "" },
      { ETH_P_LINK_CTL, _unknownPacket, "" },
      { ETH_P_ATMFATE, _unknownPacket, "" },
      { ETH_P_PAE, _unknownPacket, "" },
      { ETH_P_AOE, _unknownPacket, "" },
      { ETH_P_8021AD, _unknownPacket, "" },
      { ETH_P_802_EX1, _unknownPacket, "" },
      { ETH_P_TIPC, _unknownPacket, "" },
      { ETH_P_8021AH, _unknownPacket, "" },
      { ETH_P_MVRP, _unknownPacket, "" },
      { ETH_P_1588, _unknownPacket, "" },
      { ETH_P_PRP, _unknownPacket, "" },
      { ETH_P_FCOE, _unknownPacket, "" },
      { ETH_P_TDLS, _unknownPacket, "" },
      { ETH_P_FIP, _unknownPacket, "" },
      { ETH_P_80221, _unknownPacket, "" },
      { ETH_P_LOOPBACK, _unknownPacket, "" },
      { ETH_P_802_3_MIN, _unknownPacket, "" },
      { ETH_P_802_3, _unknownPacket, "" },
      { ETH_P_AX25, _unknownPacket, "" },
      { ETH_P_802_2, _unknownPacket, "" },
      { ETH_P_SNAP, _unknownPacket, "" },
      { ETH_P_DDCMP, _unknownPacket, "" },
      { ETH_P_WAN_PPP, _unknownPacket, "" },
      { ETH_P_PPP_MP, _unknownPacket, "" },
      { ETH_P_LOCALTALK, _unknownPacket, "" },
      { ETH_P_CAN, _unknownPacket, "" },
      { ETH_P_CANFD, _unknownPacket, "" },
      { ETH_P_PPPTALK, _unknownPacket, "" },
      { ETH_P_TR_802_2, _unknownPacket, "" },
      { ETH_P_MOBITEX, _unknownPacket, "" },
      { ETH_P_CONTROL, _unknownPacket, "" },
      { ETH_P_IRDA, _unknownPacket, "" },
      { ETH_P_ECONET, _unknownPacket, "" },
      { ETH_P_HDLC, _unknownPacket, "" },
      { ETH_P_ARCNET, _unknownPacket, "" },
      { ETH_P_DSA, _unknownPacket, "" },
      { ETH_P_TRAILER, _unknownPacket, "" },
      { ETH_P_PHONET, _unknownPacket, "" },
      { ETH_P_IEEE802154, _unknownPacket, "" },
      { ETH_P_CAIF, _unknownPacket, "" },
      { ETH_P_XDSA, _unknownPacket, "" },
      {-1, _unknownPacket, ""}
    };
  static const struct s_proto_obj tab_tcpip[60] = {
    {0, _ip, "IPv4"}, 
    {1, _icmp, "ICMP"}, 
    {2, _unknownPacket, "IGMP"}, 
    {3, _unknownPacket, "GGP"}, 
    {4, _unknownPacket, "IP-ENCAP"}, 
    {5, _unknownPacket, "ST"}, 
    {6, _tcp, "TCP"}, 
    {8, _unknownPacket, "EGP"}, 
    {9, _unknownPacket, "IGP"}, 
    {12, _unknownPacket, "PUP"}, 
    {17, _udp, "UDP"}, 
    {20, _unknownPacket, "HMP"}, 
    {22, _unknownPacket, "XNS-IDP"}, 
    {27, _unknownPacket, "RDP"}, 
    {29, _unknownPacket, "ISO-TP4"}, 
    {33, _unknownPacket, "DCCP"}, 
    {36, _unknownPacket, "XTP"}, 
    {37, _unknownPacket, "DDP"}, 
    {38, _unknownPacket, "IDPR-CMTP"}, 
    {41, _ipv6, "IPv6"}, 
    {43, _unknownPacket, "IPv6-ROUTE"}, 
    {44, _unknownPacket, "IPv6-FRAG"}, 
    {45, _unknownPacket, "IDRP"}, 
    {46, _unknownPacket, "RSVP"}, 
    {47, _unknownPacket, "GRE"}, 
    {50, _unknownPacket, "IPSEC-ESP"}, 
    {51, _unknownPacket, "IPSEC-AH"}, 
    {57, _unknownPacket, "SKIP"}, 
    {58, _unknownPacket, "IPv6-ICMP"}, 
    {59, _unknownPacket, "IPv6-NoNxt"}, 
    {60, _unknownPacket, "IPv6-Opts"}, 
    {73, _unknownPacket, "RSPF"}, 
    {81, _unknownPacket, "VMTP"}, 
    {88, _unknownPacket, "EIGRP"}, 
    {89, _unknownPacket, "OSPFIGP"}, 
    {93, _unknownPacket, "AX.25"}, 
    {94, _unknownPacket, "IPIP"}, 
    {97, _unknownPacket, "ETHERIP"}, 
    {98, _unknownPacket, "ENCAP"}, 
    {99, _unknownPacket, "Anyprivateencryptionscheme"}, 
    {103, _unknownPacket, "PIM"}, 
    {108, _unknownPacket, "IPCOMP"}, 
    {112, _unknownPacket, "VRRP"}, 
    {115, _unknownPacket, "L2TP"}, 
    {124, _unknownPacket, "ISIS"}, 
    {132, _unknownPacket, "SCTP"}, 
    {132, _unknownPacket, "SCTP"}, 
    {133, _unknownPacket, "FC"}, 
    {135, _unknownPacket, "MOBILITY-HEADER"}, 
    {136, _unknownPacket, "UDPLITE"}, 
    {137, _unknownPacket, "MPLS-IN-IP"}, 
    {138, _unknownPacket, "MANET"}, 
    {139, _unknownPacket, "HIP"}, 
    {140, _unknownPacket, "SHIM6"}, 
    {141, _unknownPacket, "WESP"}, 
    {142, _unknownPacket, "ROHC"},
    {-1, _unknownPacket, ""}
  };
    
  Frame(int pNum, int fSize);
  ~Frame();
  void parseFrame(char *buf);
  std::map<std::string, std::map<std::string, std::string>> getContent();
  int getPNum();
  
};

#endif
