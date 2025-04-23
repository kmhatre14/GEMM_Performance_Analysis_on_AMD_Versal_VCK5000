
#ifndef _DMA0_H_
#define _DMA0_H_
#include <cstring>
#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

#define DATA_TYPE 32

#define AXI_WIDTH_A 512
#define AXI_WIDTH_B 512
#define AXI_WIDTH_C 512
#define PLIO_WIDTH 128
// This is to accomodate 2 ports for read and write
#define NO_R_PORTS 2

#define H1 32
#define W1 32
#define W2 32
#define A 4
#define B 4
#define C 4
#define X 1
#define Y 1
#define Z 1
#define PACK_IN 4
#define PACK_OUT 4

const int M =H1*A*X;
const int K =W1*B*Y;
const int N =W2*C*Z;

const int A_PER_TRA=AXI_WIDTH_A/DATA_TYPE;
const int B_PER_TRA=AXI_WIDTH_B/DATA_TYPE;
const int C_PER_TRA=AXI_WIDTH_C/DATA_TYPE;

const int NUM_PER_TRA = PLIO_WIDTH/DATA_TYPE;

const int BUFFA_FACTOR= AXI_WIDTH_A/PLIO_WIDTH/2;
const int BUFFB_FACTOR= AXI_WIDTH_B/PLIO_WIDTH/2;
const int BUFFC_FACTOR= AXI_WIDTH_C/PLIO_WIDTH/2;

typedef ap_uint<PLIO_WIDTH> data_t;
typedef ap_axiu<PLIO_WIDTH, 0, 0, 0> axis_pkt;
typedef hls::stream<axis_pkt> axis_stream;

typedef hls::stream<ap_uint<32>> axis_stream_32;
typedef hls::stream<ap_uint<AXI_WIDTH_A>> axis_stream_A;
typedef hls::stream<ap_uint<AXI_WIDTH_B>> axis_stream_B;
typedef hls::stream<ap_uint<AXI_WIDTH_C>> axis_stream_C;

const int LEFT_SIZE=W1*(H1/NUM_PER_TRA);
const int RIGHT_SIZE=W2*(W1/NUM_PER_TRA);
const int OUT_SIZE=W2*(H1/NUM_PER_TRA);

const int boundA=M*K/A_PER_TRA;
const int boundB=K*N/B_PER_TRA;
const int boundC=M*N/C_PER_TRA;

#define NO_R_PORTS 2
typedef union{
    float data_float;
    unsigned int data_uint;
} fp_int;
extern "C" {
    void dma0(ap_uint<AXI_WIDTH_A> *ina0,
        ap_uint<AXI_WIDTH_A> *ina1,
        ap_uint<AXI_WIDTH_B> *inb0,
        ap_uint<AXI_WIDTH_B> *inb1, 
        ap_uint<AXI_WIDTH_C> *out0,
        ap_uint<AXI_WIDTH_C> *out1,
       axis_stream& txA0, axis_stream& txA1, axis_stream& txA2, axis_stream& txA3,
       axis_stream& txA4, axis_stream& txA5, axis_stream& txA6, axis_stream& txA7,
       axis_stream& txB0, axis_stream& txB1, axis_stream& txB2, axis_stream& txB3,
       axis_stream& txB4, axis_stream& txB5, axis_stream& txB6, axis_stream& txB7,
       axis_stream& rxC0, axis_stream& rxC1, axis_stream& rxC2, axis_stream& rxC3,
       const int TX, const int TY, const int TZ);
}
#endif
