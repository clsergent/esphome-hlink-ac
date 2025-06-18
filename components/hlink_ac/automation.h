#pragma once

#include "esphome/core/automation.h"
#include "hlink_ac.h"

namespace esphome {
namespace hlink_ac {
template<typename... Ts> class HlinkAcSendHlinkCmd : public Action<Ts...>, public Parented<HlinkAc> {
 public:
  TEMPLATABLE_VALUE(std::string, address)
  TEMPLATABLE_VALUE(std::string, data)

  void play(Ts... x) override {
    auto address = this->address_.value(x...);
    auto data = this->data_.value(x...);
    this->parent_->send_hlink_cmd(address, data);
  }
};
template<typename... Ts> class HlinkAcSendHlinkRequest : public Action<Ts...>, public Parented<HlinkAc> {
 public:
  TEMPLATABLE_VALUE(std::string, address)

  void play(Ts... x) override {
    auto address = this->address_.value(x...);
    this->parent_->send_hlink_request(address);
  }
};
}  // namespace hlink_ac
}  // namespace esphome