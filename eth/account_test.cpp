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

#include "account.hpp"

#include <sstream>

#include "../tests/catch.hpp"

namespace silkworm {

TEST_CASE("account", "[rlp]") {
  using namespace evmc::literals;

  eth::Account account{
      .nonce = 12,
      .balance = 200 * eth::kEther,
      .storage_root = 0xdde806bc028ddb3c73ddfbe1e19676224198e5d2cb205edb40e26da2a5310d5f_bytes32,
      .code_hash = 0x12580ee5fc5ea05a1a19a93cbc51830ae3607690b7c4a6996ea211aba5a966b2_bytes32,
  };

  std::ostringstream to;
  rlp::encode(to, account);

  std::istringstream from{to.str()};
  eth::Account decoded = rlp::decode_account(from);
  CHECK(decoded == account);
}
}  // namespace silkworm
