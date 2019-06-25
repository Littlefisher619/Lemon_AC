# Lemon Universal AC Source(C++)

为 [Lemon评测软件](https://github.com/zhipeng-jia/project-lemon) 量身定做的"AC自动机"。

LemonAC 仅供娱乐使用，或者当您的```std```文件夹缺少对应的标程时，可以暂时用此代码代替。
**不建议您在正式场合/培训时使用本代码进行提交**


## 运行环境
* Windows & Linux
* 仅适用于Lemon评测系统。


## 配置项目

| 行数        |   名称   |  代码  |
| :-------:| :-------:  | :------:  |
| 76   | 题目名称 | ```const string pbname="ProblemName"``` |
| 78   | 测试点数量 | ```const int answers= 10``` |
| 86 |   指定测试点WA   |   ```toggle[i]=1```   |
| 125 |    路径枚举1    |  ```tmppath[3]=basepath + pbname + "0.out"``` 或 ```tmppath[3]=basepath + "0.out"```|
|145|路径枚举2|```anspath[3]=basepath + outid +".out"``` 或 ```anspath[0]=basepath + pbname + outid +".out"```|
|193|解决方案|```将您的主程序写在此处，避免枚举失效的情况发生```|
