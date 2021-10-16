// CkAuthUtilU.h: interface for the CkAuthUtilU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.82

#ifndef _CkAuthUtilU_H
#define _CkAuthUtilU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"




#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkAuthUtilU
class CK_VISIBLE_PUBLIC CkAuthUtilU  : public CkUtf16Base
{
	

	private:
	
	// Don't allow assignment or copying these objects.
	CkAuthUtilU(const CkAuthUtilU &);
	CkAuthUtilU &operator=(const CkAuthUtilU &);

    public:
	CkAuthUtilU(void);
	virtual ~CkAuthUtilU(void);

	

	static CkAuthUtilU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------


	// ----------------------
	// Methods
	// ----------------------
	// Generates a Walmart authentication signature for Walmart REST API calls. Returns
	// a JSON string that contains both the WM_SEC_AUTH_SIGNATURE and WM_SEC.TIMESTAMP.
	bool WalmartSignature(const uint16_t *requestUrl, const uint16_t *consumerId, const uint16_t *privateKey, const uint16_t *requestMethod, CkString &outStr);
	// Generates a Walmart authentication signature for Walmart REST API calls. Returns
	// a JSON string that contains both the WM_SEC_AUTH_SIGNATURE and WM_SEC.TIMESTAMP.
	const uint16_t *walmartSignature(const uint16_t *requestUrl, const uint16_t *consumerId, const uint16_t *privateKey, const uint16_t *requestMethod);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
