#ifndef __ITC_DEF_HPP__
#define __ITC_DEF_HPP__

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include <memory>

#include "ItcException.hpp"

namespace vp {

enum class ItcMessageType {
	SEND,
	REQUEST,
	REPLY
};

}

#endif // __ITC_DEF_HPP__