project"YaoEidtor"
    location"YaoEidtor"
    language"C++"
    kind"ConsoleApp"
    cppdialect"C++17"


    targetdir"%{wksname}/bin/%{prj.name}%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    objdir"%{wksname}/bin-int/%{prj.name}%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


    files{
        "YaoEidtor/source/**.cpp",
        "YaoEidtor/source/**.h",
        "YaoEidtor/source/**.hpp",
        "YaoEidtor/source/**.c",
        "YaoEngine/Shader/glsl/**.weiyao",
    }

    includedirs{
        "YaoEngine/source",
        "YaoEngine/vendor/GLFW/include",
        "YaoEngine/vendor/glad/include",
        "YaoEngine/vendor/glm",
        "YaoEngine/vendor/entt/src/entt",
        "YaoEngine/vendor/ImGuizmo",
        "YaoEngine/vendor/imgui",
        "YaoEngine/vendor/yaml-cpp/include",
    }

    links{
        "YaoEngine",

    }


    filter"configurations:Debug"
        defines{"DEBUG"}
        symbols"On"


    filter"configurations:Release"
        defines{"NDEBUG"}
        optimize"On"


    filter "system:windows"
		systemversion "latest"
		buildoptions {"/utf-8"}
