// CkJsonObjectU.h: interface for the CkJsonObjectU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.82

#ifndef _CkJsonObjectU_H
#define _CkJsonObjectU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkJsonArrayU;
class CkStringTableU;
class CkBinDataU;
class CkDateTimeU;
class CkDtObjU;
class CkStringBuilderU;
class CkHashtableU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkJsonObjectU
class CK_VISIBLE_PUBLIC CkJsonObjectU  : public CkUtf16Base
{
	

	private:
	
	// Don't allow assignment or copying these objects.
	CkJsonObjectU(const CkJsonObjectU &);
	CkJsonObjectU &operator=(const CkJsonObjectU &);

    public:
	CkJsonObjectU(void);
	virtual ~CkJsonObjectU(void);

	

	static CkJsonObjectU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// Sets the delimiter char for JSON paths. The default value is ".". To use
	// Firebase style paths, set this property to "/". (This is a string property that
	// should have a length of 1 char.)
	void get_DelimiterChar(CkString &str);
	// Sets the delimiter char for JSON paths. The default value is ".". To use
	// Firebase style paths, set this property to "/". (This is a string property that
	// should have a length of 1 char.)
	const uint16_t *delimiterChar(void);
	// Sets the delimiter char for JSON paths. The default value is ".". To use
	// Firebase style paths, set this property to "/". (This is a string property that
	// should have a length of 1 char.)
	void put_DelimiterChar(const uint16_t *newVal);

	// If true then the Emit method outputs in the most compact form possible (a
	// single-line with no extra whitespace). If false, then emits with whitespace
	// and indentation to make the JSON human-readable.
	// 
	// The default value is true.
	// 
	bool get_EmitCompact(void);
	// If true then the Emit method outputs in the most compact form possible (a
	// single-line with no extra whitespace). If false, then emits with whitespace
	// and indentation to make the JSON human-readable.
	// 
	// The default value is true.
	// 
	void put_EmitCompact(bool newVal);

	// If true then the Emit method uses CRLF line-endings when emitting the
	// non-compact (pretty-print) format. If false, then bare-LF's are emitted. (The
	// compact format emits to a single line with no end-of-line characters.) Windows
	// systems traditionally use CRLF line-endings, whereas Linux, Mac OS X, and other
	// systems traditionally use bare-LF line-endings.
	// 
	// The default value is true.
	// 
	bool get_EmitCrLf(void);
	// If true then the Emit method uses CRLF line-endings when emitting the
	// non-compact (pretty-print) format. If false, then bare-LF's are emitted. (The
	// compact format emits to a single line with no end-of-line characters.) Windows
	// systems traditionally use CRLF line-endings, whereas Linux, Mac OS X, and other
	// systems traditionally use bare-LF line-endings.
	// 
	// The default value is true.
	// 
	void put_EmitCrLf(bool newVal);

	// The value of the "i" index to be used when evaluating a JSON path.
	int get_I(void);
	// The value of the "i" index to be used when evaluating a JSON path.
	void put_I(int newVal);

	// The value of the "j" index to be used when evaluating a JSON path.
	int get_J(void);
	// The value of the "j" index to be used when evaluating a JSON path.
	void put_J(int newVal);

	// The value of the "k" index to be used when evaluating a JSON path.
	int get_K(void);
	// The value of the "k" index to be used when evaluating a JSON path.
	void put_K(int newVal);

	// A prefix string that is automatically added to the JSON path passed in the first
	// argument for other methods (such as StringOf, UpdateString, SetBoolOf,
	// SizeOfArray, etc.)
	// 
	// The default value is the empty string.
	// 
	void get_PathPrefix(CkString &str);
	// A prefix string that is automatically added to the JSON path passed in the first
	// argument for other methods (such as StringOf, UpdateString, SetBoolOf,
	// SizeOfArray, etc.)
	// 
	// The default value is the empty string.
	// 
	const uint16_t *pathPrefix(void);
	// A prefix string that is automatically added to the JSON path passed in the first
	// argument for other methods (such as StringOf, UpdateString, SetBoolOf,
	// SizeOfArray, etc.)
	// 
	// The default value is the empty string.
	// 
	void put_PathPrefix(const uint16_t *newVal);

	// The number of name/value members in this JSON object.
	int get_Size(void);



	// ----------------------
	// Methods
	// ----------------------
	// Inserts a new and empty JSON array member to the position indicated by index. To
	// prepend, pass an index of 0. To append, pass an index of -1. Indexing is 0-based
	// (the 1st member is at index 0).
	bool AddArrayAt(int index, const uint16_t *name);

