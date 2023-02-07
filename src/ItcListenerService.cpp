
#include "ItcListenerService.hpp"
#include "ItcMessaging.hpp"

namespace vp {

/**
 * @brief Reply message
 * 
 * @param sclUserData 
 */
auto ItcListenerService::replyMessage(std::shared_ptr<ItcObject> sclUserData) -> void
{
	ItcMessaging clMsgg(m_sclItc);
	clMsgg.reply(*m_sclItcMessage, sclUserData);
}

/**
 * @brief Send message
 * 
 * @param strTopic Topic name
 * @param sclUserData User data
 */
auto ItcListenerService::sendMessage(const std::string &strTopic, std::shared_ptr<ItcObject> sclUserData) -> void
{
	ItcMessaging clMsgg(m_sclItc);
	clMsgg.send(strTopic, sclUserData);
}

/**
 * @brief Request message (to only one listener of a topic, except listenting topics by the listener)
 * 
 * @param strTopic  Topic name
 * @param sclUserData User data
 * @param nTimeoutMs Timeout (milliseconds)
 * @return std::shared_ptr<ItcObject> User data
 */
auto ItcListenerService::requestOneMessage(const std::string &strTopic, std::shared_ptr<ItcObject> sclUserData, int nTimeoutMs) -> std::shared_ptr<ItcObject>
{
	auto it = m_setTopic.find(strTopic);
	if (it != m_setTopic.end()) {
		throw VP_EXCEPTION_FAILURE("The topic (" + strTopic + ") is listeneing int the current listner");
	}

	ItcMessaging clMsgg(m_sclItc);
	auto clRet = clMsgg.requestOne(strTopic, sclUserData, nTimeoutMs);

	return clRet;
}

/**
 * @brief Add listening topic by the listener
 * 
 * @param strTopic Topic name
 */
auto ItcListenerService::addListeningTopic(const std::string& strTopic) -> void
{
	m_setTopic.insert(strTopic);
}

/**
 * @brief Set Itc instance
 * 
 * @param sclItc Itc instance
 */
auto ItcListenerService::setItc(std::shared_ptr<Itc> sclItc) -> void
{
	m_sclItc = sclItc;
}

/**
 * @brief Set ItcMessage
 * 
 * @param sclItcMessage ItcMessage
 */
auto ItcListenerService::setItcMessage(std::shared_ptr<ItcMessage> sclItcMessage) -> void
{
	m_sclItcMessage = sclItcMessage;
}

}