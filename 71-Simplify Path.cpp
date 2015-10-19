/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/
//二刷，12ms 8.86%
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string str;
        for(int i=0;i<path.size();i++){
            if(path[i] == '/'){
                if(str == ".."){
                    if(!s.empty())
                        s.pop();
                }
                else if(str!="." && str!=""){
                    s.push(str);
                }
                str="";
            }
            else{
                str+=path[i];
            }
        }
        if(str == ".."){
            if(!s.empty()){
                s.pop();
            }
        }
        else if(str!="." && str!=""){
            s.push(str);
        }
        
        if(s.empty()){
            return "/";
        }
        string res;
        while(!s.empty()){
            res = "/"+s.top()+res;
            s.pop();
        }
        return res;
        
    }
};
////麻痹，跑不了
// //c++中的Vector可以当栈用push_back()与push_front()
// //cd d//github——>cd d/github——
// //cd d/github/leetcode/../——>d/github
// class Solution {
//     public String simplifyPath(String path) {
//         vector<string> stack;
// 		assert(path[0]=='/');
// 		int i=0;
// 		while(i<path.size())
// 		{
// 			while(path[i]=='/' && i<path.size())  i++;
// 			if(i==path.size())
// 				break;
// 			int start=i;//找到路径中有效单词的开始
// 			while(path[i]!='/'&&i<path.size()) i++;
// 			int end = i-1;//路径中有效单词的结束
// 			string element = path.substr(start,end-start+1);
// 			if(element=="..")
// 			{
// 				if(stack.size()>0)
// 				stack.pop_back();
// 			}
// 			else if(element !=".")
// 			stack.push_back(element);
// 		}
// 		if(stack.size()==0) return "/";
// 		string simpPath;
// 		for(int i=0;i<stack.size();i++)
// 		simpPath+="/"+stack[i];
// 		return simpPath;
//     }
// };
