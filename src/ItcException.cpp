#include "ItcException.hpp"

namespace vp {

ItcException::ItcException(const std::string& strMsg) noexcept
{
	m_strMsg = strMsg;
	m_strWhat = m_strMsg;
}
ItcException::ItcException(const char *pzFile, const char *pzFunc, int nLine, const std::string& strMsg) noexcept
{
	m_strFile = pzFile;
	m_strFunc = pzFunc;
	m_nLine = nLine;
	m_strMsg = strMsg;
	m_strWhat = "[" + m_strFile + ":" + m_strFunc + ":" + std::to_string(m_nLine) + "] " + m_strMsg ;
}
ItcException::~ItcException() noexcept { }
auto ItcException::what() const noexcept -> const char* { return m_strWhat.c_str(); }
auto ItcException::getFile() const -> const std::string& { return m_strFile; }
auto ItcException::getFunc() const -> const std::string& { return m_strFunc; }
auto ItcException::getLine() const -> int { return m_nLine; }
auto ItcException::getMsg() const  -> const std::string& { return m_strMsg; }

// Failure
ItcExceptionFailure::ItcExceptionFailure(const std::string& strMsg) noexcept : ItcException(strMsg) {}
ItcExceptionFailure::ItcExceptionFailure(const char *pzFile, const char *pzFunc, int nLine, const std::string& strMsg) noexcept : ItcException(pzFile, pzFunc, nLine, strMsg) {}
ItcExceptionFailure::~ItcExceptionFailure() noexcept {}	

// Timeout
ItcExceptionTimeout::ItcExceptionTimeout(const std::string& strMsg) noexcept : ItcException(strMsg) {}
ItcExceptionTimeout::ItcExceptionTimeout(const char *pzFile, const char *pzFunc, int nLine, const std::string& strMsg) noexcept : ItcException(pzFile, pzFunc, nLine, strMsg) {}
ItcExceptionTimeout::~ItcExceptionTimeout() noexcept {}	

// Notfound
ItcExceptionNotfound::ItcExceptionNotfound(const std::string& strMsg) noexcept : ItcException(strMsg) {}
ItcExceptionNotfound::ItcExceptionNotfound(const char *pzFile, const char *pzFunc, int nLine, const std::string& strMsg) noexcept : ItcException(pzFile, pzFunc, nLine, strMsg) {}
ItcExceptionNotfound::~ItcExceptionNotfound() noexcept {}	

// Duplicated
ItcExceptionDuplicated::ItcExceptionDuplicated(const std::string& strMsg) noexcept : ItcException(strMsg) {}
ItcExceptionDuplicated::ItcExceptionDuplicated(const char *pzFile, const char *pzFunc, int nLine, const std::string& strMsg) noexcept : ItcException(pzFile, pzFunc, nLine, strMsg) {}
ItcExceptionDuplicated::~ItcExceptionDuplicated() noexcept {}	

}