#include "my_video_filter.h"
#include <hls_video.h>
#include <iostream>

// Convolucion de 3x3
#define WINDOW_SIDE 3
#define IMAGE_MAX_WIDTH 1920
#define PIXEL_BYTES 3

void my_video_filter(ap_axiu<8,1,1,1> *src,
		ap_axis<8,1,1,1> *dest,
		u16 width,
		u16 height)
{
	int row, col, chan;

	hls::Window<WINDOW_SIDE, WINDOW_SIDE, pixel_t> window[3];
	hls::LineBuffer<WINDOW_SIDE, IMAGE_MAX_WIDTH, pixel_t> line_buffers[3];

	int gradiente = 0;
	int gradientes[3];

	for_row:for(row=0; row<height; row++)
	{
		for_col:for(col=0; col<width; col++)
		{
			for(chan=0;chan<3;chan++)
			{
				pixel_t new_pix = src->data;

				window[chan].shift_left();
				line_buffers[chan].shift_up(col);
				line_buffers[chan].insert_top(new_pix, col);

				for(int i=0; i<WINDOW_SIDE; i++)
				{
					window[chan].insert(line_buffers[chan].val[i][col], i, WINDOW_SIDE-1);
				}

				int dx =
					  - window[chan].val[0][0]
					  + window[chan].val[0][2]
					  - 2*window[chan].val[1][0]
					  + 2*window[chan].val[1][2]
					  - window[chan].val[2][0]
					  + window[chan].val[2][2];

				int dy =
					    window[chan].val[0][0]
					  + 2*window[chan].val[0][1]
					  + window[chan].val[0][2]
					  - window[chan].val[2][0]
					  - 2*window[chan].val[2][1]
					  - window[chan].val[2][2];

				gradientes[chan] = abs(dy) + abs(dx);

				src++;
			}

			gradiente = (gradientes[0] + gradientes[0] + gradientes[1] + gradientes[2])/4;
			if(gradiente>255)
				gradiente=255;

			for(int j=0;j<3;j++)
			{
				dest->data = gradiente;
				dest->last = (row == height - 1) && (col == width-1) && (j==2);
				dest->keep = 1;
				dest->dest=0;
				dest->id=0;
				dest->strb=0;
				dest->user=0;
				dest++;
			}
		}
	}
}
