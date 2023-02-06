#include "ItcMessage.hpp"

namespace vp {

/**
 * @brief Get message information
 * 
 * @return ItcMessageInfo& 
 */
auto ItcMessage::getMessageInfo() -> ItcMessageInfo &
{
	return m_clMessageInfo;
}

/**
 * @brief Set ConditinonQueue for reply-message
 * 
 * @param sclReplyQueue ConditionQueue
 */
auto ItcMessage::setReplyQueue(std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcObject>>> sclReplyQueue) -> void
{
	m_sclReplyQueue = sclReplyQueue;
}

/**
 * @brief Get conditionQueue for reply-message
 * 
 * @return std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcObject>>> ConditionQueue
 */
auto ItcMessage::getReplyQueue() -> std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcObject>>>
{
	return m_sclReplyQueue;
}

/**
 * @brief Set user data
 * 
 * @param sclUserData User data
 */
auto ItcMessage::setUserdata(std::shared_ptr<ItcObject> sclUserData) -> void
{
	m_sclUserData = sclUserData;
}

/**
 * @brief Get user data
 * 
 * @return std::shared_ptr<ItcObject> User data
 */
auto ItcMessage::getUserdata() -> std::shared_ptr<ItcObject>
{
	return m_sclUserData;
}

}