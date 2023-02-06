#include "ItcMessaging.hpp"
#include "ItcConditionQueue.hpp"
#include "ItcEnumStr.hpp"

namespace vp {

/**
 * @brief Construct a new Itc Messaging:: Itc Messaging object
 * 
 * @param sclItc Itc instance
 */
ItcMessaging::ItcMessaging(std::shared_ptr<Itc> sclItc)
{
	m_sclItc = sclItc;
}

/**
 * @brief Send message
 * 
 * @param strTopic Topic name
 * @param pclUserData User data
 */
auto ItcMessaging::send(const std::string & strTopic, std::shared_ptr<ItcObject> pclUserData) -> void
{
	auto vecQueue = m_sclItc->getCtx()->getGetQueueByTopic(strTopic);
	for (auto it=vecQueue.begin(); it!=vecQueue.end(); it++) {
		auto clMsg = std::make_shared<ItcMessage>();
		clMsg->getMessageInfo().setTopic(strTopic);
		clMsg->getMessageInfo().setMessageType(ItcMessageType::SEND);
		clMsg->setReplyQueue(nullptr);
		clMsg->setUserdata(pclUserData);

		it->get()->enqueue(clMsg);
	}
}

/**
 * @brief Send message (to only one Listner of a topic)
 * 
 * @param strTopic Topic name
 * @param pclUserData User data
 */
auto ItcMessaging::sendOne(const std::string & strTopic, std::shared_ptr<ItcObject> pclUserData) -> void
{
	auto sclQueue = m_sclItc->getCtx()->getGetQueueByTopicOne(strTopic);
	if (sclQueue == nullptr) {
		return;
	}
	auto clMsg = std::make_shared<ItcMessage>();
	clMsg->getMessageInfo().setTopic(strTopic);
	clMsg->getMessageInfo().setMessageType(ItcMessageType::SEND);
	clMsg->setReplyQueue(nullptr);
	clMsg->setUserdata(pclUserData);

	sclQueue->enqueue(clMsg);
}

/**
 * @brief Request message (to only one listener of a topic)
 * 
 * @param strTopic Topic name
 * @param pclUserData User data
 * @param nTimeout Timeout (Milliseconds)
 * @return std::shared_ptr<ItcObject> Reply-message
 */
auto ItcMessaging::requestOne(const std::string & strTopic, std::shared_ptr<ItcObject> pclUserData, int nTimeout) -> std::shared_ptr<ItcObject>
{
	auto sclReplyQueue = std::make_shared<ItcConditionQueue<std::shared_ptr<ItcObject>>>();

	auto sclQueue = m_sclItc->getCtx()->getGetQueueByTopicOne(strTopic);

	auto clMsg = std::make_shared<ItcMessage>();
	clMsg->getMessageInfo().setTopic(strTopic);
	clMsg->getMessageInfo().setMessageType(ItcMessageType::REQUEST);
	clMsg->setReplyQueue(sclReplyQueue);
	clMsg->setUserdata(pclUserData);

	sclQueue->enqueue(clMsg);

	auto sclRet = sclReplyQueue->dequeue(nTimeout);

	return sclRet;
}

/**
 * @brief Reply message (to the sender)
 * 
 * @param clItcMessage Message instance
 * @param pclUserData User data
 */
auto ItcMessaging::reply(ItcMessage & clItcMessage, std::shared_ptr<ItcObject> pclUserData) -> void
{
	if (clItcMessage.getMessageInfo().getMessageType() != ItcMessageType::REQUEST) {
		throw VP_EXCEPTION_FAILURE("Wrong message type [exp:"
			+  ItcEnumStr::ItcMessageType::toString(ItcMessageType::REQUEST)
			+ " real:"
			+  ItcEnumStr::ItcMessageType::toString(clItcMessage.getMessageInfo().getMessageType())
			+ "]");
	}
	if (clItcMessage.getReplyQueue() == nullptr) {
		throw VP_EXCEPTION_FAILURE("Reply queue is nullptr");
	}
	clItcMessage.getReplyQueue()->enqueue(pclUserData);
}

}