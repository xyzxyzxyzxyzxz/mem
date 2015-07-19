class CMemFinder
{
	public:
		CMemFinder(DWORD dwProcessId);
		virtual ~CMemFinder();

	//attribute
	public:
		BOOL IsFirst() const { return m_bFirst;}
		BOOL IsValid() const { return m_hProcess !=NULL;}
		int GetListCount() const { return m_nListCnt;}
		DWORD operator[](int nIndex) { return m_arList[nIndex];}
	
	//
		virtual BOOL FindFirst(DWORD dwValue);
		virtual BOOL FindNext(DWORD dwValue);
		virtual BOOL WriteMemory(DWORD dwAddr,DWORD dwValue);
		
	//
	protected:
		virtual BOOL CompareAPage(DWORD dwBaseAddr,DWORD dwValue);
		DWORD m_arList[1024];			//address list
		int m_nListCnt;					//number of valid address
		HANDLE m_hProcess;				//aim process handle
		BOOL m_bFirst;					//if it is the first search
		
}
