# How to compile URBI engine from sources
## Setup environment
To build Urbi on Windows 10 you need to setup your environment by installing following software:

*  [Python 2.7](https://www.python.org/ftp/python/2.7.15/python-2.7.15.amd64.msi) - be sure that Python is in the `PATH` environment variable
*  [Ninja](https://github.com/ninja-build/ninja/releases/download/v1.9.0/ninja-win.zip) - be sure that ninja executable is available through `PATH` environment variable
*  [Microsoft Visual C++ Build Tools 2017](https://visualstudio.microsoft.com) - during installation import [configuration file](https://bitbucket.org/emysinc/urbi/raw/master_upstream/dev/msvc_buildtools_urbi.vsconfig).
*  [Git](https://github.com/git-for-windows/git/releases/download/v2.20.1.windows.1/Git-2.20.1-64-bit.exe)
*  [CMake](https://github.com/Kitware/CMake/releases/download/v3.13.4/cmake-3.13.4-win64-x64.msi)

Alternatively you can use Chocolatey to install all the tools. To do so, please install Chocolatey. Download [configuration file](https://gitlab.com/emysinc/urbi/urbi/raw/master/dev/chocolatey_packages.config?inline=false) and type: `choco install chocolatey_packages.config`


## Create workspace directory
Create directory which will be used as your workspace, where all the software is going to be build. Later, we refer to this directory as `%URBI_WORKSPACE%`.
After enetering some directory that you would like to tread as your workspace you can type following to set environment variable:
```bat
set URBI_WORKSPACE=%cd%
```

## Build Boost
Do not use boost newer than 1.68.

Download [boost source code](https://sourceforge.net/projects/boost/files/boost/1.68.0/boost_1_68_0.7z/download), and extract content to `%URBI_WORKSPACE%`.
Launch _x64 Native Tools Command Prompt for VS 2017_ and change directory to `%URBI_WORKSPACE%\boost_1_68_0`. Build and deploy boost with following command:
```bat
bootstrap.bat &&^
b2.exe -j8 --prefix=%URBI_WORKSPACE%\boost --libdir=%URBI_WORKSPACE%\boost\bin toolset=msvc link=shared variant=release address-model=64 install
```

After all, boost should be installed in `%URBI_WORKSPACE%\boost`.

## Build Urbi
Change directory to `%URBI_WORKSPACE%` and download sources with following command:
```bat
git clone --recursive git@gitlab.com:emysinc/urbi/urbi.git
```

Configure project
```bat
md %URBI_WORKSPACE%\urbi\build &&^
cd %URBI_WORKSPACE%\urbi\build &&^
cmake -G Ninja -DBOOSTROOT=%URBI_WORKSPACE%\boost -DBOOST_LIBRARYDIR=%URBI_WORKSPACE%\boost\bin -DCMAKE_INSTALL_PREFIX=%URBI_WORKSPACE%\urbi_bin -DCMAKE_BUILD_TYPE=Release ..
```

Build project
```bat
cmake --build .
```

Optional: Install project
```bat
cmake --build . --target install
```
## Launch Urbi
Works only after installing by cmake. Open fresh console terminal and change directory to `%URBI_WORKSPACE%\urbi_bin\bin` and type
```bat
urbi-launch.exe --start --port=54000 -- --interactive
```

It executes interactive console. Thus, you can type your urbiscript directly. Alternatively you can connect to localhost:54000 with any telnet client ([Gostai Console](https://pallyrobot.sharepoint.com/:u:/s/Software/EYZ7pBnNgKpLoQB3vgRowFQBBEoaw0W1yL5G6fl04ePJQw?e=tXLjw0) is recommended).

## Create MSI package
This can be done after issuing `cmake --build .`. Inside `%URBI_WORKSPACE%\urbi\build` type following:
```bat
cpack -G "WIX"
```
There will be file like `Urbi-3.0.0-win64.msi` inside `%URBI_WORKSPACE%\urbi\build`.
