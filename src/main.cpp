#include <boost/asio.hpp>

#include <iostream>

int main(int argc, char *argv[]) {
  boost::asio::io_service ios;

  boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4();

  boost::asio::ip::tcp::socket sock(ios);

  boost::system::error_code ec;

  sock.open(protocol, ec);

  if (ec.value() != 0) {
    std::cout << "Failed to open the socket! Error code = " << ec.value() << ". Message: " << ec.message();
    return ec.value();
  }
  

  std::cout << "server" << std::endl;

  
  return EXIT_SUCCESS;
}