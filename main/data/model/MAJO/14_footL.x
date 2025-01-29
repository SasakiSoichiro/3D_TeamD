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
 210;
 0.22732;-1.03689;-1.97281;,
 0.13859;-1.03689;-2.19932;,
 0.14003;-0.90865;-2.07126;,
 0.22970;-0.90865;-1.84209;,
 0.04988;-1.03689;-2.30539;,
 0.05034;-0.90865;-2.17944;,
 -0.03885;-1.03689;-2.30539;,
 -0.03933;-0.90865;-2.17944;,
 -0.12758;-1.03689;-2.19932;,
 -0.12900;-0.90865;-2.07126;,
 -0.21631;-1.03689;-1.97281;,
 -0.21869;-0.90865;-1.84209;,
 0.14055;-0.77775;-1.94455;,
 0.23056;-0.78033;-1.71444;,
 0.05052;-0.78029;-2.05348;,
 -0.03951;-0.78029;-2.05348;,
 -0.12952;-0.77775;-1.94455;,
 -0.21955;-0.78033;-1.71444;,
 0.14055;-0.61896;-1.81859;,
 0.23058;-0.65090;-1.58848;,
 0.05052;-0.61972;-1.92752;,
 -0.03951;-0.61972;-1.92752;,
 -0.12952;-0.61896;-1.81859;,
 -0.21955;-0.65090;-1.58848;,
 0.14201;-0.48524;-1.69264;,
 0.24448;-0.51286;-1.46253;,
 0.05052;-0.46174;-1.80157;,
 -0.03951;-0.46174;-1.80157;,
 -0.13100;-0.48524;-1.69264;,
 -0.23345;-0.51286;-1.46253;,
 0.16508;-0.35148;-1.37078;,
 0.28385;-0.39093;-1.23554;,
 0.05870;-0.33350;-1.44085;,
 -0.04767;-0.33350;-1.44085;,
 -0.15404;-0.35148;-1.37078;,
 -0.27284;-0.39093;-1.23554;,
 0.19610;-0.12808;-1.03364;,
 0.39782;-0.19302;-0.93507;,
 0.06672;-0.12110;-1.05840;,
 -0.05571;-0.12110;-1.05840;,
 -0.18509;-0.12808;-1.03364;,
 -0.38679;-0.19302;-0.93507;,
 0.42531;-0.09837;-0.73114;,
 0.22254;0.12911;-0.73194;,
 0.21680;0.04096;-0.54400;,
 0.41086;-0.10297;-0.54400;,
 0.07558;0.15886;-0.73114;,
 0.07558;0.07853;-0.54400;,
 -0.06457;0.15886;-0.73114;,
 -0.06457;0.07853;-0.54400;,
 -0.21151;0.12911;-0.73194;,
 -0.20579;0.04096;-0.54400;,
 -0.41430;-0.09837;-0.73114;,
 -0.39985;-0.10297;-0.54400;,
 0.21602;-0.00912;-0.35686;,
 0.40602;-0.09211;-0.35686;,
 0.07558;0.04668;-0.35686;,
 -0.06457;0.04668;-0.35686;,
 -0.20501;-0.00912;-0.35686;,
 -0.39501;-0.09211;-0.35686;,
 0.21574;-0.01882;0.12510;,
 0.40436;-0.13210;-0.13211;,
 0.07558;0.04654;0.19001;,
 -0.06457;0.04654;0.19001;,
 -0.20473;-0.01882;0.12510;,
 -0.39333;-0.13210;-0.13211;,
 0.21574;0.22067;0.79354;,
 0.37482;-0.09099;0.16855;,
 0.07558;0.17628;0.85793;,
 -0.06457;0.17628;0.85793;,
 -0.20473;0.22067;0.79354;,
 -0.36381;-0.09099;0.16855;,
 0.21574;-0.29394;0.83545;,
 0.35590;-0.15540;0.53417;,
 0.07558;-0.34546;0.88519;,
 -0.06457;-0.34546;0.88519;,
 -0.20473;-0.29394;0.83545;,
 -0.34487;-0.15540;0.53417;,
 0.21574;-0.49234;0.85625;,
 0.35590;-0.48600;0.41370;,
 0.07558;-0.49234;0.93754;,
 -0.06457;-0.49234;0.93754;,
 -0.20473;-0.49234;0.85625;,
 -0.34487;-0.48600;0.41370;,
 0.21574;-0.66574;0.85625;,
 0.35590;-0.66574;0.40882;,
 0.07558;-0.66574;0.93754;,
 -0.06457;-0.66574;0.93754;,
 -0.20473;-0.66574;0.85625;,
 -0.34487;-0.66574;0.40882;,
 0.21574;-0.83912;0.85625;,
 0.35590;-0.83912;0.40882;,
 0.07558;-0.83912;0.93754;,
 -0.06457;-0.83912;0.93754;,
 -0.20473;-0.83912;0.85625;,
 -0.34487;-0.83912;0.40882;,
 0.21574;-1.01252;0.85625;,
 0.35590;-1.01252;0.40882;,
 0.07558;-1.01252;0.93754;,
 -0.06457;-1.01252;0.93754;,
 -0.20473;-1.01252;0.85625;,
 -0.34487;-1.01252;0.40882;,
 0.22450;-1.01252;0.22167;,
 0.51100;-1.01252;-0.00303;,
 0.07558;-1.01252;0.22167;,
 -0.06457;-1.01252;0.22167;,
 -0.21349;-1.01252;0.22167;,
 -0.49999;-1.01252;-0.00303;,
 0.25206;-1.01252;0.03453;,
 0.51100;-1.01252;-0.35544;,
 0.07558;-1.01252;0.39361;,
 -0.06457;-1.01252;0.39361;,
 -0.24105;-1.01252;0.03453;,
 -0.49999;-1.01252;-0.35544;,
 0.23674;-1.01252;-0.15259;,
 0.50748;-1.01252;-0.54258;,
 0.07558;-1.01252;0.20615;,
 -0.06457;-1.01252;0.20615;,
 -0.22573;-1.01252;-0.15259;,
 -0.47460;-1.01252;-0.54258;,
 0.25168;-1.01252;-0.33753;,
 0.49321;-1.01252;-0.72972;,
 0.07536;-1.01252;0.01901;,
 -0.06433;-1.01252;0.01901;,
 -0.24068;-1.01252;-0.33753;,
 -0.46058;-1.01252;-0.72972;,
 0.48889;-1.02112;-1.16905;,
 0.25613;-1.02112;-0.99555;,
 0.13859;-1.03689;-2.19932;,
 0.22732;-1.03689;-1.97281;,
 0.07812;-1.02112;-0.80249;,
 0.04988;-1.03689;-2.30539;,
 -0.07021;-1.02112;-0.80249;,
 -0.03885;-1.03689;-2.30539;,
 -0.24830;-1.02112;-0.99555;,
 -0.12758;-1.03689;-2.19932;,
 -0.46416;-1.02112;-1.16905;,
 -0.21631;-1.03689;-1.97281;,
 -0.49999;-1.01252;-0.00303;,
 -0.34487;-1.01252;0.40882;,
 -0.34487;-0.83912;0.40882;,
 -0.49999;-0.83912;-0.00303;,
 -0.49999;-1.01252;-0.35544;,
 -0.49999;-0.83912;-0.35686;,
 -0.47460;-1.01252;-0.54258;,
 -0.49669;-0.83912;-0.54400;,
 -0.46058;-1.01252;-0.72972;,
 -0.48328;-0.83912;-0.73114;,
 -0.46416;-1.02112;-1.16905;,
 -0.51475;-0.86368;-1.12379;,
 -0.34487;-0.66574;0.40882;,
 -0.49999;-0.66574;-0.00303;,
 -0.49999;-0.66574;-0.35686;,
 -0.49687;-0.66574;-0.54400;,
 -0.48890;-0.66574;-0.73114;,
 -0.50289;-0.70625;-1.07866;,
 -0.34487;-0.48600;0.41370;,
 -0.49999;-0.49234;-0.00303;,
 -0.49999;-0.49234;-0.35686;,
 -0.49687;-0.49234;-0.54400;,
 -0.50163;-0.49234;-0.73114;,
 -0.49887;-0.54839;-1.03416;,
 -0.34487;-0.15540;0.53417;,
 -0.49999;-0.30918;-0.00303;,
 -0.49999;-0.30322;-0.35686;,
 -0.49659;-0.31612;-0.54400;,
 -0.50579;-0.31896;-0.73114;,
 -0.50049;-0.38751;-0.98963;,
 -0.36381;-0.09099;0.16855;,
 -0.39333;-0.13210;-0.13211;,
 -0.39501;-0.09211;-0.35686;,
 -0.39985;-0.10297;-0.54400;,
 -0.41430;-0.09837;-0.73114;,
 -0.38679;-0.19302;-0.93507;,
 0.35590;-1.01252;0.40882;,
 0.51100;-1.01252;-0.00303;,
 0.51100;-0.83912;-0.00303;,
 0.35590;-0.83912;0.40882;,
 0.51100;-1.01252;-0.35544;,
 0.51100;-0.83912;-0.35686;,
 0.50748;-1.01252;-0.54258;,
 0.50771;-0.83912;-0.54400;,
 0.49321;-1.01252;-0.72972;,
 0.49429;-0.83912;-0.73114;,
 0.48889;-1.02112;-1.16905;,
 0.52408;-0.86368;-1.12379;,
 0.51100;-0.66574;-0.00303;,
 0.35590;-0.66574;0.40882;,
 0.51100;-0.66574;-0.35686;,
 0.50788;-0.66574;-0.54400;,
 0.49992;-0.66574;-0.73114;,
 0.51380;-0.70625;-1.07866;,
 0.51100;-0.49234;-0.00303;,
 0.35590;-0.48600;0.41370;,
 0.51100;-0.49234;-0.35686;,
 0.50788;-0.49234;-0.54400;,
 0.51264;-0.49234;-0.73114;,
 0.50992;-0.54839;-1.03416;,
 0.51100;-0.30918;-0.00303;,
 0.35590;-0.15540;0.53417;,
 0.51100;-0.30322;-0.35686;,
 0.50760;-0.31612;-0.54400;,
 0.51681;-0.31896;-0.73114;,
 0.51154;-0.38751;-0.98963;,
 0.40436;-0.13210;-0.13211;,
 0.37482;-0.09099;0.16855;,
 0.40602;-0.09211;-0.35686;,
 0.41086;-0.10297;-0.54400;,
 0.42531;-0.09837;-0.73114;,
 0.39782;-0.19302;-0.93507;;
 
 170;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;3,2,12,13;,
 4;2,5,14,12;,
 4;5,7,15,14;,
 4;7,9,16,15;,
 4;9,11,17,16;,
 4;13,12,18,19;,
 4;12,14,20,18;,
 4;14,15,21,20;,
 4;15,16,22,21;,
 4;16,17,23,22;,
 4;19,18,24,25;,
 4;18,20,26,24;,
 4;20,21,27,26;,
 4;21,22,28,27;,
 4;22,23,29,28;,
 4;25,24,30,31;,
 4;24,26,32,30;,
 4;26,27,33,32;,
 4;27,28,34,33;,
 4;28,29,35,34;,
 4;31,30,36,37;,
 4;30,32,38,36;,
 4;32,33,39,38;,
 4;33,34,40,39;,
 4;34,35,41,40;,
 4;42,43,44,45;,
 4;43,46,47,44;,
 4;46,48,49,47;,
 4;48,50,51,49;,
 4;50,52,53,51;,
 4;45,44,54,55;,
 4;44,47,56,54;,
 4;47,49,57,56;,
 4;49,51,58,57;,
 4;51,53,59,58;,
 4;55,54,60,61;,
 4;54,56,62,60;,
 4;56,57,63,62;,
 4;57,58,64,63;,
 4;58,59,65,64;,
 4;61,60,66,67;,
 4;60,62,68,66;,
 4;62,63,69,68;,
 4;63,64,70,69;,
 4;64,65,71,70;,
 4;67,66,72,73;,
 4;66,68,74,72;,
 4;68,69,75,74;,
 4;69,70,76,75;,
 4;70,71,77,76;,
 4;73,72,78,79;,
 4;72,74,80,78;,
 4;74,75,81,80;,
 4;75,76,82,81;,
 4;76,77,83,82;,
 4;79,78,84,85;,
 4;78,80,86,84;,
 4;80,81,87,86;,
 4;81,82,88,87;,
 4;82,83,89,88;,
 4;85,84,90,91;,
 4;84,86,92,90;,
 4;86,87,93,92;,
 4;87,88,94,93;,
 4;88,89,95,94;,
 4;91,90,96,97;,
 4;90,92,98,96;,
 4;92,93,99,98;,
 4;93,94,100,99;,
 4;94,95,101,100;,
 4;97,96,102,103;,
 4;96,98,104,102;,
 4;98,99,105,104;,
 4;99,100,106,105;,
 4;100,101,107,106;,
 4;103,102,108,109;,
 4;102,104,110,108;,
 4;104,105,111,110;,
 4;105,106,112,111;,
 4;106,107,113,112;,
 4;109,108,114,115;,
 4;108,110,116,114;,
 4;110,111,117,116;,
 4;111,112,118,117;,
 4;112,113,119,118;,
 4;115,114,120,121;,
 4;114,116,122,120;,
 4;116,117,123,122;,
 4;117,118,124,123;,
 4;118,119,125,124;,
 4;126,127,128,129;,
 4;127,130,131,128;,
 4;130,132,133,131;,
 4;132,134,135,133;,
 4;134,136,137,135;,
 4;138,139,140,141;,
 4;142,138,141,143;,
 4;144,142,143,145;,
 4;146,144,145,147;,
 4;10,148,149,11;,
 4;141,140,150,151;,
 4;143,141,151,152;,
 4;145,143,152,153;,
 4;147,145,153,154;,
 4;11,149,155,17;,
 4;151,150,156,157;,
 4;152,151,157,158;,
 4;153,152,158,159;,
 4;154,153,159,160;,
 4;17,155,161,23;,
 4;157,156,162,163;,
 4;158,157,163,164;,
 4;159,158,164,165;,
 4;160,159,165,166;,
 4;23,161,167,29;,
 4;163,162,168,169;,
 4;164,163,169,170;,
 4;165,164,170,171;,
 4;166,165,171,172;,
 4;29,167,173,35;,
 4;174,175,176,177;,
 4;175,178,179,176;,
 4;178,180,181,179;,
 4;180,182,183,181;,
 4;184,0,3,185;,
 4;177,176,186,187;,
 4;176,179,188,186;,
 4;179,181,189,188;,
 4;181,183,190,189;,
 4;185,3,13,191;,
 4;187,186,192,193;,
 4;186,188,194,192;,
 4;188,189,195,194;,
 4;189,190,196,195;,
 4;191,13,19,197;,
 4;193,192,198,199;,
 4;192,194,200,198;,
 4;194,195,201,200;,
 4;195,196,202,201;,
 4;197,19,25,203;,
 4;199,198,204,205;,
 4;198,200,206,204;,
 4;200,201,207,206;,
 4;201,202,208,207;,
 4;203,25,31,209;,
 4;39,40,50,48;,
 4;38,39,48,46;,
 4;36,38,46,43;,
 4;37,36,43,42;,
 4;202,203,209,208;,
 4;196,197,203,202;,
 4;190,191,197,196;,
 4;183,185,191,190;,
 4;182,184,185,183;,
 4;121,120,127,126;,
 4;120,122,130,127;,
 4;122,123,132,130;,
 4;123,124,134,132;,
 4;124,125,136,134;,
 4;149,148,146,147;,
 4;155,149,147,154;,
 4;161,155,154,160;,
 4;167,161,160,166;,
 4;173,167,166,172;,
 4;40,41,52,50;;
 
 MeshMaterialList {
  6;
  170;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.768800;0.624000;0.608800;1.000000;;
   100.000000;
   0.000000;0.000000;0.000000;;
   0.307520;0.249600;0.243520;;
  }
  Material {
   0.047200;0.016000;0.040800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.400000;0.400000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.656000;0.456000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  173;
  0.912715;0.217139;-0.346125;,
  0.777030;0.439972;-0.450166;,
  0.346930;0.657084;-0.669238;,
  -0.346930;0.657083;-0.669239;,
  -0.777003;0.440013;-0.450173;,
  -0.919419;0.191693;-0.343400;,
  0.896592;0.260069;-0.358450;,
  0.777513;0.438697;-0.450576;,
  0.346881;0.656271;-0.670061;,
  -0.346907;0.656264;-0.670055;,
  -0.777502;0.438715;-0.450577;,
  -0.900077;0.248970;-0.357597;,
  0.877930;0.293370;-0.378383;,
  0.791957;0.407205;-0.454960;,
  0.357848;0.616082;-0.701704;,
  -0.357900;0.616069;-0.701688;,
  -0.791965;0.407208;-0.454942;,
  -0.877354;0.294808;-0.378601;,
  0.873991;0.270273;-0.403846;,
  0.809927;0.373099;-0.452566;,
  0.374645;0.580912;-0.722622;,
  -0.374688;0.580893;-0.722615;,
  -0.809953;0.373067;-0.452544;,
  -0.873952;0.270391;-0.403852;,
  0.780915;0.438659;-0.444692;,
  0.730164;0.547676;-0.408549;,
  0.320934;0.775812;-0.543247;,
  -0.320952;0.775808;-0.543243;,
  -0.730184;0.547655;-0.408539;,
  -0.780942;0.438624;-0.444678;,
  0.638925;0.604405;-0.475888;,
  0.538392;0.717094;-0.442618;,
  0.195718;0.883113;-0.426387;,
  -0.195723;0.883114;-0.426383;,
  -0.538381;0.717101;-0.442619;,
  -0.638934;0.604395;-0.475890;,
  0.802714;0.583863;-0.121463;,
  0.545748;0.836973;0.040438;,
  0.105240;0.909939;0.401167;,
  -0.105247;0.909941;0.401162;,
  -0.545741;0.836978;0.040417;,
  -0.802716;0.583854;-0.121501;,
  0.773819;0.628041;0.082275;,
  0.429146;0.874152;0.227360;,
  0.131023;0.945928;0.296736;,
  -0.131027;0.945929;0.296733;,
  -0.429145;0.874155;0.227349;,
  -0.773820;0.628042;0.082261;,
  0.717371;0.694713;0.052471;,
  0.419068;0.902653;0.097974;,
  0.179468;0.978951;0.097196;,
  -0.179468;0.978951;0.097196;,
  -0.419074;0.902650;0.097978;,
  -0.717368;0.694715;0.052485;,
  0.698360;0.715734;0.004207;,
  0.325864;0.940904;-0.092263;,
  0.088180;0.989514;-0.114396;,
  -0.088180;0.989514;-0.114396;,
  -0.325871;0.940902;-0.092262;,
  -0.698357;0.715737;0.004216;,
  0.828112;0.557832;0.055264;,
  0.205097;0.949759;-0.236419;,
  -0.025994;0.973213;-0.228431;,
  0.025994;0.973213;-0.228431;,
  -0.205098;0.949757;-0.236426;,
  -0.828121;0.557820;0.055253;,
  0.955359;0.141015;0.259623;,
  0.730613;0.103680;0.674875;,
  0.192807;0.166517;0.967005;,
  -0.192807;0.166517;0.967004;,
  -0.730624;0.103671;0.674864;,
  -0.955362;0.141006;0.259617;,
  0.943968;-0.028927;0.328768;,
  0.757711;0.039084;0.651419;,
  0.232746;0.138994;0.962554;,
  -0.232747;0.138994;0.962554;,
  -0.757726;0.039086;0.651402;,
  -0.943968;-0.028927;0.328767;,
  0.945456;-0.002199;0.325741;,
  0.780835;-0.001088;0.624737;,
  0.259770;0.000000;0.965671;,
  -0.259771;0.000000;0.965670;,
  -0.780848;-0.001088;0.624720;,
  -0.945456;-0.002199;0.325742;,
  0.945435;0.000000;0.325812;,
  0.781081;0.000000;0.624430;,
  -0.259771;0.000000;0.965670;,
  -0.781094;0.000000;0.624413;,
  -0.945434;0.000000;0.325812;,
  0.781081;0.000000;0.624430;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;0.000000;,
  0.008984;-0.999926;0.008160;,
  0.008940;-0.999935;0.007043;,
  0.004448;-0.999975;0.005580;,
  -0.004477;-0.999974;0.005599;,
  -0.009431;-0.999930;0.007112;,
  -0.009907;-0.999917;0.008260;,
  -0.983825;0.000000;0.179133;,
  -0.999596;-0.016152;-0.023370;,
  -0.997062;-0.052471;-0.055807;,
  -0.995999;-0.089242;-0.004639;,
  -0.983908;-0.001204;0.178673;,
  -0.999964;-0.000130;-0.008455;,
  -0.999601;-0.013459;-0.024843;,
  -0.999828;-0.018089;0.004075;,
  -0.984947;-0.015333;0.172176;,
  -0.999964;0.000199;-0.008522;,
  -0.999930;-0.011760;-0.001337;,
  -0.999680;-0.023290;0.009845;,
  -0.963959;0.239425;0.116008;,
  -0.972009;0.234940;0.001545;,
  -0.977792;0.209086;0.014318;,
  -0.976520;0.212423;-0.035856;,
  0.983829;0.000000;0.179112;,
  0.999961;-0.000326;-0.008829;,
  0.999121;-0.005590;-0.041538;,
  0.999450;-0.031841;-0.009261;,
  0.983912;-0.001204;0.178652;,
  0.999964;-0.000123;-0.008448;,
  0.999601;-0.013445;-0.024829;,
  0.999807;-0.019300;0.003570;,
  0.984950;-0.015331;0.172156;,
  0.999964;0.000199;-0.008522;,
  0.999930;-0.011761;-0.001324;,
  0.999677;-0.023399;0.009879;,
  0.963964;0.239414;0.115990;,
  0.972011;0.234930;0.001535;,
  0.977793;0.209084;0.014332;,
  0.976522;0.212422;-0.035789;,
  -0.421681;0.716632;-0.555540;,
  -0.113179;0.807509;-0.578895;,
  0.113170;0.807512;-0.578893;,
  0.421684;0.716636;-0.555531;,
  0.669047;0.590489;-0.451330;,
  0.873382;0.350124;-0.338552;,
  0.962148;0.124408;-0.242476;,
  0.970504;0.137499;-0.198029;,
  0.983538;0.068331;-0.167284;,
  0.000798;-0.999864;0.016470;,
  0.004849;-0.999890;0.014020;,
  0.004450;-0.999929;0.011025;,
  -0.004470;-0.999929;0.011044;,
  -0.005389;-0.999886;0.014100;,
  -0.001838;-0.999861;0.016593;,
  -0.986338;0.029556;-0.162064;,
  -0.970162;0.140269;-0.197765;,
  -0.962110;0.124645;-0.242504;,
  -0.873382;0.350091;-0.338586;,
  -0.669057;0.590460;-0.451352;,
  0.728794;0.126540;0.672939;,
  0.181850;0.058085;0.981609;,
  -0.181850;0.058085;0.981609;,
  -0.728801;0.126517;0.672935;,
  -0.008182;-0.999869;0.013953;,
  -0.016370;-0.999728;0.016615;,
  0.000003;-0.999941;0.010891;,
  0.000014;-0.999941;0.010890;,
  0.008083;-0.999870;0.013975;,
  0.016138;-0.999731;0.016661;,
  -0.998757;-0.032056;-0.038171;,
  -0.992574;-0.096234;-0.074406;,
  -0.984551;-0.174758;-0.010894;,
  -0.985118;-0.089876;-0.146512;,
  0.999959;-0.000406;-0.009096;,
  0.998938;-0.002592;-0.046003;,
  0.998116;-0.058281;-0.019171;,
  0.987449;-0.007409;-0.157764;,
  -0.155556;0.746890;-0.646496;,
  -0.078016;0.755694;-0.650261;,
  0.078011;0.755694;-0.650263;,
  0.155546;0.746889;-0.646500;;
  170;
  4;0,1,7,6;,
  4;1,2,8,7;,
  4;2,3,9,8;,
  4;3,4,10,9;,
  4;4,5,11,10;,
  4;6,7,13,12;,
  4;7,8,14,13;,
  4;8,9,15,14;,
  4;9,10,16,15;,
  4;10,11,17,16;,
  4;12,13,19,18;,
  4;13,14,20,19;,
  4;14,15,21,20;,
  4;15,16,22,21;,
  4;16,17,23,22;,
  4;18,19,25,24;,
  4;19,20,26,25;,
  4;20,21,27,26;,
  4;21,22,28,27;,
  4;22,23,29,28;,
  4;24,25,31,30;,
  4;25,26,32,31;,
  4;26,27,33,32;,
  4;27,28,34,33;,
  4;28,29,35,34;,
  4;30,31,134,135;,
  4;31,32,133,134;,
  4;32,33,132,133;,
  4;33,34,131,132;,
  4;34,35,150,131;,
  4;36,37,43,42;,
  4;37,38,44,43;,
  4;38,39,45,44;,
  4;39,40,46,45;,
  4;40,41,47,46;,
  4;42,43,49,48;,
  4;43,44,50,49;,
  4;44,45,51,50;,
  4;45,46,52,51;,
  4;46,47,53,52;,
  4;48,49,55,54;,
  4;49,50,56,55;,
  4;50,51,57,56;,
  4;51,52,58,57;,
  4;52,53,59,58;,
  4;54,55,61,60;,
  4;55,56,62,61;,
  4;56,57,63,62;,
  4;57,58,64,63;,
  4;58,59,65,64;,
  4;60,151,67,66;,
  4;151,152,68,67;,
  4;152,153,69,68;,
  4;153,154,70,69;,
  4;154,65,71,70;,
  4;66,67,73,72;,
  4;67,68,74,73;,
  4;68,69,75,74;,
  4;69,70,76,75;,
  4;70,71,77,76;,
  4;72,73,79,78;,
  4;73,74,80,79;,
  4;74,75,81,80;,
  4;75,76,82,81;,
  4;76,77,83,82;,
  4;78,79,85,84;,
  4;79,80,80,85;,
  4;80,81,86,80;,
  4;81,82,87,86;,
  4;82,83,88,87;,
  4;84,85,89,84;,
  4;85,80,80,89;,
  4;80,86,81,80;,
  4;86,87,87,81;,
  4;87,88,88,87;,
  4;90,90,90,90;,
  4;90,90,90,90;,
  4;90,90,90,90;,
  4;90,90,90,90;,
  4;90,90,90,90;,
  4;90,90,90,90;,
  4;90,90,90,90;,
  4;91,91,91,91;,
  4;92,92,92,92;,
  4;90,90,90,90;,
  4;90,90,90,90;,
  4;90,90,90,90;,
  4;90,90,90,90;,
  4;90,90,90,90;,
  4;90,90,90,90;,
  4;90,90,94,93;,
  4;90,90,95,94;,
  4;90,90,96,95;,
  4;90,90,97,96;,
  4;90,90,98,97;,
  4;140,141,155,156;,
  4;141,142,157,155;,
  4;142,143,158,157;,
  4;143,144,159,158;,
  4;144,145,160,159;,
  4;99,88,88,99;,
  4;161,99,99,100;,
  4;162,161,100,101;,
  4;163,162,101,102;,
  4;5,164,146,11;,
  4;99,88,83,103;,
  4;100,99,103,104;,
  4;101,100,104,105;,
  4;102,101,105,106;,
  4;11,146,147,17;,
  4;103,83,77,107;,
  4;104,103,107,108;,
  4;105,104,108,109;,
  4;106,105,109,110;,
  4;17,147,148,23;,
  4;107,77,71,111;,
  4;108,107,111,112;,
  4;109,108,112,113;,
  4;110,109,113,114;,
  4;23,148,149,29;,
  4;111,71,65,59;,
  4;112,111,59,53;,
  4;113,112,53,47;,
  4;114,113,47,41;,
  4;29,149,150,35;,
  4;84,115,115,84;,
  4;115,165,116,115;,
  4;165,166,117,116;,
  4;166,167,118,117;,
  4;168,0,6,139;,
  4;84,115,119,78;,
  4;115,116,120,119;,
  4;116,117,121,120;,
  4;117,118,122,121;,
  4;139,6,12,138;,
  4;78,119,123,72;,
  4;119,120,124,123;,
  4;120,121,125,124;,
  4;121,122,126,125;,
  4;138,12,18,137;,
  4;72,123,127,66;,
  4;123,124,128,127;,
  4;124,125,129,128;,
  4;125,126,130,129;,
  4;137,18,24,136;,
  4;66,127,54,60;,
  4;127,128,48,54;,
  4;128,129,42,48;,
  4;129,130,36,42;,
  4;136,24,30,135;,
  4;132,131,169,170;,
  4;133,132,170,171;,
  4;134,133,171,172;,
  4;135,134,37,36;,
  4;130,136,135,36;,
  4;126,137,136,130;,
  4;122,138,137,126;,
  4;118,139,138,122;,
  4;167,168,139,118;,
  4;93,94,141,140;,
  4;94,95,142,141;,
  4;95,96,143,142;,
  4;96,97,144,143;,
  4;97,98,145,144;,
  4;146,164,163,102;,
  4;147,146,102,106;,
  4;148,147,106,110;,
  4;149,148,110,114;,
  4;150,149,114,41;,
  4;131,150,41,40;;
 }
 MeshTextureCoords {
  210;
  0.375000;0.000000;,
  0.425000;0.000000;,
  0.425000;0.050000;,
  0.375000;0.050000;,
  0.475000;0.000000;,
  0.475000;0.050000;,
  0.525000;0.000000;,
  0.525000;0.050000;,
  0.575000;0.000000;,
  0.575000;0.050000;,
  0.625000;0.000000;,
  0.625000;0.050000;,
  0.425000;0.100000;,
  0.375000;0.100000;,
  0.475000;0.100000;,
  0.525000;0.100000;,
  0.575000;0.100000;,
  0.625000;0.100000;,
  0.425000;0.150000;,
  0.375000;0.150000;,
  0.475000;0.150000;,
  0.525000;0.150000;,
  0.575000;0.150000;,
  0.625000;0.150000;,
  0.425000;0.200000;,
  0.375000;0.200000;,
  0.475000;0.200000;,
  0.525000;0.200000;,
  0.575000;0.200000;,
  0.625000;0.200000;,
  0.425000;0.250000;,
  0.375000;0.250000;,
  0.475000;0.250000;,
  0.525000;0.250000;,
  0.575000;0.250000;,
  0.625000;0.250000;,
  0.425000;0.282330;,
  0.375000;0.282330;,
  0.475000;0.282330;,
  0.525000;0.282330;,
  0.575000;0.282330;,
  0.625000;0.282330;,
  0.375000;0.300000;,
  0.425000;0.300000;,
  0.425000;0.350000;,
  0.375000;0.350000;,
  0.475000;0.300000;,
  0.475000;0.350000;,
  0.525000;0.300000;,
  0.525000;0.350000;,
  0.575000;0.300000;,
  0.575000;0.350000;,
  0.625000;0.300000;,
  0.625000;0.350000;,
  0.425000;0.400000;,
  0.375000;0.400000;,
  0.475000;0.400000;,
  0.525000;0.400000;,
  0.575000;0.400000;,
  0.625000;0.400000;,
  0.425000;0.450000;,
  0.375000;0.450000;,
  0.475000;0.450000;,
  0.525000;0.450000;,
  0.575000;0.450000;,
  0.625000;0.450000;,
  0.425000;0.500000;,
  0.375000;0.500000;,
  0.475000;0.500000;,
  0.525000;0.500000;,
  0.575000;0.500000;,
  0.625000;0.500000;,
  0.425000;0.550000;,
  0.375000;0.550000;,
  0.475000;0.550000;,
  0.525000;0.550000;,
  0.575000;0.550000;,
  0.625000;0.550000;,
  0.425000;0.600000;,
  0.375000;0.600000;,
  0.475000;0.600000;,
  0.525000;0.600000;,
  0.575000;0.600000;,
  0.625000;0.600000;,
  0.425000;0.650000;,
  0.375000;0.650000;,
  0.475000;0.650000;,
  0.525000;0.650000;,
  0.575000;0.650000;,
  0.625000;0.650000;,
  0.425000;0.700000;,
  0.375000;0.700000;,
  0.475000;0.700000;,
  0.525000;0.700000;,
  0.575000;0.700000;,
  0.625000;0.700000;,
  0.425000;0.750000;,
  0.375000;0.750000;,
  0.475000;0.750000;,
  0.525000;0.750000;,
  0.575000;0.750000;,
  0.625000;0.750000;,
  0.425000;0.800000;,
  0.375000;0.800000;,
  0.475000;0.800000;,
  0.525000;0.800000;,
  0.575000;0.800000;,
  0.625000;0.800000;,
  0.425000;0.850000;,
  0.375000;0.850000;,
  0.475000;0.850000;,
  0.525000;0.850000;,
  0.575000;0.850000;,
  0.625000;0.850000;,
  0.425000;0.900000;,
  0.375000;0.900000;,
  0.475000;0.900000;,
  0.525000;0.900000;,
  0.575000;0.900000;,
  0.625000;0.900000;,
  0.425000;0.950000;,
  0.375000;0.950000;,
  0.475000;0.950000;,
  0.525000;0.950000;,
  0.575000;0.950000;,
  0.625000;0.950000;,
  0.375000;0.967670;,
  0.425000;0.967670;,
  0.425000;1.000000;,
  0.375000;1.000000;,
  0.475000;0.967670;,
  0.475000;1.000000;,
  0.525000;0.967670;,
  0.525000;1.000000;,
  0.575000;0.967670;,
  0.575000;1.000000;,
  0.625000;0.967670;,
  0.625000;1.000000;,
  0.825000;0.000000;,
  0.875000;0.000000;,
  0.875000;0.050000;,
  0.825000;0.050000;,
  0.775000;0.000000;,
  0.775000;0.050000;,
  0.725000;0.000000;,
  0.725000;0.050000;,
  0.675000;0.000000;,
  0.675000;0.050000;,
  0.657330;0.000000;,
  0.657330;0.050000;,
  0.875000;0.100000;,
  0.825000;0.100000;,
  0.775000;0.100000;,
  0.725000;0.100000;,
  0.675000;0.100000;,
  0.657330;0.100000;,
  0.875000;0.150000;,
  0.825000;0.150000;,
  0.775000;0.150000;,
  0.725000;0.150000;,
  0.675000;0.150000;,
  0.657330;0.150000;,
  0.875000;0.200000;,
  0.825000;0.200000;,
  0.775000;0.200000;,
  0.725000;0.200000;,
  0.675000;0.200000;,
  0.657330;0.200000;,
  0.875000;0.250000;,
  0.825000;0.250000;,
  0.775000;0.250000;,
  0.725000;0.250000;,
  0.675000;0.250000;,
  0.657330;0.250000;,
  0.125000;0.000000;,
  0.175000;0.000000;,
  0.175000;0.050000;,
  0.125000;0.050000;,
  0.225000;0.000000;,
  0.225000;0.050000;,
  0.275000;0.000000;,
  0.275000;0.050000;,
  0.325000;0.000000;,
  0.325000;0.050000;,
  0.342670;0.000000;,
  0.342670;0.050000;,
  0.175000;0.100000;,
  0.125000;0.100000;,
  0.225000;0.100000;,
  0.275000;0.100000;,
  0.325000;0.100000;,
  0.342670;0.100000;,
  0.175000;0.150000;,
  0.125000;0.150000;,
  0.225000;0.150000;,
  0.275000;0.150000;,
  0.325000;0.150000;,
  0.342670;0.150000;,
  0.175000;0.200000;,
  0.125000;0.200000;,
  0.225000;0.200000;,
  0.275000;0.200000;,
  0.325000;0.200000;,
  0.342670;0.200000;,
  0.175000;0.250000;,
  0.125000;0.250000;,
  0.225000;0.250000;,
  0.275000;0.250000;,
  0.325000;0.250000;,
  0.342670;0.250000;;
 }
}
