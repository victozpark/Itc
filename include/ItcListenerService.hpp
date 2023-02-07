#ifndef __ITC_LISTENER_SERVICE_HPP__
#define __ITC_LISTENER_SERVICE_HPP__

#include <set>

#include "Itc.hpp"
#include "ItcMessageInfo.hpp"

namespace vp {

class ItcListenerService
{
public:
	virtual auto onMessageReceived(const ItcMessageInfo & clMessageInfo, const ItcObject & clUserData) -> void = 0;
	auto replyMessage(std::shared_ptr<ItcObject> sclUserData) -> void;
	auto sendMessage(const std::string &strTopic, std::shared_ptr<ItcObject> sclUserData) -> void;
	auto requestOneMessage(const std::string &strTopic, std::shared_ptr<ItcObject> sclUserData, int nTimeoutMs) ->  std::shared_ptr<ItcObject>;

friend class ItcListener;
private:
	auto addListeningTopic(const std::string& strTopic) -> void;

	auto setItc(std::shared_ptr<Itc> sclItc) -> void;
	auto setItcMessage(std::shared_ptr<ItcMessage> sclItcMessage) -> void;

private:
	std::set<std::string> m_setTopic;
	std::shared_ptr<Itc> m_sclItc;
	std::shared_ptr<ItcMessage> m_sclItcMessage;
};

}

#endif // __ITC_LISTENER_SERVICE_HPP__