	// Inserts a copy of a JSON array to the position indicated by index. To prepend,
	// pass an index of 0. To append, pass an index of -1. Indexing is 0-based (the 1st
	// member is at index 0).
	bool AddArrayCopyAt(int index, const uint16_t *name, CkJsonArrayU &jarr);

	// Inserts a new boolean member to the position indicated by index. To prepend, pass
	// an index of 0. To append, pass an index of -1. Indexing is 0-based (the 1st member
	// is at index 0).
	bool AddBoolAt(int index, const uint16_t *name, bool value);

	// Inserts a new integer member to the position indicated by index. To prepend, pass
	// an index of 0. To append, pass an index of -1. Indexing is 0-based (the 1st member
	// is at index 0).
	bool AddIntAt(int index, const uint16_t *name, int value);

	// Inserts a new null member to the position indicated by index. To prepend, pass an
	// index of 0. To append, pass an index of -1. Indexing is 0-based (the 1st member is
	// at index 0).
	bool AddNullAt(int index, const uint16_t *name);

	// Inserts a new numeric member to the position indicated by index. The numericStr is an
	// integer, float, or double already converted to a string in the format desired by
	// the application. To prepend, pass an index of 0. To append, pass an index of -1.
	// Indexing is 0-based (the 1st member is at index 0).
	bool AddNumberAt(int index, const uint16_t *name, const uint16_t *numericStr);

	// Inserts a new and empty JSON object member to the position indicated by index. To
	// prepend, pass an index of 0. To append, pass an index of -1. Indexing is 0-based
	// (the 1st member is at index 0).
	bool AddObjectAt(int index, const uint16_t *name);

	// Inserts a copy of a JSON object to the position indicated by index. To prepend,
	// pass an index of 0. To append, pass an index of -1. Indexing is 0-based (the 1st
	// member is at index 0).
	bool AddObjectCopyAt(int index, const uint16_t *name, CkJsonObjectU &jsonObj);

	// Inserts a new string member to the position indicated by index. To prepend, pass
	// an index of 0. To append, pass an index of -1. Indexing is 0-based (the 1st member
	// is at index 0).
	bool AddStringAt(int index, const uint16_t *name, const uint16_t *value);

	// Appends a new and empty JSON array and returns it.
	// 
	// Important: The name is the member name, it is not a JSON path.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkJsonArrayU *AppendArray(const uint16_t *name);

	// Appends a copy of a JSON array.
	// 
	// Important: The name is the member name, it is not a JSON path.
	// 
	bool AppendArrayCopy(const uint16_t *name, CkJsonArrayU &jarr);

	// Appends a new boolean member. (This is the same as passing -1 to the AddBoolAt
	// method.)
	// 
	// Important: The name is the member name. It is not a JSON path. To append (or
	// update) using a JSON path, call UpdateBool instead.
	// 
	bool AppendBool(const uint16_t *name, bool value);

	// Appends a new integer member. (This is the same as passing an index of -1 to the
	// AddIntAt method.)
	// 
	// Important: The name is the member name. It is not a JSON path. To append (or
	// update) using a JSON path, call UpdateInt instead.
	// 
	bool AppendInt(const uint16_t *name, int value);

	// Appends a new and empty JSON object and returns it.
	// 
	// Important: The name is the member name, it is not a JSON path.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkJsonObjectU *AppendObject(const uint16_t *name);

	// Appends a copy of a JSON object.
	// 
	// Important: The name is the member name, it is not a JSON path.
	// 
	bool AppendObjectCopy(const uint16_t *name, CkJsonObjectU &jsonObj);

	// Appends a new string member. (This is the same as passing -1 to the AddStringAt
	// method.)
	// 
	// Important: The name is the member name. It is not a JSON path. To append (or
	// update) using a JSON path, call UpdateString instead.
	// 
	bool AppendString(const uint16_t *name, const uint16_t *value);

	// Appends an array of string values.
	// 
	// Important: The name is the member name, it is not a JSON path.
	// 
	bool AppendStringArray(const uint16_t *name, CkStringTableU &values);

	// Returns the JSON array that is the value of the Nth member. Indexing is 0-based
	// (the 1st member is at index 0).
	// The caller is responsible for deleting the object returned by this method.
	CkJsonArrayU *ArrayAt(int index);

	// Returns the JSON array at the specified jsonPath.
	// The caller is responsible for deleting the object returned by this method.
	CkJsonArrayU *ArrayOf(const uint16_t *jsonPath);

