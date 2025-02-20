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
 274;
 80.52009;9.32742;-41.54102;,
 66.96505;9.32742;-41.54102;,
 66.96505;11.17014;-41.54102;,
 80.52009;11.17014;-41.54102;,
 29.22387;9.32742;-41.54102;,
 29.22387;11.17014;-41.54102;,
 -72.88504;9.32742;-41.54102;,
 -84.50347;9.32742;-41.54102;,
 -84.50347;11.17014;-41.54102;,
 -72.88504;11.17014;-41.54102;,
 80.52009;124.97248;-40.00781;,
 66.96505;124.97248;-40.00781;,
 66.96505;123.08788;-34.11372;,
 80.52009;123.08788;-34.11372;,
 66.96505;13.73348;-41.54102;,
 29.22387;13.73348;-41.54102;,
 29.22387;13.73348;-35.42108;,
 66.96505;13.73348;-35.42108;,
 -72.88504;124.97248;-40.00781;,
 -84.50347;124.97248;-40.00781;,
 -84.50347;123.08788;-34.11372;,
 -72.88504;123.08788;-34.11372;,
 66.96505;101.29809;34.02637;,
 80.52009;101.29809;34.02637;,
 66.96505;11.17014;-35.42108;,
 29.22387;11.17014;-35.42108;,
 29.22387;11.17014;35.33037;,
 66.96505;11.17014;35.33037;,
 -84.50347;101.29809;34.02637;,
 -72.88504;101.29809;34.02637;,
 66.96505;99.38529;40.00781;,
 80.52009;99.38529;40.00781;,
 29.22387;101.29809;34.02637;,
 29.22387;99.38529;40.00781;,
 -84.50347;99.38529;40.00781;,
 -72.88504;99.38529;40.00781;,
 80.52009;11.17014;41.54102;,
 66.96505;11.17014;41.54102;,
 66.96505;9.32742;41.54102;,
 80.52009;9.32742;41.54102;,
 29.22387;11.17014;41.54102;,
 29.22387;9.32742;41.54102;,
 -72.88504;11.17014;41.54102;,
 -84.50347;11.17014;41.54102;,
 -84.50347;9.32742;41.54102;,
 -72.88504;9.32742;41.54102;,
 66.96505;9.32742;35.33035;,
 80.52009;9.32742;35.33035;,
 29.22387;9.32742;35.33035;,
 -84.50347;9.32742;35.33035;,
 -72.88504;9.32742;35.33035;,
 66.96505;9.32742;-35.42108;,
 80.52009;9.32742;-35.42108;,
 29.22387;9.32742;-35.42108;,
 -84.50347;9.32742;-35.42108;,
 -72.88504;9.32742;-35.42108;,
 -84.50347;11.17014;35.33037;,
 -84.50347;11.17014;-35.42108;,
 80.52009;11.17014;35.33037;,
 80.52009;11.17014;-35.42108;,
 80.52009;13.73348;-41.54102;,
 80.52009;13.73348;-35.42108;,
 -84.50347;13.73348;-41.54102;,
 -72.88504;13.73348;-41.54102;,
 -84.50347;13.73348;-35.42108;,
 66.96505;13.73348;35.33037;,
 80.52009;13.73348;35.33037;,
 -84.50347;13.73348;35.33037;,
 -72.88504;11.17014;35.33037;,
 -72.88504;11.17014;-35.42108;,
 -72.88504;13.73348;-35.42108;,
 -72.88504;13.73348;35.33037;,
 80.52009;13.73348;41.54102;,
 66.96505;13.73348;41.54102;,
 29.22387;13.73348;35.33037;,
 29.22387;13.73348;41.54102;,
 -84.50347;13.73348;41.54102;,
 -72.88504;13.73348;41.54102;,
 -41.02805;13.73348;-41.54102;,
 -41.02805;13.73348;-35.42108;,
 -41.02805;11.17014;-35.42108;,
 -41.02805;11.17014;35.33037;,
 -41.02805;13.73348;35.33037;,
 -41.02805;101.29809;34.02637;,
 -41.02805;99.38529;40.00781;,
 -41.02805;13.73348;41.54102;,
 -41.02805;11.17014;41.54102;,
 -41.02805;9.32742;41.54102;,
 -41.02805;9.32742;35.33035;,
 -41.02805;9.32742;-35.42108;,
 -41.02805;9.32742;-41.54102;,
 -41.02805;11.17014;-41.54102;,
 -34.02447;11.17014;-41.54102;,
 -34.02447;13.73348;-41.54102;,
 -34.02447;126.08163;-35.42108;,
 -34.02447;126.08163;-41.54102;,
 -41.02805;126.08163;-41.54102;,
 -41.02805;126.08163;-35.42108;,
 -34.02447;11.17014;-35.42108;,
 -34.02447;13.73348;-35.42108;,
 -34.02447;11.17014;35.33037;,
 -34.02447;13.73348;35.33037;,
 -34.02447;101.21339;29.68467;,
 -34.02447;13.64882;30.98869;,
 -41.02805;13.64882;30.98869;,
 -41.02805;101.21339;29.68467;,
 -34.02447;99.38529;40.00781;,
 -34.02447;101.29809;34.02637;,
 -34.02447;13.73348;41.54102;,
 -34.02447;11.17014;41.54102;,
 -34.02447;9.32742;41.54102;,
 -34.02447;9.32742;35.33035;,
 -34.02447;9.32742;-35.42108;,
 -34.02447;9.32742;-41.54102;,
 -12.92375;9.32742;-35.42108;,
 -12.92375;9.32742;-41.54102;,
 -12.92375;11.17014;-41.54102;,
 -12.92375;13.73348;-41.54102;,
 -12.92375;13.73348;-35.42108;,
 -12.92375;11.17014;-35.42108;,
 -12.92375;11.17014;35.33037;,
 -12.92375;13.73348;35.33037;,
 -12.92375;101.29809;34.02637;,
 -12.92375;99.38529;40.00781;,
 -12.92375;13.73348;41.54102;,
 -12.92375;11.17014;41.54102;,
 -12.92375;9.32742;41.54102;,
 -12.92375;9.32742;35.33035;,
 -4.41407;126.86032;-41.54102;,
 -12.92375;126.86032;-41.54102;,
 -12.92375;126.86032;-35.42108;,
 -4.41407;126.86032;-35.42108;,
 -4.41407;11.17014;-35.42108;,
 -4.41407;13.73348;-35.42108;,
 -4.41407;11.17014;35.33037;,
 -4.41407;13.73348;35.33037;,
 -4.41407;101.21339;29.68467;,
 -4.41407;13.64882;30.98869;,
 -12.92375;13.64882;30.98869;,
 -12.92375;101.21339;29.68467;,
 -4.41407;99.38529;40.00781;,
 -4.41407;101.29809;34.02637;,
 -4.41407;13.73348;41.54102;,
 -4.41407;11.17014;41.54102;,
 -4.41407;9.32742;41.54102;,
 -4.41407;9.32742;35.33035;,
 -4.41407;9.32742;-35.42108;,
 -4.41407;9.32742;-41.54102;,
 -4.41407;11.17014;-41.54102;,
 -4.41407;13.73348;-41.54102;,
 17.97900;13.73348;-41.54102;,
 -4.41407;13.73348;-41.54102;,
 -4.41407;13.73348;-35.42108;,
 17.97900;13.73348;-35.42108;,
 17.97900;11.17014;-35.42108;,
 17.97900;13.73348;-35.42108;,
 17.97900;11.17014;35.33037;,
 17.97900;11.17014;-35.42108;,
 -4.41407;11.17014;-35.42108;,
 17.97900;13.73348;35.33037;,
 17.97900;101.29809;34.02637;,
 17.97900;99.38529;40.00781;,
 17.97900;13.73348;41.54102;,
 17.97900;11.17014;41.54102;,
 17.97900;9.32742;41.54102;,
 17.97900;9.32742;35.33035;,
 17.97900;9.32742;-35.42108;,
 -4.41407;9.32742;-35.42108;,
 17.97900;9.32742;-41.54102;,
 -4.41407;9.32742;-41.54102;,
 17.97900;11.17014;-41.54102;,
 -4.41407;11.17014;-41.54102;,
 29.22387;125.55563;-41.54102;,
 17.97900;125.55563;-41.54102;,
 17.97900;125.55563;-35.42108;,
 29.22387;125.55563;-35.42108;,
 29.22387;101.21339;29.68467;,
 29.22387;13.64882;30.98869;,
 17.97900;13.64882;30.98869;,
 17.97900;101.21339;29.68467;,
 79.04982;14.63157;-39.68960;,
 -78.61900;14.63157;-39.68960;,
 -78.61900;126.24948;-39.68960;,
 79.04982;126.24948;-39.68960;,
 -78.61900;101.41957;39.68960;,
 79.04982;101.41957;39.68960;,
 -78.61900;14.63157;39.68960;,
 79.04982;14.63157;39.68960;,
 -78.61900;14.63157;-39.68960;,
 79.04982;14.63157;-39.68960;,
 -78.61900;14.63157;39.68960;,
 -78.61900;101.41957;39.68960;,
 79.04982;14.63157;39.68960;,
 79.04982;101.41957;39.68960;,
 89.88517;126.96649;-49.48458;,
 -95.00308;126.70214;-46.86540;,
 -94.98255;131.43109;-45.68923;,
 89.90570;131.69555;-48.30845;,
 -92.50153;100.43588;49.48458;,
 92.38679;100.70014;46.86540;,
 -92.52200;95.70685;48.30845;,
 92.36624;95.97116;45.68923;,
 -95.00308;126.70214;-46.86540;,
 -94.98255;131.43109;-45.68923;,
 88.76151;0.92217;-46.41031;,
 -91.30499;0.92217;-46.41031;,
 -91.30499;11.18181;-46.41031;,
 88.76151;11.18181;-46.41031;,
 -91.30499;11.18181;46.41031;,
 88.76151;11.18181;46.41031;,
 -91.30499;0.92217;46.41031;,
 88.76151;0.92217;46.41031;,
 -91.30499;0.92217;-46.41031;,
 88.76151;0.92217;-46.41031;,
 -91.30499;0.92217;46.41031;,
 -91.30499;11.18181;46.41031;,
 88.76151;0.92217;46.41031;,
 88.76151;11.18181;46.41031;,
 -85.47393;16.55771;35.11116;,
 -82.95068;16.55771;35.11116;,
 -82.95068;53.46813;35.11116;,
 -85.47393;53.46813;35.11116;,
 -82.95068;87.04694;35.11116;,
 -85.47393;87.04694;35.11116;,
 -82.95068;92.91455;35.11116;,
 -85.47393;92.91455;35.11116;,
 -82.95068;92.91455;30.24125;,
 -85.47393;92.91455;30.24125;,
 -82.95068;92.91455;2.77320;,
 -85.47393;92.91455;2.77320;,
 -82.95068;92.91455;-1.19744;,
 -85.47393;92.91455;-1.19744;,
 -82.95068;87.04694;-1.19744;,
 -85.47393;87.04694;-1.19744;,
 -82.95068;53.46813;-1.19744;,
 -85.47393;53.46813;-1.19744;,
 -82.95068;16.55771;-1.19744;,
 -85.47393;16.55771;-1.19744;,
 -82.95068;16.55771;2.77320;,
 -85.47393;16.55771;2.77320;,
 -82.95068;16.55771;30.24125;,
 -85.47393;16.55771;30.24125;,
 -82.95068;53.46813;2.77320;,
 -82.95068;53.46813;30.24125;,
 -82.95068;87.04694;2.77320;,
 -82.95068;53.46813;30.24125;,
 -82.95068;53.46813;2.77320;,
 -82.95068;87.04694;2.77320;,
 -82.95068;87.04694;30.24125;,
 -82.95068;87.04694;30.24125;,
 -85.95151;16.55771;-1.19744;,
 -85.95151;16.55771;2.77320;,
 -85.95151;53.46813;2.77320;,
 -85.95151;53.46813;-1.19744;,
 -85.95151;16.55771;30.24125;,
 -85.95151;53.46813;30.24125;,
 -85.95151;16.55771;35.11116;,
 -85.95151;53.46813;35.11116;,
 -85.95151;87.04694;2.77320;,
 -85.95151;87.04694;-1.19744;,
 -85.47393;53.46813;2.77320;,
 -85.47393;53.46813;30.24125;,
 -85.47393;87.04694;30.24125;,
 -85.47393;87.04694;2.77320;,
 -85.95151;87.04694;35.11116;,
 -85.95151;87.04694;30.24125;,
 -85.95151;92.91455;2.77320;,
 -85.95151;92.91455;-1.19744;,
 -85.95151;92.91455;30.24125;,
 -85.95151;92.91455;35.11116;,
 -85.95151;53.46813;2.77320;,
 -85.95151;53.46813;30.24125;,
 -85.95151;87.04694;2.77320;,
 -85.95151;87.04694;30.24125;;
 
 234;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;6,7,8,9;,
 4;10,11,12,13;,
 4;14,15,16,17;,
 4;18,19,20,21;,
 4;13,12,22,23;,
 4;24,25,26,27;,
 4;21,20,28,29;,
 4;23,22,30,31;,
 4;22,32,33,30;,
 4;29,28,34,35;,
 4;36,37,38,39;,
 4;37,40,41,38;,
 4;42,43,44,45;,
 4;39,38,46,47;,
 4;38,41,48,46;,
 4;45,44,49,50;,
 4;47,46,51,52;,
 4;46,48,53,51;,
 4;50,49,54,55;,
 4;52,51,1,0;,
 4;51,53,4,1;,
 4;55,54,7,6;,
 4;49,44,43,56;,
 4;54,49,56,57;,
 4;7,54,57,8;,
 4;39,47,58,36;,
 4;47,52,59,58;,
 4;52,0,3,59;,
 4;3,2,14,60;,
 4;59,3,60,61;,
 4;2,5,15,14;,
 4;25,24,17,16;,
 4;9,8,62,63;,
 4;8,57,64,62;,
 4;24,27,65,17;,
 4;58,59,61,66;,
 4;57,56,67,64;,
 4;68,69,70,71;,
 4;37,36,72,73;,
 4;36,58,66,72;,
 4;27,26,74,65;,
 4;40,37,73,75;,
 4;56,43,76,67;,
 4;43,42,77,76;,
 4;60,14,11,10;,
 4;14,17,12,11;,
 4;61,60,10,13;,
 4;63,62,19,18;,
 4;62,64,20,19;,
 4;70,63,18,21;,
 4;17,65,22,12;,
 4;66,61,13,23;,
 4;64,67,28,20;,
 4;71,70,21,29;,
 4;73,72,31,30;,
 4;72,66,23,31;,
 4;65,74,32,22;,
 4;75,73,30,33;,
 4;67,76,34,28;,
 4;76,77,35,34;,
 4;78,63,70,79;,
 4;69,80,79,70;,
 4;81,80,69,68;,
 4;82,81,68,71;,
 4;83,82,71,29;,
 4;84,83,29,35;,
 4;77,85,84,35;,
 4;42,86,85,77;,
 4;87,86,42,45;,
 4;88,87,45,50;,
 4;89,88,50,55;,
 4;90,89,55,6;,
 4;91,90,6,9;,
 4;78,91,9,63;,
 4;92,91,78,93;,
 4;94,95,96,97;,
 4;80,98,99,79;,
 4;100,98,80,81;,
 4;101,100,81,82;,
 4;102,103,104,105;,
 4;106,107,83,84;,
 4;85,108,106,84;,
 4;86,109,108,85;,
 4;110,109,86,87;,
 4;111,110,87,88;,
 4;112,111,88,89;,
 4;113,112,89,90;,
 4;92,113,90,91;,
 4;114,112,113,115;,
 4;116,115,113,92;,
 4;117,116,92,93;,
 4;118,117,93,99;,
 4;98,119,118,99;,
 4;120,119,98,100;,
 4;121,120,100,101;,
 4;122,121,101,107;,
 4;123,122,107,106;,
 4;108,124,123,106;,
 4;109,125,124,108;,
 4;126,125,109,110;,
 4;127,126,110,111;,
 4;114,127,111,112;,
 4;128,129,130,131;,
 4;119,132,133,118;,
 4;134,132,119,120;,
 4;135,134,120,121;,
 4;136,137,138,139;,
 4;140,141,122,123;,
 4;124,142,140,123;,
 4;125,143,142,124;,
 4;144,143,125,126;,
 4;145,144,126,127;,
 4;146,145,127,114;,
 4;147,146,114,115;,
 4;148,147,115,116;,
 4;149,148,116,117;,
 4;150,151,152,153;,
 4;132,154,155,133;,
 4;156,157,158,134;,
 4;159,156,134,135;,
 4;160,159,135,141;,
 4;161,160,141,140;,
 4;142,162,161,140;,
 4;143,163,162,142;,
 4;164,163,143,144;,
 4;165,164,144,145;,
 4;166,165,145,167;,
 4;168,166,167,169;,
 4;170,168,169,171;,
 4;150,170,171,151;,
 4;172,173,174,175;,
 4;157,25,16,153;,
 4;26,25,157,156;,
 4;74,26,156,159;,
 4;176,177,178,179;,
 4;33,32,160,161;,
 4;162,75,33,161;,
 4;163,40,75,162;,
 4;41,40,163,164;,
 4;48,41,164,165;,
 4;53,48,165,166;,
 4;4,53,166,168;,
 4;5,4,168,170;,
 4;15,5,170,150;,
 4;99,93,95,94;,
 4;93,78,96,95;,
 4;78,79,97,96;,
 4;79,99,94,97;,
 4;149,117,129,128;,
 4;117,118,130,129;,
 4;118,133,131,130;,
 4;133,149,128,131;,
 4;15,150,173,172;,
 4;150,153,174,173;,
 4;153,16,175,174;,
 4;16,15,172,175;,
 4;107,101,103,102;,
 4;101,82,104,103;,
 4;82,83,105,104;,
 4;83,107,102,105;,
 4;141,135,137,136;,
 4;135,121,138,137;,
 4;121,122,139,138;,
 4;122,141,136,139;,
 4;32,74,177,176;,
 4;74,159,178,177;,
 4;159,160,179,178;,
 4;160,32,176,179;,
 4;180,181,182,183;,
 4;183,182,184,185;,
 4;185,184,186,187;,
 4;187,186,188,189;,
 4;181,190,191,182;,
 4;192,180,183,193;,
 4;194,195,196,197;,
 4;197,196,198,199;,
 4;199,198,200,201;,
 4;201,200,195,194;,
 4;202,200,198,203;,
 4;201,194,197,199;,
 4;204,205,206,207;,
 4;207,206,208,209;,
 4;209,208,210,211;,
 4;211,210,212,213;,
 4;205,214,215,206;,
 4;216,204,207,217;,
 4;218,219,220,221;,
 4;221,220,222,223;,
 4;223,222,224,225;,
 4;225,224,226,227;,
 4;227,226,228,229;,
 4;229,228,230,231;,
 4;231,230,232,233;,
 4;233,232,234,235;,
 4;235,234,236,237;,
 4;237,236,238,239;,
 4;239,238,240,241;,
 4;241,240,219,218;,
 4;238,236,234,242;,
 4;240,238,242,243;,
 4;219,240,243,220;,
 4;242,234,232,244;,
 4;245,246,247,248;,
 4;220,243,249,222;,
 4;244,232,230,228;,
 4;249,244,228,226;,
 4;222,249,226,224;,
 4;250,251,252,253;,
 4;251,254,255,252;,
 4;254,256,257,255;,
 4;253,252,258,259;,
 4;260,261,262,263;,
 4;255,257,264,265;,
 4;259,258,266,267;,
 4;258,265,268,266;,
 4;265,264,269,268;,
 4;237,239,251,250;,
 4;235,237,250,253;,
 4;239,241,254,251;,
 4;261,260,270,271;,
 4;241,218,256,254;,
 4;218,221,257,256;,
 4;260,263,272,270;,
 4;233,235,253,259;,
 4;221,223,264,257;,
 4;262,261,271,273;,
 4;229,231,267,266;,
 4;231,233,259,267;,
 4;263,262,273,272;,
 4;227,229,266,268;,
 4;223,225,269,264;,
 4;225,227,268,269;;
 
 MeshMaterialList {
  3;
  234;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  2,
  2,
  1,
  2,
  2,
  1,
  2,
  2,
  1,
  2,
  2,
  2;;
  Material {
   0.400000;0.400000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.684000;0.684000;0.684000;0.470000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\texture\\MYTEXTURE\\niwatori.jpeg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\texture\\MYTEXTURE\\wood00.jpg";
   }
  }
 }
 MeshNormals {
  63;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;0.006891;-0.999976;,
  0.000000;0.004594;-0.999989;,
  0.000000;0.006891;-0.999976;,
  0.000000;0.008949;0.999960;,
  0.000000;0.952495;0.304554;,
  0.000000;0.952490;0.304569;,
  0.000000;0.952483;0.304591;,
  0.000000;0.952484;0.304589;,
  0.000000;0.952484;0.304589;,
  0.000000;0.952482;0.304594;,
  0.000000;-0.004964;-0.999988;,
  0.000000;-0.014890;-0.999889;,
  0.000000;0.008949;0.999960;,
  0.000000;0.980010;0.198947;,
  0.000000;0.952483;0.304594;,
  0.000000;-0.014890;-0.999889;,
  0.000000;-0.004964;-0.999988;,
  0.000000;-0.014890;-0.999889;,
  0.000000;-0.014890;-0.999889;,
  0.000000;0.004594;-0.999989;,
  0.000000;-0.007445;-0.999972;,
  0.000000;0.013782;-0.999905;,
  0.000000;0.013782;-0.999905;,
  0.000000;0.017898;0.999840;,
  0.000000;0.017898;0.999840;,
  0.000000;-0.014890;-0.999889;,
  0.000000;0.017898;0.999840;,
  0.000000;-0.007445;-0.999972;,
  0.000000;0.017898;0.999840;,
  0.000000;0.017898;0.999840;,
  0.000000;-0.999810;0.019496;,
  0.000000;0.999810;-0.019503;,
  0.000000;0.999810;-0.019503;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.954398;0.298537;,
  0.000000;0.000000;1.000000;,
  0.000000;-1.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  -0.014091;0.241390;-0.970326;,
  0.003026;0.950865;0.309590;,
  0.014091;-0.241390;0.970326;,
  -0.003026;-0.950865;-0.309590;,
  -0.999675;-0.001987;0.025413;,
  0.999675;0.001979;-0.025416;,
  0.000000;0.000000;-1.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;-1.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;-1.000000;-0.000000;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;;
  234;
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;10,10,11,11;,
  4;2,2,2,2;,
  4;10,10,11,11;,
  4;11,11,12,13;,
  4;2,2,2,2;,
  4;11,11,14,12;,
  4;13,12,15,15;,
  4;12,19,15,15;,
  4;12,14,15,15;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;0,0,25,6;,
  4;1,1,1,1;,
  4;0,0,0,25;,
  4;4,4,4,4;,
  4;0,0,8,7;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;4,4,9,9;,
  4;1,1,1,1;,
  4;0,0,22,26;,
  4;4,4,9,9;,
  4;3,3,3,3;,
  4;4,4,9,9;,
  4;6,25,27,27;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;7,8,28,28;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;9,9,29,30;,
  4;1,1,1,1;,
  4;26,22,31,31;,
  4;9,9,30,30;,
  4;3,3,3,3;,
  4;9,9,30,32;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;16,0,0,33;,
  4;17,16,33,17;,
  4;15,19,12,15;,
  4;9,18,34,30;,
  4;4,4,18,9;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;0,0,0,7;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;16,0,0,16;,
  4;23,23,23,23;,
  4;15,19,19,15;,
  4;18,18,35,34;,
  4;4,4,18,18;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;16,0,0,16;,
  4;17,16,16,17;,
  4;15,19,19,15;,
  4;18,9,30,35;,
  4;4,4,9,18;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;16,0,0,16;,
  4;24,24,24,24;,
  4;20,19,19,15;,
  4;9,9,30,30;,
  4;4,4,9,9;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;16,0,0,16;,
  4;21,16,16,21;,
  4;15,19,19,20;,
  4;9,9,30,30;,
  4;4,4,9,9;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;22,0,0,16;,
  4;23,23,23,23;,
  4;15,19,19,15;,
  4;9,9,30,30;,
  4;4,4,9,9;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;36,36,36,36;,
  4;3,3,3,3;,
  4;19,19,37,37;,
  4;1,1,1,1;,
  4;36,36,36,36;,
  4;3,3,3,3;,
  4;19,19,37,37;,
  4;1,1,1,1;,
  4;36,36,36,36;,
  4;3,3,3,3;,
  4;19,19,38,38;,
  4;39,39,39,39;,
  4;40,40,40,40;,
  4;41,41,41,41;,
  4;42,42,42,42;,
  4;43,43,43,43;,
  4;44,44,44,44;,
  4;45,45,45,45;,
  4;46,46,46,46;,
  4;47,47,47,47;,
  4;48,48,48,48;,
  4;49,49,49,49;,
  4;50,50,50,50;,
  4;51,51,51,51;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;54,54,54,54;,
  4;55,55,55,55;,
  4;56,56,56,56;,
  4;57,57,57,57;,
  4;57,57,57,57;,
  4;57,57,57,57;,
  4;58,58,58,58;,
  4;58,58,58,58;,
  4;58,58,58,58;,
  4;59,59,59,59;,
  4;59,59,59,59;,
  4;59,59,59,59;,
  4;60,60,60,60;,
  4;60,60,60,60;,
  4;60,60,60,60;,
  4;61,61,61,61;,
  4;61,61,61,61;,
  4;61,61,61,61;,
  4;61,61,61,61;,
  4;61,61,61,61;,
  4;61,61,61,61;,
  4;61,61,61,61;,
  4;61,61,61,61;,
  4;61,61,61,61;,
  4;62,62,62,62;,
  4;62,62,62,62;,
  4;62,62,62,62;,
  4;62,62,62,62;,
  4;62,62,62,62;,
  4;62,62,62,62;,
  4;62,62,62,62;,
  4;62,62,62,62;,
  4;62,62,62,62;,
  4;60,60,60,60;,
  4;59,59,59,59;,
  4;60,60,60,60;,
  4;58,58,58,58;,
  4;60,60,60,60;,
  4;57,57,57,57;,
  4;57,57,57,57;,
  4;59,59,59,59;,
  4;57,57,57,57;,
  4;59,59,59,59;,
  4;58,58,58,58;,
  4;59,59,59,59;,
  4;60,60,60,60;,
  4;58,58,58,58;,
  4;57,57,57,57;,
  4;58,58,58,58;;
 }
 MeshTextureCoords {
  274;
  0.124665;0.099355;,
  0.110400;0.099355;,
  0.110400;0.135777;,
  0.124665;0.135777;,
  0.056976;0.099355;,
  0.056976;0.135777;,
  0.886647;0.099355;,
  0.874666;0.099355;,
  0.874666;0.135777;,
  0.886647;0.135777;,
  0.127657;2.385119;,
  0.113352;2.385119;,
  0.125993;2.347869;,
  0.140246;2.347869;,
  0.110400;0.186442;,
  0.056976;0.186442;,
  0.065804;0.186442;,
  0.123000;0.186442;,
  0.883679;2.385119;,
  0.871674;2.385119;,
  0.859098;2.347869;,
  0.871015;2.347869;,
  0.373803;1.917187;,
  0.359554;1.917187;,
  0.123000;0.135777;,
  0.065804;0.135777;,
  0.434046;0.135777;,
  0.376796;0.135777;,
  0.641102;1.917187;,
  0.629189;1.917187;,
  0.386648;1.879380;,
  0.372343;1.879380;,
  0.431812;1.917187;,
  0.441032;1.879380;,
  0.628326;1.879380;,
  0.616321;1.879380;,
  0.375335;0.135777;,
  0.389600;0.135777;,
  0.389600;0.099355;,
  0.375335;0.099355;,
  0.443024;0.135777;,
  0.443024;0.099355;,
  0.613353;0.135777;,
  0.625334;0.135777;,
  0.625334;0.099355;,
  0.613353;0.099355;,
  0.376796;0.099355;,
  0.362500;0.099355;,
  0.434046;0.099355;,
  0.638160;0.099355;,
  0.626198;0.099355;,
  0.123000;0.099355;,
  0.137298;0.099355;,
  0.065804;0.099355;,
  0.862041;0.099355;,
  0.874006;0.099355;,
  0.638160;0.135777;,
  0.862041;0.135777;,
  0.362500;0.135777;,
  0.137298;0.135777;,
  0.124665;0.186442;,
  0.137298;0.186442;,
  0.874666;0.186442;,
  0.886647;0.186442;,
  0.862041;0.186442;,
  0.376796;0.186442;,
  0.362500;0.186442;,
  0.638160;0.186442;,
  0.626198;0.135777;,
  0.874006;0.135777;,
  0.874006;0.186442;,
  0.626198;0.186442;,
  0.375335;0.186442;,
  0.389600;0.186442;,
  0.434046;0.186442;,
  0.443024;0.186442;,
  0.625334;0.186442;,
  0.613353;0.186442;,
  0.929124;0.186442;,
  0.918781;0.186442;,
  0.918781;0.135777;,
  0.581393;0.135777;,
  0.581393;0.186442;,
  0.583972;1.917187;,
  0.573230;1.879380;,
  0.570876;0.186442;,
  0.570876;0.135777;,
  0.570876;0.099355;,
  0.581393;0.099355;,
  0.918781;0.099355;,
  0.929124;0.099355;,
  0.929124;0.135777;,
  0.940482;0.135777;,
  0.940482;0.186442;,
  0.931352;2.407042;,
  0.940482;2.407042;,
  0.929124;2.407042;,
  0.918781;2.407042;,
  0.931352;0.135777;,
  0.931352;0.186442;,
  0.568803;0.135777;,
  0.568803;0.186442;,
  0.579928;1.915513;,
  0.577075;0.184769;,
  0.590591;0.184769;,
  0.593724;1.915513;,
  0.561581;1.879380;,
  0.571107;1.917187;,
  0.559518;0.186442;,
  0.559518;0.135777;,
  0.559518;0.099355;,
  0.568803;0.099355;,
  0.931352;0.099355;,
  0.940482;0.099355;,
  0.974701;0.099355;,
  0.978378;0.099355;,
  0.978378;0.135777;,
  0.978378;0.186442;,
  0.974701;0.186442;,
  0.974701;0.135777;,
  0.525363;0.135777;,
  0.525363;0.186442;,
  0.526318;1.917187;,
  0.522440;1.879380;,
  0.521622;0.186442;,
  0.521622;0.135777;,
  0.521622;0.099355;,
  0.525363;0.099355;,
  0.994660;2.422433;,
  0.978378;2.422433;,
  0.974701;2.422433;,
  0.993739;2.422433;,
  0.993739;0.135777;,
  0.993739;0.186442;,
  0.506277;0.135777;,
  0.506277;0.186442;,
  0.507470;1.915513;,
  0.507156;0.184769;,
  0.528844;0.184769;,
  0.530082;1.915513;,
  0.505544;1.879380;,
  0.506518;1.917187;,
  0.505340;0.186442;,
  0.505340;0.135777;,
  0.505340;0.099355;,
  0.506277;0.099355;,
  0.993739;0.099355;,
  0.994660;0.099355;,
  0.994660;0.135777;,
  0.994660;0.186442;,
  0.037161;0.186442;,
  -0.005340;0.186442;,
  -0.006261;0.186442;,
  0.043292;0.186442;,
  1.043292;0.135777;,
  1.043292;0.186442;,
  0.456603;0.135777;,
  0.043292;0.135777;,
  -0.006261;0.135777;,
  0.456603;0.186442;,
  0.455025;1.917187;,
  0.461468;1.879380;,
  0.462839;0.186442;,
  0.462839;0.135777;,
  0.462839;0.099355;,
  0.456603;0.099355;,
  0.043292;0.099355;,
  -0.006261;0.099355;,
  0.037161;0.099355;,
  -0.005340;0.099355;,
  0.037161;0.135777;,
  -0.005340;0.135777;,
  0.056976;2.396646;,
  0.037161;2.396646;,
  0.043292;2.396646;,
  0.065804;2.396646;,
  0.423240;1.915513;,
  0.426017;0.184769;,
  0.450880;0.184769;,
  0.448865;1.915513;,
  0.375000;0.000000;,
  0.625000;0.000000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.625000;1.000000;,
  0.375000;1.000000;,
  0.875000;0.000000;,
  0.875000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.119335;2.424532;,
  -0.125231;2.419307;,
  -0.127236;2.512776;,
  0.121263;2.518003;,
  0.618749;1.900145;,
  0.374197;1.905368;,
  0.620677;1.806674;,
  0.372192;1.811898;,
  0.874769;2.419307;,
  0.872764;2.512776;,
  0.375000;0.000000;,
  0.625000;0.000000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.625000;1.000000;,
  0.375000;1.000000;,
  0.875000;0.000000;,
  0.875000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.639561;0.242264;,
  0.637163;0.242264;,
  0.637163;0.971811;,
  0.639561;0.971811;,
  0.637163;1.635508;,
  0.639561;1.635508;,
  0.637163;1.751483;,
  0.639561;1.751483;,
  0.648732;1.751483;,
  0.651046;1.751483;,
  0.739234;1.751483;,
  0.739557;1.751483;,
  0.754654;1.751483;,
  0.754514;1.751483;,
  0.754654;1.635508;,
  0.754514;1.635508;,
  0.754654;0.971811;,
  0.754514;0.971811;,
  0.754654;0.242264;,
  0.754514;0.242264;,
  0.739234;0.242264;,
  0.739557;0.242264;,
  0.648732;0.242264;,
  0.651046;0.242264;,
  0.739234;0.971811;,
  0.648732;0.971811;,
  0.739234;1.635508;,
  0.708330;0.083330;,
  0.791670;0.083330;,
  0.791670;0.166670;,
  0.708330;0.166670;,
  0.648732;1.635508;,
  0.754489;0.242264;,
  0.739616;0.242264;,
  0.739616;0.971811;,
  0.754489;0.971811;,
  0.651474;0.242264;,
  0.651474;0.971811;,
  0.640005;0.242264;,
  0.640005;0.971811;,
  0.739616;1.635508;,
  0.754489;1.635508;,
  0.208330;0.083330;,
  0.291670;0.083330;,
  0.291670;0.166670;,
  0.208330;0.166670;,
  0.640005;1.635508;,
  0.651474;1.635508;,
  0.739616;1.751483;,
  0.754489;1.751483;,
  0.651474;1.751483;,
  0.640005;1.751483;,
  0.208330;0.083330;,
  0.291670;0.083330;,
  0.208330;0.166670;,
  0.291670;0.166670;;
 }
}
