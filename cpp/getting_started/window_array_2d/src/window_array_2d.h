/**********
Copyright (c) 2018, Xilinx, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********/

#ifndef WINDOW_ARRAY_2D_H_
#define WINDOW_ARRAY_2D_H_
// Parameters Description:
//         TILE_PER_ROW:        number of tiles/windows in each matrix row
//         TILE_WIDTH:          number of words in each tile/window
//         TILE_PER_COLUMN:     number of tiles/windows in each matrix column
//         TILE_HEIGHT:         number of rows in matrix tile/window
//         BLOCK_SIZE:          number of words in an matrix

#define TILE_PER_ROW 4
#define TILE_WIDTH 16
#define TILE_PER_COLUMN 8
#define TILE_HEIGHT 8
#define BLOCK_SIZE (TILE_WIDTH*TILE_PER_ROW*TILE_PER_COLUMN*TILE_HEIGHT)

#include <hls_stream.h>
// Default data type is integer
typedef int DTYPE;
// use HLS stream library for easy use of AXI-stream interface
typedef hls::stream<DTYPE> my_data_fifo;

// Pragma below Specifies sds++ Compiler to Generate a Programmable Logic Design
// Which has Direct Memory Interface with DDR and PL.  
#pragma SDS data zero_copy(inx[0:BLOCK_SIZE], outx[0:BLOCK_SIZE])
void window_array_2d_accel(DTYPE *inx, DTYPE *outx, DTYPE alpha);
#endif
