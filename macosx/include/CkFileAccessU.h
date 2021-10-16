// CkFileAccessU.h: interface for the CkFileAccessU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.82

#ifndef _CkFileAccessU_H
#define _CkFileAccessU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkBinDataU;
class CkStringBuilderU;
class CkByteData;
class CkDateTimeU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkFileAccessU
class CK_VISIBLE_PUBLIC CkFileAccessU  : public CkUtf16Base
{
	

	private:
	
	// Don't allow assignment or copying these objects.
	CkFileAccessU(const CkFileAccessU &);
	CkFileAccessU &operator=(const CkFileAccessU &);

    public:
	CkFileAccessU(void);
	virtual ~CkFileAccessU(void);

	

	static CkFileAccessU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The current working directory of the calling process.
	void get_CurrentDir(CkString &str);
	// The current working directory of the calling process.
	const uint16_t *currentDir(void);

	// Returns true if the current open file is at the end-of-file.
	bool get_EndOfFile(void);

	// This property is set by the following methods: FileOpen, OpenForRead,
	// OpenForWrite, OpenForReadWrite, and OpenForAppend. It provides an error code
	// indicating the failure reason. Possible values are:
	// 
	//     Success (No error)
	//     Access denied.
	//     File not found.
	//     General (non-specific) open error.
	//     File aleady exists.
	//     Path refers to a directory and the access requested involves writing.
	//     Too many symbolic links were encountered in resolving path.
	//     The process already has the maximum number of files open.
	//     Pathname is too long.
	//     The system limit on the total number of open files has been reached.
	//     Pathname refers to a device special file and no corresponding device exists.
	//     Insufficient kernel memory was available.
	//     Pathname was to be created but the device containing pathname has no room
	//     for the new file.
	//     A component used as a directory in pathname is not, in fact, a directory.
	//     Pathname refers to a regular file, too large to be opened (this would be a
	//     limitation of the underlying operating system, not a limitation imposed by
	//     Chilkat).
	//     Pathname refers to a file on a read-only filesystem and write access was
	//     requested.
	// 
	int get_FileOpenError(void);

	// The error message text associated with the FileOpenError code.
	void get_FileOpenErrorMsg(CkString &str);
	// The error message text associated with the FileOpenError code.
	const uint16_t *fileOpenErrorMsg(void);

