#include <iostream>
#include <string>
#include <stdexcept>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class MessengerClient {
private:
    int sock;
    std::string server_ip;
    int server_port;

public:
    MessengerClient(const std::string& ip, int port) 
        : server_ip(ip), server_port(port) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            throw std::runtime_error("Failed to create socket");
        }

        sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(server_port);

        if (inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr) <= 0) {
            throw std::runtime_error("Invalid IP address");
        }

        if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
            throw std::runtime_error("Connection failed");
        }
    }

    void sendMessage(const std::string& message) {
        if (send(sock, message.c_str(), message.length(), 0) < 0) {
            throw std::runtime_error("Failed to send message");
        }
    }

    std::string receiveMessage() {
        char buffer[1024] = {0};
        int bytes_read = read(sock, buffer, sizeof(buffer) - 1);
        if (bytes_read < 0) {
            throw std::runtime_error("Failed to receive message");
        }
        return std::string(buffer);
    }

    ~MessengerClient() {
        close(sock);
    }
};

int main() {
    MessengerClient client("127.0.0.1", 8080);
    std::cout << "Connected to server!" << std::endl;
    while (true) {
        std::string message;
        std::cout << "Enter a message (type 'exit' to quit): ";
        std::getline(std::cin, message);
        if (message == "exit") {
            std::cout << "Exiting messenger. Goodbye!" << std::endl;
            break;
        }
        client.sendMessage(message);
        std::cout << "Message sent!" << std::endl;
        std::string response = client.receiveMessage();
        std::cout << "Server response: " << response << std::endl;
    }
    return 0;
}