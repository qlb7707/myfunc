#include "stdafx.h"
#include"utility.h"

void framewrite(string fullpathname,string dstdir)
{
	int pos,cnt=0;
	string name;
	string framedir;
	string framename;
	IplImage *frame;
	char frameNo[5];
	CvCapture *capture=cvCreateFileCapture(fullpathname.c_str());
	pos=fullpathname.find_last_of('\\');
	name=fullpathname.substr(pos+1,fullpathname.length()-4-pos-1);
	framedir=dstdir+"\\"+name;
	CreateDirectory(s2ws(framedir).c_str(),NULL);
	while(frame=cvQueryFrame(capture))
	{
		//_itoa(cnt+1,frameNo,10);
		sprintf(frameNo,"%04d",cnt+1);
		framename=frameNo;
		cvSaveImage((framedir+"\\frame_"+framename+".jpg").c_str(),frame);
		cnt++;
	}
	cvReleaseCapture(&capture);
}
wstring s2ws(const std::string& s)
{
    setlocale(LC_ALL, "chs"); 
    const char* _Source = s.c_str();
    size_t _Dsize = s.size() + 1;
    wchar_t *_Dest = new wchar_t[_Dsize];
    wmemset(_Dest, 0, _Dsize);
    mbstowcs(_Dest,_Source,_Dsize);
    std::wstring result = _Dest;
    delete []_Dest;
    setlocale(LC_ALL, "C");
    return result;
}

string ws2s(const std::wstring& ws)
{
    std::string curLocale = setlocale(LC_ALL, NULL);        // curLocale = "C";
    setlocale(LC_ALL, "chs");
    const wchar_t* _Source = ws.c_str();
    size_t _Dsize = 2 * ws.size() + 1;
    char *_Dest = new char[_Dsize];
    memset(_Dest,0,_Dsize);
    wcstombs(_Dest,_Source,_Dsize);
    std::string result = _Dest;
    delete []_Dest;
    setlocale(LC_ALL, curLocale.c_str());
    return result;
}

void getFiles( string path, vector<string>& files )
{
	//文件句柄
	long   hFile   =   0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if((fileinfo.attrib &  _A_SUBDIR))
			{
				//if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
				//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
					//getFiles( p.assign(path).append("\\").append(fileinfo.name), files );
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
			}
		}while(_findnext(hFile, &fileinfo)  == 0);
		_findclose(hFile);
	}
}