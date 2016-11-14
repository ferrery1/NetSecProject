#ifndef RAWSOCKET_HH_
# define RAWSOCKET_HH_

# include <string>
# include <netinet/in.h>
# include <errno.h>
# include <netdb.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <netinet/ip_icmp.h>
# include <netinet/udp.h>   
# include <netinet/tcp.h>   
# include <netinet/ip.h>    
# include <netinet/if_ether.h>
# include <net/ethernet.h>  
# include <sys/socket.h>
# include <arpa/inet.h>
# include <sys/ioctl.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>
# include <list>
// # include "ARP.hh"
// # include "IP.hh"
// # include "IPv6.hh"
// # include "ICMP.hh"
# include "Frame.hh"

class RawSocket {

 private:
  int	rsocket;
  int	nb_packet;

  std::list<Frame *> frames;
  
 public:
  RawSocket();
  void ReadSocket();
  ~RawSocket();
  void AnalyzePacket(char *buf, int data_size);
};


#endif
