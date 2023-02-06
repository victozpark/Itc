#ifndef __ITC_MESSAGING_HPP__
#define __ITC_MESSAGING_HPP__

#include "ItcDef.hpp"
#include "Itc.hpp"

namespace vp {

class ItcMessaging
{
public:
	ItcMessaging(std::shared_ptr<Itc> sclItc);
	auto send(const std::string & strTopic, std::shared_ptr<ItcObject> pclUserData) -> void;
	auto sendOne(const std::string & strTopic, std::shared_ptr<ItcObject> pclUserData) -> void;
	auto requestOne(const std::string & strTopic, std::shared_ptr<ItcObject> pclUserData, int nTimeout) -> std::shared_ptr<ItcObject>;
	auto reply(ItcMessage & clItcMessage, std::shared_ptr<ItcObject> pclUserData) -> void;

private:
	std::shared_ptr<Itc> m_sclItc;
};

}

#endif // __ITC_MESSAGING_HPP__