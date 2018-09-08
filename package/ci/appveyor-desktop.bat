if "%APPVEYOR_BUILD_WORKER_IMAGE%" == "Visual Studio 2017" call "C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Auxiliary/Build/vcvarsall.bat" %PLATFORM% || exit /b
if "%APPVEYOR_BUILD_WORKER_IMAGE%" == "Visual Studio 2015" call "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/vcvarsall.bat" %PLATFORM% || exit /b
set PATH=%APPVEYOR_BUILD_FOLDER%\deps\bin;%PATH%

rem Build
mkdir build && cd build || exit /b
cmake .. ^
    -DCMAKE_BUILD_TYPE=Debug ^
    -DCMAKE_CXX_FLAGS="/sdl /permissive-" ^
    -DCMAKE_INSTALL_PREFIX=%APPVEYOR_BUILD_FOLDER%/deps ^
    -DUTILITY_USE_ANSI_COLORS=%ANSI_COLORS% ^
    -DBUILD_TESTS=ON ^
    -G Ninja || exit /b
cmake --build . || exit /b
rem  cmake --build . --target install || exit /b
rem
rem  rem Test
rem  set CORRADE_TEST_COLOR=ON
rem  ctest -V || exit /b
rem
rem  rem Examples
rem  cd %APPVEYOR_BUILD_FOLDER% || exit /b
rem  mkdir build-examples && cd build-examples || exit /b
rem  cmake ../src/examples ^
rem      -DCMAKE_BUILD_TYPE=Debug ^
rem      -DCMAKE_PREFIX_PATH=%APPVEYOR_BUILD_FOLDER%/deps ^
rem      -G Ninja || exit /b
rem  cmake --build . || exit /b