	// Note: This property only applies for applications running on Windows.
	// 
	// If true, then the following methods open files for exclusive-access:
	// OpenForAppend, OpenForRead, OpenForReadWrite, OpenForWrite. When a file is
	// opened for exclusive access, it is locked so that no other process may open the
	// file. When the file is closed, the lock is released.
	// 
	// The default value of this property is false.
	// 
	bool get_LockFileOnOpen(void);
	// Note: This property only applies for applications running on Windows.
	// 
	// If true, then the following methods open files for exclusive-access:
	// OpenForAppend, OpenForRead, OpenForReadWrite, OpenForWrite. When a file is
	// opened for exclusive access, it is locked so that no other process may open the
	// file. When the file is closed, the lock is released.
	// 
	// The default value of this property is false.
	// 
	void put_LockFileOnOpen(bool newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Appends a string using the ANSI character encoding to the currently open file.
	bool AppendAnsi(const uint16_t *text);

	// Appends the contents of bd to the currently open file.
	bool AppendBd(CkBinDataU &bd);

	// Appends the contents of sb using the character encoding (such as "utf-8")
	// specified by charset to the currently open file.
	bool AppendSb(CkStringBuilderU &sb, const uint16_t *charset);

	// Appends a string using the character encoding specified by str to the currently
	// open file.
	bool AppendText(const uint16_t *str, const uint16_t *charset);

	// Appends the 2-byte Unicode BOM (little endian) to the currently open file.
	bool AppendUnicodeBOM(void);

	// Appends the 3-byte utf-8 BOM to the currently open file.
	bool AppendUtf8BOM(void);

	// Same as DirEnsureExists, except the argument is a file path (the last part of
	// the path is a filename and not a directory). Creates all missing directories
	// such that filePath may be created.
	bool DirAutoCreate(const uint16_t *filePath);

	// Creates a new directory specified by dirPath.
	bool DirCreate(const uint16_t *dirPath);

	// Deletes the directory specified by dirPath. It is only possible to delete a
	// directory if it contains no files or subdirectories.
	bool DirDelete(const uint16_t *dirPath);

	// Creates all directories necessary such that the entire dirPath exists.
	bool DirEnsureExists(const uint16_t *dirPath);

	// Closes the currently open file.
	void FileClose(void);

	// Compares the contents of two files and returns true if they are equal and
	// otherwise returns false. The actual contents of the files are only compared if
	// the sizes are equal. The files are not entirely loaded into memory. Instead,
	// they are compared chunk by chunk. This allows for any size files to be compared,
	// regardless of the memory capacity of the computer.
	bool FileContentsEqual(const uint16_t *filePath1, const uint16_t *filePath2);

	// Copys existingFilepath to newFilepath. If failIfExists is true and newFilepath already exists, then an error is
	// returned.
	bool FileCopy(const uint16_t *existingFilepath, const uint16_t *newFilepath, bool failIfExists);

	// Deletes the file specified by filePath.
	bool FileDelete(const uint16_t *filePath);

	// Returns true if filePath exists, otherwise returns false.
	bool FileExists(const uint16_t *filePath);

	// Returns 1 if the file exists, 0 if the file does not exist, and -1 if unable to
	// check because of directory permissions or some other error that prevents the
	// ability to obtain the information.
	int FileExists3(const uint16_t *path);

	// This method should only be called on Windows operating systems. It's arguments
	// are similar to the Windows Platform SDK function named CreateFile. For Linux,
	// MAC OS X, and other operating system, use the OpenForRead, OpenForWrite,
	// OpenForReadWrite, and OpenForAppend methods.
	// 
	// Opens a file for reading or writing. The arguments mirror the Windows CreateFile
	// function:
	// Access Modes:
	// GENERIC_READ	(0x80000000)
	// GENERIC_WRITE (0x40000000)
	// 
	// Share Modes:
	// FILE_SHARE_READ(0x00000001)
	// FILE_SHARE_WRITE(0x00000002)
	// 
	// Create Dispositions
	// CREATE_NEW          1
	// CREATE_ALWAYS       2
	// OPEN_EXISTING       3
	// OPEN_ALWAYS         4
	// TRUNCATE_EXISTING   5
	// 
	// // Attributes:
	// FILE_ATTRIBUTE_READONLY         0x00000001
	// FILE_ATTRIBUTE_HIDDEN           0x00000002
	// FILE_ATTRIBUTE_SYSTEM           0x00000004
	// FILE_ATTRIBUTE_DIRECTORY        0x00000010
	// FILE_ATTRIBUTE_ARCHIVE          0x00000020
	// FILE_ATTRIBUTE_NORMAL           0x00000080
	// FILE_ATTRIBUTE_TEMPORARY	   0x00000100
	// 
	bool FileOpen(const uint16_t *filePath, unsigned long accessMode, unsigned long shareMode, unsigned long createDisposition, unsigned long attributes);

	// Reads bytes from the currently open file. maxNumBytes specifies the maximum number of
	// bytes to read. Returns an empty byte array on error.
	bool FileRead(int maxNumBytes, CkByteData &outBytes);

	// Reads bytes from the currently open file. maxNumBytes specifies the maximum number of
	// bytes to read. Appends the bytes to the binData.
	bool FileReadBd(int maxNumBytes, CkBinDataU &binData);

	// Renames a file from existingFilepath to newFilepath.
	bool FileRename(const uint16_t *existingFilepath, const uint16_t *newFilepath);

	// Sets the file pointer for the currently open file. The offset is an offset in
	// bytes from the origin. The origin can be one of the following:
	// 0 = Offset is from beginning of file.
	// 1 = Offset is from current position of file pointer.
	// 2 = Offset is from the end-of-file (offset may be negative).
	bool FileSeek(int offset, int origin);

	// Returns the size, in bytes, of a file. Returns -1 for failure.
	int FileSize(const uint16_t *filePath);

	// Returns the size of the file in decimal string format.
	bool FileSizeStr(const uint16_t *filePath, CkString &outStr);
	// Returns the size of the file in decimal string format.
	const uint16_t *fileSizeStr(const uint16_t *filePath);

	// Examines the file at path and returns one of the following values:
	// 
	// -1 = Unable to check because of directory permissions or some error preventing
	// the ability to obtain the information.
	// 0 = File does not exist.
	// 1 = Regular file.
	// 2 = Directory.
	// 3 = Symbolic link.
	// 4 = Windows Shortcut.
	// 99 = Something else.
	// 
	// Additional file types may be added in the future as needed.
	// 
	int FileType(const uint16_t *path);

	// Writes bytes to the currently open file.
	bool FileWrite(CkByteData &data);

	// Writes bytes to the currently open file.
	bool FileWrite2(const void *pByteData, unsigned long szByteData);

	// Writes the contents of binData to the currently open file. To specify the entire
	// contents of binData, set both offset and numBytes equal to 0. To write all remaining data
	// starting at offset, then set numBytes equal to 0.
	bool FileWriteBd(CkBinDataU &binData, int offset, int numBytes);

	// This is purely a utility/convenience method -- initially created to help with
	// block file uploads to Azure Blob storage. It generates a block ID string that is
	// the decimal representation of the index in length chars, and then encoded according
	// to encoding (which can be an encoding such as "base64", "hex", "ascii", etc.) For
	// example, if index = 8, length = 12, and encoding = "base64", then the string "00000012"
	// is returned base64 encoded.
	bool GenBlockId(int index, int length, const uint16_t *encoding, CkString &outStr);
	// This is purely a utility/convenience method -- initially created to help with
	// block file uploads to Azure Blob storage. It generates a block ID string that is
	// the decimal representation of the index in length chars, and then encoded according
	// to encoding (which can be an encoding such as "base64", "hex", "ascii", etc.) For
	// example, if index = 8, length = 12, and encoding = "base64", then the string "00000012"
	// is returned base64 encoded.
	const uint16_t *genBlockId(int index, int length, const uint16_t *encoding);

	// Returns the directory information for the specified path string.
	// GetDirectoryName('C:\MyDir\MySubDir\myfile.ext') returns 'C:\MyDir\MySubDir\'
	// GetDirectoryName('C:\MyDir\MySubDir') returns 'C:\MyDir\'
	// GetDirectoryName('C:\MyDir\') returns 'C:\MyDir\'
	// GetDirectoryName('C:\MyDir') returns 'C:\'
	// GetDirectoryName('C:\') returns 'C:\'
	bool GetDirectoryName(const uint16_t *path, CkString &outStr);
	// Returns the directory information for the specified path string.
	// GetDirectoryName('C:\MyDir\MySubDir\myfile.ext') returns 'C:\MyDir\MySubDir\'
	// GetDirectoryName('C:\MyDir\MySubDir') returns 'C:\MyDir\'
	// GetDirectoryName('C:\MyDir\') returns 'C:\MyDir\'
	// GetDirectoryName('C:\MyDir') returns 'C:\'
	// GetDirectoryName('C:\') returns 'C:\'
	const uint16_t *getDirectoryName(const uint16_t *path);
	// Returns the directory information for the specified path string.
	// GetDirectoryName('C:\MyDir\MySubDir\myfile.ext') returns 'C:\MyDir\MySubDir\'
	// GetDirectoryName('C:\MyDir\MySubDir') returns 'C:\MyDir\'
	// GetDirectoryName('C:\MyDir\') returns 'C:\MyDir\'
	// GetDirectoryName('C:\MyDir') returns 'C:\'
	// GetDirectoryName('C:\') returns 'C:\'
	const uint16_t *directoryName(const uint16_t *path);

	// Returns the extension of the specified path string.
	// GetExtension('C:\mydir.old\myfile.ext') returns '.ext'
	// GetExtension('C:\mydir.old\') returns ''
	bool GetExtension(const uint16_t *path, CkString &outStr);
	// Returns the extension of the specified path string.
	// GetExtension('C:\mydir.old\myfile.ext') returns '.ext'
	// GetExtension('C:\mydir.old\') returns ''
	const uint16_t *getExtension(const uint16_t *path);
	// Returns the extension of the specified path string.
	// GetExtension('C:\mydir.old\myfile.ext') returns '.ext'
	// GetExtension('C:\mydir.old\') returns ''
	const uint16_t *extension(const uint16_t *path);

	// Returns the file name and extension of the specified path string.
	// GetFileName('C:\mydir\myfile.ext') returns 'myfile.ext'
	// GetFileName('C:\mydir\') returns ''
	bool GetFileName(const uint16_t *path, CkString &outStr);
	// Returns the file name and extension of the specified path string.
	// GetFileName('C:\mydir\myfile.ext') returns 'myfile.ext'
	// GetFileName('C:\mydir\') returns ''
	const uint16_t *getFileName(const uint16_t *path);
	// Returns the file name and extension of the specified path string.
	// GetFileName('C:\mydir\myfile.ext') returns 'myfile.ext'
	// GetFileName('C:\mydir\') returns ''
	const uint16_t *fileName(const uint16_t *path);

	// Returns the file name of the specified path string without the extension.
	// GetFileNameWithoutExtension('C:\mydir\myfile.ext') returns 'myfile'
	// GetFileNameWithoutExtension('C:\mydir\') returns ''
	bool GetFileNameWithoutExtension(const uint16_t *path, CkString &outStr);
	// Returns the file name of the specified path string without the extension.
	// GetFileNameWithoutExtension('C:\mydir\myfile.ext') returns 'myfile'
	// GetFileNameWithoutExtension('C:\mydir\') returns ''
	const uint16_t *getFileNameWithoutExtension(const uint16_t *path);
	// Returns the file name of the specified path string without the extension.
	// GetFileNameWithoutExtension('C:\mydir\myfile.ext') returns 'myfile'
	// GetFileNameWithoutExtension('C:\mydir\') returns ''
	const uint16_t *fileNameWithoutExtension(const uint16_t *path);

	// Gets one of the following date/times for a file:
	// 0: Last-modified
	// 1: Last-access
	// 2: Creation
	// The "path" argument indicates which time to return. The values can be 0, 1, or
	// 2.
	// 
	// Note: Linux filesystems do not keep a file's creation date/time. In such a case,
	// this method will return the last-modified time.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkDateTimeU *GetFileTime(const uint16_t *path, int which);

	// Gets the last-modified date/time for a file.
	// The caller is responsible for deleting the object returned by this method.
	CkDateTimeU *GetLastModified(const uint16_t *path);

	// Returns the number of blocks in the currently open file. The number of bytes per
	// block is specified by blockSize. The number of blocks is the file size divided by the
	// blockSize, plus 1 if the file size is not evenly divisible by blockSize. For example, if
	// the currently open file is 60500 bytes, and if the blockSize is 1000 bytes, then this
	// method returns a count of 61 blocks.
	// 
	// Returns -1 if no file is open. Return 0 if the file is completely empty (0
	// bytes).
	// 
	int GetNumBlocks(int blockSize);

	// Creates a temporary filepath of the form dirPath\prefix_xxxx.TMP Where "xxxx" are
	// random alpha-numeric chars. The returned filepath is guaranteed to not already
	// exist.
	bool GetTempFilename(const uint16_t *dirPath, const uint16_t *prefix, CkString &outStr);
	// Creates a temporary filepath of the form dirPath\prefix_xxxx.TMP Where "xxxx" are
	// random alpha-numeric chars. The returned filepath is guaranteed to not already
	// exist.
	const uint16_t *getTempFilename(const uint16_t *dirPath, const uint16_t *prefix);
	// Creates a temporary filepath of the form dirPath\prefix_xxxx.TMP Where "xxxx" are
	// random alpha-numeric chars. The returned filepath is guaranteed to not already
	// exist.
	const uint16_t *tempFilename(const uint16_t *dirPath, const uint16_t *prefix);

	// Opens a file for appending. If filePath did not already exists, it is created. When
	// an existing file is opened with this method, the contents will not be
	// overwritten and the file pointer is positioned at the end of the file.
	// 
	// If the open/create failed, then error information will be available in the
	// FileOpenError and FileOpenErrorMsg properties.
	// 
	bool OpenForAppend(const uint16_t *filePath);

	// Opens a file for reading. The file may contain any type of data (binary or text)
	// and it must already exist. If the open failed, then error information will be
	// available in the FileOpenError and FileOpenErrorMsg properties.
	bool OpenForRead(const uint16_t *filePath);

	// Opens a file for reading/writing. If filePath did not already exists, it is created.
	// When an existing file is opened with this method, the contents will not be
	// overwritten, but the file pointer is positioned at the beginning of the file.
	// 
	// If the open/create failed, then error information will be available in the
	// FileOpenError and FileOpenErrorMsg properties.
	// 
	bool OpenForReadWrite(const uint16_t *filePath);

	// Opens a file for writing. If filePath did not already exists, it is created. When an
	// existing file is opened with this method, the contents will be overwritten. (For
	// example, calling OpenForWrite on an existing file and then immediately closing
	// the file will result in an empty file.) If the open/create failed, then error
	// information will be available in the FileOpenError and FileOpenErrorMsg
	// properties.
	bool OpenForWrite(const uint16_t *filePath);

	// Reads the entire contents of a binary file and returns it as an encoded string
	// (using an encoding such as Base64, Hex, etc.) The encoding may be one of the
	// following strings: base64, hex, qp, or url.
	bool ReadBinaryToEncoded(const uint16_t *filePath, const uint16_t *encoding, CkString &outStr);
	// Reads the entire contents of a binary file and returns it as an encoded string
	// (using an encoding such as Base64, Hex, etc.) The encoding may be one of the
	// following strings: base64, hex, qp, or url.
	const uint16_t *readBinaryToEncoded(const uint16_t *filePath, const uint16_t *encoding);

	// Reads the Nth block of a file, where the size of each block is specified by
	// blockSize. The first block is at blockIndex 0. If the block to be read is the last in the
	// file and there is not enough data to fill an entire block, then the partial
	// block is returned.
	bool ReadBlock(int blockIndex, int blockSize, CkByteData &outBytes);

	// Reads the Nth block of a file, where the size of each block is specified by
	// blockSize. The first block is at blockIndex 0. If the block to be read is the last in the
	// file and there is not enough data to fill an entire block, then the partial
	// block is returned. The file data is appended to the contents of bd.
	bool ReadBlockBd(int blockIndex, int blockSize, CkBinDataU &bd);

	// Reads the entire contents of a binary file and returns the data.
	bool ReadEntireFile(const uint16_t *filePath, CkByteData &outBytes);

	// Reads the entire contents of a text file, interprets the bytes according to the
	// character encoding specified by charset, and returns the text file as a string.
	bool ReadEntireTextFile(const uint16_t *filePath, const uint16_t *charset, CkString &outStrFileContents);
	// Reads the entire contents of a text file, interprets the bytes according to the
	// character encoding specified by charset, and returns the text file as a string.
	const uint16_t *readEntireTextFile(const uint16_t *filePath, const uint16_t *charset);

	// Scans the currently open file (opened by calling OpenForRead) for the next chunk
	// of text delimited by beginMarker and endMarker. The matched text, including the beginMarker and
	// endMarker are appended to sb. The bytes of the text file are interpreted according
	// to charset. If startAtBeginning equals true, then scanning begins at the start of the file.
	// Otherwise scanning begins starting at the byte following the last matched
	// fragment.
	// 
	// The return value of this function is:
	// 0: No match was found.
	// 1: Found the next matching fragment and appended to sb.
	// -1: Error reading the file.
	// 
	// To support a common need for use with XML files, the beginMarker is "XML tag aware". If
	// the beginMarker is a string such as " ", then it will also match "
	// 
	int ReadNextFragment(bool startAtBeginning, const uint16_t *beginMarker, const uint16_t *endMarker, const uint16_t *charset, CkStringBuilderU &sb);

	// Reassembles a file previously split by the SplitFile method.
	bool ReassembleFile(const uint16_t *partsDirPath, const uint16_t *partPrefix, const uint16_t *partExtension, const uint16_t *reassembledFilename);

	// Replaces all occurrences of existingString with replacementString in a file. The character encoding,
	// such as utf-8, ansi, etc. is specified by charset.
	int ReplaceStrings(const uint16_t *filePath, const uint16_t *charset, const uint16_t *existingString, const uint16_t *replacementString);

	// Sets the current working directory for the calling process to dirPath.
	bool SetCurrentDir(const uint16_t *dirPath);

	// Sets the create date/time, the last-access date/time, and the last-modified
	// date/time for a file. For non-Windows filesystems where create times are not
	// implemented, the createTime is ignored.
	bool SetFileTimes(const uint16_t *filePath, CkDateTimeU &createTime, CkDateTimeU &lastAccessTime, CkDateTimeU &lastModTime);

	// Sets the last-modified date/time for a file.
	bool SetLastModified(const uint16_t *filePath, CkDateTimeU &lastModified);

	// Splits a file into chunks. Please refer to the example below:
	bool SplitFile(const uint16_t *fileToSplit, const uint16_t *partPrefix, const uint16_t *partExtension, int partSize, const uint16_t *destDir);

	// Creates a symbolic link.
	// 
	// Note: On Windows systems, this is not the same as creating a shortcut. A Windows
	// symbolic link and a Windows shortcut are two different things. Shortcut files
	// are common on Windows, but not symbolic links. Creating a symbolic link requires
	// a special privilege, unless running as administrator. To be able to create
	// symbolic links, your user account or group needs to be listed in secpol.msc →
	// Security Settings → Local Policies → User Rights Assignment → Create
	// symbolic links. However the special setting is not needed when running within
	// the development environment, such as from Visual Studio.
	// 
	bool SymlinkCreate(const uint16_t *targetPath, const uint16_t *linkPath);

	// Returns the full pathname of the file at the end of the linkPath. Also handles
	// Windows shortcut files by returning the absolute path of the target.
	bool SymlinkTarget(const uint16_t *linkPath, CkString &outStr);
	// Returns the full pathname of the file at the end of the linkPath. Also handles
	// Windows shortcut files by returning the absolute path of the target.
	const uint16_t *symlinkTarget(const uint16_t *linkPath);

	// Deletes an entire directory tree (all files and sub-directories).
	bool TreeDelete(const uint16_t *path);

	// Truncates the currently open file at the current file position.
	bool Truncate(void);

	// Opens/creates filePath, writes fileData, and closes the file.
	bool WriteEntireFile(const uint16_t *filePath, CkByteData &fileData);

	// Opens filePath, writes textData using the character encoding specified by charset, and
	// closes the file. If includedPreamble is true and the charset is Unicode or utf-8, then the
	// BOM is included at the beginning of the file.
	bool WriteEntireTextFile(const uint16_t *filePath, const uint16_t *textData, const uint16_t *charset, bool includedPreamble);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
