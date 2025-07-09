workspace"YaoEngine"
 startproject"YaoEidtor"
 location"YaoEngine"
 
 

 configurations{
    "Debug",
    "Release"
    }
 platforms{
    "x64",
    "linux",
    "macosx"
    }
group"YaoEngine Dependencies"
    include"YaoEngine/YaoEngine/vendor/GlFW/GLFW.lua"
    include"YaoEngine/YaoEngine/vendor/glad/glad.lua"
    include"YaoEngine/YaoEngine/vendor/imgui/imgui.lua"
    include"YaoEngine/YaoEngine/vendor/yaml-cpp/yaml.lua"
group""

group "Dependencies"
 include"YaoEngine/YaoEngine.lua"
group""

group""
 include"YaoEngine/YaoEidtor.lua"
group""