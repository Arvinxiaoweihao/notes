--------------------------------
string							|
--------------------------------

strcpy(char *dst,char *src);
	* �� src �����ݿ����� dst
	* ���src�����ݳ��ȴ���dst��,��ô������������
	* ֻ�´����һ��'\0'ǰ������,���һ�� '\0' ������Ŀ������
		char name[11] = "KevinBlandy";
		char cp_name[11];

		strcpy(cp_name,name);
		printf("%s\n",cp_name);		//KevinBlandy

 strncpy(char *dst,char *src,int size) 
	* �� src �����ݿ����� dst,size������������copy�ĳ���
	* ����ֻ���� sizeof(dst) - 1 ��Ԫ�ص�Ŀ��,��ΪҪ��һ��λ�ø�'\0'
	* ��� size ������ sizeof(dst) - 1,��ô�ᷢ�����
		char str[] = "123456";
		char dst[5];
		strncpy(dst,str,sizeof(dst) - 1);
		printf("%s",dst);       //123

	* ��� '\0' �ڿ����ķ�Χ֮��,��ô'\0'�Ժ������ȫ���ᱻ����
		char str[] = "Hello\0Java";
		char dst[100];

		strncpy(dst,str,sizeof(str));

		printf("dst = %s\n",dst);                       //Hello
		printf("dst = %s\n",dst + strlen("Hello") + 1); //

strcat(s1, s2)
	* �����ַ��� s2 ���ַ��� s1 ��ĩβ
		char s1[11] = "Hello";
		char s2[11] = " C";
		strcat(s1,s2);
		printf("%s\n",s1);	//HelloC

strncat(s1,s2,length)
	* ͬ��,��������׷���ַ����ĳ���
	* ��s2��ǰlength���ַ�׷�ӵ�s1
		char src[] = "Hello";
		char dst[] = "clang";
		strncat(src,dst,1);
		printf("result = %s\n",src);		//result = Helloc

strlen(s1)
	* �����ַ����ĳ���(�ֽڴ�С),������������,�������㵽��һ���ָ��
	* ���� size_t ����
		char s1[11] = "Hello";
		char s2[11] = "He\0llo";
		printf("%d %d\n",strlen(s1),strlen(s2));		//5 2

strcmp(s1,s2)
	* �ַ����ıȽ�
	* ��� s1 �� s2 ����ͬ��,�򷵻� 0
	* ��� s1<s2 �򷵻�С�� 0,��� s1 > s2 �򷵻ش��� 0
		char s1[11] = "Hello";
		char s2[11] = "Hi";
		char s3[11] = "Hello";
		printf("%d %d %d\n",strcmp(s1,s3),strcmp(s1,s2),strcmp(s2,s1));	//0 -1 1
	
strncmp(s1,s2,length)
	* ͬ��,Ҳ���ַ����ıȽ�,�÷�������ָ���Ƚϵ��ַ�������
		char src[] = "HelloC";
		char dst[] = "HelloJava";
		int result = strncmp(src,dst,5);
		printf("result = %d\n",result);	//result = 0

strchr(s1, ch);
	* ����һ��ָ��,ָ���ַ��� s1 ���ַ� ch �ĵ�һ�γ��ֵ�λ��
	* ���û�ҵ�����0
		char s1[11] = "Hello";
		printf("%p\n",strchr(s1,'H'));		//28FF35

strstr(s1, s2);
	* ����һ��ָ��,ָ���ַ��� s1 ���ַ��� s2 �ĵ�һ�γ��ֵ�λ��
	* ���û�ҵ�����0
		char s1[11] = "Hello";
		char s2[11] = "ll";
		printf("%p",strstr(s1,s2));	//0028FF37