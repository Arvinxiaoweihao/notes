--------------------------------
stdio							|
--------------------------------

EOF
	* -1,��ʾ�ļ���β

stdin
	* ��׼������ָ��
stdout
	* ��׼�����ָ��
stderr
	* ��׼������ָ��


printf()
	* ���ڱ�ע���(��ӡ)
	* ֧���ַ���ռλ��,�����ϸ���ռλ�����������ʹ��ݲ���
		printf("Hello %d,%d",5,6);

sprintf(char dst*, const char *, ...)
	* �� �ַ�����ʽ����,д�뵽dst��
		int x = 10;
		char y = 'H';
		char str[] = "Java";
		char dst[100];
		sprintf(dst,"x = %d,y = %c,buf = %s",x,y,str);
		printf("dst = %s\n",dst);	//dst = x = 10,y = H,buf = Java

puts()
	* ����ֻ��������ַ���,����ʹ��ռλ��,�Զ���ӻ���
	* ����Ĳ�������ֱ�����ַ��������Ǵ���ַ������ַ�������
	* ������ printf("%s\n",s);��������ͬ

scanf()
	* ��ȡ��Ļ����,�� printf һ��,Ҳ����ʹ�ø�ʽ�ַ����Ͳ����б�
	* scanf �ڶ�ȡ��ʱ��,���������зǿհ׷�ǰ��Ŀհ׷�
	* printf����ʹ�ñ���,�����ͱ��ʽ,scanf����ʹ�ñ�����ָ��
		int var1;
		int var2;
		scanf("%d %d",&var1,&var2);
		printf("%d %d",var1,var2);

	* ���û�ͨ��scanf�����ַ�ʱ,������Ĭ���Ȱ����ݷ��ڻ�����
	* scanf�Զ��ڻ�������ȡ����

sscanf (const char *, const char *, ...)
	* ʹ��Ԥ������ַ���,����Ϊ��׼�����������ģ��ֵ
		//����һ��"������ַ���"
		char dst[] = "1 2 3";
		//�������
		int a,b,c;
		//ʹ�� cccanf �� ������ַ�,��ֵ������
		sscanf(dst,"%d %d %d",&a,&b,&c);
		//�ɹ���ֵ
		printf("a=%d,b=%d,c=%d\n",a,b,c);	//a=1,b=2,c=3

	* ��ȡ���α���������
		char inputs[] = "a=10,b=20";
		int a , b;
		sscanf(inputs,"a=%d,b=%d",&a,&b);
		printf("a=%d,b=%d\n",a,b);  //a=10,b=20

	* ��ȡ�ַ���,Ĭ���Կո�ָ�
		char temp[] = "abc def 123";
		char str1[4],str2[4],str3[4];
		sscanf(temp,"%s %s %s",str1,str2,str3);
		printf("str1=%s,str2=%s,str3=%s",str1,str2,str3);//str1=abc,str2=def,str3=123

getchar()
	* ��ȡ��һ���ַ�������,���ҷ���,��ֻ�����ַ�
	* ��ͬ��
		char ch;
		scanf("%c",&ch);

putchar()
	* �ú��������þ���,��ӡ�ú����Ĳ���,��ֻ�����ַ�
	* ��ͬ��
		char ch = '1';
		printf("%d",ch)

