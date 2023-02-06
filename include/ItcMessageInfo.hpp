#ifndef __ITC_MESSAGE_INFO_HPP__
#define __ITC_MESSAGE_INFO_HPP__

#include "ItcDef.hpp"

namespace vp {

class ItcMessageInfo
{
public:
	auto setTopic(const std::string & strTopic) -> void;
	auto getTopic() const -> const std::string &;

	auto setMessageType(const ItcMessageType & eMessageType) -> void;
	auto getMessageType() const -> const ItcMessageType &;

private:
	std::string m_strTopic;
	ItcMessageType m_eMessageType;
};

}

#endif // __ITC_MESSAGE_INFO_HPP__