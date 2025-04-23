#include <stdint.h>
#include "dma0.hpp"
#include <stdio.h>
void address_A0_ddr(axis_stream_32 &addrA_out, const int TX, const int TY, const int TZ)
{
#pragma HLS inline off
    for (int tx = 0; tx < TX; tx++)
    {
        for (int tz = 0; tz < TZ; tz++)
        {
            for (int ty = 0; ty < TY; ty++)
            {
                ap_uint<32> pos;
                for (int j = 0; j < K; j++)
                {
                    for (int i = 0; i < M / A_PER_TRA / NO_R_PORTS; i++)
                    {
#pragma HLS PIPELINE II = 1
                        pos = i + j * (M / A_PER_TRA) * TX + ty * K * (M / A_PER_TRA) * TX + tx * (M / A_PER_TRA);
                        addrA_out.write(pos);
                        // printf("A0_ddr pos: %d\n", pos);
                    }
                }
            }
        }
    }
}

void address_A1_ddr(axis_stream_32 &addrA_out, const int TX, const int TY, const int TZ)
{
#pragma HLS inline off
    for (int tx = 0; tx < TX; tx++)
    {
        for (int tz = 0; tz < TZ; tz++)
        {
            for (int ty = 0; ty < TY; ty++)
            {
                ap_uint<32> pos;
                for (int j = 0; j < K; j++)
                {
                    for (int i = 0; i < M / A_PER_TRA / NO_R_PORTS; i++)
                    {
#pragma HLS PIPELINE II = 1
                        pos = i + j * (M / A_PER_TRA) * TX + ty * K * (M / A_PER_TRA) * TX + tx * (M / A_PER_TRA);
                        addrA_out.write(pos);
                        // printf("A1_ddr pos: %d\n", pos);
                    }
                }
            }
        }
    }
}

void loadA0_ddr(ap_uint<AXI_WIDTH_A> *ina, axis_stream_32 &addrA_in, axis_stream_A &dataA_out, const int TX, const int TY, const int TZ)
{
#pragma HLS inline off
    ap_uint<AXI_WIDTH_A> temp_data;
    int bound = boundA * TX * TY * TZ;
    for (int i = 0; i < bound / NO_R_PORTS; i++)
    {
#pragma HLS PIPELINE II = 1
        int addr = addrA_in.read();
        temp_data = ina[addr];
        dataA_out.write(temp_data);
        // printf("A0 i = %d tempdata = %x \n", i, temp_data);
    }
}

void loadA1_ddr(ap_uint<AXI_WIDTH_A> *ina, axis_stream_32 &addrA_in, axis_stream_A &dataA_out, const int TX, const int TY, const int TZ)
{
#pragma HLS inline off
    ap_uint<AXI_WIDTH_A> temp_data;
    int bound = boundA * TX * TY * TZ;
    for (int i = 0; i < bound / NO_R_PORTS; i++)
    {
#pragma HLS PIPELINE II = 1
        int addr = addrA_in.read();
        temp_data = ina[addr];
        dataA_out.write(temp_data);
        // printf("A1 i = %d tempdata = %x \n", i, temp_data);
    }
}

void address_B0_ddr(axis_stream_32 &addrB_out, const int TX, const int TY, const int TZ)
{
#pragma HLS inline off
    for (int tx = 0; tx < TX; tx++)
    {
        for (int tz = 0; tz < TZ; tz++)
        {
            for (int ty = 0; ty < TY; ty++)
            {
                ap_uint<32> pos;
                for (int j = 0; j < N; j++)
                {
                    for (int i = 0; i < K / B_PER_TRA / NO_R_PORTS; i++)
                    {
#pragma HLS PIPELINE II = 1
                        pos = i + j * (K / B_PER_TRA) * TY + ty * (K / B_PER_TRA) + tz * N * (K / B_PER_TRA) * TY;
                        addrB_out.write(pos);
                    }
                }
            }
        }
    }
}

void address_B1_ddr(axis_stream_32 &addrB_out, const int TX, const int TY, const int TZ)
{
#pragma HLS inline off
    for (int tx = 0; tx < TX; tx++)
    {
        for (int tz = 0; tz < TZ; tz++)
        {
            for (int ty = 0; ty < TY; ty++)
            {
                ap_uint<32> pos;
                for (int j = 0; j < N; j++)
                {
                    for (int i = 0; i < K / B_PER_TRA / NO_R_PORTS; i++)
                    {
#pragma HLS PIPELINE II = 1
                        pos = i + j * (K / B_PER_TRA) * TY + ty * (K / B_PER_TRA) + tz * N * (K / B_PER_TRA) * TY;
                        addrB_out.write(pos);
                    }
                }
            }
        }
    }
}

void loadB0_ddr(ap_uint<AXI_WIDTH_B> *inb, axis_stream_32 &addrB_in, axis_stream_B &dataB_out, const int TX, const int TY, const int TZ)
{
#pragma HLS inline off
    ap_uint<AXI_WIDTH_B> temp_data;
    int bound = boundB * TX * TY * TZ;
    for (int i = 0; i < bound / NO_R_PORTS; i++)
    {
#pragma HLS PIPELINE II = 1
        ap_uint<32> addr = addrB_in.read();
        temp_data = inb[addr];
        dataB_out.write(temp_data);

        // printf("i : %d \n", i);
        // for (int i = 0; i < 16; i++)
        // {
        //     printf("d : %f ", (float)temp_data(i * 32 + 31, i * 32));
        // }
        // printf("\n");
    }
}