	// Returns the boolean value of the Nth member. Indexing is 0-based (the 1st member
	// is at index 0).
	bool BoolAt(int index);

	// Returns the boolean at the specified jsonPath.
	bool BoolOf(const uint16_t *jsonPath);

	// Appends the binary bytes at the specified jsonPath to bd. The encoding indicates the
	// encoding of the bytes, such as "base64", "hex", etc.
	bool BytesOf(const uint16_t *jsonPath, const uint16_t *encoding, CkBinDataU &bd);

	// Clears the contents of the JSON object. This is the equivalent of calling
	// jsonObject.Load("{}")
	void Clear(void);

	// Returns a copy of this JSON object.
	// The caller is responsible for deleting the object returned by this method.
	CkJsonObjectU *Clone(void);

	// Fills the dateTime with the date/time string located at jsonPath. Auto-recognizes the
	// following date/time string formats: ISO-8061 Timestamp (such as
	// "2009-11-04T19:55:41Z"), RFC822 date/time format (such as "Wed, 18 Apr 2018
	// 15:51:55 -0400"), or Unix timestamp integers.
	bool DateOf(const uint16_t *jsonPath, CkDateTimeU &dateTime);

	// Deletes the member at having the name specified by name. Note: The name is not a
	// tag path. It is the name of a member of this JSON object.
	bool Delete(const uint16_t *name);

	// Deletes the member at index index. Indexing is 0-based (the 1st member is at
	// index 0).
	bool DeleteAt(int index);

	// Fills the dt with the date/time string located at jsonPath. If bLocal is true,
	// then dt is filled with the local date/time values, otherwise it is filled with
	// the UTC/GMT values. Auto-recognizes the following date/time string formats:
	// ISO-8061 Timestamp (such as "2009-11-04T19:55:41Z"), RFC822 date/time format
	// (such as "Wed, 18 Apr 2018 15:51:55 -0400"), or Unix timestamp integers.
	bool DtOf(const uint16_t *jsonPath, bool bLocal, CkDtObjU &dt);

	// Writes the JSON document (rooted at the caller) and returns as a string.
	bool Emit(CkString &outStr);
	// Writes the JSON document (rooted at the caller) and returns as a string.
// QT defines the macro "emit" globally.  (Good grief!)
#if defined(QT_VERSION)
#pragma push_macro("emit")
#undef emit
const uint16_t *emit(void);
#pragma pop_macro("emit")
#else
const uint16_t *emit(void);
#endif



	// Emits (appends) to the contents of bd.
	bool EmitBd(CkBinDataU &bd);

	// Appends the JSON to a StringBuilder object.
	bool EmitSb(CkStringBuilderU &sb);

	// Emits the JSON document with variable substitutions applied. If omitEmpty is true,
	// then members having empty strings or empty arrays are omitted.
	bool EmitWithSubs(CkHashtableU &subs, bool omitEmpty, CkString &outStr);
	// Emits the JSON document with variable substitutions applied. If omitEmpty is true,
	// then members having empty strings or empty arrays are omitted.
	const uint16_t *emitWithSubs(CkHashtableU &subs, bool omitEmpty);

	// Recursively searches the JSON subtree rooted at the caller's node for a JSON
	// object containing a member having a specified name. (If the caller is the root
	// node of the entire JSON document, then the entire JSON document is searched.)
	// Returns the first match or _NULL_ if not found.
	// The caller is responsible for deleting the object returned by this method.
	CkJsonObjectU *FindObjectWithMember(const uint16_t *name);

	// Finds a JSON record in an array where a particular field equals or matches a
	// value pattern. Reviewing the example below is the best way to understand this
	// function.
	// The caller is responsible for deleting the object returned by this method.
	CkJsonObjectU *FindRecord(const uint16_t *arrayPath, const uint16_t *relPath, const uint16_t *value, bool caseSensitive);

	// Finds a JSON value in an record array where a particular field equals or matches
	// a value pattern. Reviewing the example below is the best way to understand this
	// function.
	bool FindRecordString(const uint16_t *arrayPath, const uint16_t *relPath, const uint16_t *value, bool caseSensitive, const uint16_t *retRelPath, CkString &outStr);
	// Finds a JSON value in an record array where a particular field equals or matches
	// a value pattern. Reviewing the example below is the best way to understand this
	// function.
	const uint16_t *findRecordString(const uint16_t *arrayPath, const uint16_t *relPath, const uint16_t *value, bool caseSensitive, const uint16_t *retRelPath);

