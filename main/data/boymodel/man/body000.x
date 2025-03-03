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
 196;
 7.59151;15.49716;-4.56071;,
 7.78936;23.23833;-3.16884;,
 7.97881;23.23833;0.10560;,
 9.01773;14.24985;0.10560;,
 -0.12271;0.39967;-4.56071;,
 6.76840;0.39967;-4.56071;,
 9.43397;0.39967;0.10560;,
 -0.14016;0.39967;0.10560;,
 7.59151;15.49716;-4.56071;,
 6.64333;7.75599;-4.56071;,
 -0.09845;7.75599;-4.56071;,
 -0.11937;17.15362;-4.56071;,
 7.53863;23.23833;3.31726;,
 7.65683;15.49715;4.77192;,
 6.90957;7.75599;4.77192;,
 8.64516;7.75599;0.10560;,
 6.64333;7.75599;-4.56071;,
 6.97463;0.39967;4.77192;,
 -0.20007;0.39967;4.77192;,
 -0.12845;7.75599;4.77192;,
 6.90957;7.75599;4.77192;,
 7.65683;15.49715;4.77192;,
 -0.11091;15.49715;4.77192;,
 7.53863;23.23833;3.31726;,
 -0.16838;25.77888;3.01647;,
 -0.14750;23.23832;-3.40376;,
 7.78936;23.23833;-3.16884;,
 -0.09845;7.75599;-4.56071;,
 -0.12845;7.75599;4.77192;,
 2.25071;26.95811;0.13532;,
 1.80087;26.99206;1.38903;,
 1.33909;27.00574;-0.88821;,
 -0.14750;23.23832;-3.40376;,
 -0.12479;27.37003;-1.15298;,
 -0.16838;25.77888;3.01647;,
 -7.54028;15.49716;-4.56071;,
 -7.73815;23.23833;-3.16884;,
 -7.92757;23.23833;0.10560;,
 -8.96649;14.24985;0.10560;,
 0.17391;0.39967;-4.56071;,
 -6.71718;0.39967;-4.56071;,
 -9.38276;0.39967;0.10560;,
 0.19139;0.39967;0.10560;,
 -7.54028;15.49716;-4.56071;,
 -6.59212;7.75599;-4.56071;,
 0.14968;7.75599;-4.56071;,
 0.17058;17.15362;-4.56071;,
 -7.48741;23.23833;3.31726;,
 -7.60562;15.49715;4.77192;,
 -6.85835;7.75599;4.77192;,
 -8.59394;7.75599;0.10560;,
 -6.59212;7.75599;-4.56071;,
 -6.92341;0.39967;4.77192;,
 0.25129;0.39967;4.77192;,
 0.17966;7.75599;4.77192;,
 -6.85835;7.75599;4.77192;,
 -7.60562;15.49715;4.77192;,
 0.16212;15.49715;4.77192;,
 -7.48741;23.23833;3.31726;,
 0.21960;25.77888;3.01647;,
 0.19872;23.23832;-3.40376;,
 -7.73815;23.23833;-3.16884;,
 0.14968;7.75599;-4.56071;,
 0.17966;7.75599;4.77192;,
 -2.19948;26.95811;0.13532;,
 -1.74965;26.99206;1.38903;,
 -1.28788;27.00574;-0.88821;,
 0.19872;23.23832;-3.40376;,
 0.17601;27.37003;-1.15298;,
 0.21960;25.77888;3.01647;,
 1.18174;25.83798;2.33417;,
 2.07365;25.83798;1.82923;,
 1.52179;27.07631;1.47150;,
 0.68668;27.07631;1.66840;,
 2.71025;25.83798;1.56928;,
 1.76569;27.07631;1.16481;,
 2.07221;25.83798;0.77836;,
 2.07221;27.07631;0.77836;,
 2.17783;25.83798;0.34998;,
 2.27786;27.07631;0.34998;,
 2.07221;25.83798;-0.07840;,
 2.07221;27.07631;-0.07840;,
 1.76569;25.83798;-0.46485;,
 1.76569;27.07631;-0.46485;,
 1.28826;25.83798;-0.77154;,
 1.28826;27.07631;-0.90946;,
 0.68668;25.83798;-0.96844;,
 0.68668;27.07631;-0.96844;,
 0.01980;25.83798;-1.03629;,
 0.01980;27.07631;-1.12137;,
 -0.64707;25.83798;-0.96844;,
 -0.64707;27.07631;-0.96844;,
 -1.24865;25.83798;-0.77154;,
 -1.33549;27.07631;-0.90099;,
 -1.72606;25.83798;-0.46485;,
 -1.72606;27.07631;-0.46485;,
 -2.03259;25.83798;-0.07840;,
 -2.08653;27.07631;-0.07840;,
 -2.13822;25.83798;0.34998;,
 -2.24910;27.31606;0.34998;,
 -2.03259;25.83798;0.77836;,
 -2.03259;27.07631;0.77836;,
 -1.72606;25.83798;1.16481;,
 -1.72606;27.07631;1.16481;,
 -2.93148;25.83798;1.47149;,
 -1.24865;27.07631;1.47149;,
 -0.64707;25.83798;2.51672;,
 -0.64707;27.07631;1.66840;,
 0.01980;25.83798;2.88386;,
 0.01980;27.07631;1.73625;,
 1.18174;25.83798;2.33417;,
 0.68668;27.07631;1.66840;,
 2.07365;25.83798;1.82923;,
 1.18174;25.83798;2.33417;,
 0.01980;25.83798;0.34998;,
 2.71025;25.83798;1.56928;,
 2.07221;25.83798;0.77836;,
 2.17783;25.83798;0.34998;,
 2.07221;25.83798;-0.07840;,
 1.76569;25.83798;-0.46485;,
 1.28826;25.83798;-0.77154;,
 0.68668;25.83798;-0.96844;,
 0.01980;25.83798;-1.03629;,
 -0.64707;25.83798;-0.96844;,
 -1.24865;25.83798;-0.77154;,
 -1.72606;25.83798;-0.46485;,
 -2.03259;25.83798;-0.07840;,
 -2.13822;25.83798;0.34998;,
 -2.03259;25.83798;0.77836;,
 -1.72606;25.83798;1.16481;,
 -2.93148;25.83798;1.47149;,
 -0.64707;25.83798;2.51672;,
 0.01980;25.83798;2.88386;,
 0.68668;31.91378;1.66840;,
 1.28826;31.91378;1.47149;,
 0.01980;31.91378;0.34998;,
 1.76569;31.91378;1.16481;,
 2.07221;31.91378;0.77836;,
 2.17783;31.91378;0.34998;,
 2.07221;31.91378;-0.07840;,
 1.76569;31.91378;-0.46485;,
 1.28826;31.91378;-0.77154;,
 0.68668;31.91378;-0.96844;,
 0.01980;31.91378;-1.03629;,
 -0.64707;31.91378;-0.96844;,
 -1.24865;31.91378;-0.77154;,
 -1.72606;31.91378;-0.46485;,
 -2.03259;31.91378;-0.07840;,
 -2.13822;31.91378;0.34998;,
 -2.03259;31.91378;0.77836;,
 -1.72606;31.91378;1.16481;,
 -1.24865;31.91378;1.47149;,
 -0.64707;31.91378;1.66840;,
 0.01980;31.91378;1.73625;,
 0.01980;29.45856;1.73625;,
 0.68668;29.45856;1.66840;,
 0.68668;31.91378;1.66840;,
 0.01980;31.91378;1.73625;,
 -0.64707;29.45856;1.66840;,
 -0.64707;31.91378;1.66840;,
 -1.24865;29.45856;1.47149;,
 -1.24865;31.91378;1.47149;,
 -1.72606;29.45856;1.16481;,
 -1.72606;31.91378;1.16481;,
 -2.03259;29.45856;0.77836;,
 -2.03259;31.91378;0.77836;,
 -2.13822;29.45856;0.34998;,
 -2.13822;31.91378;0.34998;,
 -2.03259;29.45856;-0.07840;,
 -2.03259;31.91378;-0.07840;,
 -1.72606;29.45856;-0.46485;,
 -1.72606;31.91378;-0.46485;,
 -1.24865;29.45856;-0.77154;,
 -1.24865;31.91378;-0.77154;,
 -0.64707;29.45856;-0.96844;,
 -0.64707;31.91378;-0.96844;,
 0.01980;29.45856;-1.03629;,
 0.01980;31.91378;-1.03629;,
 0.68668;29.45856;-0.96844;,
 0.68668;31.91378;-0.96844;,
 1.28826;29.45856;-0.77154;,
 1.28826;31.91378;-0.77154;,
 1.76569;29.45856;-0.46485;,
 1.76569;31.91378;-0.46485;,
 2.07221;29.45856;-0.07840;,
 2.07221;31.91378;-0.07840;,
 2.17783;29.45856;0.34998;,
 2.17783;31.91378;0.34998;,
 2.07221;29.45856;0.77836;,
 2.07221;31.91378;0.77836;,
 1.76569;29.45856;1.16481;,
 1.76569;31.91378;1.16481;,
 1.28826;29.45856;1.47149;,
 1.28826;31.91378;1.47149;,
 0.68668;29.45856;1.66840;,
 0.68668;31.91378;1.66840;;
 
 272;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;2,12,13,3;,
 4;13,14,15,3;,
 4;15,16,0,3;,
 4;6,17,18,7;,
 4;19,20,21,22;,
 4;21,23,24,22;,
 4;25,26,8,11;,
 4;27,16,5,4;,
 4;16,15,6,5;,
 4;15,14,17,6;,
 4;14,28,18,17;,
 4;12,2,29,30;,
 4;2,1,31,29;,
 4;1,32,33,31;,
 3;34,12,30;,
 4;35,36,37,38;,
 4;39,40,41,42;,
 4;43,44,45,46;,
 4;37,47,48,38;,
 4;48,49,50,38;,
 4;50,51,35,38;,
 4;41,52,53,42;,
 4;54,55,56,57;,
 4;56,58,59,57;,
 4;60,61,43,46;,
 4;62,51,40,39;,
 4;51,50,41,40;,
 4;50,49,52,41;,
 4;49,63,53,52;,
 4;47,37,64,65;,
 4;37,36,66,64;,
 4;36,67,68,66;,
 3;69,47,65;,
 4;70,71,72,73;,
 4;71,74,75,72;,
 4;74,76,77,75;,
 4;76,78,79,77;,
 4;78,80,81,79;,
 4;80,82,83,81;,
 4;82,84,85,83;,
 4;84,86,87,85;,
 4;86,88,89,87;,
 4;88,90,91,89;,
 4;90,92,93,91;,
 4;92,94,95,93;,
 4;94,96,97,95;,
 4;96,98,99,97;,
 4;98,100,101,99;,
 4;100,102,103,101;,
 4;102,104,105,103;,
 4;104,106,107,105;,
 4;106,108,109,107;,
 4;108,110,111,109;,
 3;112,113,114;,
 3;115,112,114;,
 3;116,115,114;,
 3;117,116,114;,
 3;118,117,114;,
 3;119,118,114;,
 3;120,119,114;,
 3;121,120,114;,
 3;122,121,114;,
 3;123,122,114;,
 3;124,123,114;,
 3;125,124,114;,
 3;126,125,114;,
 3;127,126,114;,
 3;128,127,114;,
 3;129,128,114;,
 3;130,129,114;,
 3;131,130,114;,
 3;132,131,114;,
 3;113,132,114;,
 3;133,134,135;,
 3;134,136,135;,
 3;136,137,135;,
 3;137,138,135;,
 3;138,139,135;,
 3;139,140,135;,
 3;140,141,135;,
 3;141,142,135;,
 3;142,143,135;,
 3;143,144,135;,
 3;144,145,135;,
 3;145,146,135;,
 3;146,147,135;,
 3;147,148,135;,
 3;148,149,135;,
 3;149,150,135;,
 3;150,151,135;,
 3;151,152,135;,
 3;152,153,135;,
 3;153,133,135;,
 4;154,155,156,157;,
 4;158,154,157,159;,
 4;160,158,159,161;,
 4;162,160,161,163;,
 4;164,162,163,165;,
 4;166,164,165,167;,
 4;168,166,167,169;,
 4;170,168,169,171;,
 4;172,170,171,173;,
 4;174,172,173,175;,
 4;176,174,175,177;,
 4;178,176,177,179;,
 4;180,178,179,181;,
 4;182,180,181,183;,
 4;184,182,183,185;,
 4;186,184,185,187;,
 4;188,186,187,189;,
 4;190,188,189,191;,
 4;192,190,191,193;,
 4;194,192,193,195;,
 4;109,111,155,154;,
 4;107,109,154,158;,
 4;105,107,158,160;,
 4;103,105,160,162;,
 4;101,103,162,164;,
 4;99,101,164,166;,
 4;97,99,166,168;,
 4;95,97,168,170;,
 4;93,95,170,172;,
 4;91,93,172,174;,
 4;89,91,174,176;,
 4;87,89,176,178;,
 4;85,87,178,180;,
 4;83,85,180,182;,
 4;81,83,182,184;,
 4;79,81,184,186;,
 4;77,79,186,188;,
 4;75,77,188,190;,
 4;72,75,190,192;,
 4;73,72,192,194;,
 4;3,2,1,0;,
 4;7,6,5,4;,
 4;11,10,9,8;,
 4;3,13,12,2;,
 4;3,15,14,13;,
 4;3,0,16,15;,
 4;7,18,17,6;,
 4;22,21,20,19;,
 4;22,24,23,21;,
 4;11,8,26,25;,
 4;4,5,16,27;,
 4;5,6,15,16;,
 4;6,17,14,15;,
 4;17,18,28,14;,
 4;30,29,2,12;,
 4;29,31,1,2;,
 4;31,33,32,1;,
 3;30,12,34;,
 4;38,37,36,35;,
 4;42,41,40,39;,
 4;46,45,44,43;,
 4;38,48,47,37;,
 4;38,50,49,48;,
 4;38,35,51,50;,
 4;42,53,52,41;,
 4;57,56,55,54;,
 4;57,59,58,56;,
 4;46,43,61,60;,
 4;39,40,51,62;,
 4;40,41,50,51;,
 4;41,52,49,50;,
 4;52,53,63,49;,
 4;65,64,37,47;,
 4;64,66,36,37;,
 4;66,68,67,36;,
 3;65,47,69;,
 4;73,72,71,70;,
 4;72,75,74,71;,
 4;75,77,76,74;,
 4;77,79,78,76;,
 4;79,81,80,78;,
 4;81,83,82,80;,
 4;83,85,84,82;,
 4;85,87,86,84;,
 4;87,89,88,86;,
 4;89,91,90,88;,
 4;91,93,92,90;,
 4;93,95,94,92;,
 4;95,97,96,94;,
 4;97,99,98,96;,
 4;99,101,100,98;,
 4;101,103,102,100;,
 4;103,105,104,102;,
 4;105,107,106,104;,
 4;107,109,108,106;,
 4;109,111,110,108;,
 3;114,113,112;,
 3;114,112,115;,
 3;114,115,116;,
 3;114,116,117;,
 3;114,117,118;,
 3;114,118,119;,
 3;114,119,120;,
 3;114,120,121;,
 3;114,121,122;,
 3;114,122,123;,
 3;114,123,124;,
 3;114,124,125;,
 3;114,125,126;,
 3;114,126,127;,
 3;114,127,128;,
 3;114,128,129;,
 3;114,129,130;,
 3;114,130,131;,
 3;114,131,132;,
 3;114,132,113;,
 3;135,134,133;,
 3;135,136,134;,
 3;135,137,136;,
 3;135,138,137;,
 3;135,139,138;,
 3;135,140,139;,
 3;135,141,140;,
 3;135,142,141;,
 3;135,143,142;,
 3;135,144,143;,
 3;135,145,144;,
 3;135,146,145;,
 3;135,147,146;,
 3;135,148,147;,
 3;135,149,148;,
 3;135,150,149;,
 3;135,151,150;,
 3;135,152,151;,
 3;135,153,152;,
 3;135,133,153;,
 4;157,156,155,154;,
 4;159,157,154,158;,
 4;161,159,158,160;,
 4;163,161,160,162;,
 4;165,163,162,164;,
 4;167,165,164,166;,
 4;169,167,166,168;,
 4;171,169,168,170;,
 4;173,171,170,172;,
 4;175,173,172,174;,
 4;177,175,174,176;,
 4;179,177,176,178;,
 4;181,179,178,180;,
 4;183,181,180,182;,
 4;185,183,182,184;,
 4;187,185,184,186;,
 4;189,187,186,188;,
 4;191,189,188,190;,
 4;193,191,190,192;,
 4;195,193,192,194;,
 4;154,155,111,109;,
 4;158,154,109,107;,
 4;160,158,107,105;,
 4;162,160,105,103;,
 4;164,162,103,101;,
 4;166,164,101,99;,
 4;168,166,99,97;,
 4;170,168,97,95;,
 4;172,170,95,93;,
 4;174,172,93,91;,
 4;176,174,91,89;,
 4;178,176,89,87;,
 4;180,178,87,85;,
 4;182,180,85,83;,
 4;184,182,83,81;,
 4;186,184,81,79;,
 4;188,186,79,77;,
 4;190,188,77,75;,
 4;192,190,75,72;,
 4;194,192,72,73;;
 
 MeshMaterialList {
  6;
  272;
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
  0,
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
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
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
  0,
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
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
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
    "C:\\Users\\student\\Desktop\\���앨\\Maya obj��p\\thumbnail.png";
   }
  }
 }
 MeshNormals {
  267;
  0.656587;0.579147;-0.483199;,
  0.666912;0.623812;0.407539;,
  -0.000000;0.000000;-1.000000;,
  0.930043;-0.010618;0.367298;,
  0.103839;0.438546;0.892690;,
  0.850730;0.525551;-0.007354;,
  0.092011;0.350971;-0.931855;,
  0.999964;-0.008471;0.000075;,
  0.965449;0.001693;0.260588;,
  0.999728;-0.013842;-0.018785;,
  0.965161;-0.018071;-0.261033;,
  0.000000;-0.000000;1.000000;,
  0.004276;0.088617;0.996057;,
  0.016785;0.091080;-0.995702;,
  0.000000;-1.000000;-0.000000;,
  0.382407;0.806965;0.450080;,
  0.505177;0.862525;-0.029091;,
  0.342330;0.753229;-0.561654;,
  0.147395;0.508353;-0.848441;,
  0.656589;-0.579148;0.483196;,
  0.666913;-0.623812;-0.407536;,
  0.000000;0.000000;1.000000;,
  0.930043;0.010618;-0.367297;,
  0.103839;-0.438546;-0.892690;,
  0.850731;-0.525550;0.007353;,
  0.092011;-0.350971;0.931855;,
  0.999964;0.008471;-0.000075;,
  0.965450;-0.001694;-0.260584;,
  0.999728;0.013841;0.018785;,
  0.965162;0.018071;0.261029;,
  -0.000000;-0.000000;-1.000000;,
  0.004276;-0.088618;-0.996057;,
  0.016786;-0.091080;0.995702;,
  0.000000;1.000000;0.000000;,
  0.382408;-0.806966;-0.450078;,
  0.505178;-0.862525;0.029090;,
  0.342331;-0.753231;0.561652;,
  0.147394;-0.508353;0.848441;,
  0.154176;0.881655;0.445997;,
  0.425609;0.493357;0.758588;,
  0.824817;0.405166;0.394357;,
  0.977682;0.100602;0.184437;,
  0.999247;-0.038809;-0.000000;,
  0.873767;-0.018514;-0.485993;,
  0.703342;-0.020559;-0.710554;,
  0.419612;-0.048148;-0.906426;,
  0.183793;-0.043268;-0.982012;,
  -0.000001;-0.033943;-0.999424;,
  -0.184081;-0.044517;-0.981902;,
  -0.439777;-0.060210;-0.896086;,
  -0.704732;-0.038695;-0.708418;,
  -0.878288;-0.037132;-0.476687;,
  -0.998493;-0.047660;0.027206;,
  -0.875424;-0.017306;0.483046;,
  -0.783463;0.000000;0.621438;,
  -0.262580;0.958386;-0.112020;,
  -0.154014;0.884378;0.440630;,
  -0.003827;0.905236;0.424892;,
  0.196956;0.002828;0.980408;,
  -0.000001;0.000000;1.000000;,
  -0.207347;0.000000;0.978267;,
  -0.429253;0.000000;0.903184;,
  -0.671040;0.000000;0.741421;,
  -0.884832;0.006432;0.465865;,
  -0.999806;0.015910;0.011655;,
  -0.885669;0.011246;-0.464180;,
  -0.688444;0.010145;-0.725218;,
  -0.434844;0.015530;-0.900372;,
  -0.195728;0.011633;-0.980589;,
  -0.000001;0.008797;-0.999961;,
  0.195693;0.011304;-0.980600;,
  0.424738;0.012435;-0.905231;,
  0.687486;0.005371;-0.726177;,
  0.886059;0.004844;-0.463548;,
  0.999951;0.009946;0.000000;,
  0.886059;0.004844;0.463548;,
  0.701018;0.006769;0.713111;,
  0.456232;0.009693;0.889808;,
  0.239978;0.291921;0.925847;,
  -0.003675;0.330279;0.943876;,
  -0.251662;0.295950;0.921455;,
  -0.718881;0.623824;-0.306683;,
  -0.711004;0.000000;0.703188;,
  -0.873473;-0.002247;0.486867;,
  -0.999646;-0.007854;0.025438;,
  -0.875990;-0.007303;-0.482275;,
  -0.705275;-0.009260;-0.708873;,
  -0.440572;-0.014414;-0.897602;,
  -0.184210;-0.010664;-0.982829;,
  -0.000001;-0.008141;-0.999967;,
  0.184026;-0.010367;-0.982867;,
  0.420124;-0.011536;-0.907393;,
  0.703489;-0.004927;-0.710690;,
  0.873905;-0.004438;-0.486076;,
  0.999957;-0.009308;0.000000;,
  0.938550;0.055694;0.340620;,
  0.799836;0.206388;0.563618;,
  0.468504;0.266995;0.842151;,
  0.915421;-0.014935;-0.402221;,
  0.008519;0.176536;0.984257;,
  0.033427;0.181378;-0.982845;,
  -0.000000;-0.000000;-1.000000;,
  0.998073;0.058490;-0.020721;,
  0.893839;0.054293;-0.445088;,
  0.911705;0.051517;0.407604;,
  0.000000;-0.000000;1.000000;,
  0.915421;0.014934;0.402220;,
  0.008518;-0.176536;-0.984257;,
  0.033427;-0.181378;0.982845;,
  0.000000;-0.000000;1.000000;,
  0.998073;-0.058490;0.020720;,
  0.893840;-0.054293;0.445088;,
  0.911704;-0.051518;-0.407604;,
  -0.000000;-0.000000;-1.000000;,
  -0.311953;0.519757;0.795323;,
  -0.403451;0.180228;0.897076;,
  -0.079901;-0.958082;-0.275126;,
  0.262580;-0.958386;0.112020;,
  0.154014;-0.884378;-0.440630;,
  0.003827;-0.905236;-0.424892;,
  0.207347;0.000000;0.978268;,
  -0.000001;0.000000;1.000000;,
  -0.207347;0.000000;0.978267;,
  -0.671040;0.000000;0.741421;,
  -0.897747;0.000000;0.440511;,
  -1.000000;0.000000;0.000000;,
  -0.897747;0.000000;-0.440511;,
  -0.671045;0.000000;-0.741416;,
  -0.429253;0.000000;-0.903184;,
  -0.207340;0.000000;-0.978269;,
  -0.000001;0.000000;-1.000000;,
  0.207339;0.000000;-0.978269;,
  0.429245;0.000000;-0.903188;,
  0.671044;0.000000;-0.741418;,
  0.897756;0.000000;-0.440494;,
  1.000000;0.000000;0.000000;,
  0.897756;0.000000;0.440494;,
  0.671039;0.000000;0.741422;,
  0.429245;0.000000;0.903188;,
  -0.999964;0.008471;-0.000075;,
  -0.850730;-0.525551;0.007354;,
  -0.656587;-0.579147;0.483199;,
  -0.965161;0.018071;0.261033;,
  -0.016785;-0.091080;0.995702;,
  0.000000;-0.000000;1.000000;,
  -0.965449;-0.001693;-0.260588;,
  -0.666912;-0.623812;-0.407539;,
  -0.999728;0.013842;0.018785;,
  -0.930043;0.010618;-0.367298;,
  -0.915421;0.014935;0.402221;,
  -0.004276;-0.088617;-0.996057;,
  -0.000000;0.000000;-1.000000;,
  -0.103839;-0.438546;-0.892690;,
  -0.008519;-0.176536;-0.984257;,
  -0.033427;-0.181378;0.982845;,
  -0.092011;-0.350971;0.931855;,
  0.000000;0.000000;1.000000;,
  -0.893839;-0.054293;0.445088;,
  -0.998073;-0.058490;0.020721;,
  -0.911705;-0.051517;-0.407604;,
  -0.000000;0.000000;-1.000000;,
  -0.382407;-0.806965;-0.450080;,
  -0.505177;-0.862525;0.029091;,
  -0.342330;-0.753229;0.561654;,
  -0.147395;-0.508353;0.848441;,
  -0.999964;-0.008471;0.000075;,
  -0.850731;0.525550;-0.007353;,
  -0.656589;0.579148;-0.483196;,
  -0.965162;-0.018071;-0.261029;,
  -0.016786;0.091080;-0.995702;,
  -0.000000;-0.000000;-1.000000;,
  -0.965450;0.001694;0.260584;,
  -0.666913;0.623812;0.407536;,
  -0.999728;-0.013841;-0.018785;,
  -0.930043;-0.010618;0.367297;,
  -0.915421;-0.014934;-0.402220;,
  -0.004276;0.088618;0.996057;,
  0.000000;0.000000;1.000000;,
  -0.103839;0.438546;0.892690;,
  -0.008518;0.176536;0.984257;,
  -0.033427;0.181378;-0.982845;,
  -0.092011;0.350971;-0.931855;,
  -0.000000;0.000000;-1.000000;,
  -0.893840;0.054293;-0.445088;,
  -0.998073;0.058490;-0.020720;,
  -0.911704;0.051518;0.407604;,
  0.000000;0.000000;1.000000;,
  -0.382408;0.806966;0.450078;,
  -0.505178;0.862525;-0.029090;,
  -0.342331;0.753231;-0.561652;,
  -0.147394;0.508353;-0.848441;,
  -0.239978;-0.291921;-0.925847;,
  -0.468504;-0.266995;-0.842151;,
  -0.425609;-0.493357;-0.758588;,
  -0.323595;-0.479421;-0.815746;,
  -0.799836;-0.206388;-0.563618;,
  -0.824817;-0.405166;-0.394357;,
  -0.938550;-0.055694;-0.340620;,
  -0.977682;-0.100602;-0.184437;,
  -0.999957;0.009308;-0.000000;,
  -0.999247;0.038809;0.000000;,
  -0.873905;0.004438;0.486076;,
  -0.873767;0.018514;0.485993;,
  -0.703489;0.004927;0.710690;,
  -0.703342;0.020559;0.710554;,
  -0.420124;0.011536;0.907393;,
  -0.419612;0.048148;0.906426;,
  -0.184026;0.010367;0.982867;,
  -0.183793;0.043268;0.982012;,
  0.000001;0.008141;0.999967;,
  0.000001;0.033943;0.999424;,
  0.184210;0.010664;0.982829;,
  0.184081;0.044517;0.981902;,
  0.440572;0.014414;0.897602;,
  0.439777;0.060210;0.896086;,
  0.705275;0.009260;0.708873;,
  0.704732;0.038695;0.708418;,
  0.875990;0.007303;0.482275;,
  0.878288;0.037132;0.476687;,
  0.999646;0.007854;-0.025438;,
  0.998493;0.047660;-0.027206;,
  0.873473;0.002247;-0.486867;,
  0.875424;0.017306;-0.483046;,
  0.711004;0.000000;-0.703188;,
  0.783463;0.000000;-0.621438;,
  0.718881;-0.623824;0.306683;,
  0.403451;-0.180228;-0.897076;,
  0.251662;-0.295950;-0.921455;,
  0.311953;-0.519757;-0.795323;,
  0.003675;-0.330279;-0.943876;,
  0.000001;0.000000;-1.000000;,
  -0.207347;0.000000;-0.978268;,
  -0.196956;-0.002828;-0.980408;,
  0.000001;0.000000;-1.000000;,
  0.207347;0.000000;-0.978267;,
  0.207347;0.000000;-0.978267;,
  0.429253;0.000000;-0.903184;,
  0.671040;0.000000;-0.741421;,
  0.671040;0.000000;-0.741421;,
  0.897747;0.000000;-0.440511;,
  0.884832;-0.006432;-0.465865;,
  0.999806;-0.015910;-0.011655;,
  0.897747;0.000000;0.440511;,
  0.885669;-0.011246;0.464180;,
  0.671045;0.000000;0.741416;,
  0.688444;-0.010145;0.725218;,
  0.429253;0.000000;0.903184;,
  0.434844;-0.015530;0.900372;,
  0.207340;0.000000;0.978269;,
  0.195728;-0.011633;0.980589;,
  0.000001;0.000000;1.000000;,
  0.000001;-0.008797;0.999961;,
  -0.207339;0.000000;0.978269;,
  -0.195693;-0.011304;0.980600;,
  -0.429245;0.000000;0.903188;,
  -0.424738;-0.012435;0.905231;,
  -0.671044;0.000000;0.741418;,
  -0.687486;-0.005371;0.726177;,
  -0.897756;0.000000;0.440494;,
  -0.886059;-0.004844;0.463548;,
  -0.999951;-0.009946;-0.000000;,
  -0.897756;0.000000;-0.440494;,
  -0.886059;-0.004844;-0.463548;,
  -0.671039;0.000000;-0.741422;,
  -0.701018;-0.006769;-0.713111;,
  -0.429245;0.000000;-0.903188;,
  -0.456232;-0.009693;-0.889808;;
  272;
  4;10,0,5,7;,
  4;14,14,14,14;,
  4;13,2,2,13;,
  4;5,1,8,7;,
  4;8,3,9,7;,
  4;9,98,10,7;,
  4;14,14,14,14;,
  4;11,11,12,12;,
  4;12,99,4,12;,
  4;6,100,13,13;,
  4;2,2,101,101;,
  4;98,9,102,103;,
  4;9,3,104,102;,
  4;11,11,105,105;,
  4;1,5,16,15;,
  4;5,0,17,16;,
  4;0,6,18,17;,
  3;4,1,15;,
  4;29,19,24,26;,
  4;33,33,33,33;,
  4;32,21,21,32;,
  4;24,20,27,26;,
  4;27,22,28,26;,
  4;28,106,29,26;,
  4;33,33,33,33;,
  4;30,30,31,31;,
  4;31,107,23,31;,
  4;25,108,32,32;,
  4;21,21,109,109;,
  4;106,28,110,111;,
  4;28,22,112,110;,
  4;30,30,113,113;,
  4;20,24,35,34;,
  4;24,19,36,35;,
  4;19,25,37,36;,
  3;23,20,34;,
  4;38,39,97,78;,
  4;39,40,96,97;,
  4;40,41,95,96;,
  4;41,42,94,95;,
  4;42,43,93,94;,
  4;43,44,92,93;,
  4;44,45,91,92;,
  4;45,46,90,91;,
  4;46,47,89,90;,
  4;47,48,88,89;,
  4;48,49,87,88;,
  4;49,50,86,87;,
  4;50,51,85,86;,
  4;51,52,84,85;,
  4;52,53,83,84;,
  4;53,54,82,83;,
  4;55,55,81,81;,
  4;114,56,80,115;,
  4;56,57,79,80;,
  4;57,38,78,79;,
  3;14,116,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;117,14,14;,
  3;55,55,33;,
  3;118,117,14;,
  3;119,118,14;,
  3;116,119,14;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  4;59,58,120,121;,
  4;60,59,121,122;,
  4;61,60,122,61;,
  4;62,61,61,123;,
  4;63,62,123,124;,
  4;64,63,124,125;,
  4;65,64,125,126;,
  4;66,65,126,127;,
  4;67,66,127,128;,
  4;68,67,128,129;,
  4;69,68,129,130;,
  4;70,69,130,131;,
  4;71,70,131,132;,
  4;72,71,132,133;,
  4;73,72,133,134;,
  4;74,73,134,135;,
  4;75,74,135,136;,
  4;76,75,136,137;,
  4;77,76,137,138;,
  4;58,77,138,120;,
  4;79,78,58,59;,
  4;80,79,59,60;,
  4;115,80,60,61;,
  4;82,115,61,62;,
  4;83,82,62,63;,
  4;84,83,63,64;,
  4;85,84,64,65;,
  4;86,85,65,66;,
  4;87,86,66,67;,
  4;88,87,67,68;,
  4;89,88,68,69;,
  4;90,89,69,70;,
  4;91,90,70,71;,
  4;92,91,71,72;,
  4;93,92,72,73;,
  4;94,93,73,74;,
  4;95,94,74,75;,
  4;96,95,75,76;,
  4;97,96,76,77;,
  4;78,97,77,58;,
  4;139,140,141,142;,
  4;33,33,33,33;,
  4;143,144,144,143;,
  4;139,145,146,140;,
  4;139,147,148,145;,
  4;139,142,149,147;,
  4;33,33,33,33;,
  4;150,150,151,151;,
  4;150,152,153,150;,
  4;143,143,154,155;,
  4;156,156,144,144;,
  4;157,158,147,149;,
  4;158,159,148,147;,
  4;160,160,151,151;,
  4;161,162,140,146;,
  4;162,163,141,140;,
  4;163,164,155,141;,
  3;161,146,152;,
  4;165,166,167,168;,
  4;14,14,14,14;,
  4;169,170,170,169;,
  4;165,171,172,166;,
  4;165,173,174,171;,
  4;165,168,175,173;,
  4;14,14,14,14;,
  4;176,176,177,177;,
  4;176,178,179,176;,
  4;169,169,180,181;,
  4;182,182,170,170;,
  4;183,184,173,175;,
  4;184,185,174,173;,
  4;186,186,177,177;,
  4;187,188,166,172;,
  4;188,189,167,166;,
  4;189,190,181,167;,
  3;187,172,178;,
  4;191,192,193,194;,
  4;192,195,196,193;,
  4;195,197,198,196;,
  4;197,199,200,198;,
  4;199,201,202,200;,
  4;201,203,204,202;,
  4;203,205,206,204;,
  4;205,207,208,206;,
  4;207,209,210,208;,
  4;209,211,212,210;,
  4;211,213,214,212;,
  4;213,215,216,214;,
  4;215,217,218,216;,
  4;217,219,220,218;,
  4;219,221,222,220;,
  4;221,223,224,222;,
  4;225,225,117,117;,
  4;226,227,118,228;,
  4;227,229,119,118;,
  4;229,191,116,119;,
  3;33,38,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,55;,
  3;14,117,117;,
  3;33,55,56;,
  3;33,56,57;,
  3;33,57,38;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  4;230,231,232,233;,
  4;234,230,233,235;,
  4;236,234,235,236;,
  4;237,236,236,238;,
  4;239,237,238,240;,
  4;135,239,240,241;,
  4;242,135,241,243;,
  4;244,242,243,245;,
  4;246,244,245,247;,
  4;248,246,247,249;,
  4;250,248,249,251;,
  4;252,250,251,253;,
  4;254,252,253,255;,
  4;256,254,255,257;,
  4;258,256,257,259;,
  4;125,258,259,260;,
  4;261,125,260,262;,
  4;263,261,262,264;,
  4;265,263,264,266;,
  4;231,265,266,232;,
  4;233,232,191,229;,
  4;235,233,229,227;,
  4;236,235,227,226;,
  4;238,236,226,223;,
  4;240,238,223,221;,
  4;241,240,221,219;,
  4;243,241,219,217;,
  4;245,243,217,215;,
  4;247,245,215,213;,
  4;249,247,213,211;,
  4;251,249,211,209;,
  4;253,251,209,207;,
  4;255,253,207,205;,
  4;257,255,205,203;,
  4;259,257,203,201;,
  4;260,259,201,199;,
  4;262,260,199,197;,
  4;264,262,197,195;,
  4;266,264,195,192;,
  4;232,266,192,191;;
 }
 MeshTextureCoords {
  196;
  0.375000;0.625000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.500000;0.625000;,
  0.375000;0.875000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.500000;0.875000;,
  0.125000;0.125000;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.125000;,
  0.625000;0.500000;,
  0.625000;0.625000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.375000;0.750000;,
  0.625000;0.750000;,
  0.625000;0.875000;,
  0.750000;0.000000;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  0.750000;0.125000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.875000;,
  0.625000;0.875000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.375000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.375000;0.625000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.500000;0.625000;,
  0.375000;0.875000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.500000;0.875000;,
  0.125000;0.125000;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.125000;,
  0.625000;0.500000;,
  0.625000;0.625000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.375000;0.750000;,
  0.625000;0.750000;,
  0.625000;0.875000;,
  0.750000;0.000000;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  0.750000;0.125000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.875000;,
  0.625000;0.875000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.375000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.375000;0.312500;,
  0.387500;0.312500;,
  0.387500;0.388930;,
  0.375000;0.388930;,
  0.400000;0.312500;,
  0.400000;0.388930;,
  0.412500;0.312500;,
  0.412500;0.388930;,
  0.425000;0.312500;,
  0.425000;0.388930;,
  0.437500;0.312500;,
  0.437500;0.388930;,
  0.450000;0.312500;,
  0.450000;0.388930;,
  0.462500;0.312500;,
  0.462500;0.388930;,
  0.475000;0.312500;,
  0.475000;0.388930;,
  0.487500;0.312500;,
  0.487500;0.388930;,
  0.500000;0.312500;,
  0.500000;0.388930;,
  0.512500;0.312500;,
  0.512500;0.388930;,
  0.525000;0.312500;,
  0.525000;0.388930;,
  0.537500;0.312500;,
  0.537500;0.388930;,
  0.550000;0.312500;,
  0.550000;0.388930;,
  0.562500;0.312500;,
  0.562500;0.388930;,
  0.575000;0.312500;,
  0.575000;0.388930;,
  0.587500;0.312500;,
  0.587500;0.388930;,
  0.600000;0.312500;,
  0.600000;0.388930;,
  0.612500;0.312500;,
  0.612500;0.388930;,
  0.625000;0.312500;,
  0.625000;0.388930;,
  0.626410;0.064410;,
  0.648600;0.107970;,
  0.500000;0.156250;,
  0.591840;0.029840;,
  0.548280;0.007650;,
  0.500000;-0.000000;,
  0.451720;0.007650;,
  0.408160;0.029840;,
  0.373590;0.064410;,
  0.351400;0.107970;,
  0.343750;0.156250;,
  0.351400;0.204530;,
  0.373590;0.248090;,
  0.408160;0.282660;,
  0.451720;0.304850;,
  0.500000;0.312500;,
  0.548280;0.304850;,
  0.591840;0.282660;,
  0.626410;0.248090;,
  0.648600;0.204530;,
  0.656250;0.156250;,
  0.648600;0.892030;,
  0.626410;0.935590;,
  0.500000;0.843750;,
  0.591840;0.970160;,
  0.548280;0.992350;,
  0.500000;1.000000;,
  0.451720;0.992350;,
  0.408160;0.970160;,
  0.373590;0.935590;,
  0.351400;0.892030;,
  0.343750;0.843750;,
  0.351400;0.795470;,
  0.373590;0.751910;,
  0.408160;0.717340;,
  0.451720;0.695150;,
  0.500000;0.687500;,
  0.548280;0.695150;,
  0.591840;0.717340;,
  0.626410;0.751910;,
  0.648600;0.795470;,
  0.656250;0.843750;,
  0.612500;0.535960;,
  0.625000;0.535960;,
  0.625000;0.687500;,
  0.612500;0.687500;,
  0.600000;0.535960;,
  0.600000;0.687500;,
  0.587500;0.535960;,
  0.587500;0.687500;,
  0.575000;0.535960;,
  0.575000;0.687500;,
  0.562500;0.535960;,
  0.562500;0.687500;,
  0.550000;0.535960;,
  0.550000;0.687500;,
  0.537500;0.535960;,
  0.537500;0.687500;,
  0.525000;0.535960;,
  0.525000;0.687500;,
  0.512500;0.535960;,
  0.512500;0.687500;,
  0.500000;0.535960;,
  0.500000;0.687500;,
  0.487500;0.535960;,
  0.487500;0.687500;,
  0.475000;0.535960;,
  0.475000;0.687500;,
  0.462500;0.535960;,
  0.462500;0.687500;,
  0.450000;0.535960;,
  0.450000;0.687500;,
  0.437500;0.535960;,
  0.437500;0.687500;,
  0.425000;0.535960;,
  0.425000;0.687500;,
  0.412500;0.535960;,
  0.412500;0.687500;,
  0.400000;0.535960;,
  0.400000;0.687500;,
  0.387500;0.535960;,
  0.387500;0.687500;,
  0.375000;0.535960;,
  0.375000;0.687500;;
 }
}
