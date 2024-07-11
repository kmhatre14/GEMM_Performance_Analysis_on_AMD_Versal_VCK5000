#include <stdint.h>
#include "dma0.hpp"

void address_A_ddr(axis_stream_32& addrA_out,const int TX,const int TY,const int TZ) {
#pragma HLS inline off
    for(int tx=0;tx<TX;tx++){
        for(int tz=0;tz<TZ;tz++){
            for(int ty=0;ty<TY;ty++){
                ap_uint<32> pos;
                for(int j=0;j<K;j++){
                    for(int i=0;i<M/A_PER_TRA;i++){
                    #pragma HLS PIPELINE II = 1
                        pos=i+j*(M/A_PER_TRA)*TX+ty*K*(M/A_PER_TRA)*TX+tx*(M/A_PER_TRA);
                        addrA_out.write(pos);
                    }
                }
            }
        }
    }
}

void loadA_ddr(ap_uint<AXI_WIDTH_A>* ina, axis_stream_32& addrA_in,axis_stream_A& dataA_out,const int TX,const int TY,const int TZ) {
#pragma HLS inline off
    ap_uint<AXI_WIDTH_A> temp_data;
    int bound=boundA*TX*TY*TZ;
    for(int i=0;i<bound;i++){
    #pragma HLS PIPELINE II = 1
        int addr = addrA_in.read();
        temp_data=ina[addr];
        dataA_out.write(temp_data);        
    }
}

void address_B_ddr(axis_stream_32& addrB_out,const int TX,const int TY,const int TZ) {
#pragma HLS inline off    
    for(int tx=0;tx<TX;tx++){
        for(int tz=0;tz<TZ;tz++){
            for(int ty=0;ty<TY;ty++){
                ap_uint<32> pos;
                for(int j=0;j<N;j++){
                    for(int i=0;i<K/B_PER_TRA;i++){
                    #pragma HLS PIPELINE II = 1
                        pos=i+j*(K/B_PER_TRA)*TY+ty*(K/B_PER_TRA)+tz*N*(K/B_PER_TRA)*TY;
                        addrB_out.write(pos);
                    }
                }
            }
        }
    }
}


void loadB_ddr(ap_uint<AXI_WIDTH_B>* inb, axis_stream_32& addrB_in,axis_stream_B& dataB_out,const int TX,const int TY,const int TZ) {
#pragma HLS inline off
    ap_uint<AXI_WIDTH_B> temp_data;
    int bound=boundB*TX*TY*TZ;
    for(int i=0;i<bound;i++){
    #pragma HLS PIPELINE II = 1
        ap_uint<32> addr = addrB_in.read();
        temp_data=inb[addr];
        dataB_out.write(temp_data);
    }  
}

void address_C_ddr(axis_stream_32& addrC_out,const int TX,const int TZ) {
#pragma HLS inline off
    for(int tx=0;tx<TX;tx++){
        for(int tz=0;tz<TZ;tz++){
            ap_uint<32> pos;
            for(int j=0;j<N;j++){
                for(int i=0;i<M/C_PER_TRA;i++){
                #pragma HLS PIPELINE II = 1
                    pos=i+j*(M/C_PER_TRA)*TX+tx*(M/C_PER_TRA)+tz*N*(M/C_PER_TRA)*TX;
                    addrC_out.write(pos);
                }
            }
        }
    }
}

void storeC_ddr(ap_uint<AXI_WIDTH_C>* outc, axis_stream_32& addrC_in,axis_stream_C& dataC_in,const int TX,const int TZ) { 
#pragma HLS inline off
    int bound=boundC*TX*TZ;
    for(int i=0;i<bound;i++){
    #pragma HLS PIPELINE II = 1
        ap_uint<AXI_WIDTH_C> temp_data=dataC_in.read();
        ap_uint<32> addr = addrC_in.read();
        outc[addr]=temp_data;
            
    }
    
}

void loadA(axis_stream_A& dataA_in, ap_uint<BUFF_WIDTH> a_buf[A*(B/PACK_IN)][X*Y][PACK_IN][LEFT_SIZE_BUFF],bool enable){
#pragma HLS inline off
    if(enable){
        for(int y=0;y<Y;y++){
            for(int b=0;b<B;b++){
                for(int k=0;k<W1;k++){
                    for(int x=0;x<X;x++){
                        for(int a=0;a<A;a++){
                            for(int i=0;i<(H1/A_PER_TRA);i++){
                            #pragma HLS PIPELINE II = 1
                            #pragma HLS dependence variable=a_buf type=intra false
                                int pos0=b%PACK_IN;
                                int pos1=x*Y+y;
                                int pos2=a*(B/PACK_IN)+(b/PACK_IN);
                                ap_uint<AXI_WIDTH_A> temp_data=dataA_in.read();
                                a_buf[pos2][pos1][pos0][k]=temp_data(63,0);
                                a_buf[pos2][pos1][pos0][k+64]=temp_data(127,64);
                                a_buf[pos2][pos1][pos0][k+128]=temp_data(191,128);
                                a_buf[pos2][pos1][pos0][k+192]=temp_data(255,192);
                                a_buf[pos2][pos1][pos0][k+256]=temp_data(319,256);
                                a_buf[pos2][pos1][pos0][k+320]=temp_data(383,320);
                                a_buf[pos2][pos1][pos0][k+384]=temp_data(447,384);
                                a_buf[pos2][pos1][pos0][k+448]=temp_data(511,448);
                            }
                        }
                    }
                }
            }
        }
    }
}

void loadB(axis_stream_B& dataB_in, ap_uint<PLIO_WIDTH> b_buf[(B/PACK_IN)*C][Y*Z][PACK_IN][RIGHT_SIZE],bool enable){
#pragma HLS inline off
    if(enable){
        for(int z=0;z<Z;z++){
            for(int c=0;c<C;c++){
                for(int w2=0;w2<W2;w2++){
                    for(int y=0;y<Y;y++){
                        for(int b=0;b<B;b++){
                            for (int m=0;m<(W1/B_PER_TRA);m++){
                            #pragma HLS PIPELINE II = 1
                            #pragma HLS dependence variable=b_buf type=intra false
                                int pos1=b%PACK_IN;
                                int pos2=z*Y+y;
                                int pos3=(b/PACK_IN)+c*(B/PACK_IN);
                                ap_uint<AXI_WIDTH_B> temp_data=dataB_in.read();
                                b_buf[pos3][pos2][pos1][w2]=temp_data(127,0);
                                b_buf[pos3][pos2][pos1][w2+64]=temp_data(255,128);
                                b_buf[pos3][pos2][pos1][w2+128]=temp_data(383,256);
                                b_buf[pos3][pos2][pos1][w2+192]=temp_data(511,384);
                            }
                        }
                    }
                }
            }
        }
    }
}

void storeC(axis_stream_C& dataC_out, ap_uint<BUFF_WIDTH> c_buf[A*C/PACK_OUT][2][X*Z][PACK_OUT][OUT_SIZE_BUFF/2], bool enable){
    #pragma HLS inline off
        if(enable){
            for(int z=0;z<Z;z++){
                for(int c=0;c<C;c++){
                    for(int w2=0;w2<W2;w2++){
                        for(int x=0;x<X;x++){
                            for (int a=0;a<A;a++){
                                for (int n=0; n<H1/C_PER_TRA;n++){
                                #pragma HLS PIPELINE II = 1
                                    int aie_pack=c+a*C;
                                    int pos0=aie_pack%PACK_OUT;
                                    int pos1=x+z*X;
                                    int pos2=w2%2;
                                    int pos3=aie_pack/PACK_OUT;
                                    ap_uint<AXI_WIDTH_C> temp_data;
                                    temp_data(63,0)   =c_buf[pos3][pos2][pos1][pos0][w2/2];
                                    temp_data(127,64) =c_buf[pos3][pos2][pos1][pos0][w2/2+32 ];
                                    temp_data(191,128)=c_buf[pos3][pos2][pos1][pos0][w2/2+64 ];
                                    temp_data(255,192)=c_buf[pos3][pos2][pos1][pos0][w2/2+96 ];
                                    temp_data(319,256)=c_buf[pos3][pos2][pos1][pos0][w2/2+128];
                                    temp_data(383,320)=c_buf[pos3][pos2][pos1][pos0][w2/2+160];
                                    temp_data(447,384)=c_buf[pos3][pos2][pos1][pos0][w2/2+192];
                                    temp_data(511,448)=c_buf[pos3][pos2][pos1][pos0][w2/2+224];
                                    dataC_out.write(temp_data);
                                }
                            }
                        }
                    }
                }
            }

            for(int x = 0; x < X*Z; x++){
                for(int pack=0;pack<PACK_OUT;pack++){
                    for(int w2=0;w2<(W2/2);w2++){
                    #pragma HLS PIPELINE II = 1
                    #pragma HLS dependence variable=c_buf type=intra false
                        for(int a = 0; a < (A*C/PACK_OUT); a++){
                            c_buf[a][0][x][pack][w2]=0; 
                            c_buf[a][0][x][pack][w2+32 ]=0;
                            c_buf[a][0][x][pack][w2+64 ]=0; 
                            c_buf[a][0][x][pack][w2+96 ]=0;
                            c_buf[a][0][x][pack][w2+128]=0; 
                            c_buf[a][0][x][pack][w2+160]=0;
                            c_buf[a][0][x][pack][w2+192]=0; 
                            c_buf[a][0][x][pack][w2+224]=0;
                            c_buf[a][1][x][pack][w2]=0; 
                            c_buf[a][1][x][pack][w2+32 ]=0;
                            c_buf[a][1][x][pack][w2+64 ]=0; 
                            c_buf[a][1][x][pack][w2+96 ]=0;
                            c_buf[a][1][x][pack][w2+128]=0; 
                            c_buf[a][1][x][pack][w2+160]=0;
                            c_buf[a][1][x][pack][w2+192]=0; 
                            c_buf[a][1][x][pack][w2+224]=0;
                        }
                    }
                }
            }

        }
    }

ap_uint<32> generateHeader(unsigned int pktType, unsigned int ID){
#pragma HLS inline
    ap_uint<32> header=0;
    header(4,0)=ID;
    header(11,5)=0;
    header(14,12)=pktType;
    header[15]=0;
    header(20,16)=-1;//source row
    header(27,21)=-1;//source column
    header(30,28)=0;
    header[31]=header(30,0).xor_reduce()?(ap_uint<1>)0:(ap_uint<1>)1;
    return header;
}

