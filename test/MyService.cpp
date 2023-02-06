#include "MyService.hpp"
#include "MyMessage.hpp"
#include <iostream>

auto MyService::onMessageReceived(const vp::ItcMessageInfo & clMessageInfo, const vp::ItcObject & clUserData) -> void
{
	std::cout << "onMessageReceived" << std::endl;

	const MyMessage & msg = static_cast<const MyMessage&>(clUserData);
	if (msg.getMessageId() == "MyTTT") {
		thread_local long long llCnt = 0;
		llCnt++;

		const MyTTT & msg = static_cast<const MyTTT&>(clUserData);
		std::cout << msg.getData() << std::endl;

		if (clMessageInfo.getMessageType() == vp::ItcMessageType::REQUEST) {
			char zTmp[1024];
			snprintf(zTmp, sizeof(zTmp), "REPLY-->%010lld", llCnt);
			auto rplMsg = std::make_shared<MyTTT>();
			rplMsg->setMessageId(msg.getMessageId());
			rplMsg->setData(zTmp);
			replyMessage(rplMsg);
		}
	}
	else {
		std::cout << msg.getMessageId() << std::endl;
	}

}