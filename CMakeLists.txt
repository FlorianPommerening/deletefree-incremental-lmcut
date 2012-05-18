cmake_minimum_required(VERSION 2.8)

project(relaxed_delete)

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)

add_executable(hplusbnb src/hplusbnb.cpp  src/BranchAndBoundSearch.cpp  src/lmcut.cpp  src/SASTask.h  src/BranchAndBoundSearch.h  src/lm_cut_flo_heuristic.h  src/SearchNode.cpp  src/foreach.h  src/lmcut.h  src/SearchNode.h  src/GabowSCC.cpp  src/OperatorSelector.cpp  src/steinertreeImprove.cpp  src/GabowSCC.h  src/OperatorSelector.h  src/steinertreeImprove.h  src/hmax.cpp  src/Options.cpp  src/Timer.h  src/hmax.h  src/Options.h  src/UIntEx.cpp  src/PointerMap.h  src/UIntEx.h  src/PriorityQueue.h  src/UniversalRestartSequence.h  src/IDAStarSearch.cpp  src/RelaxedOperator.h  src/Variable.cpp  src/IDAStarSearch.h  src/RelaxedTask.cpp  src/Variable.h  src/Landmark.cpp  src/RelaxedTask.h  src/Landmark.h  src/SASTask.cpp)



include_directories(src /usr/include/boost)
link_directories(${relaxed_delete_BINARY_DIR}/src)
target_link_libraries(hplusbnb rt)
target_link_libraries(hplusbnb boost_system)
target_link_libraries(hplusbnb boost_filesystem)
