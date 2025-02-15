project('winetest', 'c',
        version : '1.0.0',
        default_options : ['warning_level=0', 'c_std=c99'])

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = [
    # TODO why do we need this if we set c_std=c99 ???
    '-D_POSIX_C_SOURCE=199309L',
    '-DBUILDING_MESON_LIBRARY',
    '-Wno-c11-extensions',
    '-Wno-unused-parameter',
    '-Wno-format',
    '-Wno-pedantic',
    '-Wno-incompatible-pointer-types',
    '-Wno-implicit-function-declaration',
    '-Wno-int-conversion',
    '-Wno-unused-but-set-parameter',
    '-Wno-unused-but-set-variable',
    '-Wno-unused-variable',
    '-Wno-unused-function',
    '-Wno-pointer-sign',
    '-Wno-sign-compare',
    '-Wno-uninitialized',
    '-Wno-missing-field-initializers',
    '-D__STANDALONE__',
    '-D__WINESRC__',
    '-DWINE_UNICODE_NATIVE',
#    '-DWINE_NO_TRACE_MSGS',
#    '-DWINE_NO_DEBUG_MSGS',
#    '-D_DEBUG',
    '-D__forceinline=__attribute__((always_inline)) inline'
]

# Define the include directory
inc_dir = include_directories(
    'standalone/inc/wine/include',
    'standalone/inc/wine/dlls/atl',
    'standalone/inc/wine/dlls/kernelbase',
    'standalone/inc/wine/dlls/oleaut32',
    'standalone/inc/wine/dlls/scrrun',
    'standalone/inc/wine/dlls/vbscript',
    'subprojects/zlog/src',
)

sources = files(
    'src/def.c',
    'src/utils.c',
    'src/scriptsite.c',

    'standalone/inc/wine/wine.c',
    'standalone/inc/wine/dlls/atl/atl.c',

    'standalone/inc/wine/dlls/oleaut32/oleaut.c',
    'standalone/inc/wine/dlls/oleaut32/variant.c',
    'standalone/inc/wine/dlls/oleaut32/varformat.c',
    'standalone/inc/wine/dlls/oleaut32/vartype.c',
    'standalone/inc/wine/dlls/oleaut32/safearray.c',

    'standalone/inc/wine/dlls/vbscript/compile.c',
    'standalone/inc/wine/dlls/vbscript/global.c',
    'standalone/inc/wine/dlls/vbscript/interp.c',
    'standalone/inc/wine/dlls/vbscript/lex.c',
    'standalone/inc/wine/dlls/vbscript/regexp.c',
    'standalone/inc/wine/dlls/vbscript/utils.c',
    'standalone/inc/wine/dlls/vbscript/vbdisp.c',
    'standalone/inc/wine/dlls/vbscript/vbregexp.c',
    'standalone/inc/wine/dlls/vbscript/vbscript.c',
    'standalone/inc/wine/dlls/vbscript/vbscript_main.c',
    'standalone/inc/wine/dlls/vbscript/parser.tab.c',

    'standalone/inc/wine/dlls/scrrun/dictionary.c',
    'standalone/inc/wine/dlls/scrrun/filesystem.c',
    'standalone/inc/wine/dlls/scrrun/scrrun.c',

    'standalone/inc/wine/dlls/kernelbase/locale.c',

    'standalone/inc/wine/wine.c'
)

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : true)
zlog_dep = dependency('zlog', fallback: ['zlog', 'zlog_dep'])
unity_dep = dependency('unity', fallback: ['unity', 'unity_dep'])

exe_sources = files(
    'src/main.c',
) + sources

exe = executable(meson.project_name(), exe_sources,
                 include_directories : inc_dir,
                 c_args : lib_args,
                 install : true,
                 dependencies: [m_dep, zlog_dep]

)

#shared_library('winetest', sources,
#               install : true,
#               c_args : lib_args,
#               include_directories : inc_dir
#)

unity_subproject = subproject('unity')
unity_dependency = unity_subproject.get_variable('unity_dep')
unity_gen_runner = unity_subproject.get_variable('gen_test_runner')

src1 = files(
    'src' / 'utils.c',
    'test' / 'TestVBScript.c',
) + sources

inc = include_directories('src')

test1 = executable('test1',
                   sources: [
                       src1,
                       unity_gen_runner.process('test' / 'TestVBScript.c')
                   ],
                   c_args : lib_args,
                   include_directories: [ inc_dir, inc ],
                   dependencies: [ m_dep, zlog_dep, unity_dependency ],
)

test('test1', test1,
     should_fail: true)