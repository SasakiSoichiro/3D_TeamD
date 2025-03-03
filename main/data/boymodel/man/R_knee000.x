xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 54;
 1.26530;-13.47323;1.93932;,
 1.83473;-13.50000;-0.03798;,
 1.35622;-11.29768;-0.03798;,
 1.15973;-11.29768;1.45598;,
 1.70949;-13.60502;-0.98472;,
 1.32278;-11.29768;-1.50626;,
 -0.01875;-13.89415;-2.14512;,
 -0.01875;-11.29768;-2.12984;,
 -1.55369;-13.77459;-1.74386;,
 -1.33159;-11.29768;-1.69769;,
 -1.75732;-13.83141;-0.03798;,
 -1.55048;-11.29768;-0.03798;,
 -1.47970;-13.51467;1.75593;,
 -1.11124;-11.29768;1.62174;,
 -0.01875;-13.11187;2.40393;,
 -0.01875;-11.29768;2.10870;,
 1.26530;-13.47323;1.93932;,
 1.15973;-11.29768;1.45598;,
 1.83473;-13.50000;-0.03798;,
 1.26530;-13.47323;1.93932;,
 -0.01875;-12.73052;-0.03798;,
 1.70949;-13.60502;-0.98472;,
 -0.01875;-13.89415;-2.14512;,
 -1.55369;-13.77459;-1.74386;,
 -1.75732;-13.83141;-0.03798;,
 -1.47970;-13.51467;1.75593;,
 -0.01875;-13.11187;2.40393;,
 1.50056;-0.07649;1.62174;,
 2.21496;-0.04315;-0.03798;,
 -0.01875;-0.28705;-0.03798;,
 1.50056;-0.03622;-1.69769;,
 -0.01875;-0.05761;-2.38517;,
 -1.53808;-0.02472;-1.69769;,
 -2.03094;-0.00950;-0.03798;,
 -1.53808;-0.03618;1.69485;,
 -0.01875;-0.02324;2.37454;,
 -0.01875;-1.57163;2.29884;,
 1.50056;-1.34276;1.62174;,
 1.50056;-0.07649;1.62174;,
 -0.01875;-0.02324;2.37454;,
 -1.53808;-1.31556;1.62174;,
 -1.53808;-0.03618;1.69485;,
 -2.07945;-1.31556;-0.03798;,
 -2.03094;-0.00950;-0.03798;,
 -1.53808;-1.31556;-1.69769;,
 -1.53808;-0.02472;-1.69769;,
 -0.01875;-0.63535;-2.16247;,
 -0.01875;-0.05761;-2.38517;,
 1.50056;-0.90162;-1.69769;,
 1.50056;-0.03622;-1.69769;,
 2.12988;-1.07733;-0.03798;,
 2.21496;-0.04315;-0.03798;,
 1.50056;-1.34276;1.62174;,
 1.50056;-0.07649;1.62174;;
 
 40;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 3;18,19,20;,
 3;21,18,20;,
 3;22,21,20;,
 3;23,22,20;,
 3;24,23,20;,
 3;25,24,20;,
 3;26,25,20;,
 3;19,26,20;,
 3;27,28,29;,
 3;28,30,29;,
 3;30,31,29;,
 3;31,32,29;,
 3;32,33,29;,
 3;33,34,29;,
 3;34,35,29;,
 3;35,27,29;,
 4;36,37,38,39;,
 4;40,36,39,41;,
 4;42,40,41,43;,
 4;44,42,43,45;,
 4;46,44,45,47;,
 4;48,46,47,49;,
 4;50,48,49,51;,
 4;52,50,51,53;,
 4;15,17,37,36;,
 4;13,15,36,40;,
 4;11,13,40,42;,
 4;9,11,42,44;,
 4;7,9,44,46;,
 4;5,7,46,48;,
 4;2,5,48,50;,
 4;3,2,50,52;;
 
 MeshMaterialList {
  6;
  40;
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "thumbnail.png";
   }
  }
  Material {
   0.800000;0.640000;0.416000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.192000;0.128000;0.040000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "ae063f068012f22dbb100fab5c95732e.jpg";
   }
  }
  Material {
   0.240000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Desktop\\���앨\\Maya obj��p\\ae063f068012f22dbb100fab5c95732e.jpg";
   }
  }
 }
 MeshNormals {
  52;
  0.776427;0.188185;0.601455;,
  0.982976;0.174388;0.057846;,
  0.836770;0.081010;-0.541529;,
  0.116593;-0.010743;-0.993122;,
  -0.281406;0.023025;-0.959313;,
  -0.993458;0.108050;0.036956;,
  -0.776928;0.147519;0.612063;,
  0.009185;0.174715;0.984576;,
  -0.063879;0.995649;-0.067838;,
  -0.108537;0.994019;0.012041;,
  -0.083220;0.993779;0.074009;,
  0.003752;0.995249;0.097286;,
  0.101118;0.992791;0.064353;,
  0.136639;0.990613;0.003937;,
  0.088549;0.993866;-0.066247;,
  0.010561;0.994019;-0.108697;,
  0.027375;-0.993043;0.114527;,
  0.010687;0.999942;0.001113;,
  0.754223;-0.037268;0.655560;,
  0.015938;-0.030753;0.999400;,
  -0.751378;-0.028032;0.659277;,
  -0.999796;-0.014021;0.014567;,
  -0.732110;-0.054061;-0.679038;,
  0.014542;-0.094501;-0.995419;,
  0.730387;-0.075409;-0.678858;,
  0.998826;-0.047185;0.010987;,
  0.783815;0.072972;0.616692;,
  0.015629;0.076489;0.996948;,
  -0.767902;0.055811;0.638132;,
  -0.998831;0.033834;0.034516;,
  -0.291755;0.009165;-0.956449;,
  0.072520;-0.010179;-0.997315;,
  0.803701;0.022742;-0.594598;,
  0.997240;0.061841;0.041091;,
  -0.988701;0.085892;-0.122853;,
  -0.984678;0.025242;-0.172547;,
  -0.383283;-0.923231;0.027189;,
  -0.349451;-0.928977;-0.122009;,
  -0.282514;-0.904424;0.319693;,
  -0.059047;-0.873862;0.482575;,
  0.313605;-0.909095;0.274224;,
  0.534286;-0.843766;0.050972;,
  0.433568;-0.900215;-0.040405;,
  0.003127;-0.988019;-0.154298;,
  0.727213;-0.032196;0.685656;,
  0.009975;-0.038856;0.999195;,
  -0.750581;-0.021119;0.660441;,
  -0.999892;0.014382;-0.002930;,
  -0.727924;-0.083897;-0.680506;,
  -0.000580;-0.179299;-0.983794;,
  0.695145;-0.112673;-0.709984;,
  0.999156;-0.041016;-0.002269;;
  40;
  4;0,1,33,26;,
  4;1,2,32,33;,
  4;2,3,31,32;,
  4;3,4,30,31;,
  4;34,5,29,35;,
  4;5,6,28,29;,
  4;6,7,27,28;,
  4;7,0,26,27;,
  3;36,37,16;,
  3;38,36,16;,
  3;39,38,16;,
  3;40,39,16;,
  3;41,40,16;,
  3;42,41,16;,
  3;43,42,16;,
  3;37,43,16;,
  3;8,9,17;,
  3;9,10,17;,
  3;10,11,17;,
  3;11,12,17;,
  3;12,13,17;,
  3;13,14,17;,
  3;14,15,17;,
  3;15,8,17;,
  4;19,18,44,45;,
  4;20,19,45,46;,
  4;21,20,46,47;,
  4;22,21,47,48;,
  4;23,22,48,49;,
  4;24,23,49,50;,
  4;25,24,50,51;,
  4;18,25,51,44;,
  4;27,26,18,19;,
  4;28,27,19,20;,
  4;29,28,20,21;,
  4;35,29,21,22;,
  4;31,30,22,23;,
  4;32,31,23,24;,
  4;33,32,24,25;,
  4;26,33,25,18;;
 }
 MeshTextureCoords {
  54;
  0.375000;0.312500;,
  0.406250;0.312500;,
  0.406250;0.354020;,
  0.375000;0.354020;,
  0.437500;0.312500;,
  0.437500;0.354020;,
  0.468750;0.312500;,
  0.468750;0.354020;,
  0.500000;0.312500;,
  0.500000;0.354020;,
  0.531250;0.312500;,
  0.531250;0.354020;,
  0.562500;0.312500;,
  0.562500;0.354020;,
  0.593750;0.312500;,
  0.593750;0.354020;,
  0.625000;0.312500;,
  0.625000;0.354020;,
  0.500000;0.000000;,
  0.610490;0.045770;,
  0.500000;0.156250;,
  0.389520;0.045770;,
  0.343750;0.156250;,
  0.389520;0.266730;,
  0.500000;0.312500;,
  0.610490;0.266730;,
  0.656250;0.156250;,
  0.610490;0.954240;,
  0.500000;1.000000;,
  0.500000;0.843750;,
  0.389520;0.954240;,
  0.343750;0.843750;,
  0.389520;0.733260;,
  0.500000;0.687500;,
  0.610490;0.733260;,
  0.656250;0.843750;,
  0.593750;0.513230;,
  0.625000;0.513230;,
  0.625000;0.687500;,
  0.593750;0.687500;,
  0.562500;0.513230;,
  0.562500;0.687500;,
  0.531250;0.513230;,
  0.531250;0.687500;,
  0.500000;0.513230;,
  0.500000;0.687500;,
  0.468750;0.513230;,
  0.468750;0.687500;,
  0.437500;0.513230;,
  0.437500;0.687500;,
  0.406250;0.513230;,
  0.406250;0.687500;,
  0.375000;0.513230;,
  0.375000;0.687500;;
 }
}
