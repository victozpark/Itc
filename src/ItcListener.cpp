#include <algorithm>

#include "ItcListener.hpp"

namespace vp {

/**
 * @brief Construct a new Itc Listener:: Itc Listener object
 * 
 * @param sclItc Itc instance
 */
ItcListener::ItcListener(std::shared_ptr<Itc> sclItc) : m_sclItc(sclItc)
{
}

/**
 * @brief Add a topic to listen
 * 
 * @param strTopic Topic name
 */
auto ItcListener::addListenTopic(const std::string &strTopic) -> void
{
	auto it = std::find(m_vecTopic.begin(), m_vecTopic.end(), strTopic);
	if (it != m_vecTopic.end()) {
		// Alread exists
		throw VP_EXCEPTION_DUPLICATED("This topic (" + strTopic + ") already exists");
	}

	m_vecTopic.push_back(strTopic);
}

/**
 * @brief Initialization
 * 
 */
auto ItcListener::initialize() -> void
{
	m_sclConditionQueue = std::make_shared<ItcConditionQueue<std::shared_ptr<ItcMessage>>>();

	for (auto it=m_vecTopic.begin(); it!=m_vecTopic.end(); it++) {
		m_sclItc->getCtx()->addTopicQueue(*it, m_sclConditionQueue);
	}

}

/**
 * @brief Start listening
 * 
 */
auto ItcListener::run() -> void
{
	m_sclListenerService->setItc(m_sclItc);
	while (true)
	{
		std::vector<std::shared_ptr<ItcMessage>> vecRet;

		try {
			int nRet = m_sclConditionQueue->dequeue(10, 10000, vecRet);
			if (nRet == 0) continue;
		}
		catch(vp::ItcExceptionTimeout& ex) {
			continue;
		}
		for (auto it=vecRet.begin(); it!=vecRet.end(); it++) {
			m_sclListenerService->setItcMessage(*it);

			auto sclUserData = it->get()->getUserdata();
			m_sclListenerService->onMessageReceived(it->get()->getMessageInfo(), *sclUserData);
			m_sclListenerService->setItcMessage(nullptr);
		}
	}
}

/**
 * @brief Set a listener service
 * 
 * @param sclListenerService Listener service
 */
auto ItcListener::setListenerService(std::shared_ptr<ItcListenerService> sclListenerService) -> void
{
	m_sclListenerService = sclListenerService;
}

}