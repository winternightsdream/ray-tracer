set(threading_source_files
	pool-thread.cpp
	pool-thread.hpp
	semaphore.hpp
	task.cpp
	task.hpp
	thread-pool.cpp
	thread-pool.hpp
)

add_library(threading ${threading_source_files})