void loadB1_ddr(ap_uint<AXI_WIDTH_B> *inb, axis_stream_32 &addrB_in, axis_stream_B &dataB_out, const int TX, const int TY, const int TZ)
{
#pragma HLS inline off
    ap_uint<AXI_WIDTH_B> temp_data;
    int bound = boundB * TX * TY * TZ;
    for (int i = 0; i < bound / NO_R_PORTS; i++)
    {
#pragma HLS PIPELINE II = 1
        ap_uint<32> addr = addrB_in.read();
        temp_data = inb[addr];
        dataB_out.write(temp_data);

        // printf("i : %d \n", i);
        // for (int i = 0; i < 16; i++)
        // {
        //     printf("d : %f ", (float)temp_data(i * 32 + 31, i * 32));
        // }
        // printf("\n");
    }
}

void address_C0_ddr(axis_stream_32 &addrC_out, const int TX, const int TZ)
{
#pragma HLS inline off
int k = 0;
    for (int tx = 0; tx < TX; tx++)
    {
        for (int tz = 0; tz < TZ; tz++)
        {
            ap_uint<32> pos;
            for (int j = 0; j < N; j++)
            {
                for (int i = 0; i < M / C_PER_TRA/ NO_R_PORTS; i++)
                {
#pragma HLS PIPELINE II = 1
                    // pos = i + j * (M / C_PER_TRA) * TX + tx * (M / C_PER_TRA) + tz * N * (M / C_PER_TRA) * TX;
                    pos = k++;
                    addrC_out.write(pos);
                    // printf("C0_ddr pos: %d\n", pos);
                }
            }
        }
    }
}

void address_C1_ddr(axis_stream_32 &addrC_out, const int TX, const int TZ)
{
#pragma HLS inline off
int k = 0;
    for (int tx = 0; tx < TX; tx++)
    {
        for (int tz = 0; tz < TZ; tz++)
        {
            ap_uint<32> pos;
            for (int j = 0; j < N; j++)
            {
                for (int i = 0; i < M / C_PER_TRA/ NO_R_PORTS; i++)
                {
#pragma HLS PIPELINE II = 1
                    // pos = i + j * (M / C_PER_TRA) * TX + tx * (M / C_PER_TRA) + tz * N * (M / C_PER_TRA) * TX;
                    pos = k++;
                    addrC_out.write(pos);
                    // printf("C1_ddr pos: %d\n", pos);
                }
            }
        }
    }
}

void storeC0_ddr(ap_uint<AXI_WIDTH_C> *outc, axis_stream_32 &addrC_in, axis_stream_C &dataC_in, const int TX, const int TZ)
{
#pragma HLS inline off
    int bound = boundC * TX * TZ;
    // printf("bound : %d \n", bound);
    for (int i = 0; i < bound/ NO_R_PORTS; i++)
    {
#pragma HLS PIPELINE II = 1
        ap_uint<AXI_WIDTH_C> temp_data = dataC_in.read();
        ap_uint<32> addr = addrC_in.read();
        outc[addr] = temp_data;

        // printf("C0i : %d \n", i);
        // for (int i = 0; i < 16; i++)
        // {
        //     printf("Cd : %f ", (float)temp_data(i * 32 + 31, i * 32));
        // }
        // printf("\n");
    }
}

void storeC1_ddr(ap_uint<AXI_WIDTH_C> *outc, axis_stream_32 &addrC_in, axis_stream_C &dataC_in, const int TX, const int TZ)
{
#pragma HLS inline off
    int bound = boundC * TX * TZ;
    // printf("bound : %d \n", bound);
    for (int i = 0; i < bound/ NO_R_PORTS; i++)
    {
#pragma HLS PIPELINE II = 1
        ap_uint<AXI_WIDTH_C> temp_data = dataC_in.read();
        ap_uint<32> addr = addrC_in.read();
        outc[addr] = temp_data;

        // printf("C1i : %d addr: %d\n", i, addr);
        // for (int i = 0; i < 16; i++) 
        // {
        //     printf("Cd : %f ", (float)temp_data(i * 32 + 31, i * 32));
        // }
        // printf("\n");
    }
}

void loadA0(axis_stream_A &dataA_in, ap_uint<PLIO_WIDTH> a_buf[A * (B / PACK_IN)][X * Y][PACK_IN * LEFT_SIZE], bool enable)
{
#pragma HLS inline off
    if (enable)
    {
        for (int y = 0; y < Y; y++)
        {
            for (int k = 0; k < W1 * B; k++)
            {
                for (int x = 0; x < X; x++)
                {
                    for (int a = 0; a < A; a++)
                    {
                        for (int i = 0; i < (H1 / A_PER_TRA / NO_R_PORTS); i++)
                        {
#pragma HLS PIPELINE II = 1
#pragma HLS dependence variable = a_buf type = intra false
                            // A0 loading should have 0 as m in the pos0 calc, 1 is handled by A1
                            int pos0 = 0 * 4 + (k % (W1 * PACK_IN)) * (H1 / NUM_PER_TRA);
                            int pos1 = x * Y + y;
                            int pos2 = (k / (W1 * PACK_IN)) + a * (B / PACK_IN);
                            ap_uint<AXI_WIDTH_A> temp_data = dataA_in.read();
                            a_buf[pos2][pos1][pos0] = temp_data(127, 0);
                            a_buf[pos2][pos1][pos0 + 1] = temp_data(255, 128);
                            a_buf[pos2][pos1][pos0 + 2] = temp_data(383, 256);
                            a_buf[pos2][pos1][pos0 + 3] = temp_data(511, 384);

                            // printf("LA0 pos2 : %d pos1 : %d pos0 : %d \n", pos2,pos1,pos0);
                            // printf("i : %d \n", i);
                            // for (int i = 0; i < 16; i++)
                            // {
                            //     printf("LA0 : %f ", (float)temp_data(i * 32 + 31, i * 32));
                            // }
                            // printf("\n");
                        }
                    }
                }
            }
        }
    }
}

