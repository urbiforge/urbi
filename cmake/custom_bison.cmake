#this needs to be done...
MESSAGE("Using bison")

#invoke flex on utoken.l
qi_generate_src(
  ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw
  SRC src/parser/utoken.l
  COMMAND flex -+ -o${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/utoken.l
)

#fix flex output
qi_generate_src(
  ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc
  SRC ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw
  COMMAND ${_python_executable} ${CMAKE_CURRENT_SOURCE_DIR}/dev/fix-utoken.py ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc
)

# You need a bison patched by gostai, in the urbi-sdk/bison repository.
set(BISON_OPTS
  --defines --report=all -xml
)
set(BISON
  bison
)

qi_generate_src(
  ${CMAKE_CURRENT_BINARY_DIR}/src/parser/ugrammar.cc
  SRC src/parser/ugrammar.y
  COMMAND ${BISON} ${BISON_OPTS} ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/ugrammar.y -o  ${CMAKE_CURRENT_BINARY_DIR}/src/parser/ugrammar.cc
)

function(astgen target command)
 qi_generate_src(
   ${CMAKE_CURRENT_SOURCE_DIR}/${target}
  SRC src/ast/ast.yml
  COMMAND ${_python_executable} ${CMAKE_CURRENT_SOURCE_DIR}/dev/ast-${command}-gen ${CMAKE_CURRENT_SOURCE_DIR}/src/ast < ${CMAKE_CURRENT_SOURCE_DIR}/src/ast/ast.yml
 )
endfunction()


astgen(src/ast/all.cc all)
astgen(src/ast/cloner.cc cloner)
astgen(src/ast/transformer.cc transformer)
astgen(src/ast/fwd.hh fwd)
astgen(src/ast/default-visitor.hh default-visitor)
astgen(src/ast/visitor.hh visitor)
astgen(src/ast/pretty-printer.cc pretty-printer)
astgen(src/ast/dot-printer.cc dot-printer)
astgen(src/ast/serializer.hh serializer)
astgen(src/ast/implicit.hh nodes)

set(GENERATED_SRC
  src/ast/visitor.hh
  src/ast/implicit.hh
  src/ast/all.cc
  src/ast/cloner.hxx
  src/ast/cloner.cc
  src/ast/dot-printer.cc
  src/ast/pretty-printer.cc
  src/ast/transformer.cc
  src/ast/default-visitor.hh
  src/ast/fwd.hh
)