unsigned int getPacketId(ap_uint<32> header){
#pragma HLS inline
    ap_uint<32> ID=0;
    ID(4,0)=header(4,0);
    return ID;
}

template<int NC>
void sendA(ap_uint<BUFF_WIDTH> a_buf[X*Y][PACK_IN][LEFT_SIZE_BUFF],
           axis_stream& txA0, axis_stream& txA1, 
           bool enable){

#pragma HLS inline off
    if(enable){
        axis_pkt tmp;
        data_t data;
        data_t da;
        ap_uint<32> header;
        
        ap_uint<32> data_temp[2][NUM_PER_TRA];
        #pragma HLS ARRAY_PARTITION variable=data_temp complete dim=0

        for (int z = 0; z < Z; z++) {
            for (int xy = 0; xy < X*Y; xy++) {//y first then x
                for (int pack = 0; pack < PACK_IN; pack++){ 
                    header=generateHeader(0,pack);
                    data(63,0)=a_buf[xy][pack][0];
                    data(127,64)=a_buf[xy][pack][1];

                    data_temp[0][0]=data(31,0);
                    data_temp[0][1]=data(63,32);
                    data_temp[0][2]=data(95,64);
                    data_temp[0][3]=data(127,96);
                    
                    da(31,0)   = header;
                    da(63,32)  = data_temp[0][0];
                    da(95,64)  = data_temp[0][1];
                    da(127,96) = data_temp[0][2];

                    tmp.data   = da;
                    tmp.keep   = -1;
                    tmp.last   = 0;
                    
                    txA0.write(tmp);
                    txA1.write(tmp);
                    
                    for (int i = 1; i < LEFT_SIZE_BUFF/2; i++){ 
                    #pragma HLS PIPELINE II = 1
                        data(63,0)=a_buf[xy][pack][i*2];
                        data(127,64)=a_buf[xy][pack][i*2+1];

                        data_temp[i%2][0]=data(31,0);
                        data_temp[i%2][1]=data(63,32);
                        data_temp[i%2][2]=data(95,64);
                        data_temp[i%2][3]=data(127,96);
                        da(31,0)   = data_temp[(i+1)%2][3];
                        da(63,32)  = data_temp[i%2][0];
                        da(95,64)  = data_temp[i%2][1];
                        da(127,96) = data_temp[i%2][2];

                        tmp.data   = da;
                        tmp.keep   = -1;
                        tmp.last   = 0;
                        txA0.write(tmp);
                        txA1.write(tmp);
                        
                    }
                    
                    da(31,0)=data_temp[1][3];
                    da(63,32)  = 0;
                    da(95,64)  = 0;
                    da(127,96) = 0;
                    tmp.data  =  da; 
                    tmp.keep  = 0x000f;
                    tmp.last  = 1;

                    txA0.write(tmp);
                    txA1.write(tmp);
                    

                }
                
            }
        }
    }
}

template<int NC>
void sendB(ap_uint<PLIO_WIDTH> b_buf[Y*Z][PACK_IN][RIGHT_SIZE],
           axis_stream& txB0, axis_stream& txB1, 
           bool enable){

#pragma HLS inline off
    if(enable){
        axis_pkt tmp;
        data_t data;
        data_t da;
        ap_uint<32> header;

        ap_uint<32> data_temp[2][4];
        #pragma HLS ARRAY_PARTITION variable=data_temp complete dim=0

        for (int z = 0; z < Z; z++) {
            for (int x = 0; x < X; x++) {
                for (int y = 0; y < Y; y++){
                    for (int pack = 0; pack < PACK_IN; pack++){  
                        header=generateHeader(0,pack);
                        int pos1=y+z*Y;
                        data=b_buf[pos1][pack][0];


                        data_temp[0][0]=data(31,0);
                        data_temp[0][1]=data(63,32);
                        data_temp[0][2]=data(95,64);
                        data_temp[0][3]=data(127,96);
                        
                        da(31,0)   = header;
                        da(63,32)  = data_temp[0][0];
                        da(95,64)  = data_temp[0][1];
                        da(127,96) = data_temp[0][2];

                        tmp.data   = da;
                        tmp.keep   = -1;
                        tmp.last   = 0;

                        txB0.write(tmp);
                        txB1.write(tmp);
                        
                        for (int i = 1; i < RIGHT_SIZE; i++){ 
                        #pragma HLS PIPELINE II = 1
                            data=b_buf[pos1][pack][i];

                            data_temp[i%2][0]=data(31,0);
                            data_temp[i%2][1]=data(63,32);
                            data_temp[i%2][2]=data(95,64);
                            data_temp[i%2][3]=data(127,96);
                            da(31,0)   = data_temp[(i+1)%2][3];
                            da(63,32)  = data_temp[i%2][0];
                            da(95,64)  = data_temp[i%2][1];
                            da(127,96) = data_temp[i%2][2];

                            tmp.data   = da;
                            tmp.keep   = -1;
                            tmp.last   = 0;
                            txB0.write(tmp);
                            txB1.write(tmp);
                              
                        }
                        
                        da(31,0)   = data_temp[1][3];
                        da(63,32)  = 0;
                        da(95,64)  = 0;
                        da(127,96) = 0;

                        tmp.data =  da;
                        tmp.keep  = 0x000f;
                        tmp.last  = 1;
                        txB0.write(tmp);
                        txB1.write(tmp);
                        

                    }
                }
            }
        }
    }
}

template<int NC>
void receiveC(ap_uint<BUFF_WIDTH> c_buf[2][X*Z][PACK_OUT][OUT_SIZE_BUFF/2],axis_stream& rxC, bool enable){ 

#pragma HLS inline off
if (enable){
        
    axis_pkt tmp; 
    int cnt[2];
    #pragma HLS ARRAY_PARTITION variable=cnt complete dim=0
    comb_32 data_temp[2][4];
    #pragma HLS ARRAY_PARTITION variable=data_temp complete dim=0
    comb_32 d0,d1,d2,d3;
    ap_uint<32> header;
    unsigned int ID;
    unsigned int tile_x;

    for(int i=0;i<PACK_OUT;i++){
    #pragma HLS unroll
        cnt[i]=0;
    }
    
    for(int z = 0; z < Z; z++){
        for(int x = 0; x < X; x++){
            for (int n = 0; n < Y; n++){
                for(int pack=0;pack<PACK_OUT;pack++){
                    tmp=rxC.read();
                    header=tmp.data(31,0);

                    data_temp[0][1].low0=tmp.data(39,32);
                    data_temp[0][1].low1=tmp.data(47,40);
                    data_temp[0][1].high0=tmp.data(55,48);
                    data_temp[0][1].high1=tmp.data(63,56);
                    data_temp[0][2].low0=tmp.data(71,64);
                    data_temp[0][2].low1=tmp.data(79,72);
                    data_temp[0][2].high0=tmp.data(87,80);
                    data_temp[0][2].high1=tmp.data(95,88);
                    data_temp[0][3].low0=tmp.data(103,96);
                    data_temp[0][3].low1=tmp.data(111,104);
                    data_temp[0][3].high0=tmp.data(119,112);
                    data_temp[0][3].high1=tmp.data(127,120);
                    
                    ID=getPacketId(header);
                    tile_x=cnt[ID]/Y;
                    cnt[ID]=cnt[ID]+1;

                    for(int i=0;i<OUT_SIZE_BUFF/2;i++){
                    #pragma HLS PIPELINE II = 1
                    #pragma HLS dependence variable=c_buf type=inter false
                    #pragma HLS dependence variable=c_buf type=intra false
                        tmp=rxC.read();
                        
                        data_temp[(i+1)%2][0].low0=tmp.data(7,0);
                        data_temp[(i+1)%2][0].low1=tmp.data(15,8);
                        data_temp[(i+1)%2][0].high0=tmp.data(23,16);
                        data_temp[(i+1)%2][0].high1=tmp.data(31,24);
                        data_temp[(i+1)%2][1].low0=tmp.data(39,32);
                        data_temp[(i+1)%2][1].low1=tmp.data(47,40);
                        data_temp[(i+1)%2][1].high0=tmp.data(55,48);
                        data_temp[(i+1)%2][1].high1=tmp.data(63,56);
                        data_temp[(i+1)%2][2].low0=tmp.data(71,64);
                        data_temp[(i+1)%2][2].low1=tmp.data(79,72);
                        data_temp[(i+1)%2][2].high0=tmp.data(87,80);
                        data_temp[(i+1)%2][2].high1=tmp.data(95,88);
                        data_temp[(i+1)%2][3].low0=tmp.data(103,96);
                        data_temp[(i+1)%2][3].low1=tmp.data(111,104);
                        data_temp[(i+1)%2][3].high0=tmp.data(119,112);
                        data_temp[(i+1)%2][3].high1=tmp.data(127,120);
                        
                        d0.low0  =c_buf[0][tile_x][ID][i](7,0)  ;
                        d0.low1  =c_buf[0][tile_x][ID][i](15,8) ;
                        d0.high0 =c_buf[0][tile_x][ID][i](23,16);
                        d0.high1 =c_buf[0][tile_x][ID][i](31,24);
                        d1.low0  =c_buf[0][tile_x][ID][i](39,32);
                        d1.low1  =c_buf[0][tile_x][ID][i](47,40);
                        d1.high0 =c_buf[0][tile_x][ID][i](55,48);
                        d1.high1 =c_buf[0][tile_x][ID][i](63,56);
                        d2.low0  =c_buf[1][tile_x][ID][i](7,0)  ;
                        d2.low1  =c_buf[1][tile_x][ID][i](15,8) ;
                        d2.high0 =c_buf[1][tile_x][ID][i](23,16);
                        d2.high1 =c_buf[1][tile_x][ID][i](31,24);
                        d3.low0  =c_buf[1][tile_x][ID][i](39,32);
                        d3.low1  =c_buf[1][tile_x][ID][i](47,40);
                        d3.high0 =c_buf[1][tile_x][ID][i](55,48);
                        d3.high1 =c_buf[1][tile_x][ID][i](63,56);


                        d0.low0  = data_temp[i%2][1].low0       + d0.low0 ;
                        d0.low1  = data_temp[i%2][1].low1       + d0.low1 ;
                        d0.high0 = data_temp[i%2][1].high0      + d0.high0;
                        d0.high1 = data_temp[i%2][1].high1      + d0.high1;
                        d1.low0  = data_temp[i%2][2].low0       + d1.low0 ;
                        d1.low1  = data_temp[i%2][2].low1       + d1.low1 ;
                        d1.high0 = data_temp[i%2][2].high0      + d1.high0;
                        d1.high1 = data_temp[i%2][2].high1      + d1.high1;
                        d2.low0  = data_temp[i%2][3].low0       + d2.low0 ;
                        d2.low1  = data_temp[i%2][3].low1       + d2.low1 ;
                        d2.high0 = data_temp[i%2][3].high0      + d2.high0;
                        d2.high1 = data_temp[i%2][3].high1      + d2.high1;
                        d3.low0  = data_temp[(i+1)%2][0].low0   + d3.low0 ;
                        d3.low1  = data_temp[(i+1)%2][0].low1   + d3.low1 ;
                        d3.high0 = data_temp[(i+1)%2][0].high0  + d3.high0;
                        d3.high1 = data_temp[(i+1)%2][0].high1  + d3.high1;
                        
                        c_buf[0][tile_x][ID][i](7,0)    = d0.low0  ;
                        c_buf[0][tile_x][ID][i](15,8)   = d0.low1  ;
                        c_buf[0][tile_x][ID][i](23,16)  = d0.high0 ;
                        c_buf[0][tile_x][ID][i](31,24)  = d0.high1 ;
                        c_buf[0][tile_x][ID][i](39,32)  = d1.low0  ;
                        c_buf[0][tile_x][ID][i](47,40)  = d1.low1  ;
                        c_buf[0][tile_x][ID][i](55,48)  = d1.high0 ;
                        c_buf[0][tile_x][ID][i](63,56)  = d1.high1 ;
                        c_buf[1][tile_x][ID][i](7,0)    = d2.low0  ;
                        c_buf[1][tile_x][ID][i](15,8)   = d2.low1  ;
                        c_buf[1][tile_x][ID][i](23,16)  = d2.high0 ;
                        c_buf[1][tile_x][ID][i](31,24)  = d2.high1 ;
                        c_buf[1][tile_x][ID][i](39,32)  = d3.low0  ;
                        c_buf[1][tile_x][ID][i](47,40)  = d3.low1  ;
                        c_buf[1][tile_x][ID][i](55,48)  = d3.high0 ;
                        c_buf[1][tile_x][ID][i](63,56)  = d3.high1 ;
                    }
                }
            }
        } 
    }
}  
}

