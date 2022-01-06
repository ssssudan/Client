#pragma once

// ConnectSocket 명령 대상

class ConnectSocket : public CSocket
{
public:
	ConnectSocket();
	virtual ~ConnectSocket();

	
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};

