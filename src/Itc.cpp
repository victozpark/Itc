#include "Itc.hpp"

namespace vp {

/**
 * @brief Initialization
 * 
 */
auto Itc::initialize() -> void
{

}

/**
 * @brief Set ItcCtx
 * 
 * @param sclCtx 
 */
auto Itc::setCtx(std::shared_ptr<ItcCtx> sclCtx) -> void
{
	m_sclCtx = sclCtx;
}

/**
 * @brief Get ItxCtx
 * 
 * @return std::shared_ptr<ItcCtx> 
 */
auto Itc::getCtx() -> std::shared_ptr<ItcCtx>
{
	return m_sclCtx;
}

}