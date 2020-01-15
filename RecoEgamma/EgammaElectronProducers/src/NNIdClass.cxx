#include "RecoEgamma/EgammaElectronProducers/interface/NNIdClass.h"
#include <cmath>

double NNIdClass::Value(int index,double in0,double in1,double in2,double in3,double in4,double in5,double in6,double in7,double in8,double in9,double in10,double in11,double in12,double in13,double in14,double in15,double in16,double in17,double in18,double in19,double in20,double in21,double in22,double in23,double in24,double in25,double in26,double in27,double in28,double in29,double in30,double in31,double in32,double in33,double in34,double in35,double in36,double in37,double in38,double in39,double in40,double in41,double in42,double in43,double in44,double in45,double in46) {
   input0 = (in0 - 3.30568)/48.6792;
   input1 = (in1 - 12.8847)/4.17829;
   input2 = (in2 - 6.5319)/4.97039;
   input3 = (in3 - 0.00783424)/1.98459;
   input4 = (in4 - 0.00913837)/0.0142996;
   input5 = (in5 - 0.0106244)/0.0153254;
   input6 = (in6 - 0.127614)/0.194984;
   input7 = (in7 - 0.378905)/0.368747;
   input8 = (in8 - 0.422753)/0.415945;
   input9 = (in9 - 0.497655)/0.447881;
   input10 = (in10 - 0.266755)/0.525228;
   input11 = (in11 - 9.33262)/5.15035;
   input12 = (in12 - 1.20825)/2.7078;
   input13 = (in13 - 15.7441)/9342.87;
   input14 = (in14 - 0.558027)/0.642304;
   input15 = (in15 - 16.1829)/3.64844;
   input16 = (in16 - 7.17654)/7.70603;
   input17 = (in17 - 4.28379e-12)/1.05713e-08;
   input18 = (in18 - 0.00921491)/1.70103;
   input19 = (in19 - 0.00701273)/0.696978;
   input20 = (in20 - -0.001443)/0.874836;
   input21 = (in21 - 11.5451)/10.935;
   input22 = (in22 - 2.68414)/3.85209;
   input23 = (in23 - 1.26016)/2.14157;
   input24 = (in24 - 0.417854)/0.493206;
   input25 = (in25 - 0.933695)/0.177607;
   input26 = (in26 - 0.00115398)/0.0190361;
   input27 = (in27 - 0.00888189)/0.0820615;
   input28 = (in28 - 5.04715)/2.51826;
   input29 = (in29 - 2.46693)/2.46501;
   input30 = (in30 - -44.7273)/210.551;
   input31 = (in31 - -162.236)/370.007;
   input32 = (in32 - -187.099)/389.749;
   input33 = (in33 - -231.628)/421.596;
   input34 = (in34 - -341.971)/474.008;
   input35 = (in35 - -187.099)/389.749;
   input36 = (in36 - -231.626)/421.596;
   input37 = (in37 - -341.97)/474.008;
   input38 = (in38 - 6.54681)/9.3226;
   input39 = (in39 - -44.8377)/210.528;
   input40 = (in40 - -162.653)/369.822;
   input41 = (in41 - 0.474072)/0.705552;
   input42 = (in42 - 0.422954)/0.661355;
   input43 = (in43 - 0.323269)/0.591275;
   input44 = (in44 - 3.86687)/5.75791;
   input45 = (in45 - -45.4656)/210.385;
   input46 = (in46 - -162.909)/369.709;
   switch(index) {
     case 0:
         return neuron0x1dc4cbc0();
     default:
         return 0.;
   }
}

double NNIdClass::Value(int index, double* input) {
   input0 = (input[0] - 3.30568)/48.6792;
   input1 = (input[1] - 12.8847)/4.17829;
   input2 = (input[2] - 6.5319)/4.97039;
   input3 = (input[3] - 0.00783424)/1.98459;
   input4 = (input[4] - 0.00913837)/0.0142996;
   input5 = (input[5] - 0.0106244)/0.0153254;
   input6 = (input[6] - 0.127614)/0.194984;
   input7 = (input[7] - 0.378905)/0.368747;
   input8 = (input[8] - 0.422753)/0.415945;
   input9 = (input[9] - 0.497655)/0.447881;
   input10 = (input[10] - 0.266755)/0.525228;
   input11 = (input[11] - 9.33262)/5.15035;
   input12 = (input[12] - 1.20825)/2.7078;
   input13 = (input[13] - 15.7441)/9342.87;
   input14 = (input[14] - 0.558027)/0.642304;
   input15 = (input[15] - 16.1829)/3.64844;
   input16 = (input[16] - 7.17654)/7.70603;
   input17 = (input[17] - 4.28379e-12)/1.05713e-08;
   input18 = (input[18] - 0.00921491)/1.70103;
   input19 = (input[19] - 0.00701273)/0.696978;
   input20 = (input[20] - -0.001443)/0.874836;
   input21 = (input[21] - 11.5451)/10.935;
   input22 = (input[22] - 2.68414)/3.85209;
   input23 = (input[23] - 1.26016)/2.14157;
   input24 = (input[24] - 0.417854)/0.493206;
   input25 = (input[25] - 0.933695)/0.177607;
   input26 = (input[26] - 0.00115398)/0.0190361;
   input27 = (input[27] - 0.00888189)/0.0820615;
   input28 = (input[28] - 5.04715)/2.51826;
   input29 = (input[29] - 2.46693)/2.46501;
   input30 = (input[30] - -44.7273)/210.551;
   input31 = (input[31] - -162.236)/370.007;
   input32 = (input[32] - -187.099)/389.749;
   input33 = (input[33] - -231.628)/421.596;
   input34 = (input[34] - -341.971)/474.008;
   input35 = (input[35] - -187.099)/389.749;
   input36 = (input[36] - -231.626)/421.596;
   input37 = (input[37] - -341.97)/474.008;
   input38 = (input[38] - 6.54681)/9.3226;
   input39 = (input[39] - -44.8377)/210.528;
   input40 = (input[40] - -162.653)/369.822;
   input41 = (input[41] - 0.474072)/0.705552;
   input42 = (input[42] - 0.422954)/0.661355;
   input43 = (input[43] - 0.323269)/0.591275;
   input44 = (input[44] - 3.86687)/5.75791;
   input45 = (input[45] - -45.4656)/210.385;
   input46 = (input[46] - -162.909)/369.709;
   switch(index) {
     case 0:
         return neuron0x1dc4cbc0();
     default:
         return 0.;
   }
}

double NNIdClass::neuron0x3e012f0() {
   return input0;
}

double NNIdClass::neuron0x3e01630() {
   return input1;
}

double NNIdClass::neuron0x3e01970() {
   return input2;
}

double NNIdClass::neuron0x1de98b20() {
   return input3;
}

double NNIdClass::neuron0x1de98e60() {
   return input4;
}

double NNIdClass::neuron0x1de991e0() {
   return input5;
}

double NNIdClass::neuron0x1d8d6690() {
   return input6;
}

double NNIdClass::neuron0x1d8d69d0() {
   return input7;
}

double NNIdClass::neuron0x1d8d6d10() {
   return input8;
}

double NNIdClass::neuron0x1d8d7050() {
   return input9;
}

double NNIdClass::neuron0x1d8d7390() {
   return input10;
}

double NNIdClass::neuron0x1d8d76d0() {
   return input11;
}

double NNIdClass::neuron0x1d8d7a10() {
   return input12;
}

double NNIdClass::neuron0x1d8d7d50() {
   return input13;
}

double NNIdClass::neuron0x1d8d8090() {
   return input14;
}

double NNIdClass::neuron0x1d8d83d0() {
   return input15;
}

double NNIdClass::neuron0x1d8d44a0() {
   return input16;
}

double NNIdClass::neuron0x1d8d4a00() {
   return input17;
}

double NNIdClass::neuron0x1d8d4d40() {
   return input18;
}

double NNIdClass::neuron0x1d8d5080() {
   return input19;
}

double NNIdClass::neuron0x1d8d53f0() {
   return input20;
}

double NNIdClass::neuron0x1d8d5760() {
   return input21;
}

double NNIdClass::neuron0x1d8d5aa0() {
   return input22;
}

double NNIdClass::neuron0x1d8d5de0() {
   return input23;
}

double NNIdClass::neuron0x1d8d6120() {
   return input24;
}

double NNIdClass::neuron0x1d90f490() {
   return input25;
}

double NNIdClass::neuron0x1d90f770() {
   return input26;
}

double NNIdClass::neuron0x1d90fab0() {
   return input27;
}

double NNIdClass::neuron0x1d90fdf0() {
   return input28;
}

double NNIdClass::neuron0x1d910130() {
   return input29;
}

double NNIdClass::neuron0x1d910470() {
   return input30;
}

double NNIdClass::neuron0x1d9107b0() {
   return input31;
}

double NNIdClass::neuron0x1d910af0() {
   return input32;
}

double NNIdClass::neuron0x1d8d47e0() {
   return input33;
}

double NNIdClass::neuron0x1d911370() {
   return input34;
}

double NNIdClass::neuron0x1d8e9af0() {
   return input35;
}

double NNIdClass::neuron0x1d8e9e30() {
   return input36;
}

double NNIdClass::neuron0x1d8ea170() {
   return input37;
}

double NNIdClass::neuron0x1d8ea4b0() {
   return input38;
}

double NNIdClass::neuron0x1d8ea7f0() {
   return input39;
}

double NNIdClass::neuron0x1d8eab30() {
   return input40;
}

double NNIdClass::neuron0x1d8eae70() {
   return input41;
}

double NNIdClass::neuron0x1d8eb1e0() {
   return input42;
}

double NNIdClass::neuron0x1d8eb550() {
   return input43;
}

double NNIdClass::neuron0x1d8eb8c0() {
   return input44;
}

double NNIdClass::neuron0x1d8ebc30() {
   return input45;
}

double NNIdClass::neuron0x1d8c89b0() {
   return input46;
}

double NNIdClass::input0x1d8c8d20() {
   double input = -1.39768;
   input += synapse0x3e02a70();
   input += synapse0x1d8c5bd0();
   input += synapse0x1d8dba10();
   input += synapse0x1de994d0();
   input += synapse0x1de997d0();
   input += synapse0x1d8ebdf0();
   input += synapse0x1d8c9060();
   input += synapse0x1d8c90a0();
   input += synapse0x1d8c90e0();
   input += synapse0x1d8c9120();
   input += synapse0x1d8c9160();
   input += synapse0x1d8c91a0();
   input += synapse0x1d8c91e0();
   input += synapse0x1d8c9220();
   input += synapse0x1d8c9260();
   input += synapse0x1d8c92a0();
   input += synapse0x1de987a0();
   input += synapse0x1de987e0();
   input += synapse0x1d8d8560();
   input += synapse0x1d8d85a0();
   input += synapse0x1de986a0();
   input += synapse0x1de986e0();
   input += synapse0x1d8c8eb0();
   input += synapse0x1d8c8ef0();
   input += synapse0x1dc34b70();
   input += synapse0x1dc34bb0();
   input += synapse0x3e00fa0();
   input += synapse0x3e00fe0();
   input += synapse0x3e01020();
   input += synapse0x1d8c9500();
   input += synapse0x1d8c9540();
   input += synapse0x1d8c9580();
   input += synapse0x1d8c92e0();
   input += synapse0x1d8c9320();
   input += synapse0x1d8c9360();
   input += synapse0x1d8c93a0();
   input += synapse0x1d8c93e0();
   input += synapse0x1d8c9420();
   input += synapse0x1d8c9460();
   input += synapse0x1d8c94a0();
   input += synapse0x1d8c99e0();
   input += synapse0x1d8c9a20();
   input += synapse0x1d8c9a60();
   input += synapse0x1d8c9aa0();
   input += synapse0x1d8c9ae0();
   input += synapse0x1d8c9b20();
   input += synapse0x1d8c9b60();
   return input;
}