void compute(axis_stream_A& dataA_out, axis_stream_B& dataB_out, axis_stream_C& dataC_in,
             axis_stream& txA0, axis_stream& txA1, axis_stream& txA2, axis_stream& txA3,
             axis_stream& txA4, axis_stream& txA5, axis_stream& txA6, axis_stream& txA7,
             axis_stream& txA8, axis_stream& txA9, axis_stream& txA10, axis_stream& txA11,
             axis_stream& txA12, axis_stream& txA13, axis_stream& txA14, axis_stream& txA15,
             axis_stream& txA16, axis_stream& txA17, axis_stream& txA18, axis_stream& txA19,
             axis_stream& txA20, axis_stream& txA21, axis_stream& txA22, axis_stream& txA23,
             axis_stream& txA24, axis_stream& txA25, axis_stream& txA26, axis_stream& txA27,
             axis_stream& txA28, axis_stream& txA29, axis_stream& txA30, axis_stream& txA31,
             axis_stream& txA32, axis_stream& txA33, axis_stream& txA34, axis_stream& txA35,
             axis_stream& txA36, axis_stream& txA37, axis_stream& txA38, axis_stream& txA39,
             axis_stream& txA40, axis_stream& txA41, axis_stream& txA42, axis_stream& txA43,
             axis_stream& txA44, axis_stream& txA45, axis_stream& txA46, axis_stream& txA47,
             axis_stream& txB0, axis_stream& txB1, axis_stream& txB2, axis_stream& txB3,
             axis_stream& txB4, axis_stream& txB5, axis_stream& txB6, axis_stream& txB7,
             axis_stream& txB8, axis_stream& txB9, axis_stream& txB10, axis_stream& txB11,
             axis_stream& txB12, axis_stream& txB13, axis_stream& txB14, axis_stream& txB15,
             axis_stream& txB16, axis_stream& txB17, axis_stream& txB18, axis_stream& txB19,
             axis_stream& txB20, axis_stream& txB21, axis_stream& txB22, axis_stream& txB23,
             axis_stream& txB24, axis_stream& txB25, axis_stream& txB26, axis_stream& txB27,
             axis_stream& txB28, axis_stream& txB29, axis_stream& txB30, axis_stream& txB31,
             axis_stream& txB32, axis_stream& txB33, axis_stream& txB34, axis_stream& txB35,
             axis_stream& txB36, axis_stream& txB37, axis_stream& txB38, axis_stream& txB39,
             axis_stream& txB40, axis_stream& txB41, axis_stream& txB42, axis_stream& txB43,
             axis_stream& txB44, axis_stream& txB45, axis_stream& txB46, axis_stream& txB47,
             axis_stream& txB48, axis_stream& txB49, axis_stream& txB50, axis_stream& txB51,
             axis_stream& txB52, axis_stream& txB53, axis_stream& txB54, axis_stream& txB55,
             axis_stream& txB56, axis_stream& txB57, axis_stream& txB58, axis_stream& txB59,
             axis_stream& txB60, axis_stream& txB61, axis_stream& txB62, axis_stream& txB63,
             axis_stream& txB64, axis_stream& txB65, axis_stream& txB66, axis_stream& txB67,
             axis_stream& txB68, axis_stream& txB69, axis_stream& txB70, axis_stream& txB71,
             axis_stream& txB72, axis_stream& txB73, axis_stream& txB74, axis_stream& txB75,
             axis_stream& txB76, axis_stream& txB77, axis_stream& txB78, axis_stream& txB79,
             axis_stream& txB80, axis_stream& txB81, axis_stream& txB82, axis_stream& txB83,
             axis_stream& txB84, axis_stream& txB85, axis_stream& txB86, axis_stream& txB87,
             axis_stream& txB88, axis_stream& txB89, axis_stream& txB90, axis_stream& txB91,
             axis_stream& txB92, axis_stream& txB93, axis_stream& txB94, axis_stream& txB95,
             axis_stream& rxC0, axis_stream& rxC1, axis_stream& rxC2, axis_stream& rxC3,
             axis_stream& rxC4, axis_stream& rxC5, axis_stream& rxC6, axis_stream& rxC7,
             axis_stream& rxC8, axis_stream& rxC9, axis_stream& rxC10, axis_stream& rxC11,
             axis_stream& rxC12, axis_stream& rxC13, axis_stream& rxC14, axis_stream& rxC15,
             const int TX, const int TY, const int TZ){

    ap_uint<BUFF_WIDTH> buff0_A[A*(B/PACK_IN)][X*Y][PACK_IN][LEFT_SIZE_BUFF];
    #pragma HLS bind_storage variable=buff0_A type=RAM_T2P impl=URAM
    #pragma HLS ARRAY_PARTITION variable=buff0_A complete dim=1
    #pragma HLS ARRAY_PARTITION variable=buff0_A block factor=BUFFA_FACTOR dim=4
    
    ap_uint<BUFF_WIDTH> buff1_A[A*(B/PACK_IN)][X*Y][PACK_IN][LEFT_SIZE_BUFF];
    #pragma HLS bind_storage variable=buff1_A type=RAM_T2P impl=URAM
    #pragma HLS ARRAY_PARTITION variable=buff1_A complete dim=1
    #pragma HLS ARRAY_PARTITION variable=buff1_A block factor=BUFFA_FACTOR dim=4

    ap_uint<PLIO_WIDTH> buff0_B[(B/PACK_IN)*C][Z*Y][PACK_IN][RIGHT_SIZE];
    #pragma HLS bind_storage variable=buff0_B type=RAM_T2P impl=URAM
    #pragma HLS ARRAY_PARTITION variable=buff0_B complete dim=1
    #pragma HLS ARRAY_PARTITION variable=buff0_B block factor=BUFFB_FACTOR dim=4

    ap_uint<PLIO_WIDTH> buff1_B[(B/PACK_IN)*C][Z*Y][PACK_IN][RIGHT_SIZE];
    #pragma HLS bind_storage variable=buff1_B type=RAM_T2P impl=URAM
    #pragma HLS ARRAY_PARTITION variable=buff1_B complete dim=1
    #pragma HLS ARRAY_PARTITION variable=buff1_B block factor=BUFFB_FACTOR dim=4

    ap_uint<BUFF_WIDTH> buff0_C[(C/PACK_OUT)*A][2][Z*X][PACK_OUT][OUT_SIZE_BUFF/2];
    #pragma HLS bind_storage variable=buff0_C type=RAM_T2P impl=URAM
    #pragma HLS ARRAY_PARTITION variable=buff0_C complete dim=1
    #pragma HLS ARRAY_PARTITION variable=buff0_C complete dim=2
    #pragma HLS ARRAY_PARTITION variable=buff0_C block factor=BUFFC_FACTOR dim=5

    ap_uint<BUFF_WIDTH> buff1_C[(C/PACK_OUT)*A][2][Z*X][PACK_OUT][OUT_SIZE_BUFF/2];
    #pragma HLS bind_storage variable=buff1_C type=RAM_T2P impl=URAM
    #pragma HLS ARRAY_PARTITION variable=buff1_C complete dim=1
    #pragma HLS ARRAY_PARTITION variable=buff1_C complete dim=2
    #pragma HLS ARRAY_PARTITION variable=buff1_C block factor=BUFFC_FACTOR dim=5

    const int Total_rd=TX*TY*TZ;

    for (int rd=0; rd<Total_rd+2;rd++){
        int c_flg=0,s_flg=0;
        if(rd>0){
            c_flg=((rd-1)/TY)%2;
        }
        if(rd>1){
            s_flg=(rd-2)%TY;
        }
        if(rd%2==0&&c_flg==0){
            loadA(dataA_out,buff0_A,rd<Total_rd);
            loadB(dataB_out,buff0_B,rd<Total_rd);   

            sendA<0>(buff1_A[0],txA0,txA6,rd>0&&rd<Total_rd+1);
            sendA<1>(buff1_A[1],txA1,txA7,rd>0&&rd<Total_rd+1);
            sendA<2>(buff1_A[2],txA2,txA8,rd>0&&rd<Total_rd+1);
            sendA<3>(buff1_A[3],txA3,txA9,rd>0&&rd<Total_rd+1);
            sendA<4>(buff1_A[4],txA4,txA10,rd>0&&rd<Total_rd+1);
            sendA<5>(buff1_A[5],txA5,txA11,rd>0&&rd<Total_rd+1);
            sendA<6>(buff1_A[6],txA12,txA18,rd>0&&rd<Total_rd+1);
            sendA<7>(buff1_A[7],txA13,txA19,rd>0&&rd<Total_rd+1);
            sendA<8>(buff1_A[8],txA14,txA20,rd>0&&rd<Total_rd+1);
            sendA<9>(buff1_A[9],txA15,txA21,rd>0&&rd<Total_rd+1);
            sendA<10>(buff1_A[10],txA16,txA22,rd>0&&rd<Total_rd+1);
            sendA<11>(buff1_A[11],txA17,txA23,rd>0&&rd<Total_rd+1);
            sendA<12>(buff1_A[12],txA24,txA30,rd>0&&rd<Total_rd+1);
            sendA<13>(buff1_A[13],txA25,txA31,rd>0&&rd<Total_rd+1);
            sendA<14>(buff1_A[14],txA26,txA32,rd>0&&rd<Total_rd+1);
            sendA<15>(buff1_A[15],txA27,txA33,rd>0&&rd<Total_rd+1);
            sendA<16>(buff1_A[16],txA28,txA34,rd>0&&rd<Total_rd+1);
            sendA<17>(buff1_A[17],txA29,txA35,rd>0&&rd<Total_rd+1);
            sendA<18>(buff1_A[18],txA36,txA42,rd>0&&rd<Total_rd+1);
            sendA<19>(buff1_A[19],txA37,txA43,rd>0&&rd<Total_rd+1);
            sendA<20>(buff1_A[20],txA38,txA44,rd>0&&rd<Total_rd+1);
            sendA<21>(buff1_A[21],txA39,txA45,rd>0&&rd<Total_rd+1);
            sendA<22>(buff1_A[22],txA40,txA46,rd>0&&rd<Total_rd+1);
            sendA<23>(buff1_A[23],txA41,txA47,rd>0&&rd<Total_rd+1);
            

            sendB<0>(buff1_B[0],txB0,txB6,rd>0&&rd<Total_rd+1);
            sendB<1>(buff1_B[1],txB1,txB7,rd>0&&rd<Total_rd+1);
            sendB<2>(buff1_B[2],txB2,txB8,rd>0&&rd<Total_rd+1);
            sendB<3>(buff1_B[3],txB3,txB9,rd>0&&rd<Total_rd+1);
            sendB<4>(buff1_B[4],txB4,txB10,rd>0&&rd<Total_rd+1);
            sendB<5>(buff1_B[5],txB5,txB11,rd>0&&rd<Total_rd+1);
            sendB<6>(buff1_B[6],txB12,txB18,rd>0&&rd<Total_rd+1);
            sendB<7>(buff1_B[7],txB13,txB19,rd>0&&rd<Total_rd+1);
            sendB<8>(buff1_B[8],txB14,txB20,rd>0&&rd<Total_rd+1);
            sendB<9>(buff1_B[9],txB15,txB21,rd>0&&rd<Total_rd+1);
            sendB<10>(buff1_B[10],txB16,txB22,rd>0&&rd<Total_rd+1);
            sendB<11>(buff1_B[11],txB17,txB23,rd>0&&rd<Total_rd+1);
            sendB<12>(buff1_B[12],txB24,txB30,rd>0&&rd<Total_rd+1);
            sendB<13>(buff1_B[13],txB25,txB31,rd>0&&rd<Total_rd+1);
            sendB<14>(buff1_B[14],txB26,txB32,rd>0&&rd<Total_rd+1);
            sendB<15>(buff1_B[15],txB27,txB33,rd>0&&rd<Total_rd+1);
            sendB<16>(buff1_B[16],txB28,txB34,rd>0&&rd<Total_rd+1);
            sendB<17>(buff1_B[17],txB29,txB35,rd>0&&rd<Total_rd+1);
            sendB<18>(buff1_B[18],txB36,txB42,rd>0&&rd<Total_rd+1);
            sendB<19>(buff1_B[19],txB37,txB43,rd>0&&rd<Total_rd+1);
            sendB<20>(buff1_B[20],txB38,txB44,rd>0&&rd<Total_rd+1);
            sendB<21>(buff1_B[21],txB39,txB45,rd>0&&rd<Total_rd+1);
            sendB<22>(buff1_B[22],txB40,txB46,rd>0&&rd<Total_rd+1);
            sendB<23>(buff1_B[23],txB41,txB47,rd>0&&rd<Total_rd+1);
            sendB<24>(buff1_B[24],txB48,txB54,rd>0&&rd<Total_rd+1);
            sendB<25>(buff1_B[25],txB49,txB55,rd>0&&rd<Total_rd+1);
            sendB<26>(buff1_B[26],txB50,txB56,rd>0&&rd<Total_rd+1);
            sendB<27>(buff1_B[27],txB51,txB57,rd>0&&rd<Total_rd+1);
            sendB<28>(buff1_B[28],txB52,txB58,rd>0&&rd<Total_rd+1);
            sendB<29>(buff1_B[29],txB53,txB59,rd>0&&rd<Total_rd+1);
            sendB<30>(buff1_B[30],txB60,txB66,rd>0&&rd<Total_rd+1);
            sendB<31>(buff1_B[31],txB61,txB67,rd>0&&rd<Total_rd+1);
            sendB<32>(buff1_B[32],txB62,txB68,rd>0&&rd<Total_rd+1);
            sendB<33>(buff1_B[33],txB63,txB69,rd>0&&rd<Total_rd+1);
            sendB<34>(buff1_B[34],txB64,txB70,rd>0&&rd<Total_rd+1);
            sendB<35>(buff1_B[35],txB65,txB71,rd>0&&rd<Total_rd+1);
            sendB<36>(buff1_B[36],txB72,txB78,rd>0&&rd<Total_rd+1);
            sendB<37>(buff1_B[37],txB73,txB79,rd>0&&rd<Total_rd+1);
            sendB<38>(buff1_B[38],txB74,txB80,rd>0&&rd<Total_rd+1);
            sendB<39>(buff1_B[39],txB75,txB81,rd>0&&rd<Total_rd+1);
            sendB<40>(buff1_B[40],txB76,txB82,rd>0&&rd<Total_rd+1);
            sendB<41>(buff1_B[41],txB77,txB83,rd>0&&rd<Total_rd+1);
            sendB<42>(buff1_B[42],txB84,txB90,rd>0&&rd<Total_rd+1);
            sendB<43>(buff1_B[43],txB85,txB91,rd>0&&rd<Total_rd+1);
            sendB<44>(buff1_B[44],txB86,txB92,rd>0&&rd<Total_rd+1);
            sendB<45>(buff1_B[45],txB87,txB93,rd>0&&rd<Total_rd+1);
            sendB<46>(buff1_B[46],txB88,txB94,rd>0&&rd<Total_rd+1);
            sendB<47>(buff1_B[47],txB89,txB95,rd>0&&rd<Total_rd+1);
            

            receiveC<0>(buff0_C[0],rxC0, rd>0&&rd<Total_rd+1);
            receiveC<1>(buff0_C[1],rxC1, rd>0&&rd<Total_rd+1);
            receiveC<2>(buff0_C[2],rxC2, rd>0&&rd<Total_rd+1);
            receiveC<3>(buff0_C[3],rxC3, rd>0&&rd<Total_rd+1);
            receiveC<4>(buff0_C[4],rxC4, rd>0&&rd<Total_rd+1);
            receiveC<5>(buff0_C[5],rxC5, rd>0&&rd<Total_rd+1);
            receiveC<6>(buff0_C[6],rxC6, rd>0&&rd<Total_rd+1);
            receiveC<7>(buff0_C[7],rxC7, rd>0&&rd<Total_rd+1);
            receiveC<8>(buff0_C[8],rxC8, rd>0&&rd<Total_rd+1);
            receiveC<9>(buff0_C[9],rxC9, rd>0&&rd<Total_rd+1);
            receiveC<10>(buff0_C[10],rxC10, rd>0&&rd<Total_rd+1);
            receiveC<11>(buff0_C[11],rxC11, rd>0&&rd<Total_rd+1);
            receiveC<12>(buff0_C[12],rxC12, rd>0&&rd<Total_rd+1);
            receiveC<13>(buff0_C[13],rxC13, rd>0&&rd<Total_rd+1);
            receiveC<14>(buff0_C[14],rxC14, rd>0&&rd<Total_rd+1);
            receiveC<15>(buff0_C[15],rxC15, rd>0&&rd<Total_rd+1);
            

            storeC(dataC_in, buff1_C, rd>TY&&s_flg==(TY-1));
        }
        else if(rd%2==1&&c_flg==0){
            loadA(dataA_out,buff1_A,rd<Total_rd);
            loadB(dataB_out,buff1_B,rd<Total_rd);   

            sendA<0>(buff0_A[0],txA0,txA6,rd>0&&rd<Total_rd+1);
            sendA<1>(buff0_A[1],txA1,txA7,rd>0&&rd<Total_rd+1);
            sendA<2>(buff0_A[2],txA2,txA8,rd>0&&rd<Total_rd+1);
            sendA<3>(buff0_A[3],txA3,txA9,rd>0&&rd<Total_rd+1);
            sendA<4>(buff0_A[4],txA4,txA10,rd>0&&rd<Total_rd+1);
            sendA<5>(buff0_A[5],txA5,txA11,rd>0&&rd<Total_rd+1);
            sendA<6>(buff0_A[6],txA12,txA18,rd>0&&rd<Total_rd+1);
            sendA<7>(buff0_A[7],txA13,txA19,rd>0&&rd<Total_rd+1);
            sendA<8>(buff0_A[8],txA14,txA20,rd>0&&rd<Total_rd+1);
            sendA<9>(buff0_A[9],txA15,txA21,rd>0&&rd<Total_rd+1);
            sendA<10>(buff0_A[10],txA16,txA22,rd>0&&rd<Total_rd+1);
            sendA<11>(buff0_A[11],txA17,txA23,rd>0&&rd<Total_rd+1);
            sendA<12>(buff0_A[12],txA24,txA30,rd>0&&rd<Total_rd+1);
            sendA<13>(buff0_A[13],txA25,txA31,rd>0&&rd<Total_rd+1);
            sendA<14>(buff0_A[14],txA26,txA32,rd>0&&rd<Total_rd+1);
            sendA<15>(buff0_A[15],txA27,txA33,rd>0&&rd<Total_rd+1);
            sendA<16>(buff0_A[16],txA28,txA34,rd>0&&rd<Total_rd+1);
            sendA<17>(buff0_A[17],txA29,txA35,rd>0&&rd<Total_rd+1);
            sendA<18>(buff0_A[18],txA36,txA42,rd>0&&rd<Total_rd+1);
            sendA<19>(buff0_A[19],txA37,txA43,rd>0&&rd<Total_rd+1);
            sendA<20>(buff0_A[20],txA38,txA44,rd>0&&rd<Total_rd+1);
            sendA<21>(buff0_A[21],txA39,txA45,rd>0&&rd<Total_rd+1);
            sendA<22>(buff0_A[22],txA40,txA46,rd>0&&rd<Total_rd+1);
            sendA<23>(buff0_A[23],txA41,txA47,rd>0&&rd<Total_rd+1);
            

            sendB<0>(buff0_B[0],txB0,txB6,rd>0&&rd<Total_rd+1);
            sendB<1>(buff0_B[1],txB1,txB7,rd>0&&rd<Total_rd+1);
            sendB<2>(buff0_B[2],txB2,txB8,rd>0&&rd<Total_rd+1);
            sendB<3>(buff0_B[3],txB3,txB9,rd>0&&rd<Total_rd+1);
            sendB<4>(buff0_B[4],txB4,txB10,rd>0&&rd<Total_rd+1);
            sendB<5>(buff0_B[5],txB5,txB11,rd>0&&rd<Total_rd+1);
            sendB<6>(buff0_B[6],txB12,txB18,rd>0&&rd<Total_rd+1);
            sendB<7>(buff0_B[7],txB13,txB19,rd>0&&rd<Total_rd+1);
            sendB<8>(buff0_B[8],txB14,txB20,rd>0&&rd<Total_rd+1);
            sendB<9>(buff0_B[9],txB15,txB21,rd>0&&rd<Total_rd+1);
            sendB<10>(buff0_B[10],txB16,txB22,rd>0&&rd<Total_rd+1);
            sendB<11>(buff0_B[11],txB17,txB23,rd>0&&rd<Total_rd+1);
            sendB<12>(buff0_B[12],txB24,txB30,rd>0&&rd<Total_rd+1);
            sendB<13>(buff0_B[13],txB25,txB31,rd>0&&rd<Total_rd+1);
            sendB<14>(buff0_B[14],txB26,txB32,rd>0&&rd<Total_rd+1);
            sendB<15>(buff0_B[15],txB27,txB33,rd>0&&rd<Total_rd+1);
            sendB<16>(buff0_B[16],txB28,txB34,rd>0&&rd<Total_rd+1);
            sendB<17>(buff0_B[17],txB29,txB35,rd>0&&rd<Total_rd+1);
            sendB<18>(buff0_B[18],txB36,txB42,rd>0&&rd<Total_rd+1);
            sendB<19>(buff0_B[19],txB37,txB43,rd>0&&rd<Total_rd+1);
            sendB<20>(buff0_B[20],txB38,txB44,rd>0&&rd<Total_rd+1);
            sendB<21>(buff0_B[21],txB39,txB45,rd>0&&rd<Total_rd+1);
            sendB<22>(buff0_B[22],txB40,txB46,rd>0&&rd<Total_rd+1);
            sendB<23>(buff0_B[23],txB41,txB47,rd>0&&rd<Total_rd+1);
            sendB<24>(buff0_B[24],txB48,txB54,rd>0&&rd<Total_rd+1);
            sendB<25>(buff0_B[25],txB49,txB55,rd>0&&rd<Total_rd+1);
            sendB<26>(buff0_B[26],txB50,txB56,rd>0&&rd<Total_rd+1);
            sendB<27>(buff0_B[27],txB51,txB57,rd>0&&rd<Total_rd+1);
            sendB<28>(buff0_B[28],txB52,txB58,rd>0&&rd<Total_rd+1);
            sendB<29>(buff0_B[29],txB53,txB59,rd>0&&rd<Total_rd+1);
            sendB<30>(buff0_B[30],txB60,txB66,rd>0&&rd<Total_rd+1);
            sendB<31>(buff0_B[31],txB61,txB67,rd>0&&rd<Total_rd+1);
            sendB<32>(buff0_B[32],txB62,txB68,rd>0&&rd<Total_rd+1);
            sendB<33>(buff0_B[33],txB63,txB69,rd>0&&rd<Total_rd+1);
            sendB<34>(buff0_B[34],txB64,txB70,rd>0&&rd<Total_rd+1);
            sendB<35>(buff0_B[35],txB65,txB71,rd>0&&rd<Total_rd+1);
            sendB<36>(buff0_B[36],txB72,txB78,rd>0&&rd<Total_rd+1);
            sendB<37>(buff0_B[37],txB73,txB79,rd>0&&rd<Total_rd+1);
            sendB<38>(buff0_B[38],txB74,txB80,rd>0&&rd<Total_rd+1);
            sendB<39>(buff0_B[39],txB75,txB81,rd>0&&rd<Total_rd+1);
            sendB<40>(buff0_B[40],txB76,txB82,rd>0&&rd<Total_rd+1);
            sendB<41>(buff0_B[41],txB77,txB83,rd>0&&rd<Total_rd+1);
            sendB<42>(buff0_B[42],txB84,txB90,rd>0&&rd<Total_rd+1);
            sendB<43>(buff0_B[43],txB85,txB91,rd>0&&rd<Total_rd+1);
            sendB<44>(buff0_B[44],txB86,txB92,rd>0&&rd<Total_rd+1);
            sendB<45>(buff0_B[45],txB87,txB93,rd>0&&rd<Total_rd+1);
            sendB<46>(buff0_B[46],txB88,txB94,rd>0&&rd<Total_rd+1);
            sendB<47>(buff0_B[47],txB89,txB95,rd>0&&rd<Total_rd+1);
            

            receiveC<0>(buff0_C[0],rxC0, rd>0&&rd<Total_rd+1);
            receiveC<1>(buff0_C[1],rxC1, rd>0&&rd<Total_rd+1);
            receiveC<2>(buff0_C[2],rxC2, rd>0&&rd<Total_rd+1);
            receiveC<3>(buff0_C[3],rxC3, rd>0&&rd<Total_rd+1);
            receiveC<4>(buff0_C[4],rxC4, rd>0&&rd<Total_rd+1);
            receiveC<5>(buff0_C[5],rxC5, rd>0&&rd<Total_rd+1);
            receiveC<6>(buff0_C[6],rxC6, rd>0&&rd<Total_rd+1);
            receiveC<7>(buff0_C[7],rxC7, rd>0&&rd<Total_rd+1);
            receiveC<8>(buff0_C[8],rxC8, rd>0&&rd<Total_rd+1);
            receiveC<9>(buff0_C[9],rxC9, rd>0&&rd<Total_rd+1);
            receiveC<10>(buff0_C[10],rxC10, rd>0&&rd<Total_rd+1);
            receiveC<11>(buff0_C[11],rxC11, rd>0&&rd<Total_rd+1);
            receiveC<12>(buff0_C[12],rxC12, rd>0&&rd<Total_rd+1);
            receiveC<13>(buff0_C[13],rxC13, rd>0&&rd<Total_rd+1);
            receiveC<14>(buff0_C[14],rxC14, rd>0&&rd<Total_rd+1);
            receiveC<15>(buff0_C[15],rxC15, rd>0&&rd<Total_rd+1);
            

            storeC(dataC_in, buff1_C, rd>TY&&s_flg==(TY-1));
        }
        else if(rd%2==0&&c_flg==1){
            loadA(dataA_out,buff0_A,rd<Total_rd);
            loadB(dataB_out,buff0_B,rd<Total_rd);   

            sendA<0>(buff1_A[0],txA0,txA6,rd>0&&rd<Total_rd+1);
            sendA<1>(buff1_A[1],txA1,txA7,rd>0&&rd<Total_rd+1);
            sendA<2>(buff1_A[2],txA2,txA8,rd>0&&rd<Total_rd+1);
            sendA<3>(buff1_A[3],txA3,txA9,rd>0&&rd<Total_rd+1);
            sendA<4>(buff1_A[4],txA4,txA10,rd>0&&rd<Total_rd+1);
            sendA<5>(buff1_A[5],txA5,txA11,rd>0&&rd<Total_rd+1);
            sendA<6>(buff1_A[6],txA12,txA18,rd>0&&rd<Total_rd+1);
            sendA<7>(buff1_A[7],txA13,txA19,rd>0&&rd<Total_rd+1);
            sendA<8>(buff1_A[8],txA14,txA20,rd>0&&rd<Total_rd+1);
            sendA<9>(buff1_A[9],txA15,txA21,rd>0&&rd<Total_rd+1);
            sendA<10>(buff1_A[10],txA16,txA22,rd>0&&rd<Total_rd+1);
            sendA<11>(buff1_A[11],txA17,txA23,rd>0&&rd<Total_rd+1);
            sendA<12>(buff1_A[12],txA24,txA30,rd>0&&rd<Total_rd+1);
            sendA<13>(buff1_A[13],txA25,txA31,rd>0&&rd<Total_rd+1);
            sendA<14>(buff1_A[14],txA26,txA32,rd>0&&rd<Total_rd+1);
            sendA<15>(buff1_A[15],txA27,txA33,rd>0&&rd<Total_rd+1);
            sendA<16>(buff1_A[16],txA28,txA34,rd>0&&rd<Total_rd+1);
            sendA<17>(buff1_A[17],txA29,txA35,rd>0&&rd<Total_rd+1);
            sendA<18>(buff1_A[18],txA36,txA42,rd>0&&rd<Total_rd+1);
            sendA<19>(buff1_A[19],txA37,txA43,rd>0&&rd<Total_rd+1);
            sendA<20>(buff1_A[20],txA38,txA44,rd>0&&rd<Total_rd+1);
            sendA<21>(buff1_A[21],txA39,txA45,rd>0&&rd<Total_rd+1);
            sendA<22>(buff1_A[22],txA40,txA46,rd>0&&rd<Total_rd+1);
            sendA<23>(buff1_A[23],txA41,txA47,rd>0&&rd<Total_rd+1);
            

            sendB<0>(buff1_B[0],txB0,txB6,rd>0&&rd<Total_rd+1);
            sendB<1>(buff1_B[1],txB1,txB7,rd>0&&rd<Total_rd+1);
            sendB<2>(buff1_B[2],txB2,txB8,rd>0&&rd<Total_rd+1);
            sendB<3>(buff1_B[3],txB3,txB9,rd>0&&rd<Total_rd+1);
            sendB<4>(buff1_B[4],txB4,txB10,rd>0&&rd<Total_rd+1);
            sendB<5>(buff1_B[5],txB5,txB11,rd>0&&rd<Total_rd+1);
            sendB<6>(buff1_B[6],txB12,txB18,rd>0&&rd<Total_rd+1);
            sendB<7>(buff1_B[7],txB13,txB19,rd>0&&rd<Total_rd+1);
            sendB<8>(buff1_B[8],txB14,txB20,rd>0&&rd<Total_rd+1);
            sendB<9>(buff1_B[9],txB15,txB21,rd>0&&rd<Total_rd+1);
            sendB<10>(buff1_B[10],txB16,txB22,rd>0&&rd<Total_rd+1);
            sendB<11>(buff1_B[11],txB17,txB23,rd>0&&rd<Total_rd+1);
            sendB<12>(buff1_B[12],txB24,txB30,rd>0&&rd<Total_rd+1);
            sendB<13>(buff1_B[13],txB25,txB31,rd>0&&rd<Total_rd+1);
            sendB<14>(buff1_B[14],txB26,txB32,rd>0&&rd<Total_rd+1);
            sendB<15>(buff1_B[15],txB27,txB33,rd>0&&rd<Total_rd+1);
            sendB<16>(buff1_B[16],txB28,txB34,rd>0&&rd<Total_rd+1);
            sendB<17>(buff1_B[17],txB29,txB35,rd>0&&rd<Total_rd+1);
            sendB<18>(buff1_B[18],txB36,txB42,rd>0&&rd<Total_rd+1);
            sendB<19>(buff1_B[19],txB37,txB43,rd>0&&rd<Total_rd+1);
            sendB<20>(buff1_B[20],txB38,txB44,rd>0&&rd<Total_rd+1);
            sendB<21>(buff1_B[21],txB39,txB45,rd>0&&rd<Total_rd+1);
            sendB<22>(buff1_B[22],txB40,txB46,rd>0&&rd<Total_rd+1);
            sendB<23>(buff1_B[23],txB41,txB47,rd>0&&rd<Total_rd+1);
            sendB<24>(buff1_B[24],txB48,txB54,rd>0&&rd<Total_rd+1);
            sendB<25>(buff1_B[25],txB49,txB55,rd>0&&rd<Total_rd+1);
            sendB<26>(buff1_B[26],txB50,txB56,rd>0&&rd<Total_rd+1);
            sendB<27>(buff1_B[27],txB51,txB57,rd>0&&rd<Total_rd+1);
            sendB<28>(buff1_B[28],txB52,txB58,rd>0&&rd<Total_rd+1);
            sendB<29>(buff1_B[29],txB53,txB59,rd>0&&rd<Total_rd+1);
            sendB<30>(buff1_B[30],txB60,txB66,rd>0&&rd<Total_rd+1);
            sendB<31>(buff1_B[31],txB61,txB67,rd>0&&rd<Total_rd+1);
            sendB<32>(buff1_B[32],txB62,txB68,rd>0&&rd<Total_rd+1);
            sendB<33>(buff1_B[33],txB63,txB69,rd>0&&rd<Total_rd+1);
            sendB<34>(buff1_B[34],txB64,txB70,rd>0&&rd<Total_rd+1);
            sendB<35>(buff1_B[35],txB65,txB71,rd>0&&rd<Total_rd+1);
            sendB<36>(buff1_B[36],txB72,txB78,rd>0&&rd<Total_rd+1);
            sendB<37>(buff1_B[37],txB73,txB79,rd>0&&rd<Total_rd+1);
            sendB<38>(buff1_B[38],txB74,txB80,rd>0&&rd<Total_rd+1);
            sendB<39>(buff1_B[39],txB75,txB81,rd>0&&rd<Total_rd+1);
            sendB<40>(buff1_B[40],txB76,txB82,rd>0&&rd<Total_rd+1);
            sendB<41>(buff1_B[41],txB77,txB83,rd>0&&rd<Total_rd+1);
            sendB<42>(buff1_B[42],txB84,txB90,rd>0&&rd<Total_rd+1);
            sendB<43>(buff1_B[43],txB85,txB91,rd>0&&rd<Total_rd+1);
            sendB<44>(buff1_B[44],txB86,txB92,rd>0&&rd<Total_rd+1);
            sendB<45>(buff1_B[45],txB87,txB93,rd>0&&rd<Total_rd+1);
            sendB<46>(buff1_B[46],txB88,txB94,rd>0&&rd<Total_rd+1);
            sendB<47>(buff1_B[47],txB89,txB95,rd>0&&rd<Total_rd+1);
            

            receiveC<0>(buff1_C[0],rxC0, rd>0&&rd<Total_rd+1);
            receiveC<1>(buff1_C[1],rxC1, rd>0&&rd<Total_rd+1);
            receiveC<2>(buff1_C[2],rxC2, rd>0&&rd<Total_rd+1);
            receiveC<3>(buff1_C[3],rxC3, rd>0&&rd<Total_rd+1);
            receiveC<4>(buff1_C[4],rxC4, rd>0&&rd<Total_rd+1);
            receiveC<5>(buff1_C[5],rxC5, rd>0&&rd<Total_rd+1);
            receiveC<6>(buff1_C[6],rxC6, rd>0&&rd<Total_rd+1);
            receiveC<7>(buff1_C[7],rxC7, rd>0&&rd<Total_rd+1);
            receiveC<8>(buff1_C[8],rxC8, rd>0&&rd<Total_rd+1);
            receiveC<9>(buff1_C[9],rxC9, rd>0&&rd<Total_rd+1);
            receiveC<10>(buff1_C[10],rxC10, rd>0&&rd<Total_rd+1);
            receiveC<11>(buff1_C[11],rxC11, rd>0&&rd<Total_rd+1);
            receiveC<12>(buff1_C[12],rxC12, rd>0&&rd<Total_rd+1);
            receiveC<13>(buff1_C[13],rxC13, rd>0&&rd<Total_rd+1);
            receiveC<14>(buff1_C[14],rxC14, rd>0&&rd<Total_rd+1);
            receiveC<15>(buff1_C[15],rxC15, rd>0&&rd<Total_rd+1);
            

            storeC(dataC_in, buff0_C, rd>TY&&s_flg==(TY-1));
        }
        else{ //if(rd%2==1&&c_flg==1)
            loadA(dataA_out,buff1_A,rd<Total_rd);
            loadB(dataB_out,buff1_B,rd<Total_rd);   

            sendA<0>(buff0_A[0],txA0,txA6,rd>0&&rd<Total_rd+1);
            sendA<1>(buff0_A[1],txA1,txA7,rd>0&&rd<Total_rd+1);
            sendA<2>(buff0_A[2],txA2,txA8,rd>0&&rd<Total_rd+1);
            sendA<3>(buff0_A[3],txA3,txA9,rd>0&&rd<Total_rd+1);
            sendA<4>(buff0_A[4],txA4,txA10,rd>0&&rd<Total_rd+1);
            sendA<5>(buff0_A[5],txA5,txA11,rd>0&&rd<Total_rd+1);
            sendA<6>(buff0_A[6],txA12,txA18,rd>0&&rd<Total_rd+1);
            sendA<7>(buff0_A[7],txA13,txA19,rd>0&&rd<Total_rd+1);
            sendA<8>(buff0_A[8],txA14,txA20,rd>0&&rd<Total_rd+1);
            sendA<9>(buff0_A[9],txA15,txA21,rd>0&&rd<Total_rd+1);
            sendA<10>(buff0_A[10],txA16,txA22,rd>0&&rd<Total_rd+1);
            sendA<11>(buff0_A[11],txA17,txA23,rd>0&&rd<Total_rd+1);
            sendA<12>(buff0_A[12],txA24,txA30,rd>0&&rd<Total_rd+1);
            sendA<13>(buff0_A[13],txA25,txA31,rd>0&&rd<Total_rd+1);
            sendA<14>(buff0_A[14],txA26,txA32,rd>0&&rd<Total_rd+1);
            sendA<15>(buff0_A[15],txA27,txA33,rd>0&&rd<Total_rd+1);
            sendA<16>(buff0_A[16],txA28,txA34,rd>0&&rd<Total_rd+1);
            sendA<17>(buff0_A[17],txA29,txA35,rd>0&&rd<Total_rd+1);
            sendA<18>(buff0_A[18],txA36,txA42,rd>0&&rd<Total_rd+1);
            sendA<19>(buff0_A[19],txA37,txA43,rd>0&&rd<Total_rd+1);
            sendA<20>(buff0_A[20],txA38,txA44,rd>0&&rd<Total_rd+1);
            sendA<21>(buff0_A[21],txA39,txA45,rd>0&&rd<Total_rd+1);
            sendA<22>(buff0_A[22],txA40,txA46,rd>0&&rd<Total_rd+1);
            sendA<23>(buff0_A[23],txA41,txA47,rd>0&&rd<Total_rd+1);
            

            sendB<0>(buff0_B[0],txB0,txB6,rd>0&&rd<Total_rd+1);
            sendB<1>(buff0_B[1],txB1,txB7,rd>0&&rd<Total_rd+1);
            sendB<2>(buff0_B[2],txB2,txB8,rd>0&&rd<Total_rd+1);
            sendB<3>(buff0_B[3],txB3,txB9,rd>0&&rd<Total_rd+1);
            sendB<4>(buff0_B[4],txB4,txB10,rd>0&&rd<Total_rd+1);
            sendB<5>(buff0_B[5],txB5,txB11,rd>0&&rd<Total_rd+1);
            sendB<6>(buff0_B[6],txB12,txB18,rd>0&&rd<Total_rd+1);
            sendB<7>(buff0_B[7],txB13,txB19,rd>0&&rd<Total_rd+1);
            sendB<8>(buff0_B[8],txB14,txB20,rd>0&&rd<Total_rd+1);
            sendB<9>(buff0_B[9],txB15,txB21,rd>0&&rd<Total_rd+1);
            sendB<10>(buff0_B[10],txB16,txB22,rd>0&&rd<Total_rd+1);
            sendB<11>(buff0_B[11],txB17,txB23,rd>0&&rd<Total_rd+1);
            sendB<12>(buff0_B[12],txB24,txB30,rd>0&&rd<Total_rd+1);
            sendB<13>(buff0_B[13],txB25,txB31,rd>0&&rd<Total_rd+1);
            sendB<14>(buff0_B[14],txB26,txB32,rd>0&&rd<Total_rd+1);
            sendB<15>(buff0_B[15],txB27,txB33,rd>0&&rd<Total_rd+1);
            sendB<16>(buff0_B[16],txB28,txB34,rd>0&&rd<Total_rd+1);
            sendB<17>(buff0_B[17],txB29,txB35,rd>0&&rd<Total_rd+1);
            sendB<18>(buff0_B[18],txB36,txB42,rd>0&&rd<Total_rd+1);
            sendB<19>(buff0_B[19],txB37,txB43,rd>0&&rd<Total_rd+1);
            sendB<20>(buff0_B[20],txB38,txB44,rd>0&&rd<Total_rd+1);
            sendB<21>(buff0_B[21],txB39,txB45,rd>0&&rd<Total_rd+1);
            sendB<22>(buff0_B[22],txB40,txB46,rd>0&&rd<Total_rd+1);
            sendB<23>(buff0_B[23],txB41,txB47,rd>0&&rd<Total_rd+1);
            sendB<24>(buff0_B[24],txB48,txB54,rd>0&&rd<Total_rd+1);
            sendB<25>(buff0_B[25],txB49,txB55,rd>0&&rd<Total_rd+1);
            sendB<26>(buff0_B[26],txB50,txB56,rd>0&&rd<Total_rd+1);
            sendB<27>(buff0_B[27],txB51,txB57,rd>0&&rd<Total_rd+1);
            sendB<28>(buff0_B[28],txB52,txB58,rd>0&&rd<Total_rd+1);
            sendB<29>(buff0_B[29],txB53,txB59,rd>0&&rd<Total_rd+1);
            sendB<30>(buff0_B[30],txB60,txB66,rd>0&&rd<Total_rd+1);
            sendB<31>(buff0_B[31],txB61,txB67,rd>0&&rd<Total_rd+1);
            sendB<32>(buff0_B[32],txB62,txB68,rd>0&&rd<Total_rd+1);
            sendB<33>(buff0_B[33],txB63,txB69,rd>0&&rd<Total_rd+1);
            sendB<34>(buff0_B[34],txB64,txB70,rd>0&&rd<Total_rd+1);
            sendB<35>(buff0_B[35],txB65,txB71,rd>0&&rd<Total_rd+1);
            sendB<36>(buff0_B[36],txB72,txB78,rd>0&&rd<Total_rd+1);
            sendB<37>(buff0_B[37],txB73,txB79,rd>0&&rd<Total_rd+1);
            sendB<38>(buff0_B[38],txB74,txB80,rd>0&&rd<Total_rd+1);
            sendB<39>(buff0_B[39],txB75,txB81,rd>0&&rd<Total_rd+1);
            sendB<40>(buff0_B[40],txB76,txB82,rd>0&&rd<Total_rd+1);
            sendB<41>(buff0_B[41],txB77,txB83,rd>0&&rd<Total_rd+1);
            sendB<42>(buff0_B[42],txB84,txB90,rd>0&&rd<Total_rd+1);
            sendB<43>(buff0_B[43],txB85,txB91,rd>0&&rd<Total_rd+1);
            sendB<44>(buff0_B[44],txB86,txB92,rd>0&&rd<Total_rd+1);
            sendB<45>(buff0_B[45],txB87,txB93,rd>0&&rd<Total_rd+1);
            sendB<46>(buff0_B[46],txB88,txB94,rd>0&&rd<Total_rd+1);
            sendB<47>(buff0_B[47],txB89,txB95,rd>0&&rd<Total_rd+1);
            

            receiveC<0>(buff1_C[0],rxC0, rd>0&&rd<Total_rd+1);
            receiveC<1>(buff1_C[1],rxC1, rd>0&&rd<Total_rd+1);
            receiveC<2>(buff1_C[2],rxC2, rd>0&&rd<Total_rd+1);
            receiveC<3>(buff1_C[3],rxC3, rd>0&&rd<Total_rd+1);
            receiveC<4>(buff1_C[4],rxC4, rd>0&&rd<Total_rd+1);
            receiveC<5>(buff1_C[5],rxC5, rd>0&&rd<Total_rd+1);
            receiveC<6>(buff1_C[6],rxC6, rd>0&&rd<Total_rd+1);
            receiveC<7>(buff1_C[7],rxC7, rd>0&&rd<Total_rd+1);
            receiveC<8>(buff1_C[8],rxC8, rd>0&&rd<Total_rd+1);
            receiveC<9>(buff1_C[9],rxC9, rd>0&&rd<Total_rd+1);
            receiveC<10>(buff1_C[10],rxC10, rd>0&&rd<Total_rd+1);
            receiveC<11>(buff1_C[11],rxC11, rd>0&&rd<Total_rd+1);
            receiveC<12>(buff1_C[12],rxC12, rd>0&&rd<Total_rd+1);
            receiveC<13>(buff1_C[13],rxC13, rd>0&&rd<Total_rd+1);
            receiveC<14>(buff1_C[14],rxC14, rd>0&&rd<Total_rd+1);
            receiveC<15>(buff1_C[15],rxC15, rd>0&&rd<Total_rd+1);
            

            storeC(dataC_in, buff0_C, rd>TY&&s_flg==(TY-1));
        }
    }
}

