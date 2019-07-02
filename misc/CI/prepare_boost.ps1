$TARGETDIR = "$pwd\boost_bin"
if(!(Test-Path -Path $TARGETDIR )){
    echo "Building boost"
    [Net.ServicePointManager]::SecurityProtocol = "tls12, tls11, tls"
    iwr -outf boost.zip https://dl.bintray.com/boostorg/release/1.68.0/source/boost_1_68_0.zip
    7z x -y boost.zip
    cd boost_1_68_0
    ./bootstrap.bat >$null
    ./b2.exe -j4 --prefix=$pwd/../boost_bin toolset=msvc link=shared address-model=64 install >$null
    if(!(Test-Path -Path "$pwd/../boost_bin/bin")){
        md $pwd/../boost_bin/bin/
    }
    mv $pwd/../boost_bin/lib/*.dll $pwd/../boost_bin/bin
	echo "Boost compiled and installed"
    cd ..
}
