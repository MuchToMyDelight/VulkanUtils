#pragma once

#include "vulkan/vulkan_raii.hpp"

namespace VulkanUtils {

template<typename Derived>
struct VulkanContextImpl {
  void init() {
    // TODO
  }
  Derived& d() { return static_cast<Derived&>(*this); }

  char const * appName() { return "the app name";}
  bool selectDevice(vk::Device const &) { return true;}
};

}