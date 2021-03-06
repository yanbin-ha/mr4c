/**
  * Copyright 2014 Google Inc. All rights reserved.
  * 
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *     http://www.apache.org/licenses/LICENSE-2.0
  * 
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
*/

#ifndef __MR4C_SIMPLE_DATA_FILE_SOURCE_H__
#define __MR4C_SIMPLE_DATA_FILE_SOURCE_H__

#include <string>

namespace MR4C {


class SimpleDataFileSourceImpl;

class SimpleDataFileSource : public DataFileSource {

	public:

		SimpleDataFileSource(char* bytes, size_t size, DataFile::Allocation alloc = DataFile::NEW);

		char* getFileBytes() const;

		size_t getFileSize() const;

		size_t read(char* buf, size_t num);

		size_t skip(size_t num);

		void release();

		bool isReleased() const;

		~SimpleDataFileSource();

	private:

		SimpleDataFileSourceImpl* m_impl;

		// prevent calling these
		SimpleDataFileSource();
		SimpleDataFileSource(const SimpleDataFileSource& src);
		SimpleDataFileSource& operator=(const SimpleDataFileSource& src);
};

}
#endif


