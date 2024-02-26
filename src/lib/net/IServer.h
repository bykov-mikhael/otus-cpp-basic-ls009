#pragma once

#include <iostream>

class IServer {
  public:
    virtual ~IServer();
    virtual int run();
    virtual int stop();

  private:
    size_t m_client_count;
}