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

#ifndef SILKWORM_ETH_CONFIG_H_
#define SILKWORM_ETH_CONFIG_H_

#include <stdint.h>

#include <optional>

namespace silkworm::eth {

struct ChainConfig {
  // https://eips.ethereum.org/EIPS/eip-155
  uint64_t chain_id{0};

  // https://eips.ethereum.org/EIPS/eip-606
  std::optional<uint64_t> homestead_block;

  // https://eips.ethereum.org/EIPS/eip-779
  std::optional<uint64_t> dao_block;

  // https://eips.ethereum.org/EIPS/eip-608
  // https://ecips.ethereumclassic.org/ECIPs/ecip-1015
  std::optional<uint64_t> tangerine_whistle_block;

  // TODO (Andrew) EIP-160 was applied to ETC before the rest of Spurious Dragon; see
  // https://ecips.ethereumclassic.org/ECIPs/ecip-1066

  // https://eips.ethereum.org/EIPS/eip-607
  // https://ecips.ethereumclassic.org/ECIPs/ecip-1054
  std::optional<uint64_t> spurious_dragon_block;

  // https://eips.ethereum.org/EIPS/eip-609
  // https://ecips.ethereumclassic.org/ECIPs/ecip-1054
  std::optional<uint64_t> byzantium_block;

  // https://eips.ethereum.org/EIPS/eip-1013
  // https://ecips.ethereumclassic.org/ECIPs/ecip-1056
  std::optional<uint64_t> constantinople_block;

  // https://eips.ethereum.org/EIPS/eip-1716
  // https://ecips.ethereumclassic.org/ECIPs/ecip-1056
  std::optional<uint64_t> petersburg_block;

  // https://eips.ethereum.org/EIPS/eip-1679
  // https://ecips.ethereumclassic.org/ECIPs/ecip-1088
  std::optional<uint64_t> istanbul_block;

  // https://eips.ethereum.org/EIPS/eip-2387
  std::optional<uint64_t> muir_glacier_block;

  // TODO(Andrew)
  // https://ecips.ethereumclassic.org/ECIPs/ecip-1017

  bool has_homestead(uint64_t block_num) const noexcept {
    return homestead_block.has_value() && homestead_block <= block_num;
  }

  bool has_tangerine_whistle(uint64_t block_num) const noexcept {
    return tangerine_whistle_block.has_value() && tangerine_whistle_block <= block_num;
  }

  bool has_spurious_dragon(uint64_t block_num) const noexcept {
    return spurious_dragon_block.has_value() && spurious_dragon_block <= block_num;
  }

  bool has_byzantium(uint64_t block_num) const noexcept {
    return byzantium_block.has_value() && byzantium_block <= block_num;
  }

  bool has_constantinople(uint64_t block_num) const noexcept {
    return constantinople_block.has_value() && constantinople_block <= block_num;
  }

  bool has_petersburg(uint64_t block_num) const noexcept {
    return petersburg_block.has_value() && petersburg_block <= block_num;
  }

  bool has_istanbul(uint64_t block_num) const noexcept {
    return istanbul_block.has_value() && istanbul_block <= block_num;
  }
};

constexpr ChainConfig kEthMainnetChainConfig{
    .chain_id = 1,

    .homestead_block = 1'150'000,
    .dao_block = 1'920'000,
    .tangerine_whistle_block = 2'463'000,
    .spurious_dragon_block = 2'675'000,
    .byzantium_block = 4'370'000,
    .constantinople_block = 7'280'000,
    .petersburg_block = 7'280'000,
    .istanbul_block = 9'069'000,
    .muir_glacier_block = 9'200'000,
};

// https://ecips.ethereumclassic.org/ECIPs/ecip-1066
constexpr ChainConfig kEtcMainnetChainConfig{
    .chain_id = 61,

    .homestead_block = 1'150'000,
    .dao_block = {},
    .tangerine_whistle_block = 2'500'000,
    .spurious_dragon_block = 8'772'000,
    .byzantium_block = 8'772'000,
    .constantinople_block = 9'573'000,
    .petersburg_block = 9'573'000,
    .istanbul_block = 10'500'839,
};
}  // namespace silkworm::eth

#endif  // SILKWORM_ETH_CONFIG_H_