gets(char *s)
	* �ӱ�׼�����ȡ�ַ�,�����浽sָ�����ڴ�ռ�ֱ�����ֻ��з������ļ���βΪֹ
	* ���ض�ȡ�ɹ����ַ���,�����ȡʧ�ܷ��� NULL
	* ����scanf������,����������������пո�
	* ����scanf���޷�֪�������ַ����Ĵ�С,�����������з����߶�ȡ���ļ��Ľ�β�Ž�������������׵�������Խ��(���������)
	* ��api�Ѿ�����,������ʹ��( warning: the `gets' function is dangerous and should not be used.)

fgets(char *s,int size,FILE *stream)
	* ����
		s: �ַ���
		size:ָ����ȡ����ַ����ĳ���(Ĭ�� -1,������)
		stram:�ļ�ָ��,'�����ȡ����������ַ���,�̶�Ϊstdin'
	* ��streamָ�����ļ��ڶ����ַ�,���浽sָ�����ڴ�ռ�,ֱ�����ֻ����ַ�,��ȡ���ļ���β,�����Ѿ���ȡ��size - 1 ���ַ�Ϊֹ
	* ���Զ��������� '\0' ��ʶ,��ѻ��з�Ҳһ���ȡ��ȥ
	* s���ֻ��װ length - 1���ַ�,��Ϊ����Ҫ��һ�����ַ��������� '\0',����������ݴ����� size ���� sizeof(s) ��ô�������ֻᱻ�ض�
	* ��ȡ�ɹ����ض�ȡ�����ַ���,��ȡ���ļ�ĩβ���߳���,���� NULL
	* �޷���ȡ����???
	* ��ȡ��������demo
		char buf[100];
		fgets(buf,sizeof(buf),stdin);
		printf("���������:%s\n",buf);

puts(const char *s)
	* ��׼�豸���s�ַ���,���Զ���ӻ��з� \n
	* �ɹ����طǸ���,ʧ�ܷ��� -1


fputs(const char *str,FILE *stream)
	* �� str �ַ�д�뵽streamָ�����ļ���,�ַ��������� '\0' ��д���ļ�
	* �޷��������???

fprintf(FILE *fp,const char *format, ...)
	* ���԰Ѹ�ʽ��������,�����ָ������
		FILE *file = fopen("E:\\c-lang.txt","w");
		fprintf(file,"Hello %s","Java");
		fclose(file);
	* printf("Hello %s","Java") == fprintf(stdout,"Hello %s","Java")

fscanf(FILE *fp, const char *format, ...) 
	* ���������ļ��ж�ȡ�ַ���,������������һ���ո�/�����ַ�ʱ,����ֹͣ��ȡ
		FILE *file = fopen("E:\\c-lang.txt","r");
		char buf[1024];
		fscanf(file,"%s",buf);	//��ȡ����һ��,����buf

sprintf(char dst*, const char *, ...)
	* �� �ַ�����ʽ����,д�뵽dst��

sscanf (const char *, const char *temp, ...)
	* �Ѵ�dst��ȡ�����ַ���,��䵽tempģ��
		//����һ��"������ַ���"
		char dst[] = "1 2 3";
		//�������
		int a,b,c;
		//ʹ�� cccanf �� ������ַ�,��ֵ������
		sscanf(dst,"%d %d %d",&a,&b,&c);
		printf("a=%d,b=%d,c=%d\n",a,b,c);	//a=1,b=2,c=3

	* ���ַ�������ȡ���α���������
		char inputs[] = "a=10,b=20";
		int a , b;
		sscanf(inputs,"a=%d,b=%d",&a,&b);
		printf("a=%d,b=%d\n",a,b);  //a=10,b=20

	* ��ȡ�ַ���,Ĭ���Կո�ָ�
		char temp[] = "abc def 123";
		char str1[4],str2[4],str3[4];
		sscanf(temp,"%s %s %s",str1,str2,str3);
		printf("str1=%s,str2=%s,str3=%s",str1,str2,str3);//str1=abc,str2=def,str3=123
	

FILE * fopen (const char *name, const char *model);
	* ��һ���ļ�,nameָ���ļ���ַ,modelָ���򿪵�����
	* model��ö���ַ���
		r	��һ�����е��ı��ļ�,�����ȡ�ļ�

		w	��һ���ı��ļ�,����д���ļ�,����ļ�������,��ᴴ��һ�����ļ�
			������,�������ļ��Ŀ�ͷд������,����ļ�����,��ûᱻ�ض�Ϊ�㳤��,����д��

		a	��һ���ı��ļ�,��׷��ģʽд���ļ�,����ļ�������,��ᴴ��һ�����ļ�
			������,����������е��ļ�������׷������

		r+	��һ���ı��ļ�,�����д�ļ�

		w+	��һ���ı��ļ�,�����д�ļ�,����ļ��Ѵ���,���ļ��ᱻ�ض�Ϊ�㳤��
			����ļ������ڣ���ᴴ��һ�����ļ�

		a+	��һ���ı��ļ�,�����д�ļ�,����ļ�������,��ᴴ��һ�����ļ�,��ȡ����ļ��Ŀ�ͷ��ʼ,д����ֻ����׷��ģʽ
	
	*  ������Ƕ������ļ�,����ʹ������ķ���ģʽ��ȡ������ķ���ģʽ��

		"rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"

int fclose (FILE *);
	* �ر��ļ�

int fseek (FILE *file, long offset, int whence); 
	* ���io

