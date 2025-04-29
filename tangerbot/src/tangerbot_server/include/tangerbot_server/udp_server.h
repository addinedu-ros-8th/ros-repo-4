#include <string>

class UDPServer {
public:
    UDPServer();
    UDPServer(const std::string ADDR, const int PORT);
    ~UDPServer();
    void start();
    void listen_loop();

private:
    std::string ADDR;
    int PORT;
    int sock;
};