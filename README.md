# CPP-inter-Objects-Communication
Introduced from `https://blog.csdn.net/langwang122/article/details/81238423`

![image](https://github.com/Bigpig4396/CPP-inter-Objects-Communication/blob/master/pic1.png)

In programming, we often need to introduce event triggering mechanism. For example, object `a` from class `A` needs to notify object `b` from class `B` when something in `a` happens. It is rather hard to do if `a` and `b` are from different classes. Here is a good template how this mechanism can be implemented in cpp. Use it when you need inter-class object communication.
