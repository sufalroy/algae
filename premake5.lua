include "./premake/premake_customization/solution_items.lua"

workspace "algae"
	architecture "x86_64"
	startproject "test"

	configurations
	{
		"Debug",
		"Release"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


include "algae"
include "test"
