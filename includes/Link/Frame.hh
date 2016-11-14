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
# include "Proto.hh"
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
  Proto *prot;
  std::map<std::string, NetObj> content;
  std::map<std::string, std::map<std::string, std::string>> contents;
  
public:    
  Frame(int pNum, int fSize);
  ~Frame();
  void parseFrame(char *buf);
  std::map<std::string, std::map<std::string, std::string>> getContent();
  int getPNum();
  
};

#endif
