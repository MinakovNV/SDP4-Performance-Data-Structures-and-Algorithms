# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\asus.VENIK\CLionProjects\Ex4-6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\asus.VENIK\CLionProjects\Ex4-6\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Ex4_6.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Ex4_6.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Ex4_6.dir\flags.make

CMakeFiles\Ex4_6.dir\main.c.obj: CMakeFiles\Ex4_6.dir\flags.make
CMakeFiles\Ex4_6.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus.VENIK\CLionProjects\Ex4-6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Ex4_6.dir/main.c.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Ex4_6.dir\main.c.obj /FdCMakeFiles\Ex4_6.dir\ /FS -c C:\Users\asus.VENIK\CLionProjects\Ex4-6\main.c
<<

CMakeFiles\Ex4_6.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex4_6.dir/main.c.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\Ex4_6.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\asus.VENIK\CLionProjects\Ex4-6\main.c
<<

CMakeFiles\Ex4_6.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex4_6.dir/main.c.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Ex4_6.dir\main.c.s /c C:\Users\asus.VENIK\CLionProjects\Ex4-6\main.c
<<

CMakeFiles\Ex4_6.dir\ReadMain.c.obj: CMakeFiles\Ex4_6.dir\flags.make
CMakeFiles\Ex4_6.dir\ReadMain.c.obj: ..\ReadMain.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus.VENIK\CLionProjects\Ex4-6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Ex4_6.dir/ReadMain.c.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Ex4_6.dir\ReadMain.c.obj /FdCMakeFiles\Ex4_6.dir\ /FS -c C:\Users\asus.VENIK\CLionProjects\Ex4-6\ReadMain.c
<<

CMakeFiles\Ex4_6.dir\ReadMain.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex4_6.dir/ReadMain.c.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\Ex4_6.dir\ReadMain.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\asus.VENIK\CLionProjects\Ex4-6\ReadMain.c
<<

CMakeFiles\Ex4_6.dir\ReadMain.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex4_6.dir/ReadMain.c.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Ex4_6.dir\ReadMain.c.s /c C:\Users\asus.VENIK\CLionProjects\Ex4-6\ReadMain.c
<<

# Object files for target Ex4_6
Ex4_6_OBJECTS = \
"CMakeFiles\Ex4_6.dir\main.c.obj" \
"CMakeFiles\Ex4_6.dir\ReadMain.c.obj"

# External object files for target Ex4_6
Ex4_6_EXTERNAL_OBJECTS =

Ex4_6.exe: CMakeFiles\Ex4_6.dir\main.c.obj
Ex4_6.exe: CMakeFiles\Ex4_6.dir\ReadMain.c.obj
Ex4_6.exe: CMakeFiles\Ex4_6.dir\build.make
Ex4_6.exe: CMakeFiles\Ex4_6.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\asus.VENIK\CLionProjects\Ex4-6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Ex4_6.exe"
	"C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Ex4_6.dir --manifests  -- C:\PROGRA~2\MICROS~1.0\VC\bin\link.exe /nologo @CMakeFiles\Ex4_6.dir\objects1.rsp @<<
 /out:Ex4_6.exe /implib:Ex4_6.lib /pdb:C:\Users\asus.VENIK\CLionProjects\Ex4-6\cmake-build-debug\Ex4_6.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Ex4_6.dir\build: Ex4_6.exe

.PHONY : CMakeFiles\Ex4_6.dir\build

CMakeFiles\Ex4_6.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ex4_6.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Ex4_6.dir\clean

CMakeFiles\Ex4_6.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\asus.VENIK\CLionProjects\Ex4-6 C:\Users\asus.VENIK\CLionProjects\Ex4-6 C:\Users\asus.VENIK\CLionProjects\Ex4-6\cmake-build-debug C:\Users\asus.VENIK\CLionProjects\Ex4-6\cmake-build-debug C:\Users\asus.VENIK\CLionProjects\Ex4-6\cmake-build-debug\CMakeFiles\Ex4_6.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Ex4_6.dir\depend