void loadA1(axis_stream_A &dataA_in, ap_uint<PLIO_WIDTH> a_buf[A * (B / PACK_IN)][X * Y][PACK_IN * LEFT_SIZE], bool enable)
{
#pragma HLS inline off
    if (enable)
    {
        for (int y = 0; y < Y; y++)
        {
            for (int k = 0; k < W1 * B; k++)
            {
                for (int x = 0; x < X; x++)
                {
                    for (int a = 0; a < A; a++)
                    {
                        for (int i = 0; i < (H1 / A_PER_TRA / NO_R_PORTS); i++)
                        {
#pragma HLS PIPELINE II = 1
#pragma HLS dependence variable = a_buf type = intra false
                            // A1 loading should have 1 as m in the pos0 calc, 0 is handled by A0
                            int pos0 = 1 * 4 + (k % (W1 * PACK_IN)) * (H1 / NUM_PER_TRA);
                            int pos1 = x * Y + y;
                            int pos2 = (k / (W1 * PACK_IN)) + a * (B / PACK_IN);
                            ap_uint<AXI_WIDTH_A> temp_data = dataA_in.read();
                            a_buf[pos2][pos1][pos0] = temp_data(127, 0);
                            a_buf[pos2][pos1][pos0 + 1] = temp_data(255, 128);
                            a_buf[pos2][pos1][pos0 + 2] = temp_data(383, 256);
                            a_buf[pos2][pos1][pos0 + 3] = temp_data(511, 384);

                            // printf("LA1 pos2 : %d pos1 : %d pos0 : %d \n", pos2,pos1,pos0);
                            // printf("i : %d \n", i);
                            // for (int i = 0; i < 16; i++)
                            // {
                            //     printf("LA1 : %f ", (float)temp_data(i * 32 + 31, i * 32));
                            // }
                            // printf("\n");
                        }
                    }
                }
            }
        }
    }
}

void loadB0(axis_stream_B &dataB_in, ap_uint<PLIO_WIDTH> b_buf[(B / PACK_IN) * C][Z * Y][PACK_IN * RIGHT_SIZE], bool enable)
{
#pragma HLS inline off
    if (enable)
    {
        for (int z = 0; z < Z; z++)
        {
            for (int c = 0; c < C; c++)
            {
                for (int w2 = 0; w2 < W2; w2++)
                {
                    for (int y = 0; y < Y; y++)
                    {
                        for (int b = 0; b < B; b++)
                        {
                            for (int m = 0; m < (W1 / B_PER_TRA/ NO_R_PORTS); m++)
                            {
#pragma HLS PIPELINE II = 1
#pragma HLS dependence variable = b_buf type = intra false
                                // B0 loading has 0 as m in the pos0 calc, 1 is handled by B1
                                int pos0 = 0 * 4 + w2 * (W1 / NUM_PER_TRA) + (b % PACK_IN) * RIGHT_SIZE;
                                int pos1 = y + z * Y;
                                int pos2 = (b / PACK_IN) + c * (B / PACK_IN);
                                ap_uint<AXI_WIDTH_B> temp_data = dataB_in.read();
                                b_buf[pos2][pos1][pos0] = temp_data(127, 0);
                                b_buf[pos2][pos1][pos0 + 1] = temp_data(255, 128);
                                b_buf[pos2][pos1][pos0 + 2] = temp_data(383, 256);
                                b_buf[pos2][pos1][pos0 + 3] = temp_data(511, 384);

                                // printf("B0 pos2 : %d pos1 : %d pos0 : %d \n", pos2,pos1,pos0);
                                // printf("B0m : %d \n", m);
                                // for (int i = 0; i < 16; i++)
                                // {
                                //     printf("B0 : %f ", (float)temp_data(i * 32 + 31, i * 32));
                                // }
                                // printf("\n");
                            }
                        }
                    }
                }
            }
        }
    }
}

void loadB1(axis_stream_B &dataB_in, ap_uint<PLIO_WIDTH> b_buf[(B / PACK_IN) * C][Z * Y][PACK_IN * RIGHT_SIZE], bool enable)
{
#pragma HLS inline off
    if (enable)
    {
        for (int z = 0; z < Z; z++)
        {
            for (int c = 0; c < C; c++)
            {
                for (int w2 = 0; w2 < W2; w2++)
                {
                    for (int y = 0; y < Y; y++)
                    {
                        for (int b = 0; b < B; b++)
                        {
                            for (int m = 0; m < (W1 / B_PER_TRA/ NO_R_PORTS); m++)
                            {
#pragma HLS PIPELINE II = 1
#pragma HLS dependence variable = b_buf type = intra false
                                // B1 loading should have 1 as m in the pos0 calc, 0 is handled by B0
                                int pos0 = 1 * 4 + w2 * (W1 / NUM_PER_TRA) + (b % PACK_IN) * RIGHT_SIZE;
                                int pos1 = y + z * Y;
                                int pos2 = (b / PACK_IN) + c * (B / PACK_IN);
                                ap_uint<AXI_WIDTH_B> temp_data = dataB_in.read();
                                b_buf[pos2][pos1][pos0] = temp_data(127, 0);
                                b_buf[pos2][pos1][pos0 + 1] = temp_data(255, 128);
                                b_buf[pos2][pos1][pos0 + 2] = temp_data(383, 256);
                                b_buf[pos2][pos1][pos0 + 3] = temp_data(511, 384);

                                // printf("B1 pos2 : %d pos1 : %d pos0 : %d \n", pos2,pos1,pos0);
                                // printf("B1m : %d \n", m);
                                // for (int i = 0; i < 16; i++)
                                // {
                                //     printf("B1 : %f ", (float)temp_data(i * 32 + 31, i * 32));
                                // }
                                // printf("\n");
                            }
                        }
                    }
                }
            }
        }
    }
}

