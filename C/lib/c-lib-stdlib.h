--------------------------------
stdlib							|
--------------------------------

FILE

NULL
	* null 

EXIT_SUCCESS = 0
	* �ɹ�

EXIT_FAILURE = 1
	* ʧ��
	
exit()
	* �����˳�,����Ϊ int ֵ,��ʾ������˳�״̬

system()
	* ִ��ϵͳ����
	* ����ֵ int,��ֵ���ǳ���ķ���ֵ,�ڲ�ͬ��ƽ̨��һ��

char *getenv (const char *);
	* ��ȡϵͳ��������,��������ڷ���NULL
		char *p = getenv("JAVA_HOME");
		printf("%s",p);	//C:\Program Files\Java\jdk1.8.0_171

srand(unsigned int)
	* ���������������

rand()
	* �ú�������һ������� int
	* �������һ��,��ô��ε��õĽ��Ҳһ��

atoi(const char *nptr);
	* ���ַ���ת��Ϊ����,Ȼ�󷵻�
	* ������ǰ��Ŀո�,ֱ���������ֻ��������Ųſ�ʼת��,�����������ַ�������\0�ͽ���ת��,���ҷ���ת�����

stof(const char *nptr);
	* ͬ��
	* ���ַ���ת��Ϊfloat
	
atol(const char *nptr);
	* ͬ��
	* ���ַ���ת��Ϊlong

void *malloc (size_t)
	* ������ʾ����Ŀռ��Ƕ���
	* �������ɹ�,���ص����ݾ�������Ķѿռ����Ԫ�ص�ַ(ָ��),����ʧ��,���� NULL
	* ����Ķѿռ�,�������û�н���,��ô�����ͷ�,��Ҫ�����ֶ����ͷ�
	* demo
		int *p = (int *) malloc(sizeof(int));
		*p = 15;
		printf("%d",p[0]);		//15

void free (void *);
	* �ͷŶѿռ���ڴ�,����������ϵͳ
	* ͬһ����Ķ��ڴ�,ֻ��ִ��һ���ͷŲ���
	* �ͷŵ��ڴ��,ִ�и��ڴ��ָ�����Ұָ����

fclose()
fopen()
freopen()
fflush()