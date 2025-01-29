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
 -1.74989;-14.62428;2.31261;,
 0.30480;-14.50169;2.58712;,
 1.30641;-9.67026;2.55279;,
 -0.93404;-9.57811;2.76052;,
 2.42467;-14.17216;1.95082;,
 2.91745;-9.57811;1.04932;,
 3.10312;-14.03935;-0.22278;,
 2.85951;-9.57811;-1.23083;,
 2.05241;-14.09381;-2.24649;,
 1.20623;-9.57811;-2.80217;,
 -0.11195;-14.30364;-2.93490;,
 -1.07391;-9.57811;-2.74424;,
 -2.07335;-14.58179;-1.36662;,
 -2.60074;-9.59100;-0.92297;,
 -3.46742;-14.58420;0.34978;,
 -2.79729;-9.43569;1.24481;,
 -1.74989;-14.62428;2.31261;,
 -0.93404;-9.57811;2.76052;,
 -1.03584;-4.82673;2.82012;,
 -2.64216;-4.76160;1.05731;,
 1.21423;-4.76160;2.75742;,
 2.86298;-4.76160;1.18134;,
 2.91435;-4.76160;-1.09896;,
 1.33826;-4.76160;-2.74770;,
 -0.98541;-4.87428;-2.96272;,
 -2.37935;-4.69513;-1.27903;,
 -2.64216;-4.76160;1.05731;,
 0.99344;0.54270;3.21454;,
 -1.37087;0.47593;2.51898;,
 2.70305;0.47593;1.43941;,
 3.01786;0.05533;-0.78012;,
 1.64521;-0.36527;-2.55251;,
 -0.61083;-0.53949;-2.83949;,
 -2.55540;-0.53104;-1.95103;,
 -2.11098;0.15904;0.55713;,
 -1.37087;0.47593;2.51898;,
 0.30480;-14.50169;2.58712;,
 -1.74989;-14.62428;2.31261;,
 -0.47462;-14.32291;0.23772;,
 2.42467;-14.17216;1.95082;,
 3.10312;-14.03935;-0.22278;,
 2.05241;-14.09381;-2.24649;,
 -0.11195;-14.30364;-2.93490;,
 -2.07335;-14.58179;-1.36662;,
 -3.46742;-14.58420;0.34978;,
 -1.37087;0.47593;2.51898;,
 0.99344;0.54270;3.21454;,
 0.73573;0.06513;-0.31733;,
 2.70305;0.47593;1.43941;,
 3.01786;0.05533;-0.78012;,
 1.64521;-0.36527;-2.55251;,
 -0.61083;-0.53949;-2.83949;,
 -2.55540;-0.53104;-1.95103;,
 -2.11098;0.15904;0.55713;;
 
 40;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;3,2,18,19;,
 4;2,5,20,18;,
 4;5,7,21,20;,
 4;7,9,22,21;,
 4;9,11,23,22;,
 4;11,13,24,23;,
 4;13,15,25,24;,
 4;15,17,26,25;,
 4;19,18,27,28;,
 4;18,20,29,27;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;25,26,35,34;,
 3;36,37,38;,
 3;39,36,38;,
 3;40,39,38;,
 3;41,40,38;,
 3;42,41,38;,
 3;43,42,38;,
 3;44,43,38;,
 3;37,44,38;,
 3;45,46,47;,
 3;46,48,47;,
 3;48,49,47;,
 3;49,50,47;,
 3;50,51,47;,
 3;51,52,47;,
 3;52,53,47;,
 3;53,45,47;;
 
 MeshMaterialList {
  1;
  40;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.400000;0.400000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  52;
  -0.382543;-0.016974;0.923782;,
  0.250075;-0.016281;0.968090;,
  0.829705;0.005914;0.558171;,
  0.968044;-0.003039;-0.250763;,
  0.510019;-0.010834;-0.860095;,
  -0.306735;-0.039625;-0.950970;,
  -0.826695;0.001868;-0.562648;,
  -0.921920;0.062575;-0.382293;,
  -0.550344;-0.001417;0.834937;,
  0.133257;-0.021885;0.990840;,
  0.771069;-0.005726;0.636726;,
  0.991881;-0.001532;-0.127158;,
  0.612766;-0.005460;-0.790245;,
  -0.152443;-0.029706;-0.987866;,
  -0.771661;-0.004795;-0.636016;,
  -0.989539;0.043750;-0.137470;,
  -0.776001;0.044043;0.629192;,
  -0.029684;-0.027087;0.999192;,
  0.697085;-0.023697;0.716597;,
  0.999307;0.001419;0.037186;,
  0.731865;0.002371;-0.681446;,
  0.075915;0.004002;-0.997106;,
  -0.692659;-0.016993;-0.721065;,
  -0.999050;0.025631;-0.035243;,
  -0.842453;0.073650;0.533712;,
  -0.071479;-0.026744;0.997083;,
  0.687420;-0.030252;0.725630;,
  0.997118;0.002838;0.075813;,
  0.756625;0.004737;-0.653832;,
  0.148363;0.026716;-0.988572;,
  -0.167353;0.042462;-0.984982;,
  -0.997554;0.019217;-0.067204;,
  0.095134;-0.994885;-0.033960;,
  -0.043367;0.982076;-0.183428;,
  -0.693665;0.008197;0.720251;,
  -0.966068;-0.080452;-0.245438;,
  0.095757;-0.989629;-0.107075;,
  0.077829;-0.992305;-0.096294;,
  0.096630;-0.992398;-0.076209;,
  0.075717;-0.996803;-0.025532;,
  0.086147;-0.996273;-0.004248;,
  0.122055;-0.992492;0.007924;,
  0.119328;-0.992001;0.041161;,
  0.086564;-0.996186;-0.010934;,
  -0.001520;0.989512;-0.144446;,
  -0.040732;0.990550;-0.130967;,
  -0.063817;0.985227;-0.158921;,
  -0.035770;0.979723;-0.197138;,
  -0.043019;0.977657;-0.205759;,
  -0.065857;0.977738;-0.199226;,
  -0.064989;0.972434;-0.223938;,
  -0.030992;0.978076;-0.205930;;
  40;
  4;0,1,9,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;34,0,8,34;,
  4;8,9,17,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,8,16,23;,
  4;16,17,25,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,35;,
  4;23,16,24,31;,
  3;36,37,32;,
  3;38,36,32;,
  3;39,38,32;,
  3;40,39,32;,
  3;41,40,32;,
  3;42,41,32;,
  3;43,42,32;,
  3;37,43,32;,
  3;44,45,33;,
  3;45,46,33;,
  3;46,47,33;,
  3;47,48,33;,
  3;48,49,33;,
  3;49,50,33;,
  3;50,51,33;,
  3;51,44,33;;
 }
 MeshTextureCoords {
  54;
  0.375000;0.312500;,
  0.406250;0.312500;,
  0.406250;0.437500;,
  0.375000;0.437500;,
  0.437500;0.312500;,
  0.437500;0.437500;,
  0.468750;0.312500;,
  0.468750;0.437500;,
  0.500000;0.312500;,
  0.500000;0.437500;,
  0.531250;0.312500;,
  0.531250;0.437500;,
  0.562500;0.312500;,
  0.562500;0.437500;,
  0.593750;0.312500;,
  0.593750;0.437500;,
  0.625000;0.312500;,
  0.625000;0.437500;,
  0.406250;0.562500;,
  0.375000;0.562500;,
  0.437500;0.562500;,
  0.468750;0.562500;,
  0.500000;0.562500;,
  0.531250;0.562500;,
  0.562500;0.562500;,
  0.593750;0.562500;,
  0.625000;0.562500;,
  0.406250;0.687500;,
  0.375000;0.687500;,
  0.437500;0.687500;,
  0.468750;0.687500;,
  0.500000;0.687500;,
  0.531250;0.687500;,
  0.562500;0.687500;,
  0.593750;0.687500;,
  0.625000;0.687500;,
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
  0.656250;0.843750;;
 }
}