void storeC0(axis_stream_C &dataC_out, ap_uint<PLIO_WIDTH> c_buf[(C / PACK_OUT) * A][Z * X][PACK_OUT][OUT_SIZE], bool enable)
{
#pragma HLS inline off
    if (enable)
    {
        for (int z = 0; z < Z; z++)
        {
            for (int c = 0; c < C / NO_R_PORTS; c++)
            {
                for (int w2 = 0; w2 < W2; w2++)
                {
                    for (int x = 0; x < X; x++)
                    {
                        for (int a = 0; a < A; a++)
                        {
                            for (int n = 0; n < (H1 / C_PER_TRA); n++)
                            {
#pragma HLS PIPELINE II = 1
#pragma HLS dependence variable = c_buf type = intra false
                                int pos0 = n * 4 + w2 * (H1 / NUM_PER_TRA);
                                int pos1 = c % PACK_OUT;
                                int pos2 = x + z * X;
                                int pos3 = (c / PACK_OUT) + a * (C / PACK_OUT);
                                ap_uint<AXI_WIDTH_C> temp_data;
                                // printf("pos3 : %d ", pos3);
                                // printf("pos2 : %d ", pos2);
                                // printf("pos1 : %d ", pos1);
                                // printf("pos0 : %d \n", pos0);
                                temp_data(127, 0) = c_buf[pos3][pos2][pos1][pos0];
                                temp_data(255, 128) = c_buf[pos3][pos2][pos1][pos0 + 1];
                                temp_data(383, 256) = c_buf[pos3][pos2][pos1][pos0 + 2];
                                temp_data(511, 384) = c_buf[pos3][pos2][pos1][pos0 + 3];

                                // ap_uint<32> float_128 = 0x43000000;

                                // // Construct the 512-bit value by repeating the float value 16 times
                                // temp_data = 0;
                                // for (int i = 0; i < 16; ++i) {
                                //     temp_data = (temp_data << 32) | float_128;
                                // }

                                // printf("C0 pos3 : %d pos2 : %d pos1 : %d pos0 : %d \n", pos3,pos2,pos1,pos0);
                                // // printf("i : %d \n", i);
                                // for (int i = 0; i < 16; i++)
                                // {
                                //     printf("Sc0d : %f ", (float)temp_data(i * 32 + 31, i * 32));
                                // }
                                // printf("\n");

                                dataC_out.write(temp_data);
                            }
                        }
                    }
                }
            }
        }

        for (int x = 0; x < X * Z; x++)
        {
            // 2 and 3 are done by StoreC1 thus pack for StoreC0 should end at 2
            for (int pack = 0; pack < PACK_OUT/NO_R_PORTS; pack++)
            {
                for (int i = 0; i < OUT_SIZE / 4; i++)
                {
#pragma HLS PIPELINE II = 1
#pragma HLS dependence variable = c_buf type = intra false
                    for (int a = 0; a < (C / PACK_OUT) * A; a++)
                    {
                        int pos0 = i * 4;
                        c_buf[a][x][pack][pos0 + 0] = 0;
                        c_buf[a][x][pack][pos0 + 1] = 0;
                        c_buf[a][x][pack][pos0 + 2] = 0;
                        c_buf[a][x][pack][pos0 + 3] = 0;
                    }
                }
            }
        }
    }
}

void storeC1(axis_stream_C &dataC_out, ap_uint<PLIO_WIDTH> c_buf[(C / PACK_OUT) * A][Z * X][PACK_OUT][OUT_SIZE], bool enable)
{
#pragma HLS inline off
    if (enable)
    {
        for (int z = 0; z < Z; z++)
        {
            for (int c = 2; c < C; c++)
            {
                for (int w2 = 0; w2 < W2; w2++)
                {
                    for (int x = 0; x < X; x++)
                    {
                        for (int a = 0; a < A; a++)
                        {
                            for (int n = 0; n < (H1 / C_PER_TRA); n++)
                            {
#pragma HLS PIPELINE II = 1
#pragma HLS dependence variable = c_buf type = intra false
                                int pos0 = n * 4 + w2 * (H1 / NUM_PER_TRA);
                                int pos1 = c % PACK_OUT;
                                int pos2 = x + z * X;
                                int pos3 = (c / PACK_OUT) + a * (C / PACK_OUT);
                                ap_uint<AXI_WIDTH_C> temp_data;
                                temp_data(127, 0) = c_buf[pos3][pos2][pos1][pos0];
                                temp_data(255, 128) = c_buf[pos3][pos2][pos1][pos0 + 1];
                                temp_data(383, 256) = c_buf[pos3][pos2][pos1][pos0 + 2];
                                temp_data(511, 384) = c_buf[pos3][pos2][pos1][pos0 + 3];

                                // ap_uint<32> float_128 = 0x43000000;

                                // // Construct the 512-bit value by repeating the float value 16 times
                                // temp_data = 0;
                                // for (int i = 0; i < 16; ++i) {
                                //     temp_data = (temp_data << 32) | float_128;
                                // }
                   
                                // printf("C1 pos3 : %d pos2 : %d pos1 : %d pos0 : %d \n", pos3,pos2,pos1,pos0);
                                // printf("i : %d \n", i);
                                // for (int i = 0; i < 16; i++)
                                // {
                                //     printf("C1 Scd : %f ", (float)temp_data(i * 32 + 31, i * 32));
                                // }
                                // printf("\n");

                                dataC_out.write(temp_data);
                            }
                        }
                    }
                }
            }
        }

        for (int x = 0; x < X * Z; x++)
        {
            // 0 and 1 are done by StoreC0 thus pack for StoreC1 should start at 2
            for (int pack = 2; pack < PACK_OUT; pack++)
            {
                for (int i = 0; i < OUT_SIZE / 4; i++)
                {
#pragma HLS PIPELINE II = 1
#pragma HLS dependence variable = c_buf type = intra false
                    for (int a = 0; a < (C / PACK_OUT) * A; a++)
                    {
                        int pos0 = i * 4;
                        c_buf[a][x][pack][pos0 + 0] = 0;
                        c_buf[a][x][pack][pos0 + 1] = 0;
                        c_buf[a][x][pack][pos0 + 2] = 0;
                        c_buf[a][x][pack][pos0 + 3] = 0;
                    }
                }
            }
        }
    }
}

