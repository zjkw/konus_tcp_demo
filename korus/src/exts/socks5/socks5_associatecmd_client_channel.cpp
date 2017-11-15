#include <assert.h>
#include "socks5_associatecmd_client_channel.h"

socks5_associatecmd_client_channel::socks5_associatecmd_client_channel(std::shared_ptr<reactor_loop> reactor, const std::string& server_addr, const std::string& socks_user, const std::string& socks_psw, const udp_client_channel_factory_t& udp_factory)
: socks5_client_channel_base(reactor)
{

}

socks5_associatecmd_client_channel::~socks5_associatecmd_client_channel()
{
}

//override------------------
void	socks5_associatecmd_client_channel::on_chain_init()
{
}

void	socks5_associatecmd_client_channel::on_chain_final()
{
}

void	socks5_associatecmd_client_channel::on_connected()
{
}

void	socks5_associatecmd_client_channel::on_closed()
{

}

//��ȡ���ݰ�������ֵ =0 ��ʾ���������� >0 �����İ�(��)
int32_t socks5_associatecmd_client_channel::on_recv_split(const void* buf, const size_t len)
{
	return 0;
}

//����һ����������������
void	socks5_associatecmd_client_channel::on_recv_pkg(const void* buf, const size_t len)
{

}