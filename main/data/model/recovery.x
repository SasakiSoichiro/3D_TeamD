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
 57;
 -6.19522;19.62942;8.15062;,
 6.19522;19.62942;8.15062;,
 6.19522;19.62942;-8.15062;,
 -6.19522;19.62942;-8.15062;,
 -6.19522;1.16346;-8.15062;,
 6.19522;1.16346;-8.15062;,
 6.19522;1.16346;8.15062;,
 -6.19522;1.16346;8.15062;,
 6.19522;17.56079;-8.15062;,
 -6.19522;17.56079;-8.15062;,
 6.19522;17.49837;8.15062;,
 -6.19522;17.49837;8.15062;,
 -6.75055;17.63772;-8.49127;,
 6.75055;17.63772;-8.49127;,
 6.75055;19.54770;-8.49127;,
 -6.75055;19.54770;-8.49127;,
 6.75055;17.58009;8.49127;,
 6.75055;19.54770;8.49127;,
 -6.75055;17.58009;8.49127;,
 -6.75055;19.54770;8.49127;,
 -6.41701;14.13999;-0.60931;,
 -5.84601;14.13999;-0.60931;,
 -5.84601;6.65288;-0.60931;,
 -6.41701;6.65288;-0.60931;,
 -5.84601;14.13999;0.60931;,
 -5.84601;6.65288;0.60931;,
 -6.41701;14.13999;0.60931;,
 -6.41701;6.65288;0.60931;,
 -6.34875;11.37506;-2.30768;,
 -5.77204;11.37506;-2.30768;,
 -5.77204;9.41782;-2.30768;,
 -6.34875;9.41782;-2.30768;,
 -5.77204;11.37506;2.30768;,
 -5.77204;9.41782;2.30768;,
 -6.34875;11.37506;2.30768;,
 -6.34875;9.41782;2.30768;,
 4.43143;21.84031;0.16521;,
 4.99845;23.02329;0.25365;,
 4.40472;22.91513;-2.37693;,
 3.93144;21.74922;-2.05001;,
 5.35017;21.63196;0.20301;,
 4.75644;21.52380;-2.42756;,
 2.50572;21.86142;-4.29924;,
 2.33229;20.86187;-3.66880;,
 2.85744;20.47009;-4.34987;,
 -0.09563;20.19670;-4.90296;,
 0.14168;19.46002;-4.17720;,
 0.25609;18.80538;-4.95360;,
 -0.33057;18.28281;3.73851;,
 -0.65643;18.79875;4.49694;,
 1.99035;20.57672;4.33914;,
 1.89829;19.78003;3.60563;,
 -0.30471;17.40742;4.44631;,
 2.34207;19.18539;4.28850;,
 4.09840;22.15155;2.75730;,
 3.67349;21.10622;2.27355;,
 4.45012;20.76023;2.70667;;
 
 48;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,5,4,9;,
 4;10,6,5,8;,
 4;11,7,6,10;,
 4;9,4,7,11;,
 4;12,13,8,9;,
 4;14,15,3,2;,
 4;13,12,15,14;,
 4;13,16,10,8;,
 4;17,14,2,1;,
 4;16,13,14,17;,
 4;16,18,11,10;,
 4;19,17,1,0;,
 4;18,16,17,19;,
 4;18,12,9,11;,
 4;15,19,0,3;,
 4;12,18,19,15;,
 4;20,21,22,23;,
 4;21,24,25,22;,
 4;24,26,27,25;,
 4;26,20,23,27;,
 4;26,24,21,20;,
 4;23,22,25,27;,
 4;28,29,30,31;,
 4;29,32,33,30;,
 4;32,34,35,33;,
 4;34,28,31,35;,
 4;34,32,29,28;,
 4;31,30,33,35;,
 4;36,37,38,39;,
 4;37,40,41,38;,
 4;40,36,39,41;,
 4;39,38,42,43;,
 4;38,41,44,42;,
 4;41,39,43,44;,
 4;43,42,45,46;,
 4;42,44,47,45;,
 4;44,43,46,47;,
 4;48,49,50,51;,
 4;49,52,53,50;,
 4;52,48,51,53;,
 4;51,50,54,55;,
 4;50,53,56,54;,
 4;53,51,55,56;,
 4;55,54,37,36;,
 4;54,56,40,37;,
 4;56,55,36,40;;
 
 MeshMaterialList {
  2;
  48;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.960000;0.960000;0.960000;;
  }
  Material {
   0.800000;0.000000;0.116078;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.950000;0.000000;0.137843;;
  }
 }
}