ap_uint<32> generateHeader(unsigned int pktType, unsigned int ID)
{
#pragma HLS inline
    ap_uint<32> header = 0;
    header(4, 0) = ID;
    header(11, 5) = 0;
    header(14, 12) = pktType;
    header[15] = 0;
    header(20, 16) = -1; // source row
    header(27, 21) = -1; // source column
    header(30, 28) = 0;
    header[31] = header(30, 0).xor_reduce() ? (ap_uint<1>)0 : (ap_uint<1>)1;
    return header;
}

unsigned int getPacketId(ap_uint<32> header)
{
#pragma HLS inline
    ap_uint<32> ID = 0;
    ID(4, 0) = header(4, 0);
    return ID;
}

template <int NC>
void sendA(ap_uint<PLIO_WIDTH> a_buf[X * Y][PACK_IN * LEFT_SIZE],
           axis_stream &txA0, axis_stream &txA1,
           bool enable)
{

#pragma HLS inline off
    if (enable)
    {
        axis_pkt tmp;
        data_t data;
        data_t da;
        ap_uint<32> header;

        ap_uint<32> data_temp[2][NUM_PER_TRA];
#pragma HLS ARRAY_PARTITION variable = data_temp complete dim = 0

        for (int z = 0; z < Z; z++)
        {
            for (int xy = 0; xy < X * Y; xy++)
            { // y first then x
                for (int pack = 0; pack < PACK_IN; pack++)
                {
                    header = generateHeader(0, pack);
                    int position = pack * LEFT_SIZE;
                    data = a_buf[xy][position];

                    data_temp[0][0] = data(31, 0);
                    data_temp[0][1] = data(63, 32);
                    data_temp[0][2] = data(95, 64);
                    data_temp[0][3] = data(127, 96);

                    da(31, 0) = header;
                    da(63, 32) = data_temp[0][0];
                    da(95, 64) = data_temp[0][1];
                    da(127, 96) = data_temp[0][2];

                    tmp.data = da;
                    tmp.keep = -1;
                    tmp.last = 0;

                    txA0.write(tmp);
                    txA1.write(tmp);

                    for (int i = 1; i < LEFT_SIZE; i++)
                    {
#pragma HLS PIPELINE II = 1
                        int pos = i + position;
                        data = a_buf[xy][pos];

                        data_temp[i % 2][0] = data(31, 0);
                        data_temp[i % 2][1] = data(63, 32);
                        data_temp[i % 2][2] = data(95, 64);
                        data_temp[i % 2][3] = data(127, 96);
                        da(31, 0) = data_temp[(i + 1) % 2][3];
                        da(63, 32) = data_temp[i % 2][0];
                        da(95, 64) = data_temp[i % 2][1];
                        da(127, 96) = data_temp[i % 2][2];

                        tmp.data = da;
                        tmp.keep = -1;
                        tmp.last = 0;
                        txA0.write(tmp);
                        txA1.write(tmp);
                    }

                    da(31, 0) = data_temp[1][3];
                    da(63, 32) = 0;
                    da(95, 64) = 0;
                    da(127, 96) = 0;
                    tmp.data = da;
                    tmp.keep = 0x000f;
                    tmp.last = 1;

                    txA0.write(tmp);
                    txA1.write(tmp);
                }
            }
        }
    }
}

template <int NC>
void sendB(ap_uint<PLIO_WIDTH> b_buf[Z * Y][PACK_IN * RIGHT_SIZE],
           axis_stream &txB0,
           bool enable)
{

#pragma HLS inline off
    if (enable)
    {
        axis_pkt tmp;
        data_t data;
        data_t da;
        ap_uint<32> header;

        ap_uint<32> data_temp[2][4];
#pragma HLS ARRAY_PARTITION variable = data_temp complete dim = 0

        for (int z = 0; z < Z; z++)
        {
            for (int x = 0; x < X; x++)
            {
                for (int y = 0; y < Y; y++)
                {
                    for (int pack = 0; pack < PACK_IN; pack++)
                    {
                        header = generateHeader(0, pack);
                        int position = pack * RIGHT_SIZE;
                        int pos1 = y + z * Y;
                        data = b_buf[pos1][position];

                        data_temp[0][0] = data(31, 0);
                        data_temp[0][1] = data(63, 32);
                        data_temp[0][2] = data(95, 64);
                        data_temp[0][3] = data(127, 96);

                        da(31, 0) = header;
                        da(63, 32) = data_temp[0][0];
                        da(95, 64) = data_temp[0][1];
                        da(127, 96) = data_temp[0][2];

                        tmp.data = da;
                        tmp.keep = -1;
                        tmp.last = 0;

                        txB0.write(tmp);

                        for (int i = 1; i < RIGHT_SIZE; i++)
                        {
#pragma HLS PIPELINE II = 1
                            int pos0 = i + position;
                            data = b_buf[pos1][pos0];

                            data_temp[i % 2][0] = data(31, 0);
                            data_temp[i % 2][1] = data(63, 32);
                            data_temp[i % 2][2] = data(95, 64);
                            data_temp[i % 2][3] = data(127, 96);
                            da(31, 0) = data_temp[(i + 1) % 2][3];
                            da(63, 32) = data_temp[i % 2][0];
                            da(95, 64) = data_temp[i % 2][1];
                            da(127, 96) = data_temp[i % 2][2];

                            tmp.data = da;
                            tmp.keep = -1;
                            tmp.last = 0;
                            txB0.write(tmp);
                        }

                        da(31, 0) = data_temp[1][3];
                        da(63, 32) = 0;
                        da(95, 64) = 0;
                        da(127, 96) = 0;

                        tmp.data = da;
                        tmp.keep = 0x000f;
                        tmp.last = 1;
                        txB0.write(tmp);
                    }
                }
            }
        }
    }
}