	// Applies a Firebase event to the JSON. The data contains JSON having a format
	// such as
	// {"path": "/", "data": {"a": 1, "b": 2}}
	// The name should be "put" or "patch".
	bool FirebaseApplyEvent(const uint16_t *name, const uint16_t *data);

	// For each key in the jsonData, update (or add) the corresponding key in the JSON at
	// the given jsonPath. The jsonPath is relative to this JSON object. (This is effectively
	// applying a Firebase patch event.)
	bool FirebasePatch(const uint16_t *jsonPath, const uint16_t *jsonData);

	// Inserts or replaces the value at the jsonPath. The value can contain JSON text, an
	// integer (in decimal string format), a boolean (true/false), the keyword "null",
	// or a quoted string.
	// 
	// The jsonPath is relative to this JSON object. (This is effectively applying a
	// Firebase put event.)
	// 
	bool FirebasePut(const uint16_t *jsonPath, const uint16_t *value);

	// Returns the root of the JSON document. The root can be obtained from any JSON
	// object within the JSON document. The entire JSON document remains in memory as
	// long as at least one JSON object is referenced by the application. When the last
	// reference is removed, the entire JSON document is automatically dellocated.
	// The caller is responsible for deleting the object returned by this method.
	CkJsonObjectU *GetDocRoot(void);

	// Returns true if the item at the jsonPath exists.
	bool HasMember(const uint16_t *jsonPath);

	// Returns the index of the member having the given name. Returns -1 if the name is
	// not found.
	int IndexOf(const uint16_t *name);

	// Returns the integer value of the Nth member. Indexing is 0-based (the 1st member
	// is at index 0).
	int IntAt(int index);

	// Returns the integer at the specified jsonPath.
	int IntOf(const uint16_t *jsonPath);

	// Returns the boolean value of the member having the specified index.
	bool IsNullAt(int index);

	// Returns true if the value at the specified jsonPath is null. Otherwise returns
	// false.
	bool IsNullOf(const uint16_t *jsonPath);

	// Returns the type of data at the given jsonPath. Possible return values are:
	//     1 - string
	//     2- number
	//     3- object
	//     4- array
	//     5- boolean
	//     6- null
	// Returns -1 if no member exists at the given jsonPath.
	int JsonTypeOf(const uint16_t *jsonPath);

	// Parses a JSON string and loads it into this JSON object to provide DOM-style
	// access.
	bool Load(const uint16_t *json);

	// Loads the contents of bd.
	bool LoadBd(CkBinDataU &bd);

	// Loads a JSON file into this JSON object. The path is the file path to the JSON
	// file.
	bool LoadFile(const uint16_t *path);

	// Loads this JSON object from a predefined document having a specified name.
	bool LoadPredefined(const uint16_t *name);

	// Loads JSON from the contents of a StringBuilder object.
	bool LoadSb(CkStringBuilderU &sb);

	// Move the member from fromIndex to toIndex. If toIndex equals -1, then moves the member at
	// position fromIndex to the last position. Set toIndex = 0 to move a member to the first
	// position.
	bool MoveMember(int fromIndex, int toIndex);

	// Returns the name of the Nth member. Indexing is 0-based (the 1st member is at
	// index 0).
	bool NameAt(int index, CkString &outStr);
	// Returns the name of the Nth member. Indexing is 0-based (the 1st member is at
	// index 0).
	const uint16_t *nameAt(int index);

	// Returns the JSON object that is the value of the Nth member. Indexing is 0-based
	// (the 1st member is at index 0).
	// The caller is responsible for deleting the object returned by this method.
	CkJsonObjectU *ObjectAt(int index);

	// Returns the JSON object at the specified jsonPath.
	// The caller is responsible for deleting the object returned by this method.
	CkJsonObjectU *ObjectOf(const uint16_t *jsonPath);

	// Adds or replaces this JSON to an internal global set of predefined JSON
	// documents that can be subsequently loaded by name.
	bool Predefine(const uint16_t *name);

	// Renames the member named oldName to newName.
	bool Rename(const uint16_t *oldName, const uint16_t *newName);

	// Renames the member at index to name.
	bool RenameAt(int index, const uint16_t *name);

	// Sets the boolean value of the Nth member. Indexing is 0-based (the 1st member is
	// at index 0).
	bool SetBoolAt(int index, bool value);

	// Sets the boolean value at the specified jsonPath.
	bool SetBoolOf(const uint16_t *jsonPath, bool value);

	// Sets the integer value of the Nth member. Indexing is 0-based (the 1st member is
	// at index 0).
	bool SetIntAt(int index, int value);

