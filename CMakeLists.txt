cmake_minimum_required(VERSION 3.12)
project(KnowingEye)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(. DIRSRCS)



if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
	execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Environment/Soloud/dll/Debug ${CMAKE_CURRENT_BINARY_DIR}) # 拷贝文件夹
	execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Environment/tesseract-5.2.0-x64-windows/dllD ${CMAKE_CURRENT_BINARY_DIR}) # 拷贝文件夹
else()
	execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Environment/Soloud/dll/Release ${CMAKE_CURRENT_BINARY_DIR}) # 拷贝文件夹
	execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Environment/tesseract-5.2.0-x64-windows/dll ${CMAKE_CURRENT_BINARY_DIR}) # 拷贝文件夹
endif()

execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Environment/TTS/bin ${CMAKE_CURRENT_BINARY_DIR}) # 拷贝文件夹
execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/TessData ${CMAKE_CURRENT_BINARY_DIR}/TessData)# 把 tesseract 的模型拷进去
execute_process(COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/1.png ${CMAKE_CURRENT_BINARY_DIR})# 拷贝文件
#execute_process(COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/launch.vs.json ${PROJECT_SOURCE_DIR}/.vs)# 设置的DLL文件路径




# 设置 include 的引用
include_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}./Environment/Soloud/include
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}./Environment/tesseract-5.2.0-x64-windows/include
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}./Environment/TTS/include
)

# 设置要引用 lib 文件路径
if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
	link_directories(
		SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}./Environment/Soloud/lib/Debug
		SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}./Environment/tesseract-5.2.0-x64-windows/libD
		SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}./Environment/TTS/libs
	)
else()
	link_directories(
		SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}./Environment/Soloud/lib/Release
		SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}./Environment/tesseract-5.2.0-x64-windows/lib
		SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}./Environment/TTS/libs
	)
endif()


add_executable(KnowingEye  ${DIRSRCS}
	resource.rc#设置exe程序图标
)

#set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")#关闭控制台

add_subdirectory(Function)


# 设置 引用那些 lib 文件
if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
	target_link_libraries(
		# 引进的项目
		KnowingEye 
		# 引进文件夹里面的代码
		FunctionLib

		# 引用的 lib 文件
		SDL2.lib
		SDL2main.lib
		soloud.lib
		leptonica-1.82.0d.lib
		tesseract52d.lib
		msc_x64.lib
	)
else()
	target_link_libraries(
		KnowingEye 

		SDL2.lib
		SDL2main.lib
		soloud.lib
		leptonica-1.82.0.lib
		tesseract52.lib
		msc_x64.lib
	)
endif()

