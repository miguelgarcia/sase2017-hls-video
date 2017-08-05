#ifndef _MY_VIDEO_FILTER_H_
#define _MY_VIDEO_FILTER_H_

#include "ap_axi_sdata.h"
#include "types.h"

#define MAX_LINE 2000

void my_video_filter(ap_axiu<8,1,1,1> *src,
		ap_axis<8,1,1,1> *dest,
		u16 width,
		u16 height);

#endif
