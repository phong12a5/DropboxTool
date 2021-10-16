// CkZipCrcU.h: interface for the CkZipCrcU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.82

#ifndef _CkZipCrcU_H
#define _CkZipCrcU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkClassWithCallbacksU.h"

class CkByteData;
class CkBinDataU;
class CkStringBuilderU;
class CkTaskU;
class CkBaseProgressU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkZipCrcU
class CK_VISIBLE_PUBLIC CkZipCrcU  : public CkClassWithCallbacksU
{
	public:
	bool m_cbOwned;

	private:
	
	// Don't allow assignment or copying these objects.
	CkZipCrcU(const CkZipCrcU &);
	CkZipCrcU &operator=(const CkZipCrcU &);

    public:
	CkZipCrcU(void);
	virtual ~CkZipCrcU(void);

	

	static CkZipCrcU *createNew(void);
	

	CkZipCrcU(bool bCallbackOwned);
	static CkZipCrcU *createNew(bool bCallbackOwned);

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	CkBaseProgressU *get_EventCallbackObject(void) const;
	void put_EventCallbackObject(CkBaseProgressU *progress);


	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------


	// ----------------------
	// Methods
	// ----------------------
	// Provides a way to calculate a CRC by streaming the data a chunk at a time. An
	// application would start by calling BeginStream. Then it would add data by
	// calling MoreData for each additional chunk. After the last chunk has been
	// processed, the EndStream method is called to return the CRC.
	void BeginStream(void);

	// Calculates a 32-bit CRC for in-memory byte data. This is the 32-bit CRC that
	// would be found in a Zip file header if a file containing the data was added to a
	// zip archive. Returns the CRC32 of the data.
	unsigned long CalculateCrc(CkByteData &data);

	// Calculates a CRC32 for the bytes contained in bd.
	unsigned long CrcBd(CkBinDataU &bd);

	// Calculates a CRC32 for the string contained in sb. The charset is the byte
	// representation to be used for the sb when calculating the CRC32. It can be
	// utf-8, utf-16, windows-1252, iso-8859-1, or any of the character encodings
	// (charsets) listed at the link below.
	unsigned long CrcSb(CkStringBuilderU &sb, const uint16_t *charset);

	// Calculates a CRC32 for a string. The charset is the byte representation to be used
	// for the str when calculating the CRC32. It can be utf-8, utf-16, windows-1252,
	// iso-8859-1, or any of the character encodings (charsets) listed at the link
	// below.
	unsigned long CrcString(const uint16_t *str, const uint16_t *charset);

	// Finalizes and returns the Zip CRC value calculated by calling BeginStream
	// followed by multiple calls to MoreData.
	unsigned long EndStream(void);

	// Calculates the CRC32 of a file. The data contained in the file is streamed for
	// the calculation to keep the memory footprint small and constant. Returns the
	// CRC32 of the file.
	unsigned long FileCrc(const uint16_t *path);

	// Creates an asynchronous task to call the FileCrc method with the arguments
	// provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *FileCrcAsync(const uint16_t *path);

	// Loads the caller of the task's async method.
	bool LoadTaskCaller(CkTaskU &task);

	// Adds additional data to the CRC currently being calculated. (See BeginStream for
	// more information.)
	void MoreData(CkByteData &data);

	// Converts a 32-bit integer to a hex string.
	bool ToHex(int crc, CkString &outStr);
	// Converts a 32-bit integer to a hex string.
	const uint16_t *toHex(int crc);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
