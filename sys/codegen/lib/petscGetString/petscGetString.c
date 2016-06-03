#include "petscGetString.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_char(const emxArray_uint8_T *varargin_1, emxArray_char_T *y);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_char(const emxArray_uint8_T *varargin_1, emxArray_char_T *y)
{
  unsigned int uv0[2];
  int i1;
  int loop_ub;
  for (i1 = 0; i1 < 2; i1++) {
    uv0[i1] = (unsigned int)varargin_1->size[i1];
  }

  i1 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)uv0[1];
  emxEnsureCapacity((emxArray__common *)y, i1, (int)sizeof(char));
  loop_ub = (int)uv0[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    y->data[i1] = (signed char)varargin_1->data[i1];
  }
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("petscGetNum:UnknownConstant", "Unknonw constant %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void petscGetString(const emxArray_char_T *name, emxArray_char_T *str, boolean_T
                    *toplevel)
{
  boolean_T b_bool;
  int empty;
  int exitg178;
  static const char cv0[17] = { 'P', 'E', 'T', 'S', 'C', '_', 'N', 'U', 'L', 'L',
    '_', 'S', 'T', 'R', 'I', 'N', 'G' };

  emxArray_char_T *b_str;
  emxArray_uint8_T *str1;
  int exitg177;
  emxArray_char_T *b_name;
  const char * c_str;
  static const char cv1[7] = { 'M', 'A', 'T', 'S', 'A', 'M', 'E' };

  int i0;
  int exitg176;
  int n;
  static const char cv2[7] = { 'M', 'A', 'T', 'M', 'A', 'I', 'J' };

  int exitg175;
  static const char cv3[10] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'M', 'A', 'I', 'J'
  };

  char * ptr;
  int exitg174;
  char y[2];
  static const char cv4[10] = { 'M', 'A', 'T', 'M', 'P', 'I', 'M', 'A', 'I', 'J'
  };

  int exitg173;
  static const char cv5[5] = { 'M', 'A', 'T', 'I', 'S' };

  int exitg172;
  static const char cv6[6] = { 'M', 'A', 'T', 'A', 'I', 'J' };

  int exitg171;
  static const char cv7[9] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J' };

  int exitg170;
  static const char cv8[9] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J' };

  int exitg169;
  static const char cv9[9] = { 'M', 'A', 'T', 'A', 'I', 'J', 'C', 'R', 'L' };

  int exitg168;
  static const char cv10[12] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'C', 'R', 'L' };

  int exitg167;
  static const char cv11[12] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'C', 'R', 'L' };

  int exitg166;
  static const char cv12[10] = { 'M', 'A', 'T', 'A', 'I', 'J', 'C', 'U', 'S',
    'P' };

  int exitg165;
  static const char cv13[13] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'C', 'U', 'S', 'P' };

  int exitg164;
  static const char cv14[13] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'C', 'U', 'S', 'P' };

  int exitg163;
  static const char cv15[14] = { 'M', 'A', 'T', 'A', 'I', 'J', 'C', 'U', 'S',
    'P', 'A', 'R', 'S', 'E' };

  int exitg162;
  static const char cv16[17] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'C', 'U', 'S', 'P', 'A', 'R', 'S', 'E' };

  int exitg161;
  static const char cv17[17] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'C', 'U', 'S', 'P', 'A', 'R', 'S', 'E' };

  int exitg160;
  static const char cv18[14] = { 'M', 'A', 'T', 'A', 'I', 'J', 'V', 'I', 'E',
    'N', 'N', 'A', 'C', 'L' };

  int exitg159;
  static const char cv19[17] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'V', 'I', 'E', 'N', 'N', 'A', 'C', 'L' };

  int exitg158;
  static const char cv20[17] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'V', 'I', 'E', 'N', 'N', 'A', 'C', 'L' };

  int exitg157;
  static const char cv21[10] = { 'M', 'A', 'T', 'A', 'I', 'J', 'P', 'E', 'R',
    'M' };

  int exitg156;
  static const char cv22[13] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'P', 'E', 'R', 'M' };

  int exitg155;
  static const char cv23[13] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'P', 'E', 'R', 'M' };

  int exitg154;
  static const char cv24[8] = { 'M', 'A', 'T', 'S', 'H', 'E', 'L', 'L' };

  int exitg153;
  static const char cv25[8] = { 'M', 'A', 'T', 'D', 'E', 'N', 'S', 'E' };

  int exitg152;
  static const char cv26[11] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'D', 'E', 'N',
    'S', 'E' };

  int exitg151;
  static const char cv27[11] = { 'M', 'A', 'T', 'M', 'P', 'I', 'D', 'E', 'N',
    'S', 'E' };

  int exitg150;
  static const char cv28[12] = { 'M', 'A', 'T', 'E', 'L', 'E', 'M', 'E', 'N',
    'T', 'A', 'L' };

  int exitg149;
  static const char cv29[7] = { 'M', 'A', 'T', 'B', 'A', 'I', 'J' };

  int exitg148;
  static const char cv30[10] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'B', 'A', 'I',
    'J' };

  int exitg147;
  static const char cv31[10] = { 'M', 'A', 'T', 'M', 'P', 'I', 'B', 'A', 'I',
    'J' };

  int exitg146;
  static const char cv32[9] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'D', 'J' };

  int exitg145;
  static const char cv33[8] = { 'M', 'A', 'T', 'S', 'B', 'A', 'I', 'J' };

  int exitg144;
  static const char cv34[11] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'S', 'B', 'A',
    'I', 'J' };

  int exitg143;
  static const char cv35[11] = { 'M', 'A', 'T', 'M', 'P', 'I', 'S', 'B', 'A',
    'I', 'J' };

  int exitg142;
  static const char cv36[11] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'B', 'S', 'T',
    'R', 'M' };

  int exitg141;
  static const char cv37[11] = { 'M', 'A', 'T', 'M', 'P', 'I', 'B', 'S', 'T',
    'R', 'M' };

  int exitg140;
  static const char cv38[8] = { 'M', 'A', 'T', 'B', 'S', 'T', 'R', 'M' };

  int exitg139;
  static const char cv39[12] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'S', 'B', 'S',
    'T', 'R', 'M' };

  int exitg138;
  static const char cv40[12] = { 'M', 'A', 'T', 'M', 'P', 'I', 'S', 'B', 'S',
    'T', 'R', 'M' };

  int exitg137;
  static const char cv41[9] = { 'M', 'A', 'T', 'S', 'B', 'S', 'T', 'R', 'M' };

  int exitg136;
  static const char cv42[7] = { 'M', 'A', 'T', 'D', 'A', 'A', 'D' };

  int exitg135;
  static const char cv43[7] = { 'M', 'A', 'T', 'M', 'F', 'F', 'D' };

  int exitg134;
  static const char cv44[9] = { 'M', 'A', 'T', 'N', 'O', 'R', 'M', 'A', 'L' };

  int exitg133;
  static const char cv45[18] = { 'M', 'A', 'T', 'N', 'O', 'R', 'M', 'A', 'L',
    'H', 'E', 'R', 'M', 'I', 'T', 'I', 'A', 'N' };

  int exitg132;
  static const char cv46[6] = { 'M', 'A', 'T', 'L', 'R', 'C' };

  int exitg131;
  static const char cv47[10] = { 'M', 'A', 'T', 'S', 'C', 'A', 'T', 'T', 'E',
    'R' };

  int exitg130;
  static const char cv48[11] = { 'M', 'A', 'T', 'B', 'L', 'O', 'C', 'K', 'M',
    'A', 'T' };

  int exitg129;
  static const char cv49[12] = { 'M', 'A', 'T', 'C', 'O', 'M', 'P', 'O', 'S',
    'I', 'T', 'E' };

  int exitg128;
  static const char cv50[6] = { 'M', 'A', 'T', 'F', 'F', 'T' };

  int exitg127;
  static const char cv51[7] = { 'M', 'A', 'T', 'F', 'F', 'T', 'W' };

  int exitg126;
  static const char cv52[11] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'C', 'U', 'F',
    'F', 'T' };

  int exitg125;
  static const char cv53[15] = { 'M', 'A', 'T', 'T', 'R', 'A', 'N', 'S', 'P',
    'O', 'S', 'E', 'M', 'A', 'T' };

  int exitg124;
  static const char cv54[18] = { 'M', 'A', 'T', 'S', 'C', 'H', 'U', 'R', 'C',
    'O', 'M', 'P', 'L', 'E', 'M', 'E', 'N', 'T' };

  int exitg123;
  static const char cv55[9] = { 'M', 'A', 'T', 'P', 'Y', 'T', 'H', 'O', 'N' };

  int exitg122;
  static const char cv56[14] = { 'M', 'A', 'T', 'H', 'Y', 'P', 'R', 'E', 'S',
    'T', 'R', 'U', 'C', 'T' };

  int exitg121;
  static const char cv57[15] = { 'M', 'A', 'T', 'H', 'Y', 'P', 'R', 'E', 'S',
    'S', 'T', 'R', 'U', 'C', 'T' };

  int exitg120;
  static const char cv58[12] = { 'M', 'A', 'T', 'S', 'U', 'B', 'M', 'A', 'T',
    'R', 'I', 'X' };

  int exitg119;
  static const char cv59[11] = { 'M', 'A', 'T', 'L', 'O', 'C', 'A', 'L', 'R',
    'E', 'F' };

  int exitg118;
  static const char cv60[7] = { 'M', 'A', 'T', 'N', 'E', 'S', 'T' };

  int exitg117;
  static const char cv61[15] = { 'M', 'A', 'T', 'P', 'R', 'E', 'A', 'L', 'L',
    'O', 'C', 'A', 'T', 'O', 'R' };

  int exitg116;
  static const char cv62[6] = { 'V', 'E', 'C', 'S', 'E', 'Q' };

  int exitg115;
  static const char cv63[6] = { 'V', 'E', 'C', 'M', 'P', 'I' };

  int exitg114;
  static const char cv64[11] = { 'V', 'E', 'C', 'S', 'T', 'A', 'N', 'D', 'A',
    'R', 'D' };

  int exitg113;
  static const char cv65[9] = { 'V', 'E', 'C', 'S', 'H', 'A', 'R', 'E', 'D' };

  int exitg112;
  static const char cv66[10] = { 'V', 'E', 'C', 'S', 'E', 'Q', 'C', 'U', 'S',
    'P' };

  int exitg111;
  static const char cv67[10] = { 'V', 'E', 'C', 'M', 'P', 'I', 'C', 'U', 'S',
    'P' };

  int exitg110;
  static const char cv68[7] = { 'V', 'E', 'C', 'C', 'U', 'S', 'P' };

  int exitg109;
  static const char cv69[14] = { 'V', 'E', 'C', 'S', 'E', 'Q', 'V', 'I', 'E',
    'N', 'N', 'A', 'C', 'L' };

  int exitg108;
  static const char cv70[14] = { 'V', 'E', 'C', 'M', 'P', 'I', 'V', 'I', 'E',
    'N', 'N', 'A', 'C', 'L' };

  int exitg107;
  static const char cv71[11] = { 'V', 'E', 'C', 'V', 'I', 'E', 'N', 'N', 'A',
    'C', 'L' };

  int exitg106;
  static const char cv72[10] = { 'V', 'E', 'C', 'S', 'E', 'Q', 'C', 'U', 'D',
    'A' };

  int exitg105;
  static const char cv73[10] = { 'V', 'E', 'C', 'M', 'P', 'I', 'C', 'U', 'D',
    'A' };

  int exitg104;
  static const char cv74[7] = { 'V', 'E', 'C', 'C', 'U', 'D', 'A' };

  int exitg103;
  static const char cv75[7] = { 'V', 'E', 'C', 'N', 'E', 'S', 'T' };

  int exitg102;
  static const char cv76[13] = { 'K', 'S', 'P', 'R', 'I', 'C', 'H', 'A', 'R',
    'D', 'S', 'O', 'N' };

  int exitg101;
  static const char cv77[12] = { 'K', 'S', 'P', 'C', 'H', 'E', 'B', 'Y', 'S',
    'H', 'E', 'V' };

  int exitg100;
  static const char cv78[5] = { 'K', 'S', 'P', 'C', 'G' };

  int exitg99;
  static const char cv79[10] = { 'K', 'S', 'P', 'G', 'R', 'O', 'P', 'P', 'C',
    'G' };

  int exitg98;
  static const char cv80[9] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'C', 'G' };

  int exitg97;
  static const char cv81[11] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'C', 'G',
    'R', 'R' };

  int exitg96;
  static const char cv82[7] = { 'K', 'S', 'P', 'C', 'G', 'N', 'E' };

  int exitg95;
  static const char cv83[7] = { 'K', 'S', 'P', 'N', 'A', 'S', 'H' };

  int exitg94;
  static const char cv84[7] = { 'K', 'S', 'P', 'S', 'T', 'C', 'G' };

  int exitg93;
  static const char cv85[7] = { 'K', 'S', 'P', 'G', 'L', 'T', 'R' };

  int exitg92;
  static const char cv86[6] = { 'K', 'S', 'P', 'F', 'C', 'G' };

  int exitg91;
  static const char cv87[10] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'F', 'C',
    'G' };

  int exitg90;
  static const char cv88[8] = { 'K', 'S', 'P', 'G', 'M', 'R', 'E', 'S' };

  int exitg89;
  static const char cv89[13] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'F', 'G',
    'M', 'R', 'E', 'S' };

  int exitg88;
  static const char cv90[9] = { 'K', 'S', 'P', 'F', 'G', 'M', 'R', 'E', 'S' };

  int exitg87;
  static const char cv91[9] = { 'K', 'S', 'P', 'L', 'G', 'M', 'R', 'E', 'S' };

  int exitg86;
  static const char cv92[9] = { 'K', 'S', 'P', 'D', 'G', 'M', 'R', 'E', 'S' };

  int exitg85;
  static const char cv93[9] = { 'K', 'S', 'P', 'P', 'G', 'M', 'R', 'E', 'S' };

  int exitg84;
  static const char cv94[8] = { 'K', 'S', 'P', 'T', 'C', 'Q', 'M', 'R' };

  int exitg83;
  static const char cv95[7] = { 'K', 'S', 'P', 'B', 'C', 'G', 'S' };

  int exitg82;
  static const char cv96[8] = { 'K', 'S', 'P', 'I', 'B', 'C', 'G', 'S' };

  int exitg81;
  static const char cv97[8] = { 'K', 'S', 'P', 'F', 'B', 'C', 'G', 'S' };

  int exitg80;
  static const char cv98[9] = { 'K', 'S', 'P', 'F', 'B', 'C', 'G', 'S', 'R' };

  int exitg79;
  static const char cv99[8] = { 'K', 'S', 'P', 'B', 'C', 'G', 'S', 'L' };

  int exitg78;
  static const char cv100[6] = { 'K', 'S', 'P', 'C', 'G', 'S' };

  int exitg77;
  static const char cv101[8] = { 'K', 'S', 'P', 'T', 'F', 'Q', 'M', 'R' };

  int exitg76;
  static const char cv102[5] = { 'K', 'S', 'P', 'C', 'R' };

  int exitg75;
  static const char cv103[9] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'C', 'R' };

  int exitg74;
  static const char cv104[7] = { 'K', 'S', 'P', 'L', 'S', 'Q', 'R' };

  int exitg73;
  static const char cv105[10] = { 'K', 'S', 'P', 'P', 'R', 'E', 'O', 'N', 'L',
    'Y' };

  int exitg72;
  static const char cv106[6] = { 'K', 'S', 'P', 'Q', 'C', 'G' };

  int exitg71;
  static const char cv107[7] = { 'K', 'S', 'P', 'B', 'I', 'C', 'G' };

  int exitg70;
  static const char cv108[9] = { 'K', 'S', 'P', 'M', 'I', 'N', 'R', 'E', 'S' };

  int exitg69;
  static const char cv109[9] = { 'K', 'S', 'P', 'S', 'Y', 'M', 'M', 'L', 'Q' };

  int exitg68;
  static const char cv110[6] = { 'K', 'S', 'P', 'L', 'C', 'D' };

  int exitg67;
  static const char cv111[9] = { 'K', 'S', 'P', 'P', 'Y', 'T', 'H', 'O', 'N' };

  int exitg66;
  static const char cv112[6] = { 'K', 'S', 'P', 'G', 'C', 'R' };

  int exitg65;
  static const char cv113[10] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'G', 'C',
    'R' };

  int exitg64;
  static const char cv114[8] = { 'K', 'S', 'P', 'T', 'S', 'I', 'R', 'M' };

  int exitg63;
  static const char cv115[7] = { 'K', 'S', 'P', 'C', 'G', 'L', 'S' };

  int exitg62;
  static const char cv116[6] = { 'P', 'C', 'N', 'O', 'N', 'E' };

  int exitg61;
  static const char cv117[8] = { 'P', 'C', 'J', 'A', 'C', 'O', 'B', 'I' };

  int exitg60;
  static const char cv118[5] = { 'P', 'C', 'S', 'O', 'R' };

  int exitg59;
  static const char cv119[4] = { 'P', 'C', 'L', 'U' };

  int exitg58;
  static const char cv120[7] = { 'P', 'C', 'S', 'H', 'E', 'L', 'L' };

  int exitg57;
  static const char cv121[9] = { 'P', 'C', 'B', 'J', 'A', 'C', 'O', 'B', 'I' };

  int exitg56;
  static const char cv122[4] = { 'P', 'C', 'M', 'G' };

  int exitg55;
  static const char cv123[11] = { 'P', 'C', 'E', 'I', 'S', 'E', 'N', 'S', 'T',
    'A', 'T' };

  int exitg54;
  static const char cv124[5] = { 'P', 'C', 'I', 'L', 'U' };

  int exitg53;
  static const char cv125[5] = { 'P', 'C', 'I', 'C', 'C' };

  int exitg52;
  static const char cv126[5] = { 'P', 'C', 'A', 'S', 'M' };

  int exitg51;
  static const char cv127[6] = { 'P', 'C', 'G', 'A', 'S', 'M' };

  int exitg50;
  static const char cv128[5] = { 'P', 'C', 'K', 'S', 'P' };

  int exitg49;
  static const char cv129[11] = { 'P', 'C', 'C', 'O', 'M', 'P', 'O', 'S', 'I',
    'T', 'E' };

  int exitg48;
  static const char cv130[11] = { 'P', 'C', 'R', 'E', 'D', 'U', 'N', 'D', 'A',
    'N', 'T' };

  int exitg47;
  static const char cv131[6] = { 'P', 'C', 'S', 'P', 'A', 'I' };

  int exitg46;
  static const char cv132[4] = { 'P', 'C', 'N', 'N' };

  int exitg45;
  static const char cv133[10] = { 'P', 'C', 'C', 'H', 'O', 'L', 'E', 'S', 'K',
    'Y' };

  int exitg44;
  static const char cv134[10] = { 'P', 'C', 'P', 'B', 'J', 'A', 'C', 'O', 'B',
    'I' };

  int exitg43;
  static const char cv135[5] = { 'P', 'C', 'M', 'A', 'T' };

  int exitg42;
  static const char cv136[7] = { 'P', 'C', 'H', 'Y', 'P', 'R', 'E' };

  int exitg41;
  static const char cv137[7] = { 'P', 'C', 'P', 'A', 'R', 'M', 'S' };

  int exitg40;
  static const char cv138[12] = { 'P', 'C', 'F', 'I', 'E', 'L', 'D', 'S', 'P',
    'L', 'I', 'T' };

  int exitg39;
  static const char cv139[5] = { 'P', 'C', 'T', 'F', 'S' };

  int exitg38;
  static const char cv140[4] = { 'P', 'C', 'M', 'L' };

  int exitg37;
  static const char cv141[10] = { 'P', 'C', 'G', 'A', 'L', 'E', 'R', 'K', 'I',
    'N' };

  int exitg36;
  static const char cv142[8] = { 'P', 'C', 'E', 'X', 'O', 'T', 'I', 'C' };

  int exitg35;
  static const char cv143[4] = { 'P', 'C', 'C', 'P' };

  int exitg34;
  static const char cv144[6] = { 'P', 'C', 'B', 'F', 'B', 'T' };

  int exitg33;
  static const char cv145[5] = { 'P', 'C', 'L', 'S', 'C' };

  int exitg32;
  static const char cv146[8] = { 'P', 'C', 'P', 'Y', 'T', 'H', 'O', 'N' };

  int exitg31;
  static const char cv147[6] = { 'P', 'C', 'P', 'F', 'M', 'G' };

  int exitg30;
  static const char cv148[9] = { 'P', 'C', 'S', 'Y', 'S', 'P', 'F', 'M', 'G' };

  int exitg29;
  static const char cv149[14] = { 'P', 'C', 'R', 'E', 'D', 'I', 'S', 'T', 'R',
    'I', 'B', 'U', 'T', 'E' };

  int exitg28;
  static const char cv150[5] = { 'P', 'C', 'S', 'V', 'D' };

  int exitg27;
  static const char cv151[6] = { 'P', 'C', 'G', 'A', 'M', 'G' };

  int exitg26;
  static const char cv152[8] = { 'P', 'C', 'S', 'A', 'C', 'U', 'S', 'P' };

  int exitg25;
  static const char cv153[12] = { 'P', 'C', 'S', 'A', 'C', 'U', 'S', 'P', 'P',
    'O', 'L', 'Y' };

  int exitg24;
  static const char cv154[14] = { 'P', 'C', 'B', 'I', 'C', 'G', 'S', 'T', 'A',
    'B', 'C', 'U', 'S', 'P' };

  int exitg23;
  static const char cv155[10] = { 'P', 'C', 'A', 'I', 'N', 'V', 'C', 'U', 'S',
    'P' };

  int exitg22;
  static const char cv156[6] = { 'P', 'C', 'B', 'D', 'D', 'C' };

  int exitg21;
  static const char cv157[10] = { 'P', 'C', 'K', 'A', 'C', 'Z', 'M', 'A', 'R',
    'Z' };

  int exitg20;
  static const char cv158[11] = { 'P', 'C', 'T', 'E', 'L', 'E', 'S', 'C', 'O',
    'P', 'E' };

  int exitg19;
  static const char cv159[16] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'S', 'U', 'P', 'E', 'R', 'L', 'U' };

  int exitg18;
  static const char cv160[21] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'S', 'U', 'P', 'E', 'R', 'L', 'U', '_', 'D', 'I', 'S', 'T' };

  int exitg17;
  static const char cv161[16] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'U', 'M', 'F', 'P', 'A', 'C', 'K' };

  int exitg16;
  static const char cv162[16] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'C', 'H', 'O', 'L', 'M', 'O', 'D' };

  int exitg15;
  static const char cv163[15] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'C', 'L', 'I', 'Q', 'U', 'E' };

  int exitg14;
  static const char cv164[12] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'K', 'L', 'U' };

  int exitg13;
  static const char cv165[18] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'E', 'L', 'E', 'M', 'E', 'N', 'T', 'A', 'L' };

  int exitg12;
  static const char cv166[13] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'E', 'S', 'S', 'L' };

  int exitg11;
  static const char cv167[14] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'L', 'U', 'S', 'O', 'L' };

  int exitg10;
  static const char cv168[14] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'U', 'M', 'P', 'S' };

  int exitg9;
  static const char cv169[20] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'K', 'L', '_', 'P', 'A', 'R', 'D', 'I', 'S', 'O' };

  int exitg8;
  static const char cv170[21] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'K', 'L', '_', 'C', 'P', 'A', 'R', 'D', 'I', 'S', 'O' };

  int exitg7;
  static const char cv171[15] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'P', 'A', 'S', 'T', 'I', 'X' };

  int exitg6;
  static const char cv172[15] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'A', 'T', 'L', 'A', 'B' };

  int exitg5;
  static const char cv173[14] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'P', 'E', 'T', 'S', 'C' };

  int exitg4;
  static const char cv174[12] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'B', 'A', 'S' };

  int exitg3;
  static const char cv175[17] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'C', 'U', 'S', 'P', 'A', 'R', 'S', 'E' };

  int exitg2;
  static const char cv176[14] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'B', 'S', 'T', 'R', 'M' };

  int exitg1;
  static const char cv177[15] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'S', 'B', 'S', 'T', 'R', 'M' };

  b_bool = false;
  if (name->size[1] != 17) {
  } else {
    empty = 0;
    do {
      exitg178 = 0;
      if (empty + 1 < 18) {
        if (name->data[empty] != cv0[empty]) {
          exitg178 = 1;
        } else {
          empty++;
        }
      } else {
        b_bool = true;
        exitg178 = 1;
      }
    } while (exitg178 == 0);
  }

  if (b_bool) {
    empty = 0;
  } else {
    b_bool = false;
    if (name->size[1] != 7) {
    } else {
      empty = 0;
      do {
        exitg177 = 0;
        if (empty + 1 < 8) {
          if (name->data[empty] != cv1[empty]) {
            exitg177 = 1;
          } else {
            empty++;
          }
        } else {
          b_bool = true;
          exitg177 = 1;
        }
      } while (exitg177 == 0);
    }

    if (b_bool) {
      empty = 1;
    } else {
      b_bool = false;
      if (name->size[1] != 7) {
      } else {
        empty = 0;
        do {
          exitg176 = 0;
          if (empty + 1 < 8) {
            if (name->data[empty] != cv2[empty]) {
              exitg176 = 1;
            } else {
              empty++;
            }
          } else {
            b_bool = true;
            exitg176 = 1;
          }
        } while (exitg176 == 0);
      }

      if (b_bool) {
        empty = 2;
      } else {
        b_bool = false;
        if (name->size[1] != 10) {
        } else {
          empty = 0;
          do {
            exitg175 = 0;
            if (empty + 1 < 11) {
              if (name->data[empty] != cv3[empty]) {
                exitg175 = 1;
              } else {
                empty++;
              }
            } else {
              b_bool = true;
              exitg175 = 1;
            }
          } while (exitg175 == 0);
        }

        if (b_bool) {
          empty = 3;
        } else {
          b_bool = false;
          if (name->size[1] != 10) {
          } else {
            empty = 0;
            do {
              exitg174 = 0;
              if (empty + 1 < 11) {
                if (name->data[empty] != cv4[empty]) {
                  exitg174 = 1;
                } else {
                  empty++;
                }
              } else {
                b_bool = true;
                exitg174 = 1;
              }
            } while (exitg174 == 0);
          }

          if (b_bool) {
            empty = 4;
          } else {
            b_bool = false;
            if (name->size[1] != 5) {
            } else {
              empty = 0;
              do {
                exitg173 = 0;
                if (empty + 1 < 6) {
                  if (name->data[empty] != cv5[empty]) {
                    exitg173 = 1;
                  } else {
                    empty++;
                  }
                } else {
                  b_bool = true;
                  exitg173 = 1;
                }
              } while (exitg173 == 0);
            }

            if (b_bool) {
              empty = 5;
            } else {
              b_bool = false;
              if (name->size[1] != 6) {
              } else {
                empty = 0;
                do {
                  exitg172 = 0;
                  if (empty + 1 < 7) {
                    if (name->data[empty] != cv6[empty]) {
                      exitg172 = 1;
                    } else {
                      empty++;
                    }
                  } else {
                    b_bool = true;
                    exitg172 = 1;
                  }
                } while (exitg172 == 0);
              }

              if (b_bool) {
                empty = 6;
              } else {
                b_bool = false;
                if (name->size[1] != 9) {
                } else {
                  empty = 0;
                  do {
                    exitg171 = 0;
                    if (empty + 1 < 10) {
                      if (name->data[empty] != cv7[empty]) {
                        exitg171 = 1;
                      } else {
                        empty++;
                      }
                    } else {
                      b_bool = true;
                      exitg171 = 1;
                    }
                  } while (exitg171 == 0);
                }

                if (b_bool) {
                  empty = 7;
                } else {
                  b_bool = false;
                  if (name->size[1] != 9) {
                  } else {
                    empty = 0;
                    do {
                      exitg170 = 0;
                      if (empty + 1 < 10) {
                        if (name->data[empty] != cv8[empty]) {
                          exitg170 = 1;
                        } else {
                          empty++;
                        }
                      } else {
                        b_bool = true;
                        exitg170 = 1;
                      }
                    } while (exitg170 == 0);
                  }

                  if (b_bool) {
                    empty = 8;
                  } else {
                    b_bool = false;
                    if (name->size[1] != 9) {
                    } else {
                      empty = 0;
                      do {
                        exitg169 = 0;
                        if (empty + 1 < 10) {
                          if (name->data[empty] != cv9[empty]) {
                            exitg169 = 1;
                          } else {
                            empty++;
                          }
                        } else {
                          b_bool = true;
                          exitg169 = 1;
                        }
                      } while (exitg169 == 0);
                    }

                    if (b_bool) {
                      empty = 9;
                    } else {
                      b_bool = false;
                      if (name->size[1] != 12) {
                      } else {
                        empty = 0;
                        do {
                          exitg168 = 0;
                          if (empty + 1 < 13) {
                            if (name->data[empty] != cv10[empty]) {
                              exitg168 = 1;
                            } else {
                              empty++;
                            }
                          } else {
                            b_bool = true;
                            exitg168 = 1;
                          }
                        } while (exitg168 == 0);
                      }

                      if (b_bool) {
                        empty = 10;
                      } else {
                        b_bool = false;
                        if (name->size[1] != 12) {
                        } else {
                          empty = 0;
                          do {
                            exitg167 = 0;
                            if (empty + 1 < 13) {
                              if (name->data[empty] != cv11[empty]) {
                                exitg167 = 1;
                              } else {
                                empty++;
                              }
                            } else {
                              b_bool = true;
                              exitg167 = 1;
                            }
                          } while (exitg167 == 0);
                        }

                        if (b_bool) {
                          empty = 11;
                        } else {
                          b_bool = false;
                          if (name->size[1] != 10) {
                          } else {
                            empty = 0;
                            do {
                              exitg166 = 0;
                              if (empty + 1 < 11) {
                                if (name->data[empty] != cv12[empty]) {
                                  exitg166 = 1;
                                } else {
                                  empty++;
                                }
                              } else {
                                b_bool = true;
                                exitg166 = 1;
                              }
                            } while (exitg166 == 0);
                          }

                          if (b_bool) {
                            empty = 12;
                          } else {
                            b_bool = false;
                            if (name->size[1] != 13) {
                            } else {
                              empty = 0;
                              do {
                                exitg165 = 0;
                                if (empty + 1 < 14) {
                                  if (name->data[empty] != cv13[empty]) {
                                    exitg165 = 1;
                                  } else {
                                    empty++;
                                  }
                                } else {
                                  b_bool = true;
                                  exitg165 = 1;
                                }
                              } while (exitg165 == 0);
                            }

                            if (b_bool) {
                              empty = 13;
                            } else {
                              b_bool = false;
                              if (name->size[1] != 13) {
                              } else {
                                empty = 0;
                                do {
                                  exitg164 = 0;
                                  if (empty + 1 < 14) {
                                    if (name->data[empty] != cv14[empty]) {
                                      exitg164 = 1;
                                    } else {
                                      empty++;
                                    }
                                  } else {
                                    b_bool = true;
                                    exitg164 = 1;
                                  }
                                } while (exitg164 == 0);
                              }

                              if (b_bool) {
                                empty = 14;
                              } else {
                                b_bool = false;
                                if (name->size[1] != 14) {
                                } else {
                                  empty = 0;
                                  do {
                                    exitg163 = 0;
                                    if (empty + 1 < 15) {
                                      if (name->data[empty] != cv15[empty]) {
                                        exitg163 = 1;
                                      } else {
                                        empty++;
                                      }
                                    } else {
                                      b_bool = true;
                                      exitg163 = 1;
                                    }
                                  } while (exitg163 == 0);
                                }

                                if (b_bool) {
                                  empty = 15;
                                } else {
                                  b_bool = false;
                                  if (name->size[1] != 17) {
                                  } else {
                                    empty = 0;
                                    do {
                                      exitg162 = 0;
                                      if (empty + 1 < 18) {
                                        if (name->data[empty] != cv16[empty]) {
                                          exitg162 = 1;
                                        } else {
                                          empty++;
                                        }
                                      } else {
                                        b_bool = true;
                                        exitg162 = 1;
                                      }
                                    } while (exitg162 == 0);
                                  }

                                  if (b_bool) {
                                    empty = 16;
                                  } else {
                                    b_bool = false;
                                    if (name->size[1] != 17) {
                                    } else {
                                      empty = 0;
                                      do {
                                        exitg161 = 0;
                                        if (empty + 1 < 18) {
                                          if (name->data[empty] != cv17[empty])
                                          {
                                            exitg161 = 1;
                                          } else {
                                            empty++;
                                          }
                                        } else {
                                          b_bool = true;
                                          exitg161 = 1;
                                        }
                                      } while (exitg161 == 0);
                                    }

                                    if (b_bool) {
                                      empty = 17;
                                    } else {
                                      b_bool = false;
                                      if (name->size[1] != 14) {
                                      } else {
                                        empty = 0;
                                        do {
                                          exitg160 = 0;
                                          if (empty + 1 < 15) {
                                            if (name->data[empty] != cv18[empty])
                                            {
                                              exitg160 = 1;
                                            } else {
                                              empty++;
                                            }
                                          } else {
                                            b_bool = true;
                                            exitg160 = 1;
                                          }
                                        } while (exitg160 == 0);
                                      }

                                      if (b_bool) {
                                        empty = 18;
                                      } else {
                                        b_bool = false;
                                        if (name->size[1] != 17) {
                                        } else {
                                          empty = 0;
                                          do {
                                            exitg159 = 0;
                                            if (empty + 1 < 18) {
                                              if (name->data[empty] !=
                                                  cv19[empty]) {
                                                exitg159 = 1;
                                              } else {
                                                empty++;
                                              }
                                            } else {
                                              b_bool = true;
                                              exitg159 = 1;
                                            }
                                          } while (exitg159 == 0);
                                        }

                                        if (b_bool) {
                                          empty = 19;
                                        } else {
                                          b_bool = false;
                                          if (name->size[1] != 17) {
                                          } else {
                                            empty = 0;
                                            do {
                                              exitg158 = 0;
                                              if (empty + 1 < 18) {
                                                if (name->data[empty] !=
                                                    cv20[empty]) {
                                                  exitg158 = 1;
                                                } else {
                                                  empty++;
                                                }
                                              } else {
                                                b_bool = true;
                                                exitg158 = 1;
                                              }
                                            } while (exitg158 == 0);
                                          }

                                          if (b_bool) {
                                            empty = 20;
                                          } else {
                                            b_bool = false;
                                            if (name->size[1] != 10) {
                                            } else {
                                              empty = 0;
                                              do {
                                                exitg157 = 0;
                                                if (empty + 1 < 11) {
                                                  if (name->data[empty] !=
                                                      cv21[empty]) {
                                                    exitg157 = 1;
                                                  } else {
                                                    empty++;
                                                  }
                                                } else {
                                                  b_bool = true;
                                                  exitg157 = 1;
                                                }
                                              } while (exitg157 == 0);
                                            }

                                            if (b_bool) {
                                              empty = 21;
                                            } else {
                                              b_bool = false;
                                              if (name->size[1] != 13) {
                                              } else {
                                                empty = 0;
                                                do {
                                                  exitg156 = 0;
                                                  if (empty + 1 < 14) {
                                                    if (name->data[empty] !=
                                                        cv22[empty]) {
                                                      exitg156 = 1;
                                                    } else {
                                                      empty++;
                                                    }
                                                  } else {
                                                    b_bool = true;
                                                    exitg156 = 1;
                                                  }
                                                } while (exitg156 == 0);
                                              }

                                              if (b_bool) {
                                                empty = 22;
                                              } else {
                                                b_bool = false;
                                                if (name->size[1] != 13) {
                                                } else {
                                                  empty = 0;
                                                  do {
                                                    exitg155 = 0;
                                                    if (empty + 1 < 14) {
                                                      if (name->data[empty] !=
                                                          cv23[empty]) {
                                                        exitg155 = 1;
                                                      } else {
                                                        empty++;
                                                      }
                                                    } else {
                                                      b_bool = true;
                                                      exitg155 = 1;
                                                    }
                                                  } while (exitg155 == 0);
                                                }

                                                if (b_bool) {
                                                  empty = 23;
                                                } else {
                                                  b_bool = false;
                                                  if (name->size[1] != 8) {
                                                  } else {
                                                    empty = 0;
                                                    do {
                                                      exitg154 = 0;
                                                      if (empty + 1 < 9) {
                                                        if (name->data[empty] !=
                                                            cv24[empty]) {
                                                          exitg154 = 1;
                                                        } else {
                                                          empty++;
                                                        }
                                                      } else {
                                                        b_bool = true;
                                                        exitg154 = 1;
                                                      }
                                                    } while (exitg154 == 0);
                                                  }

                                                  if (b_bool) {
                                                    empty = 24;
                                                  } else {
                                                    b_bool = false;
                                                    if (name->size[1] != 8) {
                                                    } else {
                                                      empty = 0;
                                                      do {
                                                        exitg153 = 0;
                                                        if (empty + 1 < 9) {
                                                          if (name->data[empty]
                                                              != cv25[empty]) {
                                                            exitg153 = 1;
                                                          } else {
                                                            empty++;
                                                          }
                                                        } else {
                                                          b_bool = true;
                                                          exitg153 = 1;
                                                        }
                                                      } while (exitg153 == 0);
                                                    }

                                                    if (b_bool) {
                                                      empty = 25;
                                                    } else {
                                                      b_bool = false;
                                                      if (name->size[1] != 11) {
                                                      } else {
                                                        empty = 0;
                                                        do {
                                                          exitg152 = 0;
                                                          if (empty + 1 < 12) {
                                                            if (name->data[empty]
                                                                != cv26[empty])
                                                            {
                                                              exitg152 = 1;
                                                            } else {
                                                              empty++;
                                                            }
                                                          } else {
                                                            b_bool = true;
                                                            exitg152 = 1;
                                                          }
                                                        } while (exitg152 == 0);
                                                      }

                                                      if (b_bool) {
                                                        empty = 26;
                                                      } else {
                                                        b_bool = false;
                                                        if (name->size[1] != 11)
                                                        {
                                                        } else {
                                                          empty = 0;
                                                          do {
                                                            exitg151 = 0;
                                                            if (empty + 1 < 12)
                                                            {
                                                              if (name->
                                                                  data[empty] !=
                                                                  cv27[empty]) {
                                                                exitg151 = 1;
                                                              } else {
                                                                empty++;
                                                              }
                                                            } else {
                                                              b_bool = true;
                                                              exitg151 = 1;
                                                            }
                                                          } while (exitg151 == 0);
                                                        }

                                                        if (b_bool) {
                                                          empty = 27;
                                                        } else {
                                                          b_bool = false;
                                                          if (name->size[1] !=
                                                              12) {
                                                          } else {
                                                            empty = 0;
                                                            do {
                                                              exitg150 = 0;
                                                              if (empty + 1 < 13)
                                                              {
                                                                if (name->
                                                                    data[empty]
                                                                    !=
                                                                    cv28[empty])
                                                                {
                                                                  exitg150 = 1;
                                                                } else {
                                                                  empty++;
                                                                }
                                                              } else {
                                                                b_bool = true;
                                                                exitg150 = 1;
                                                              }
                                                            } while (exitg150 ==
                                                                     0);
                                                          }

                                                          if (b_bool) {
                                                            empty = 28;
                                                          } else {
                                                            b_bool = false;
                                                            if (name->size[1] !=
                                                                7) {
                                                            } else {
                                                              empty = 0;
                                                              do {
                                                                exitg149 = 0;
                                                                if (empty + 1 <
                                                                    8) {
                                                                  if (name->
                                                                      data[empty]
                                                                      !=
                                                                      cv29[empty])
                                                                  {
                                                                    exitg149 = 1;
                                                                  } else {
                                                                    empty++;
                                                                  }
                                                                } else {
                                                                  b_bool = true;
                                                                  exitg149 = 1;
                                                                }
                                                              } while (exitg149 ==
                                                                      0);
                                                            }

                                                            if (b_bool) {
                                                              empty = 29;
                                                            } else {
                                                              b_bool = false;
                                                              if (name->size[1]
                                                                  != 10) {
                                                              } else {
                                                                empty = 0;
                                                                do {
                                                                  exitg148 = 0;
                                                                  if (empty + 1 <
                                                                      11) {
                                                                    if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv30[empty])
                                                                    {
                                                                      exitg148 =
                                                                      1;
                                                                    } else {
                                                                      empty++;
                                                                    }
                                                                  } else {
                                                                    b_bool =
                                                                      true;
                                                                    exitg148 = 1;
                                                                  }
                                                                } while
                                                                      (exitg148 ==
                                                                      0);
                                                              }

                                                              if (b_bool) {
                                                                empty = 30;
                                                              } else {
                                                                b_bool = false;
                                                                if (name->size[1]
                                                                    != 10) {
                                                                } else {
                                                                  empty = 0;
                                                                  do {
                                                                    exitg147 = 0;
                                                                    if (empty +
                                                                      1 < 11) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv31[empty])
                                                                      {
                                                                      exitg147 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                    } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg147 =
                                                                      1;
                                                                    }
                                                                  } while
                                                                      (exitg147 ==
                                                                      0);
                                                                }

                                                                if (b_bool) {
                                                                  empty = 31;
                                                                } else {
                                                                  b_bool = false;
                                                                  if (name->
                                                                      size[1] !=
                                                                      9) {
                                                                  } else {
                                                                    empty = 0;
                                                                    do {
                                                                      exitg146 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv32[empty])
                                                                      {
                                                                      exitg146 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg146 =
                                                                      1;
                                                                      }
                                                                    } while
                                                                      (exitg146 ==
                                                                      0);
                                                                  }

                                                                  if (b_bool) {
                                                                    empty = 32;
                                                                  } else {
                                                                    b_bool =
                                                                      false;
                                                                    if
                                                                      (name->size
                                                                      [1] != 8)
                                                                    {
                                                                    } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg145 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv33[empty])
                                                                      {
                                                                      exitg145 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg145 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg145 ==
                                                                      0);
                                                                    }

                                                                    if (b_bool)
                                                                    {
                                                                      empty = 33;
                                                                    } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg144 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv34[empty])
                                                                      {
                                                                      exitg144 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg144 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg144 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 34;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg143 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv35[empty])
                                                                      {
                                                                      exitg143 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg143 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg143 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 35;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg142 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv36[empty])
                                                                      {
                                                                      exitg142 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg142 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg142 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 36;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg141 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv37[empty])
                                                                      {
                                                                      exitg141 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg141 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg141 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 37;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg140 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv38[empty])
                                                                      {
                                                                      exitg140 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg140 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg140 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 38;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 12)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg139 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 13)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv39[empty])
                                                                      {
                                                                      exitg139 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg139 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg139 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 39;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 12)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg138 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 13)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv40[empty])
                                                                      {
                                                                      exitg138 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg138 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg138 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 40;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg137 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv41[empty])
                                                                      {
                                                                      exitg137 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg137 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg137 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 41;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg136 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv42[empty])
                                                                      {
                                                                      exitg136 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg136 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg136 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 42;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg135 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv43[empty])
                                                                      {
                                                                      exitg135 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg135 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg135 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 43;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg134 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv44[empty])
                                                                      {
                                                                      exitg134 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg134 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg134 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 44;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 18)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg133 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 19)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv45[empty])
                                                                      {
                                                                      exitg133 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg133 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg133 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 45;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg132 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv46[empty])
                                                                      {
                                                                      exitg132 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg132 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg132 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 46;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg131 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv47[empty])
                                                                      {
                                                                      exitg131 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg131 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg131 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 47;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg130 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv48[empty])
                                                                      {
                                                                      exitg130 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg130 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg130 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 48;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 12)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg129 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 13)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv49[empty])
                                                                      {
                                                                      exitg129 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg129 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg129 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 49;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg128 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv50[empty])
                                                                      {
                                                                      exitg128 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg128 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg128 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 50;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg127 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv51[empty])
                                                                      {
                                                                      exitg127 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg127 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg127 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 51;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg126 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv52[empty])
                                                                      {
                                                                      exitg126 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg126 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg126 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 52;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 15)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg125 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 16)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv53[empty])
                                                                      {
                                                                      exitg125 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg125 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg125 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 53;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 18)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg124 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 19)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv54[empty])
                                                                      {
                                                                      exitg124 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg124 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg124 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 54;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg123 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv55[empty])
                                                                      {
                                                                      exitg123 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg123 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg123 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 55;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg122 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 15)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv56[empty])
                                                                      {
                                                                      exitg122 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg122 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg122 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 56;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 15)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg121 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 16)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv57[empty])
                                                                      {
                                                                      exitg121 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg121 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg121 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 57;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 12)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg120 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 13)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv58[empty])
                                                                      {
                                                                      exitg120 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg120 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg120 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 58;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg119 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv59[empty])
                                                                      {
                                                                      exitg119 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg119 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg119 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 59;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg118 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv60[empty])
                                                                      {
                                                                      exitg118 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg118 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg118 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 60;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 15)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg117 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 16)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv61[empty])
                                                                      {
                                                                      exitg117 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg117 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg117 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 61;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg116 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv62[empty])
                                                                      {
                                                                      exitg116 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg116 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg116 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 62;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg115 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv63[empty])
                                                                      {
                                                                      exitg115 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg115 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg115 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 63;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg114 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv64[empty])
                                                                      {
                                                                      exitg114 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg114 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg114 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 64;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg113 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv65[empty])
                                                                      {
                                                                      exitg113 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg113 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg113 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 65;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg112 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv66[empty])
                                                                      {
                                                                      exitg112 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg112 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg112 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 66;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg111 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv67[empty])
                                                                      {
                                                                      exitg111 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg111 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg111 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 67;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg110 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv68[empty])
                                                                      {
                                                                      exitg110 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg110 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg110 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 68;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg109 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 15)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv69[empty])
                                                                      {
                                                                      exitg109 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg109 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg109 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 69;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg108 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 15)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv70[empty])
                                                                      {
                                                                      exitg108 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg108 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg108 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 70;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg107 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv71[empty])
                                                                      {
                                                                      exitg107 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg107 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg107 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 71;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg106 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv72[empty])
                                                                      {
                                                                      exitg106 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg106 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg106 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 72;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg105 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv73[empty])
                                                                      {
                                                                      exitg105 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg105 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg105 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 73;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg104 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv74[empty])
                                                                      {
                                                                      exitg104 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg104 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg104 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 74;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg103 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv75[empty])
                                                                      {
                                                                      exitg103 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg103 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg103 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 75;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 13)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg102 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 14)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv76[empty])
                                                                      {
                                                                      exitg102 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg102 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg102 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 76;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 12)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg101 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 13)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv77[empty])
                                                                      {
                                                                      exitg101 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg101 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg101 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 77;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 5)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg100 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 6) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv78[empty])
                                                                      {
                                                                      exitg100 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg100 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg100 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 78;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg99 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv79[empty])
                                                                      {
                                                                      exitg99 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg99 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg99 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 79;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg98 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv80[empty])
                                                                      {
                                                                      exitg98 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg98 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg98 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 80;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg97 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv81[empty])
                                                                      {
                                                                      exitg97 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg97 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg97 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 81;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg96 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv82[empty])
                                                                      {
                                                                      exitg96 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg96 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg96 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 82;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg95 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv83[empty])
                                                                      {
                                                                      exitg95 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg95 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg95 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 83;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg94 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv84[empty])
                                                                      {
                                                                      exitg94 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg94 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg94 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 84;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg93 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv85[empty])
                                                                      {
                                                                      exitg93 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg93 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg93 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 85;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg92 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv86[empty])
                                                                      {
                                                                      exitg92 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg92 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg92 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 86;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg91 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv87[empty])
                                                                      {
                                                                      exitg91 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg91 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg91 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 87;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg90 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv88[empty])
                                                                      {
                                                                      exitg90 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg90 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg90 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 88;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 13)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg89 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 14)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv89[empty])
                                                                      {
                                                                      exitg89 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg89 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg89 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 89;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg88 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv90[empty])
                                                                      {
                                                                      exitg88 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg88 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg88 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 90;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg87 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv91[empty])
                                                                      {
                                                                      exitg87 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg87 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg87 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 91;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg86 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv92[empty])
                                                                      {
                                                                      exitg86 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg86 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg86 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 92;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg85 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv93[empty])
                                                                      {
                                                                      exitg85 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg85 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg85 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 93;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg84 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv94[empty])
                                                                      {
                                                                      exitg84 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg84 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg84 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 94;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg83 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv95[empty])
                                                                      {
                                                                      exitg83 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg83 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg83 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 95;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg82 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv96[empty])
                                                                      {
                                                                      exitg82 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg82 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg82 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 96;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg81 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv97[empty])
                                                                      {
                                                                      exitg81 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg81 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg81 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 97;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg80 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv98[empty])
                                                                      {
                                                                      exitg80 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg80 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg80 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 98;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg79 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv99[empty])
                                                                      {
                                                                      exitg79 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg79 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg79 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty = 99;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg78 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv100[empty])
                                                                      {
                                                                      exitg78 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg78 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg78 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      100;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg77 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv101[empty])
                                                                      {
                                                                      exitg77 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg77 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg77 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      101;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 5)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg76 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 6) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv102[empty])
                                                                      {
                                                                      exitg76 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg76 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg76 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      102;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg75 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv103[empty])
                                                                      {
                                                                      exitg75 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg75 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg75 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      103;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg74 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv104[empty])
                                                                      {
                                                                      exitg74 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg74 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg74 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      104;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg73 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv105[empty])
                                                                      {
                                                                      exitg73 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg73 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg73 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      105;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg72 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv106[empty])
                                                                      {
                                                                      exitg72 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg72 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg72 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      106;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg71 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv107[empty])
                                                                      {
                                                                      exitg71 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg71 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg71 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      107;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg70 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv108[empty])
                                                                      {
                                                                      exitg70 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg70 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg70 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      108;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg69 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv109[empty])
                                                                      {
                                                                      exitg69 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg69 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg69 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      109;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg68 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv110[empty])
                                                                      {
                                                                      exitg68 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg68 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg68 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      110;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg67 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv111[empty])
                                                                      {
                                                                      exitg67 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg67 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg67 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      111;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg66 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv112[empty])
                                                                      {
                                                                      exitg66 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg66 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg66 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      112;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg65 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv113[empty])
                                                                      {
                                                                      exitg65 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg65 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg65 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      113;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg64 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv114[empty])
                                                                      {
                                                                      exitg64 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg64 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg64 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      114;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg63 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv115[empty])
                                                                      {
                                                                      exitg63 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg63 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg63 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      115;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg62 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv116[empty])
                                                                      {
                                                                      exitg62 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg62 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg62 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      116;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg61 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv117[empty])
                                                                      {
                                                                      exitg61 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg61 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg61 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      117;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 5)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg60 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 6) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv118[empty])
                                                                      {
                                                                      exitg60 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg60 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg60 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      118;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 4)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg59 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 5) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv119[empty])
                                                                      {
                                                                      exitg59 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg59 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg59 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      119;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg58 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv120[empty])
                                                                      {
                                                                      exitg58 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg58 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg58 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      120;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg57 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv121[empty])
                                                                      {
                                                                      exitg57 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg57 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg57 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      121;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 4)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg56 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 5) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv122[empty])
                                                                      {
                                                                      exitg56 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg56 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg56 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      122;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg55 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv123[empty])
                                                                      {
                                                                      exitg55 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg55 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg55 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      123;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 5)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg54 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 6) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv124[empty])
                                                                      {
                                                                      exitg54 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg54 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg54 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      124;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 5)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg53 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 6) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv125[empty])
                                                                      {
                                                                      exitg53 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg53 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg53 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      125;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 5)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg52 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 6) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv126[empty])
                                                                      {
                                                                      exitg52 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg52 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg52 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      126;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg51 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv127[empty])
                                                                      {
                                                                      exitg51 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg51 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg51 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      127;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 5)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg50 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 6) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv128[empty])
                                                                      {
                                                                      exitg50 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg50 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg50 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      128;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg49 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv129[empty])
                                                                      {
                                                                      exitg49 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg49 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg49 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      129;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg48 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv130[empty])
                                                                      {
                                                                      exitg48 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg48 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg48 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      130;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg47 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv131[empty])
                                                                      {
                                                                      exitg47 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg47 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg47 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      131;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 4)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg46 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 5) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv132[empty])
                                                                      {
                                                                      exitg46 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg46 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg46 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      132;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg45 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv133[empty])
                                                                      {
                                                                      exitg45 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg45 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg45 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      133;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg44 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv134[empty])
                                                                      {
                                                                      exitg44 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg44 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg44 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      134;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 5)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg43 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 6) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv135[empty])
                                                                      {
                                                                      exitg43 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg43 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg43 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      135;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg42 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv136[empty])
                                                                      {
                                                                      exitg42 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg42 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg42 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      136;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg41 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv137[empty])
                                                                      {
                                                                      exitg41 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg41 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg41 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      137;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 12)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg40 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 13)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv138[empty])
                                                                      {
                                                                      exitg40 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg40 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg40 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      138;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 5)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg39 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 6) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv139[empty])
                                                                      {
                                                                      exitg39 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg39 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg39 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      139;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 4)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg38 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 5) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv140[empty])
                                                                      {
                                                                      exitg38 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg38 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg38 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      140;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg37 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv141[empty])
                                                                      {
                                                                      exitg37 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg37 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg37 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      141;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg36 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv142[empty])
                                                                      {
                                                                      exitg36 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg36 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg36 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      142;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 4)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg35 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 5) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv143[empty])
                                                                      {
                                                                      exitg35 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg35 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg35 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      143;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg34 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv144[empty])
                                                                      {
                                                                      exitg34 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg34 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg34 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      144;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 5)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg33 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 6) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv145[empty])
                                                                      {
                                                                      exitg33 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg33 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg33 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      145;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg32 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv146[empty])
                                                                      {
                                                                      exitg32 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg32 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg32 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      146;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg31 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv147[empty])
                                                                      {
                                                                      exitg31 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg31 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg31 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      147;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 9)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg30 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 10)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv148[empty])
                                                                      {
                                                                      exitg30 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg30 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg30 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      148;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg29 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 15)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv149[empty])
                                                                      {
                                                                      exitg29 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg29 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg29 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      149;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 5)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg28 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 6) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv150[empty])
                                                                      {
                                                                      exitg28 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg28 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg28 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      150;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg27 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv151[empty])
                                                                      {
                                                                      exitg27 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg27 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg27 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      151;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 8)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg26 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv152[empty])
                                                                      {
                                                                      exitg26 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg26 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg26 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      152;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 12)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg25 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 13)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv153[empty])
                                                                      {
                                                                      exitg25 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg25 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg25 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      153;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg24 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 15)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv154[empty])
                                                                      {
                                                                      exitg24 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg24 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg24 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      154;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg23 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv155[empty])
                                                                      {
                                                                      exitg23 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg23 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg23 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      155;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg22 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv156[empty])
                                                                      {
                                                                      exitg22 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg22 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg22 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      156;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 10)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg21 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 11)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv157[empty])
                                                                      {
                                                                      exitg21 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg21 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg21 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      157;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 11)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg20 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 12)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv158[empty])
                                                                      {
                                                                      exitg20 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg20 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg20 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      158;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 16)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg19 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 17)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv159[empty])
                                                                      {
                                                                      exitg19 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg19 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg19 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      159;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 21)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg18 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 22)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv160[empty])
                                                                      {
                                                                      exitg18 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg18 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg18 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      160;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 16)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg17 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 17)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv161[empty])
                                                                      {
                                                                      exitg17 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg17 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg17 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      161;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 16)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg16 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 17)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv162[empty])
                                                                      {
                                                                      exitg16 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg16 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg16 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      162;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 15)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg15 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 16)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv163[empty])
                                                                      {
                                                                      exitg15 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg15 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg15 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      163;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 12)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg14 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 13)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv164[empty])
                                                                      {
                                                                      exitg14 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg14 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg14 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      164;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 18)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg13 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 19)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv165[empty])
                                                                      {
                                                                      exitg13 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg13 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg13 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      165;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 13)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg12 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 14)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv166[empty])
                                                                      {
                                                                      exitg12 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg12 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg12 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      166;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg11 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 15)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv167[empty])
                                                                      {
                                                                      exitg11 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg11 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg11 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      167;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg10 =
                                                                      0;
                                                                      if (empty
                                                                      + 1 < 15)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv168[empty])
                                                                      {
                                                                      exitg10 =
                                                                      1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg10 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg10 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      168;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 20)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg9 = 0;
                                                                      if (empty
                                                                      + 1 < 21)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv169[empty])
                                                                      {
                                                                      exitg9 = 1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg9 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg9 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      169;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 21)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg8 = 0;
                                                                      if (empty
                                                                      + 1 < 22)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv170[empty])
                                                                      {
                                                                      exitg8 = 1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg8 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg8 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      170;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 15)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg7 = 0;
                                                                      if (empty
                                                                      + 1 < 16)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv171[empty])
                                                                      {
                                                                      exitg7 = 1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg7 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg7 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      171;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 15)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg6 = 0;
                                                                      if (empty
                                                                      + 1 < 16)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv172[empty])
                                                                      {
                                                                      exitg6 = 1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg6 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg6 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      172;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg5 = 0;
                                                                      if (empty
                                                                      + 1 < 15)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv173[empty])
                                                                      {
                                                                      exitg5 = 1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg5 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg5 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      173;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 12)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg4 = 0;
                                                                      if (empty
                                                                      + 1 < 13)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv174[empty])
                                                                      {
                                                                      exitg4 = 1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg4 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg4 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      174;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 17)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg3 = 0;
                                                                      if (empty
                                                                      + 1 < 18)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv175[empty])
                                                                      {
                                                                      exitg3 = 1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg3 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg3 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      175;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg2 = 0;
                                                                      if (empty
                                                                      + 1 < 15)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv176[empty])
                                                                      {
                                                                      exitg2 = 1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg2 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg2 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      176;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] != 15)
                                                                      {
                                                                      } else {
                                                                      empty = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (empty
                                                                      + 1 < 16)
                                                                      {
                                                                      if
                                                                      (name->data
                                                                      [empty] !=
                                                                      cv177[empty])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      empty++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      empty =
                                                                      177;
                                                                      } else {
                                                                      empty = -1;
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                      }
                                                                    }
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  emxInit_char_T(&b_str, 2);
  emxInit_uint8_T(&str1, 2);
  switch (empty) {
   case 0:
    c_str = (NULL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 1:
    c_str = (MATSAME);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 2:
    c_str = (MATMAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 3:
    c_str = (MATSEQMAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 4:
    c_str = (MATMPIMAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 5:
    c_str = (MATIS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 6:
    c_str = (MATAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 7:
    c_str = (MATSEQAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 8:
    c_str = (MATMPIAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 9:
    c_str = (MATMPIAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 10:
    c_str = (MATSEQAIJCRL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 11:
    c_str = (MATMPIAIJCRL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 12:
    c_str = (MATAIJCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 13:
    c_str = (MATSEQAIJCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 14:
    c_str = (MATMPIAIJCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 15:
    c_str = (MATAIJCUSPARSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 16:
    c_str = (MATSEQAIJCUSPARSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 17:
    c_str = (MATMPIAIJCUSPARSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 18:
    c_str = (MATAIJVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 19:
    c_str = (MATSEQAIJVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 20:
    c_str = (MATMPIAIJVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 21:
    c_str = (MATAIJPERM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 22:
    c_str = (MATSEQAIJPERM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 23:
    c_str = (MATMPIAIJPERM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 24:
    c_str = (MATSHELL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 25:
    c_str = (MATDENSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 26:
    c_str = (MATSEQDENSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 27:
    c_str = (MATMPIDENSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 28:
    c_str = (MATELEMENTAL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 29:
    c_str = (MATBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 30:
    c_str = (MATSEQBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 31:
    c_str = (MATMPIBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 32:
    c_str = (MATMPIADJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 33:
    c_str = (MATSBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 34:
    c_str = (MATSEQSBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 35:
    c_str = (MATMPISBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 36:
    c_str = (MATSEQBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 37:
    c_str = (MATMPIBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 38:
    c_str = (MATBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 39:
    c_str = (MATSEQSBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 40:
    c_str = (MATMPISBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 41:
    c_str = (MATSBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 42:
    c_str = (MATDAAD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 43:
    c_str = (MATMFFD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 44:
    c_str = (MATNORMAL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 45:
    c_str = (MATNORMALHERMITIAN);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 46:
    c_str = (MATLRC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 47:
    c_str = (MATSCATTER);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 48:
    c_str = (MATBLOCKMAT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 49:
    c_str = (MATCOMPOSITE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 50:
    c_str = (MATFFT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 51:
    c_str = (MATFFTW);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 52:
    c_str = (MATSEQCUFFT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 53:
    c_str = (MATTRANSPOSEMAT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 54:
    c_str = (MATSCHURCOMPLEMENT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 55:
    c_str = (MATPYTHON);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 56:
    c_str = (MATHYPRESTRUCT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 57:
    c_str = (MATHYPRESSTRUCT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 58:
    c_str = (MATSUBMATRIX);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 59:
    c_str = (MATSUBMATRIX);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 60:
    c_str = (MATNEST);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 61:
    c_str = (MATPREALLOCATOR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 62:
    c_str = (VECSEQ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 63:
    c_str = (VECMPI);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 64:
    c_str = (VECSTANDARD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 65:
    c_str = (VECSHARED);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 66:
    c_str = (VECSEQCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 67:
    c_str = (VECMPICUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 68:
    c_str = (VECCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 69:
    c_str = (VECSEQVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 70:
    c_str = (VECMPIVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 71:
    c_str = (VECVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 72:
    c_str = (VECSEQCUDA);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 73:
    c_str = (VECMPICUDA);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 74:
    c_str = (VECCUDA);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 75:
    c_str = (VECNEST);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 76:
    c_str = (KSPRICHARDSON);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 77:
    c_str = (KSPCHEBYSHEV);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 78:
    c_str = (KSPCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 79:
    c_str = (KSPGROPPCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 80:
    c_str = (KSPPIPECG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 81:
    c_str = (KSPPIPECGRR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 82:
    c_str = (KSPCGNE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 83:
    c_str = (KSPNASH);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 84:
    c_str = (KSPSTCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 85:
    c_str = (KSPGLTR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 86:
    c_str = (KSPFCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 87:
    c_str = (KSPPIPEFCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 88:
    c_str = (KSPGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 89:
    c_str = (KSPPIPEFGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 90:
    c_str = (KSPFGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 91:
    c_str = (KSPLGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 92:
    c_str = (KSPDGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 93:
    c_str = (KSPPGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 94:
    c_str = (KSPTCQMR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 95:
    c_str = (KSPBCGS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 96:
    c_str = (KSPIBCGS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 97:
    c_str = (KSPFBCGS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 98:
    c_str = (KSPFBCGSR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 99:
    c_str = (KSPBCGSL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 100:
    c_str = (KSPCGS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 101:
    c_str = (KSPTFQMR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 102:
    c_str = (KSPCR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 103:
    c_str = (KSPPIPECR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 104:
    c_str = (KSPLSQR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 105:
    c_str = (KSPPREONLY);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 106:
    c_str = (KSPQCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 107:
    c_str = (KSPBICG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 108:
    c_str = (KSPMINRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 109:
    c_str = (KSPSYMMLQ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 110:
    c_str = (KSPLCD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 111:
    c_str = (KSPPYTHON);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 112:
    c_str = (KSPGCR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 113:
    c_str = (KSPPIPEGCR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 114:
    c_str = (KSPTSIRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 115:
    c_str = (KSPCGLS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 116:
    c_str = (PCNONE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 117:
    c_str = (PCJACOBI);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 118:
    c_str = (PCSOR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 119:
    c_str = (PCLU);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 120:
    c_str = (PCSHELL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 121:
    c_str = (PCBJACOBI);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 122:
    c_str = (PCMG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 123:
    c_str = (PCEISENSTAT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 124:
    c_str = (PCILU);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 125:
    c_str = (PCICC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 126:
    c_str = (PCASM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 127:
    c_str = (PCGASM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 128:
    c_str = (PCKSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 129:
    c_str = (PCCOMPOSITE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 130:
    c_str = (PCREDUNDANT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 131:
    c_str = (PCSPAI);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 132:
    c_str = (PCNN);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 133:
    c_str = (PCCHOLESKY);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 134:
    c_str = (PCPBJACOBI);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 135:
    c_str = (PCMAT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 136:
    c_str = (PCHYPRE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 137:
    c_str = (PCPARMS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 138:
    c_str = (PCFIELDSPLIT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 139:
    c_str = (PCTFS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 140:
    c_str = (PCML);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 141:
    c_str = (PCGALERKIN);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 142:
    c_str = (PCEXOTIC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 143:
    c_str = (PCCP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 144:
    c_str = (PCBFBT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 145:
    c_str = (PCLSC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 146:
    c_str = (PCPYTHON);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 147:
    c_str = (PCPFMG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 148:
    c_str = (PCSYSPFMG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 149:
    c_str = (PCREDISTRIBUTE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 150:
    c_str = (PCSVD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 151:
    c_str = (PCGAMG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 152:
    c_str = (PCSACUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 153:
    c_str = (PCSACUSPPOLY);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 154:
    c_str = (PCBICGSTABCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 155:
    c_str = (PCAINVCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 156:
    c_str = (PCBDDC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 157:
    c_str = (PCKACZMARZ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 158:
    c_str = (PCTELESCOPE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 159:
    c_str = (MATSOLVERSUPERLU);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 160:
    c_str = (MATSOLVERSUPERLU_DIST);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 161:
    c_str = (MATSOLVERUMFPACK);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 162:
    c_str = (MATSOLVERCHOLMOD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 163:
    c_str = (MATSOLVERCLIQUE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 164:
    c_str = (MATSOLVERKLU);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 165:
    c_str = (MATSOLVERELEMENTAL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 166:
    c_str = (MATSOLVERESSL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 167:
    c_str = (MATSOLVERLUSOL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 168:
    c_str = (MATSOLVERMUMPS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 169:
    c_str = (MATSOLVERMKL_PARDISO);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 170:
    c_str = (MATSOLVERMKL_CPARDISO);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 171:
    c_str = (MATSOLVERPASTIX);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 172:
    c_str = (MATSOLVERMATLAB);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 173:
    c_str = (MATSOLVERPETSC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 174:
    c_str = (MATSOLVERBAS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 175:
    c_str = (MATSOLVERCUSPARSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 176:
    c_str = (MATSOLVERBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   case 177:
    c_str = (MATSOLVERSBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = M2C_OFFSET_PTR(ptr, 1);
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
    break;

   default:
    emxInit_char_T(&b_name, 2);
    i0 = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    b_name->size[1] = name->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_name, i0, (int)sizeof(char));
    empty = name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      b_name->data[b_name->size[0] * i0] = name->data[name->size[0] * i0];
    }

    b_name->data[b_name->size[0] * name->size[1]] = '\x00';
    m2c_error(b_name);
    y[0] = '\x00';
    y[1] = '\x01';
    i0 = str->size[0] * str->size[1];
    str->size[0] = 2;
    str->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    emxFree_char_T(&b_name);
    for (i0 = 0; i0 < 2; i0++) {
      str->data[i0] = y[i0];
    }

    *toplevel = true;
    break;
  }

  emxFree_uint8_T(&str1);
  emxFree_char_T(&b_str);
}

void petscGetString_initialize(void)
{
}

void petscGetString_terminate(void)
{
}
