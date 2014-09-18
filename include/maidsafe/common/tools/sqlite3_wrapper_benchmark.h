/*  Copyright 2014 MaidSafe.net limited

    This MaidSafe Software is licensed to you under (1) the MaidSafe.net Commercial License,
    version 1.0 or later, or (2) The General Public License (GPL), version 3, depending on which
    licence you accepted on initial access to the Software (the "Licences").

    By contributing code to the MaidSafe Software, or to this project generally, you agree to be
    bound by the terms of the MaidSafe Contributor Agreement, version 1.0, found in the root
    directory of this project at LICENSE, COPYING and CONTRIBUTOR respectively and also
    available at: http://www.maidsafe.net/licenses

    Unless required by applicable law or agreed to in writing, the MaidSafe Software distributed
    under the GPL Licence is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS
    OF ANY KIND, either express or implied.

    See the Licences for the specific language governing permissions and limitations relating to
    use of the MaidSafe Software.                                                                 */

#ifndef MAIDSAFE_COMMON_TOOLS_SQLITE3_WRAPPER_BENCHMARK_H_
#define MAIDSAFE_COMMON_TOOLS_SQLITE3_WRAPPER_BENCHMARK_H_

#include <string>
#include <vector>

#include "boost/progress.hpp"

#include "maidsafe/common/log.h"
#include "maidsafe/common/sqlite3_wrapper.h"
#include "maidsafe/common/utils.h"

namespace maidsafe {

namespace benchmark {

class Sqlite3WrapperBenchmark {
 public:
  Sqlite3WrapperBenchmark();
  void Run();

 private:
  void EndpointStringsSingleTransaction();
  void EndpointStringsIndividualTransaction();

  void PrepareTable(sqlite::Database& database, std::string query);
  void CheckEndpointStringsTestResult(const std::vector<std::string>& expected_result,
                                      const std::vector<std::string>& result,
                                      bool check_content, bool check_order);

  void InsertEndpointStrings(sqlite::Database& database,
                             const std::vector<std::string>& endpoint_strings,
                             std::string query);
  void ReadEndpointStrings(std::vector<std::string>& result, std::string query);

  boost::filesystem::path database_path;
  boost::progress_timer ticking_clock;
  std::vector<std::string> ten_thousand_strings;
};

}  // namespace benchmark

}  // namespace maidsafe

#endif  // MAIDSAFE_COMMON_TOOLS_SQLITE3_WRAPPER_BENCHMARK_H_