void dma0(ap_uint<AXI_WIDTH_A>* ina, ap_uint<AXI_WIDTH_B>* inb, ap_uint<AXI_WIDTH_C>* out0,
         axis_stream& txA0, axis_stream& txA1, axis_stream& txA2, axis_stream& txA3,
         axis_stream& txA4, axis_stream& txA5, axis_stream& txA6, axis_stream& txA7,
         axis_stream& txA8, axis_stream& txA9, axis_stream& txA10, axis_stream& txA11,
         axis_stream& txA12, axis_stream& txA13, axis_stream& txA14, axis_stream& txA15,
         axis_stream& txA16, axis_stream& txA17, axis_stream& txA18, axis_stream& txA19,
         axis_stream& txA20, axis_stream& txA21, axis_stream& txA22, axis_stream& txA23,
         axis_stream& txA24, axis_stream& txA25, axis_stream& txA26, axis_stream& txA27,
         axis_stream& txA28, axis_stream& txA29, axis_stream& txA30, axis_stream& txA31,
         axis_stream& txA32, axis_stream& txA33, axis_stream& txA34, axis_stream& txA35,
         axis_stream& txA36, axis_stream& txA37, axis_stream& txA38, axis_stream& txA39,
         axis_stream& txA40, axis_stream& txA41, axis_stream& txA42, axis_stream& txA43,
         axis_stream& txA44, axis_stream& txA45, axis_stream& txA46, axis_stream& txA47,
         axis_stream& txB0, axis_stream& txB1, axis_stream& txB2, axis_stream& txB3,
         axis_stream& txB4, axis_stream& txB5, axis_stream& txB6, axis_stream& txB7,
         axis_stream& txB8, axis_stream& txB9, axis_stream& txB10, axis_stream& txB11,
         axis_stream& txB12, axis_stream& txB13, axis_stream& txB14, axis_stream& txB15,
         axis_stream& txB16, axis_stream& txB17, axis_stream& txB18, axis_stream& txB19,
         axis_stream& txB20, axis_stream& txB21, axis_stream& txB22, axis_stream& txB23,
         axis_stream& txB24, axis_stream& txB25, axis_stream& txB26, axis_stream& txB27,
         axis_stream& txB28, axis_stream& txB29, axis_stream& txB30, axis_stream& txB31,
         axis_stream& txB32, axis_stream& txB33, axis_stream& txB34, axis_stream& txB35,
         axis_stream& txB36, axis_stream& txB37, axis_stream& txB38, axis_stream& txB39,
         axis_stream& txB40, axis_stream& txB41, axis_stream& txB42, axis_stream& txB43,
         axis_stream& txB44, axis_stream& txB45, axis_stream& txB46, axis_stream& txB47,
         axis_stream& txB48, axis_stream& txB49, axis_stream& txB50, axis_stream& txB51,
         axis_stream& txB52, axis_stream& txB53, axis_stream& txB54, axis_stream& txB55,
         axis_stream& txB56, axis_stream& txB57, axis_stream& txB58, axis_stream& txB59,
         axis_stream& txB60, axis_stream& txB61, axis_stream& txB62, axis_stream& txB63,
         axis_stream& txB64, axis_stream& txB65, axis_stream& txB66, axis_stream& txB67,
         axis_stream& txB68, axis_stream& txB69, axis_stream& txB70, axis_stream& txB71,
         axis_stream& txB72, axis_stream& txB73, axis_stream& txB74, axis_stream& txB75,
         axis_stream& txB76, axis_stream& txB77, axis_stream& txB78, axis_stream& txB79,
         axis_stream& txB80, axis_stream& txB81, axis_stream& txB82, axis_stream& txB83,
         axis_stream& txB84, axis_stream& txB85, axis_stream& txB86, axis_stream& txB87,
         axis_stream& txB88, axis_stream& txB89, axis_stream& txB90, axis_stream& txB91,
         axis_stream& txB92, axis_stream& txB93, axis_stream& txB94, axis_stream& txB95,
         axis_stream& rxC0, axis_stream& rxC1, axis_stream& rxC2, axis_stream& rxC3,
         axis_stream& rxC4, axis_stream& rxC5, axis_stream& rxC6, axis_stream& rxC7,
         axis_stream& rxC8, axis_stream& rxC9, axis_stream& rxC10, axis_stream& rxC11,
         axis_stream& rxC12, axis_stream& rxC13, axis_stream& rxC14, axis_stream& rxC15,
         const int TX, const int TY, const int TZ){
    
    #pragma HLS interface m_axi offset=slave bundle=gmem0 port=ina max_read_burst_length=16 num_read_outstanding=64
    #pragma HLS interface s_axilite bundle=control port=ina
    #pragma HLS interface m_axi offset=slave bundle=gmem1 port=inb max_read_burst_length=16 num_read_outstanding=64
    #pragma HLS interface s_axilite bundle=control port=inb
    #pragma HLS interface m_axi offset=slave bundle=gmem2 port=out0 max_write_burst_length=16 num_write_outstanding=64
    #pragma HLS interface s_axilite bundle=control port=out0
    #pragma HLS interface s_axilite bundle=control port=TX
    #pragma HLS interface s_axilite bundle=control port=TY
    #pragma HLS interface s_axilite bundle=control port=TZ
    #pragma HLS interface axis port=txA0
    #pragma HLS interface axis port=txA1
    #pragma HLS interface axis port=txA2
    #pragma HLS interface axis port=txA3
    #pragma HLS interface axis port=txA4
    #pragma HLS interface axis port=txA5
    #pragma HLS interface axis port=txA6
    #pragma HLS interface axis port=txA7
    #pragma HLS interface axis port=txA8
    #pragma HLS interface axis port=txA9
    #pragma HLS interface axis port=txA10
    #pragma HLS interface axis port=txA11
    #pragma HLS interface axis port=txA12
    #pragma HLS interface axis port=txA13
    #pragma HLS interface axis port=txA14
    #pragma HLS interface axis port=txA15
    #pragma HLS interface axis port=txA16
    #pragma HLS interface axis port=txA17
    #pragma HLS interface axis port=txA18
    #pragma HLS interface axis port=txA19
    #pragma HLS interface axis port=txA20
    #pragma HLS interface axis port=txA21
    #pragma HLS interface axis port=txA22
    #pragma HLS interface axis port=txA23
    #pragma HLS interface axis port=txA24
    #pragma HLS interface axis port=txA25
    #pragma HLS interface axis port=txA26
    #pragma HLS interface axis port=txA27
    #pragma HLS interface axis port=txA28
    #pragma HLS interface axis port=txA29
    #pragma HLS interface axis port=txA30
    #pragma HLS interface axis port=txA31
    #pragma HLS interface axis port=txA32
    #pragma HLS interface axis port=txA33
    #pragma HLS interface axis port=txA34
    #pragma HLS interface axis port=txA35
    #pragma HLS interface axis port=txA36
    #pragma HLS interface axis port=txA37
    #pragma HLS interface axis port=txA38
    #pragma HLS interface axis port=txA39
    #pragma HLS interface axis port=txA40
    #pragma HLS interface axis port=txA41
    #pragma HLS interface axis port=txA42
    #pragma HLS interface axis port=txA43
    #pragma HLS interface axis port=txA44
    #pragma HLS interface axis port=txA45
    #pragma HLS interface axis port=txA46
    #pragma HLS interface axis port=txA47
    #pragma HLS interface axis port=txB0
    #pragma HLS interface axis port=txB1
    #pragma HLS interface axis port=txB2
    #pragma HLS interface axis port=txB3
    #pragma HLS interface axis port=txB4
    #pragma HLS interface axis port=txB5
    #pragma HLS interface axis port=txB6
    #pragma HLS interface axis port=txB7
    #pragma HLS interface axis port=txB8
    #pragma HLS interface axis port=txB9
    #pragma HLS interface axis port=txB10
    #pragma HLS interface axis port=txB11
    #pragma HLS interface axis port=txB12
    #pragma HLS interface axis port=txB13
    #pragma HLS interface axis port=txB14
    #pragma HLS interface axis port=txB15
    #pragma HLS interface axis port=txB16
    #pragma HLS interface axis port=txB17
    #pragma HLS interface axis port=txB18
    #pragma HLS interface axis port=txB19
    #pragma HLS interface axis port=txB20
    #pragma HLS interface axis port=txB21
    #pragma HLS interface axis port=txB22
    #pragma HLS interface axis port=txB23
    #pragma HLS interface axis port=txB24
    #pragma HLS interface axis port=txB25
    #pragma HLS interface axis port=txB26
    #pragma HLS interface axis port=txB27
    #pragma HLS interface axis port=txB28
    #pragma HLS interface axis port=txB29
    #pragma HLS interface axis port=txB30
    #pragma HLS interface axis port=txB31
    #pragma HLS interface axis port=txB32
    #pragma HLS interface axis port=txB33
    #pragma HLS interface axis port=txB34
    #pragma HLS interface axis port=txB35
    #pragma HLS interface axis port=txB36
    #pragma HLS interface axis port=txB37
    #pragma HLS interface axis port=txB38
    #pragma HLS interface axis port=txB39
    #pragma HLS interface axis port=txB40
    #pragma HLS interface axis port=txB41
    #pragma HLS interface axis port=txB42
    #pragma HLS interface axis port=txB43
    #pragma HLS interface axis port=txB44
    #pragma HLS interface axis port=txB45
    #pragma HLS interface axis port=txB46
    #pragma HLS interface axis port=txB47
    #pragma HLS interface axis port=txB48
    #pragma HLS interface axis port=txB49
    #pragma HLS interface axis port=txB50
    #pragma HLS interface axis port=txB51
    #pragma HLS interface axis port=txB52
    #pragma HLS interface axis port=txB53
    #pragma HLS interface axis port=txB54
    #pragma HLS interface axis port=txB55
    #pragma HLS interface axis port=txB56
    #pragma HLS interface axis port=txB57
    #pragma HLS interface axis port=txB58
    #pragma HLS interface axis port=txB59
    #pragma HLS interface axis port=txB60
    #pragma HLS interface axis port=txB61
    #pragma HLS interface axis port=txB62
    #pragma HLS interface axis port=txB63
    #pragma HLS interface axis port=txB64
    #pragma HLS interface axis port=txB65
    #pragma HLS interface axis port=txB66
    #pragma HLS interface axis port=txB67
    #pragma HLS interface axis port=txB68
    #pragma HLS interface axis port=txB69
    #pragma HLS interface axis port=txB70
    #pragma HLS interface axis port=txB71
    #pragma HLS interface axis port=txB72
    #pragma HLS interface axis port=txB73
    #pragma HLS interface axis port=txB74
    #pragma HLS interface axis port=txB75
    #pragma HLS interface axis port=txB76
    #pragma HLS interface axis port=txB77
    #pragma HLS interface axis port=txB78
    #pragma HLS interface axis port=txB79
    #pragma HLS interface axis port=txB80
    #pragma HLS interface axis port=txB81
    #pragma HLS interface axis port=txB82
    #pragma HLS interface axis port=txB83
    #pragma HLS interface axis port=txB84
    #pragma HLS interface axis port=txB85
    #pragma HLS interface axis port=txB86
    #pragma HLS interface axis port=txB87
    #pragma HLS interface axis port=txB88
    #pragma HLS interface axis port=txB89
    #pragma HLS interface axis port=txB90
    #pragma HLS interface axis port=txB91
    #pragma HLS interface axis port=txB92
    #pragma HLS interface axis port=txB93
    #pragma HLS interface axis port=txB94
    #pragma HLS interface axis port=txB95
    #pragma HLS interface axis port=rxC0
    #pragma HLS interface axis port=rxC1
    #pragma HLS interface axis port=rxC2
    #pragma HLS interface axis port=rxC3
    #pragma HLS interface axis port=rxC4
    #pragma HLS interface axis port=rxC5
    #pragma HLS interface axis port=rxC6
    #pragma HLS interface axis port=rxC7
    #pragma HLS interface axis port=rxC8
    #pragma HLS interface axis port=rxC9
    #pragma HLS interface axis port=rxC10
    #pragma HLS interface axis port=rxC11
    #pragma HLS interface axis port=rxC12
    #pragma HLS interface axis port=rxC13
    #pragma HLS interface axis port=rxC14
    #pragma HLS interface axis port=rxC15
    #pragma HLS interface s_axilite bundle=control port=return

    #pragma HLS dataflow
    axis_stream_A dataA_out;
    axis_stream_B dataB_out;
    axis_stream_C dataC_in;
    axis_stream_32 addrA_out;
    axis_stream_32 addrB_out;
    axis_stream_32 addrC_out;

    address_A_ddr(addrA_out,TX,TY,TZ);
    loadA_ddr(ina, addrA_out,dataA_out,TX,TY,TZ);

    address_B_ddr(addrB_out,TX,TY,TZ);
    loadB_ddr(inb,addrB_out,dataB_out,TX,TY,TZ);

    address_C_ddr(addrC_out,TX,TZ);
    storeC_ddr(out0,addrC_out,dataC_in,TX,TZ);

    compute(dataA_out, dataB_out, dataC_in,
            txA0, txA1, txA2, txA3,
            txA4, txA5, txA6, txA7,
            txA8, txA9, txA10, txA11,
            txA12, txA13, txA14, txA15,
            txA16, txA17, txA18, txA19,
            txA20, txA21, txA22, txA23,
            txA24, txA25, txA26, txA27,
            txA28, txA29, txA30, txA31,
            txA32, txA33, txA34, txA35,
            txA36, txA37, txA38, txA39,
            txA40, txA41, txA42, txA43,
            txA44, txA45, txA46, txA47,
            txB0, txB1, txB2, txB3,
            txB4, txB5, txB6, txB7,
            txB8, txB9, txB10, txB11,
            txB12, txB13, txB14, txB15,
            txB16, txB17, txB18, txB19,
            txB20, txB21, txB22, txB23,
            txB24, txB25, txB26, txB27,
            txB28, txB29, txB30, txB31,
            txB32, txB33, txB34, txB35,
            txB36, txB37, txB38, txB39,
            txB40, txB41, txB42, txB43,
            txB44, txB45, txB46, txB47,
            txB48, txB49, txB50, txB51,
            txB52, txB53, txB54, txB55,
            txB56, txB57, txB58, txB59,
            txB60, txB61, txB62, txB63,
            txB64, txB65, txB66, txB67,
            txB68, txB69, txB70, txB71,
            txB72, txB73, txB74, txB75,
            txB76, txB77, txB78, txB79,
            txB80, txB81, txB82, txB83,
            txB84, txB85, txB86, txB87,
            txB88, txB89, txB90, txB91,
            txB92, txB93, txB94, txB95,
            rxC0, rxC1, rxC2, rxC3,
            rxC4, rxC5, rxC6, rxC7,
            rxC8, rxC9, rxC10, rxC11,
            rxC12, rxC13, rxC14, rxC15,
            TX, TY, TZ);

}