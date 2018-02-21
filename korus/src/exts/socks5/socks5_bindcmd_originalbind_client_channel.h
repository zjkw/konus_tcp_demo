#pragma once

#include "socks5_client_channel_base.h"

class socks5_bindcmd_client_handler_origin;

class socks5_bindcmd_originalbind_client_channel : public socks5_client_channel_base
{
public:
	socks5_bindcmd_originalbind_client_channel(std::shared_ptr<reactor_loop> reactor, const std::string& server_addr, const std::string& socks_user, const std::string& socks_psw);
	virtual ~socks5_bindcmd_originalbind_client_channel();

	//override------------------
	virtual void	on_chain_init();
	virtual void	on_chain_final();
	virtual void	chain_inref();
	virtual void	chain_deref();
	void set_integration(socks5_bindcmd_client_handler_origin* integration) { _integration = integration; }

	virtual void	on_connected();
	virtual void	on_closed();
	virtual CLOSE_MODE_STRATEGY	on_error(CHANNEL_ERROR_CODE code);

	virtual int32_t on_recv_split(const void* buf, const size_t size);
	virtual void	on_recv_pkg(const void* buf, const size_t size);

private:
	std::string _server_addr;
	socks5_bindcmd_client_handler_origin* _integration;
	
	virtual int32_t	make_tunnel_pkg(void* buf, const uint16_t size);
	virtual void	on_tunnel_pkg(const void* buf, const uint16_t size);
};