#ifndef RAWSOCKET_HH_
# define RAWSOCKET_HH_

class RawSocket {
 private:
  int socket;

public:
  RawSocket();
  void ReadSocket();
  ~RawSocket();
};


#endif
