#pragma once

#include <map>
#include <mutex>
#include <vector>
#include "korus/src/util/object_state.h"
#include "korus/src/reactor/idle_helper.h"
#include "tcp_server_channel.h"

class tcp_server_channel_creator : public noncopyable
{
public:
	tcp_server_channel_creator(std::shared_ptr<reactor_loop> reactor, const tcp_server_channel_factory_t& factory, const uint32_t self_read_size, const uint32_t self_write_size, const uint32_t sock_read_size, const uint32_t sock_write_size);
	virtual ~tcp_server_channel_creator();
	
	void on_newfd(const SOCKET fd, const struct sockaddr_in& addr);
	void on_delfd(const SOCKET fd);

private:
	std::shared_ptr<reactor_loop>			_reactor;
	tcp_server_channel_factory_t			_factory;
	uint32_t	_self_read_size;
	uint32_t	_self_write_size;
	uint32_t	_sock_read_size;
	uint32_t	_sock_write_size;

	std::map<SOCKET, chain_object_sharedwrapper<tcp_server_handler_origin>> _channel_list;
	SOCKET		_last_recover_scan_fd;	//上次扫描到的位置
	idle_helper	_idle_helper;
	void on_idle_recover(idle_helper* idle_id);
};

