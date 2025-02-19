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
 378;
 0.03596;0.96592;9.59294;,
 1.73128;0.96592;10.29516;,
 1.73128;0.30923;10.29516;,
 0.03596;0.30923;9.59294;,
 1.38959;0.96592;10.63686;,
 0.03596;0.96592;10.07616;,
 0.03596;0.30923;10.07616;,
 1.38959;0.30923;10.63686;,
 2.43351;0.96592;11.99049;,
 2.43351;0.30923;11.99049;,
 1.95028;0.96592;11.99049;,
 1.95028;0.30923;11.99049;,
 1.73128;0.96592;13.68582;,
 1.73128;0.30923;13.68582;,
 1.38959;0.96592;13.34413;,
 1.38959;0.30923;13.34413;,
 0.03596;0.96592;14.38805;,
 0.03596;0.30923;14.38805;,
 0.03596;0.96592;13.90482;,
 0.03596;0.30923;13.90482;,
 -1.65937;0.96592;13.68582;,
 -1.65937;0.30923;13.68582;,
 -1.31768;0.96592;13.34413;,
 -1.31768;0.30923;13.34413;,
 -2.36160;0.96592;11.99049;,
 -2.36160;0.30923;11.99049;,
 -1.87837;0.96592;11.99049;,
 -1.87837;0.30923;11.99049;,
 -1.65937;0.96592;10.29516;,
 -1.65937;0.30923;10.29516;,
 -1.31768;0.96592;10.63686;,
 -1.31768;0.30923;10.63686;,
 0.03596;0.96592;9.59294;,
 0.03596;0.30923;9.59294;,
 0.03596;0.96592;10.07616;,
 0.03596;0.30923;10.07616;,
 1.38959;0.96592;10.63686;,
 1.73128;0.96592;10.29516;,
 0.03596;0.30923;9.59294;,
 1.73128;0.30923;10.29516;,
 1.38959;0.30923;10.63686;,
 0.03596;0.30923;10.07616;,
 1.95028;0.96592;11.99049;,
 2.43351;0.96592;11.99049;,
 2.43351;0.30923;11.99049;,
 1.95028;0.30923;11.99049;,
 1.38959;0.96592;13.34413;,
 1.73128;0.96592;13.68582;,
 1.73128;0.30923;13.68582;,
 1.38959;0.30923;13.34413;,
 0.03596;0.96592;13.90482;,
 0.03596;0.96592;14.38805;,
 0.03596;0.30923;14.38805;,
 0.03596;0.30923;13.90482;,
 -1.31768;0.96592;13.34413;,
 -1.65937;0.96592;13.68582;,
 -1.65937;0.30923;13.68582;,
 -1.31768;0.30923;13.34413;,
 -1.87837;0.96592;11.99049;,
 -2.36160;0.96592;11.99049;,
 -2.36160;0.30923;11.99049;,
 -1.87837;0.30923;11.99049;,
 -1.31768;0.96592;10.63686;,
 -1.65937;0.96592;10.29516;,
 -1.65937;0.30923;10.29516;,
 -1.31768;0.30923;10.63686;,
 2.26562;0.96592;6.01953;,
 3.96095;0.96592;6.72176;,
 3.96095;0.30923;6.72176;,
 2.26562;0.30923;6.01953;,
 3.61925;0.96592;7.06346;,
 2.26562;0.96592;6.50275;,
 2.26562;0.30923;6.50275;,
 3.61925;0.30923;7.06346;,
 4.66318;0.96592;8.41708;,
 4.66318;0.30923;8.41708;,
 4.17995;0.96592;8.41708;,
 4.17995;0.30923;8.41708;,
 3.96095;0.96592;10.11241;,
 3.96095;0.30923;10.11241;,
 3.61925;0.96592;9.77071;,
 3.61925;0.30923;9.77071;,
 2.26562;0.96592;10.81465;,
 2.26562;0.30923;10.81465;,
 2.26562;0.96592;10.33140;,
 2.26562;0.30923;10.33140;,
 0.57029;0.96592;10.11241;,
 0.57029;0.30923;10.11241;,
 0.91198;0.96592;9.77071;,
 0.91198;0.30923;9.77071;,
 -0.13193;0.96592;8.41708;,
 -0.13193;0.30923;8.41708;,
 0.35129;0.96592;8.41708;,
 0.35129;0.30923;8.41708;,
 0.57029;0.96592;6.72176;,
 0.57029;0.30923;6.72176;,
 0.91198;0.96592;7.06346;,
 0.91198;0.30923;7.06346;,
 2.26562;0.96592;6.01953;,
 2.26562;0.30923;6.01953;,
 2.26562;0.96592;6.50275;,
 2.26562;0.30923;6.50275;,
 3.61925;0.96592;7.06346;,
 3.96095;0.96592;6.72176;,
 2.26562;0.30923;6.01953;,
 3.96095;0.30923;6.72176;,
 3.61925;0.30923;7.06346;,
 2.26562;0.30923;6.50275;,
 4.17995;0.96592;8.41708;,
 4.66318;0.96592;8.41708;,
 4.66318;0.30923;8.41708;,
 4.17995;0.30923;8.41708;,
 3.61925;0.96592;9.77071;,
 3.96095;0.96592;10.11241;,
 3.96095;0.30923;10.11241;,
 3.61925;0.30923;9.77071;,
 2.26562;0.96592;10.33140;,
 2.26562;0.96592;10.81465;,
 2.26562;0.30923;10.81465;,
 2.26562;0.30923;10.33140;,
 0.91198;0.96592;9.77071;,
 0.57029;0.96592;10.11241;,
 0.57029;0.30923;10.11241;,
 0.91198;0.30923;9.77071;,
 0.35129;0.96592;8.41708;,
 -0.13193;0.96592;8.41708;,
 -0.13193;0.30923;8.41708;,
 0.35129;0.30923;8.41708;,
 0.91198;0.96592;7.06346;,
 0.57029;0.96592;6.72176;,
 0.57029;0.30923;6.72176;,
 0.91198;0.30923;7.06346;,
 -2.07662;0.96592;6.01953;,
 -0.38129;0.96592;6.72176;,
 -0.38129;0.30923;6.72176;,
 -2.07662;0.30923;6.01953;,
 -0.72298;0.96592;7.06346;,
 -2.07662;0.96592;6.50275;,
 -2.07662;0.30923;6.50275;,
 -0.72298;0.30923;7.06346;,
 0.32093;0.96592;8.41708;,
 0.32093;0.30923;8.41708;,
 -0.16229;0.96592;8.41708;,
 -0.16229;0.30923;8.41708;,
 -0.38129;0.96592;10.11241;,
 -0.38129;0.30923;10.11241;,
 -0.72298;0.96592;9.77071;,
 -0.72298;0.30923;9.77071;,
 -2.07662;0.96592;10.81465;,
 -2.07662;0.30923;10.81465;,
 -2.07662;0.96592;10.33140;,
 -2.07662;0.30923;10.33140;,
 -3.77194;0.96592;10.11241;,
 -3.77194;0.30923;10.11241;,
 -3.43025;0.96592;9.77071;,
 -3.43025;0.30923;9.77071;,
 -4.47418;0.96592;8.41708;,
 -4.47418;0.30923;8.41708;,
 -3.99095;0.96592;8.41708;,
 -3.99095;0.30923;8.41708;,
 -3.77194;0.96592;6.72176;,
 -3.77194;0.30923;6.72176;,
 -3.43025;0.96592;7.06346;,
 -3.43025;0.30923;7.06346;,
 -2.07662;0.96592;6.01953;,
 -2.07662;0.30923;6.01953;,
 -2.07662;0.96592;6.50275;,
 -2.07662;0.30923;6.50275;,
 -0.72298;0.96592;7.06346;,
 -0.38129;0.96592;6.72176;,
 -2.07662;0.30923;6.01953;,
 -0.38129;0.30923;6.72176;,
 -0.72298;0.30923;7.06346;,
 -2.07662;0.30923;6.50275;,
 -0.16229;0.96592;8.41708;,
 0.32093;0.96592;8.41708;,
 0.32093;0.30923;8.41708;,
 -0.16229;0.30923;8.41708;,
 -0.72298;0.96592;9.77071;,
 -0.38129;0.96592;10.11241;,
 -0.38129;0.30923;10.11241;,
 -0.72298;0.30923;9.77071;,
 -2.07662;0.96592;10.33140;,
 -2.07662;0.96592;10.81465;,
 -2.07662;0.30923;10.81465;,
 -2.07662;0.30923;10.33140;,
 -3.43025;0.96592;9.77071;,
 -3.77194;0.96592;10.11241;,
 -3.77194;0.30923;10.11241;,
 -3.43025;0.30923;9.77071;,
 -3.99095;0.96592;8.41708;,
 -4.47418;0.96592;8.41708;,
 -4.47418;0.30923;8.41708;,
 -3.99095;0.30923;8.41708;,
 -3.43025;0.96592;7.06346;,
 -3.77194;0.96592;6.72176;,
 -3.77194;0.30923;6.72176;,
 -3.43025;0.30923;7.06346;,
 -0.43612;0.99690;8.98457;,
 0.49936;0.99690;8.98457;,
 0.49936;0.27825;8.98457;,
 -0.43612;0.27825;8.98457;,
 0.49936;0.99690;8.98457;,
 0.49936;0.99690;9.92005;,
 0.49936;0.27825;9.92005;,
 0.49936;0.27825;8.98457;,
 0.49936;0.99690;9.92005;,
 -0.43612;0.99690;9.92005;,
 -0.43612;0.27825;9.92005;,
 0.49936;0.27825;9.92005;,
 -0.43612;0.99690;9.92005;,
 -0.43612;0.99690;8.98457;,
 -0.43612;0.27825;8.98457;,
 -0.43612;0.27825;9.92005;,
 0.49936;0.99690;8.98457;,
 -0.43612;0.99690;8.98457;,
 -0.43612;0.27825;8.98457;,
 0.49936;0.27825;8.98457;,
 0.16544;0.92999;4.90253;,
 1.04595;0.92999;5.26725;,
 1.04595;0.37242;5.26725;,
 0.16544;0.37242;4.90253;,
 0.84444;0.92999;5.46876;,
 0.16544;0.92999;5.18751;,
 0.16544;0.37242;5.18751;,
 0.84444;0.37242;5.46876;,
 1.41067;0.92999;6.14777;,
 1.41067;0.37242;6.14777;,
 1.12570;0.92999;6.14777;,
 1.12570;0.37242;6.14777;,
 1.04595;0.92999;7.02829;,
 1.04595;0.37242;7.02829;,
 0.84444;0.92999;6.82677;,
 0.84444;0.37242;6.82677;,
 0.16544;0.92999;7.39301;,
 0.16544;0.37242;7.39301;,
 0.16544;0.92999;7.10802;,
 0.16544;0.37242;7.10802;,
 -0.71508;0.92999;7.02829;,
 -0.71508;0.37242;7.02829;,
 -0.51357;0.92999;6.82677;,
 -0.51357;0.37242;6.82677;,
 -1.07980;0.92999;6.14777;,
 -1.07980;0.37242;6.14777;,
 -0.79483;0.92999;6.14777;,
 -0.79483;0.37242;6.14777;,
 -0.71508;0.92999;5.26725;,
 -0.71508;0.37242;5.26725;,
 -0.51357;0.92999;5.46876;,
 -0.51357;0.37242;5.46876;,
 0.16544;0.92999;4.90253;,
 0.16544;0.37242;4.90253;,
 0.16544;0.92999;5.18751;,
 0.16544;0.37242;5.18751;,
 0.84444;0.92999;5.46876;,
 1.04595;0.92999;5.26725;,
 0.16544;0.37242;4.90253;,
 1.04595;0.37242;5.26725;,
 0.84444;0.37242;5.46876;,
 0.16544;0.37242;5.18751;,
 1.12570;0.92999;6.14777;,
 1.41067;0.92999;6.14777;,
 1.41067;0.37242;6.14777;,
 1.12570;0.37242;6.14777;,
 0.84444;0.92999;6.82677;,
 1.04595;0.92999;7.02829;,
 1.04595;0.37242;7.02829;,
 0.84444;0.37242;6.82677;,
 0.16544;0.92999;7.10802;,
 0.16544;0.92999;7.39301;,
 0.16544;0.37242;7.39301;,
 0.16544;0.37242;7.10802;,
 -0.51357;0.92999;6.82677;,
 -0.71508;0.92999;7.02829;,
 -0.71508;0.37242;7.02829;,
 -0.51357;0.37242;6.82677;,
 -0.79483;0.92999;6.14777;,
 -1.07980;0.92999;6.14777;,
 -1.07980;0.37242;6.14777;,
 -0.79483;0.37242;6.14777;,
 -0.51357;0.92999;5.46876;,
 -0.71508;0.92999;5.26725;,
 -0.71508;0.37242;5.26725;,
 -0.51357;0.37242;5.46876;,
 0.08513;0.91444;9.12501;,
 0.32560;0.82825;9.12501;,
 0.36023;0.85683;-3.23707;,
 0.08373;0.95594;-3.23707;,
 0.42520;0.62017;9.12501;,
 0.47476;0.61756;-3.23707;,
 0.32560;0.41209;9.12501;,
 0.36023;0.37829;-3.23707;,
 0.08513;0.32590;9.12501;,
 0.08373;0.27919;-3.23707;,
 -0.15533;0.41209;9.12501;,
 -0.19277;0.37829;-3.23707;,
 -0.25493;0.62017;9.12501;,
 -0.30730;0.61756;-3.23707;,
 -0.15533;0.82825;9.12501;,
 -0.19277;0.85683;-3.23707;,
 0.08513;0.91444;9.12501;,
 0.08373;0.95594;-3.23707;,
 0.08513;0.62017;9.12501;,
 0.08513;0.62017;9.12501;,
 0.08513;0.62017;9.12501;,
 0.08513;0.62017;9.12501;,
 0.08513;0.62017;9.12501;,
 0.08513;0.62017;9.12501;,
 0.08513;0.62017;9.12501;,
 0.08513;0.62017;9.12501;,
 0.08373;0.61756;-3.23707;,
 0.08373;0.61756;-3.23707;,
 0.08373;0.61756;-3.23707;,
 0.08373;0.61756;-3.23707;,
 0.08373;0.61756;-3.23707;,
 0.08373;0.61756;-3.23707;,
 0.08373;0.61756;-3.23707;,
 0.08373;0.61756;-3.23707;,
 0.08630;1.29691;2.51455;,
 0.60326;1.04795;2.51455;,
 0.60326;1.04795;2.27876;,
 0.08630;1.29691;2.27876;,
 0.73093;0.48857;2.51455;,
 0.73093;0.48857;2.27876;,
 0.37319;0.03997;2.51455;,
 0.37319;0.03997;2.27876;,
 -0.20059;0.03997;2.51455;,
 -0.20059;0.03997;2.27876;,
 -0.55833;0.48857;2.51455;,
 -0.55833;0.48857;2.27876;,
 -0.43065;1.04795;2.51455;,
 -0.43065;1.04795;2.27876;,
 0.08630;1.29691;2.51455;,
 0.08630;1.29691;2.27876;,
 0.08630;0.63570;2.51455;,
 0.08630;0.63570;2.51455;,
 0.08630;0.63570;2.51455;,
 0.08630;0.63570;2.51455;,
 0.08630;0.63570;2.51455;,
 0.08630;0.63570;2.51455;,
 0.08630;0.63570;2.51455;,
 0.08630;0.63570;2.27876;,
 0.08630;0.63570;2.27876;,
 0.08630;0.63570;2.27876;,
 0.08630;0.63570;2.27876;,
 0.08630;0.63570;2.27876;,
 0.08630;0.63570;2.27876;,
 0.08630;0.63570;2.27876;,
 0.08466;1.28486;1.79988;,
 0.60419;1.03466;1.79988;,
 0.60419;1.03466;1.56292;,
 0.08466;1.28486;1.56292;,
 0.73251;0.47248;1.79988;,
 0.73251;0.47248;1.56292;,
 0.37297;0.02164;1.79988;,
 0.37297;0.02164;1.56292;,
 -0.20366;0.02164;1.79988;,
 -0.20366;0.02164;1.56292;,
 -0.56320;0.47248;1.79988;,
 -0.56320;0.47248;1.56292;,
 -0.43488;1.03466;1.79988;,
 -0.43488;1.03466;1.56292;,
 0.08466;1.28486;1.79988;,
 0.08466;1.28486;1.56292;,
 0.08466;0.62034;1.79988;,
 0.08466;0.62034;1.79988;,
 0.08466;0.62034;1.79988;,
 0.08466;0.62034;1.79988;,
 0.08466;0.62034;1.79988;,
 0.08466;0.62034;1.79988;,
 0.08466;0.62034;1.79988;,
 0.08466;0.62034;1.56292;,
 0.08466;0.62034;1.56292;,
 0.08466;0.62034;1.56292;,
 0.08466;0.62034;1.56292;,
 0.08466;0.62034;1.56292;,
 0.08466;0.62034;1.56292;,
 0.08466;0.62034;1.56292;;
 
 200;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;1,8,9,2;,
 4;10,4,7,11;,
 4;8,12,13,9;,
 4;14,10,11,15;,
 4;12,16,17,13;,
 4;18,14,15,19;,
 4;16,20,21,17;,
 4;22,18,19,23;,
 4;20,24,25,21;,
 4;26,22,23,27;,
 4;24,28,29,25;,
 4;30,26,27,31;,
 4;28,32,33,29;,
 4;34,30,31,35;,
 4;0,5,36,37;,
 4;38,39,40,41;,
 4;37,36,42,43;,
 4;39,44,45,40;,
 4;43,42,46,47;,
 4;44,48,49,45;,
 4;47,46,50,51;,
 4;48,52,53,49;,
 4;51,50,54,55;,
 4;52,56,57,53;,
 4;55,54,58,59;,
 4;56,60,61,57;,
 4;59,58,62,63;,
 4;60,64,65,61;,
 4;63,62,5,0;,
 4;64,38,41,65;,
 4;66,67,68,69;,
 4;70,71,72,73;,
 4;67,74,75,68;,
 4;76,70,73,77;,
 4;74,78,79,75;,
 4;80,76,77,81;,
 4;78,82,83,79;,
 4;84,80,81,85;,
 4;82,86,87,83;,
 4;88,84,85,89;,
 4;86,90,91,87;,
 4;92,88,89,93;,
 4;90,94,95,91;,
 4;96,92,93,97;,
 4;94,98,99,95;,
 4;100,96,97,101;,
 4;66,71,102,103;,
 4;104,105,106,107;,
 4;103,102,108,109;,
 4;105,110,111,106;,
 4;109,108,112,113;,
 4;110,114,115,111;,
 4;113,112,116,117;,
 4;114,118,119,115;,
 4;117,116,120,121;,
 4;118,122,123,119;,
 4;121,120,124,125;,
 4;122,126,127,123;,
 4;125,124,128,129;,
 4;126,130,131,127;,
 4;129,128,71,66;,
 4;130,104,107,131;,
 4;132,133,134,135;,
 4;136,137,138,139;,
 4;133,140,141,134;,
 4;142,136,139,143;,
 4;140,144,145,141;,
 4;146,142,143,147;,
 4;144,148,149,145;,
 4;150,146,147,151;,
 4;148,152,153,149;,
 4;154,150,151,155;,
 4;152,156,157,153;,
 4;158,154,155,159;,
 4;156,160,161,157;,
 4;162,158,159,163;,
 4;160,164,165,161;,
 4;166,162,163,167;,
 4;132,137,168,169;,
 4;170,171,172,173;,
 4;169,168,174,175;,
 4;171,176,177,172;,
 4;175,174,178,179;,
 4;176,180,181,177;,
 4;179,178,182,183;,
 4;180,184,185,181;,
 4;183,182,186,187;,
 4;184,188,189,185;,
 4;187,186,190,191;,
 4;188,192,193,189;,
 4;191,190,194,195;,
 4;192,196,197,193;,
 4;195,194,137,132;,
 4;196,170,173,197;,
 4;198,199,200,201;,
 4;202,203,204,205;,
 4;206,207,208,209;,
 4;210,211,212,213;,
 4;210,203,214,215;,
 4;216,217,204,213;,
 4;218,219,220,221;,
 4;222,223,224,225;,
 4;219,226,227,220;,
 4;228,222,225,229;,
 4;226,230,231,227;,
 4;232,228,229,233;,
 4;230,234,235,231;,
 4;236,232,233,237;,
 4;234,238,239,235;,
 4;240,236,237,241;,
 4;238,242,243,239;,
 4;244,240,241,245;,
 4;242,246,247,243;,
 4;248,244,245,249;,
 4;246,250,251,247;,
 4;252,248,249,253;,
 4;218,223,254,255;,
 4;256,257,258,259;,
 4;255,254,260,261;,
 4;257,262,263,258;,
 4;261,260,264,265;,
 4;262,266,267,263;,
 4;265,264,268,269;,
 4;266,270,271,267;,
 4;269,268,272,273;,
 4;270,274,275,271;,
 4;273,272,276,277;,
 4;274,278,279,275;,
 4;277,276,280,281;,
 4;278,282,283,279;,
 4;281,280,223,218;,
 4;282,256,259,283;,
 4;284,285,286,287;,
 4;285,288,289,286;,
 4;288,290,291,289;,
 4;290,292,293,291;,
 4;292,294,295,293;,
 4;294,296,297,295;,
 4;296,298,299,297;,
 4;298,300,301,299;,
 3;302,285,284;,
 3;303,288,285;,
 3;304,290,288;,
 3;305,292,290;,
 3;306,294,292;,
 3;307,296,294;,
 3;308,298,296;,
 3;309,300,298;,
 3;310,287,286;,
 3;311,286,289;,
 3;312,289,291;,
 3;313,291,293;,
 3;314,293,295;,
 3;315,295,297;,
 3;316,297,299;,
 3;317,299,301;,
 4;318,319,320,321;,
 4;319,322,323,320;,
 4;322,324,325,323;,
 4;324,326,327,325;,
 4;326,328,329,327;,
 4;328,330,331,329;,
 4;330,332,333,331;,
 3;334,319,318;,
 3;335,322,319;,
 3;336,324,322;,
 3;337,326,324;,
 3;338,328,326;,
 3;339,330,328;,
 3;340,332,330;,
 3;341,321,320;,
 3;342,320,323;,
 3;343,323,325;,
 3;344,325,327;,
 3;345,327,329;,
 3;346,329,331;,
 3;347,331,333;,
 4;348,349,350,351;,
 4;349,352,353,350;,
 4;352,354,355,353;,
 4;354,356,357,355;,
 4;356,358,359,357;,
 4;358,360,361,359;,
 4;360,362,363,361;,
 3;364,349,348;,
 3;365,352,349;,
 3;366,354,352;,
 3;367,356,354;,
 3;368,358,356;,
 3;369,360,358;,
 3;370,362,360;,
 3;371,351,350;,
 3;372,350,353;,
 3;373,353,355;,
 3;374,355,357;,
 3;375,357,359;,
 3;376,359,361;,
 3;377,361,363;;
 
 MeshMaterialList {
  1;
  200;
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
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.217210;0.174000;0.000000;1.000000;;
   26.000000;
   0.170000;0.170000;0.170000;;
   0.606690;0.486000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Desktop\\sabi.jpg";
   }
  }
 }
 MeshNormals {
  91;
  0.000000;0.000000;-1.000000;,
  0.707105;0.000000;-0.707108;,
  1.000000;0.000000;0.000001;,
  0.707108;0.000000;0.707106;,
  0.000000;0.000000;1.000000;,
  -0.707108;0.000000;0.707106;,
  -1.000000;0.000000;0.000001;,
  -0.707105;0.000000;-0.707109;,
  -0.000001;0.000000;1.000000;,
  -0.707108;0.000000;0.707105;,
  -1.000000;0.000000;0.000000;,
  -0.707107;0.000000;-0.707107;,
  -0.000001;0.000000;-1.000000;,
  0.707108;0.000000;-0.707106;,
  1.000000;0.000000;0.000000;,
  0.707109;0.000000;0.707104;,
  -0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.707108;0.000000;0.707105;,
  -0.000000;0.000000;1.000000;,
  -0.707108;0.000000;0.707105;,
  -1.000000;0.000000;0.000000;,
  -0.707107;0.000000;-0.707106;,
  -0.000001;0.000000;1.000000;,
  -1.000000;0.000000;-0.000001;,
  -0.707105;0.000000;-0.707108;,
  -0.000001;0.000000;-1.000000;,
  0.707105;0.000000;-0.707108;,
  1.000000;0.000000;-0.000001;,
  0.707108;0.000000;0.707105;,
  -0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707106;,
  1.000000;0.000000;0.000000;,
  0.707108;0.000000;0.707105;,
  -0.000000;0.000000;1.000000;,
  -0.707107;0.000000;0.707106;,
  -1.000000;0.000000;0.000000;,
  -0.707106;0.000000;-0.707107;,
  0.000001;0.000000;1.000000;,
  -0.707108;0.000000;0.707105;,
  -1.000000;0.000000;-0.000001;,
  -0.707105;0.000000;-0.707108;,
  0.000001;0.000000;-1.000000;,
  0.707105;0.000000;-0.707108;,
  1.000000;0.000000;-0.000001;,
  0.707108;0.000000;0.707105;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000001;0.000000;-1.000000;,
  0.707108;0.000000;-0.707106;,
  1.000000;0.000000;-0.000000;,
  0.707109;0.000000;0.707104;,
  0.000001;0.000000;1.000000;,
  -0.707108;0.000000;0.707106;,
  -1.000000;0.000000;-0.000000;,
  -0.707106;0.000000;-0.707107;,
  -0.000002;0.000000;1.000000;,
  -0.707107;0.000000;0.707107;,
  -1.000000;0.000000;0.000001;,
  -0.707106;0.000000;-0.707107;,
  -0.000002;0.000000;-1.000000;,
  0.707105;0.000000;-0.707109;,
  1.000000;0.000000;0.000001;,
  0.707106;0.000000;0.707108;,
  -0.000002;0.999994;0.003357;,
  0.670034;0.742322;0.003593;,
  0.999992;0.000000;0.004009;,
  0.670034;-0.742321;0.003906;,
  -0.000002;-0.999993;0.003779;,
  -0.670039;-0.742315;0.004059;,
  -0.999991;0.000000;0.004236;,
  -0.670040;0.742316;0.003746;,
  0.000000;1.000000;0.000000;,
  0.781834;0.623486;0.000000;,
  0.974928;-0.222522;-0.000000;,
  0.433886;-0.900968;-0.000000;,
  -0.433886;-0.900968;0.000000;,
  -0.974928;-0.222522;0.000000;,
  -0.781834;0.623486;0.000000;,
  0.000000;1.000000;0.000000;,
  0.781832;0.623489;0.000000;,
  0.974929;-0.222518;-0.000000;,
  0.433883;-0.900969;-0.000000;,
  -0.433883;-0.900969;0.000000;,
  -0.974929;-0.222518;0.000000;,
  -0.781832;0.623489;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -1.000000;0.000000;0.000000;;
  200;
  4;0,1,1,0;,
  4;9,8,8,9;,
  4;1,2,2,1;,
  4;10,9,9,10;,
  4;2,3,3,2;,
  4;11,10,10,11;,
  4;3,4,4,3;,
  4;12,11,11,12;,
  4;4,5,5,4;,
  4;13,12,12,13;,
  4;5,6,6,5;,
  4;14,13,13,14;,
  4;6,7,7,6;,
  4;15,14,14,15;,
  4;7,0,0,7;,
  4;8,15,15,8;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;16,17,17,16;,
  4;9,24,24,9;,
  4;17,18,18,17;,
  4;25,9,9,25;,
  4;18,19,19,18;,
  4;26,25,25,26;,
  4;19,20,20,19;,
  4;27,26,26,27;,
  4;20,21,21,20;,
  4;28,27,27,28;,
  4;21,22,22,21;,
  4;29,28,28,29;,
  4;22,23,23,22;,
  4;30,29,29,30;,
  4;23,16,16,23;,
  4;24,30,30,24;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;31,32,32,31;,
  4;40,39,39,40;,
  4;32,33,33,32;,
  4;41,40,40,41;,
  4;33,34,34,33;,
  4;42,41,41,42;,
  4;34,35,35,34;,
  4;43,42,42,43;,
  4;35,36,36,35;,
  4;44,43,43,44;,
  4;36,37,37,36;,
  4;45,44,44,45;,
  4;37,38,38,37;,
  4;46,45,45,46;,
  4;38,31,31,38;,
  4;39,46,46,39;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;47,47,47,47;,
  4;48,48,48,48;,
  4;49,49,49,49;,
  4;90,90,90,90;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;50,51,51,50;,
  4;59,58,58,59;,
  4;51,52,52,51;,
  4;60,59,59,60;,
  4;52,53,53,52;,
  4;61,60,60,61;,
  4;53,54,54,53;,
  4;62,61,61,62;,
  4;54,55,55,54;,
  4;63,62,62,63;,
  4;55,56,56,55;,
  4;64,63,63,64;,
  4;56,57,57,56;,
  4;65,64,64,65;,
  4;57,50,50,57;,
  4;58,65,65,58;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;66,67,67,66;,
  4;67,68,68,67;,
  4;68,69,69,68;,
  4;69,70,70,69;,
  4;70,71,71,70;,
  4;71,72,72,71;,
  4;72,73,73,72;,
  4;73,66,66,73;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  4;74,75,75,74;,
  4;75,76,76,75;,
  4;76,77,77,76;,
  4;77,78,78,77;,
  4;78,79,79,78;,
  4;79,80,80,79;,
  4;80,74,74,80;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  4;81,82,82,81;,
  4;82,83,83,82;,
  4;83,84,84,83;,
  4;84,85,85,84;,
  4;85,86,86,85;,
  4;86,87,87,86;,
  4;87,81,81,87;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;49,49,49;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;,
  3;47,47,47;;
 }
 MeshTextureCoords {
  378;
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.125000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.125000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.125000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.125000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.125000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.125000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.125000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.125000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.187500;0.000000;,
  0.312500;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.687500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.000000;0.000000;,
  0.142860;0.000000;,
  0.142860;1.000000;,
  0.000000;1.000000;,
  0.285710;0.000000;,
  0.285710;1.000000;,
  0.428570;0.000000;,
  0.428570;1.000000;,
  0.571430;0.000000;,
  0.571430;1.000000;,
  0.714290;0.000000;,
  0.714290;1.000000;,
  0.857140;0.000000;,
  0.857140;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.071430;0.000000;,
  0.214290;0.000000;,
  0.357140;0.000000;,
  0.500000;0.000000;,
  0.642860;0.000000;,
  0.785710;0.000000;,
  0.928570;0.000000;,
  0.071430;1.000000;,
  0.214290;1.000000;,
  0.357140;1.000000;,
  0.500000;1.000000;,
  0.642860;1.000000;,
  0.785710;1.000000;,
  0.928570;1.000000;,
  0.000000;0.000000;,
  0.142860;0.000000;,
  0.142860;1.000000;,
  0.000000;1.000000;,
  0.285710;0.000000;,
  0.285710;1.000000;,
  0.428570;0.000000;,
  0.428570;1.000000;,
  0.571430;0.000000;,
  0.571430;1.000000;,
  0.714290;0.000000;,
  0.714290;1.000000;,
  0.857140;0.000000;,
  0.857140;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.071430;0.000000;,
  0.214290;0.000000;,
  0.357140;0.000000;,
  0.500000;0.000000;,
  0.642860;0.000000;,
  0.785710;0.000000;,
  0.928570;0.000000;,
  0.071430;1.000000;,
  0.214290;1.000000;,
  0.357140;1.000000;,
  0.500000;1.000000;,
  0.642860;1.000000;,
  0.785710;1.000000;,
  0.928570;1.000000;;
 }
}
