#pragma once

#include <string>
#include "basic_defines.h"

bool set_reuse_port_sock(SOCKET fd, int reuse);

bool set_reuse_addr_sock(SOCKET fd, int reuse);

bool set_nonblock_sock(SOCKET fd, unsigned int nonblock);

bool set_socket_sendbuflen(SOCKET fd, uint32_t buf_size);

bool set_socket_recvbuflen(SOCKET fd, uint32_t buf_size);

bool bind_sock(SOCKET fd, const struct sockaddr_in& addr);

bool split_hostport(const std::string& address, std::string& host, uint16_t& port);
bool sockaddr_from_string(const std::string& address, struct sockaddr_in& si);
bool sockaddr_from_string(const std::string& ip, const uint16_t port, struct sockaddr_in& si);	//port为host字节序
bool sockaddr_from_string(const uint32_t ip, const uint16_t port, struct sockaddr_in& si);		//ip port为host字节序
bool sockaddr_from_string(const std::string& address, std::string& host, std::string& port);

bool string_from_sockaddr(std::string& address, const struct sockaddr_in& si);

bool string_from_ipport(std::string& address, const std::string& ip, const uint16_t port);
bool string_from_ipport(std::string& address, const uint32_t& ip, const uint16_t port);

bool peeraddr_from_fd(SOCKET fd, std::string& addr);
bool localaddr_from_fd(SOCKET fd, std::string& addr);

enum SOCK_ADDR_TYPE
{
	SAT_NONE = 0,
	SAT_IPV4 = 1,
	SAT_IPV6 = 2,
	SAT_DOMAIN = 3,
};
//address可能包括端口
SOCK_ADDR_TYPE	addrtype_from_string(const std::string& host);	//  if (inet_aton (*str, &addr.sin_addr) != 0) {



