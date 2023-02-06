#ifndef __ITC_EXCEPTION_HPP__
#define __ITC_EXCEPTION_HPP__

#include <exception>
#include <string>

#define VP_EXCEPTION_FAILURE(str) vp::ItcExceptionFailure(__FILE__, __func__, __LINE__, str)
#define VP_EXCEPTION_TIMEOUT(str) vp::ItcExceptionTimeout(__FILE__, __func__, __LINE__, str)
#define VP_EXCEPTION_NOTFOUND(str) vp::ItcExceptionNotfound(__FILE__, __func__, __LINE__, str)
#define VP_EXCEPTION_DUPLICATED(str) vp::ItcExceptionDuplicated(__FILE__, __func__, __LINE__, str)

namespace vp {

class ItcException : public std::exception
{
public:
	ItcException(const std::string& strMsg) noexcept;
	ItcException(const char *pzFile, const char *pzFunc, int nLine, const std::string& strMsg) noexcept;
	virtual ~ItcException() noexcept;

	virtual auto what() const noexcept -> const char*;
	virtual auto getFile() const -> const std::string& ;
	virtual auto getFunc() const -> const std::string& ;
	virtual auto getLine() const -> int;
	virtual auto getMsg() const  -> const std::string& ;

private:
	std::string m_strWhat;
	std::string m_strFile;
	std::string m_strFunc;
	int m_nLine;
	std::string m_strMsg;
};

class ItcExceptionFailure : public ItcException
{
public:
	ItcExceptionFailure(const std::string& strMsg) noexcept;
	ItcExceptionFailure(const char *pzFile, const char *pzFunc, int nLine, const std::string& strMsg) noexcept;
	virtual ~ItcExceptionFailure() noexcept;	
};

class ItcExceptionTimeout : public ItcException
{
public:
	ItcExceptionTimeout(const std::string& strMsg) noexcept;
	ItcExceptionTimeout(const char *pzFile, const char *pzFunc, int nLine, const std::string& strMsg) noexcept;
	virtual ~ItcExceptionTimeout() noexcept;	
};

class ItcExceptionNotfound : public ItcException
{
public:
	ItcExceptionNotfound(const std::string& strMsg) noexcept;
	ItcExceptionNotfound(const char *pzFile, const char *pzFunc, int nLine, const std::string& strMsg) noexcept;
	virtual ~ItcExceptionNotfound() noexcept;	
};

class ItcExceptionDuplicated : public ItcException
{
public:
	ItcExceptionDuplicated(const std::string& strMsg) noexcept;
	ItcExceptionDuplicated(const char *pzFile, const char *pzFunc, int nLine, const std::string& strMsg) noexcept;
	virtual ~ItcExceptionDuplicated() noexcept;	
};

}

#endif // __ITC_EXCEPTION_HPP__