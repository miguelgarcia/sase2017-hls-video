############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project my_video_filter
set_top my_video_filter
add_files my_video_filter/src/types.h
add_files my_video_filter/src/my_video_filter.h
add_files my_video_filter/src/my_video_filter.cpp
open_solution "solution1"
set_part {xc7z010clg400-1}
create_clock -period 10 -name default
source "./my_video_filter/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog -description "my_video_filter" -vendor "sase" -version "1.5" -display_name "my_video_filter"
