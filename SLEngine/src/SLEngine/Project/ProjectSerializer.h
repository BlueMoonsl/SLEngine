#pragma once

#include "Project.h"

namespace SLEngine {

	class ProjectSerializer
	{
	public:
		ProjectSerializer(Ref<Project> project);

		bool Serialize(const std::filesystem::path& filepath);
		bool Deserialize(const std::filesystem::path& filepath);
	private:
		Ref<Project> m_Project;
	};

}
