#include "ItcListenerService.hpp"

class MyService : public vp::ItcListenerService
{
public:
	virtual auto onMessageReceived(const vp::ItcMessageInfo & clMessageInfo, const vp::ItcObject & clUserData) -> void;
};