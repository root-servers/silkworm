/*
   Copyright 2020 The Silkworm Authors

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef SILKWORM_STATE_SUBSTATE_H_
#define SILKWORM_STATE_SUBSTATE_H_

#include <stdint.h>

#include <silkworm/types/log.hpp>
#include <unordered_set>
#include <vector>

namespace silkworm {

// See Section 6.1 "Substate" of the Yellow Paper.
class Substate {
 public:
  Substate(const Substate&) = default;
  Substate& operator=(const Substate&) = default;

  std::unordered_set<evmc::address> self_destructs;
  std::vector<Log> logs;
  // TODO[Spurious Dragon] touched accounts
  uint64_t refund{0};

  uint64_t total_refund() const;

  void clear();
};
}  // namespace silkworm

#endif  // SILKWORM_STATE_SUBSTATE_H_
