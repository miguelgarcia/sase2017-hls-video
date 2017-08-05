############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
set_directive_interface -mode axis "my_video_filter" src
set_directive_interface -mode axis "my_video_filter" dest
set_directive_interface -mode s_axilite "my_video_filter" width
set_directive_interface -mode s_axilite "my_video_filter" height
set_directive_interface -mode s_axilite "my_video_filter"
set_directive_pipeline "my_video_filter/for_col"
set_directive_loop_tripcount -min 1080 -max 1080 -avg 1080 "my_video_filter/for_row"
set_directive_loop_tripcount -min 1920 -max 1920 -avg 1920 "my_video_filter/for_col"
