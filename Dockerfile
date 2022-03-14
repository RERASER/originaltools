FROM fedora:31

LABEL description="Build environment for segatools"

RUN yum -y install meson
RUN yum -y install ninja-build
RUN yum -y install make
RUN yum -y install zip
RUN yum -y install clang
RUN yum -y install mingw64-gcc.x86_64
RUN yum -y install mingw32-gcc.x86_64
RUN yum -y install git

RUN mkdir /segatools
WORKDIR /segatools

COPY aimeio aimeio
COPY amex amex
COPY board board
COPY carolhook carolhook
COPY carolio carolio
COPY chunihook chunihook
COPY chusanhook chusanhook
COPY chuniio chuniio
COPY dist dist
COPY divahook divahook
COPY divaio divaio
COPY doc doc
COPY fgohook fgohook
COPY fgoio fgoio
COPY hooklib hooklib
COPY iccard iccard
COPY idzhook idzhook
COPY idzio idzio
COPY jvs jvs
COPY mai2hook mai2hook
COPY mai2io mai2io
COPY minihook minihook
COPY mu3hook mu3hook
COPY mu3io mu3io
COPY pki pki
COPY platform platform
COPY reg reg
COPY spike spike
COPY subprojects subprojects
COPY util util
COPY CHANGELOG.md CHANGELOG.md
COPY cross-mingw-32.txt cross-mingw-32.txt
COPY cross-mingw-64.txt cross-mingw-64.txt
COPY Makefile Makefile
COPY meson.build meson.build
COPY Package.mk Package.mk
COPY precompiled.h precompiled.h
COPY README.md README.md

RUN make dist