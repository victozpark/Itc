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