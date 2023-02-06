#ifndef __ITC_LISTENER_HPP__
#define __ITC_LISTENER_HPP__

#include "ItcDef.hpp"
#include "ItcConditionQueue.hpp"

#include "Itc.hpp"
#include "ItcListenerService.hpp"

namespace vp {

class ItcListener
{
public:
	ItcListener(std::shared_ptr<Itc> sclItc);

	auto addListenTopic(const std::string& strTopic) -> void;
	auto initialize() -> void;
	auto run() -> void;
	
	auto setListenerService(std::shared_ptr<ItcListenerService> sclListenerService) -> void;

private:
	std::shared_ptr<Itc> m_sclItc;
	std::shared_ptr<ItcListenerService> m_sclListenerService;
	std::shared_ptr<ItcConditionQueue<std::shared_ptr<ItcMessage>>> m_sclConditionQueue;
	std::vector<std::string> m_vecTopic;
};

}

#endif // __ITC_LISTENER_HPP__