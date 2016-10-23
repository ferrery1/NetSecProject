#include "RawSocket.hh"

/*
** Cf: http://man7.org/linux/man-pages/man7/packet.7.html
*/
RawSocket::RawSocket() {
  this.socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
  if (this.socket < 0)
    {
      perror("[RawSocket][Socket instanciation]");
      exit(EXIT_FAILURE);
    }
}

RawSocket::~RawSocket() {}

void RawSocket::ReadSocket() {

}
