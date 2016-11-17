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
// # include "Packet.hh"
// # include "ARP.hh"
// # include "ICMP.hh"
// # include "IPv6.hh"
// # include "IP.hh"
// # include "UDP.hh"
// # include "TCP.hh"
# define HEADER "HEADER"
# define DATA	"DATA"

class Frame {
private:
  int _num;
  int _size;
  struct ethhdr	*ethHdr;
  std::map<std::string, NetObj> content;
  std::map<std::string, std::map<std::string, std::string>> contents;

  struct s_proto_obj {
    int		proto_ID;
    std::string name;
  };
 struct s_proto_obj _frameProt[74] =
    {
      { ETH_P_LOOP, "" },
      { ETH_P_PUP, "" },
      { ETH_P_PUPAT, "" },
      { ETH_P_TSN, "" },
      { ETH_P_IP, "IP" },
      { ETH_P_X25, "" },
      { ETH_P_ARP, "ARP" },
      { ETH_P_IEEEPUP, "" },
      { ETH_P_IEEEPUPAT, "" },
      { ETH_P_DEC, "" },
      { ETH_P_DNA_DL, "" },
      { ETH_P_DNA_RC, "" },
      { ETH_P_DNA_RT, "" },
      { ETH_P_LAT, "" },
      { ETH_P_DIAG, "" },
      { ETH_P_CUST, "" },
      { ETH_P_SCA, "SCA" },
      { ETH_P_TEB, "TEB" },
      { ETH_P_RARP, "RARP" },
      { ETH_P_ATALK, "ATAML" },
      { ETH_P_AARP, "AARP" },
      { ETH_P_8021Q, "8021q" },
      { ETH_P_IPX, "IPX" },
      { ETH_P_IPV6, "IPv6" },
      { ETH_P_PAUSE, "PAUSE" },
      { ETH_P_SLOW, "SLOW" },
      { ETH_P_WCCP, "WCCP" },
      { ETH_P_MPLS_UC, "MPLS_UC" },
      { ETH_P_MPLS_MC, "MPLS_MC" },
      { ETH_P_ATMMPOA, "ATMMPOA" },
      { ETH_P_PPP_DISC, "PPP_DISC" },
      { ETH_P_PPP_SES, "PPP_SES" },
      { ETH_P_LINK_CTL, "LINK_CTL" },
      { ETH_P_ATMFATE, "ATMFATE" },
      { ETH_P_PAE, "PAE" },
      { ETH_P_AOE, "AOE" },
      { ETH_P_8021AD, "8021ad" },
      { ETH_P_802_EX1, "802EX1" },
      { ETH_P_TIPC, "TIPC" },
      { ETH_P_8021AH, "8021ah" },
      { ETH_P_MVRP, "MVRP" },
      { ETH_P_1588, "1588" },
      { ETH_P_PRP, "PRP" },
      { ETH_P_FCOE, "FCOE" },
      { ETH_P_TDLS, "TDLS" },
      { ETH_P_FIP, "FIP" },
      { ETH_P_80221, "80221" },
      { ETH_P_LOOPBACK, "" },
      { ETH_P_802_3_MIN, "" },
      { ETH_P_802_3, "" },
      { ETH_P_AX25, "" },
      { ETH_P_802_2, "" },
      { ETH_P_SNAP, "" },
      { ETH_P_DDCMP, "" },
      { ETH_P_WAN_PPP, "" },
      { ETH_P_PPP_MP, "" },
      { ETH_P_LOCALTALK, "" },
      { ETH_P_CAN, "" },
      { ETH_P_CANFD, "" },
      { ETH_P_PPPTALK, "" },
      { ETH_P_TR_802_2, "" },
      { ETH_P_MOBITEX, "" },
      { ETH_P_CONTROL, "" },
      { ETH_P_IRDA, "" },
      { ETH_P_ECONET, "" },
      { ETH_P_HDLC, "" },
      { ETH_P_ARCNET, "" },
      { ETH_P_DSA, "" },
      { ETH_P_TRAILER, "" },
      { ETH_P_PHONET, "" },
      { ETH_P_IEEE802154, "" },
      { ETH_P_CAIF, "" },
      { ETH_P_XDSA, "" },
      {-1, "NONE"}
    };
  
public:    
  Frame(int pNum, int fSize);
  ~Frame();
  void parseFrame(char *buf);
  std::map<std::string, std::map<std::string, std::string>> getContents();
  int getPNum();
  
};

#endif
