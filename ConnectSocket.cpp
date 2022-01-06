// ConnectSocket.cpp: 구현 파일
//

#include "pch.h"
#include "Client.h"
#include "ConnectSocket.h"
#include "ClientDlg.h"


// ConnectSocket

ConnectSocket::ConnectSocket()
{
}

ConnectSocket::~ConnectSocket()
{
}


// ConnectSocket 멤버 함수


void ConnectSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	char szBuffer[256] = { 0 ,};

	CClientDlg* pMain = (CClientDlg*)AfxGetMainWnd();

	if (Receive(szBuffer, 256) > 0)
	{
		if (szBuffer[0] == -84) {
			for (int i = 0; i <= 248; i++) {
				szBuffer[i] = szBuffer[i + 7];
			}
			pMain->m_strMessage = szBuffer;
			int cnt = pMain->m_List.GetCount();
			pMain->m_List.InsertString(cnt, pMain->m_strMessage);
		}
		else {
			pMain->m_strMessage = szBuffer;
			int cnt = pMain->m_List.GetCount();
			pMain->m_List.InsertString(cnt, pMain->m_strMessage);
		}
		CSocket::OnReceive(nErrorCode);
	}
}


void ConnectSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	ShutDown();
	Close();

	AfxMessageBox(_T("서버로부터 연결 중단"));
	::PostQuitMessage(0);


	CSocket::OnClose(nErrorCode);
}
