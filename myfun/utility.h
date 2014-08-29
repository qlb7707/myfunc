#ifndef UTILITY_H
#define UTILITY_H
#include "cv.h"
#include "highgui.h"
#include "cxcore.h"
#include "CvvImage.h"
#include "string"
#include "io.h"
using namespace std;
//extern void writeframe(vector<string> fileName,string dstdir );
extern wstring s2ws(const std::string& s);
extern string ws2s(const std::wstring& ws);
extern void getFiles( string path, vector<string>& files );
extern void framewrite(string fullpathname,string dstdir);

#endif