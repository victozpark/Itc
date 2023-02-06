
#include <string>
#include "ItcObject.hpp"

class MyMessage : public vp::ItcObject
{
public:
	virtual auto getMessageId() const -> const std::string & = 0;
};

class MyTTT : public MyMessage
{
public:
	auto setMessageId(const std::string & strMessageId) -> void { m_strMessageId = strMessageId; }
	auto getMessageId() const -> const std::string & { return m_strMessageId; }

	auto setData(const std::string &data) -> void { m_strData = data;}
	auto getData() const -> const std::string& { return m_strData;}

private:
	std::string m_strMessageId;
	std::string m_strData;
};