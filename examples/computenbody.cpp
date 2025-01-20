#include "VulkanUtils/VulkanContext.hpp"

namespace {
struct MyVulkanContext: public VulkanUtils::VulkanContextImpl<MyVulkanContext> {
  char const * appName() { return "compute: n body";}
};
}

int main() {
  MyVulkanContext context;
  context.init();

  return 0;
}