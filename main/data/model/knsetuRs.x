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
 90;
 -0.04030;-0.00002;-0.12394;,
 -0.04030;-0.03383;-0.11908;,
 -10.23030;-0.03383;-0.11908;,
 -10.23030;-0.00002;-0.12394;,
 -0.04030;-0.06490;-0.10489;,
 -10.23030;-0.06490;-0.10489;,
 -0.04030;-0.09071;-0.08253;,
 -10.23030;-0.09071;-0.08253;,
 -0.04030;-0.10918;-0.05379;,
 -10.23030;-0.10918;-0.05379;,
 -0.04030;-0.11880;-0.02102;,
 -10.23030;-0.11880;-0.02102;,
 -0.04030;-0.11880;0.01314;,
 -10.23030;-0.11880;0.01314;,
 -0.04030;-0.10918;0.04591;,
 -10.23030;-0.10918;0.04591;,
 -0.04030;-0.09071;0.07464;,
 -10.23030;-0.09071;0.07464;,
 -0.04030;-0.06490;0.09701;,
 -10.23030;-0.06490;0.09701;,
 -0.04030;-0.03383;0.11120;,
 -10.23030;-0.03383;0.11120;,
 -0.04030;-0.00002;0.11606;,
 -10.23030;-0.00002;0.11606;,
 -0.04030;0.03379;0.11120;,
 -10.23030;0.03379;0.11120;,
 -0.04030;0.06486;0.09701;,
 -10.23030;0.06486;0.09701;,
 -0.04030;0.09067;0.07464;,
 -10.23030;0.09067;0.07464;,
 -0.04030;0.10914;0.04591;,
 -10.23030;0.10914;0.04591;,
 -0.04030;0.11876;0.01314;,
 -10.23030;0.11876;0.01314;,
 -0.04030;0.11876;-0.02102;,
 -10.23030;0.11876;-0.02102;,
 -0.04030;0.10914;-0.05379;,
 -10.23030;0.10914;-0.05379;,
 -0.04030;0.09067;-0.08253;,
 -10.23030;0.09067;-0.08253;,
 -0.04030;0.06486;-0.10489;,
 -10.23030;0.06486;-0.10489;,
 -0.04030;0.03379;-0.11908;,
 -10.23030;0.03379;-0.11908;,
 -0.04030;-0.00002;-0.12394;,
 -10.23030;-0.00002;-0.12394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -0.04030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;,
 -10.23030;-0.00002;-0.00394;;
 
 66;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;16,18,19,17;,
 4;18,20,21,19;,
 4;20,22,23,21;,
 4;22,24,25,23;,
 4;24,26,27,25;,
 4;26,28,29,27;,
 4;28,30,31,29;,
 4;30,32,33,31;,
 4;32,34,35,33;,
 4;34,36,37,35;,
 4;36,38,39,37;,
 4;38,40,41,39;,
 4;40,42,43,41;,
 4;42,44,45,43;,
 3;46,1,0;,
 3;47,4,1;,
 3;48,6,4;,
 3;49,8,6;,
 3;50,10,8;,
 3;51,12,10;,
 3;52,14,12;,
 3;53,16,14;,
 3;54,18,16;,
 3;55,20,18;,
 3;56,22,20;,
 3;57,24,22;,
 3;58,26,24;,
 3;59,28,26;,
 3;60,30,28;,
 3;61,32,30;,
 3;62,34,32;,
 3;63,36,34;,
 3;64,38,36;,
 3;65,40,38;,
 3;66,42,40;,
 3;67,44,42;,
 3;68,3,2;,
 3;69,2,5;,
 3;70,5,7;,
 3;71,7,9;,
 3;72,9,11;,
 3;73,11,13;,
 3;74,13,15;,
 3;75,15,17;,
 3;76,17,19;,
 3;77,19,21;,
 3;78,21,23;,
 3;79,23,25;,
 3;80,25,27;,
 3;81,27,29;,
 3;82,29,31;,
 3;83,31,33;,
 3;84,33,35;,
 3;85,35,37;,
 3;86,37,39;,
 3;87,39,41;,
 3;88,41,43;,
 3;89,43,45;;
 
 MeshMaterialList {
  1;
  66;
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
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  24;
  1.000000;0.000000;0.000000;,
  -0.000000;-0.000000;-1.000000;,
  -0.000000;-0.281731;-0.959493;,
  -0.000000;-0.540641;-0.841254;,
  -0.000000;-0.755749;-0.654861;,
  -0.000000;-0.909632;-0.415415;,
  -0.000000;-0.989822;-0.142315;,
  -0.000000;-0.989822;0.142315;,
  -0.000000;-0.909632;0.415415;,
  -0.000000;-0.755749;0.654861;,
  -0.000000;-0.540641;0.841253;,
  -0.000000;-0.281731;0.959494;,
  -0.000000;-0.000000;1.000000;,
  0.000000;0.281731;0.959494;,
  0.000000;0.540641;0.841253;,
  0.000000;0.755749;0.654862;,
  0.000000;0.909632;0.415415;,
  0.000000;0.989821;0.142315;,
  0.000000;0.989822;-0.142314;,
  0.000000;0.909633;-0.415412;,
  0.000000;0.755752;-0.654858;,
  0.000000;0.540641;-0.841253;,
  0.000000;0.281731;-0.959494;,
  -1.000000;0.000000;0.000000;;
  66;
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;4,5,5,4;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,8,8,7;,
  4;8,9,9,8;,
  4;9,10,10,9;,
  4;10,11,11,10;,
  4;11,12,12,11;,
  4;12,13,13,12;,
  4;13,14,14,13;,
  4;14,15,15,14;,
  4;15,16,16,15;,
  4;16,17,17,16;,
  4;17,18,18,17;,
  4;18,19,19,18;,
  4;19,20,20,19;,
  4;20,21,21,20;,
  4;21,22,22,21;,
  4;22,1,1,22;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;;
 }
 MeshTextureCoords {
  90;
  0.000000;0.000000;,
  0.045455;0.000000;,
  0.045455;1.000000;,
  0.000000;1.000000;,
  0.090909;0.000000;,
  0.090909;1.000000;,
  0.136364;0.000000;,
  0.136364;1.000000;,
  0.181818;0.000000;,
  0.181818;1.000000;,
  0.227273;0.000000;,
  0.227273;1.000000;,
  0.272727;0.000000;,
  0.272727;1.000000;,
  0.318182;0.000000;,
  0.318182;1.000000;,
  0.363636;0.000000;,
  0.363636;1.000000;,
  0.409091;0.000000;,
  0.409091;1.000000;,
  0.454545;0.000000;,
  0.454545;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.545455;0.000000;,
  0.545455;1.000000;,
  0.590909;0.000000;,
  0.590909;1.000000;,
  0.636364;0.000000;,
  0.636364;1.000000;,
  0.681818;0.000000;,
  0.681818;1.000000;,
  0.727273;0.000000;,
  0.727273;1.000000;,
  0.772727;0.000000;,
  0.772727;1.000000;,
  0.818182;0.000000;,
  0.818182;1.000000;,
  0.863637;0.000000;,
  0.863637;1.000000;,
  0.909091;0.000000;,
  0.909091;1.000000;,
  0.954546;0.000000;,
  0.954546;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.022727;0.000000;,
  0.068182;0.000000;,
  0.113636;0.000000;,
  0.159091;0.000000;,
  0.204545;0.000000;,
  0.250000;0.000000;,
  0.295455;0.000000;,
  0.340909;0.000000;,
  0.386364;0.000000;,
  0.431818;0.000000;,
  0.477273;0.000000;,
  0.522727;0.000000;,
  0.568182;0.000000;,
  0.613636;0.000000;,
  0.659091;0.000000;,
  0.704546;0.000000;,
  0.750000;0.000000;,
  0.795455;0.000000;,
  0.840909;0.000000;,
  0.886364;0.000000;,
  0.931818;0.000000;,
  0.977273;0.000000;,
  0.022727;1.000000;,
  0.068182;1.000000;,
  0.113636;1.000000;,
  0.159091;1.000000;,
  0.204545;1.000000;,
  0.250000;1.000000;,
  0.295455;1.000000;,
  0.340909;1.000000;,
  0.386364;1.000000;,
  0.431818;1.000000;,
  0.477273;1.000000;,
  0.522727;1.000000;,
  0.568182;1.000000;,
  0.613636;1.000000;,
  0.659091;1.000000;,
  0.704546;1.000000;,
  0.750000;1.000000;,
  0.795455;1.000000;,
  0.840909;1.000000;,
  0.886364;1.000000;,
  0.931818;1.000000;,
  0.977273;1.000000;;
 }
}