template <int NC>
void receiveC(ap_uint<PLIO_WIDTH> c_buf[Z * X][PACK_OUT][OUT_SIZE], axis_stream &rxC, bool enable)
{

#pragma HLS inline off
    if (enable)
    {
        axis_pkt tmp;
        data_t data;

        fp_int data_temp0[2][NUM_PER_TRA];
#pragma HLS ARRAY_PARTITION variable = data_temp0 complete dim = 0

        fp_int data_temp1[NUM_PER_TRA];
#pragma HLS ARRAY_PARTITION variable = data_temp1 complete dim = 1

        fp_int data_temp2[NUM_PER_TRA];
#pragma HLS ARRAY_PARTITION variable = data_temp2 complete dim = 1

        int cnt[PACK_OUT];
#pragma HLS ARRAY_PARTITION variable = cnt complete dim = 0

        unsigned int ID;
        unsigned int tile_x;
        ap_uint<32> header;

        for (int i = 0; i < PACK_OUT; i++)
        {
#pragma HLS unroll
            cnt[i] = 0;
        }

        for (int z = 0; z < Z; z++)
        {
            for (int x = 0; x < X; x++)
            {
                for (int y = 0; y < Y; y++)
                {
                    for (int pack = 0; pack < PACK_OUT; pack++)
                    {

                        tmp = rxC.read();
                        // printf("tmp: %x \n", tmp.data);
                        header = tmp.data(31, 0);
                        // printf("Header: %x \n", header);

                        data_temp0[0][1].data_uint = tmp.data(63, 32);
                        data_temp0[0][2].data_uint = tmp.data(95, 64);
                        data_temp0[0][3].data_uint = tmp.data(127, 96);

                        ID = getPacketId(header);
                        tile_x = cnt[ID] / Y;
                        cnt[ID] = cnt[ID] + 1;

                        for (int i = 0; i < OUT_SIZE; i++)
                        {
#pragma HLS PIPELINE II = 1
#pragma HLS dependence variable = c_buf type = inter false
                            tmp = rxC.read();
                            // printf("outi : %d \n", i);
                            // for (int i = 0; i < 4; i++)
                            // {
                            //     printf("tmpd : %f ", (float)tmp.data(i * 32 + 31, i * 32));
                            // }
                            // printf("\n");

                            for (int un = 0; un < NUM_PER_TRA; un++)
                            {
#pragma HLS UNROLL factor = NUM_PER_TRA
                                data_temp0[(i + 1) % 2][un].data_uint = tmp.data(un * 32 + 31, un * 32);
                                data_temp1[un].data_uint = c_buf[tile_x][ID][i](un * 32 + 31, un * 32);
                            }
                            data_temp2[0].data_float = data_temp0[i % 2][1].data_float + data_temp1[0].data_float;
                            data_temp2[1].data_float = data_temp0[i % 2][2].data_float + data_temp1[1].data_float;
                            data_temp2[2].data_float = data_temp0[i % 2][3].data_float + data_temp1[2].data_float;
                            data_temp2[3].data_float = data_temp0[(i + 1) % 2][0].data_float + data_temp1[3].data_float;

                            // printf("outi : %d \n", i);

                            c_buf[tile_x][ID][i](31, 0) = data_temp2[0].data_uint;
                            c_buf[tile_x][ID][i](63, 32) = data_temp2[1].data_uint;
                            c_buf[tile_x][ID][i](95, 64) = data_temp2[2].data_uint;
                            c_buf[tile_x][ID][i](127, 96) = data_temp2[3].data_uint;
                            
                            // printf("outsize : %d \n", i);
                            // printf("tile_x: %d, ID: %d\n",tile_x,ID);
                            // for (int i = 0; i < 4; i++)
                            // {
                            //     printf("data : %f ", (float)c_buf[tile_x][ID][i](i * 32 + 31, i * 32));
                            // }
                            // printf("\n");
                        }
                    }
                }
            }
        }
    }
}

