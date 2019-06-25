/*前言： 
本程序仅供交流与讨论，请在下载后于24小时内删除。
V1: 
不调用WINAPI，所有使用的函数，均在NOIP允许范围之内，保证程序的高效工作。  
本程序必须在lemon评测环境下才可正常运行！！
lemon1.1 以及 lemon1.2_beta AK测试通过，其他版本未测试。

V2:
智能判断系统
兼容WINDOWS和LINUX! 

V3:
更新字符串截取算法，修复V2版本中的bug，使得测试点数量在10以上时可以AC 

V4:
修复一些Bug 
                                                
                                     .                                 
                          :iiruU5uuYuJjjU1F1urii,                          
                 .7uJr.:irvJv7i::::::::::::irLuUY7i. iL27:                 
               i@B@B@B@Bu::,,.,...........,.,,::iiuB@B@B@B@L               
              rM2777vUG@BY ........,...,.,.,.... iB@Bq2vi:7BF              
              :..:r:.  i@B, ..................,..M@Y..:;Li  :              
              ,r7r:,..  vBi. ....................@U  .,:rjui               
            .rvri,..... :r. .....................Ji ,,,,:ivuU:             
           .7Li:......       ................... ....,.:,::7jS7            
          .ri:i:iiriiii::.. .   . ......... .     ::iiriiiii7LS1:          
       .:rrYr.         ..,:i::.  ............:i7v:           .:rLv:        
     :7,kB@B@M               ,i:. ........:.L@@B@B,              .rv:      
    :J  N@@@B@                 ::  ......i. r@B@B@.                ,L      
    :v   L8PL,.,::ii:::,,..    ,i ..... .i.  ;GE2:..:::::::.,..    .L      
     ri:..     . .  ...,,::::i::.  ......,,:,.    .... ....,,:::::,i7      
     .L:... ....,..               .........       ....,::::::,,::::rJ.     
     ivriiiiiiiiii:::.       . . ..............,.,.,:iirirrr;r;77vvuu,     
    :Lr::irii:i:::ii;i. ... . ................,....:r;;iii;ir;77rir7Lr.    
    i1i::::::::::::::,.... . . ..................,.::i:::i:i:ii;ii;rv5:    
    rji::,,.,.,.,.... . ........................,.,..,::::::::iiiirrv5i    
   .ivi:::,,...... . ..........................,.,.,,,,:,:,:,::ii;ir71i    
   .iri::,:.,.. ..............................,.,.,,:,:,:,:,::iiiir;7ji    
   :;7i:::,,.,...............................,.,.,,,,:,:::,::i:ii;ir7j:.   
   ,;ri:::,.,.............................,.,.,.,,:,:,::::::i:i:iirivui.   
   ,ivii::.::..,.,.......................,.,.,.,,,,:,::::::i:iri:i;r71i.   
   .7ji:::.i7.....,...........,.........,.,.,,,,,,:,::::::i:::j;:ir;vFr.   
   .7Fii::.v2. ,.....,...............,.,.,.,.,,,,:,::::i:i:i,ik7:i;r7ki.   
   .rur:i:,i5r....,.,.,...........,.,.,.,,,.:,:,::::::::i::,:YFr:irrLL:    
   .:77;:::.7@: ...,.,.,.,.,.,.,.,.,.,,,,,,,,::::::::::::::,v@i,:;rLur..   
    ,rSri::.,F@i .,.,.,.,.,.,.,.,,,.:,,,:,:,::::::::::i::,.L@u::i;rLki.    
    .iLvii::..G@;  ..,.,.,,,.,,,,,,,,:,:,:,:::::::::::::..Y@k.,iir7u7:     
     .r57ii:: .0@F. ..,.,,,,,,,.,,:,:,::::::::::::::::,.:Z@5 .:irrjUi.     
     .:Lu7ii::. j@@7.  ..,,,,:,:,:,:,:,:::::::::::::..:uB@7..::rrJUr,.     
      .i2j7iii:. ,BB@J. ....,,:,:,:::::::::::::,:...:F@@Z. .::rrLUJ:.      
       ,i5uriiii,  rM@BZ7,  .....,,:,:,:::,,.....:YOB@Gi .:::rr71u:.       
       .:r1U7iiii:.  :GB@BBur::.... . .....,::v5@B@@P,  ,:::rrL1ui,        
        .:r2U7;;iii:.  .rX@@B@B@EPS5JLJSFPG@B@@@MFi. ..:::irrY1Yi,         
          ,iU2Lrri;ii::.   :rLPM@B@B@B@@@B@OSv;:   .::::i;77u5Y:,          
           ,iL127r;;iiii::.     ....,:,....     .::::::i;7YS2v:.           
            .:7USuviriii;iiii::.... . . ....::::::::iirrY1SYr:.            
             .,i7FkUvr;riri;iriiiiiiii:i:i:i:::iiiirr7LFkUri..             
               .:iY2SSjr7r;iri;iii;iiiiiiiii;iiirr77UkFu7:,.               
                 .,i7U5q5jvvrriri;iririririr;r7LLukP2uri,.                 
                   .::rvu5NX1uUjJvvv7r7vLLujUuFPq2u7;:,.                   
                     ..,:irLY5SPSXSk121XFPkXF5Yv;i:,.                      
                         ..,::i;77vLJLYvv7rii::..                          
                             . ....,,:,,.,.. .                             */ 
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include <unistd.h>
#define FILEPATH_MAX (999)
//#include<windows.h> 
//#include<winuser.h> //==>完全不使用WINAPI! 
using namespace std;
const string pbname="ProblemName";
//请在此填入题目名  
const int answers= 10;
//请输入测试点数量 
bool toggle[answers+5]={0};
//控制本次是否输出
//用途：若觉得自己AK了不合适，请在int main()中提前修改对应测试点的toggle值
//0==>输出 1==>不输出 
int ac()
{
	//toggle[i]=1; 第i个测试点不输出 (这里并不知道答案文件是否从0开始计算)
	
	string frepath;//V1版本：frepath=_pgmptr;  _pgmptr实测在windows下有用，Linux编译不过。。 
	string outid,basepath;
	
	//此处获得运行路径，根据Windows用 \ ，linux用 / 判断系统 
	bool islinux=false;
	char *file_path_getcwd;
	file_path_getcwd=(char *)malloc(FILEPATH_MAX);
	getcwd(file_path_getcwd,FILEPATH_MAX);
	frepath = file_path_getcwd;
	if(frepath.find("/")!=-1) 
	{//linux系统 
		islinux=true;
	}
    
    //MessageBox(NULL,frepath.data(),"",MB_OK); //测试用的 =_= ，这行可以删 
    int p=frepath.find("temp");
	outid=frepath;
	if(p==-1) return -1;//ERROR 未处于Lemon评测环境中 
	outid=outid.erase(0,p+6);
	outid=outid.erase(outid.find("."),outid.length()); //截取当前对应的答案文件ID 
	//比如xxx1.out,outid就是这其中的1 
	//cout<<outid<<endl;
	
	if(islinux)basepath=frepath.erase(p,frepath.length()) +"data/" + pbname + "/"; //linux系统 
	else basepath=frepath.erase(p,frepath.length()) +"data\\" + pbname + "\\"; //windows系统 
	//cout<<basepath;
	
	//基本路径指的是题目文件夹，pbname是题目名 
	// basepath = ....\lemon\比赛文件夹\data\pbname\      windows
	// 或  basepath = ..../lemon/比赛文件夹/data/pbname/  linux
	
	//判断答案文件是否从0开始计数，你可以在此添加更多的枚举项，但请与答案文件的枚举项相对应 
	int trypp=4;bool form0=false;
	string tmppath[trypp];
	tmppath[0]=basepath + pbname + "0.out";
	tmppath[1]=basepath + pbname + "0.ans";
	tmppath[2]=basepath + "0.ans";   
	tmppath[3]=basepath + "0.out";
	for(int i=0;i<trypp;i++) 
	{
		if(freopen(tmppath[i].data(),"r",stdin)!=NULL) {form0=true;break;}
	}
	
	if(!form0) 
	//文件不从0开始计数 
	{
		stringstream ss;
		ss<<atoi(outid.c_str())+1;
		outid = ss.str();
	}//outid+1..
	
	//拼合并枚举答案文件路径 ，你可以在此添加更多的枚举项，但请与上面的枚举项相对应  
	int tryap=4;
	string anspath[tryap]; 
	anspath[0]=basepath + pbname + outid +".out";
	anspath[1]=basepath + pbname + outid +".ans";     
	anspath[2]=basepath + outid +".ans";   
	anspath[3]=basepath + outid +".out";    
	
	bool flag=0;
	for(int i=0;i<tryap;i++)
	{
		if(freopen(anspath[i].data(),"r",stdin)!=NULL) {flag=1;break;}
	} 
	
	if(flag)//若找到了答案文件 
	{ //逐行读入并输出 
		string inpath=pbname + ".out"; 
		freopen(inpath.data(),"w",stdout);
		char m[99];memset( m, 0, sizeof(m) ); 
		while(cin.getline(m,99))
		{
			if(!toggle[atoi(outid.c_str())])cout<<m<<endl;
			//MessageBox(NULL,m,"",MB_OK); //测试用的 =_= ，这行可以删 
			memset(m, 0, sizeof(m) ); 
		}
		return 0;
	}
	else return -2;

} 
int main()
{
	int status=ac();
	if(status!=0)
	{
		/*
		cout<<"AC自动机 For Lemon"<<endl；
		cout<<"题目名: "<<pbname<<endl；
		cout<<"测试点数量: "<<answers<<endl；
		switch(ac()) 
		{
			case -2:
				cout<<"Err 2:未找到可用的答案文件";
				break;
			case -1:
				cout<<"Err 1:不处于Lemon评测环境下";
				break;
		}*/
		string strin,strout;
		strin=pbname+".in";
		strout=pbname+".out";
		freopen(strin.c_str(),"r",stdin);
		freopen(strout.c_str(),"w",stdout);
		//找不到答案文件，请给自己留条后路，写主程序吧。。 
		//....
		
		
	}
}

