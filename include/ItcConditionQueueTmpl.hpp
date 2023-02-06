#ifndef __ITC_CONDITION_QUEUE_TMPL_HPP__
#define __ITC_CONDITION_QUEUE_TMPL_HPP__

#include <queue>
#include <mutex>
#include <condition_variable>

#include "ItcConditionQueue.hpp"

namespace vp {

template<class T>
ItcConditionQueue<T>::ItcConditionQueue()
{
}

template<class T>
ItcConditionQueue<T>::~ItcConditionQueue()
{
}

template<class T>
auto ItcConditionQueue<T>::enqueue(const T& clData) -> int
{
	std::unique_lock<std::mutex> lock(m_mutQueueMutex);

	m_queDataQueue.push(clData);

	m_cvConditionVriable.notify_all();

	return 1; // Enqueue count is 1
}

template<class T>
auto ItcConditionQueue<T>::dequeue(int nTimeoutMs) -> T
{
	std::chrono::milliseconds cnTimeout(nTimeoutMs);

	std::unique_lock<std::mutex> lock(m_mutQueueMutex);

	if (m_queDataQueue.empty()) {
		auto sttRet = m_cvConditionVriable.wait_for(lock, cnTimeout);
		if (sttRet == std::cv_status::timeout) {
			throw VP_EXCEPTION_TIMEOUT("Timoeout : No data available for " + std::to_string(nTimeoutMs) + " ms");
		}
	}
	auto clRet = m_queDataQueue.front();
	m_queDataQueue.pop();

	return clRet;
}

template<class T>
auto ItcConditionQueue<T>::dequeue(std::size_t nMaxCnt, int nTimeoutMs, std::vector<T>& vecRet) -> std::size_t 
{
	std::chrono::milliseconds cnTimeout(nTimeoutMs);

	std::unique_lock<std::mutex> lock(m_mutQueueMutex);

	if (m_queDataQueue.empty()) {
		auto sttRet = m_cvConditionVriable.wait_for(lock, cnTimeout);
		if (sttRet == std::cv_status::timeout) {
			throw VP_EXCEPTION_TIMEOUT("Timoeout : No data available for " + std::to_string(nTimeoutMs) + " ms");
		}
	}

	int nCnt = 0;
	for (std::size_t i=0; i<nMaxCnt && !m_queDataQueue.empty(); i++) {
		vecRet.push_back(m_queDataQueue.front());
		m_queDataQueue.pop();
		nCnt++;
	}

	return nCnt;
}

template<class T>
auto ItcConditionQueue<T>::getQueueCount() -> int
{
	std::unique_lock<std::mutex> lock(m_mutQueueMutex);

	return m_queDataQueue.size();
}

template<class T>
auto ItcConditionQueue<T>::isEmpty() -> bool
{
	std::unique_lock<std::mutex> lock(m_mutQueueMutex);

	return m_queDataQueue.empty();
}

}

#endif // __ITC_CONDITION_QUEUE_TMPL_HPP__