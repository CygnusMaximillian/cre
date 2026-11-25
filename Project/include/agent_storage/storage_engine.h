#pragma once

#include <string_view>

namespace agent_storage {

[[nodiscard]] constexpr std::string_view project_name() noexcept {
    return "agent-aware-storage";
}

} // namespace agent_storage
