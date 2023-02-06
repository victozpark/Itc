#ifndef __ITC_MESSAGE_HPP__
#define __ITC_MESSAGE_HPP__

#include "ItcDef.hpp"
#include "ItcObject.hpp"
#include "ItcMessageInfo.hpp"
#include "ItcConditionQueue.hpp"

namespace vp {

class ItcMessage
{
public:
	auto getMessageInfo() -> ItcMessageInfo &;

	auto setReplyQueue(std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcObject>>> sclReplyQueue) -> void;
	auto getReplyQueue() -> std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcObject>>>;

	auto setUserdata(std::shared_ptr<ItcObject> sclUserData) -> void;
	auto getUserdata() -> std::shared_ptr<ItcObject>;

private:
	ItcMessageInfo m_clMessageInfo;
	std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcObject>>> m_sclReplyQueue;
	std::shared_ptr<ItcObject> m_sclUserData;
};

}

#endif // __ITC_MESSAGE_HPP__