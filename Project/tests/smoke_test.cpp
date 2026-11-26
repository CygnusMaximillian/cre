#include "agent_storage/storage_engine.h"

#include <cassert>
#include <string_view>

int main() {
    assert(agent_storage::project_name() == std::string_view{"agent-aware-storage"});
    return 0;
}