	// Sets the integer at the specified jsonPath.
	bool SetIntOf(const uint16_t *jsonPath, int value);

	// Sets the value of the Nth member to null. Indexing is 0-based (the 1st member is
	// at index 0).
	bool SetNullAt(int index);

	// Sets the value at the specified jsonPath to null.
	bool SetNullOf(const uint16_t *jsonPath);

	// Sets the numeric value of the Nth member. The value is an integer, float, or
	// double already converted to a string in the format desired by the application.
	// Indexing is 0-based (the 1st member is at index 0).
	bool SetNumberAt(int index, const uint16_t *value);

	// Sets the numeric value at the specified jsonPath. The value is an integer, float, or
	// double already converted to a string in the format desired by the application.
	bool SetNumberOf(const uint16_t *jsonPath, const uint16_t *value);

	// Sets the string value of the Nth member. Indexing is 0-based (the 1st member is
	// at index 0).
	bool SetStringAt(int index, const uint16_t *value);

	// Sets the string value at the specified jsonPath.
	bool SetStringOf(const uint16_t *jsonPath, const uint16_t *value);

	// Returns the size of the array at the given jsonPath. Returns -1 if the jsonPath does not
	// evaluate to an existent JSON array.
	int SizeOfArray(const uint16_t *jsonPath);

	// Returns the string value of the Nth member. Indexing is 0-based (the 1st member
	// is at index 0).
	bool StringAt(int index, CkString &outStr);
	// Returns the string value of the Nth member. Indexing is 0-based (the 1st member
	// is at index 0).
	const uint16_t *stringAt(int index);

	// Returns the string value at the specified jsonPath.
	bool StringOf(const uint16_t *jsonPath, CkString &outStr);
	// Returns the string value at the specified jsonPath.
	const uint16_t *stringOf(const uint16_t *jsonPath);

	// Appends the string value at the specified jsonPath to sb.
	bool StringOfSb(const uint16_t *jsonPath, CkStringBuilderU &sb);

	// Swaps the positions of members at index1 and index2.
	bool Swap(int index1, int index2);

	// Returns the type of data at the given index. Possible return values are:
	//     string
	//     number
	//     object
	//     array
	//     boolean
	//     null
	// Returns -1 if no member exists at the given index.
	int TypeAt(int index);

	// Updates or appends a new string member with the encoded contents of bd. If the
	// full path specified by jsonPath does not exist, it is automatically created as
	// needed. The bytes contained in bd are encoded according to encoding (such as
	// "base64", "hex", etc.)
	bool UpdateBd(const uint16_t *jsonPath, const uint16_t *encoding, CkBinDataU &bd);

	// Updates or appends a new boolean member. If the full path specified by jsonPath does
	// not exist, it is automatically created as needed.
	bool UpdateBool(const uint16_t *jsonPath, bool value);

	// Updates or appends a new integer member. If the full path specified by jsonPath does
	// not exist, it is automatically created as needed.
	bool UpdateInt(const uint16_t *jsonPath, int value);

	// Updates or appends a new and empty array at the jsonPath. If the full path specified
	// by jsonPath does not exist, it is automatically created as needed.
	bool UpdateNewArray(const uint16_t *jsonPath);

	// Updates or appends a new and empty array at the jsonPath. If the full path specified
	// by jsonPath does not exist, it is automatically created as needed.
	bool UpdateNewObject(const uint16_t *jsonPath);

	// Updates or appends a null member. If the full path specified by jsonPath does not
	// exist, it is automatically created as needed.
	bool UpdateNull(const uint16_t *jsonPath);

	// Updates or appends a new numeric member. If the full path specified by jsonPath does
	// not exist, it is automatically created as needed.
	bool UpdateNumber(const uint16_t *jsonPath, const uint16_t *numericStr);

	// Updates or appends a new string member with the contents of sb. If the full
	// path specified by jsonPath does not exist, it is automatically created as needed.
	bool UpdateSb(const uint16_t *jsonPath, CkStringBuilderU &sb);

	// Updates or appends a new string member. If the full path specified by jsonPath does
	// not exist, it is automatically created as needed.
	// 
	// Important: Prior to version 9.5.0.68, the string passed in to this method did
	// not get properly JSON escaped. This could cause problems if non-us-ascii chars
	// are present, or if certain special chars such as quotes, CR's, or LF's are
	// present. Version 9.5.0.68 fixes the problem.
	// 
	bool UpdateString(const uint16_t *jsonPath, const uint16_t *value);

	// Saves the JSON to a file.
	bool WriteFile(const uint16_t *path);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