void compute(axis_stream_A &dataA0_out, axis_stream_A &dataA1_out, axis_stream_B &dataB0_out , axis_stream_B &dataB1_out,  
             axis_stream_C &dataC0_in,axis_stream_C &dataC1_in,
             axis_stream &txA0, axis_stream &txA1, axis_stream &txB0, axis_stream &txB1, axis_stream &txB2, axis_stream &txB3,
             axis_stream &rxC0, const int TX, const int TY, const int TZ)
{

    ap_uint<PLIO_WIDTH> buff0_A[A * (B / PACK_IN)][X * Y][PACK_IN * LEFT_SIZE];
#pragma HLS bind_storage variable = buff0_A type = RAM_T2P impl = BRAM
#pragma HLS ARRAY_PARTITION variable = buff0_A complete dim = 1
#pragma HLS ARRAY_PARTITION variable = buff0_A cyclic factor = BUFFA_FACTOR dim = 3

    ap_uint<PLIO_WIDTH> buff1_A[A * (B / PACK_IN)][X * Y][PACK_IN * LEFT_SIZE];
#pragma HLS bind_storage variable = buff1_A type = RAM_T2P impl = BRAM
#pragma HLS ARRAY_PARTITION variable = buff1_A complete dim = 1
#pragma HLS ARRAY_PARTITION variable = buff1_A cyclic factor = BUFFA_FACTOR dim = 3

    ap_uint<PLIO_WIDTH> buff0_B[(B / PACK_IN) * C][Z * Y][PACK_IN * RIGHT_SIZE];
#pragma HLS bind_storage variable = buff0_B type = RAM_T2P impl = BRAM
#pragma HLS ARRAY_PARTITION variable = buff0_B complete dim = 1
#pragma HLS ARRAY_PARTITION variable = buff0_B cyclic factor = BUFFB_FACTOR dim = 3

    ap_uint<PLIO_WIDTH> buff1_B[(B / PACK_IN) * C][Z * Y][PACK_IN * RIGHT_SIZE];
#pragma HLS bind_storage variable = buff1_B type = RAM_T2P impl = BRAM
#pragma HLS ARRAY_PARTITION variable = buff1_B complete dim = 1
#pragma HLS ARRAY_PARTITION variable = buff1_B cyclic factor = BUFFB_FACTOR dim = 3

    ap_uint<PLIO_WIDTH> buff0_C[(C / PACK_OUT) * A][Z * X][PACK_OUT][OUT_SIZE];
#pragma HLS bind_storage variable = buff0_C type = RAM_T2P impl = BRAM
#pragma HLS ARRAY_PARTITION variable = buff0_C complete dim = 1
#pragma HLS ARRAY_PARTITION variable = buff0_C cyclic factor = BUFFC_FACTOR dim = 4

    ap_uint<PLIO_WIDTH> buff1_C[(C / PACK_OUT) * A][Z * X][PACK_OUT][OUT_SIZE];
#pragma HLS bind_storage variable = buff1_C type = RAM_T2P impl = BRAM
#pragma HLS ARRAY_PARTITION variable = buff1_C complete dim = 1
#pragma HLS ARRAY_PARTITION variable = buff1_C cyclic factor = BUFFC_FACTOR dim = 4

    const int Total_rd = TX * TY * TZ;

    for (int rd = 0; rd < Total_rd + 2; rd++)
    {
        int c_flg = 0, s_flg = 0;
        if (rd > 0)
        {
            c_flg = ((rd - 1) / TY) % 2;
        }
        if (rd > 1)
        {
            s_flg = (rd - 2) % TY;
        }
        if (rd % 2 == 0 && c_flg == 0)
        {
            loadA0(dataA0_out, buff0_A, rd < Total_rd);
            loadA1(dataA1_out, buff0_A, rd < Total_rd);
            loadB0(dataB0_out, buff0_B, rd < Total_rd);
            loadB1(dataB1_out, buff0_B, rd < Total_rd);

            sendA<0>(buff1_A[0], txA0, txA1, rd > 0 && rd < Total_rd + 1);

            sendB<0>(buff1_B[0], txB0, rd > 0 && rd < Total_rd + 1);
            sendB<1>(buff1_B[1], txB1, rd > 0 && rd < Total_rd + 1);
            sendB<2>(buff1_B[2], txB2, rd > 0 && rd < Total_rd + 1);
            sendB<3>(buff1_B[3], txB3, rd > 0 && rd < Total_rd + 1);

            receiveC<0>(buff0_C[0], rxC0, rd > 0 && rd < Total_rd + 1);

            storeC0(dataC0_in, buff1_C, rd > TY && s_flg == (TY - 1));
            storeC1(dataC1_in, buff1_C, rd > TY && s_flg == (TY - 1));
        }
        else if (rd % 2 == 1 && c_flg == 0)
        {
            loadA0(dataA0_out, buff1_A, rd < Total_rd);
            loadA1(dataA1_out, buff1_A, rd < Total_rd);
            loadB0(dataB0_out, buff1_B, rd < Total_rd);
            loadB1(dataB1_out, buff1_B, rd < Total_rd);

            sendA<0>(buff0_A[0], txA0, txA1, rd > 0 && rd < Total_rd + 1);

            sendB<0>(buff0_B[0], txB0, rd > 0 && rd < Total_rd + 1);
            sendB<1>(buff0_B[1], txB1, rd > 0 && rd < Total_rd + 1);
            sendB<2>(buff0_B[2], txB2, rd > 0 && rd < Total_rd + 1);
            sendB<3>(buff0_B[3], txB3, rd > 0 && rd < Total_rd + 1);

            receiveC<0>(buff0_C[0], rxC0, rd > 0 && rd < Total_rd + 1);

            storeC0(dataC0_in, buff1_C, rd > TY && s_flg == (TY - 1));
            storeC1(dataC1_in, buff1_C, rd > TY && s_flg == (TY - 1));
        }
        else if (rd % 2 == 0 && c_flg == 1)
        {
            loadA0(dataA0_out, buff0_A, rd < Total_rd);
            loadA1(dataA1_out, buff0_A, rd < Total_rd);
            loadB0(dataB0_out, buff0_B, rd < Total_rd);
            loadB1(dataB1_out, buff0_B, rd < Total_rd);

            sendA<0>(buff1_A[0], txA0, txA1, rd > 0 && rd < Total_rd + 1);

            sendB<0>(buff1_B[0], txB0, rd > 0 && rd < Total_rd + 1);
            sendB<1>(buff1_B[1], txB1, rd > 0 && rd < Total_rd + 1);
            sendB<2>(buff1_B[2], txB2, rd > 0 && rd < Total_rd + 1);
            sendB<3>(buff1_B[3], txB3, rd > 0 && rd < Total_rd + 1);

            receiveC<0>(buff1_C[0], rxC0, rd > 0 && rd < Total_rd + 1);

            storeC0(dataC0_in, buff0_C, rd > TY && s_flg == (TY - 1));
            storeC1(dataC1_in, buff0_C, rd > TY && s_flg == (TY - 1));
        }
        else
        { // if(rd%2==1&&c_flg==1)
            loadA0(dataA0_out, buff1_A, rd < Total_rd);
            loadA1(dataA1_out, buff1_A, rd < Total_rd);
            loadB0(dataB0_out, buff1_B, rd < Total_rd);
            loadB1(dataB1_out, buff1_B, rd < Total_rd);

            sendA<0>(buff0_A[0], txA0, txA1, rd > 0 && rd < Total_rd + 1);

            sendB<0>(buff0_B[0], txB0, rd > 0 && rd < Total_rd + 1);
            sendB<1>(buff0_B[1], txB1, rd > 0 && rd < Total_rd + 1);
            sendB<2>(buff0_B[2], txB2, rd > 0 && rd < Total_rd + 1);
            sendB<3>(buff0_B[3], txB3, rd > 0 && rd < Total_rd + 1);

            receiveC<0>(buff1_C[0], rxC0, rd > 0 && rd < Total_rd + 1);

            storeC0(dataC0_in, buff0_C, rd > TY && s_flg == (TY - 1));
            storeC1(dataC1_in, buff0_C, rd > TY && s_flg == (TY - 1));
        }
    }
}