double NNIdClass::neuron0x1d8c8d20() {
   double input = input0x1d8c8d20();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d8c9ba0() {
   double input = -0.260723;
   input += synapse0x1d8c9ee0();
   input += synapse0x1d8c9f20();
   input += synapse0x1d8c9f60();
   input += synapse0x1d8c9fa0();
   input += synapse0x1d8c9fe0();
   input += synapse0x1d8ca020();
   input += synapse0x1d8ca060();
   input += synapse0x1d8ca0a0();
   input += synapse0x1d8ca0e0();
   input += synapse0x1d8ca120();
   input += synapse0x1d8ca160();
   input += synapse0x1d8ca1a0();
   input += synapse0x1d8ca1e0();
   input += synapse0x1d8ca220();
   input += synapse0x1d8ca260();
   input += synapse0x1d8ca2a0();
   input += synapse0x1d8c9d30();
   input += synapse0x1d8c9d70();
   input += synapse0x1d8c5c10();
   input += synapse0x1d8d8650();
   input += synapse0x1d8c6140();
   input += synapse0x1d8c61d0();
   input += synapse0x1de98720();
   input += synapse0x1de98760();
   input += synapse0x1de98820();
   input += synapse0x1de98860();
   input += synapse0x1de99540();
   input += synapse0x1de99580();
   input += synapse0x1de995c0();
   input += synapse0x1d8dba50();
   input += synapse0x1d8dba90();
   input += synapse0x1d8dbad0();
   input += synapse0x1d8db700();
   input += synapse0x1d8db740();
   input += synapse0x1d8db780();
   input += synapse0x1d8ca2e0();
   input += synapse0x1d8ca320();
   input += synapse0x1d8ca360();
   input += synapse0x1d8ca3a0();
   input += synapse0x3e011a0();
   input += synapse0x3e011e0();
   input += synapse0x3e01220();
   input += synapse0x3e01260();
   input += synapse0x3e012a0();
   input += synapse0x1d8dbf20();
   input += synapse0x1d8dbf60();
   input += synapse0x1d8dbfa0();
   return input;
}

double NNIdClass::neuron0x1d8c9ba0() {
   double input = input0x1d8c9ba0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d8db840() {
   double input = 0.197328;
   input += synapse0x1d8db9d0();
   input += synapse0x1d8c98f0();
   input += synapse0x1d8c9930();
   input += synapse0x1d8c9970();
   input += synapse0x1d8dc070();
   input += synapse0x1de988e0();
   input += synapse0x1de98920();
   input += synapse0x1de98960();
   input += synapse0x1de989a0();
   input += synapse0x1de989e0();
   input += synapse0x1de98a20();
   input += synapse0x1de98a60();
   input += synapse0x1de98aa0();
   input += synapse0x1de98ae0();
   input += synapse0x1d8dbb70();
   input += synapse0x1d8dbbb0();
   input += synapse0x1d8dbfe0();
   input += synapse0x1d8dc020();
   input += synapse0x1d8dbd00();
   input += synapse0x1d8dbd40();
   input += synapse0x1d8dbd80();
   input += synapse0x1d8dbdc0();
   input += synapse0x1d8dbe00();
   input += synapse0x1d8dbe40();
   input += synapse0x1d8dbe80();
   input += synapse0x1d8dbec0();
   input += synapse0x1d8ca800();
   input += synapse0x1d8ca840();
   input += synapse0x1d8ca880();
   input += synapse0x1d8ca8c0();
   input += synapse0x1d8ca900();
   input += synapse0x1d8ca940();
   input += synapse0x1d8dbbf0();
   input += synapse0x1d8dbc30();
   input += synapse0x1d8dbc70();
   input += synapse0x1d8dbcb0();
   input += synapse0x1d8ca3f0();
   input += synapse0x1d8ca430();
   input += synapse0x1d8ca470();
   input += synapse0x1d8ca4b0();
   input += synapse0x1d8ca4f0();
   input += synapse0x1d8ca530();
   input += synapse0x1d8ca570();
   input += synapse0x1d8ca5b0();
   input += synapse0x1d8ca5f0();
   input += synapse0x1d8ca630();
   input += synapse0x1d8ca670();
   return input;
}

double NNIdClass::neuron0x1d8db840() {
   double input = input0x1d8db840();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d8cb3a0() {
   double input = -0.316695;
   input += synapse0x1d8cb6e0();
   input += synapse0x1d8cb720();
   input += synapse0x1d8cb760();
   input += synapse0x1d8cb7a0();
   input += synapse0x1d8cb7e0();
   input += synapse0x1d8cb820();
   input += synapse0x1d8cb860();
   input += synapse0x1d8cb8a0();
   input += synapse0x1d8cb8e0();
   input += synapse0x1d8cb920();
   input += synapse0x1d8cb960();
   input += synapse0x1d8cb9a0();
   input += synapse0x1d8cb9e0();
   input += synapse0x1d8cba20();
   input += synapse0x1d8cba60();
   input += synapse0x1d8cbaa0();
   input += synapse0x1d8cb530();
   input += synapse0x1d8cb570();
   input += synapse0x1d8ca6b0();
   input += synapse0x1d8ca6f0();
   input += synapse0x1d8ca730();
   input += synapse0x1d8ca770();
   input += synapse0x1d8ca7b0();
   input += synapse0x1d8cbbf0();
   input += synapse0x1d8cbc30();
   input += synapse0x1d8cbc70();
   input += synapse0x1d8cbcb0();
   input += synapse0x1d8cbcf0();
   input += synapse0x1d8cbd30();
   input += synapse0x1d8cbd70();
   input += synapse0x1d8cbdb0();
   input += synapse0x1d8cbdf0();
   input += synapse0x1d8cbae0();
   input += synapse0x1d8cbb20();
   input += synapse0x1d8cbb60();
   input += synapse0x1d8cbba0();
   input += synapse0x1d8cc040();
   input += synapse0x1d8cc080();
   input += synapse0x1d8cc0c0();
   input += synapse0x1d8cc100();
   input += synapse0x1d8cc140();
   input += synapse0x1d8cc180();
   input += synapse0x1d8cc1c0();
   input += synapse0x1d8cc200();
   input += synapse0x1d8cc240();
   input += synapse0x1d8cc280();
   input += synapse0x1d8cc2c0();
   return input;
}

double NNIdClass::neuron0x1d8cb3a0() {
   double input = input0x1d8cb3a0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d8cdb90() {
   double input = -0.429652;
   input += synapse0x1d8cded0();
   input += synapse0x1d8cdf10();
   input += synapse0x1d8cdf50();
   input += synapse0x1d8cdf90();
   input += synapse0x1d8cdfd0();
   input += synapse0x1d8ce010();
   input += synapse0x1d8ce050();
   input += synapse0x1d8ce090();
   input += synapse0x1d8ce0d0();
   input += synapse0x1d8ce110();
   input += synapse0x1d8ce150();
   input += synapse0x1d8ce190();
   input += synapse0x1d8ce1d0();
   input += synapse0x1d8ce210();
   input += synapse0x1d8ce250();
   input += synapse0x1d8ce290();
   input += synapse0x1d8cdd20();
   input += synapse0x1d8cdd60();
   input += synapse0x1d8cc300();
   input += synapse0x1d8cc340();
   input += synapse0x1d8cc380();
   input += synapse0x1d8cc3c0();
   input += synapse0x1d8ce3e0();
   input += synapse0x1d8ce420();
   input += synapse0x1d8ce460();
   input += synapse0x1d8ce4a0();
   input += synapse0x1d8ce4e0();
   input += synapse0x1d8ce520();
   input += synapse0x1d8ce560();
   input += synapse0x1d8ce5a0();
   input += synapse0x1d8ce5e0();
   input += synapse0x1d8ce620();
   input += synapse0x1d8ce2d0();
   input += synapse0x1d8ce310();
   input += synapse0x1d8ce350();
   input += synapse0x1d8ce390();
   input += synapse0x1d8ce870();
   input += synapse0x1d8ce8b0();
   input += synapse0x1d8ce8f0();
   input += synapse0x1d8ce930();
   input += synapse0x1d8ce970();
   input += synapse0x1d8ce9b0();
   input += synapse0x1d8ce9f0();
   input += synapse0x1d8cea30();
   input += synapse0x1d8cea70();
   input += synapse0x1d8ceab0();
   input += synapse0x1d8ceaf0();
   return input;
}

double NNIdClass::neuron0x1d8cdb90() {
   double input = input0x1d8cdb90();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d8ceb30() {
   double input = 0.2883;
   input += synapse0x1d8cee70();
   input += synapse0x1d8ceeb0();
   input += synapse0x1d8ceef0();
   input += synapse0x1d8cef30();
   input += synapse0x1d8cef70();
   input += synapse0x1d8cefb0();
   input += synapse0x1d8ceff0();
   input += synapse0x1d8cf030();
   input += synapse0x1d8cf070();
   input += synapse0x1d8cf0b0();
   input += synapse0x1d8cf0f0();
   input += synapse0x1d8cf130();
   input += synapse0x1d8cf170();
   input += synapse0x1d8cf1b0();
   input += synapse0x1d8cf1f0();
   input += synapse0x1d8cf230();
   input += synapse0x1d8cecc0();
   input += synapse0x1d8ced00();
   input += synapse0x1d8cf380();
   input += synapse0x1d8cf3c0();
   input += synapse0x1d8cf400();
   input += synapse0x1d8cf440();
   input += synapse0x1d8cab90();
   input += synapse0x1d8cabd0();
   input += synapse0x1d8cac10();
   input += synapse0x1d8cac50();
   input += synapse0x1d8cac90();
   input += synapse0x1d8cacd0();
   input += synapse0x1d8cad10();
   input += synapse0x1d8cad50();
   input += synapse0x1d8cad90();
   input += synapse0x1d8cadd0();
   input += synapse0x1d8cf270();
   input += synapse0x1d8cf2b0();
   input += synapse0x1d8cf2f0();
   input += synapse0x1d8cf330();
   input += synapse0x1d8cb020();
   input += synapse0x1d8cb060();
   input += synapse0x1d8cb0a0();
   input += synapse0x1d8cb0e0();
   input += synapse0x1d8cb120();
   input += synapse0x1d8cb160();
   input += synapse0x1d8cb1a0();
   input += synapse0x1d8cb1e0();
   input += synapse0x1d8cb220();
   input += synapse0x1d8cb260();
   input += synapse0x1d8cb2a0();
   return input;
}

double NNIdClass::neuron0x1d8ceb30() {
   double input = input0x1d8ceb30();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d8d0490() {
   double input = 0.2676;
   input += synapse0x1d8d07d0();
   input += synapse0x1d8d0810();
   input += synapse0x1d8d0850();
   input += synapse0x1d8d0890();
   input += synapse0x1d8d08d0();
   input += synapse0x1d8d0910();
   input += synapse0x1d8d0950();
   input += synapse0x1d8d0990();
   input += synapse0x1d8d09d0();
   input += synapse0x1d8d0a10();
   input += synapse0x1d8d0a50();
   input += synapse0x1d8d0a90();
   input += synapse0x1d8d0ad0();
   input += synapse0x1d8d0b10();
   input += synapse0x1d8d0b50();
   input += synapse0x1d8d0b90();
   input += synapse0x1d8d0620();
   input += synapse0x1d8d0660();
   input += synapse0x1d8cb2e0();
   input += synapse0x1d8cb320();
   input += synapse0x1d8cb360();
   input += synapse0x1d8d0ce0();
   input += synapse0x1d8d0d20();
   input += synapse0x1d8d0d60();
   input += synapse0x1d8d0da0();
   input += synapse0x1d8d0de0();
   input += synapse0x1d8d0e20();
   input += synapse0x1d8d0e60();
   input += synapse0x1d8d0ea0();
   input += synapse0x1d8d0ee0();
   input += synapse0x1d8d0f20();
   input += synapse0x1d8d0f60();
   input += synapse0x1d8d0bd0();
   input += synapse0x1d8d0c10();
   input += synapse0x1d8d0c50();
   input += synapse0x1d8d0c90();
   input += synapse0x1d8d11b0();
   input += synapse0x1d8d11f0();
   input += synapse0x1d8d1230();
   input += synapse0x1d8d1270();
   input += synapse0x1d8d12b0();
   input += synapse0x1d8d12f0();
   input += synapse0x1d8d1330();
   input += synapse0x1d8d1370();
   input += synapse0x1d8d13b0();
   input += synapse0x1d8d13f0();
   input += synapse0x1d8d1430();
   return input;
}

double NNIdClass::neuron0x1d8d0490() {
   double input = input0x1d8d0490();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d8d1470() {
   double input = 0.035194;
   input += synapse0x1d8d17b0();
   input += synapse0x1d8d17f0();
   input += synapse0x1d8d1830();
   input += synapse0x1d8d1870();
   input += synapse0x1d8d18b0();
   input += synapse0x1d8d18f0();
   input += synapse0x1d8d1930();
   input += synapse0x1d8d1970();
   input += synapse0x1d8d19b0();
   input += synapse0x1d94c6a0();
   input += synapse0x1d94c6e0();
   input += synapse0x1d94c720();
   input += synapse0x1d94c760();
   input += synapse0x1d94c7a0();
   input += synapse0x1d94c7e0();
   input += synapse0x1d94c820();
   input += synapse0x1d8d1600();
   input += synapse0x1d8d1640();
   input += synapse0x1d94c970();
   input += synapse0x1d94c9b0();
   input += synapse0x1d94c9f0();
   input += synapse0x1d94ca30();
   input += synapse0x1d94ca70();
   input += synapse0x1d94cab0();
   input += synapse0x1d94caf0();
   input += synapse0x1d94cb30();
   input += synapse0x1d94cb70();
   input += synapse0x1d94cbb0();
   input += synapse0x1d94cbf0();
   input += synapse0x1d94cc30();
   input += synapse0x1d94cc70();
   input += synapse0x1d94ccb0();
   input += synapse0x1d94c860();
   input += synapse0x1d94c8a0();
   input += synapse0x1d94c8e0();
   input += synapse0x1d94c920();
   input += synapse0x1d94cf00();
   input += synapse0x1d94cf40();
   input += synapse0x1d94cf80();
   input += synapse0x1d94cfc0();
   input += synapse0x1d94d000();
   input += synapse0x1d94d040();
   input += synapse0x1d94d080();
   input += synapse0x1d94d0c0();
   input += synapse0x1d94d100();
   input += synapse0x1d94d140();
   input += synapse0x1d94d180();
   return input;
}

double NNIdClass::neuron0x1d8d1470() {
   double input = input0x1d8d1470();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d94d1c0() {
   double input = 0.58696;
   input += synapse0x1d94d500();
   input += synapse0x1d94d540();
   input += synapse0x1d94d580();
   input += synapse0x1d94d5c0();
   input += synapse0x1d94d600();
   input += synapse0x1d94d640();
   input += synapse0x1d94d680();
   input += synapse0x1d94d6c0();
   input += synapse0x1d94d700();
   input += synapse0x1d94d740();
   input += synapse0x1d94d780();
   input += synapse0x1d94d7c0();
   input += synapse0x1d94d800();
   input += synapse0x1d94d840();
   input += synapse0x1d94d880();
   input += synapse0x1d94d8c0();
   input += synapse0x1d94d350();
   input += synapse0x1d94d390();
   input += synapse0x1d94da10();
   input += synapse0x1d94da50();
   input += synapse0x1d94da90();
   input += synapse0x1d94dad0();
   input += synapse0x1d94db10();
   input += synapse0x1d94db50();
   input += synapse0x1d94db90();
   input += synapse0x1d94dbd0();
   input += synapse0x1d94dc10();
   input += synapse0x1d94dc50();
   input += synapse0x1d94dc90();
   input += synapse0x1d94dcd0();
   input += synapse0x1d94dd10();
   input += synapse0x1d94dd50();
   input += synapse0x1d94d900();
   input += synapse0x1d94d940();
   input += synapse0x1d94d980();
   input += synapse0x1d94d9c0();
   input += synapse0x1d94dfa0();
   input += synapse0x1d94dfe0();
   input += synapse0x1d94e020();
   input += synapse0x1d94e060();
   input += synapse0x1d94e0a0();
   input += synapse0x1d94e0e0();
   input += synapse0x1d94e120();
   input += synapse0x1d94e160();
   input += synapse0x1d94e1a0();
   input += synapse0x1d94e1e0();
   input += synapse0x1d94e220();
   return input;
}

double NNIdClass::neuron0x1d94d1c0() {
   double input = input0x1d94d1c0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d94e260() {
   double input = -1.64829;
   input += synapse0x1d94e5a0();
   input += synapse0x1d94e5e0();
   input += synapse0x1d94e620();
   input += synapse0x1d94e660();
   input += synapse0x1d94e6a0();
   input += synapse0x1d94e6e0();
   input += synapse0x1d94e720();
   input += synapse0x1d94e760();
   input += synapse0x1d94e7a0();
   input += synapse0x1d94e7e0();
   input += synapse0x1d94e820();
   input += synapse0x1d94e860();
   input += synapse0x1d94e8a0();
   input += synapse0x1d94e8e0();
   input += synapse0x1d94e920();
   input += synapse0x1d94e960();
   input += synapse0x1d94e3f0();
   input += synapse0x1d94e430();
   input += synapse0x1d94eab0();
   input += synapse0x1d94eaf0();
   input += synapse0x1d94eb30();
   input += synapse0x1d94eb70();
   input += synapse0x1d94ebb0();
   input += synapse0x1d94ebf0();
   input += synapse0x1d94ec30();
   input += synapse0x1d94ec70();
   input += synapse0x1d94ecb0();
   input += synapse0x1d94ecf0();
   input += synapse0x1d94ed30();
   input += synapse0x1d94ed70();
   input += synapse0x1d94edb0();
   input += synapse0x1d94edf0();
   input += synapse0x1d94e9a0();
   input += synapse0x1d94e9e0();
   input += synapse0x1d94ea20();
   input += synapse0x1d94ea60();
   input += synapse0x1d94f040();
   input += synapse0x1d94f080();
   input += synapse0x1d94f0c0();
   input += synapse0x1d94f100();
   input += synapse0x1d94f140();
   input += synapse0x1d94f180();
   input += synapse0x1d94f1c0();
   input += synapse0x1d94f200();
   input += synapse0x1d94f240();
   input += synapse0x1d94f280();
   input += synapse0x1d94f2c0();
   return input;
}

double NNIdClass::neuron0x1d94e260() {
   double input = input0x1d94e260();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d94f300() {
   double input = 0.625355;
   input += synapse0x1d94f640();
   input += synapse0x1d94f680();
   input += synapse0x1d94f6c0();
   input += synapse0x1d94f700();
   input += synapse0x1d94f740();
   input += synapse0x1d94f780();
   input += synapse0x1d94f7c0();
   input += synapse0x1d94f800();
   input += synapse0x1d94f840();
   input += synapse0x1d94f880();
   input += synapse0x1d94f8c0();
   input += synapse0x1d94f900();
   input += synapse0x1d94f940();
   input += synapse0x1d94f980();
   input += synapse0x1d94f9c0();
   input += synapse0x1d94fa00();
   input += synapse0x1d94f490();
   input += synapse0x1d94f4d0();
   input += synapse0x1d94fb50();
   input += synapse0x1d94fb90();
   input += synapse0x1d94fbd0();
   input += synapse0x1d94fc10();
   input += synapse0x1d94fc50();
   input += synapse0x1d94fc90();
   input += synapse0x1d94fcd0();
   input += synapse0x1d94fd10();
   input += synapse0x1d94fd50();
   input += synapse0x1d94fd90();
   input += synapse0x1d94fdd0();
   input += synapse0x1d94fe10();
   input += synapse0x1d94fe50();
   input += synapse0x1d94fe90();
   input += synapse0x1d94fa40();
   input += synapse0x1d94fa80();
   input += synapse0x1d94fac0();
   input += synapse0x1d94fb00();
   input += synapse0x1d9500e0();
   input += synapse0x1d950120();
   input += synapse0x1d950160();
   input += synapse0x1d9501a0();
   input += synapse0x1d9501e0();
   input += synapse0x1d950220();
   input += synapse0x1d950260();
   input += synapse0x1d9502a0();
   input += synapse0x1d9502e0();
   input += synapse0x1d950320();
   input += synapse0x1d950360();
   return input;
}

double NNIdClass::neuron0x1d94f300() {
   double input = input0x1d94f300();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d9503a0() {
   double input = -0.25396;
   input += synapse0x1d8cf630();
   input += synapse0x1d8cf670();
   input += synapse0x1d8cf6b0();
   input += synapse0x1d8cf6f0();
   input += synapse0x1d8cf730();
   input += synapse0x1d8cf770();
   input += synapse0x1d8cf7b0();
   input += synapse0x1d8cf7f0();
   input += synapse0x1d8cf830();
   input += synapse0x1d8cf870();
   input += synapse0x1d8cf8b0();
   input += synapse0x1d8cf8f0();
   input += synapse0x1d8cf930();
   input += synapse0x1d8cf970();
   input += synapse0x1d8cf9b0();
   input += synapse0x1d8cf9f0();
   input += synapse0x1d8cf480();
   input += synapse0x1d8cf4c0();
   input += synapse0x1d8cfb40();
   input += synapse0x1d8cfb80();
   input += synapse0x1d8cfbc0();
   input += synapse0x1d8cfc00();
   input += synapse0x1d8cfc40();
   input += synapse0x1d8cfc80();
   input += synapse0x1d8cfcc0();
   input += synapse0x1d8cfd00();
   input += synapse0x1d8cfd40();
   input += synapse0x1d8cfd80();
   input += synapse0x1d8cfdc0();
   input += synapse0x1d8cfe00();
   input += synapse0x1d8cfe40();
   input += synapse0x1d8cfe80();
   input += synapse0x1d8cfa30();
   input += synapse0x1d8cfa70();
   input += synapse0x1d8cfab0();
   input += synapse0x1d8cfaf0();
   input += synapse0x1d8d00d0();
   input += synapse0x1d8d0110();
   input += synapse0x1d8d0150();
   input += synapse0x1d8d0190();
   input += synapse0x1d8d01d0();
   input += synapse0x1d8d0210();
   input += synapse0x1d8d0250();
   input += synapse0x1d8d0290();
   input += synapse0x1d8d02d0();
   input += synapse0x1d8d0310();
   input += synapse0x1d8d0350();
   return input;
}

double NNIdClass::neuron0x1d9503a0() {
   double input = input0x1d9503a0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x3d255f0() {
   double input = -2.12484;
   input += synapse0x3d25930();
   input += synapse0x3d25970();
   input += synapse0x3d259b0();
   input += synapse0x3d259f0();
   input += synapse0x3d25a30();
   input += synapse0x3d25a70();
   input += synapse0x3d25ab0();
   input += synapse0x3d25af0();
   input += synapse0x3d25b30();
   input += synapse0x3d25b70();
   input += synapse0x3d25bb0();
   input += synapse0x3d25bf0();
   input += synapse0x3d25c30();
   input += synapse0x3d25c70();
   input += synapse0x3d25cb0();
   input += synapse0x3d25cf0();
   input += synapse0x3d25780();
   input += synapse0x3d257c0();
   input += synapse0x1d8d0390();
   input += synapse0x1d8d03d0();
   input += synapse0x1d8d0410();
   input += synapse0x1d8d0450();
   input += synapse0x3d25e40();
   input += synapse0x3d25e80();
   input += synapse0x3d25ec0();
   input += synapse0x3d25f00();
   input += synapse0x3d25f40();
   input += synapse0x3d25f80();
   input += synapse0x3d25fc0();
   input += synapse0x3d26000();
   input += synapse0x3d26040();
   input += synapse0x3d26080();
   input += synapse0x3d25d30();
   input += synapse0x3d25d70();
   input += synapse0x3d25db0();
   input += synapse0x3d25df0();
   input += synapse0x3d262d0();
   input += synapse0x3d26310();
   input += synapse0x3d26350();
   input += synapse0x3d26390();
   input += synapse0x3d263d0();
   input += synapse0x3d26410();
   input += synapse0x3d26450();
   input += synapse0x3d26490();
   input += synapse0x3d264d0();
   input += synapse0x3d26510();
   input += synapse0x3d26550();
   return input;
}

double NNIdClass::neuron0x3d255f0() {
   double input = input0x3d255f0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x3d26590() {
   double input = -0.267628;
   input += synapse0x3d268d0();
   input += synapse0x3d26910();
   input += synapse0x3d26950();
   input += synapse0x3d26990();
   input += synapse0x3d269d0();
   input += synapse0x3d26a10();
   input += synapse0x3d26a50();
   input += synapse0x3d26a90();
   input += synapse0x3d26ad0();
   input += synapse0x3d26b10();
   input += synapse0x3d26b50();
   input += synapse0x3d26b90();
   input += synapse0x3d26bd0();
   input += synapse0x3d26c10();
   input += synapse0x3d26c50();
   input += synapse0x3d26c90();
   input += synapse0x3d26720();
   input += synapse0x3d26760();
   input += synapse0x3d26de0();
   input += synapse0x3d26e20();
   input += synapse0x3d26e60();
   input += synapse0x3d26ea0();
   input += synapse0x3d26ee0();
   input += synapse0x3d26f20();
   input += synapse0x3d26f60();
   input += synapse0x3d26fa0();
   input += synapse0x3d26fe0();
   input += synapse0x3d27020();
   input += synapse0x3d27060();
   input += synapse0x3d270a0();
   input += synapse0x3d270e0();
   input += synapse0x3d27120();
   input += synapse0x3d26cd0();
   input += synapse0x3d26d10();
   input += synapse0x3d26d50();
   input += synapse0x3d26d90();
   input += synapse0x3d27370();
   input += synapse0x3d273b0();
   input += synapse0x3d273f0();
   input += synapse0x3d27430();
   input += synapse0x3d27470();
   input += synapse0x3d274b0();
   input += synapse0x3d274f0();
   input += synapse0x3d27530();
   input += synapse0x3d27570();
   input += synapse0x3d275b0();
   input += synapse0x1d8e47d0();
   return input;
}

double NNIdClass::neuron0x3d26590() {
   double input = input0x3d26590();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d8e4810() {
   double input = -0.299995;
   input += synapse0x1d8e4b50();
   input += synapse0x1d8e4b90();
   input += synapse0x1d8e4bd0();
   input += synapse0x1d8e4c10();
   input += synapse0x1d8e4c50();
   input += synapse0x1d8e4c90();
   input += synapse0x1d8e4cd0();
   input += synapse0x1d8e4d10();
   input += synapse0x1d8e4d50();
   input += synapse0x1d8e4d90();
   input += synapse0x1d8e4dd0();
   input += synapse0x1d8e4e10();
   input += synapse0x1d8e4e50();
   input += synapse0x1d8e4e90();
   input += synapse0x1d8e4ed0();
   input += synapse0x1d8e4f10();
   input += synapse0x1d8e49a0();
   input += synapse0x1d8e49e0();
   input += synapse0x1d8e5060();
   input += synapse0x1d8e50a0();
   input += synapse0x1d8e50e0();
   input += synapse0x1d8e5120();
   input += synapse0x1d8e5160();
   input += synapse0x1d8e51a0();
   input += synapse0x1d8e51e0();
   input += synapse0x1d8e5220();
   input += synapse0x1d8e5260();
   input += synapse0x1d8e52a0();
   input += synapse0x1d8e52e0();
   input += synapse0x1d8e5320();
   input += synapse0x1d8e5360();
   input += synapse0x1d8e53a0();
   input += synapse0x1d8e4f50();
   input += synapse0x1d8e4f90();
   input += synapse0x1d8e4fd0();
   input += synapse0x1d8e5010();
   input += synapse0x1d8e55f0();
   input += synapse0x1d8e5630();
   input += synapse0x1d8e5670();
   input += synapse0x1d8e56b0();
   input += synapse0x1d8e56f0();
   input += synapse0x1d8e5730();
   input += synapse0x1d8e5770();
   input += synapse0x1d8e57b0();
   input += synapse0x1d8e57f0();
   input += synapse0x1d8e5830();
   input += synapse0x1d8e5870();
   return input;
}

double NNIdClass::neuron0x1d8e4810() {
   double input = input0x1d8e4810();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d8e58b0() {
   double input = 2.06564;
   input += synapse0x1d8e5bf0();
   input += synapse0x3e01510();
   input += synapse0x3e01550();
   input += synapse0x3e01850();
   input += synapse0x3e01890();
   input += synapse0x3e01b90();
   input += synapse0x3e01bd0();
   input += synapse0x1de98d40();
   input += synapse0x1de98d80();
   input += synapse0x1de990c0();
   input += synapse0x1de99100();
   input += synapse0x1de99440();
   input += synapse0x1de99480();
   input += synapse0x1d8d68b0();
   input += synapse0x1d8d68f0();
   input += synapse0x1d8d6bf0();
   input += synapse0x1d8d6c30();
   input += synapse0x1d8d6f30();
   input += synapse0x1d8d6f70();
   input += synapse0x1d8d7270();
   input += synapse0x1d8d72b0();
   input += synapse0x1d8d75b0();
   input += synapse0x1d8d75f0();
   input += synapse0x1d8d78f0();
   input += synapse0x1d8d7930();
   input += synapse0x1d8d7c30();
   input += synapse0x1d8d7c70();
   input += synapse0x1d8d7f70();
   input += synapse0x1d8d7fb0();
   input += synapse0x1d8d82b0();
   input += synapse0x1d8d82f0();
   input += synapse0x1d8e5a40();
   input += synapse0x1d8e5a80();
   input += synapse0x1d8d46c0();
   input += synapse0x1d8d4700();
   input += synapse0x1d8d4c20();
   input += synapse0x1d8d4c60();
   input += synapse0x1d8d4f60();
   input += synapse0x1d8d4fa0();
   input += synapse0x1d8d52d0();
   input += synapse0x1d8d5310();
   input += synapse0x1d8d5640();
   input += synapse0x1d8d5680();
   input += synapse0x1d8d5980();
   input += synapse0x1d8d59c0();
   input += synapse0x1d8d5cc0();
   input += synapse0x1d8d5d00();
   return input;
}

double NNIdClass::neuron0x1d8e58b0() {
   double input = input0x1d8e58b0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d8e9030() {
   double input = 0.297029;
   input += synapse0x1d8e91c0();
   input += synapse0x1d8e9200();
   input += synapse0x1d8e9240();
   input += synapse0x1d8e9280();
   input += synapse0x1d8e92c0();
   input += synapse0x1d8e9300();
   input += synapse0x1d8e9340();
   input += synapse0x1d8e9380();
   input += synapse0x1d8e93c0();
   input += synapse0x1d8e9400();
   input += synapse0x1d8e9440();
   input += synapse0x1d8e9480();
   input += synapse0x1d8e94c0();
   input += synapse0x1d8e9500();
   input += synapse0x1d8e9540();
   input += synapse0x1d8e9580();
   input += synapse0x1d90fcd0();
   input += synapse0x1d90fd10();
   input += synapse0x1d910010();
   input += synapse0x1d910050();
   input += synapse0x1d910350();
   input += synapse0x1d910390();
   input += synapse0x1d910690();
   input += synapse0x1d9106d0();
   input += synapse0x1d9109d0();
   input += synapse0x1d910a10();
   input += synapse0x1d910d10();
   input += synapse0x1d910d50();
   input += synapse0x1d911250();
   input += synapse0x1d911290();
   input += synapse0x1d911590();
   input += synapse0x1d9115d0();
   input += synapse0x1d8e9d10();
   input += synapse0x1d8e9d50();
   input += synapse0x1d8ea050();
   input += synapse0x1d8ea090();
   input += synapse0x1d8ea390();
   input += synapse0x1d8ea3d0();
   input += synapse0x1d8ea6d0();
   input += synapse0x1d8ea710();
   input += synapse0x1d8eaa10();
   input += synapse0x1d8eaa50();
   input += synapse0x1d8ead50();
   input += synapse0x1d8ead90();
   input += synapse0x1d8eb0c0();
   input += synapse0x1d8eb100();
   input += synapse0x1d8eb430();
   return input;
}

double NNIdClass::neuron0x1d8e9030() {
   double input = input0x1d8e9030();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d903a50() {
   double input = -0.113526;
   input += synapse0x1d8eb470();
   input += synapse0x1d8c8c00();
   input += synapse0x1d8c8c40();
   input += synapse0x1d8d6000();
   input += synapse0x1d8d6040();
   input += synapse0x1de99690();
   input += synapse0x1de996d0();
   input += synapse0x1d8d6340();
   input += synapse0x1d8d6380();
   input += synapse0x1d8e98e0();
   input += synapse0x1d8e9920();
   input += synapse0x1d8e9960();
   input += synapse0x1d8e95c0();
   input += synapse0x1d8e9600();
   input += synapse0x1d8e9640();
   input += synapse0x1d8e9680();
   input += synapse0x1d8eb7a0();
   input += synapse0x1d8eb7e0();
   input += synapse0x1d911150();
   input += synapse0x1d911190();
   input += synapse0x1d9111d0();
   input += synapse0x1d911210();
   input += synapse0x1d903ff0();
   input += synapse0x1d904030();
   input += synapse0x1d904070();
   input += synapse0x1d9040b0();
   input += synapse0x1d9040f0();
   input += synapse0x1d904130();
   input += synapse0x1d904170();
   input += synapse0x1d9041b0();
   input += synapse0x1d9041f0();
   input += synapse0x1d904230();
   input += synapse0x1d911040();
   input += synapse0x1d911080();
   input += synapse0x1d9110c0();
   input += synapse0x1d911100();
   input += synapse0x1d904480();
   input += synapse0x1d9044c0();
   input += synapse0x1d904500();
   input += synapse0x1d904540();
   input += synapse0x1d904580();
   input += synapse0x1d9045c0();
   input += synapse0x1d904600();
   input += synapse0x1d904640();
   input += synapse0x1d904680();
   input += synapse0x1d9046c0();
   input += synapse0x1d904700();
   return input;
}

double NNIdClass::neuron0x1d903a50() {
   double input = input0x1d903a50();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d904740() {
   double input = -0.48764;
   input += synapse0x1d904a80();
   input += synapse0x1d904ac0();
   input += synapse0x1d904b00();
   input += synapse0x1d904b40();
   input += synapse0x1d904b80();
   input += synapse0x1d904bc0();
   input += synapse0x1d904c00();
   input += synapse0x1d904c40();
   input += synapse0x1d904c80();
   input += synapse0x1d904cc0();
   input += synapse0x1d904d00();
   input += synapse0x1d904d40();
   input += synapse0x1d904d80();
   input += synapse0x1d904dc0();
   input += synapse0x1d904e00();
   input += synapse0x1d904e40();
   input += synapse0x1d9048d0();
   input += synapse0x1d904910();
   input += synapse0x1d904f90();
   input += synapse0x1d904fd0();
   input += synapse0x1d905010();
   input += synapse0x1d905050();
   input += synapse0x1d905090();
   input += synapse0x1d9050d0();
   input += synapse0x1d905110();
   input += synapse0x1d905150();
   input += synapse0x1d905190();
   input += synapse0x1d9051d0();
   input += synapse0x1d905210();
   input += synapse0x1d905250();
   input += synapse0x1d905290();
   input += synapse0x1d9052d0();
   input += synapse0x1d904e80();
   input += synapse0x1d904ec0();
   input += synapse0x1d904f00();
   input += synapse0x1d904f40();
   input += synapse0x1d905520();
   input += synapse0x1d905560();
   input += synapse0x1d9055a0();
   input += synapse0x1d9055e0();
   input += synapse0x1d905620();
   input += synapse0x1d905660();
   input += synapse0x1d9056a0();
   input += synapse0x1d9056e0();
   input += synapse0x1d905720();
   input += synapse0x1d905760();
   input += synapse0x1d9057a0();
   return input;
}

double NNIdClass::neuron0x1d904740() {
   double input = input0x1d904740();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d9057e0() {
   double input = 0.224847;
   input += synapse0x1d905b20();
   input += synapse0x1d905b60();
   input += synapse0x1d905ba0();
   input += synapse0x1d905be0();
   input += synapse0x1d905c20();
   input += synapse0x1d905c60();
   input += synapse0x1d905ca0();
   input += synapse0x1d905ce0();
   input += synapse0x1d905d20();
   input += synapse0x1d905d60();
   input += synapse0x1d905da0();
   input += synapse0x1d905de0();
   input += synapse0x1d905e20();
   input += synapse0x1d905e60();
   input += synapse0x1d905ea0();
   input += synapse0x1d905ee0();
   input += synapse0x1d905970();
   input += synapse0x1d9059b0();
   input += synapse0x1d906030();
   input += synapse0x1d906070();
   input += synapse0x1d9060b0();
   input += synapse0x1d9060f0();
   input += synapse0x1d906130();
   input += synapse0x1d906170();
   input += synapse0x1d9061b0();
   input += synapse0x1d9061f0();
   input += synapse0x1d906230();
   input += synapse0x1d906270();
   input += synapse0x1d9062b0();
   input += synapse0x1d9062f0();
   input += synapse0x1d906330();
   input += synapse0x1d906370();
   input += synapse0x1d905f20();
   input += synapse0x1d905f60();
   input += synapse0x1d905fa0();
   input += synapse0x1d905fe0();
   input += synapse0x1d9065c0();
   input += synapse0x1d906600();
   input += synapse0x1d906640();
   input += synapse0x1d906680();
   input += synapse0x1d9066c0();
   input += synapse0x1d906700();
   input += synapse0x1d906740();
   input += synapse0x1d906780();
   input += synapse0x1d9067c0();
   input += synapse0x1d906800();
   input += synapse0x1d906840();
   return input;
}

double NNIdClass::neuron0x1d9057e0() {
   double input = input0x1d9057e0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d906880() {
   double input = 0.54902;
   input += synapse0x1d906bc0();
   input += synapse0x1d906c00();
   input += synapse0x1d906c40();
   input += synapse0x1d906c80();
   input += synapse0x1d906cc0();
   input += synapse0x1d906d00();
   input += synapse0x1d906d40();
   input += synapse0x1d906d80();
   input += synapse0x1d906dc0();
   input += synapse0x1d906e00();
   input += synapse0x1d906e40();
   input += synapse0x1d906e80();
   input += synapse0x1d906ec0();
   input += synapse0x1d906f00();
   input += synapse0x1d906f40();
   input += synapse0x1d906f80();
   input += synapse0x1d906a10();
   input += synapse0x1d906a50();
   input += synapse0x1d9070d0();
   input += synapse0x1d907110();
   input += synapse0x1d907150();
   input += synapse0x1d907190();
   input += synapse0x1d9071d0();
   input += synapse0x1d907210();
   input += synapse0x1d907250();
   input += synapse0x1d907290();
   input += synapse0x1d9072d0();
   input += synapse0x1d907310();
   input += synapse0x1d907350();
   input += synapse0x1d907390();
   input += synapse0x1d9073d0();
   input += synapse0x1d907410();
   input += synapse0x1d906fc0();
   input += synapse0x1d907000();
   input += synapse0x1d907040();
   input += synapse0x1d907080();
   input += synapse0x1d907660();
   input += synapse0x1d9076a0();
   input += synapse0x1d9076e0();
   input += synapse0x1d907720();
   input += synapse0x1d907760();
   input += synapse0x1d9077a0();
   input += synapse0x1d9077e0();
   input += synapse0x1d907820();
   input += synapse0x1d907860();
   input += synapse0x1d9078a0();
   input += synapse0x1d9078e0();
   return input;
}

double NNIdClass::neuron0x1d906880() {
   double input = input0x1d906880();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d907920() {
   double input = -0.191094;
   input += synapse0x1d907c60();
   input += synapse0x1d907ca0();
   input += synapse0x1d907ce0();
   input += synapse0x1d907d20();
   input += synapse0x1d907d60();
   input += synapse0x1d907da0();
   input += synapse0x1d907de0();
   input += synapse0x1d907e20();
   input += synapse0x1d907e60();
   input += synapse0x1d907ea0();
   input += synapse0x1d907ee0();
   input += synapse0x1d907f20();
   input += synapse0x1d907f60();
   input += synapse0x1d907fa0();
   input += synapse0x1d907fe0();
   input += synapse0x1d908020();
   input += synapse0x1d907ab0();
   input += synapse0x1d907af0();
   input += synapse0x1d908170();
   input += synapse0x1d9081b0();
   input += synapse0x1d9081f0();
   input += synapse0x1d908230();
   input += synapse0x1d908270();
   input += synapse0x1d9082b0();
   input += synapse0x1d9082f0();
   input += synapse0x1d908330();
   input += synapse0x1d908370();
   input += synapse0x1d9083b0();
   input += synapse0x1d9083f0();
   input += synapse0x1d908430();
   input += synapse0x1d908470();
   input += synapse0x1d9084b0();
   input += synapse0x1d908060();
   input += synapse0x1d9080a0();
   input += synapse0x1d9080e0();
   input += synapse0x1d908120();
   input += synapse0x1d908700();
   input += synapse0x1d908740();
   input += synapse0x1d908780();
   input += synapse0x1d9087c0();
   input += synapse0x1d908800();
   input += synapse0x1d908840();
   input += synapse0x1d908880();
   input += synapse0x1d9088c0();
   input += synapse0x1d908900();
   input += synapse0x1d908940();
   input += synapse0x1d908980();
   return input;
}

double NNIdClass::neuron0x1d907920() {
   double input = input0x1d907920();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1d9089c0() {
   double input = -0.165662;
   input += synapse0x1d908d00();
   input += synapse0x1d908d40();
   input += synapse0x1d908d80();
   input += synapse0x1d908dc0();
   input += synapse0x1d908e00();
   input += synapse0x1d908e40();
   input += synapse0x1d908e80();
   input += synapse0x1d908ec0();
   input += synapse0x1d908f00();
   input += synapse0x1d908f40();
   input += synapse0x1d908f80();
   input += synapse0x1d908fc0();
   input += synapse0x1d909000();
   input += synapse0x1d909040();
   input += synapse0x1d909080();
   input += synapse0x1d9090c0();
   input += synapse0x1d908b50();
   input += synapse0x1d908b90();
   input += synapse0x1d909210();
   input += synapse0x1d909250();
   input += synapse0x1d909290();
   input += synapse0x1d9092d0();
   input += synapse0x1d909310();
   input += synapse0x1d909350();
   input += synapse0x1d909390();
   input += synapse0x1d9093d0();
   input += synapse0x1d909410();
   input += synapse0x1d909450();
   input += synapse0x1d957260();
   input += synapse0x1d9572a0();
   input += synapse0x1d9572e0();
   input += synapse0x1d957320();
   input += synapse0x1d909100();
   input += synapse0x1d909140();
   input += synapse0x1d909180();
   input += synapse0x1d9091c0();
   input += synapse0x1d957570();
   input += synapse0x1d9575b0();
   input += synapse0x1d9575f0();
   input += synapse0x1d957630();
   input += synapse0x1d957670();
   input += synapse0x1d9576b0();
   input += synapse0x1d9576f0();
   input += synapse0x1d957730();
   input += synapse0x1d957770();
   input += synapse0x1d9577b0();
   input += synapse0x1d9577f0();
   return input;
}

double NNIdClass::neuron0x1d9089c0() {
   double input = input0x1d9089c0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x3d236f0() {
   double input = 0.419188;
   input += synapse0x3d23880();
   input += synapse0x3d238c0();
   input += synapse0x3d23900();
   input += synapse0x3d23940();
   input += synapse0x3d23980();
   input += synapse0x3d239c0();
   input += synapse0x3d23a00();
   input += synapse0x3d23a40();
   input += synapse0x3d23a80();
   input += synapse0x3d23ac0();
   input += synapse0x3d23b00();
   input += synapse0x3d23b40();
   input += synapse0x3d23b80();
   input += synapse0x3d23bc0();
   input += synapse0x3d23c00();
   input += synapse0x3d23c40();
   input += synapse0x1d8cb650();
   input += synapse0x1d8cb690();
   input += synapse0x1d8cde40();
   input += synapse0x1d8cde80();
   input += synapse0x1d8cede0();
   input += synapse0x1d8cee20();
   input += synapse0x1d8d0740();
   return input;
}

double NNIdClass::neuron0x3d236f0() {
   double input = input0x3d236f0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x3d23d90() {
   double input = 1.02594;
   input += synapse0x3d23f20();
   input += synapse0x3d23f60();
   input += synapse0x3d23fa0();
   input += synapse0x3d23fe0();
   input += synapse0x3d24020();
   input += synapse0x3d24060();
   input += synapse0x3d240a0();
   input += synapse0x3d240e0();
   input += synapse0x3d24120();
   input += synapse0x3d24160();
   input += synapse0x3d241a0();
   input += synapse0x3d241e0();
   input += synapse0x3d24220();
   input += synapse0x3d24260();
   input += synapse0x3d242a0();
   input += synapse0x3d242e0();
   input += synapse0x1d8d0780();
   input += synapse0x1d94f5b0();
   input += synapse0x1d94f5f0();
   input += synapse0x1d8cf5a0();
   input += synapse0x1d8cf5e0();
   input += synapse0x3d258a0();
   input += synapse0x3d258e0();
   return input;
}

double NNIdClass::neuron0x3d23d90() {
   double input = input0x3d23d90();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x3d24430() {
   double input = 0.213533;
   input += synapse0x3d245c0();
   input += synapse0x3d24600();
   input += synapse0x3d24640();
   input += synapse0x3d24680();
   input += synapse0x3d246c0();
   input += synapse0x3d24700();
   input += synapse0x3d24740();
   input += synapse0x3d24780();
   input += synapse0x3d247c0();
   input += synapse0x3d24800();
   input += synapse0x3d24840();
   input += synapse0x3d24880();
   input += synapse0x3d248c0();
   input += synapse0x3d24900();
   input += synapse0x3d24940();
   input += synapse0x3d24980();
   input += synapse0x1d90f990();
   input += synapse0x1d90f9d0();
   input += synapse0x1d8c8890();
   input += synapse0x1d8c88d0();
   input += synapse0x1d9049f0();
   input += synapse0x1d904a30();
   input += synapse0x1d905a90();
   return input;
}

double NNIdClass::neuron0x3d24430() {
   double input = input0x3d24430();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x3d24ad0() {
   double input = -0.00719581;
   input += synapse0x3d24c60();
   input += synapse0x3d24ca0();
   input += synapse0x3d24ce0();
   input += synapse0x3d24d20();
   input += synapse0x3d24d60();
   input += synapse0x3d24da0();
   input += synapse0x3d24de0();
   input += synapse0x3d24e20();
   input += synapse0x3d24e60();
   input += synapse0x3d24ea0();
   input += synapse0x3d24ee0();
   input += synapse0x3d24f20();
   input += synapse0x3d24f60();
   input += synapse0x3d24fa0();
   input += synapse0x3d24fe0();
   input += synapse0x3d25020();
   input += synapse0x1d905ad0();
   input += synapse0x1d908c70();
   input += synapse0x1d908cb0();
   input += synapse0x1d8c8fd0();
   input += synapse0x1d8c9010();
   input += synapse0x1d8d1720();
   input += synapse0x1d8d1760();
   return input;
}

double NNIdClass::neuron0x3d24ad0() {
   double input = input0x3d24ad0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x3d25170() {
   double input = -0.45583;
   input += synapse0x3d25390();
   input += synapse0x3d253d0();
   input += synapse0x3d25410();
   input += synapse0x3d25450();
   input += synapse0x3d25490();
   input += synapse0x3d254d0();
   input += synapse0x3d25510();
   input += synapse0x3d25550();
   input += synapse0x3d25590();
   input += synapse0x1dc484c0();
   input += synapse0x1dc48500();
   input += synapse0x1dc48540();
   input += synapse0x1dc48580();
   input += synapse0x1dc485c0();
   input += synapse0x1dc48600();
   input += synapse0x1dc48640();
   input += synapse0x3d26840();
   input += synapse0x3d26880();
   input += synapse0x1dc48790();
   input += synapse0x1dc487d0();
   input += synapse0x1dc48810();
   input += synapse0x1dc48850();
   input += synapse0x1dc48890();
   return input;
}

double NNIdClass::neuron0x3d25170() {
   double input = input0x3d25170();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1dc488d0() {
   double input = -0.489085;
   input += synapse0x1dc48c10();
   input += synapse0x1dc48c50();
   input += synapse0x1dc48c90();
   input += synapse0x1dc48cd0();
   input += synapse0x1dc48d10();
   input += synapse0x1dc48d50();
   input += synapse0x1dc48d90();
   input += synapse0x1dc48dd0();
   input += synapse0x1dc48e10();
   input += synapse0x1dc48e50();
   input += synapse0x1dc48e90();
   input += synapse0x1dc48ed0();
   input += synapse0x1dc48f10();
   input += synapse0x1dc48f50();
   input += synapse0x1dc48f90();
   input += synapse0x1dc48fd0();
   input += synapse0x1dc48a60();
   input += synapse0x1dc48aa0();
   input += synapse0x1dc49120();
   input += synapse0x1dc49160();
   input += synapse0x1dc491a0();
   input += synapse0x1dc491e0();
   input += synapse0x1dc49220();
   return input;
}

double NNIdClass::neuron0x1dc488d0() {
   double input = input0x1dc488d0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1dc49260() {
   double input = 0.55531;
   input += synapse0x1dc495a0();
   input += synapse0x1dc495e0();
   input += synapse0x1dc49620();
   input += synapse0x1dc49660();
   input += synapse0x1dc496a0();
   input += synapse0x1dc496e0();
   input += synapse0x1dc49720();
   input += synapse0x1dc49760();
   input += synapse0x1dc497a0();
   input += synapse0x1dc497e0();
   input += synapse0x1dc49820();
   input += synapse0x1dc49860();
   input += synapse0x1dc498a0();
   input += synapse0x1dc498e0();
   input += synapse0x1dc49920();
   input += synapse0x1dc49960();
   input += synapse0x1dc493f0();
   input += synapse0x1dc49430();
   input += synapse0x1dc49ab0();
   input += synapse0x1dc49af0();
   input += synapse0x1dc49b30();
   input += synapse0x1dc49b70();
   input += synapse0x1dc49bb0();
   return input;
}

double NNIdClass::neuron0x1dc49260() {
   double input = input0x1dc49260();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1dc49bf0() {
   double input = -0.240364;
   input += synapse0x1dc49f30();
   input += synapse0x1dc49f70();
   input += synapse0x1dc49fb0();
   input += synapse0x1dc49ff0();
   input += synapse0x1dc4a030();
   input += synapse0x1dc4a070();
   input += synapse0x1dc4a0b0();
   input += synapse0x1dc4a0f0();
   input += synapse0x1dc4a130();
   input += synapse0x1dc4a170();
   input += synapse0x1dc4a1b0();
   input += synapse0x1dc4a1f0();
   input += synapse0x1dc4a230();
   input += synapse0x1dc4a270();
   input += synapse0x1dc4a2b0();
   input += synapse0x1dc4a2f0();
   input += synapse0x1dc49d80();
   input += synapse0x1dc49dc0();
   input += synapse0x1dc4a440();
   input += synapse0x1dc4a480();
   input += synapse0x1dc4a4c0();
   input += synapse0x1dc4a500();
   input += synapse0x1dc4a540();
   return input;
}

double NNIdClass::neuron0x1dc49bf0() {
   double input = input0x1dc49bf0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1dc4a580() {
   double input = 0.945144;
   input += synapse0x1dc4a8c0();
   input += synapse0x1dc4a900();
   input += synapse0x1dc4a940();
   input += synapse0x1dc4a980();
   input += synapse0x1dc4a9c0();
   input += synapse0x1dc4aa00();
   input += synapse0x1dc4aa40();
   input += synapse0x1dc4aa80();
   input += synapse0x1dc4aac0();
   input += synapse0x1dc4ab00();
   input += synapse0x1dc4ab40();
   input += synapse0x1dc4ab80();
   input += synapse0x1dc4abc0();
   input += synapse0x1dc4ac00();
   input += synapse0x1dc4ac40();
   input += synapse0x1dc4ac80();
   input += synapse0x1dc4a710();
   input += synapse0x1dc4a750();
   input += synapse0x1dc4add0();
   input += synapse0x1dc4ae10();
   input += synapse0x1dc4ae50();
   input += synapse0x1dc4ae90();
   input += synapse0x1dc4aed0();
   return input;
}

double NNIdClass::neuron0x1dc4a580() {
   double input = input0x1dc4a580();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1dc4af10() {
   double input = -0.563806;
   input += synapse0x1dc4b250();
   input += synapse0x1dc4b290();
   input += synapse0x1dc4b2d0();
   input += synapse0x1dc4b310();
   input += synapse0x1dc4b350();
   input += synapse0x1dc4b390();
   input += synapse0x1dc4b3d0();
   input += synapse0x1dc4b410();
   input += synapse0x1dc4b450();
   input += synapse0x1dc4b490();
   input += synapse0x1dc4b4d0();
   input += synapse0x1dc4b510();
   input += synapse0x1dc4b550();
   input += synapse0x1dc4b590();
   input += synapse0x1dc4b5d0();
   input += synapse0x1dc4b610();
   input += synapse0x1dc4b0a0();
   input += synapse0x1dc4b0e0();
   input += synapse0x1dc4b760();
   input += synapse0x1dc4b7a0();
   input += synapse0x1dc4b7e0();
   input += synapse0x1dc4b820();
   input += synapse0x1dc4b860();
   return input;
}

double NNIdClass::neuron0x1dc4af10() {
   double input = input0x1dc4af10();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1dc4b8a0() {
   double input = 0.032248;
   input += synapse0x1dc4bbe0();
   input += synapse0x1dc4bc20();
   input += synapse0x1dc4bc60();
   input += synapse0x1dc4bca0();
   input += synapse0x1dc4bce0();
   input += synapse0x1dc4bd20();
   input += synapse0x1dc4bd60();
   input += synapse0x1dc4bda0();
   input += synapse0x1dc4bde0();
   input += synapse0x1dc4be20();
   input += synapse0x1dc4be60();
   input += synapse0x1dc4bea0();
   input += synapse0x1dc4bee0();
   input += synapse0x1dc4bf20();
   input += synapse0x1dc4bf60();
   input += synapse0x1dc4bfa0();
   input += synapse0x1dc4ba30();
   input += synapse0x1dc4ba70();
   input += synapse0x1dc4c0f0();
   input += synapse0x1dc4c130();
   input += synapse0x1dc4c170();
   input += synapse0x1dc4c1b0();
   input += synapse0x1dc4c1f0();
   return input;
}

double NNIdClass::neuron0x1dc4b8a0() {
   double input = input0x1dc4b8a0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1dc4c230() {
   double input = 0.111397;
   input += synapse0x1dc4c570();
   input += synapse0x1dc4c5b0();
   input += synapse0x1dc4c5f0();
   input += synapse0x1dc4c630();
   input += synapse0x1dc4c670();
   input += synapse0x1dc4c6b0();
   input += synapse0x1dc4c6f0();
   input += synapse0x1dc4c730();
   input += synapse0x1dc4c770();
   input += synapse0x1dc4c7b0();
   input += synapse0x1dc4c7f0();
   input += synapse0x1dc4c830();
   input += synapse0x1dc4c870();
   input += synapse0x1dc4c8b0();
   input += synapse0x1dc4c8f0();
   input += synapse0x1dc4c930();
   input += synapse0x1dc4c3c0();
   input += synapse0x1dc4c400();
   input += synapse0x1dc4ca80();
   input += synapse0x1dc4cac0();
   input += synapse0x1dc4cb00();
   input += synapse0x1dc4cb40();
   input += synapse0x1dc4cb80();
   return input;
}

double NNIdClass::neuron0x1dc4c230() {
   double input = input0x1dc4c230();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double NNIdClass::input0x1dc4cbc0() {
   double input = 0.245591;
   input += synapse0x1dc4cf00();
   input += synapse0x1dc4cf40();
   input += synapse0x1dc4cf80();
   input += synapse0x1dc4cfc0();
   input += synapse0x1dc4d000();
   input += synapse0x1dc4d040();
   input += synapse0x1dc4d080();
   input += synapse0x1dc4d0c0();
   input += synapse0x1dc4d100();
   input += synapse0x1dc4d140();
   input += synapse0x1dc4d180();
   input += synapse0x1dc4d1c0();
   return input;
}

double NNIdClass::neuron0x1dc4cbc0() {
   double input = input0x1dc4cbc0();
   return (input * 1)+0;
}

double NNIdClass::synapse0x3e02a70() {
   return (neuron0x3e012f0()*-0.446137);
}

double NNIdClass::synapse0x1d8c5bd0() {
   return (neuron0x3e01630()*-0.312823);
}

double NNIdClass::synapse0x1d8dba10() {
   return (neuron0x3e01970()*2.67774);
}

double NNIdClass::synapse0x1de994d0() {
   return (neuron0x1de98b20()*0.0145277);
}

double NNIdClass::synapse0x1de997d0() {
   return (neuron0x1de98e60()*0.0480497);
}

double NNIdClass::synapse0x1d8ebdf0() {
   return (neuron0x1de991e0()*-0.172376);
}

double NNIdClass::synapse0x1d8c9060() {
   return (neuron0x1d8d6690()*0.0379627);
}

double NNIdClass::synapse0x1d8c90a0() {
   return (neuron0x1d8d69d0()*-0.2695);
}

double NNIdClass::synapse0x1d8c90e0() {
   return (neuron0x1d8d6d10()*0.256538);
}

double NNIdClass::synapse0x1d8c9120() {
   return (neuron0x1d8d7050()*-0.539897);
}

double NNIdClass::synapse0x1d8c9160() {
   return (neuron0x1d8d7390()*-0.00898665);
}

double NNIdClass::synapse0x1d8c91a0() {
   return (neuron0x1d8d76d0()*-0.405597);
}

double NNIdClass::synapse0x1d8c91e0() {
   return (neuron0x1d8d7a10()*0.0510106);
}

double NNIdClass::synapse0x1d8c9220() {
   return (neuron0x1d8d7d50()*0.351715);
}

double NNIdClass::synapse0x1d8c9260() {
   return (neuron0x1d8d8090()*-5.39473);
}

double NNIdClass::synapse0x1d8c92a0() {
   return (neuron0x1d8d83d0()*-0.022588);
}

double NNIdClass::synapse0x1de987a0() {
   return (neuron0x1d8d44a0()*-0.0535812);
}

double NNIdClass::synapse0x1de987e0() {
   return (neuron0x1d8d4a00()*0.0102407);
}

double NNIdClass::synapse0x1d8d8560() {
   return (neuron0x1d8d4d40()*0.108837);
}

double NNIdClass::synapse0x1d8d85a0() {
   return (neuron0x1d8d5080()*-0.0285943);
}

double NNIdClass::synapse0x1de986a0() {
   return (neuron0x1d8d53f0()*-0.0741736);
}

double NNIdClass::synapse0x1de986e0() {
   return (neuron0x1d8d5760()*0.270769);
}

double NNIdClass::synapse0x1d8c8eb0() {
   return (neuron0x1d8d5aa0()*0.405435);
}

double NNIdClass::synapse0x1d8c8ef0() {
   return (neuron0x1d8d5de0()*-0.175237);
}

double NNIdClass::synapse0x1dc34b70() {
   return (neuron0x1d8d6120()*-0.0605623);
}

double NNIdClass::synapse0x1dc34bb0() {
   return (neuron0x1d90f490()*-0.0653868);
}

double NNIdClass::synapse0x3e00fa0() {
   return (neuron0x1d90f770()*0.683475);
}

double NNIdClass::synapse0x3e00fe0() {
   return (neuron0x1d90fab0()*0.620513);
}

double NNIdClass::synapse0x3e01020() {
   return (neuron0x1d90fdf0()*-0.188814);
}

double NNIdClass::synapse0x1d8c9500() {
   return (neuron0x1d910130()*-0.0670312);
}

double NNIdClass::synapse0x1d8c9540() {
   return (neuron0x1d910470()*0.325726);
}

double NNIdClass::synapse0x1d8c9580() {
   return (neuron0x1d9107b0()*0.0299657);
}

double NNIdClass::synapse0x1d8c92e0() {
   return (neuron0x1d910af0()*-0.115268);
}

double NNIdClass::synapse0x1d8c9320() {
   return (neuron0x1d8d47e0()*-0.333438);
}

double NNIdClass::synapse0x1d8c9360() {
   return (neuron0x1d911370()*-0.0706435);
}

double NNIdClass::synapse0x1d8c93a0() {
   return (neuron0x1d8e9af0()*0.13943);
}

double NNIdClass::synapse0x1d8c93e0() {
   return (neuron0x1d8e9e30()*0.176333);
}

double NNIdClass::synapse0x1d8c9420() {
   return (neuron0x1d8ea170()*0.239848);
}

double NNIdClass::synapse0x1d8c9460() {
   return (neuron0x1d8ea4b0()*0.228716);
}

double NNIdClass::synapse0x1d8c94a0() {
   return (neuron0x1d8ea7f0()*0.351875);
}

double NNIdClass::synapse0x1d8c99e0() {
   return (neuron0x1d8eab30()*-0.000686605);
}

double NNIdClass::synapse0x1d8c9a20() {
   return (neuron0x1d8eae70()*-0.029028);
}

double NNIdClass::synapse0x1d8c9a60() {
   return (neuron0x1d8eb1e0()*-0.0416546);
}

double NNIdClass::synapse0x1d8c9aa0() {
   return (neuron0x1d8eb550()*-0.0146991);
}

double NNIdClass::synapse0x1d8c9ae0() {
   return (neuron0x1d8eb8c0()*-0.0771222);
}

double NNIdClass::synapse0x1d8c9b20() {
   return (neuron0x1d8ebc30()*-0.582109);
}

double NNIdClass::synapse0x1d8c9b60() {
   return (neuron0x1d8c89b0()*-0.0310805);
}

double NNIdClass::synapse0x1d8c9ee0() {
   return (neuron0x3e012f0()*0.452153);
}

double NNIdClass::synapse0x1d8c9f20() {
   return (neuron0x3e01630()*0.236406);
}

double NNIdClass::synapse0x1d8c9f60() {
   return (neuron0x3e01970()*-0.480908);
}

double NNIdClass::synapse0x1d8c9fa0() {
   return (neuron0x1de98b20()*0.272442);
}

double NNIdClass::synapse0x1d8c9fe0() {
   return (neuron0x1de98e60()*0.103045);
}

double NNIdClass::synapse0x1d8ca020() {
   return (neuron0x1de991e0()*0.185565);
}

double NNIdClass::synapse0x1d8ca060() {
   return (neuron0x1d8d6690()*-0.217276);
}

double NNIdClass::synapse0x1d8ca0a0() {
   return (neuron0x1d8d69d0()*-0.297645);
}

double NNIdClass::synapse0x1d8ca0e0() {
   return (neuron0x1d8d6d10()*-0.275399);
}

double NNIdClass::synapse0x1d8ca120() {
   return (neuron0x1d8d7050()*-0.236912);
}

double NNIdClass::synapse0x1d8ca160() {
   return (neuron0x1d8d7390()*-0.24006);
}

double NNIdClass::synapse0x1d8ca1a0() {
   return (neuron0x1d8d76d0()*-0.486119);
}

double NNIdClass::synapse0x1d8ca1e0() {
   return (neuron0x1d8d7a10()*-0.0334342);
}

double NNIdClass::synapse0x1d8ca220() {
   return (neuron0x1d8d7d50()*-0.0832589);
}

double NNIdClass::synapse0x1d8ca260() {
   return (neuron0x1d8d8090()*-0.0664352);
}

double NNIdClass::synapse0x1d8ca2a0() {
   return (neuron0x1d8d83d0()*0.0685755);
}

double NNIdClass::synapse0x1d8c9d30() {
   return (neuron0x1d8d44a0()*-0.467566);
}

double NNIdClass::synapse0x1d8c9d70() {
   return (neuron0x1d8d4a00()*-0.33667);
}

double NNIdClass::synapse0x1d8c5c10() {
   return (neuron0x1d8d4d40()*0.110514);
}

double NNIdClass::synapse0x1d8d8650() {
   return (neuron0x1d8d5080()*-0.242136);
}

double NNIdClass::synapse0x1d8c6140() {
   return (neuron0x1d8d53f0()*-0.119767);
}

double NNIdClass::synapse0x1d8c61d0() {
   return (neuron0x1d8d5760()*0.109146);
}

double NNIdClass::synapse0x1de98720() {
   return (neuron0x1d8d5aa0()*-0.229861);
}

double NNIdClass::synapse0x1de98760() {
   return (neuron0x1d8d5de0()*0.712139);
}

double NNIdClass::synapse0x1de98820() {
   return (neuron0x1d8d6120()*0.18696);
}

double NNIdClass::synapse0x1de98860() {
   return (neuron0x1d90f490()*0.280883);
}

double NNIdClass::synapse0x1de99540() {
   return (neuron0x1d90f770()*0.230283);
}

double NNIdClass::synapse0x1de99580() {
   return (neuron0x1d90fab0()*0.237641);
}

double NNIdClass::synapse0x1de995c0() {
   return (neuron0x1d90fdf0()*-0.152269);
}

double NNIdClass::synapse0x1d8dba50() {
   return (neuron0x1d910130()*-0.790489);
}

double NNIdClass::synapse0x1d8dba90() {
   return (neuron0x1d910470()*-0.362978);
}

double NNIdClass::synapse0x1d8dbad0() {
   return (neuron0x1d9107b0()*0.340056);
}

double NNIdClass::synapse0x1d8db700() {
   return (neuron0x1d910af0()*-0.55636);
}

double NNIdClass::synapse0x1d8db740() {
   return (neuron0x1d8d47e0()*-0.609815);
}

double NNIdClass::synapse0x1d8db780() {
   return (neuron0x1d911370()*-0.310829);
}

double NNIdClass::synapse0x1d8ca2e0() {
   return (neuron0x1d8e9af0()*-0.434841);
}

double NNIdClass::synapse0x1d8ca320() {
   return (neuron0x1d8e9e30()*-0.141058);
}

double NNIdClass::synapse0x1d8ca360() {
   return (neuron0x1d8ea170()*0.301575);
}

double NNIdClass::synapse0x1d8ca3a0() {
   return (neuron0x1d8ea4b0()*-0.530772);
}

double NNIdClass::synapse0x3e011a0() {
   return (neuron0x1d8ea7f0()*-0.423454);
}

double NNIdClass::synapse0x3e011e0() {
   return (neuron0x1d8eab30()*-0.240977);
}

double NNIdClass::synapse0x3e01220() {
   return (neuron0x1d8eae70()*0.0479813);
}

double NNIdClass::synapse0x3e01260() {
   return (neuron0x1d8eb1e0()*-0.056664);
}

double NNIdClass::synapse0x3e012a0() {
   return (neuron0x1d8eb550()*0.0509333);
}

double NNIdClass::synapse0x1d8dbf20() {
   return (neuron0x1d8eb8c0()*-0.0131988);
}

double NNIdClass::synapse0x1d8dbf60() {
   return (neuron0x1d8ebc30()*-0.305672);
}

double NNIdClass::synapse0x1d8dbfa0() {
   return (neuron0x1d8c89b0()*-0.124185);
}

double NNIdClass::synapse0x1d8db9d0() {
   return (neuron0x3e012f0()*-0.0708041);
}

double NNIdClass::synapse0x1d8c98f0() {
   return (neuron0x3e01630()*0.1852);
}

double NNIdClass::synapse0x1d8c9930() {
   return (neuron0x3e01970()*0.803352);
}

double NNIdClass::synapse0x1d8c9970() {
   return (neuron0x1de98b20()*0.020681);
}

double NNIdClass::synapse0x1d8dc070() {
   return (neuron0x1de98e60()*-0.0568862);
}

double NNIdClass::synapse0x1de988e0() {
   return (neuron0x1de991e0()*-0.363111);
}

double NNIdClass::synapse0x1de98920() {
   return (neuron0x1d8d6690()*-0.042909);
}

double NNIdClass::synapse0x1de98960() {
   return (neuron0x1d8d69d0()*0.06308);
}

double NNIdClass::synapse0x1de989a0() {
   return (neuron0x1d8d6d10()*0.0459201);
}

double NNIdClass::synapse0x1de989e0() {
   return (neuron0x1d8d7050()*-0.275291);
}

double NNIdClass::synapse0x1de98a20() {
   return (neuron0x1d8d7390()*0.0764232);
}

double NNIdClass::synapse0x1de98a60() {
   return (neuron0x1d8d76d0()*-0.0383446);
}

double NNIdClass::synapse0x1de98aa0() {
   return (neuron0x1d8d7a10()*0.0805335);
}

double NNIdClass::synapse0x1de98ae0() {
   return (neuron0x1d8d7d50()*-0.311082);
}

double NNIdClass::synapse0x1d8dbb70() {
   return (neuron0x1d8d8090()*-0.177849);
}

double NNIdClass::synapse0x1d8dbbb0() {
   return (neuron0x1d8d83d0()*-0.33077);
}

double NNIdClass::synapse0x1d8dbfe0() {
   return (neuron0x1d8d44a0()*-0.301857);
}

double NNIdClass::synapse0x1d8dc020() {
   return (neuron0x1d8d4a00()*-0.105936);
}

double NNIdClass::synapse0x1d8dbd00() {
   return (neuron0x1d8d4d40()*0.545592);
}

double NNIdClass::synapse0x1d8dbd40() {
   return (neuron0x1d8d5080()*0.144499);
}

double NNIdClass::synapse0x1d8dbd80() {
   return (neuron0x1d8d53f0()*0.0603054);
}

double NNIdClass::synapse0x1d8dbdc0() {
   return (neuron0x1d8d5760()*-0.259435);
}

double NNIdClass::synapse0x1d8dbe00() {
   return (neuron0x1d8d5aa0()*0.106163);
}

double NNIdClass::synapse0x1d8dbe40() {
   return (neuron0x1d8d5de0()*0.393529);
}

double NNIdClass::synapse0x1d8dbe80() {
   return (neuron0x1d8d6120()*-0.313637);
}

double NNIdClass::synapse0x1d8dbec0() {
   return (neuron0x1d90f490()*0.109099);
}

double NNIdClass::synapse0x1d8ca800() {
   return (neuron0x1d90f770()*-0.341698);
}

double NNIdClass::synapse0x1d8ca840() {
   return (neuron0x1d90fab0()*0.12267);
}

double NNIdClass::synapse0x1d8ca880() {
   return (neuron0x1d90fdf0()*0.259805);
}

double NNIdClass::synapse0x1d8ca8c0() {
   return (neuron0x1d910130()*-0.124238);
}

double NNIdClass::synapse0x1d8ca900() {
   return (neuron0x1d910470()*0.379757);
}

double NNIdClass::synapse0x1d8ca940() {
   return (neuron0x1d9107b0()*0.272389);
}

double NNIdClass::synapse0x1d8dbbf0() {
   return (neuron0x1d910af0()*-0.280914);
}

double NNIdClass::synapse0x1d8dbc30() {
   return (neuron0x1d8d47e0()*-0.392399);
}

double NNIdClass::synapse0x1d8dbc70() {
   return (neuron0x1d911370()*0.292942);
}

double NNIdClass::synapse0x1d8dbcb0() {
   return (neuron0x1d8e9af0()*0.295621);
}

double NNIdClass::synapse0x1d8ca3f0() {
   return (neuron0x1d8e9e30()*-0.191942);
}

double NNIdClass::synapse0x1d8ca430() {
   return (neuron0x1d8ea170()*-0.137364);
}

double NNIdClass::synapse0x1d8ca470() {
   return (neuron0x1d8ea4b0()*0.213174);
}

double NNIdClass::synapse0x1d8ca4b0() {
   return (neuron0x1d8ea7f0()*0.0466054);
}

double NNIdClass::synapse0x1d8ca4f0() {
   return (neuron0x1d8eab30()*-0.0314093);
}

double NNIdClass::synapse0x1d8ca530() {
   return (neuron0x1d8eae70()*-0.0177715);
}

double NNIdClass::synapse0x1d8ca570() {
   return (neuron0x1d8eb1e0()*-0.323142);
}

double NNIdClass::synapse0x1d8ca5b0() {
   return (neuron0x1d8eb550()*-0.0772017);
}

double NNIdClass::synapse0x1d8ca5f0() {
   return (neuron0x1d8eb8c0()*-0.692288);
}

double NNIdClass::synapse0x1d8ca630() {
   return (neuron0x1d8ebc30()*-0.0689485);
}

double NNIdClass::synapse0x1d8ca670() {
   return (neuron0x1d8c89b0()*0.129728);
}

double NNIdClass::synapse0x1d8cb6e0() {
   return (neuron0x3e012f0()*0.315944);
}

double NNIdClass::synapse0x1d8cb720() {
   return (neuron0x3e01630()*0.321069);
}

double NNIdClass::synapse0x1d8cb760() {
   return (neuron0x3e01970()*0.813223);
}

double NNIdClass::synapse0x1d8cb7a0() {
   return (neuron0x1de98b20()*0.211273);
}

double NNIdClass::synapse0x1d8cb7e0() {
   return (neuron0x1de98e60()*-0.221908);
}

double NNIdClass::synapse0x1d8cb820() {
   return (neuron0x1de991e0()*-0.283992);
}

double NNIdClass::synapse0x1d8cb860() {
   return (neuron0x1d8d6690()*0.0624445);
}

double NNIdClass::synapse0x1d8cb8a0() {
   return (neuron0x1d8d69d0()*-0.338743);
}

double NNIdClass::synapse0x1d8cb8e0() {
   return (neuron0x1d8d6d10()*-0.0853841);
}

double NNIdClass::synapse0x1d8cb920() {
   return (neuron0x1d8d7050()*0.171155);
}

double NNIdClass::synapse0x1d8cb960() {
   return (neuron0x1d8d7390()*-0.0506725);
}

double NNIdClass::synapse0x1d8cb9a0() {
   return (neuron0x1d8d76d0()*-0.254147);
}

double NNIdClass::synapse0x1d8cb9e0() {
   return (neuron0x1d8d7a10()*0.0728794);
}

double NNIdClass::synapse0x1d8cba20() {
   return (neuron0x1d8d7d50()*-0.373226);
}

double NNIdClass::synapse0x1d8cba60() {
   return (neuron0x1d8d8090()*0.347604);
}

double NNIdClass::synapse0x1d8cbaa0() {
   return (neuron0x1d8d83d0()*0.228489);
}

double NNIdClass::synapse0x1d8cb530() {
   return (neuron0x1d8d44a0()*0.704644);
}

double NNIdClass::synapse0x1d8cb570() {
   return (neuron0x1d8d4a00()*-0.0173099);
}

double NNIdClass::synapse0x1d8ca6b0() {
   return (neuron0x1d8d4d40()*-0.0429157);
}

double NNIdClass::synapse0x1d8ca6f0() {
   return (neuron0x1d8d5080()*0.189189);
}

double NNIdClass::synapse0x1d8ca730() {
   return (neuron0x1d8d53f0()*0.0352903);
}

double NNIdClass::synapse0x1d8ca770() {
   return (neuron0x1d8d5760()*0.154573);
}

double NNIdClass::synapse0x1d8ca7b0() {
   return (neuron0x1d8d5aa0()*0.179252);
}

double NNIdClass::synapse0x1d8cbbf0() {
   return (neuron0x1d8d5de0()*-0.0693738);
}

double NNIdClass::synapse0x1d8cbc30() {
   return (neuron0x1d8d6120()*-0.375177);
}

double NNIdClass::synapse0x1d8cbc70() {
   return (neuron0x1d90f490()*-0.429201);
}

double NNIdClass::synapse0x1d8cbcb0() {
   return (neuron0x1d90f770()*0.283949);
}

double NNIdClass::synapse0x1d8cbcf0() {
   return (neuron0x1d90fab0()*0.286626);
}

double NNIdClass::synapse0x1d8cbd30() {
   return (neuron0x1d90fdf0()*-0.230104);
}

double NNIdClass::synapse0x1d8cbd70() {
   return (neuron0x1d910130()*-0.265937);
}

double NNIdClass::synapse0x1d8cbdb0() {
   return (neuron0x1d910470()*0.0693154);
}

double NNIdClass::synapse0x1d8cbdf0() {
   return (neuron0x1d9107b0()*0.122321);
}

double NNIdClass::synapse0x1d8cbae0() {
   return (neuron0x1d910af0()*-0.358084);
}

double NNIdClass::synapse0x1d8cbb20() {
   return (neuron0x1d8d47e0()*-0.451761);
}

double NNIdClass::synapse0x1d8cbb60() {
   return (neuron0x1d911370()*0.253773);
}

double NNIdClass::synapse0x1d8cbba0() {
   return (neuron0x1d8e9af0()*-0.368775);
}

double NNIdClass::synapse0x1d8cc040() {
   return (neuron0x1d8e9e30()*0.448623);
}

double NNIdClass::synapse0x1d8cc080() {
   return (neuron0x1d8ea170()*-0.159292);
}

double NNIdClass::synapse0x1d8cc0c0() {
   return (neuron0x1d8ea4b0()*0.750032);
}

double NNIdClass::synapse0x1d8cc100() {
   return (neuron0x1d8ea7f0()*0.219099);
}

double NNIdClass::synapse0x1d8cc140() {
   return (neuron0x1d8eab30()*0.0609707);
}

double NNIdClass::synapse0x1d8cc180() {
   return (neuron0x1d8eae70()*0.222693);
}

double NNIdClass::synapse0x1d8cc1c0() {
   return (neuron0x1d8eb1e0()*0.253898);
}

double NNIdClass::synapse0x1d8cc200() {
   return (neuron0x1d8eb550()*0.0540353);
}

double NNIdClass::synapse0x1d8cc240() {
   return (neuron0x1d8eb8c0()*0.563696);
}

double NNIdClass::synapse0x1d8cc280() {
   return (neuron0x1d8ebc30()*-0.0299709);
}

double NNIdClass::synapse0x1d8cc2c0() {
   return (neuron0x1d8c89b0()*0.385303);
}

double NNIdClass::synapse0x1d8cded0() {
   return (neuron0x3e012f0()*0.424548);
}

double NNIdClass::synapse0x1d8cdf10() {
   return (neuron0x3e01630()*-0.0496468);
}

double NNIdClass::synapse0x1d8cdf50() {
   return (neuron0x3e01970()*-1.06141);
}

double NNIdClass::synapse0x1d8cdf90() {
   return (neuron0x1de98b20()*0.0289947);
}

double NNIdClass::synapse0x1d8cdfd0() {
   return (neuron0x1de98e60()*0.249254);
}

double NNIdClass::synapse0x1d8ce010() {
   return (neuron0x1de991e0()*-0.0657331);
}

double NNIdClass::synapse0x1d8ce050() {
   return (neuron0x1d8d6690()*-0.0753663);
}

double NNIdClass::synapse0x1d8ce090() {
   return (neuron0x1d8d69d0()*0.0350471);
}

double NNIdClass::synapse0x1d8ce0d0() {
   return (neuron0x1d8d6d10()*0.204671);
}

double NNIdClass::synapse0x1d8ce110() {
   return (neuron0x1d8d7050()*0.0918975);
}

double NNIdClass::synapse0x1d8ce150() {
   return (neuron0x1d8d7390()*-0.0686901);
}

double NNIdClass::synapse0x1d8ce190() {
   return (neuron0x1d8d76d0()*-0.135464);
}

double NNIdClass::synapse0x1d8ce1d0() {
   return (neuron0x1d8d7a10()*-0.064801);
}

double NNIdClass::synapse0x1d8ce210() {
   return (neuron0x1d8d7d50()*0.407328);
}

double NNIdClass::synapse0x1d8ce250() {
   return (neuron0x1d8d8090()*0.125565);
}

double NNIdClass::synapse0x1d8ce290() {
   return (neuron0x1d8d83d0()*0.667442);
}

double NNIdClass::synapse0x1d8cdd20() {
   return (neuron0x1d8d44a0()*0.309993);
}

double NNIdClass::synapse0x1d8cdd60() {
   return (neuron0x1d8d4a00()*0.0125039);
}

double NNIdClass::synapse0x1d8cc300() {
   return (neuron0x1d8d4d40()*-0.104877);
}

double NNIdClass::synapse0x1d8cc340() {
   return (neuron0x1d8d5080()*-0.00522995);
}

double NNIdClass::synapse0x1d8cc380() {
   return (neuron0x1d8d53f0()*0.00950174);
}

double NNIdClass::synapse0x1d8cc3c0() {
   return (neuron0x1d8d5760()*0.88005);
}

double NNIdClass::synapse0x1d8ce3e0() {
   return (neuron0x1d8d5aa0()*-2.51523);
}

double NNIdClass::synapse0x1d8ce420() {
   return (neuron0x1d8d5de0()*-0.17144);
}

double NNIdClass::synapse0x1d8ce460() {
   return (neuron0x1d8d6120()*0.00312298);
}

double NNIdClass::synapse0x1d8ce4a0() {
   return (neuron0x1d90f490()*0.506571);
}

double NNIdClass::synapse0x1d8ce4e0() {
   return (neuron0x1d90f770()*0.299336);
}

double NNIdClass::synapse0x1d8ce520() {
   return (neuron0x1d90fab0()*-0.0552365);
}

double NNIdClass::synapse0x1d8ce560() {
   return (neuron0x1d90fdf0()*0.0522716);
}

double NNIdClass::synapse0x1d8ce5a0() {
   return (neuron0x1d910130()*-0.0247126);
}

double NNIdClass::synapse0x1d8ce5e0() {
   return (neuron0x1d910470()*-0.0114026);
}

double NNIdClass::synapse0x1d8ce620() {
   return (neuron0x1d9107b0()*-0.0915052);
}

double NNIdClass::synapse0x1d8ce2d0() {
   return (neuron0x1d910af0()*-0.153806);
}

double NNIdClass::synapse0x1d8ce310() {
   return (neuron0x1d8d47e0()*0.340443);
}

double NNIdClass::synapse0x1d8ce350() {
   return (neuron0x1d911370()*0.0776106);
}

double NNIdClass::synapse0x1d8ce390() {
   return (neuron0x1d8e9af0()*-0.0607725);
}

double NNIdClass::synapse0x1d8ce870() {
   return (neuron0x1d8e9e30()*-0.295377);
}

double NNIdClass::synapse0x1d8ce8b0() {
   return (neuron0x1d8ea170()*-0.0803492);
}

double NNIdClass::synapse0x1d8ce8f0() {
   return (neuron0x1d8ea4b0()*0.165015);
}

double NNIdClass::synapse0x1d8ce930() {
   return (neuron0x1d8ea7f0()*0.131901);
}

double NNIdClass::synapse0x1d8ce970() {
   return (neuron0x1d8eab30()*0.0286677);
}

double NNIdClass::synapse0x1d8ce9b0() {
   return (neuron0x1d8eae70()*-0.263806);
}

double NNIdClass::synapse0x1d8ce9f0() {
   return (neuron0x1d8eb1e0()*-0.122152);
}

double NNIdClass::synapse0x1d8cea30() {
   return (neuron0x1d8eb550()*-0.0257302);
}

double NNIdClass::synapse0x1d8cea70() {
   return (neuron0x1d8eb8c0()*0.590777);
}

double NNIdClass::synapse0x1d8ceab0() {
   return (neuron0x1d8ebc30()*0.000808805);
}

double NNIdClass::synapse0x1d8ceaf0() {
   return (neuron0x1d8c89b0()*0.464948);
}

double NNIdClass::synapse0x1d8cee70() {
   return (neuron0x3e012f0()*-0.635593);
}

double NNIdClass::synapse0x1d8ceeb0() {
   return (neuron0x3e01630()*0.217005);
}

double NNIdClass::synapse0x1d8ceef0() {
   return (neuron0x3e01970()*0.177803);
}

double NNIdClass::synapse0x1d8cef30() {
   return (neuron0x1de98b20()*-0.25498);
}

double NNIdClass::synapse0x1d8cef70() {
   return (neuron0x1de98e60()*0.132786);
}

double NNIdClass::synapse0x1d8cefb0() {
   return (neuron0x1de991e0()*-0.283149);
}

double NNIdClass::synapse0x1d8ceff0() {
   return (neuron0x1d8d6690()*0.357419);
}

double NNIdClass::synapse0x1d8cf030() {
   return (neuron0x1d8d69d0()*0.300175);
}

double NNIdClass::synapse0x1d8cf070() {
   return (neuron0x1d8d6d10()*0.0868119);
}

double NNIdClass::synapse0x1d8cf0b0() {
   return (neuron0x1d8d7050()*0.110973);
}

double NNIdClass::synapse0x1d8cf0f0() {
   return (neuron0x1d8d7390()*0.00760133);
}

double NNIdClass::synapse0x1d8cf130() {
   return (neuron0x1d8d76d0()*-0.166797);
}

double NNIdClass::synapse0x1d8cf170() {
   return (neuron0x1d8d7a10()*0.332912);
}

double NNIdClass::synapse0x1d8cf1b0() {
   return (neuron0x1d8d7d50()*0.240174);
}

double NNIdClass::synapse0x1d8cf1f0() {
   return (neuron0x1d8d8090()*0.118216);
}

double NNIdClass::synapse0x1d8cf230() {
   return (neuron0x1d8d83d0()*0.448716);
}

double NNIdClass::synapse0x1d8cecc0() {
   return (neuron0x1d8d44a0()*-0.291285);
}

double NNIdClass::synapse0x1d8ced00() {
   return (neuron0x1d8d4a00()*0.0572495);
}

double NNIdClass::synapse0x1d8cf380() {
   return (neuron0x1d8d4d40()*-0.434227);
}

double NNIdClass::synapse0x1d8cf3c0() {
   return (neuron0x1d8d5080()*-0.136621);
}

double NNIdClass::synapse0x1d8cf400() {
   return (neuron0x1d8d53f0()*-0.196471);
}

double NNIdClass::synapse0x1d8cf440() {
   return (neuron0x1d8d5760()*-0.240701);
}

double NNIdClass::synapse0x1d8cab90() {
   return (neuron0x1d8d5aa0()*-0.131137);
}

double NNIdClass::synapse0x1d8cabd0() {
   return (neuron0x1d8d5de0()*0.290014);
}

double NNIdClass::synapse0x1d8cac10() {
   return (neuron0x1d8d6120()*-0.182038);
}

double NNIdClass::synapse0x1d8cac50() {
   return (neuron0x1d90f490()*-0.380566);
}

double NNIdClass::synapse0x1d8cac90() {
   return (neuron0x1d90f770()*-0.0864545);
}

double NNIdClass::synapse0x1d8cacd0() {
   return (neuron0x1d90fab0()*0.276491);
}

double NNIdClass::synapse0x1d8cad10() {
   return (neuron0x1d90fdf0()*0.148821);
}

double NNIdClass::synapse0x1d8cad50() {
   return (neuron0x1d910130()*-0.231917);
}

double NNIdClass::synapse0x1d8cad90() {
   return (neuron0x1d910470()*-0.264351);
}

double NNIdClass::synapse0x1d8cadd0() {
   return (neuron0x1d9107b0()*0.0899863);
}

double NNIdClass::synapse0x1d8cf270() {
   return (neuron0x1d910af0()*0.0848858);
}

double NNIdClass::synapse0x1d8cf2b0() {
   return (neuron0x1d8d47e0()*0.43286);
}

double NNIdClass::synapse0x1d8cf2f0() {
   return (neuron0x1d911370()*0.349145);
}

double NNIdClass::synapse0x1d8cf330() {
   return (neuron0x1d8e9af0()*-0.198946);
}

double NNIdClass::synapse0x1d8cb020() {
   return (neuron0x1d8e9e30()*-0.224642);
}

double NNIdClass::synapse0x1d8cb060() {
   return (neuron0x1d8ea170()*-0.307117);
}

double NNIdClass::synapse0x1d8cb0a0() {
   return (neuron0x1d8ea4b0()*-0.429088);
}

double NNIdClass::synapse0x1d8cb0e0() {
   return (neuron0x1d8ea7f0()*-0.409261);
}

double NNIdClass::synapse0x1d8cb120() {
   return (neuron0x1d8eab30()*-0.0580219);
}

double NNIdClass::synapse0x1d8cb160() {
   return (neuron0x1d8eae70()*0.289608);
}

double NNIdClass::synapse0x1d8cb1a0() {
   return (neuron0x1d8eb1e0()*-0.19976);
}

double NNIdClass::synapse0x1d8cb1e0() {
   return (neuron0x1d8eb550()*-0.0792164);
}

double NNIdClass::synapse0x1d8cb220() {
   return (neuron0x1d8eb8c0()*0.146948);
}

double NNIdClass::synapse0x1d8cb260() {
   return (neuron0x1d8ebc30()*0.289624);
}

double NNIdClass::synapse0x1d8cb2a0() {
   return (neuron0x1d8c89b0()*0.0923755);
}

double NNIdClass::synapse0x1d8d07d0() {
   return (neuron0x3e012f0()*-0.38959);
}

double NNIdClass::synapse0x1d8d0810() {
   return (neuron0x3e01630()*0.643874);
}

double NNIdClass::synapse0x1d8d0850() {
   return (neuron0x3e01970()*-0.75007);
}

double NNIdClass::synapse0x1d8d0890() {
   return (neuron0x1de98b20()*-0.372028);
}

double NNIdClass::synapse0x1d8d08d0() {
   return (neuron0x1de98e60()*-0.088391);
}

double NNIdClass::synapse0x1d8d0910() {
   return (neuron0x1de991e0()*0.0114289);
}

double NNIdClass::synapse0x1d8d0950() {
   return (neuron0x1d8d6690()*0.122794);
}

double NNIdClass::synapse0x1d8d0990() {
   return (neuron0x1d8d69d0()*-0.12759);
}

double NNIdClass::synapse0x1d8d09d0() {
   return (neuron0x1d8d6d10()*-0.462221);
}

double NNIdClass::synapse0x1d8d0a10() {
   return (neuron0x1d8d7050()*0.028939);
}

double NNIdClass::synapse0x1d8d0a50() {
   return (neuron0x1d8d7390()*-0.107015);
}

double NNIdClass::synapse0x1d8d0a90() {
   return (neuron0x1d8d76d0()*-0.15294);
}

double NNIdClass::synapse0x1d8d0ad0() {
   return (neuron0x1d8d7a10()*-0.0435172);
}

double NNIdClass::synapse0x1d8d0b10() {
   return (neuron0x1d8d7d50()*-0.259512);
}

double NNIdClass::synapse0x1d8d0b50() {
   return (neuron0x1d8d8090()*-0.16503);
}

double NNIdClass::synapse0x1d8d0b90() {
   return (neuron0x1d8d83d0()*0.0852824);
}

double NNIdClass::synapse0x1d8d0620() {
   return (neuron0x1d8d44a0()*-0.0819725);
}

double NNIdClass::synapse0x1d8d0660() {
   return (neuron0x1d8d4a00()*-0.0855384);
}

double NNIdClass::synapse0x1d8cb2e0() {
   return (neuron0x1d8d4d40()*-0.0323671);
}

double NNIdClass::synapse0x1d8cb320() {
   return (neuron0x1d8d5080()*-0.171168);
}

double NNIdClass::synapse0x1d8cb360() {
   return (neuron0x1d8d53f0()*0.0432684);
}

double NNIdClass::synapse0x1d8d0ce0() {
   return (neuron0x1d8d5760()*0.379875);
}

double NNIdClass::synapse0x1d8d0d20() {
   return (neuron0x1d8d5aa0()*-0.568013);
}

double NNIdClass::synapse0x1d8d0d60() {
   return (neuron0x1d8d5de0()*-0.134338);
}

double NNIdClass::synapse0x1d8d0da0() {
   return (neuron0x1d8d6120()*-0.0174829);
}

double NNIdClass::synapse0x1d8d0de0() {
   return (neuron0x1d90f490()*0.198303);
}

double NNIdClass::synapse0x1d8d0e20() {
   return (neuron0x1d90f770()*0.122756);
}

double NNIdClass::synapse0x1d8d0e60() {
   return (neuron0x1d90fab0()*-0.0371499);
}

double NNIdClass::synapse0x1d8d0ea0() {
   return (neuron0x1d90fdf0()*0.102345);
}

double NNIdClass::synapse0x1d8d0ee0() {
   return (neuron0x1d910130()*-0.128327);
}

double NNIdClass::synapse0x1d8d0f20() {
   return (neuron0x1d910470()*0.0999428);
}

double NNIdClass::synapse0x1d8d0f60() {
   return (neuron0x1d9107b0()*-0.350951);
}

double NNIdClass::synapse0x1d8d0bd0() {
   return (neuron0x1d910af0()*0.244867);
}

double NNIdClass::synapse0x1d8d0c10() {
   return (neuron0x1d8d47e0()*-0.364656);
}

double NNIdClass::synapse0x1d8d0c50() {
   return (neuron0x1d911370()*0.0105578);
}

double NNIdClass::synapse0x1d8d0c90() {
   return (neuron0x1d8e9af0()*0.159634);
}

double NNIdClass::synapse0x1d8d11b0() {
   return (neuron0x1d8e9e30()*-0.0418256);
}

double NNIdClass::synapse0x1d8d11f0() {
   return (neuron0x1d8ea170()*0.54205);
}

double NNIdClass::synapse0x1d8d1230() {
   return (neuron0x1d8ea4b0()*0.255774);
}

double NNIdClass::synapse0x1d8d1270() {
   return (neuron0x1d8ea7f0()*0.27081);
}

double NNIdClass::synapse0x1d8d12b0() {
   return (neuron0x1d8eab30()*-0.0914105);
}

double NNIdClass::synapse0x1d8d12f0() {
   return (neuron0x1d8eae70()*0.0695721);
}

double NNIdClass::synapse0x1d8d1330() {
   return (neuron0x1d8eb1e0()*0.0207646);
}

double NNIdClass::synapse0x1d8d1370() {
   return (neuron0x1d8eb550()*0.153635);
}

double NNIdClass::synapse0x1d8d13b0() {
   return (neuron0x1d8eb8c0()*-0.405476);
}

double NNIdClass::synapse0x1d8d13f0() {
   return (neuron0x1d8ebc30()*0.0462994);
}

double NNIdClass::synapse0x1d8d1430() {
   return (neuron0x1d8c89b0()*0.0189111);
}

double NNIdClass::synapse0x1d8d17b0() {
   return (neuron0x3e012f0()*-0.932688);
}

double NNIdClass::synapse0x1d8d17f0() {
   return (neuron0x3e01630()*-0.117873);
}

double NNIdClass::synapse0x1d8d1830() {
   return (neuron0x3e01970()*0.769409);
}

double NNIdClass::synapse0x1d8d1870() {
   return (neuron0x1de98b20()*-0.00838207);
}

double NNIdClass::synapse0x1d8d18b0() {
   return (neuron0x1de98e60()*0.17311);
}

double NNIdClass::synapse0x1d8d18f0() {
   return (neuron0x1de991e0()*0.199763);
}

double NNIdClass::synapse0x1d8d1930() {
   return (neuron0x1d8d6690()*-0.133542);
}

double NNIdClass::synapse0x1d8d1970() {
   return (neuron0x1d8d69d0()*-0.206834);
}

double NNIdClass::synapse0x1d8d19b0() {
   return (neuron0x1d8d6d10()*-0.205204);
}

double NNIdClass::synapse0x1d94c6a0() {
   return (neuron0x1d8d7050()*-0.537305);
}

double NNIdClass::synapse0x1d94c6e0() {
   return (neuron0x1d8d7390()*0.126474);
}

double NNIdClass::synapse0x1d94c720() {
   return (neuron0x1d8d76d0()*0.0191042);
}

double NNIdClass::synapse0x1d94c760() {
   return (neuron0x1d8d7a10()*-0.338745);
}

double NNIdClass::synapse0x1d94c7a0() {
   return (neuron0x1d8d7d50()*0.350538);
}

double NNIdClass::synapse0x1d94c7e0() {
   return (neuron0x1d8d8090()*-0.00960031);
}

double NNIdClass::synapse0x1d94c820() {
   return (neuron0x1d8d83d0()*-0.448571);
}

double NNIdClass::synapse0x1d8d1600() {
   return (neuron0x1d8d44a0()*-0.0468798);
}

double NNIdClass::synapse0x1d8d1640() {
   return (neuron0x1d8d4a00()*-0.0684318);
}

double NNIdClass::synapse0x1d94c970() {
   return (neuron0x1d8d4d40()*0.196716);
}

double NNIdClass::synapse0x1d94c9b0() {
   return (neuron0x1d8d5080()*0.0518925);
}

double NNIdClass::synapse0x1d94c9f0() {
   return (neuron0x1d8d53f0()*-0.124792);
}

double NNIdClass::synapse0x1d94ca30() {
   return (neuron0x1d8d5760()*1.48362);
}

double NNIdClass::synapse0x1d94ca70() {
   return (neuron0x1d8d5aa0()*-0.791544);
}

double NNIdClass::synapse0x1d94cab0() {
   return (neuron0x1d8d5de0()*-0.550497);
}

double NNIdClass::synapse0x1d94caf0() {
   return (neuron0x1d8d6120()*-0.0472965);
}

double NNIdClass::synapse0x1d94cb30() {
   return (neuron0x1d90f490()*0.170749);
}

double NNIdClass::synapse0x1d94cb70() {
   return (neuron0x1d90f770()*-0.0822809);
}

double NNIdClass::synapse0x1d94cbb0() {
   return (neuron0x1d90fab0()*0.563011);
}

double NNIdClass::synapse0x1d94cbf0() {
   return (neuron0x1d90fdf0()*-0.512296);
}

double NNIdClass::synapse0x1d94cc30() {
   return (neuron0x1d910130()*0.0252793);
}

double NNIdClass::synapse0x1d94cc70() {
   return (neuron0x1d910470()*0.0876346);
}

double NNIdClass::synapse0x1d94ccb0() {
   return (neuron0x1d9107b0()*0.351807);
}

double NNIdClass::synapse0x1d94c860() {
   return (neuron0x1d910af0()*-0.303912);
}

double NNIdClass::synapse0x1d94c8a0() {
   return (neuron0x1d8d47e0()*-0.300379);
}

double NNIdClass::synapse0x1d94c8e0() {
   return (neuron0x1d911370()*0.101036);
}

double NNIdClass::synapse0x1d94c920() {
   return (neuron0x1d8e9af0()*-0.341941);
}

double NNIdClass::synapse0x1d94cf00() {
   return (neuron0x1d8e9e30()*-0.328963);
}

double NNIdClass::synapse0x1d94cf40() {
   return (neuron0x1d8ea170()*-0.397161);
}

double NNIdClass::synapse0x1d94cf80() {
   return (neuron0x1d8ea4b0()*0.193698);
}

double NNIdClass::synapse0x1d94cfc0() {
   return (neuron0x1d8ea7f0()*-0.265092);
}

double NNIdClass::synapse0x1d94d000() {
   return (neuron0x1d8eab30()*-0.316752);
}

double NNIdClass::synapse0x1d94d040() {
   return (neuron0x1d8eae70()*0.0832304);
}

double NNIdClass::synapse0x1d94d080() {
   return (neuron0x1d8eb1e0()*0.276964);
}

double NNIdClass::synapse0x1d94d0c0() {
   return (neuron0x1d8eb550()*0.222634);
}

double NNIdClass::synapse0x1d94d100() {
   return (neuron0x1d8eb8c0()*0.0708501);
}

double NNIdClass::synapse0x1d94d140() {
   return (neuron0x1d8ebc30()*0.468031);
}

double NNIdClass::synapse0x1d94d180() {
   return (neuron0x1d8c89b0()*0.297928);
}

double NNIdClass::synapse0x1d94d500() {
   return (neuron0x3e012f0()*-0.235233);
}

double NNIdClass::synapse0x1d94d540() {
   return (neuron0x3e01630()*-0.15911);
}

double NNIdClass::synapse0x1d94d580() {
   return (neuron0x3e01970()*1.72203);
}

double NNIdClass::synapse0x1d94d5c0() {
   return (neuron0x1de98b20()*0.0174809);
}

double NNIdClass::synapse0x1d94d600() {
   return (neuron0x1de98e60()*0.0871021);
}

double NNIdClass::synapse0x1d94d640() {
   return (neuron0x1de991e0()*0.14509);
}

double NNIdClass::synapse0x1d94d680() {
   return (neuron0x1d8d6690()*-0.0618279);
}

double NNIdClass::synapse0x1d94d6c0() {
   return (neuron0x1d8d69d0()*0.113673);
}

double NNIdClass::synapse0x1d94d700() {
   return (neuron0x1d8d6d10()*0.05136);
}

double NNIdClass::synapse0x1d94d740() {
   return (neuron0x1d8d7050()*-0.0802622);
}

double NNIdClass::synapse0x1d94d780() {
   return (neuron0x1d8d7390()*0.110122);
}

double NNIdClass::synapse0x1d94d7c0() {
   return (neuron0x1d8d76d0()*0.019538);
}

double NNIdClass::synapse0x1d94d800() {
   return (neuron0x1d8d7a10()*-0.255359);
}

double NNIdClass::synapse0x1d94d840() {
   return (neuron0x1d8d7d50()*0.326178);
}

double NNIdClass::synapse0x1d94d880() {
   return (neuron0x1d8d8090()*1.03116);
}

double NNIdClass::synapse0x1d94d8c0() {
   return (neuron0x1d8d83d0()*-0.261921);
}

double NNIdClass::synapse0x1d94d350() {
   return (neuron0x1d8d44a0()*0.0107242);
}

double NNIdClass::synapse0x1d94d390() {
   return (neuron0x1d8d4a00()*-0.017186);
}

double NNIdClass::synapse0x1d94da10() {
   return (neuron0x1d8d4d40()*0.423605);
}

double NNIdClass::synapse0x1d94da50() {
   return (neuron0x1d8d5080()*-0.0414804);
}

double NNIdClass::synapse0x1d94da90() {
   return (neuron0x1d8d53f0()*-0.108242);
}

double NNIdClass::synapse0x1d94dad0() {
   return (neuron0x1d8d5760()*-0.1543);
}

double NNIdClass::synapse0x1d94db10() {
   return (neuron0x1d8d5aa0()*0.0427443);
}

double NNIdClass::synapse0x1d94db50() {
   return (neuron0x1d8d5de0()*-0.31459);
}

double NNIdClass::synapse0x1d94db90() {
   return (neuron0x1d8d6120()*-0.0626371);
}

double NNIdClass::synapse0x1d94dbd0() {
   return (neuron0x1d90f490()*-0.0419782);
}

double NNIdClass::synapse0x1d94dc10() {
   return (neuron0x1d90f770()*-0.260594);
}

double NNIdClass::synapse0x1d94dc50() {
   return (neuron0x1d90fab0()*-0.0483685);
}

double NNIdClass::synapse0x1d94dc90() {
   return (neuron0x1d90fdf0()*-0.152579);
}

double NNIdClass::synapse0x1d94dcd0() {
   return (neuron0x1d910130()*-0.176099);
}

double NNIdClass::synapse0x1d94dd10() {
   return (neuron0x1d910470()*0.15157);
}

double NNIdClass::synapse0x1d94dd50() {
   return (neuron0x1d9107b0()*-0.471087);
}

double NNIdClass::synapse0x1d94d900() {
   return (neuron0x1d910af0()*-0.0790719);
}

double NNIdClass::synapse0x1d94d940() {
   return (neuron0x1d8d47e0()*-0.201396);
}

double NNIdClass::synapse0x1d94d980() {
   return (neuron0x1d911370()*0.0139257);
}

double NNIdClass::synapse0x1d94d9c0() {
   return (neuron0x1d8e9af0()*1.60688e-05);
}

double NNIdClass::synapse0x1d94dfa0() {
   return (neuron0x1d8e9e30()*-0.0321125);
}

double NNIdClass::synapse0x1d94dfe0() {
   return (neuron0x1d8ea170()*0.100612);
}

double NNIdClass::synapse0x1d94e020() {
   return (neuron0x1d8ea4b0()*0.115007);
}

double NNIdClass::synapse0x1d94e060() {
   return (neuron0x1d8ea7f0()*-0.120676);
}

double NNIdClass::synapse0x1d94e0a0() {
   return (neuron0x1d8eab30()*0.349755);
}

double NNIdClass::synapse0x1d94e0e0() {
   return (neuron0x1d8eae70()*-0.0258672);
}

double NNIdClass::synapse0x1d94e120() {
   return (neuron0x1d8eb1e0()*-0.0426334);
}

double NNIdClass::synapse0x1d94e160() {
   return (neuron0x1d8eb550()*-0.0314957);
}

double NNIdClass::synapse0x1d94e1a0() {
   return (neuron0x1d8eb8c0()*0.559675);
}

double NNIdClass::synapse0x1d94e1e0() {
   return (neuron0x1d8ebc30()*0.0612666);
}

double NNIdClass::synapse0x1d94e220() {
   return (neuron0x1d8c89b0()*0.0459387);
}

double NNIdClass::synapse0x1d94e5a0() {
   return (neuron0x3e012f0()*0.40794);
}

double NNIdClass::synapse0x1d94e5e0() {
   return (neuron0x3e01630()*0.0152494);
}

double NNIdClass::synapse0x1d94e620() {
   return (neuron0x3e01970()*-1.69706);
}

double NNIdClass::synapse0x1d94e660() {
   return (neuron0x1de98b20()*0.0654091);
}

double NNIdClass::synapse0x1d94e6a0() {
   return (neuron0x1de98e60()*-0.0799032);
}

double NNIdClass::synapse0x1d94e6e0() {
   return (neuron0x1de991e0()*0.171362);
}

double NNIdClass::synapse0x1d94e720() {
   return (neuron0x1d8d6690()*-0.240508);
}

double NNIdClass::synapse0x1d94e760() {
   return (neuron0x1d8d69d0()*0.0483032);
}

double NNIdClass::synapse0x1d94e7a0() {
   return (neuron0x1d8d6d10()*-0.457854);
}

double NNIdClass::synapse0x1d94e7e0() {
   return (neuron0x1d8d7050()*0.130886);
}

double NNIdClass::synapse0x1d94e820() {
   return (neuron0x1d8d7390()*0.00191396);
}

double NNIdClass::synapse0x1d94e860() {
   return (neuron0x1d8d76d0()*-0.178805);
}

double NNIdClass::synapse0x1d94e8a0() {
   return (neuron0x1d8d7a10()*0.456147);
}

double NNIdClass::synapse0x1d94e8e0() {
   return (neuron0x1d8d7d50()*0.344057);
}

double NNIdClass::synapse0x1d94e920() {
   return (neuron0x1d8d8090()*-0.422859);
}

double NNIdClass::synapse0x1d94e960() {
   return (neuron0x1d8d83d0()*0.506393);
}

double NNIdClass::synapse0x1d94e3f0() {
   return (neuron0x1d8d44a0()*-0.109685);
}

double NNIdClass::synapse0x1d94e430() {
   return (neuron0x1d8d4a00()*-0.0317041);
}

double NNIdClass::synapse0x1d94eab0() {
   return (neuron0x1d8d4d40()*0.259211);
}

double NNIdClass::synapse0x1d94eaf0() {
   return (neuron0x1d8d5080()*-0.0536728);
}

double NNIdClass::synapse0x1d94eb30() {
   return (neuron0x1d8d53f0()*0.0726801);
}

double NNIdClass::synapse0x1d94eb70() {
   return (neuron0x1d8d5760()*-0.583283);
}

double NNIdClass::synapse0x1d94ebb0() {
   return (neuron0x1d8d5aa0()*0.246288);
}

double NNIdClass::synapse0x1d94ebf0() {
   return (neuron0x1d8d5de0()*-0.00754659);
}

double NNIdClass::synapse0x1d94ec30() {
   return (neuron0x1d8d6120()*0.140451);
}

double NNIdClass::synapse0x1d94ec70() {
   return (neuron0x1d90f490()*-0.236798);
}

double NNIdClass::synapse0x1d94ecb0() {
   return (neuron0x1d90f770()*0.582036);
}

double NNIdClass::synapse0x1d94ecf0() {
   return (neuron0x1d90fab0()*-0.202924);
}

double NNIdClass::synapse0x1d94ed30() {
   return (neuron0x1d90fdf0()*-0.242359);
}

double NNIdClass::synapse0x1d94ed70() {
   return (neuron0x1d910130()*-0.252213);
}

double NNIdClass::synapse0x1d94edb0() {
   return (neuron0x1d910470()*0.162936);
}

double NNIdClass::synapse0x1d94edf0() {
   return (neuron0x1d9107b0()*0.0839233);
}

double NNIdClass::synapse0x1d94e9a0() {
   return (neuron0x1d910af0()*-0.0674099);
}

double NNIdClass::synapse0x1d94e9e0() {
   return (neuron0x1d8d47e0()*-0.0030658);
}

double NNIdClass::synapse0x1d94ea20() {
   return (neuron0x1d911370()*-0.195453);
}

double NNIdClass::synapse0x1d94ea60() {
   return (neuron0x1d8e9af0()*0.196628);
}

double NNIdClass::synapse0x1d94f040() {
   return (neuron0x1d8e9e30()*-0.102727);
}

double NNIdClass::synapse0x1d94f080() {
   return (neuron0x1d8ea170()*-0.189372);
}

double NNIdClass::synapse0x1d94f0c0() {
   return (neuron0x1d8ea4b0()*-0.465554);
}

double NNIdClass::synapse0x1d94f100() {
   return (neuron0x1d8ea7f0()*-0.105413);
}

double NNIdClass::synapse0x1d94f140() {
   return (neuron0x1d8eab30()*0.149933);
}

double NNIdClass::synapse0x1d94f180() {
   return (neuron0x1d8eae70()*0.0155071);
}

double NNIdClass::synapse0x1d94f1c0() {
   return (neuron0x1d8eb1e0()*-0.125233);
}

double NNIdClass::synapse0x1d94f200() {
   return (neuron0x1d8eb550()*-0.046674);
}

double NNIdClass::synapse0x1d94f240() {
   return (neuron0x1d8eb8c0()*-0.694178);
}

double NNIdClass::synapse0x1d94f280() {
   return (neuron0x1d8ebc30()*0.25444);
}

double NNIdClass::synapse0x1d94f2c0() {
   return (neuron0x1d8c89b0()*0.0405309);
}

double NNIdClass::synapse0x1d94f640() {
   return (neuron0x3e012f0()*-0.587333);
}

double NNIdClass::synapse0x1d94f680() {
   return (neuron0x3e01630()*-0.0615647);
}

double NNIdClass::synapse0x1d94f6c0() {
   return (neuron0x3e01970()*0.451563);
}

double NNIdClass::synapse0x1d94f700() {
   return (neuron0x1de98b20()*0.035622);
}

double NNIdClass::synapse0x1d94f740() {
   return (neuron0x1de98e60()*0.179543);
}

double NNIdClass::synapse0x1d94f780() {
   return (neuron0x1de991e0()*-0.326283);
}

double NNIdClass::synapse0x1d94f7c0() {
   return (neuron0x1d8d6690()*0.0255374);
}

double NNIdClass::synapse0x1d94f800() {
   return (neuron0x1d8d69d0()*-0.157181);
}

double NNIdClass::synapse0x1d94f840() {
   return (neuron0x1d8d6d10()*0.16908);
}

double NNIdClass::synapse0x1d94f880() {
   return (neuron0x1d8d7050()*0.146217);
}

double NNIdClass::synapse0x1d94f8c0() {
   return (neuron0x1d8d7390()*0.0417223);
}

double NNIdClass::synapse0x1d94f900() {
   return (neuron0x1d8d76d0()*0.369822);
}

double NNIdClass::synapse0x1d94f940() {
   return (neuron0x1d8d7a10()*-4.50411e-05);
}

double NNIdClass::synapse0x1d94f980() {
   return (neuron0x1d8d7d50()*0.0448732);
}

double NNIdClass::synapse0x1d94f9c0() {
   return (neuron0x1d8d8090()*-0.083104);
}

double NNIdClass::synapse0x1d94fa00() {
   return (neuron0x1d8d83d0()*-0.608935);
}

double NNIdClass::synapse0x1d94f490() {
   return (neuron0x1d8d44a0()*-0.212168);
}

double NNIdClass::synapse0x1d94f4d0() {
   return (neuron0x1d8d4a00()*0.0819058);
}

double NNIdClass::synapse0x1d94fb50() {
   return (neuron0x1d8d4d40()*0.332639);
}

double NNIdClass::synapse0x1d94fb90() {
   return (neuron0x1d8d5080()*0.233909);
}

double NNIdClass::synapse0x1d94fbd0() {
   return (neuron0x1d8d53f0()*0.350845);
}

double NNIdClass::synapse0x1d94fc10() {
   return (neuron0x1d8d5760()*0.0749939);
}

double NNIdClass::synapse0x1d94fc50() {
   return (neuron0x1d8d5aa0()*0.165378);
}

double NNIdClass::synapse0x1d94fc90() {
   return (neuron0x1d8d5de0()*-1.27217);
}

double NNIdClass::synapse0x1d94fcd0() {
   return (neuron0x1d8d6120()*0.196773);
}

double NNIdClass::synapse0x1d94fd10() {
   return (neuron0x1d90f490()*-0.262142);
}

double NNIdClass::synapse0x1d94fd50() {
   return (neuron0x1d90f770()*0.24206);
}

double NNIdClass::synapse0x1d94fd90() {
   return (neuron0x1d90fab0()*-0.0177325);
}

double NNIdClass::synapse0x1d94fdd0() {
   return (neuron0x1d90fdf0()*0.164725);
}

double NNIdClass::synapse0x1d94fe10() {
   return (neuron0x1d910130()*0.303937);
}

double NNIdClass::synapse0x1d94fe50() {
   return (neuron0x1d910470()*0.254821);
}

double NNIdClass::synapse0x1d94fe90() {
   return (neuron0x1d9107b0()*-0.136131);
}

double NNIdClass::synapse0x1d94fa40() {
   return (neuron0x1d910af0()*-0.347871);
}

double NNIdClass::synapse0x1d94fa80() {
   return (neuron0x1d8d47e0()*-0.00528762);
}

double NNIdClass::synapse0x1d94fac0() {
   return (neuron0x1d911370()*0.219913);
}

double NNIdClass::synapse0x1d94fb00() {
   return (neuron0x1d8e9af0()*-0.320487);
}

double NNIdClass::synapse0x1d9500e0() {
   return (neuron0x1d8e9e30()*-0.274447);
}

double NNIdClass::synapse0x1d950120() {
   return (neuron0x1d8ea170()*0.0857707);
}

double NNIdClass::synapse0x1d950160() {
   return (neuron0x1d8ea4b0()*-0.276092);
}

double NNIdClass::synapse0x1d9501a0() {
   return (neuron0x1d8ea7f0()*-0.122425);
}

double NNIdClass::synapse0x1d9501e0() {
   return (neuron0x1d8eab30()*-0.460223);
}

double NNIdClass::synapse0x1d950220() {
   return (neuron0x1d8eae70()*-0.0784305);
}

double NNIdClass::synapse0x1d950260() {
   return (neuron0x1d8eb1e0()*-0.145787);
}

double NNIdClass::synapse0x1d9502a0() {
   return (neuron0x1d8eb550()*0.00968093);
}

double NNIdClass::synapse0x1d9502e0() {
   return (neuron0x1d8eb8c0()*0.409712);
}

double NNIdClass::synapse0x1d950320() {
   return (neuron0x1d8ebc30()*0.0341567);
}

double NNIdClass::synapse0x1d950360() {
   return (neuron0x1d8c89b0()*0.326406);
}

double NNIdClass::synapse0x1d8cf630() {
   return (neuron0x3e012f0()*0.166611);
}

double NNIdClass::synapse0x1d8cf670() {
   return (neuron0x3e01630()*-0.115684);
}

double NNIdClass::synapse0x1d8cf6b0() {
   return (neuron0x3e01970()*-1.63592);
}

double NNIdClass::synapse0x1d8cf6f0() {
   return (neuron0x1de98b20()*-0.00893355);
}

double NNIdClass::synapse0x1d8cf730() {
   return (neuron0x1de98e60()*0.0228162);
}

double NNIdClass::synapse0x1d8cf770() {
   return (neuron0x1de991e0()*-0.0496602);
}

double NNIdClass::synapse0x1d8cf7b0() {
   return (neuron0x1d8d6690()*-0.0766578);
}

double NNIdClass::synapse0x1d8cf7f0() {
   return (neuron0x1d8d69d0()*-0.0977218);
}

double NNIdClass::synapse0x1d8cf830() {
   return (neuron0x1d8d6d10()*-0.0433236);
}

double NNIdClass::synapse0x1d8cf870() {
   return (neuron0x1d8d7050()*-0.412258);
}

double NNIdClass::synapse0x1d8cf8b0() {
   return (neuron0x1d8d7390()*0.0887847);
}

double NNIdClass::synapse0x1d8cf8f0() {
   return (neuron0x1d8d76d0()*-0.52726);
}

double NNIdClass::synapse0x1d8cf930() {
   return (neuron0x1d8d7a10()*0.0215874);
}

double NNIdClass::synapse0x1d8cf970() {
   return (neuron0x1d8d7d50()*-0.355932);
}

double NNIdClass::synapse0x1d8cf9b0() {
   return (neuron0x1d8d8090()*0.78104);
}

double NNIdClass::synapse0x1d8cf9f0() {
   return (neuron0x1d8d83d0()*0.531144);
}

double NNIdClass::synapse0x1d8cf480() {
   return (neuron0x1d8d44a0()*0.159826);
}

double NNIdClass::synapse0x1d8cf4c0() {
   return (neuron0x1d8d4a00()*0.052942);
}

double NNIdClass::synapse0x1d8cfb40() {
   return (neuron0x1d8d4d40()*-0.102541);
}

double NNIdClass::synapse0x1d8cfb80() {
   return (neuron0x1d8d5080()*0.488231);
}

double NNIdClass::synapse0x1d8cfbc0() {
   return (neuron0x1d8d53f0()*0.167133);
}

double NNIdClass::synapse0x1d8cfc00() {
   return (neuron0x1d8d5760()*0.0210847);
}

double NNIdClass::synapse0x1d8cfc40() {
   return (neuron0x1d8d5aa0()*-0.0368714);
}

double NNIdClass::synapse0x1d8cfc80() {
   return (neuron0x1d8d5de0()*1.17381);
}

double NNIdClass::synapse0x1d8cfcc0() {
   return (neuron0x1d8d6120()*-0.125869);
}

double NNIdClass::synapse0x1d8cfd00() {
   return (neuron0x1d90f490()*-0.159086);
}

double NNIdClass::synapse0x1d8cfd40() {
   return (neuron0x1d90f770()*-0.226725);
}

double NNIdClass::synapse0x1d8cfd80() {
   return (neuron0x1d90fab0()*0.106738);
}

double NNIdClass::synapse0x1d8cfdc0() {
   return (neuron0x1d90fdf0()*-0.154061);
}

double NNIdClass::synapse0x1d8cfe00() {
   return (neuron0x1d910130()*0.190723);
}

double NNIdClass::synapse0x1d8cfe40() {
   return (neuron0x1d910470()*-0.354267);
}

double NNIdClass::synapse0x1d8cfe80() {
   return (neuron0x1d9107b0()*-0.156502);
}

double NNIdClass::synapse0x1d8cfa30() {
   return (neuron0x1d910af0()*0.454483);
}

double NNIdClass::synapse0x1d8cfa70() {
   return (neuron0x1d8d47e0()*0.522268);
}

double NNIdClass::synapse0x1d8cfab0() {
   return (neuron0x1d911370()*-0.055457);
}

double NNIdClass::synapse0x1d8cfaf0() {
   return (neuron0x1d8e9af0()*0.716421);
}

double NNIdClass::synapse0x1d8d00d0() {
   return (neuron0x1d8e9e30()*0.0867913);
}

double NNIdClass::synapse0x1d8d0110() {
   return (neuron0x1d8ea170()*0.0228629);
}

double NNIdClass::synapse0x1d8d0150() {
   return (neuron0x1d8ea4b0()*-0.0904225);
}

double NNIdClass::synapse0x1d8d0190() {
   return (neuron0x1d8ea7f0()*-0.0550426);
}

double NNIdClass::synapse0x1d8d01d0() {
   return (neuron0x1d8eab30()*0.220139);
}

double NNIdClass::synapse0x1d8d0210() {
   return (neuron0x1d8eae70()*0.206799);
}

double NNIdClass::synapse0x1d8d0250() {
   return (neuron0x1d8eb1e0()*0.0813783);
}

double NNIdClass::synapse0x1d8d0290() {
   return (neuron0x1d8eb550()*0.065103);
}

double NNIdClass::synapse0x1d8d02d0() {
   return (neuron0x1d8eb8c0()*0.338394);
}

double NNIdClass::synapse0x1d8d0310() {
   return (neuron0x1d8ebc30()*-0.430924);
}

double NNIdClass::synapse0x1d8d0350() {
   return (neuron0x1d8c89b0()*-0.115573);
}

double NNIdClass::synapse0x3d25930() {
   return (neuron0x3e012f0()*-0.0270987);
}

double NNIdClass::synapse0x3d25970() {
   return (neuron0x3e01630()*0.435197);
}

double NNIdClass::synapse0x3d259b0() {
   return (neuron0x3e01970()*-2.78659);
}

double NNIdClass::synapse0x3d259f0() {
   return (neuron0x1de98b20()*-0.0672901);
}

double NNIdClass::synapse0x3d25a30() {
   return (neuron0x1de98e60()*-0.0749376);
}

double NNIdClass::synapse0x3d25a70() {
   return (neuron0x1de991e0()*0.197463);
}

double NNIdClass::synapse0x3d25ab0() {
   return (neuron0x1d8d6690()*-0.146356);
}

double NNIdClass::synapse0x3d25af0() {
   return (neuron0x1d8d69d0()*0.0327623);
}

double NNIdClass::synapse0x3d25b30() {
   return (neuron0x1d8d6d10()*0.0593463);
}

double NNIdClass::synapse0x3d25b70() {
   return (neuron0x1d8d7050()*0.07202);
}

double NNIdClass::synapse0x3d25bb0() {
   return (neuron0x1d8d7390()*0.0173516);
}

double NNIdClass::synapse0x3d25bf0() {
   return (neuron0x1d8d76d0()*0.507268);
}

double NNIdClass::synapse0x3d25c30() {
   return (neuron0x1d8d7a10()*0.00839018);
}

double NNIdClass::synapse0x3d25c70() {
   return (neuron0x1d8d7d50()*0.0537063);
}

double NNIdClass::synapse0x3d25cb0() {
   return (neuron0x1d8d8090()*0.000746595);
}

double NNIdClass::synapse0x3d25cf0() {
   return (neuron0x1d8d83d0()*-0.253624);
}

double NNIdClass::synapse0x3d25780() {
   return (neuron0x1d8d44a0()*0.406979);
}

double NNIdClass::synapse0x3d257c0() {
   return (neuron0x1d8d4a00()*0.0373016);
}

double NNIdClass::synapse0x1d8d0390() {
   return (neuron0x1d8d4d40()*-0.0970827);
}

double NNIdClass::synapse0x1d8d03d0() {
   return (neuron0x1d8d5080()*0.0626373);
}

double NNIdClass::synapse0x1d8d0410() {
   return (neuron0x1d8d53f0()*-0.0972885);
}

double NNIdClass::synapse0x1d8d0450() {
   return (neuron0x1d8d5760()*-0.23842);
}

double NNIdClass::synapse0x3d25e40() {
   return (neuron0x1d8d5aa0()*0.361332);
}

double NNIdClass::synapse0x3d25e80() {
   return (neuron0x1d8d5de0()*0.579624);
}

double NNIdClass::synapse0x3d25ec0() {
   return (neuron0x1d8d6120()*0.0344952);
}

double NNIdClass::synapse0x3d25f00() {
   return (neuron0x1d90f490()*-0.164122);
}

double NNIdClass::synapse0x3d25f40() {
   return (neuron0x1d90f770()*-0.0254342);
}

double NNIdClass::synapse0x3d25f80() {
   return (neuron0x1d90fab0()*-0.374653);
}

double NNIdClass::synapse0x3d25fc0() {
   return (neuron0x1d90fdf0()*-0.333771);
}

double NNIdClass::synapse0x3d26000() {
   return (neuron0x1d910130()*0.126825);
}

double NNIdClass::synapse0x3d26040() {
   return (neuron0x1d910470()*0.234353);
}

double NNIdClass::synapse0x3d26080() {
   return (neuron0x1d9107b0()*-0.180036);
}

double NNIdClass::synapse0x3d25d30() {
   return (neuron0x1d910af0()*-0.0481441);
}

double NNIdClass::synapse0x3d25d70() {
   return (neuron0x1d8d47e0()*-0.0557013);
}

double NNIdClass::synapse0x3d25db0() {
   return (neuron0x1d911370()*0.291629);
}

double NNIdClass::synapse0x3d25df0() {
   return (neuron0x1d8e9af0()*-0.00664577);
}

double NNIdClass::synapse0x3d262d0() {
   return (neuron0x1d8e9e30()*-0.572664);
}

double NNIdClass::synapse0x3d26310() {
   return (neuron0x1d8ea170()*0.22792);
}

double NNIdClass::synapse0x3d26350() {
   return (neuron0x1d8ea4b0()*-0.205127);
}

double NNIdClass::synapse0x3d26390() {
   return (neuron0x1d8ea7f0()*0.190977);
}

double NNIdClass::synapse0x3d263d0() {
   return (neuron0x1d8eab30()*-0.0212569);
}

double NNIdClass::synapse0x3d26410() {
   return (neuron0x1d8eae70()*0.198907);
}

double NNIdClass::synapse0x3d26450() {
   return (neuron0x1d8eb1e0()*-0.013032);
}

double NNIdClass::synapse0x3d26490() {
   return (neuron0x1d8eb550()*0.0224783);
}

double NNIdClass::synapse0x3d264d0() {
   return (neuron0x1d8eb8c0()*-0.215085);
}

double NNIdClass::synapse0x3d26510() {
   return (neuron0x1d8ebc30()*-0.123258);
}

double NNIdClass::synapse0x3d26550() {
   return (neuron0x1d8c89b0()*-0.209195);
}

double NNIdClass::synapse0x3d268d0() {
   return (neuron0x3e012f0()*-0.0864648);
}

double NNIdClass::synapse0x3d26910() {
   return (neuron0x3e01630()*0.851219);
}

double NNIdClass::synapse0x3d26950() {
   return (neuron0x3e01970()*1.30562);
}

double NNIdClass::synapse0x3d26990() {
   return (neuron0x1de98b20()*0.074636);
}

double NNIdClass::synapse0x3d269d0() {
   return (neuron0x1de98e60()*0.0759177);
}

double NNIdClass::synapse0x3d26a10() {
   return (neuron0x1de991e0()*0.343452);
}

double NNIdClass::synapse0x3d26a50() {
   return (neuron0x1d8d6690()*-0.278476);
}

double NNIdClass::synapse0x3d26a90() {
   return (neuron0x1d8d69d0()*-0.137836);
}

double NNIdClass::synapse0x3d26ad0() {
   return (neuron0x1d8d6d10()*-0.228409);
}

double NNIdClass::synapse0x3d26b10() {
   return (neuron0x1d8d7050()*0.043052);
}

double NNIdClass::synapse0x3d26b50() {
   return (neuron0x1d8d7390()*0.380879);
}

double NNIdClass::synapse0x3d26b90() {
   return (neuron0x1d8d76d0()*0.363378);
}

double NNIdClass::synapse0x3d26bd0() {
   return (neuron0x1d8d7a10()*0.0241342);
}

double NNIdClass::synapse0x3d26c10() {
   return (neuron0x1d8d7d50()*0.280782);
}

double NNIdClass::synapse0x3d26c50() {
   return (neuron0x1d8d8090()*-0.00655755);
}

double NNIdClass::synapse0x3d26c90() {
   return (neuron0x1d8d83d0()*0.00254925);
}

double NNIdClass::synapse0x3d26720() {
   return (neuron0x1d8d44a0()*0.429746);
}

double NNIdClass::synapse0x3d26760() {
   return (neuron0x1d8d4a00()*-0.00818684);
}

double NNIdClass::synapse0x3d26de0() {
   return (neuron0x1d8d4d40()*-0.219377);
}

double NNIdClass::synapse0x3d26e20() {
   return (neuron0x1d8d5080()*0.0456926);
}

double NNIdClass::synapse0x3d26e60() {
   return (neuron0x1d8d53f0()*-0.156704);
}

double NNIdClass::synapse0x3d26ea0() {
   return (neuron0x1d8d5760()*-0.0255518);
}

double NNIdClass::synapse0x3d26ee0() {
   return (neuron0x1d8d5aa0()*-0.434317);
}

double NNIdClass::synapse0x3d26f20() {
   return (neuron0x1d8d5de0()*0.0462267);
}

double NNIdClass::synapse0x3d26f60() {
   return (neuron0x1d8d6120()*0.272102);
}

double NNIdClass::synapse0x3d26fa0() {
   return (neuron0x1d90f490()*-0.150767);
}

double NNIdClass::synapse0x3d26fe0() {
   return (neuron0x1d90f770()*-0.00874774);
}

double NNIdClass::synapse0x3d27020() {
   return (neuron0x1d90fab0()*0.347895);
}

double NNIdClass::synapse0x3d27060() {
   return (neuron0x1d90fdf0()*0.200336);
}

double NNIdClass::synapse0x3d270a0() {
   return (neuron0x1d910130()*0.0580009);
}

double NNIdClass::synapse0x3d270e0() {
   return (neuron0x1d910470()*0.0288821);
}

double NNIdClass::synapse0x3d27120() {
   return (neuron0x1d9107b0()*0.334179);
}

double NNIdClass::synapse0x3d26cd0() {
   return (neuron0x1d910af0()*-0.0767459);
}

double NNIdClass::synapse0x3d26d10() {
   return (neuron0x1d8d47e0()*-0.159384);
}

double NNIdClass::synapse0x3d26d50() {
   return (neuron0x1d911370()*0.0124399);
}

double NNIdClass::synapse0x3d26d90() {
   return (neuron0x1d8e9af0()*0.0936159);
}

double NNIdClass::synapse0x3d27370() {
   return (neuron0x1d8e9e30()*-0.109407);
}

double NNIdClass::synapse0x3d273b0() {
   return (neuron0x1d8ea170()*-0.183139);
}

double NNIdClass::synapse0x3d273f0() {
   return (neuron0x1d8ea4b0()*-0.00992771);
}

double NNIdClass::synapse0x3d27430() {
   return (neuron0x1d8ea7f0()*0.290709);
}

double NNIdClass::synapse0x3d27470() {
   return (neuron0x1d8eab30()*-0.29763);
}

double NNIdClass::synapse0x3d274b0() {
   return (neuron0x1d8eae70()*0.119051);
}

double NNIdClass::synapse0x3d274f0() {
   return (neuron0x1d8eb1e0()*-0.270692);
}

double NNIdClass::synapse0x3d27530() {
   return (neuron0x1d8eb550()*0.00826583);
}

double NNIdClass::synapse0x3d27570() {
   return (neuron0x1d8eb8c0()*-0.297673);
}

double NNIdClass::synapse0x3d275b0() {
   return (neuron0x1d8ebc30()*-0.213219);
}

double NNIdClass::synapse0x1d8e47d0() {
   return (neuron0x1d8c89b0()*-0.137364);
}

double NNIdClass::synapse0x1d8e4b50() {
   return (neuron0x3e012f0()*-0.0246409);
}

double NNIdClass::synapse0x1d8e4b90() {
   return (neuron0x3e01630()*0.0577321);
}

double NNIdClass::synapse0x1d8e4bd0() {
   return (neuron0x3e01970()*-1.33149);
}

double NNIdClass::synapse0x1d8e4c10() {
   return (neuron0x1de98b20()*0.00571078);
}

double NNIdClass::synapse0x1d8e4c50() {
   return (neuron0x1de98e60()*0.0890895);
}

double NNIdClass::synapse0x1d8e4c90() {
   return (neuron0x1de991e0()*-0.218828);
}

double NNIdClass::synapse0x1d8e4cd0() {
   return (neuron0x1d8d6690()*0.128769);
}

double NNIdClass::synapse0x1d8e4d10() {
   return (neuron0x1d8d69d0()*0.0747071);
}

double NNIdClass::synapse0x1d8e4d50() {
   return (neuron0x1d8d6d10()*-0.206823);
}

double NNIdClass::synapse0x1d8e4d90() {
   return (neuron0x1d8d7050()*-0.596525);
}

double NNIdClass::synapse0x1d8e4dd0() {
   return (neuron0x1d8d7390()*-0.0750619);
}

double NNIdClass::synapse0x1d8e4e10() {
   return (neuron0x1d8d76d0()*-0.00731905);
}

double NNIdClass::synapse0x1d8e4e50() {
   return (neuron0x1d8d7a10()*0.459105);
}

double NNIdClass::synapse0x1d8e4e90() {
   return (neuron0x1d8d7d50()*-0.0974255);
}

double NNIdClass::synapse0x1d8e4ed0() {
   return (neuron0x1d8d8090()*-2.4272);
}

double NNIdClass::synapse0x1d8e4f10() {
   return (neuron0x1d8d83d0()*0.958903);
}

double NNIdClass::synapse0x1d8e49a0() {
   return (neuron0x1d8d44a0()*-0.581228);
}

double NNIdClass::synapse0x1d8e49e0() {
   return (neuron0x1d8d4a00()*-0.045067);
}

double NNIdClass::synapse0x1d8e5060() {
   return (neuron0x1d8d4d40()*-0.0872171);
}

double NNIdClass::synapse0x1d8e50a0() {
   return (neuron0x1d8d5080()*0.0892901);
}

double NNIdClass::synapse0x1d8e50e0() {
   return (neuron0x1d8d53f0()*0.0787942);
}

double NNIdClass::synapse0x1d8e5120() {
   return (neuron0x1d8d5760()*-0.416218);
}

double NNIdClass::synapse0x1d8e5160() {
   return (neuron0x1d8d5aa0()*0.0266003);
}

double NNIdClass::synapse0x1d8e51a0() {
   return (neuron0x1d8d5de0()*0.473356);
}

double NNIdClass::synapse0x1d8e51e0() {
   return (neuron0x1d8d6120()*0.0622525);
}

double NNIdClass::synapse0x1d8e5220() {
   return (neuron0x1d90f490()*0.0944226);
}

double NNIdClass::synapse0x1d8e5260() {
   return (neuron0x1d90f770()*-0.0625941);
}

double NNIdClass::synapse0x1d8e52a0() {
   return (neuron0x1d90fab0()*-0.249974);
}

double NNIdClass::synapse0x1d8e52e0() {
   return (neuron0x1d90fdf0()*-0.0834752);
}

double NNIdClass::synapse0x1d8e5320() {
   return (neuron0x1d910130()*0.320787);
}

double NNIdClass::synapse0x1d8e5360() {
   return (neuron0x1d910470()*0.0171819);
}

double NNIdClass::synapse0x1d8e53a0() {
   return (neuron0x1d9107b0()*-0.210883);
}

double NNIdClass::synapse0x1d8e4f50() {
   return (neuron0x1d910af0()*-0.274769);
}

double NNIdClass::synapse0x1d8e4f90() {
   return (neuron0x1d8d47e0()*0.361946);
}

double NNIdClass::synapse0x1d8e4fd0() {
   return (neuron0x1d911370()*0.116016);
}

double NNIdClass::synapse0x1d8e5010() {
   return (neuron0x1d8e9af0()*-0.13677);
}

double NNIdClass::synapse0x1d8e55f0() {
   return (neuron0x1d8e9e30()*0.125885);
}

double NNIdClass::synapse0x1d8e5630() {
   return (neuron0x1d8ea170()*-0.20123);
}

double NNIdClass::synapse0x1d8e5670() {
   return (neuron0x1d8ea4b0()*0.00966113);
}

double NNIdClass::synapse0x1d8e56b0() {
   return (neuron0x1d8ea7f0()*0.231121);
}

double NNIdClass::synapse0x1d8e56f0() {
   return (neuron0x1d8eab30()*0.140493);
}

double NNIdClass::synapse0x1d8e5730() {
   return (neuron0x1d8eae70()*-0.0184252);
}

double NNIdClass::synapse0x1d8e5770() {
   return (neuron0x1d8eb1e0()*-0.0776401);
}

double NNIdClass::synapse0x1d8e57b0() {
   return (neuron0x1d8eb550()*0.0282104);
}

double NNIdClass::synapse0x1d8e57f0() {
   return (neuron0x1d8eb8c0()*-0.413655);
}

double NNIdClass::synapse0x1d8e5830() {
   return (neuron0x1d8ebc30()*-0.415107);
}

double NNIdClass::synapse0x1d8e5870() {
   return (neuron0x1d8c89b0()*0.277126);
}

double NNIdClass::synapse0x1d8e5bf0() {
   return (neuron0x3e012f0()*-0.118246);
}

double NNIdClass::synapse0x3e01510() {
   return (neuron0x3e01630()*-0.364349);
}

double NNIdClass::synapse0x3e01550() {
   return (neuron0x3e01970()*3.53011);
}

double NNIdClass::synapse0x3e01850() {
   return (neuron0x1de98b20()*0.0500258);
}

double NNIdClass::synapse0x3e01890() {
   return (neuron0x1de98e60()*-0.177305);
}

double NNIdClass::synapse0x3e01b90() {
   return (neuron0x1de991e0()*0.156473);
}

double NNIdClass::synapse0x3e01bd0() {
   return (neuron0x1d8d6690()*-0.0681539);
}

double NNIdClass::synapse0x1de98d40() {
   return (neuron0x1d8d69d0()*0.12005);
}

double NNIdClass::synapse0x1de98d80() {
   return (neuron0x1d8d6d10()*-0.180206);
}

double NNIdClass::synapse0x1de990c0() {
   return (neuron0x1d8d7050()*-0.219864);
}

double NNIdClass::synapse0x1de99100() {
   return (neuron0x1d8d7390()*-0.0700395);
}

double NNIdClass::synapse0x1de99440() {
   return (neuron0x1d8d76d0()*-0.00629401);
}

double NNIdClass::synapse0x1de99480() {
   return (neuron0x1d8d7a10()*0.112909);
}

double NNIdClass::synapse0x1d8d68b0() {
   return (neuron0x1d8d7d50()*0.468229);
}

double NNIdClass::synapse0x1d8d68f0() {
   return (neuron0x1d8d8090()*0.0715928);
}

double NNIdClass::synapse0x1d8d6bf0() {
   return (neuron0x1d8d83d0()*0.485589);
}

double NNIdClass::synapse0x1d8d6c30() {
   return (neuron0x1d8d44a0()*-0.795242);
}

double NNIdClass::synapse0x1d8d6f30() {
   return (neuron0x1d8d4a00()*0.0018505);
}

double NNIdClass::synapse0x1d8d6f70() {
   return (neuron0x1d8d4d40()*-0.0422319);
}

double NNIdClass::synapse0x1d8d7270() {
   return (neuron0x1d8d5080()*0.13648);
}

double NNIdClass::synapse0x1d8d72b0() {
   return (neuron0x1d8d53f0()*0.0590472);
}

double NNIdClass::synapse0x1d8d75b0() {
   return (neuron0x1d8d5760()*-0.547215);
}

double NNIdClass::synapse0x1d8d75f0() {
   return (neuron0x1d8d5aa0()*-0.0597166);
}

double NNIdClass::synapse0x1d8d78f0() {
   return (neuron0x1d8d5de0()*1.04506);
}

double NNIdClass::synapse0x1d8d7930() {
   return (neuron0x1d8d6120()*-0.0333836);
}

double NNIdClass::synapse0x1d8d7c30() {
   return (neuron0x1d90f490()*0.0784849);
}

double NNIdClass::synapse0x1d8d7c70() {
   return (neuron0x1d90f770()*-0.309272);
}

double NNIdClass::synapse0x1d8d7f70() {
   return (neuron0x1d90fab0()*0.103608);
}

double NNIdClass::synapse0x1d8d7fb0() {
   return (neuron0x1d90fdf0()*0.0722799);
}

double NNIdClass::synapse0x1d8d82b0() {
   return (neuron0x1d910130()*-0.00233758);
}

double NNIdClass::synapse0x1d8d82f0() {
   return (neuron0x1d910470()*0.305439);
}

double NNIdClass::synapse0x1d8e5a40() {
   return (neuron0x1d9107b0()*0.315115);
}

double NNIdClass::synapse0x1d8e5a80() {
   return (neuron0x1d910af0()*0.177565);
}

double NNIdClass::synapse0x1d8d46c0() {
   return (neuron0x1d8d47e0()*-0.103457);
}

double NNIdClass::synapse0x1d8d4700() {
   return (neuron0x1d911370()*0.572379);
}

double NNIdClass::synapse0x1d8d4c20() {
   return (neuron0x1d8e9af0()*0.251766);
}

double NNIdClass::synapse0x1d8d4c60() {
   return (neuron0x1d8e9e30()*-0.274322);
}

double NNIdClass::synapse0x1d8d4f60() {
   return (neuron0x1d8ea170()*-0.368037);
}

double NNIdClass::synapse0x1d8d4fa0() {
   return (neuron0x1d8ea4b0()*-0.288258);
}

double NNIdClass::synapse0x1d8d52d0() {
   return (neuron0x1d8ea7f0()*-0.203761);
}

double NNIdClass::synapse0x1d8d5310() {
   return (neuron0x1d8eab30()*-0.249695);
}

double NNIdClass::synapse0x1d8d5640() {
   return (neuron0x1d8eae70()*0.0220528);
}

double NNIdClass::synapse0x1d8d5680() {
   return (neuron0x1d8eb1e0()*-0.014688);
}

double NNIdClass::synapse0x1d8d5980() {
   return (neuron0x1d8eb550()*-0.0255273);
}

double NNIdClass::synapse0x1d8d59c0() {
   return (neuron0x1d8eb8c0()*-0.663533);
}

double NNIdClass::synapse0x1d8d5cc0() {
   return (neuron0x1d8ebc30()*0.0572354);
}

double NNIdClass::synapse0x1d8d5d00() {
   return (neuron0x1d8c89b0()*-0.212085);
}

double NNIdClass::synapse0x1d8e91c0() {
   return (neuron0x3e012f0()*0.162937);
}

double NNIdClass::synapse0x1d8e9200() {
   return (neuron0x3e01630()*-0.209079);
}

double NNIdClass::synapse0x1d8e9240() {
   return (neuron0x3e01970()*3.28576);
}

double NNIdClass::synapse0x1d8e9280() {
   return (neuron0x1de98b20()*0.158187);
}

double NNIdClass::synapse0x1d8e92c0() {
   return (neuron0x1de98e60()*0.117958);
}

double NNIdClass::synapse0x1d8e9300() {
   return (neuron0x1de991e0()*-0.363971);
}

double NNIdClass::synapse0x1d8e9340() {
   return (neuron0x1d8d6690()*0.0643993);
}

double NNIdClass::synapse0x1d8e9380() {
   return (neuron0x1d8d69d0()*-0.0123319);
}

double NNIdClass::synapse0x1d8e93c0() {
   return (neuron0x1d8d6d10()*0.212703);
}

double NNIdClass::synapse0x1d8e9400() {
   return (neuron0x1d8d7050()*-0.110259);
}

double NNIdClass::synapse0x1d8e9440() {
   return (neuron0x1d8d7390()*0.0270231);
}

double NNIdClass::synapse0x1d8e9480() {
   return (neuron0x1d8d76d0()*-0.0837168);
}

double NNIdClass::synapse0x1d8e94c0() {
   return (neuron0x1d8d7a10()*-0.109556);
}

double NNIdClass::synapse0x1d8e9500() {
   return (neuron0x1d8d7d50()*0.021884);
}

double NNIdClass::synapse0x1d8e9540() {
   return (neuron0x1d8d8090()*-0.0430715);
}

double NNIdClass::synapse0x1d8e9580() {
   return (neuron0x1d8d83d0()*-0.362286);
}

double NNIdClass::synapse0x1d90fcd0() {
   return (neuron0x1d8d44a0()*-0.0616616);
}

double NNIdClass::synapse0x1d90fd10() {
   return (neuron0x1d8d4a00()*0.0159601);
}

double NNIdClass::synapse0x1d910010() {
   return (neuron0x1d8d4d40()*0.1929);
}

double NNIdClass::synapse0x1d910050() {
   return (neuron0x1d8d5080()*0.0056508);
}

double NNIdClass::synapse0x1d910350() {
   return (neuron0x1d8d53f0()*0.116481);
}

double NNIdClass::synapse0x1d910390() {
   return (neuron0x1d8d5760()*0.781427);
}

double NNIdClass::synapse0x1d910690() {
   return (neuron0x1d8d5aa0()*-0.0584877);
}

double NNIdClass::synapse0x1d9106d0() {
   return (neuron0x1d8d5de0()*-1.01613);
}

double NNIdClass::synapse0x1d9109d0() {
   return (neuron0x1d8d6120()*-0.0908005);
}

double NNIdClass::synapse0x1d910a10() {
   return (neuron0x1d90f490()*0.0576912);
}

double NNIdClass::synapse0x1d910d10() {
   return (neuron0x1d90f770()*0.186896);
}

double NNIdClass::synapse0x1d910d50() {
   return (neuron0x1d90fab0()*0.890743);
}

double NNIdClass::synapse0x1d911250() {
   return (neuron0x1d90fdf0()*-0.338061);
}

double NNIdClass::synapse0x1d911290() {
   return (neuron0x1d910130()*-0.0302023);
}

double NNIdClass::synapse0x1d911590() {
   return (neuron0x1d910470()*-0.204564);
}

double NNIdClass::synapse0x1d9115d0() {
   return (neuron0x1d9107b0()*-0.0266763);
}

double NNIdClass::synapse0x1d8e9d10() {
   return (neuron0x1d910af0()*0.124745);
}

double NNIdClass::synapse0x1d8e9d50() {
   return (neuron0x1d8d47e0()*0.0780702);
}

double NNIdClass::synapse0x1d8ea050() {
   return (neuron0x1d911370()*0.537936);
}

double NNIdClass::synapse0x1d8ea090() {
   return (neuron0x1d8e9af0()*0.137065);
}

double NNIdClass::synapse0x1d8ea390() {
   return (neuron0x1d8e9e30()*-0.164952);
}

double NNIdClass::synapse0x1d8ea3d0() {
   return (neuron0x1d8ea170()*-0.0847094);
}

double NNIdClass::synapse0x1d8ea6d0() {
   return (neuron0x1d8ea4b0()*0.0645573);
}

double NNIdClass::synapse0x1d8ea710() {
   return (neuron0x1d8ea7f0()*0.412842);
}

double NNIdClass::synapse0x1d8eaa10() {
   return (neuron0x1d8eab30()*-0.0968095);
}

double NNIdClass::synapse0x1d8eaa50() {
   return (neuron0x1d8eae70()*-0.213359);
}

double NNIdClass::synapse0x1d8ead50() {
   return (neuron0x1d8eb1e0()*-0.0159392);
}

double NNIdClass::synapse0x1d8ead90() {
   return (neuron0x1d8eb550()*0.000745595);
}

double NNIdClass::synapse0x1d8eb0c0() {
   return (neuron0x1d8eb8c0()*-0.0171961);
}

double NNIdClass::synapse0x1d8eb100() {
   return (neuron0x1d8ebc30()*-0.167606);
}

double NNIdClass::synapse0x1d8eb430() {
   return (neuron0x1d8c89b0()*-0.185802);
}

double NNIdClass::synapse0x1d8eb470() {
   return (neuron0x3e012f0()*0.105366);
}

double NNIdClass::synapse0x1d8c8c00() {
   return (neuron0x3e01630()*0.565318);
}

double NNIdClass::synapse0x1d8c8c40() {
   return (neuron0x3e01970()*0.270046);
}

double NNIdClass::synapse0x1d8d6000() {
   return (neuron0x1de98b20()*0.070062);
}

double NNIdClass::synapse0x1d8d6040() {
   return (neuron0x1de98e60()*-0.0699018);
}

double NNIdClass::synapse0x1de99690() {
   return (neuron0x1de991e0()*-0.111668);
}

double NNIdClass::synapse0x1de996d0() {
   return (neuron0x1d8d6690()*0.0258767);
}

double NNIdClass::synapse0x1d8d6340() {
   return (neuron0x1d8d69d0()*0.32233);
}

double NNIdClass::synapse0x1d8d6380() {
   return (neuron0x1d8d6d10()*0.202305);
}

double NNIdClass::synapse0x1d8e98e0() {
   return (neuron0x1d8d7050()*0.506043);
}

double NNIdClass::synapse0x1d8e9920() {
   return (neuron0x1d8d7390()*0.156499);
}

double NNIdClass::synapse0x1d8e9960() {
   return (neuron0x1d8d76d0()*-0.0675641);
}

double NNIdClass::synapse0x1d8e95c0() {
   return (neuron0x1d8d7a10()*-0.088706);
}

double NNIdClass::synapse0x1d8e9600() {
   return (neuron0x1d8d7d50()*0.485428);
}

double NNIdClass::synapse0x1d8e9640() {
   return (neuron0x1d8d8090()*1.61387);
}

double NNIdClass::synapse0x1d8e9680() {
   return (neuron0x1d8d83d0()*-0.277827);
}

double NNIdClass::synapse0x1d8eb7a0() {
   return (neuron0x1d8d44a0()*-0.464982);
}

double NNIdClass::synapse0x1d8eb7e0() {
   return (neuron0x1d8d4a00()*-0.089687);
}

double NNIdClass::synapse0x1d911150() {
   return (neuron0x1d8d4d40()*-0.0489504);
}

double NNIdClass::synapse0x1d911190() {
   return (neuron0x1d8d5080()*0.0673474);
}

double NNIdClass::synapse0x1d9111d0() {
   return (neuron0x1d8d53f0()*-0.0887176);
}

double NNIdClass::synapse0x1d911210() {
   return (neuron0x1d8d5760()*-0.427708);
}

double NNIdClass::synapse0x1d903ff0() {
   return (neuron0x1d8d5aa0()*0.0270324);
}

double NNIdClass::synapse0x1d904030() {
   return (neuron0x1d8d5de0()*-0.624214);
}

double NNIdClass::synapse0x1d904070() {
   return (neuron0x1d8d6120()*-0.0279298);
}

double NNIdClass::synapse0x1d9040b0() {
   return (neuron0x1d90f490()*0.429078);
}

double NNIdClass::synapse0x1d9040f0() {
   return (neuron0x1d90f770()*-0.519355);
}

double NNIdClass::synapse0x1d904130() {
   return (neuron0x1d90fab0()*0.562454);
}

double NNIdClass::synapse0x1d904170() {
   return (neuron0x1d90fdf0()*-0.140384);
}

double NNIdClass::synapse0x1d9041b0() {
   return (neuron0x1d910130()*-0.42962);
}

double NNIdClass::synapse0x1d9041f0() {
   return (neuron0x1d910470()*0.107344);
}

double NNIdClass::synapse0x1d904230() {
   return (neuron0x1d9107b0()*-0.0986752);
}

double NNIdClass::synapse0x1d911040() {
   return (neuron0x1d910af0()*-0.122236);
}

double NNIdClass::synapse0x1d911080() {
   return (neuron0x1d8d47e0()*-0.59001);
}

double NNIdClass::synapse0x1d9110c0() {
   return (neuron0x1d911370()*-0.5435);
}

double NNIdClass::synapse0x1d911100() {
   return (neuron0x1d8e9af0()*-0.538348);
}

double NNIdClass::synapse0x1d904480() {
   return (neuron0x1d8e9e30()*0.0736001);
}

double NNIdClass::synapse0x1d9044c0() {
   return (neuron0x1d8ea170()*-0.231448);
}

double NNIdClass::synapse0x1d904500() {
   return (neuron0x1d8ea4b0()*0.381548);
}

double NNIdClass::synapse0x1d904540() {
   return (neuron0x1d8ea7f0()*0.343576);
}

double NNIdClass::synapse0x1d904580() {
   return (neuron0x1d8eab30()*0.446344);
}

double NNIdClass::synapse0x1d9045c0() {
   return (neuron0x1d8eae70()*-0.19837);
}

double NNIdClass::synapse0x1d904600() {
   return (neuron0x1d8eb1e0()*-0.287411);
}

double NNIdClass::synapse0x1d904640() {
   return (neuron0x1d8eb550()*-0.109467);
}

double NNIdClass::synapse0x1d904680() {
   return (neuron0x1d8eb8c0()*0.193305);
}

double NNIdClass::synapse0x1d9046c0() {
   return (neuron0x1d8ebc30()*-0.0395511);
}

double NNIdClass::synapse0x1d904700() {
   return (neuron0x1d8c89b0()*0.372951);
}

double NNIdClass::synapse0x1d904a80() {
   return (neuron0x3e012f0()*-0.0471685);
}

double NNIdClass::synapse0x1d904ac0() {
   return (neuron0x3e01630()*0.547246);
}

double NNIdClass::synapse0x1d904b00() {
   return (neuron0x3e01970()*-2.65853);
}

double NNIdClass::synapse0x1d904b40() {
   return (neuron0x1de98b20()*0.318767);
}

double NNIdClass::synapse0x1d904b80() {
   return (neuron0x1de98e60()*-0.187911);
}

double NNIdClass::synapse0x1d904bc0() {
   return (neuron0x1de991e0()*0.197493);
}

double NNIdClass::synapse0x1d904c00() {
   return (neuron0x1d8d6690()*0.0392885);
}

double NNIdClass::synapse0x1d904c40() {
   return (neuron0x1d8d69d0()*0.225105);
}

double NNIdClass::synapse0x1d904c80() {
   return (neuron0x1d8d6d10()*-0.175365);
}

double NNIdClass::synapse0x1d904cc0() {
   return (neuron0x1d8d7050()*-0.0160159);
}

double NNIdClass::synapse0x1d904d00() {
   return (neuron0x1d8d7390()*0.0728844);
}

double NNIdClass::synapse0x1d904d40() {
   return (neuron0x1d8d76d0()*-0.092929);
}

double NNIdClass::synapse0x1d904d80() {
   return (neuron0x1d8d7a10()*-0.00509887);
}

double NNIdClass::synapse0x1d904dc0() {
   return (neuron0x1d8d7d50()*0.323025);
}

double NNIdClass::synapse0x1d904e00() {
   return (neuron0x1d8d8090()*0.271739);
}

double NNIdClass::synapse0x1d904e40() {
   return (neuron0x1d8d83d0()*0.272846);
}

double NNIdClass::synapse0x1d9048d0() {
   return (neuron0x1d8d44a0()*0.304604);
}

double NNIdClass::synapse0x1d904910() {
   return (neuron0x1d8d4a00()*0.0638588);
}

double NNIdClass::synapse0x1d904f90() {
   return (neuron0x1d8d4d40()*0.740124);
}

double NNIdClass::synapse0x1d904fd0() {
   return (neuron0x1d8d5080()*0.0510979);
}

double NNIdClass::synapse0x1d905010() {
   return (neuron0x1d8d53f0()*0.1741);
}

double NNIdClass::synapse0x1d905050() {
   return (neuron0x1d8d5760()*-0.429934);
}

double NNIdClass::synapse0x1d905090() {
   return (neuron0x1d8d5aa0()*0.0136667);
}

double NNIdClass::synapse0x1d9050d0() {
   return (neuron0x1d8d5de0()*0.96548);
}

double NNIdClass::synapse0x1d905110() {
   return (neuron0x1d8d6120()*-0.214672);
}

double NNIdClass::synapse0x1d905150() {
   return (neuron0x1d90f490()*0.180797);
}

double NNIdClass::synapse0x1d905190() {
   return (neuron0x1d90f770()*-0.295688);
}

double NNIdClass::synapse0x1d9051d0() {
   return (neuron0x1d90fab0()*-0.204726);
}

double NNIdClass::synapse0x1d905210() {
   return (neuron0x1d90fdf0()*-0.158385);
}

double NNIdClass::synapse0x1d905250() {
   return (neuron0x1d910130()*-0.224774);
}

double NNIdClass::synapse0x1d905290() {
   return (neuron0x1d910470()*0.202408);
}

double NNIdClass::synapse0x1d9052d0() {
   return (neuron0x1d9107b0()*-0.281916);
}

double NNIdClass::synapse0x1d904e80() {
   return (neuron0x1d910af0()*0.308874);
}

double NNIdClass::synapse0x1d904ec0() {
   return (neuron0x1d8d47e0()*0.0174364);
}

double NNIdClass::synapse0x1d904f00() {
   return (neuron0x1d911370()*-0.147778);
}

double NNIdClass::synapse0x1d904f40() {
   return (neuron0x1d8e9af0()*-0.359812);
}

double NNIdClass::synapse0x1d905520() {
   return (neuron0x1d8e9e30()*-0.517858);
}

double NNIdClass::synapse0x1d905560() {
   return (neuron0x1d8ea170()*0.365032);
}

double NNIdClass::synapse0x1d9055a0() {
   return (neuron0x1d8ea4b0()*0.000243472);
}

double NNIdClass::synapse0x1d9055e0() {
   return (neuron0x1d8ea7f0()*-0.0454087);
}

double NNIdClass::synapse0x1d905620() {
   return (neuron0x1d8eab30()*0.525635);
}

double NNIdClass::synapse0x1d905660() {
   return (neuron0x1d8eae70()*-0.158398);
}

double NNIdClass::synapse0x1d9056a0() {
   return (neuron0x1d8eb1e0()*0.206131);
}

double NNIdClass::synapse0x1d9056e0() {
   return (neuron0x1d8eb550()*0.0319209);
}

double NNIdClass::synapse0x1d905720() {
   return (neuron0x1d8eb8c0()*-0.60973);
}

double NNIdClass::synapse0x1d905760() {
   return (neuron0x1d8ebc30()*0.17107);
}

double NNIdClass::synapse0x1d9057a0() {
   return (neuron0x1d8c89b0()*-0.355874);
}

double NNIdClass::synapse0x1d905b20() {
   return (neuron0x3e012f0()*0.437118);
}

double NNIdClass::synapse0x1d905b60() {
   return (neuron0x3e01630()*-0.076126);
}

double NNIdClass::synapse0x1d905ba0() {
   return (neuron0x3e01970()*0.570014);
}

double NNIdClass::synapse0x1d905be0() {
   return (neuron0x1de98b20()*0.0715575);
}

double NNIdClass::synapse0x1d905c20() {
   return (neuron0x1de98e60()*-0.0943215);
}

double NNIdClass::synapse0x1d905c60() {
   return (neuron0x1de991e0()*-0.00895228);
}

double NNIdClass::synapse0x1d905ca0() {
   return (neuron0x1d8d6690()*0.00788397);
}

double NNIdClass::synapse0x1d905ce0() {
   return (neuron0x1d8d69d0()*0.15635);
}

double NNIdClass::synapse0x1d905d20() {
   return (neuron0x1d8d6d10()*-0.150881);
}

double NNIdClass::synapse0x1d905d60() {
   return (neuron0x1d8d7050()*0.309437);
}

double NNIdClass::synapse0x1d905da0() {
   return (neuron0x1d8d7390()*-0.00237509);
}

double NNIdClass::synapse0x1d905de0() {
   return (neuron0x1d8d76d0()*0.0362762);
}

double NNIdClass::synapse0x1d905e20() {
   return (neuron0x1d8d7a10()*0.415704);
}

double NNIdClass::synapse0x1d905e60() {
   return (neuron0x1d8d7d50()*-0.0500483);
}

double NNIdClass::synapse0x1d905ea0() {
   return (neuron0x1d8d8090()*0.837831);
}

double NNIdClass::synapse0x1d905ee0() {
   return (neuron0x1d8d83d0()*-0.145141);
}

double NNIdClass::synapse0x1d905970() {
   return (neuron0x1d8d44a0()*-0.0471434);
}

double NNIdClass::synapse0x1d9059b0() {
   return (neuron0x1d8d4a00()*-0.0257394);
}

double NNIdClass::synapse0x1d906030() {
   return (neuron0x1d8d4d40()*-0.0399996);
}

double NNIdClass::synapse0x1d906070() {
   return (neuron0x1d8d5080()*0.016763);
}

double NNIdClass::synapse0x1d9060b0() {
   return (neuron0x1d8d53f0()*0.0319028);
}

double NNIdClass::synapse0x1d9060f0() {
   return (neuron0x1d8d5760()*-0.312241);
}

double NNIdClass::synapse0x1d906130() {
   return (neuron0x1d8d5aa0()*0.462771);
}

double NNIdClass::synapse0x1d906170() {
   return (neuron0x1d8d5de0()*0.34307);
}

double NNIdClass::synapse0x1d9061b0() {
   return (neuron0x1d8d6120()*0.136328);
}

double NNIdClass::synapse0x1d9061f0() {
   return (neuron0x1d90f490()*-0.111614);
}

double NNIdClass::synapse0x1d906230() {
   return (neuron0x1d90f770()*-0.376194);
}

double NNIdClass::synapse0x1d906270() {
   return (neuron0x1d90fab0()*-0.56097);
}

double NNIdClass::synapse0x1d9062b0() {
   return (neuron0x1d90fdf0()*-0.54608);
}

double NNIdClass::synapse0x1d9062f0() {
   return (neuron0x1d910130()*-0.349518);
}

double NNIdClass::synapse0x1d906330() {
   return (neuron0x1d910470()*-0.190066);
}

double NNIdClass::synapse0x1d906370() {
   return (neuron0x1d9107b0()*-0.204524);
}

double NNIdClass::synapse0x1d905f20() {
   return (neuron0x1d910af0()*-0.395766);
}

double NNIdClass::synapse0x1d905f60() {
   return (neuron0x1d8d47e0()*-0.318086);
}

double NNIdClass::synapse0x1d905fa0() {
   return (neuron0x1d911370()*0.0487196);
}

double NNIdClass::synapse0x1d905fe0() {
   return (neuron0x1d8e9af0()*-0.333406);
}

double NNIdClass::synapse0x1d9065c0() {
   return (neuron0x1d8e9e30()*-0.354207);
}

double NNIdClass::synapse0x1d906600() {
   return (neuron0x1d8ea170()*-0.210184);
}

double NNIdClass::synapse0x1d906640() {
   return (neuron0x1d8ea4b0()*-0.166229);
}

double NNIdClass::synapse0x1d906680() {
   return (neuron0x1d8ea7f0()*-0.0166478);
}

double NNIdClass::synapse0x1d9066c0() {
   return (neuron0x1d8eab30()*-0.361283);
}

double NNIdClass::synapse0x1d906700() {
   return (neuron0x1d8eae70()*0.0469518);
}

double NNIdClass::synapse0x1d906740() {
   return (neuron0x1d8eb1e0()*0.06719);
}

double NNIdClass::synapse0x1d906780() {
   return (neuron0x1d8eb550()*0.0692369);
}

double NNIdClass::synapse0x1d9067c0() {
   return (neuron0x1d8eb8c0()*-0.166782);
}

double NNIdClass::synapse0x1d906800() {
   return (neuron0x1d8ebc30()*0.56797);
}

double NNIdClass::synapse0x1d906840() {
   return (neuron0x1d8c89b0()*0.297965);
}

double NNIdClass::synapse0x1d906bc0() {
   return (neuron0x3e012f0()*0.223115);
}

double NNIdClass::synapse0x1d906c00() {
   return (neuron0x3e01630()*-0.117976);
}

double NNIdClass::synapse0x1d906c40() {
   return (neuron0x3e01970()*-0.00149023);
}

double NNIdClass::synapse0x1d906c80() {
   return (neuron0x1de98b20()*0.214197);
}

double NNIdClass::synapse0x1d906cc0() {
   return (neuron0x1de98e60()*0.204385);
}

double NNIdClass::synapse0x1d906d00() {
   return (neuron0x1de991e0()*0.190505);
}

double NNIdClass::synapse0x1d906d40() {
   return (neuron0x1d8d6690()*-0.125498);
}

double NNIdClass::synapse0x1d906d80() {
   return (neuron0x1d8d69d0()*-0.0693615);
}

double NNIdClass::synapse0x1d906dc0() {
   return (neuron0x1d8d6d10()*-0.562405);
}

double NNIdClass::synapse0x1d906e00() {
   return (neuron0x1d8d7050()*-0.264977);
}

double NNIdClass::synapse0x1d906e40() {
   return (neuron0x1d8d7390()*-0.12851);
}

double NNIdClass::synapse0x1d906e80() {
   return (neuron0x1d8d76d0()*0.26081);
}

double NNIdClass::synapse0x1d906ec0() {
   return (neuron0x1d8d7a10()*0.0843183);
}

double NNIdClass::synapse0x1d906f00() {
   return (neuron0x1d8d7d50()*0.198996);
}

double NNIdClass::synapse0x1d906f40() {
   return (neuron0x1d8d8090()*0.181732);
}

double NNIdClass::synapse0x1d906f80() {
   return (neuron0x1d8d83d0()*0.255604);
}

double NNIdClass::synapse0x1d906a10() {
   return (neuron0x1d8d44a0()*0.184199);
}

double NNIdClass::synapse0x1d906a50() {
   return (neuron0x1d8d4a00()*-0.0179163);
}

double NNIdClass::synapse0x1d9070d0() {
   return (neuron0x1d8d4d40()*-0.0357318);
}

double NNIdClass::synapse0x1d907110() {
   return (neuron0x1d8d5080()*-0.044339);
}

double NNIdClass::synapse0x1d907150() {
   return (neuron0x1d8d53f0()*0.0295858);
}

double NNIdClass::synapse0x1d907190() {
   return (neuron0x1d8d5760()*-0.132026);
}

double NNIdClass::synapse0x1d9071d0() {
   return (neuron0x1d8d5aa0()*1.20423);
}

double NNIdClass::synapse0x1d907210() {
   return (neuron0x1d8d5de0()*0.477196);
}

double NNIdClass::synapse0x1d907250() {
   return (neuron0x1d8d6120()*-0.0732972);
}

double NNIdClass::synapse0x1d907290() {
   return (neuron0x1d90f490()*0.438265);
}

double NNIdClass::synapse0x1d9072d0() {
   return (neuron0x1d90f770()*0.0383649);
}

double NNIdClass::synapse0x1d907310() {
   return (neuron0x1d90fab0()*0.0693601);
}

double NNIdClass::synapse0x1d907350() {
   return (neuron0x1d90fdf0()*-0.0825285);
}

double NNIdClass::synapse0x1d907390() {
   return (neuron0x1d910130()*0.363982);
}

double NNIdClass::synapse0x1d9073d0() {
   return (neuron0x1d910470()*-0.0254096);
}

double NNIdClass::synapse0x1d907410() {
   return (neuron0x1d9107b0()*-0.106139);
}

double NNIdClass::synapse0x1d906fc0() {
   return (neuron0x1d910af0()*0.225932);
}

double NNIdClass::synapse0x1d907000() {
   return (neuron0x1d8d47e0()*0.485649);
}

double NNIdClass::synapse0x1d907040() {
   return (neuron0x1d911370()*0.320586);
}

double NNIdClass::synapse0x1d907080() {
   return (neuron0x1d8e9af0()*-0.415765);
}

double NNIdClass::synapse0x1d907660() {
   return (neuron0x1d8e9e30()*-0.0323564);
}

double NNIdClass::synapse0x1d9076a0() {
   return (neuron0x1d8ea170()*-0.168117);
}

double NNIdClass::synapse0x1d9076e0() {
   return (neuron0x1d8ea4b0()*0.202043);
}

double NNIdClass::synapse0x1d907720() {
   return (neuron0x1d8ea7f0()*-0.152982);
}

double NNIdClass::synapse0x1d907760() {
   return (neuron0x1d8eab30()*0.0570662);
}

double NNIdClass::synapse0x1d9077a0() {
   return (neuron0x1d8eae70()*-0.0535813);
}

double NNIdClass::synapse0x1d9077e0() {
   return (neuron0x1d8eb1e0()*0.350208);
}

double NNIdClass::synapse0x1d907820() {
   return (neuron0x1d8eb550()*0.169024);
}

double NNIdClass::synapse0x1d907860() {
   return (neuron0x1d8eb8c0()*0.389099);
}

double NNIdClass::synapse0x1d9078a0() {
   return (neuron0x1d8ebc30()*-0.104348);
}

double NNIdClass::synapse0x1d9078e0() {
   return (neuron0x1d8c89b0()*0.280526);
}

double NNIdClass::synapse0x1d907c60() {
   return (neuron0x3e012f0()*-0.144642);
}

double NNIdClass::synapse0x1d907ca0() {
   return (neuron0x3e01630()*0.124318);
}

double NNIdClass::synapse0x1d907ce0() {
   return (neuron0x3e01970()*-0.261696);
}

double NNIdClass::synapse0x1d907d20() {
   return (neuron0x1de98b20()*0.0983231);
}

double NNIdClass::synapse0x1d907d60() {
   return (neuron0x1de98e60()*0.0328652);
}

double NNIdClass::synapse0x1d907da0() {
   return (neuron0x1de991e0()*-0.141023);
}

double NNIdClass::synapse0x1d907de0() {
   return (neuron0x1d8d6690()*-0.0235983);
}

double NNIdClass::synapse0x1d907e20() {
   return (neuron0x1d8d69d0()*0.119754);
}

double NNIdClass::synapse0x1d907e60() {
   return (neuron0x1d8d6d10()*-0.605384);
}

double NNIdClass::synapse0x1d907ea0() {
   return (neuron0x1d8d7050()*-0.61148);
}

double NNIdClass::synapse0x1d907ee0() {
   return (neuron0x1d8d7390()*0.214093);
}

double NNIdClass::synapse0x1d907f20() {
   return (neuron0x1d8d76d0()*-0.0569334);
}

double NNIdClass::synapse0x1d907f60() {
   return (neuron0x1d8d7a10()*-0.00985081);
}

double NNIdClass::synapse0x1d907fa0() {
   return (neuron0x1d8d7d50()*-0.383447);
}

double NNIdClass::synapse0x1d907fe0() {
   return (neuron0x1d8d8090()*-0.968382);
}

double NNIdClass::synapse0x1d908020() {
   return (neuron0x1d8d83d0()*0.116338);
}

double NNIdClass::synapse0x1d907ab0() {
   return (neuron0x1d8d44a0()*-0.0581681);
}

double NNIdClass::synapse0x1d907af0() {
   return (neuron0x1d8d4a00()*0.122825);
}

double NNIdClass::synapse0x1d908170() {
   return (neuron0x1d8d4d40()*0.0418696);
}

double NNIdClass::synapse0x1d9081b0() {
   return (neuron0x1d8d5080()*0.188044);
}

double NNIdClass::synapse0x1d9081f0() {
   return (neuron0x1d8d53f0()*-0.22507);
}

double NNIdClass::synapse0x1d908230() {
   return (neuron0x1d8d5760()*0.235494);
}

double NNIdClass::synapse0x1d908270() {
   return (neuron0x1d8d5aa0()*-0.161917);
}

double NNIdClass::synapse0x1d9082b0() {
   return (neuron0x1d8d5de0()*-0.325359);
}

double NNIdClass::synapse0x1d9082f0() {
   return (neuron0x1d8d6120()*-0.204504);
}

double NNIdClass::synapse0x1d908330() {
   return (neuron0x1d90f490()*0.0268835);
}

double NNIdClass::synapse0x1d908370() {
   return (neuron0x1d90f770()*-0.0489319);
}

double NNIdClass::synapse0x1d9083b0() {
   return (neuron0x1d90fab0()*0.341081);
}

double NNIdClass::synapse0x1d9083f0() {
   return (neuron0x1d90fdf0()*0.444041);
}

double NNIdClass::synapse0x1d908430() {
   return (neuron0x1d910130()*-0.153636);
}

double NNIdClass::synapse0x1d908470() {
   return (neuron0x1d910470()*0.0715605);
}

double NNIdClass::synapse0x1d9084b0() {
   return (neuron0x1d9107b0()*0.125151);
}

double NNIdClass::synapse0x1d908060() {
   return (neuron0x1d910af0()*0.0986404);
}

double NNIdClass::synapse0x1d9080a0() {
   return (neuron0x1d8d47e0()*0.137862);
}

double NNIdClass::synapse0x1d9080e0() {
   return (neuron0x1d911370()*-0.304255);
}

double NNIdClass::synapse0x1d908120() {
   return (neuron0x1d8e9af0()*0.258639);
}

double NNIdClass::synapse0x1d908700() {
   return (neuron0x1d8e9e30()*-0.249896);
}

double NNIdClass::synapse0x1d908740() {
   return (neuron0x1d8ea170()*0.180029);
}

double NNIdClass::synapse0x1d908780() {
   return (neuron0x1d8ea4b0()*0.142318);
}

double NNIdClass::synapse0x1d9087c0() {
   return (neuron0x1d8ea7f0()*-0.130511);
}

double NNIdClass::synapse0x1d908800() {
   return (neuron0x1d8eab30()*0.176372);
}

double NNIdClass::synapse0x1d908840() {
   return (neuron0x1d8eae70()*-0.0216473);
}

double NNIdClass::synapse0x1d908880() {
   return (neuron0x1d8eb1e0()*0.0111947);
}

double NNIdClass::synapse0x1d9088c0() {
   return (neuron0x1d8eb550()*-0.0415054);
}

double NNIdClass::synapse0x1d908900() {
   return (neuron0x1d8eb8c0()*0.108557);
}

double NNIdClass::synapse0x1d908940() {
   return (neuron0x1d8ebc30()*0.0129566);
}

double NNIdClass::synapse0x1d908980() {
   return (neuron0x1d8c89b0()*-0.0153738);
}

double NNIdClass::synapse0x1d908d00() {
   return (neuron0x3e012f0()*-0.197178);
}

double NNIdClass::synapse0x1d908d40() {
   return (neuron0x3e01630()*0.352534);
}

double NNIdClass::synapse0x1d908d80() {
   return (neuron0x3e01970()*-0.712696);
}

double NNIdClass::synapse0x1d908dc0() {
   return (neuron0x1de98b20()*0.101106);
}

double NNIdClass::synapse0x1d908e00() {
   return (neuron0x1de98e60()*-0.156556);
}

double NNIdClass::synapse0x1d908e40() {
   return (neuron0x1de991e0()*0.0197213);
}

double NNIdClass::synapse0x1d908e80() {
   return (neuron0x1d8d6690()*0.0948719);
}

double NNIdClass::synapse0x1d908ec0() {
   return (neuron0x1d8d69d0()*-0.106534);
}

double NNIdClass::synapse0x1d908f00() {
   return (neuron0x1d8d6d10()*0.485476);
}

double NNIdClass::synapse0x1d908f40() {
   return (neuron0x1d8d7050()*0.749731);
}

double NNIdClass::synapse0x1d908f80() {
   return (neuron0x1d8d7390()*0.22904);
}

double NNIdClass::synapse0x1d908fc0() {
   return (neuron0x1d8d76d0()*-0.348233);
}

double NNIdClass::synapse0x1d909000() {
   return (neuron0x1d8d7a10()*-0.0756888);
}

double NNIdClass::synapse0x1d909040() {
   return (neuron0x1d8d7d50()*0.0869652);
}

double NNIdClass::synapse0x1d909080() {
   return (neuron0x1d8d8090()*-1.15979);
}

double NNIdClass::synapse0x1d9090c0() {
   return (neuron0x1d8d83d0()*-0.584933);
}

double NNIdClass::synapse0x1d908b50() {
   return (neuron0x1d8d44a0()*0.589394);
}

double NNIdClass::synapse0x1d908b90() {
   return (neuron0x1d8d4a00()*-0.0515601);
}

double NNIdClass::synapse0x1d909210() {
   return (neuron0x1d8d4d40()*-0.143251);
}

double NNIdClass::synapse0x1d909250() {
   return (neuron0x1d8d5080()*-0.0122294);
}

double NNIdClass::synapse0x1d909290() {
   return (neuron0x1d8d53f0()*0.0011527);
}

double NNIdClass::synapse0x1d9092d0() {
   return (neuron0x1d8d5760()*0.528352);
}

double NNIdClass::synapse0x1d909310() {
   return (neuron0x1d8d5aa0()*0.0575021);
}

double NNIdClass::synapse0x1d909350() {
   return (neuron0x1d8d5de0()*-0.210763);
}

double NNIdClass::synapse0x1d909390() {
   return (neuron0x1d8d6120()*0.0352532);
}

double NNIdClass::synapse0x1d9093d0() {
   return (neuron0x1d90f490()*-0.0511404);
}

double NNIdClass::synapse0x1d909410() {
   return (neuron0x1d90f770()*-0.309694);
}

double NNIdClass::synapse0x1d909450() {
   return (neuron0x1d90fab0()*0.241495);
}

double NNIdClass::synapse0x1d957260() {
   return (neuron0x1d90fdf0()*0.0784635);
}

double NNIdClass::synapse0x1d9572a0() {
   return (neuron0x1d910130()*0.0520962);
}

double NNIdClass::synapse0x1d9572e0() {
   return (neuron0x1d910470()*-0.0487027);
}

double NNIdClass::synapse0x1d957320() {
   return (neuron0x1d9107b0()*0.0400351);
}

double NNIdClass::synapse0x1d909100() {
   return (neuron0x1d910af0()*-0.073349);
}

double NNIdClass::synapse0x1d909140() {
   return (neuron0x1d8d47e0()*-0.311931);
}

double NNIdClass::synapse0x1d909180() {
   return (neuron0x1d911370()*-0.167649);
}

double NNIdClass::synapse0x1d9091c0() {
   return (neuron0x1d8e9af0()*-0.284171);
}

double NNIdClass::synapse0x1d957570() {
   return (neuron0x1d8e9e30()*-0.192245);
}

double NNIdClass::synapse0x1d9575b0() {
   return (neuron0x1d8ea170()*-0.357712);
}

double NNIdClass::synapse0x1d9575f0() {
   return (neuron0x1d8ea4b0()*-0.242115);
}

double NNIdClass::synapse0x1d957630() {
   return (neuron0x1d8ea7f0()*0.425695);
}

double NNIdClass::synapse0x1d957670() {
   return (neuron0x1d8eab30()*0.293269);
}

double NNIdClass::synapse0x1d9576b0() {
   return (neuron0x1d8eae70()*-0.140339);
}

double NNIdClass::synapse0x1d9576f0() {
   return (neuron0x1d8eb1e0()*-0.150967);
}

double NNIdClass::synapse0x1d957730() {
   return (neuron0x1d8eb550()*-0.166735);
}

double NNIdClass::synapse0x1d957770() {
   return (neuron0x1d8eb8c0()*0.0854897);
}

double NNIdClass::synapse0x1d9577b0() {
   return (neuron0x1d8ebc30()*-0.0435549);
}

double NNIdClass::synapse0x1d9577f0() {
   return (neuron0x1d8c89b0()*-0.00475637);
}

double NNIdClass::synapse0x3d23880() {
   return (neuron0x1d8c8d20()*0.350593);
}

double NNIdClass::synapse0x3d238c0() {
   return (neuron0x1d8c9ba0()*-0.250402);
}

double NNIdClass::synapse0x3d23900() {
   return (neuron0x1d8db840()*-0.275678);
}

double NNIdClass::synapse0x3d23940() {
   return (neuron0x1d8cb3a0()*-0.0819697);
}

double NNIdClass::synapse0x3d23980() {
   return (neuron0x1d8cdb90()*0.0699122);
}

double NNIdClass::synapse0x3d239c0() {
   return (neuron0x1d8ceb30()*0.34347);
}

double NNIdClass::synapse0x3d23a00() {
   return (neuron0x1d8d0490()*-0.166678);
}

double NNIdClass::synapse0x3d23a40() {
   return (neuron0x1d8d1470()*-0.425554);
}

double NNIdClass::synapse0x3d23a80() {
   return (neuron0x1d94d1c0()*-0.0367433);
}

double NNIdClass::synapse0x3d23ac0() {
   return (neuron0x1d94e260()*0.151855);
}

double NNIdClass::synapse0x3d23b00() {
   return (neuron0x1d94f300()*0.400412);
}

double NNIdClass::synapse0x3d23b40() {
   return (neuron0x1d9503a0()*-0.429365);
}

double NNIdClass::synapse0x3d23b80() {
   return (neuron0x3d255f0()*0.511088);
}

double NNIdClass::synapse0x3d23bc0() {
   return (neuron0x3d26590()*0.38661);
}

double NNIdClass::synapse0x3d23c00() {
   return (neuron0x1d8e4810()*0.304397);
}

double NNIdClass::synapse0x3d23c40() {
   return (neuron0x1d8e58b0()*0.273165);
}

double NNIdClass::synapse0x1d8cb650() {
   return (neuron0x1d8e9030()*-0.448971);
}

double NNIdClass::synapse0x1d8cb690() {
   return (neuron0x1d903a50()*0.17076);
}

double NNIdClass::synapse0x1d8cde40() {
   return (neuron0x1d904740()*0.148353);
}

double NNIdClass::synapse0x1d8cde80() {
   return (neuron0x1d9057e0()*-0.137228);
}

double NNIdClass::synapse0x1d8cede0() {
   return (neuron0x1d906880()*-0.216632);
}

double NNIdClass::synapse0x1d8cee20() {
   return (neuron0x1d907920()*0.104792);
}

double NNIdClass::synapse0x1d8d0740() {
   return (neuron0x1d9089c0()*-0.316864);
}

double NNIdClass::synapse0x3d23f20() {
   return (neuron0x1d8c8d20()*1.13856);
}

double NNIdClass::synapse0x3d23f60() {
   return (neuron0x1d8c9ba0()*-0.0898079);
}

double NNIdClass::synapse0x3d23fa0() {
   return (neuron0x1d8db840()*-0.377638);
}

double NNIdClass::synapse0x3d23fe0() {
   return (neuron0x1d8cb3a0()*0.185517);
}

double NNIdClass::synapse0x3d24020() {
   return (neuron0x1d8cdb90()*-0.886272);
}

double NNIdClass::synapse0x3d24060() {
   return (neuron0x1d8ceb30()*0.311792);
}

double NNIdClass::synapse0x3d240a0() {
   return (neuron0x1d8d0490()*0.209704);
}

double NNIdClass::synapse0x3d240e0() {
   return (neuron0x1d8d1470()*0.125761);
}

double NNIdClass::synapse0x3d24120() {
   return (neuron0x1d94d1c0()*0.482724);
}

double NNIdClass::synapse0x3d24160() {
   return (neuron0x1d94e260()*0.39389);
}

double NNIdClass::synapse0x3d241a0() {
   return (neuron0x1d94f300()*0.588163);
}

double NNIdClass::synapse0x3d241e0() {
   return (neuron0x1d9503a0()*-0.171814);
}

double NNIdClass::synapse0x3d24220() {
   return (neuron0x3d255f0()*-0.214875);
}

double NNIdClass::synapse0x3d24260() {
   return (neuron0x3d26590()*0.0627501);
}

double NNIdClass::synapse0x3d242a0() {
   return (neuron0x1d8e4810()*-0.700161);
}

double NNIdClass::synapse0x3d242e0() {
   return (neuron0x1d8e58b0()*0.712408);
}

double NNIdClass::synapse0x1d8d0780() {
   return (neuron0x1d8e9030()*1.56991);
}

double NNIdClass::synapse0x1d94f5b0() {
   return (neuron0x1d903a50()*0.824416);
}

double NNIdClass::synapse0x1d94f5f0() {
   return (neuron0x1d904740()*-0.957203);
}

double NNIdClass::synapse0x1d8cf5a0() {
   return (neuron0x1d9057e0()*-0.0614717);
}

double NNIdClass::synapse0x1d8cf5e0() {
   return (neuron0x1d906880()*0.416319);
}

double NNIdClass::synapse0x3d258a0() {
   return (neuron0x1d907920()*0.173572);
}

double NNIdClass::synapse0x3d258e0() {
   return (neuron0x1d9089c0()*-0.00718603);
}

double NNIdClass::synapse0x3d245c0() {
   return (neuron0x1d8c8d20()*-0.1355);
}

double NNIdClass::synapse0x3d24600() {
   return (neuron0x1d8c9ba0()*0.316817);
}

double NNIdClass::synapse0x3d24640() {
   return (neuron0x1d8db840()*0.265517);
}

double NNIdClass::synapse0x3d24680() {
   return (neuron0x1d8cb3a0()*-0.102827);
}

double NNIdClass::synapse0x3d246c0() {
   return (neuron0x1d8cdb90()*-0.614478);
}

double NNIdClass::synapse0x3d24700() {
   return (neuron0x1d8ceb30()*0.0398336);
}

double NNIdClass::synapse0x3d24740() {
   return (neuron0x1d8d0490()*0.0954543);
}

double NNIdClass::synapse0x3d24780() {
   return (neuron0x1d8d1470()*0.42761);
}

double NNIdClass::synapse0x3d247c0() {
   return (neuron0x1d94d1c0()*-0.000815366);
}

double NNIdClass::synapse0x3d24800() {
   return (neuron0x1d94e260()*0.567038);
}

double NNIdClass::synapse0x3d24840() {
   return (neuron0x1d94f300()*0.433116);
}

double NNIdClass::synapse0x3d24880() {
   return (neuron0x1d9503a0()*-0.35664);
}

double NNIdClass::synapse0x3d248c0() {
   return (neuron0x3d255f0()*0.16074);
}

double NNIdClass::synapse0x3d24900() {
   return (neuron0x3d26590()*0.0666293);
}

double NNIdClass::synapse0x3d24940() {
   return (neuron0x1d8e4810()*-0.184552);
}

double NNIdClass::synapse0x3d24980() {
   return (neuron0x1d8e58b0()*0.525118);
}

double NNIdClass::synapse0x1d90f990() {
   return (neuron0x1d8e9030()*-0.0757545);
}

double NNIdClass::synapse0x1d90f9d0() {
   return (neuron0x1d903a50()*0.472863);
}

double NNIdClass::synapse0x1d8c8890() {
   return (neuron0x1d904740()*-0.0579349);
}

double NNIdClass::synapse0x1d8c88d0() {
   return (neuron0x1d9057e0()*-0.433484);
}

double NNIdClass::synapse0x1d9049f0() {
   return (neuron0x1d906880()*-0.0477261);
}

double NNIdClass::synapse0x1d904a30() {
   return (neuron0x1d907920()*0.257778);
}

double NNIdClass::synapse0x1d905a90() {
   return (neuron0x1d9089c0()*-0.108765);
}

double NNIdClass::synapse0x3d24c60() {
   return (neuron0x1d8c8d20()*-1.02029);
}

double NNIdClass::synapse0x3d24ca0() {
   return (neuron0x1d8c9ba0()*-0.0256071);
}

double NNIdClass::synapse0x3d24ce0() {
   return (neuron0x1d8db840()*0.00919514);
}

double NNIdClass::synapse0x3d24d20() {
   return (neuron0x1d8cb3a0()*0.02527);
}

double NNIdClass::synapse0x3d24d60() {
   return (neuron0x1d8cdb90()*0.783647);
}

double NNIdClass::synapse0x3d24da0() {
   return (neuron0x1d8ceb30()*-0.256408);
}

double NNIdClass::synapse0x3d24de0() {
   return (neuron0x1d8d0490()*-0.0233047);
}

double NNIdClass::synapse0x3d24e20() {
   return (neuron0x1d8d1470()*-0.780656);
}

double NNIdClass::synapse0x3d24e60() {
   return (neuron0x1d94d1c0()*0.0188012);
}

double NNIdClass::synapse0x3d24ea0() {
   return (neuron0x1d94e260()*-0.424535);
}

double NNIdClass::synapse0x3d24ee0() {
   return (neuron0x1d94f300()*-0.829044);
}

double NNIdClass::synapse0x3d24f20() {
   return (neuron0x1d9503a0()*0.280706);
}

double NNIdClass::synapse0x3d24f60() {
   return (neuron0x3d255f0()*0.338167);
}

double NNIdClass::synapse0x3d24fa0() {
   return (neuron0x3d26590()*-0.137157);
}

double NNIdClass::synapse0x3d24fe0() {
   return (neuron0x1d8e4810()*0.507917);
}

double NNIdClass::synapse0x3d25020() {
   return (neuron0x1d8e58b0()*0.0357428);
}

double NNIdClass::synapse0x1d905ad0() {
   return (neuron0x1d8e9030()*-0.672802);
}

double NNIdClass::synapse0x1d908c70() {
   return (neuron0x1d903a50()*-0.968674);
}

double NNIdClass::synapse0x1d908cb0() {
   return (neuron0x1d904740()*0.374332);
}

double NNIdClass::synapse0x1d8c8fd0() {
   return (neuron0x1d9057e0()*-0.103441);
}

double NNIdClass::synapse0x1d8c9010() {
   return (neuron0x1d906880()*0.140574);
}

double NNIdClass::synapse0x1d8d1720() {
   return (neuron0x1d907920()*-0.254736);
}

double NNIdClass::synapse0x1d8d1760() {
   return (neuron0x1d9089c0()*0.225552);
}

double NNIdClass::synapse0x3d25390() {
   return (neuron0x1d8c8d20()*-3.22703);
}

double NNIdClass::synapse0x3d253d0() {
   return (neuron0x1d8c9ba0()*0.721978);
}

double NNIdClass::synapse0x3d25410() {
   return (neuron0x1d8db840()*-0.120544);
}

double NNIdClass::synapse0x3d25450() {
   return (neuron0x1d8cb3a0()*-0.98394);
}

double NNIdClass::synapse0x3d25490() {
   return (neuron0x1d8cdb90()*1.18297);
}

double NNIdClass::synapse0x3d254d0() {
   return (neuron0x1d8ceb30()*-0.505317);
}

double NNIdClass::synapse0x3d25510() {
   return (neuron0x1d8d0490()*0.88966);
}

double NNIdClass::synapse0x3d25550() {
   return (neuron0x1d8d1470()*-1.1277);
}

double NNIdClass::synapse0x3d25590() {
   return (neuron0x1d94d1c0()*-1.18084);
}

double NNIdClass::synapse0x1dc484c0() {
   return (neuron0x1d94e260()*0.684663);
}

double NNIdClass::synapse0x1dc48500() {
   return (neuron0x1d94f300()*-0.606396);
}

double NNIdClass::synapse0x1dc48540() {
   return (neuron0x1d9503a0()*1.38157);
}

double NNIdClass::synapse0x1dc48580() {
   return (neuron0x3d255f0()*2.85302);
}

double NNIdClass::synapse0x1dc485c0() {
   return (neuron0x3d26590()*-1.18336);
}

double NNIdClass::synapse0x1dc48600() {
   return (neuron0x1d8e4810()*1.96148);
}

double NNIdClass::synapse0x1dc48640() {
   return (neuron0x1d8e58b0()*-4.84367);
}

double NNIdClass::synapse0x3d26840() {
   return (neuron0x1d8e9030()*-2.90791);
}

double NNIdClass::synapse0x3d26880() {
   return (neuron0x1d903a50()*-0.503482);
}

double NNIdClass::synapse0x1dc48790() {
   return (neuron0x1d904740()*2.60416);
}

double NNIdClass::synapse0x1dc487d0() {
   return (neuron0x1d9057e0()*-0.560315);
}

double NNIdClass::synapse0x1dc48810() {
   return (neuron0x1d906880()*-0.655159);
}

double NNIdClass::synapse0x1dc48850() {
   return (neuron0x1d907920()*1.48614);
}

double NNIdClass::synapse0x1dc48890() {
   return (neuron0x1d9089c0()*1.56954);
}

double NNIdClass::synapse0x1dc48c10() {
   return (neuron0x1d8c8d20()*-1.01339);
}

double NNIdClass::synapse0x1dc48c50() {
   return (neuron0x1d8c9ba0()*-0.160175);
}

double NNIdClass::synapse0x1dc48c90() {
   return (neuron0x1d8db840()*-0.097467);
}

double NNIdClass::synapse0x1dc48cd0() {
   return (neuron0x1d8cb3a0()*0.200814);
}

double NNIdClass::synapse0x1dc48d10() {
   return (neuron0x1d8cdb90()*-0.306952);
}

double NNIdClass::synapse0x1dc48d50() {
   return (neuron0x1d8ceb30()*0.0854828);
}

double NNIdClass::synapse0x1dc48d90() {
   return (neuron0x1d8d0490()*-0.637668);
}

double NNIdClass::synapse0x1dc48dd0() {
   return (neuron0x1d8d1470()*-0.69665);
}

double NNIdClass::synapse0x1dc48e10() {
   return (neuron0x1d94d1c0()*0.654858);
}

double NNIdClass::synapse0x1dc48e50() {
   return (neuron0x1d94e260()*-1.01829);
}

double NNIdClass::synapse0x1dc48e90() {
   return (neuron0x1d94f300()*-0.590873);
}

double NNIdClass::synapse0x1dc48ed0() {
   return (neuron0x1d9503a0()*0.573475);
}

double NNIdClass::synapse0x1dc48f10() {
   return (neuron0x3d255f0()*0.155072);
}

double NNIdClass::synapse0x1dc48f50() {
   return (neuron0x3d26590()*-0.0173324);
}

double NNIdClass::synapse0x1dc48f90() {
   return (neuron0x1d8e4810()*-0.499656);
}

double NNIdClass::synapse0x1dc48fd0() {
   return (neuron0x1d8e58b0()*-0.172878);
}

double NNIdClass::synapse0x1dc48a60() {
   return (neuron0x1d8e9030()*-0.171557);
}

double NNIdClass::synapse0x1dc48aa0() {
   return (neuron0x1d903a50()*-0.0856857);
}

double NNIdClass::synapse0x1dc49120() {
   return (neuron0x1d904740()*0.0595361);
}

double NNIdClass::synapse0x1dc49160() {
   return (neuron0x1d9057e0()*-0.229216);
}

double NNIdClass::synapse0x1dc491a0() {
   return (neuron0x1d906880()*-0.105222);
}

double NNIdClass::synapse0x1dc491e0() {
   return (neuron0x1d907920()*-1.08307);
}

double NNIdClass::synapse0x1dc49220() {
   return (neuron0x1d9089c0()*-0.679587);
}

double NNIdClass::synapse0x1dc495a0() {
   return (neuron0x1d8c8d20()*-0.397331);
}

double NNIdClass::synapse0x1dc495e0() {
   return (neuron0x1d8c9ba0()*0.284224);
}

double NNIdClass::synapse0x1dc49620() {
   return (neuron0x1d8db840()*0.175198);
}

double NNIdClass::synapse0x1dc49660() {
   return (neuron0x1d8cb3a0()*0.372674);
}

double NNIdClass::synapse0x1dc496a0() {
   return (neuron0x1d8cdb90()*-0.228922);
}

double NNIdClass::synapse0x1dc496e0() {
   return (neuron0x1d8ceb30()*0.408899);
}

double NNIdClass::synapse0x1dc49720() {
   return (neuron0x1d8d0490()*0.02345);
}

double NNIdClass::synapse0x1dc49760() {
   return (neuron0x1d8d1470()*-0.188958);
}

double NNIdClass::synapse0x1dc497a0() {
   return (neuron0x1d94d1c0()*0.395424);
}

double NNIdClass::synapse0x1dc497e0() {
   return (neuron0x1d94e260()*-0.393387);
}

double NNIdClass::synapse0x1dc49820() {
   return (neuron0x1d94f300()*0.179991);
}

double NNIdClass::synapse0x1dc49860() {
   return (neuron0x1d9503a0()*0.0280576);
}

double NNIdClass::synapse0x1dc498a0() {
   return (neuron0x3d255f0()*-0.0432987);
}

double NNIdClass::synapse0x1dc498e0() {
   return (neuron0x3d26590()*-0.0524445);
}

double NNIdClass::synapse0x1dc49920() {
   return (neuron0x1d8e4810()*0.455548);
}

double NNIdClass::synapse0x1dc49960() {
   return (neuron0x1d8e58b0()*0.109832);
}

double NNIdClass::synapse0x1dc493f0() {
   return (neuron0x1d8e9030()*0.357949);
}

double NNIdClass::synapse0x1dc49430() {
   return (neuron0x1d903a50()*0.0655342);
}

double NNIdClass::synapse0x1dc49ab0() {
   return (neuron0x1d904740()*0.449569);
}

double NNIdClass::synapse0x1dc49af0() {
   return (neuron0x1d9057e0()*0.319225);
}

double NNIdClass::synapse0x1dc49b30() {
   return (neuron0x1d906880()*0.429172);
}

double NNIdClass::synapse0x1dc49b70() {
   return (neuron0x1d907920()*0.170016);
}

double NNIdClass::synapse0x1dc49bb0() {
   return (neuron0x1d9089c0()*-0.0628631);
}

double NNIdClass::synapse0x1dc49f30() {
   return (neuron0x1d8c8d20()*-0.464588);
}

double NNIdClass::synapse0x1dc49f70() {
   return (neuron0x1d8c9ba0()*0.177023);
}

double NNIdClass::synapse0x1dc49fb0() {
   return (neuron0x1d8db840()*0.113383);
}

double NNIdClass::synapse0x1dc49ff0() {
   return (neuron0x1d8cb3a0()*0.0821311);
}

double NNIdClass::synapse0x1dc4a030() {
   return (neuron0x1d8cdb90()*0.143025);
}

double NNIdClass::synapse0x1dc4a070() {
   return (neuron0x1d8ceb30()*-0.00440715);
}

double NNIdClass::synapse0x1dc4a0b0() {
   return (neuron0x1d8d0490()*0.0352336);
}

double NNIdClass::synapse0x1dc4a0f0() {
   return (neuron0x1d8d1470()*0.370182);
}

double NNIdClass::synapse0x1dc4a130() {
   return (neuron0x1d94d1c0()*0.571309);
}

double NNIdClass::synapse0x1dc4a170() {
   return (neuron0x1d94e260()*-0.302868);
}

double NNIdClass::synapse0x1dc4a1b0() {
   return (neuron0x1d94f300()*0.453025);
}

double NNIdClass::synapse0x1dc4a1f0() {
   return (neuron0x1d9503a0()*-0.470534);
}

double NNIdClass::synapse0x1dc4a230() {
   return (neuron0x3d255f0()*-0.148418);
}

double NNIdClass::synapse0x1dc4a270() {
   return (neuron0x3d26590()*-0.211698);
}

double NNIdClass::synapse0x1dc4a2b0() {
   return (neuron0x1d8e4810()*-0.151534);
}

double NNIdClass::synapse0x1dc4a2f0() {
   return (neuron0x1d8e58b0()*0.072137);
}

double NNIdClass::synapse0x1dc49d80() {
   return (neuron0x1d8e9030()*0.76993);
}

double NNIdClass::synapse0x1dc49dc0() {
   return (neuron0x1d903a50()*0.0186514);
}

double NNIdClass::synapse0x1dc4a440() {
   return (neuron0x1d904740()*0.154846);
}

double NNIdClass::synapse0x1dc4a480() {
   return (neuron0x1d9057e0()*0.116792);
}

double NNIdClass::synapse0x1dc4a4c0() {
   return (neuron0x1d906880()*0.403082);
}

double NNIdClass::synapse0x1dc4a500() {
   return (neuron0x1d907920()*0.0652678);
}

double NNIdClass::synapse0x1dc4a540() {
   return (neuron0x1d9089c0()*0.10957);
}

double NNIdClass::synapse0x1dc4a8c0() {
   return (neuron0x1d8c8d20()*-0.796789);
}

double NNIdClass::synapse0x1dc4a900() {
   return (neuron0x1d8c9ba0()*0.432828);
}

double NNIdClass::synapse0x1dc4a940() {
   return (neuron0x1d8db840()*-0.853961);
}

double NNIdClass::synapse0x1dc4a980() {
   return (neuron0x1d8cb3a0()*-0.249116);
}

double NNIdClass::synapse0x1dc4a9c0() {
   return (neuron0x1d8cdb90()*-1.60736);
}

double NNIdClass::synapse0x1dc4aa00() {
   return (neuron0x1d8ceb30()*0.0862274);
}

double NNIdClass::synapse0x1dc4aa40() {
   return (neuron0x1d8d0490()*1.04127);
}

double NNIdClass::synapse0x1dc4aa80() {
   return (neuron0x1d8d1470()*1.51679);
}

double NNIdClass::synapse0x1dc4aac0() {
   return (neuron0x1d94d1c0()*-1.10476);
}

double NNIdClass::synapse0x1dc4ab00() {
   return (neuron0x1d94e260()*1.54324);
}

double NNIdClass::synapse0x1dc4ab40() {
   return (neuron0x1d94f300()*1.46487);
}

double NNIdClass::synapse0x1dc4ab80() {
   return (neuron0x1d9503a0()*-0.732085);
}

double NNIdClass::synapse0x1dc4abc0() {
   return (neuron0x3d255f0()*0.802882);
}

double NNIdClass::synapse0x1dc4ac00() {
   return (neuron0x3d26590()*-0.485988);
}

double NNIdClass::synapse0x1dc4ac40() {
   return (neuron0x1d8e4810()*-0.104864);
}

double NNIdClass::synapse0x1dc4ac80() {
   return (neuron0x1d8e58b0()*0.432306);
}

double NNIdClass::synapse0x1dc4a710() {
   return (neuron0x1d8e9030()*1.10331);
}

double NNIdClass::synapse0x1dc4a750() {
   return (neuron0x1d903a50()*1.61166);
}

double NNIdClass::synapse0x1dc4add0() {
   return (neuron0x1d904740()*-0.303936);
}

double NNIdClass::synapse0x1dc4ae10() {
   return (neuron0x1d9057e0()*-1.29209);
}

double NNIdClass::synapse0x1dc4ae50() {
   return (neuron0x1d906880()*0.942188);
}

double NNIdClass::synapse0x1dc4ae90() {
   return (neuron0x1d907920()*1.11928);
}

double NNIdClass::synapse0x1dc4aed0() {
   return (neuron0x1d9089c0()*0.878318);
}

double NNIdClass::synapse0x1dc4b250() {
   return (neuron0x1d8c8d20()*-0.239948);
}

double NNIdClass::synapse0x1dc4b290() {
   return (neuron0x1d8c9ba0()*0.290295);
}

double NNIdClass::synapse0x1dc4b2d0() {
   return (neuron0x1d8db840()*0.339112);
}

double NNIdClass::synapse0x1dc4b310() {
   return (neuron0x1d8cb3a0()*-0.020651);
}

double NNIdClass::synapse0x1dc4b350() {
   return (neuron0x1d8cdb90()*0.331042);
}

double NNIdClass::synapse0x1dc4b390() {
   return (neuron0x1d8ceb30()*-0.236647);
}

double NNIdClass::synapse0x1dc4b3d0() {
   return (neuron0x1d8d0490()*0.084737);
}

double NNIdClass::synapse0x1dc4b410() {
   return (neuron0x1d8d1470()*-0.240885);
}

double NNIdClass::synapse0x1dc4b450() {
   return (neuron0x1d94d1c0()*-0.275694);
}

double NNIdClass::synapse0x1dc4b490() {
   return (neuron0x1d94e260()*-0.211588);
}

double NNIdClass::synapse0x1dc4b4d0() {
   return (neuron0x1d94f300()*0.211);
}

double NNIdClass::synapse0x1dc4b510() {
   return (neuron0x1d9503a0()*0.423713);
}

double NNIdClass::synapse0x1dc4b550() {
   return (neuron0x3d255f0()*0.0436538);
}

double NNIdClass::synapse0x1dc4b590() {
   return (neuron0x3d26590()*-0.40115);
}

double NNIdClass::synapse0x1dc4b5d0() {
   return (neuron0x1d8e4810()*0.123243);
}

double NNIdClass::synapse0x1dc4b610() {
   return (neuron0x1d8e58b0()*-0.254511);
}

double NNIdClass::synapse0x1dc4b0a0() {
   return (neuron0x1d8e9030()*-0.454883);
}

double NNIdClass::synapse0x1dc4b0e0() {
   return (neuron0x1d903a50()*-0.313024);
}

double NNIdClass::synapse0x1dc4b760() {
   return (neuron0x1d904740()*-0.401347);
}

double NNIdClass::synapse0x1dc4b7a0() {
   return (neuron0x1d9057e0()*-0.0405323);
}

double NNIdClass::synapse0x1dc4b7e0() {
   return (neuron0x1d906880()*-0.563602);
}

double NNIdClass::synapse0x1dc4b820() {
   return (neuron0x1d907920()*-0.445934);
}

double NNIdClass::synapse0x1dc4b860() {
   return (neuron0x1d9089c0()*0.558312);
}

double NNIdClass::synapse0x1dc4bbe0() {
   return (neuron0x1d8c8d20()*0.435109);
}

double NNIdClass::synapse0x1dc4bc20() {
   return (neuron0x1d8c9ba0()*0.49525);
}

double NNIdClass::synapse0x1dc4bc60() {
   return (neuron0x1d8db840()*0.563319);
}

double NNIdClass::synapse0x1dc4bca0() {
   return (neuron0x1d8cb3a0()*-0.010209);
}

double NNIdClass::synapse0x1dc4bce0() {
   return (neuron0x1d8cdb90()*-0.108368);
}

double NNIdClass::synapse0x1dc4bd20() {
   return (neuron0x1d8ceb30()*-0.00871723);
}

double NNIdClass::synapse0x1dc4bd60() {
   return (neuron0x1d8d0490()*-0.0610633);
}

double NNIdClass::synapse0x1dc4bda0() {
   return (neuron0x1d8d1470()*-0.650613);
}

double NNIdClass::synapse0x1dc4bde0() {
   return (neuron0x1d94d1c0()*0.22463);
}

double NNIdClass::synapse0x1dc4be20() {
   return (neuron0x1d94e260()*-0.00867226);
}

double NNIdClass::synapse0x1dc4be60() {
   return (neuron0x1d94f300()*0.26852);
}

double NNIdClass::synapse0x1dc4bea0() {
   return (neuron0x1d9503a0()*-0.227956);
}

double NNIdClass::synapse0x1dc4bee0() {
   return (neuron0x3d255f0()*-0.488835);
}

double NNIdClass::synapse0x1dc4bf20() {
   return (neuron0x3d26590()*-0.305037);
}

double NNIdClass::synapse0x1dc4bf60() {
   return (neuron0x1d8e4810()*-0.311303);
}

double NNIdClass::synapse0x1dc4bfa0() {
   return (neuron0x1d8e58b0()*0.217698);
}

double NNIdClass::synapse0x1dc4ba30() {
   return (neuron0x1d8e9030()*-0.282136);
}

double NNIdClass::synapse0x1dc4ba70() {
   return (neuron0x1d903a50()*-0.239651);
}

double NNIdClass::synapse0x1dc4c0f0() {
   return (neuron0x1d904740()*0.238303);
}

double NNIdClass::synapse0x1dc4c130() {
   return (neuron0x1d9057e0()*-0.205952);
}

double NNIdClass::synapse0x1dc4c170() {
   return (neuron0x1d906880()*0.105406);
}

double NNIdClass::synapse0x1dc4c1b0() {
   return (neuron0x1d907920()*-0.211632);
}

double NNIdClass::synapse0x1dc4c1f0() {
   return (neuron0x1d9089c0()*0.164234);
}

double NNIdClass::synapse0x1dc4c570() {
   return (neuron0x1d8c8d20()*0.656787);
}

double NNIdClass::synapse0x1dc4c5b0() {
   return (neuron0x1d8c9ba0()*-0.341537);
}

double NNIdClass::synapse0x1dc4c5f0() {
   return (neuron0x1d8db840()*0.166968);
}

double NNIdClass::synapse0x1dc4c630() {
   return (neuron0x1d8cb3a0()*0.287072);
}

double NNIdClass::synapse0x1dc4c670() {
   return (neuron0x1d8cdb90()*0.0477797);
}

double NNIdClass::synapse0x1dc4c6b0() {
   return (neuron0x1d8ceb30()*-0.271386);
}

double NNIdClass::synapse0x1dc4c6f0() {
   return (neuron0x1d8d0490()*0.0208384);
}

double NNIdClass::synapse0x1dc4c730() {
   return (neuron0x1d8d1470()*0.269493);
}

double NNIdClass::synapse0x1dc4c770() {
   return (neuron0x1d94d1c0()*-0.364587);
}

double NNIdClass::synapse0x1dc4c7b0() {
   return (neuron0x1d94e260()*-0.336064);
}

double NNIdClass::synapse0x1dc4c7f0() {
   return (neuron0x1d94f300()*0.0338998);
}

double NNIdClass::synapse0x1dc4c830() {
   return (neuron0x1d9503a0()*0.252926);
}

double NNIdClass::synapse0x1dc4c870() {
   return (neuron0x3d255f0()*-0.503565);
}

double NNIdClass::synapse0x1dc4c8b0() {
   return (neuron0x3d26590()*0.142659);
}

double NNIdClass::synapse0x1dc4c8f0() {
   return (neuron0x1d8e4810()*-0.0530138);
}

double NNIdClass::synapse0x1dc4c930() {
   return (neuron0x1d8e58b0()*-0.271269);
}

double NNIdClass::synapse0x1dc4c3c0() {
   return (neuron0x1d8e9030()*0.277244);
}

double NNIdClass::synapse0x1dc4c400() {
   return (neuron0x1d903a50()*0.247968);
}

double NNIdClass::synapse0x1dc4ca80() {
   return (neuron0x1d904740()*-0.279039);
}

double NNIdClass::synapse0x1dc4cac0() {
   return (neuron0x1d9057e0()*-0.282178);
}

double NNIdClass::synapse0x1dc4cb00() {
   return (neuron0x1d906880()*-0.312678);
}

double NNIdClass::synapse0x1dc4cb40() {
   return (neuron0x1d907920()*-0.0864285);
}

double NNIdClass::synapse0x1dc4cb80() {
   return (neuron0x1d9089c0()*-0.293806);
}

double NNIdClass::synapse0x1dc4cf00() {
   return (neuron0x3d236f0()*-0.00590999);
}

double NNIdClass::synapse0x1dc4cf40() {
   return (neuron0x3d23d90()*1.39999);
}

double NNIdClass::synapse0x1dc4cf80() {
   return (neuron0x3d24430()*0.336332);
}

double NNIdClass::synapse0x1dc4cfc0() {
   return (neuron0x3d24ad0()*0.696503);
}

double NNIdClass::synapse0x1dc4d000() {
   return (neuron0x3d25170()*1.10503);
}

double NNIdClass::synapse0x1dc4d040() {
   return (neuron0x1dc488d0()*-1.2627);
}

double NNIdClass::synapse0x1dc4d080() {
   return (neuron0x1dc49260()*0.0291714);
}

double NNIdClass::synapse0x1dc4d0c0() {
   return (neuron0x1dc49bf0()*0.382543);
}

double NNIdClass::synapse0x1dc4d100() {
   return (neuron0x1dc4a580()*-2.10253);
}

double NNIdClass::synapse0x1dc4d140() {
   return (neuron0x1dc4af10()*0.431459);
}

double NNIdClass::synapse0x1dc4d180() {
   return (neuron0x1dc4b8a0()*-0.274358);
}

double NNIdClass::synapse0x1dc4d1c0() {
   return (neuron0x1dc4c230()*-0.126758);
}

