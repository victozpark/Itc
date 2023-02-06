#ifndef __ITC_CTX_HPP__
#define __ITC_CTX_HPP__

#include "ItcDef.hpp"
#include "ItcConditionQueue.hpp"
#include "ItcMessage.hpp"

namespace vp {

class ItcCtx
{
public:
	ItcCtx();
	virtual ~ItcCtx();

	auto addTopicQueue(const std::string &strTopic, std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcMessage>>> sclQueue) -> void;
	auto getGetQueueByTopic(const std::string &strTopic) -> std::vector<std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcMessage>>>>;
	auto getGetQueueByTopicOne(const std::string &strTopic) -> std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcMessage>>>;

private:
	std::unordered_map<
		std::string,
		std::vector<std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcMessage>>>>
	> m_mapTopicMap;
	 std::mutex m_mutTopicMutex;
};

}

#endif // __ITC_CTX_HPP__