----------------------------
�ļ����					|
----------------------------
	# �ļ�������
		* �豸�ļ�,�豸Ҳ���Ե����ļ�,�߱�io
		* �����ļ�

	# ���ļ�
		FILE *fopen( const char * filename, const char * mode );
		
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
		
		* �����ʧ��,���� NULL
			FILE *file = fopen("d.txt","r");
			if (file == NULL){
				perror("fopen");	//fopen: No such file or directory
				return EXIT_FAILURE;
			}
		* ע��,�ýṹ�����ڶѿռ�����,ʹ����ɺ�Ҫ�ͷ�
		* �ļ��Ĵ�,���������·��,Ҳ�����Ǿ���·��
			fopen("./d.txt","r");


	# �ر��ļ�
		int  fclose (FILE *);
	
	# ˢ��������
		int fflush (FILE *);
	
	# �ض����ļ�
		FILE * freopen (const char *, const char *, FILE *);
	
	# FILE �ṹ�������
		typedef struct _iobuf
		{
		  char	*_ptr;
		  int	 _cnt;
		  char	*_base;
		  int	 _flag;
		  int	 _file;
		  int	 _charbuf;
		  int	 _bufsiz;
		  char	*_tmpfname;
		} FILE;

		typedef struct 
		{
			short			level;		//������״̬,�����߿�
			unsigned		flags;		//�ļ�״̬��ʶ
			char			fd;			//�ļ�������
			unsigned char	hold;		//���޻���������ȡ�ַ�
			short			bsize;		//��������С
			unsigned char	*buffer;	//����������λ��
			unsigned		ar;			//ָ��,��ǰ��ָ��
			unsigned		istemp;		//��ʱ�ļ�,ָʾ��
			short			token;		//������Ч�Եļ��
		} FILE;
	

----------------------------
�ı��ļ��Ķ�д				|
----------------------------
	# ��ȡ/д�뵥���ַ�
		fgetc( FILE * fp );
			* fgetc() ������ fp ��ָ��������ļ��ж�ȡһ���ַ�,����ֵ�Ƕ�ȡ���ַ�
			* ������������򷵻� EOF,(-1)
		
		fputc( int c, FILE *stream );
			* ���ڰѵ����ַ�д��streamָ�����ļ���
			* ��д��ɹ�,���᷵��д����ַ�,�����������,���߶�ȡ����ĩβ,��᷵�� EOF(-1)
		
	# ��ȡ/д���ַ���
		fgets(char *s,int size,FILE stream)
			* ����
				s: �ַ���
				size:ָ����ȡ����ַ����ĳ���(Ĭ�� -1,������)
				stram:�ļ�ָ��,'�����ȡ����������ַ���,�̶�Ϊstdin'
			* ��streamָ�����ļ��ڶ����ַ�,���浽sָ�����ڴ�ռ�,ֱ�����ֻ����ַ�,��ȡ���ļ���β,�����Ѿ���ȡ��size - 1 ���ַ�Ϊֹ
			* ���Զ��������� '\0' ��ʶ,��ѻ��з�Ҳһ���ȡ��ȥ
			* s���ֻ��װ length - 1���ַ�,��Ϊ����Ҫ��һ�����ַ��������� '\0',����������ݴ����� size ���� sizeof(s) ��ô�������ֻᱻ�ض�
			* ��ȡ�ɹ����ض�ȡ�����ַ���,��ȡ���ļ�ĩβ���߳���,���� NULL
			* ��ȡ�ļ�
				FILE *file = fopen("E:\\c-lang.txt","r");
				char buf[1024];
				char *r = fgets(buf,sizeof(buf) - 1,file);
				while(r != NULL){
					printf("%s",buf);
					r = fgets(buf,sizeof(buf) - 1,file);
				}
		
		fputs(const char *str,FILE *stream)
			* �� str �ַ�д�뵽streamָ�����ļ���,�ַ��������� '\0' ��д���ļ�
			* �ɹ����� 0,ʧ�ܷ��� EOF(-1)
			* ���԰�stream�滻Ϊ stdout,ʹstr���������Ļ
		
	

	# ��ʽ�������		fprintf(FILE *fp,const char *format, ...)
		* Դ�Ǳ���,Ŀ�����ļ�

		FILE *file = fopen("E:\\c-lang.txt","w+");
		fprintf(file,"Hello KevinBlany ,Im %s","Java");
		fclose(file);
		
	
	# ��ʽ��������		int fscanf(FILE *fp, const char *format, ...) 
		* Դ���ļ�,Ŀ���Ǳ���
		* ���������ļ��ж�ȡ�ַ���,������������һ���ո��ַ�ʱ,����ֹͣ��ȡ

		FILE *file = fopen("E:\\c-lang.txt","r");
		int x,y,z;
		fscanf(file,"%d %d %d",&z,&y,&z);
		printf("z=%d,y=%d,z=%d",z,y,z);		//z=36,y=12,z=36
		fclose(file);
	
	# �ж��ļ��Ƿ��ȡ����ĩβ
		* �ı��ļ���ĩβ����һ�����ص�-1(EOF),��ʾ�ļ��Ѿ�����
		* �������ļ�ĩβû��-1��ʶ,��Ϊ-1�������ļ��е�����,ͬ�� -1 ���жϲ�����
		* ����ͨ�� feof() ���ж��ļ��Ƿ��ȡ����ĩβ,�����Ƕ������ļ������ı��ļ�
		* feof(); ���� bool
			FILE *file = fopen("c.txt","r");

			bool end = feof(file);
			printf("%d",end);		//0

		* ����ʵ���ж����ȡ�������,�ǲ���ĩβ��ʶ,Ҳ����˵Ҫ�ȶ�ȡ��ĩβ��ʶ,����,һ���ȶ�ȡ,���ж�
			fgetc(file);
			if(feof(file)){
				break;
			}
			....
	

----------------------------
���io						|
----------------------------
	int fseek (FILE *file, long offset, int whence); 
		* fseek ���õ�ǰ��д�㵽 offset ��
		* whence ������ SEEK_SET,SEEK_CUR,SEEK_END ��Щֵ�����Ǵ��ļ�ͷ,��ǰ��,�ļ�β	����ƫ���� offset
		* ��Ե�ǰλ�������ƶ�һ���ֽ�:fseek(fp,1,SEEK_CUR);
		* ��ǰ�ƶ�һ���ֽ�.ֱ�Ӹ�Ϊ��ֵ�Ϳ���:fseek(fp,-1,SEEK_CUR)

			FILE *file = fopen("E:\\c-lang.txt","r+");
			//ָ���ƶ�����10���ֽ�
			fseek(file,10,SEEK_SET);
			//�ѵ�10���ֽ��滻Ϊ'A'
			if(fputc('A',file) == EOF){
				printf("�쳣");
			}
			fclose(file);

		* ֻ���� r+ ģʽ���ļ����ܲ�������,w �� w+ ģʽ������յ�ԭ���ļ�����������д
		* a �� a+ ģʽ���ܻ����ļ���β�������,������ fseek() �ƶ����ļ�ָ��λ��

----------------------------
�������ļ��Ķ�д			|
----------------------------
	
	size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
				  
	size_t fwrite(const void *ptr, size_t size_of_elements,size_t number_of_elements, FILE *a_file);

	# �����������������ڴ洢��Ķ�д - ͨ���������ṹ��