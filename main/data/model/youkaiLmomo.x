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
 28;
 -0.44632;-11.94918;-0.58676;,
 -0.43301;-11.95970;0.17603;,
 -0.42621;0.74021;0.56509;,
 -0.43953;0.75073;-0.19771;,
 0.23439;-11.96494;0.54590;,
 0.24118;0.73497;0.93496;,
 0.88848;-11.95970;0.15298;,
 0.89527;0.74021;0.54203;,
 0.87516;-11.94918;-0.60983;,
 0.88195;0.75073;-0.22077;,
 0.20776;-11.94393;-0.97969;,
 0.21455;0.75597;-0.59064;,
 -0.44632;-11.94918;-0.58676;,
 -0.43953;0.75073;-0.19771;,
 -0.43301;-11.95970;0.17603;,
 -0.44632;-11.94918;-0.58676;,
 0.22108;-11.95443;-0.21690;,
 0.23439;-11.96494;0.54590;,
 0.88848;-11.95970;0.15298;,
 0.87516;-11.94918;-0.60983;,
 0.20776;-11.94393;-0.97969;,
 -0.43953;0.75073;-0.19771;,
 -0.42621;0.74021;0.56509;,
 0.22787;0.74547;0.17217;,
 0.24118;0.73497;0.93496;,
 0.89527;0.74021;0.54203;,
 0.88195;0.75073;-0.22077;,
 0.21455;0.75597;-0.59064;;
 
 18;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 3;14,15,16;,
 3;17,14,16;,
 3;18,17,16;,
 3;19,18,16;,
 3;20,19,16;,
 3;15,20,16;,
 3;21,22,23;,
 3;22,24,23;,
 3;24,25,23;,
 3;25,26,23;,
 3;26,27,23;,
 3;27,21,23;;
 
 MeshMaterialList {
  1;
  18;
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
  20;
  -0.999848;0.000000;0.017454;,
  -0.484724;-0.026523;0.874265;,
  0.514928;-0.026524;0.856823;,
  0.999848;-0.000000;-0.017454;,
  0.484717;0.026523;-0.874269;,
  -0.000240;-0.999905;-0.013773;,
  0.000240;0.999905;0.013768;,
  -0.514940;0.026523;-0.856816;,
  -0.000217;-0.999905;-0.013781;,
  -0.000231;-0.999905;-0.013773;,
  -0.000240;-0.999905;-0.013773;,
  -0.000264;-0.999905;-0.013781;,
  -0.000250;-0.999905;-0.013773;,
  -0.000240;-0.999905;-0.013757;,
  0.000248;0.999905;0.013772;,
  0.000233;0.999905;0.013772;,
  0.000240;0.999905;0.013759;,
  0.000248;0.999905;0.013772;,
  0.000233;0.999905;0.013772;,
  0.000240;0.999905;0.013759;;
  18;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;7,7,7,7;,
  3;8,9,5;,
  3;10,8,5;,
  3;11,10,5;,
  3;12,11,5;,
  3;13,12,5;,
  3;9,13,5;,
  3;14,15,6;,
  3;15,16,6;,
  3;16,17,6;,
  3;17,18,6;,
  3;18,19,6;,
  3;19,14,6;;
 }
 MeshTextureCoords {
  28;
  0.375000;0.312500;,
  0.416670;0.312500;,
  0.416670;0.687500;,
  0.375000;0.687500;,
  0.458330;0.312500;,
  0.458330;0.687500;,
  0.500000;0.312500;,
  0.500000;0.687500;,
  0.541670;0.312500;,
  0.541670;0.687500;,
  0.583330;0.312500;,
  0.583330;0.687500;,
  0.625000;0.312500;,
  0.625000;0.687500;,
  0.421880;0.020930;,
  0.578120;0.020930;,
  0.500000;0.156250;,
  0.343750;0.156250;,
  0.421880;0.291570;,
  0.578120;0.291570;,
  0.656250;0.156250;,
  0.578120;0.979070;,
  0.421880;0.979070;,
  0.500000;0.843750;,
  0.343750;0.843750;,
  0.421880;0.708430;,
  0.578120;0.708430;,
  0.656250;0.843750;;
 }
}
