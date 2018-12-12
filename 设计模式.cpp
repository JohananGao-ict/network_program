简单工厂、工厂方法、抽象工厂
单例模式
代理模式
外观模式
适配器模式
模板方法模式
策略模式
命令模式
观察者模式
装饰器模式




ftp服务器搭建：即是服务器也是客户端
安装apt-get install vsftpd
修改配置文件/etc/vsftpd.conf
重启服务：service vsftpd restart 
客户端：登录ftp serverIP


nfs服务器
安装apt-get install nfs-kernel-server
修改配置文件：/etc/exports   添加共享路径
重启服务：service nfs-kernel-server restart 
客户端：挂载：mount serverIP:/共享文件路径 

ssh服务器
安装apt-get install openssh-server
aptitude show openssh-server 查看SSH是否安装
客户端：
登录：ssh username@serverIP
退出登录：logout
远程到本地scp username@serverIP:远程目标路径 本地路径(-r复制目录)
本地到远程scp 本地路径 username@serverIP: 远程目标路径 
super copy

进程的五种状态：
初始态、就绪态、运行态、挂起态、终止态

fork()创建子进程
父进程成功，fork()返回子进程的PID
子进程成功，fork()返回0
getpid() 获取进程ID
getppid()获取父进程ID
父子间进程不能通过全局变量共享内存，线程是可以的
解决进程间通信：管道、共享内存等
exec函数组：需要注意的是exec并不是1个函数, 其实它只是一组函数的统称, 它包括下面6个函数
 execl、 execlp、 execle、execv、 execvp、 execve
 exec函数族重新替换.txt中的代码，执行exec中的代码
 
 孤儿进程
 爹先死，孩子还活着，孩子叫孤儿进程
 孤儿被init进程领养，init进程变成孤儿进程的父亲
 为了释放子进程占用的系统资源
 进程结束之后，能够释放用户区空间
 释放不了pcb，必须由父进程释放
 
 僵尸进程
 孩子死了，爹还活着，爹不去释放子进程的pcb，孩子就变成了僵尸进程
 是一个死了的进程
 回收进程：
 wait 阻塞函数
 waitpid
 
 进程间通信IPC
 常用几种方式：
 管道-简单
 信号-系统开销小
 信号量
 消息队列
 共享映射区-有无血缘关系的进程间通信都可以
 本地套接字-稳定
 
 
 
 
 匿名管道：pipe
 本质：内核缓冲区、伪文件不占用磁盘空间
 特点：
 两部分：读端，写端对应两个文件描述符
 数据写端流入，读端流出
 操作管道的进程被销毁之后，管道自动被释放了
 管道默认是阻塞的
 使用场景：只能血缘关系进程间通信
 管道的原理：
 内部实现方式：队列 环形队列 fifo
 缓冲区：默认4K
 管道的局限性：
 队列：数据只能读取一次，不能重复读取
 半双工
 设置读端为非阻塞：
 int flags = fcntl(fd[0],F_GETFL);
 flags |= O_NONBLOCK;
 fcntl(fd[0],F_SETFL,flags);
 
 有名管道：fifo
 特点：在磁盘上有这样一个文件p
 伪文件，在磁盘大小永远为0
 在内核中有一个对应的缓冲区
 半双工的通信方式
 使用场景：无血缘关系进程间通信
 创建方式：mkfifo 管道名
  
  内存映射:mmap 
  mmap()建立内存映射区
  munmap()释放内存映射区
 
 
