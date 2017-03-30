# Summary.
project('ellis_op', 'cpp',
  version: '0.1',
  license: 'mit',
  default_options: [
    'c_std=c99',
    'cpp_std=c++14',
    'buildtype=debug',
    'warning_level=3',
    'werror=true'])

common_flags = ['-Wshadow']
c_flags = common_flags
cpp_flags = common_flags + ['-fno-rtti']
add_project_arguments(c_flags, language: 'c')
add_project_arguments(cpp_flags, language: 'cpp')

pkg = import('pkgconfig')

# Dependencies
thread_dep = dependency('threads')
asio_dep = dependency('boost', modules : ['asio', 'system'])
nghttp2_dep = dependency('libnghttp2_asio', version : '>=1.18.0')
ssl_dep = dependency('libssl')
ellis_dep = dependency('ellis')
all_deps = [ thread_dep, ellis_dep, asio_dep, nghttp2_dep, ssl_dep ]

# Includes.
inc = include_directories('include')
public_headers = [
  'include/ellis_op/call_trace.hpp',
  'include/ellis_op/time.hpp',
]
install_headers(public_headers, subdir: 'ellis_op')

# Source for library.
src = [
  'src/time.cpp',
]
# Library
lib = shared_library(
  'ellis_op',
  src,
  include_directories: inc,
  install: true,
  dependencies: all_deps)
pkg.generate(
  name: 'ellis_op',
  description: 'Format neutral remote or local procedure calling interface',
  libraries: [lib],
  subdirs: 'ellis_op',
  version: '0.1')

# Documentation.
run_target('docs', command: 'meson/makedoc')

# Static analysis.
run_target('check', command: 'meson/check')
run_target('clangcheck', command: 'meson/clangcheck')
run_target('clangtidy', command: 'meson/clangtidy')
run_target('cppcheck', command: 'meson/cppcheck')

# Tests.
tests = [
  ['op_test', 'test/op_test.cpp'],
]
foreach t : tests
  exe = executable(
    t.get(0),
    t.get(1),
    include_directories: inc,
    link_with: lib,
    dependencies: all_deps)
  test(t.get(0), exe)
endforeach
