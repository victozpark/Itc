#ifndef __ITC_HPP__
#define __ITC_HPP__

#include "ItcDef.hpp"
#include "ItcCtx.hpp"

namespace vp {

class Itc
{
public:
	auto initialize() -> void;

	auto setCtx(std::shared_ptr<ItcCtx> sclCtx) -> void;
	auto getCtx() -> std::shared_ptr<ItcCtx>;

private:
	std::shared_ptr<ItcCtx> m_sclCtx;
};

}

#endif // __ITC_HPP__