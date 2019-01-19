-- premake5.lua
workspace "opengl"
   configurations { "Debug", "Release" }

project "opengl-tutorial"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

  -- platforms { "Win32", "Win64", "linux" }

 --  filter { "platforms:Win32" }
   -- system "Windows"
    --architecture "x32"
    ---links { "wsock32", "Mingw32","SDL2Main", "SDL2" }

    --filter { "platforms:Win64" }
    --system "Windows"
    --architecture "x64"
    --links { "wsock32", "Mingw32","SDL2Main", "SDL2" }

--filter { "platforms:linux" }
  --  system "linux"
    links { "SDL2" ,"dl"}


   ---links { "wsock32", "Mingw32","SDL2Main", "SDL2" }
   files { "**.h", "**.cpp", "**.c" }
   defines({"SQLITE_THREADSAFE=1"})
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"