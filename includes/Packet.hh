#ifndef PACKET_HH_
# define PACKET_HH_

# include <map>
# include <array>
# include <string>
# include "NetObj.hh"
//# include "Proto.hh"


class Packet : public NetObj {
protected:
  void	*hdr;
  int	size;
  std::map<std::string, std::map<std::string, std::string>> contents;
  std::array<std::string, 4> row;
  std::string _type;
    struct s_proto_obj {
    int		proto_ID;
    std::string name;
  };

    struct s_proto_obj _tabTcpip[60] = {
    {0, "IPv4"}, 
    {1, "ICMP"}, 
    {2, "IGMP"}, 
    {3, "GGP"}, 
    {4, "IP-ENCAP"}, 
    {5, "ST"}, 
    {6, "TCP"}, 
    {8, "EGP"}, 
    {9, "IGP"}, 
    {12, "PUP"}, 
    {17, "UDP"}, 
    {20, "HMP"}, 
    {22, "XNS-IDP"}, 
    {27, "RDP"}, 
    {29, "ISO-TP4"}, 
    {33, "DCCP"}, 
    {36, "XTP"}, 
    {37, "DDP"}, 
    {38, "IDPR-CMTP"}, 
    {41,  "IPv6"}, 
    {43, "IPv6-ROUTE"}, 
    {44, "IPv6-FRAG"}, 
    {45, "IDRP"}, 
    {46, "RSVP"}, 
    {47, "GRE"}, 
    {50, "IPSEC-ESP"}, 
    {51, "IPSEC-AH"}, 
    {57, "SKIP"}, 
    {58, "IPv6-ICMP"}, 
    {59, "IPv6-NoNxt"}, 
    {60, "IPv6-Opts"}, 
    {73, "RSPF"}, 
    {81, "VMTP"}, 
    {88, "EIGRP"}, 
    {89, "OSPFIGP"}, 
    {93, "AX.25"}, 
    {94, "IPIP"}, 
    {97, "ETHERIP"}, 
    {98, "ENCAP"}, 
    {99, "Anyprivateencryptionscheme"}, 
    {103, "PIM"}, 
    {108, "IPCOMP"}, 
    {112, "VRRP"}, 
    {115, "L2TP"}, 
    {124, "ISIS"}, 
    {132, "SCTP"}, 
    {132, "SCTP"}, 
    {133, "FC"}, 
    {135, "MOBILITY-HEADER"}, 
    {136, "UDPLITE"}, 
    {137, "MPLS-IN-IP"}, 
    {138, "MANET"}, 
    {139, "HIP"}, 
    {140, "SHIM6"}, 
    {141, "WESP"}, 
    {142, "ROHC"},
    {-1, "NONE"}
  };

public:
  Packet(std::string type);
  ~Packet();
  virtual void parsePacket(char *buf);
  virtual std::array<std::string, 4> getRow();
  void setNum(int num);
  virtual std::string getType();
  virtual std::map<std::string, std::map<std::string, std::string>> getContents();
};

#endif
