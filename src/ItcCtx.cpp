#include "ItcCtx.hpp"
#include <iostream>
#include <chrono>

namespace vp {

/**
 * @brief Construct a new Itc Ctx:: Itc Ctx object
 * 
 */
ItcCtx::ItcCtx()
{
}

/**
 * @brief Destroy the Itc Ctx:: Itc Ctx object
 * 
 */
ItcCtx::~ItcCtx()
{
}

/**
 * @brief Add a ItcCondtionQueue of a topic
 * 
 * @param strTopic Topic name
 * @param sclQueue ItcConditionQueue
 * @todo Check topic duplication
 */
auto ItcCtx::addTopicQueue(const std::string &strTopic, std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcMessage>>> sclQueue) -> void
{
	std::unique_lock<std::mutex> lock(m_mutTopicMutex);
	m_mapTopicMap[strTopic].push_back(sclQueue);
}

/**
 * @brief Get ItcConditionQueues of a topic
 * 
 * @param strTopic Topic name
 * @return std::vector<std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcMessage>>>> 
 */
auto ItcCtx::getGetQueueByTopic(const std::string &strTopic) -> std::vector<std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcMessage>>>>
{
	std::unique_lock<std::mutex> lock(m_mutTopicMutex);

	auto it = m_mapTopicMap.find(strTopic);
	if (it==m_mapTopicMap.end()) {
		throw VP_EXCEPTION_NOTFOUND("No topic (" + strTopic + ") exists");
	}
	auto vecRet = it->second;

	return vecRet;
}

/**
 * @brief Get one ItcConditoinQueue of a topic
 * 
 * @param strTopic Topic name
 * @return std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcMessage>>> 
 */
auto ItcCtx::getGetQueueByTopicOne(const std::string &strTopic) -> std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcMessage>>>
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto nano = std::chrono::duration_cast<std::chrono::nanoseconds>(duration) / 1000;

	std::unique_lock<std::mutex> lock(m_mutTopicMutex);

	auto it = m_mapTopicMap.find(strTopic);
	if (it==m_mapTopicMap.end()) {
		throw VP_EXCEPTION_NOTFOUND("No topic (" + strTopic + ") exists");
	}

	auto vecQueue = it->second;
	long long idx = nano.count() % vecQueue.size();
	auto sclRet = vecQueue[(int)idx];

	return sclRet;
}

}
