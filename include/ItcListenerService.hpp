#ifndef __ITC_LISTENER_SERVICE_HPP__
#define __ITC_LISTENER_SERVICE_HPP__

#include "Itc.hpp"
#include "ItcMessageInfo.hpp"

namespace vp {

class ItcListenerService
{
public:
	virtual auto onMessageReceived(const ItcMessageInfo & clMessageInfo, const ItcObject & clUserData) -> void = 0;
	auto replyMessage(std::shared_ptr<ItcObject> sclUserData) -> void;

friend class ItcListener;
private:
	auto setItc(std::shared_ptr<Itc> sclItc) -> void;
	auto setItcMessage(std::shared_ptr<ItcMessage> sclItcMessage) -> void;

private:
	std::shared_ptr<Itc> m_sclItc;
	std::shared_ptr<ItcMessage> m_sclItcMessage;
};

}

#endif // __ITC_LISTENER_SERVICE_HPP__