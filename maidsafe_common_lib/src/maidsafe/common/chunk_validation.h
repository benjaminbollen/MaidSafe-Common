/* Copyright (c) 2011 maidsafe.net limited
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
    * Neither the name of the maidsafe.net limited nor the names of its
    contributors may be used to endorse or promote products derived from this
    software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * @file chunk_validation.h
 * @brief Declaration of ChunkValidation interface.
 */

#ifndef MAIDSAFE_COMMON_CHUNK_VALIDATION_H_
#define MAIDSAFE_COMMON_CHUNK_VALIDATION_H_

#include <string>
#include "boost/filesystem/path.hpp"
#include "maidsafe/common/version.h"

#if MAIDSAFE_COMMON_VERSION != 1004
#  error This API is not compatible with the installed library.\
    Please update the MaidSafe-Common library.
#endif


namespace fs = boost::filesystem;

namespace maidsafe {

/**
 * Abstract class to validate chunks.
 *
 * Implementations will need to be aware of different chunk types and their
 * inherent validity.
 */
class ChunkValidation {
 public:
  ChunkValidation() {}
  virtual ~ChunkValidation() {}

  /**
   * Checks if a chunk's name is in a valid, known format.
   * @param name Chunk name
   * @return Whether chunk name is valid.
   */
  virtual bool ValidName(const std::string &name) = 0;

  /**
   * Checks if the hash of a chunk's content is supposed to match its name.
   * @param name Chunk name
   * @return Whether chunk is hashable.
   */
  virtual bool Hashable(const std::string &name) = 0;

  /**
   * Checks if a chunk is valid.
   * @param name Chunk name
   * @param content Chunk's content as string.
   * @return Whether chunk is valid.
   */
  virtual bool ValidChunk(const std::string &name,
                          const std::string &content) = 0;

  /**
   * Checks if a chunk is valid.
   * @param name Chunk name
   * @param path Path to chunk's content.
   * @return Whether chunk is valid.
   */
  virtual bool ValidChunk(const std::string &name, const fs::path &path) = 0;

 private:
  ChunkValidation(const ChunkValidation&);
  ChunkValidation& operator=(const ChunkValidation&);
};

}  // namespace maidsafe

#endif  // MAIDSAFE_COMMON_CHUNK_VALIDATION_H_