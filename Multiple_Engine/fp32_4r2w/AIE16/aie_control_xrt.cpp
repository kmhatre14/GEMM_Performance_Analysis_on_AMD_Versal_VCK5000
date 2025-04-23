#include <iostream>
#include "adf/new_frontend/adf.h"
#include "adf/adf_api/X86SimConfig.h"


/************************** Graph Configurations  *****************************/

  adf::X86SimGraphConfig GraphConfigurations[] = {
  // {id, name, runForIter, x86SimPtr}
    {0, "mm_graph0", -1, nullptr},
  };
  const int NUM_GRAPH = 1;

/************************** PLIO Configurations  *****************************/

  adf::X86SimPLIOConfig PLIOConfigurations[] = {
  //{id, name, loginal_name}
    {0, "LHS_in0_L0", "LHS_in0_L0"},
    {1, "LHS_in1_L0", "LHS_in1_L0"},
    {2, "RHS_in0_L0", "RHS_in0_L0"},
    {3, "RHS_in1_L0", "RHS_in1_L0"},
    {4, "RHS_in2_L0", "RHS_in2_L0"},
    {5, "RHS_in3_L0", "RHS_in3_L0"},
    {6, "out0_L0", "out0_L0"},
  };
  const int NUM_PLIO = 7;


/************************** ADF API initializer *****************************/

  class InitializeAIEControlXRT
  {
  public:
    InitializeAIEControlXRT()
    {
      std::cout<<"Initializing ADF API..."<<std::endl;
      adf::initializeX86SimConfigurations(GraphConfigurations, NUM_GRAPH,
                                    nullptr, 0,
                                    nullptr, 0,
                                    PLIOConfigurations, NUM_PLIO,
                                    nullptr, 0);
    }
  } initAIEControlXRT;



#if !defined(__CDO__)

// Kernel Stub Definition
  void mm1_kernel0_L0(input_window<float> *__restrict,input_window<float> *__restrict,output_stream<accfloat> *__restrict) { /* Stub */ } 
  void mm1_kernel1_L0(input_window<float> *__restrict,input_window<float> *__restrict,input_stream<accfloat> *__restrict,output_stream<accfloat> *__restrict) { /* Stub */ } 
  void mm1_kernel2_L0(input_window<float> *__restrict,input_window<float> *__restrict,input_stream<accfloat> *__restrict,output_window<float> *__restrict) { /* Stub */ } 
#endif
