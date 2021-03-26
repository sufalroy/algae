project "algae"
	kind "none"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"


	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin/intermediates/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.hpp"
	}

	includedirs
	{
		"src/"
	}

	defines
	{
	
	}

	
	filter "system:windows"
		systemversion "latest"
	
		defines 
		{
	
		}

		buildoptions
		{
			"/MP", "/bigobj"
		}


	filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
