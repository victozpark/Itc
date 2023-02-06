#ifndef __ITC_CONDITION_QUEUE_HPP__
#define __ITC_CONDITION_QUEUE_HPP__

#include <queue>
#include <mutex>
#include <condition_variable>

namespace vp {

template<class T>
class ItcConditionQueue
{
public:
	ItcConditionQueue();
	virtual ~ItcConditionQueue();

	auto operator=(const ItcConditionQueue& rhs) -> ItcConditionQueue& = delete;
	auto operator=(ItcConditionQueue&& rhs) -> ItcConditionQueue& = delete;

	auto enqueue(const T& clData) -> int;
	auto dequeue(int nTimeoutMs) -> T;
	auto dequeue(std::size_t nMaxCnt, int nTimeoutMs, std::vector<T>& vecRet) -> std::size_t;

	auto getQueueCount() -> int;
	auto isEmpty() -> bool;
private:
	std::queue<T> m_queDataQueue;	
	std::mutex m_mutQueueMutex;
	std::condition_variable m_cvConditionVriable;
};

}

#include "ItcConditionQueueTmpl.hpp"

#endif // __ITC_CONDITION_QUEUE_HPP_