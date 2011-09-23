# SPEC file for (at least) Fedora Core 1, 2, 3

Name: 		libmatroska
Version: 1.3.0
Release: 1
License: 	LGPL
Summary:	Matroska Video Container
Group:		System Environment/Libraries
URL: 		http://www.matroska.org/
Vendor:         Moritz Bunkus <moritz@bunkus.org>
Source: 	http://dl.matroska.org/downloads/%{name}/%{name}-%{version}.tar.bz2
BuildRoot: 	%{_tmppath}/%{name}-root

%description
Matroska aims to become THE Standard of Multimedia Container Formats.
It was derived from a project called MCF, but differentiates from it
significantly because it is based on  EBML (Extensible Binary Meta
Language), a binary derivative of XML. EBML enables the Matroska
Development Team to gain significant advantages in terms of future
format extensibility, without breaking file support in old parsers.

%package devel
Summary:	Matroska Video Container headers/development files
Group:		Development/Libraries

%description devel
Headers for libmatroska.

%prep
%setup -q

%build
cd make/linux
CFLAGS="$RPM_OPT_FLAGS" \
make \
prefix="%{_prefix}" \
LIBEBML_INCLUDE_DIR=%{_includedir} \
LIBEBML_LIB_DIR=%{_libdir} \
staticlib
cd ../..

%install
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT
cd make/linux
make prefix=$RPM_BUILD_ROOT/%{_prefix} libdir=$RPM_BUILD_ROOT/%{_libdir} install_staticlib install_headers
cd ../..

%clean
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT

%files devel
%defattr(-, root, root)
%{_includedir}/matroska/*.h
%{_includedir}/matroska/c/*.h
%{_libdir}/libmatroska.a

%changelog
* Sat Apr 16 2005 Moritz Bunkus <moritz@bunkus.org>
- updated for the new libmatroska build targets
* Fri May 15 2003 Ronald Bultje <rbultje@ronald.bitfreak.net>
- create spec file
