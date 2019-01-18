-- premake5.lua
workspace "opengl"
   configurations { "Debug", "Release" }

project "opengl-tutorial"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   links { "wsock32", "Mingw32","SDL2Main", "SDL2" }
   files { "**.h", "**.cpp", "**.c" }
   defines({"SQLITE_THREADSAFE=1"})
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"