#include "ItcMessageInfo.hpp"

namespace vp {

/**
 * @brief Set topic name
 * 
 * @param strTopic Topic name
 */
auto ItcMessageInfo::setTopic(const std::string & strTopic) -> void
{
	m_strTopic = strTopic;
}

/**
 * @brief Get topic name
 * 
 * @return const std::string& Topic name
 */
auto ItcMessageInfo::getTopic() const -> const std::string &
{
	return m_strTopic;
}

/**
 * @brief Set message type
 * 
 * @param eMessageType Message type
 */
auto ItcMessageInfo::setMessageType(const ItcMessageType & eMessageType) -> void
{
	m_eMessageType = eMessageType;
}

/**
 * @brief Get message type
 * 
 * @return const ItcMessageType& Message type
 */
auto ItcMessageInfo::getMessageType() const -> const ItcMessageType &
{
	return m_eMessageType;
}

}