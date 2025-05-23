#pragma once

#include "SLEngine/Core/Buffer.h"

namespace SLEngine {

	class FileSystem
	{
	public:
		// TODO: move to FileSystem class
		static Buffer ReadFileBinary(const std::filesystem::path& filepath);
	};

}
