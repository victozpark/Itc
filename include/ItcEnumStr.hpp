#ifndef __ITC_ENUM_STR_HPP__
#define __ITC_ENUM_STR_HPP__

#include <string>

#include "ItcDef.hpp"

namespace vp {

class ItcEnumStr
{
public:
	class ItcMessageType
	{
	public:
		static auto toString(const vp::ItcMessageType & eMessageType) -> const std::string
		{
			if (eMessageType == vp::ItcMessageType::SEND) return "Send";
			else if (eMessageType == vp::ItcMessageType::REQUEST) return "Request";
			else if (eMessageType == vp::ItcMessageType::REPLY) return "Reply";
			else return "Undefined";
		}
	};
};

}

#endif // __ITC_ENUM_STR_HPP__