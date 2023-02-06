#include <iostream>
#include <thread>
#include <memory>

#include "ItcException.hpp"

#include "Itc.hpp"
#include "ItcCtx.hpp"
#include "ItcListener.hpp"

#include "ItcMessaging.hpp"
#include "ItcMessage.hpp"

#include "ItcListenerService.hpp"
#include "MyService.hpp"
#include "MyMessage.hpp"

void fnSender();
void fnReceiver1();
void fnReceiver2();

std::shared_ptr<vp::Itc> gsclItc = nullptr; // Itc instance

int main(void)
{
	auto sclItc = std::make_shared<vp::Itc>(); // Create Itc instance
	auto sclItcCtx = std::make_shared<vp::ItcCtx>(); // Create ItcCtx instnace
	sclItc->setCtx(sclItcCtx);

	// Set Itc instance as a global vaiable
	gsclItc = sclItc;

	// Create and start threads
	std::thread thrSender(fnSender);
	std::thread thrReceiver1(fnReceiver1);
	std::thread thrReceiver2(fnReceiver2);

	// Join threads
	thrSender.join();
	thrReceiver1.join();
	thrReceiver2.join();

	return 0;
}

void fnSender()
{
	vp::ItcMessaging clMsgg(gsclItc);

	char zTmp[1024];

	// send, request, sleep
	for (int i=0; ; i++) {
		//
		// Send message
		//

		// Create a message
		std::snprintf(zTmp, sizeof(zTmp), "%010d.%s", i, "TEST_MSG_SEND");
		auto data = std::make_shared<MyTTT>();
		data->setMessageId("MyTTT");
		data->setData(zTmp);

		// Send message
		try {
			clMsgg.send("TopicA", data);
		}
		catch (vp::ItcExceptionNotfound &e) {
			; // Do nothing
		}

		//
		// Request message
		//

		// Create a message
		std::snprintf(zTmp, sizeof(zTmp), "%010d.%s", i, "TEST_MSG_REQUEST");
		auto data2 = std::make_shared<MyTTT>();
		data2->setMessageId("MyTTT");
		data2->setData(zTmp);

		// Request and reply message
		try {
			auto replyMsg = clMsgg.requestOne("TopicA", data2, 10000);
			if (replyMsg != nullptr) {
				const MyMessage & msg = static_cast<const MyMessage&>(*replyMsg);
				if (msg.getMessageId() == "MyTTT") {
					const MyTTT & msg = static_cast<const MyTTT&>(*replyMsg);
					std::cout << msg.getData() << std::endl;
				}
			}
		}
		catch (vp::ItcExceptionNotfound &e) {
			; // Do nothing
		}

		// Sleep for 1s
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void fnReceiver1()
{
	// Create Listner instance
	auto lsnr = std::make_shared<vp::ItcListener>(gsclItc);
	lsnr->setListenerService(std::make_shared<MyService>());
	lsnr->addListenTopic("TopicA"); // Add listen topic
	lsnr->addListenTopic("TopicB"); // Add listen topic
	lsnr->initialize();

	lsnr->run(); // Run listener
}

void fnReceiver2()
{
	auto lsnr = std::make_shared<vp::ItcListener>(gsclItc);
	lsnr->setListenerService(std::make_shared<MyService>());
	lsnr->addListenTopic("TopicA"); // Add listen topic
	lsnr->initialize();

	lsnr->run(); // Run listener
}
