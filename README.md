# How to compile URBI engine from sources
## Setup environment
To build Urbi on Windows 10 you need to setup your environment by installing following software:

*  [Python 2.7](https://www.python.org/ftp/python/2.7.15/python-2.7.15.amd64.msi) - be sure that Python is in the `PATH` environment variable
*  qiBuild - install with PIP, which is delivered with Python: `pip install qibuild`
*  [Ninja](https://github.com/ninja-build/ninja/releases/download/v1.9.0/ninja-win.zip) - be sure that ninja executable is available through `PATH` environment variable
*  [Microsoft Visual C++ Build Tools 2017](https://visualstudio.microsoft.com) - during installation import [configuration file](https://bitbucket.org/emysinc/urbi/raw/master_upstream/dev/msvc_buildtools_urbi.vsconfig).
*  [Git](https://github.com/git-for-windows/git/releases/download/v2.20.1.windows.1/Git-2.20.1-64-bit.exe)
*  [CMake](https://github.com/Kitware/CMake/releases/download/v3.13.4/cmake-3.13.4-win64-x64.msi)

Alternatively you can use Chocolatey to install all the tools (except qiBuild). To do so, please install Chocolatey. Download [configuration file](https://gitlab.com/emysinc/urbi/urbi/raw/master/dev/chocolatey_packages.config?inline=false) and type: `choco install chocolatey_packages.config`
Remember to install qiBuild manually.

## Create workspace directory
Create directory which will be used as your workspace, where all the software is going to be build. Later, we refer to this directory as `%URBI_WORKSPACE%`.

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
qisrc init &&^
qisrc add --branch master git@gitlab.com:emysinc/urbi/libjpeg.git &&^
qisrc add --branch master git@gitlab.com:emysinc/urbi/libport.git &&^
qisrc add --branch master git@gitlab.com:emysinc/urbi/urbi.git
```

Configure project
```bat
qibuild configure --release --with-debug-info -DBOOSTROOT=%URBI_WORKSPACE%\boost -DBOOST_LIBRARYDIR=%URBI_WORKSPACE%\boost\bin -G"Ninja" urbi
```

Build project
```bat
qibuild make -j8 urbi
```

Install project
```bat
qibuild install urbi %URBI_WORKSPACE%\urbi
```
## Launch Urbi
Open fresh console terminal and change directory to `%URBI_WORKSPACE%\urbi\bin` and type
```bat
urbi-launch.exe --start --port=54000 -- --interactive
```

It executes interactive console. Thus, you can type your urbiscript directly. Alternatively you can connect to localhost:54000 with any telnet client ([Gostai Console](https://pallyrobot.sharepoint.com/:u:/s/Software/EYZ7pBnNgKpLoQB3vgRowFQBBEoaw0W1yL5G6fl04ePJQw?e=tXLjw0) is recommended).

## Create MSI package
To create MSI package, the additional environment variables has to be created:

* `BOOST_STAGEDIR` points to `%URBI_WORKSPACE%\boost`
* `URBI_STAGEDIR` points to `%URBI_WORKSPACE%\urbi`

Create folder `%URBI_WORKSPACE%\installer` and type
```bat
cd %URBI_WORKSPACE%\installer

"%WIX%"\bin\candle.exe -arch x64 ^
%URBI_WORKSPACE%\emysinc\urbi\urbi\misc\installer\Boost.wxs ^
%URBI_WORKSPACE%\emysinc\urbi\urbi\misc\installer\BoostDev.wxs ^
%URBI_WORKSPACE%\emysinc\urbi\urbi\misc\installer\LibJpegDev.wxs ^
%URBI_WORKSPACE%\emysinc\urbi\urbi\misc\installer\LibPort.wxs ^
%URBI_WORKSPACE%\emysinc\urbi\urbi\misc\installer\LibPortDev.wxs ^
%URBI_WORKSPACE%\emysinc\urbi\urbi\misc\installer\Urbi.wxs ^
%URBI_WORKSPACE%\emysinc\urbi\urbi\misc\installer\UrbiDev.wxs ^
%URBI_WORKSPACE%\emysinc\urbi\urbi\misc\installer\UrbiMain.wxs

"%WIX%"\bin\light.exe -ext WIXUIExtension -out urbi-vc141-x64-3.0.0.msi ^
Boost.wixobj ^
BoostDev.wixobj ^
LibJpegDev.wixobj ^
LibPort.wixobj ^
LibPortDev.wixobj ^
Urbi.wixobj ^
UrbiDev.wixobj ^
UrbiMain.wixobj

```
