install(
    TARGETS greetness-app_exe
    RUNTIME COMPONENT greetness-app_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
