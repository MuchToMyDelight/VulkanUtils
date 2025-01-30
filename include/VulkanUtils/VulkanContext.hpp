#pragma once

#include <cstdint>
#include <stdexcept>
#include "vulkan/vulkan.hpp"
#include "vulkan/vulkan_raii.hpp"

namespace VulkanUtils {

template<typename Derived>
struct VulkanContextImpl {
  void init() {
    vk::ApplicationInfo appInfo {d().appName(), 0, d().engineName(), 0, d().apiVersion();}
    auto layers = d().enableLayers(), exts = d().enableExtensions();
    vk::InstanceCreateInfo insInfo {vk::InstanceCreateFlags(), &appInfo, layers.size(), layers.data(), exts.size(), exts.data()};
    instance_ = vk::raii::Intance{context_, insInfo};
    physicalDevice_ = d().selectPhysicalDevice(instance_.enmueratePhysicalDevices());
    auto queueId = selectComputeQueueFamilyId(physicalDevice_.getQueueFamilyProperties());

    vk::DeviceQueueCreateInfo queueCreateInfo {};
    vk::DeviceCreateInfo deviceCreateInfo {};
    device_ = vk::raii::Device {physicalDevice_, deviceCreateInfo};
  }

  Derived& d() { return static_cast<Derived&>(*this); }

  // override functions below if needed
  uint32_t apiVersion() { return VK_API_VERSION_1_4; }
  bool selectPhysicalDevice(std::vector<vk::raii::PhysicalDevice> const vec) {
    if (vec.empty()) throw std::runtime_error("Cannot find any Vulkan physical device");
    return vec[0];
  }
  size_t selectComputeQueueFamilyId() {
    //
  }
  std::vector<char const *> enabledLayers() {  return {};}
  std::vector<char const *> enabledExtensions() { return {};}

  // some trival functions, usually just use the default ones
  char const * appName() { return "the app name";}
  char const *engineName() { return "no engine";}

  vk::raii::Context  context_;
  vk::raii::Instance instance_;
  vk::raii::PhysicalDevice physicalDevice_;
  vk::raii::Device  device_;

};

}