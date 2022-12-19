# 鹅鸭杀作弊

[![麻省理工学院执照](https://camo.githubusercontent.com/a534d512dd511cc3dbba106a143f49102de27441cefb97421d90dc8d8ea7661f/68747470733a2f2f696d672e736869656c64732e696f2f61706d2f6c2f61746f6d69632d64657369676e2d75692e7376673f)](https://github.com/tterb/atomic-design-ui/blob/master/LICENSEs)

庸医！庸医！庸医！庸医！庸医！庸医！庸医！庸医！庸医！庸医！庸医！庸医！

**鹅鸭杀**的免费开源作弊软件

** 仅适用于视窗!!!!!**

（在 Windows 10 上测试，未在其他 Windows 版本中测试。但我认为Windows 11会运行良好。

（我认为这可能是低效的，因为我不擅长编程。如果您认为有什么需要改进的地方，请给我您的积极意见。

#### 如果它不好玩也没关系，它是为那些想赢的人准备的。

#### 它也是为个人学习而制作的，对于因使用/滥用该项目而引起的任何问题，我概不负责。

## 那么，怎么用呢？

只需使用Visual Studio遵守它，并使用您最喜欢的注射器进行注射。 （在编译之前，请检查“发布x64”。

注入 dll 后，按插入打开或关闭作弊菜单。 （注入前请确保游戏窗口的分辨率为 1280x720）

## 特征

- 用户和角色列表（正在处理）
- 在地图上绘制每个人的位置（预定）
- 图形用户界面
- AOBS扫描某些偏移量（计划）

## 已知错误

- 注入时，游戏崩溃。请稍等片刻，然后重新注入 dll。
- 在结束游戏或投票时间后，有时游戏崩溃。我不知道这个。如果你知道这件事，请通知我。

## 反编译工具

- Visual Studio 2022 community v17.3.3
- cheat engine 6.3.0.0 & Mono dissector
- x64dbg
- Il2cppDumper

\#Postscript

如果您在编译过程中遇到 minhook 问题，请重建 Minhook 并将 “libMinHook.x64.lib” 替换为您自己的。（不要更改文件名！ 如果您认为 ESP 功能不起作用，请单击屏幕上的任意位置以移动角色。

## 嘟嘟嘟

参考

- [Rebzzel / kiero](https://github.com/Rebzzel/kiero)
- [TsudaKageyu / minhook](https://github.com/TsudaKageyu/minhook)
- [ocornut / imgui](https://github.com/ocornut/imgui)
- [stackoverflow - GetProcessBaseAddress](https://stackoverflow.com/questions/26572459/c-get-module-base-address-for-64bit-application)
- [TFive - Il2CppDumper GUI](https://github.com/T5ive/Il2CppDumper-GUI)