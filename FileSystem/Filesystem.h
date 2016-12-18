struct INODE//i���(64B)  �ѱ�֤��ÿ��������֮���пո����
{                                                  //ռλ��    INODE��ƫ�Ƶ�ַ
	int fsize;//�ļ���С                            setw(6)     (0 ~ 5)
	int fbnum;//�ļ��̿���        setw(6)===> Ŀ¼�ļ�Ϊ1�����ļ�1~4����  (6 ~ 11)
	int addr[4];//�ĸ�ֱ���̿��(0 ~ 512*4==2048b)  setw(3)*4     
	int addr1;//һ��һ�μ�ַ()                      setw(3)     (24 ~ 26)
	int addr2;//һ�����μ�ַ()                      setw(3)     (27 ~ 29)
	char owner[6];//�ļ�ӵ����                      setw(6)     (30 ~ 35)
	char group[6];//�ļ�������                      setw(6)     (36 ~ 41)
	char mode[11];// �ļ���𼰴洢Ȩ��             setw(12)    (42 ~ 53)
	//[0]����(d��Ŀ¼-���ļ�)[1~3]ownerȨ��
	//[4~6]groupȨ��[7~9]otherȨ�� r(��)w(д)x(ִ��)
	char ctime[9];//����޸�ʱ��                    setw(10)    (54 ~ 63)
};

struct SUPERBLOCK//����
{
	int fistack[80];//���н���ջ          setw(3)*80   ������-1
	int fiptr;//���н��ջָ��(���ж��ٸ�)  setw(3)
	int fbstack[10];//�����̿��ջ          setw(3)*10
	int fbptr;//���н��ջָ��              setw(3)
	int inum;//����i�������                setw(3)
	int bnum;//�����̿�����                 setw(3)
};
SUPERBLOCK superblock;//ģ���ڴ泬��

struct DIR//Ŀ¼��(36B)
{
	char fname[14];//�ļ���(��ǰĿ¼)        setw(15)   (0 ~ 14)
	int  index;//i����                     setw(3)    (15 ~ 17)
	char parfname[14];//��Ŀ¼��             setw(15)   (18 ~ 32)
	int  parindex;//��Ŀ¼i����            setw(3)    (33 ~ 35)
};