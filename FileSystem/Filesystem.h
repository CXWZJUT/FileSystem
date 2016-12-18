struct INODE//i结点(64B)  已保证了每两个数据之间有空格隔开
{                                                  //占位数    INODE中偏移地址
	int fsize;//文件大小                            setw(6)     (0 ~ 5)
	int fbnum;//文件盘块数        setw(6)===> 目录文件为1数据文件1~4都有  (6 ~ 11)
	int addr[4];//四个直接盘块号(0 ~ 512*4==2048b)  setw(3)*4     
	int addr1;//一个一次间址()                      setw(3)     (24 ~ 26)
	int addr2;//一个两次间址()                      setw(3)     (27 ~ 29)
	char owner[6];//文件拥有者                      setw(6)     (30 ~ 35)
	char group[6];//文件所属组                      setw(6)     (36 ~ 41)
	char mode[11];// 文件类别及存储权限             setw(12)    (42 ~ 53)
	//[0]类型(d是目录-是文件)[1~3]owner权限
	//[4~6]group权限[7~9]other权限 r(读)w(写)x(执行)
	char ctime[9];//最近修改时间                    setw(10)    (54 ~ 63)
};

struct SUPERBLOCK//超块
{
	int fistack[80];//空闲结点号栈          setw(3)*80   用了填-1
	int fiptr;//空闲结点栈指针(还有多少个)  setw(3)
	int fbstack[10];//空闲盘块号栈          setw(3)*10
	int fbptr;//空闲结点栈指针              setw(3)
	int inum;//空闲i结点总数                setw(3)
	int bnum;//空闲盘块总数                 setw(3)
};
SUPERBLOCK superblock;//模拟内存超块

struct DIR//目录项(36B)
{
	char fname[14];//文件名(当前目录)        setw(15)   (0 ~ 14)
	int  index;//i结点号                     setw(3)    (15 ~ 17)
	char parfname[14];//父目录名             setw(15)   (18 ~ 32)
	int  parindex;//父目录i结点号            setw(3)    (33 ~ 35)
};