void dma0(ap_uint<AXI_WIDTH_A> *ina0,
          ap_uint<AXI_WIDTH_A> *ina1,
          ap_uint<AXI_WIDTH_B> *inb0,
          ap_uint<AXI_WIDTH_B> *inb1, 
          ap_uint<AXI_WIDTH_C> *out0,
          ap_uint<AXI_WIDTH_C> *out1,
          axis_stream &txA0, axis_stream &txA1, axis_stream &txB0, axis_stream &txB1, axis_stream &txB2, axis_stream &txB3,
          axis_stream &rxC0, const int TX, const int TY, const int TZ)
{

#pragma HLS interface m_axi offset = slave bundle = gmem0 port = ina0 max_read_burst_length = 16 num_read_outstanding = 64
#pragma HLS interface s_axilite bundle = control port = ina0
#pragma HLS interface m_axi offset = slave bundle = gmem1 port = ina1 max_read_burst_length = 16 num_read_outstanding = 64
#pragma HLS interface s_axilite bundle = control port = ina1
#pragma HLS interface m_axi offset = slave bundle = gmem2 port = inb0 max_read_burst_length = 16 num_read_outstanding = 64
#pragma HLS interface s_axilite bundle = control port = inb0
#pragma HLS interface m_axi offset = slave bundle = gmem3 port = inb1 max_read_burst_length = 16 num_read_outstanding = 64
#pragma HLS interface s_axilite bundle = control port = inb1
#pragma HLS interface m_axi offset = slave bundle = gmem4 port = out0 max_write_burst_length = 16 num_write_outstanding = 64
#pragma HLS interface s_axilite bundle = control port = out0
#pragma HLS interface m_axi offset = slave bundle = gmem5 port = out1 max_write_burst_length = 16 num_write_outstanding = 64
#pragma HLS interface s_axilite bundle = control port = out1
#pragma HLS interface s_axilite bundle = control port = TX
#pragma HLS interface s_axilite bundle = control port = TY
#pragma HLS interface s_axilite bundle = control port = TZ
#pragma HLS interface axis port = txA0
#pragma HLS interface axis port = txA1
#pragma HLS interface axis port = txB0
#pragma HLS interface axis port = txB1
#pragma HLS interface axis port = txB2
#pragma HLS interface axis port = txB3
#pragma HLS interface axis port = rxC0
#pragma HLS interface s_axilite bundle = control port = return

#pragma HLS dataflow
    axis_stream_A dataA0_out;
    axis_stream_A dataA1_out;
    axis_stream_B dataB0_out;
    axis_stream_B dataB1_out;
    axis_stream_C dataC0_in;
    axis_stream_C dataC1_in;

    axis_stream_32 addrA0_out;
    axis_stream_32 addrA1_out;
    axis_stream_32 addrB0_out;
    axis_stream_32 addrB1_out;
    axis_stream_32 addrC0_out;
    axis_stream_32 addrC1_out;

    address_A0_ddr(addrA0_out, TX, TY, TZ);
    loadA0_ddr(ina0, addrA0_out, dataA0_out, TX, TY, TZ);

    address_A1_ddr(addrA1_out, TX, TY, TZ);
    loadA1_ddr(ina1, addrA1_out, dataA1_out, TX, TY, TZ);

    address_B0_ddr(addrB0_out, TX, TY, TZ);
    loadB0_ddr(inb0, addrB0_out, dataB0_out, TX, TY, TZ);

    address_B1_ddr(addrB1_out, TX, TY, TZ);
    loadB1_ddr(inb1, addrB1_out, dataB1_out, TX, TY, TZ);

    compute(dataA0_out, dataA1_out, dataB0_out, dataB1_out, dataC0_in, dataC1_in,
            txA0, txA1, txB0, txB1, txB2, txB3,
            rxC0, TX, TY, TZ);

    address_C0_ddr(addrC0_out, TX, TZ);
    address_C1_ddr(addrC1_out, TX, TZ);
    
    storeC0_ddr(out0, addrC0_out, dataC0_in, TX, TZ);
    storeC1_ddr(out1, addrC1_out, dataC1_in, TX, TZ);

}