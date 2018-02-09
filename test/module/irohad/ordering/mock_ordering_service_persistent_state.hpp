/**
 * Copyright Soramitsu Co., Ltd. 2018 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef IROHA_MOCK_ORDERING_SERVICE_PERSISTENT_STATE_HPP
#define IROHA_MOCK_ORDERING_SERVICE_PERSISTENT_STATE_HPP

#include "ametsuchi/ordering_service_persistent_state.hpp"

class MockOrderingServicePersistentState
    : public iroha::ametsuchi::OrderingServicePersistentState {
 public:
  /**
   * Save proposal height
   */
  virtual bool saveProposalHeight(size_t height) {
    height_ = height;
    return true;
  }

  /**
   * Load proposal height
   */
  virtual boost::optional<size_t> loadProposalHeight() const {
    return boost::optional<size_t>(height_);
  }

 private:
  /**
   * Initial height is 2 (1 for genesis block).
   */
  size_t height_ = 2;
};

#endif  // IROHA_MOCK_ORDERING_SERVICE_PERSISTENT_STATE_HPP
