----------------------------
�ṹ��						|
----------------------------
	# ����������ɴ洢��ͬ����������ı���,�ṹ�� C �������һ���û��Զ���Ŀ��õ���������,������洢��ͬ���͵�������
	# �ṹ��������붨���ֵ�ĳ�ʼ��
		struct Book {
			int id;
			char name[50];
			char *author;
			double price;
		};

		struct Book java,python;

		java.id = 1;	
		strcpy(java.name,"Java���ŵ���ͨ");		//�ַ����������ʹ��copy
		java.author = "KevinBlandy";			//�ַ�ָ��,����ֱ�Ӹ�ֵ
		java.price = 15.6;

		printf("id=%d,name=%s,author=%s,price=%f",java.id,java.name,java.author,java.price);
		//id=1,name=Java���ŵ���ͨ,author=KevinBlandy,price=15.600000
	
	# �ṹ��Ϊ��������
		struct Book {
			int id;
			char name[50];
			char *author;
			double price;
		};
		void func(struct Book book){
			printf("id=%d,name=%s,author=%s,price=%f\n",book.id,book.name,book.author,book.price);
		}
		int main(){
			struct Book java;
			java.id = 1;
			strcpy(java.name,"Java���ŵ���ͨ");
			java.author = "KevinBlandy";
			java.price = 15.6;
			func(java);	//id=1,name=Java���ŵ���ͨ,author=KevinBlandy,price=15.600000
			return EXIT_SUCCESS;
		}
	
	# ָ��ṹ��ָ��
		struct Book {
			int id;
		};
		int main(){
			//��ʼ���ṹ��
			struct Book java;
			//��ʼ������ֵ
			java.id = 15;

			//����һ��ָ��ṹ���ָ��
			struct Book *p;
			//��ȡ�ṹ��ĵ�ַ
			p = &java;
			
			//ͨ�� -> ��������ͨ���ṹ��ָ����ʽṹ������
			printf("id=%d\n",p -> id);
	
			//Ҳ����ͨ�� -> ����������ֵ
			p -> id = 255;
			return EXIT_SUCCESS;
		}
	
	# �ṹ���ڴ����ԭ��
		* ԭ��һ:�ṹ����Ԫ�ذ��ն���˳���ŵ��ڴ���,����'���ǽ�������'
		* �ӽṹ��洢���׵�ַ��ʼ ,ÿһ��Ԫ�ش����ڴ���ʱ,��������Ϊ�ڴ������Լ��Ŀ�������ֿռ��
		* ���'Ԫ�ش�ŵ�λ��һ�������Լ���С���������Ͽ�ʼ'
			

		* ԭ���:��ԭ��һ�Ļ�����,���������'�洢��Ԫ�Ƿ�Ϊ����Ԫ��������Ԫ�س��ȵ�������'
		* ����,�����:����,����'����'Ϊ����������

		* ����demo
			struct Data{
				char a;			//1 -> 1���ֽ�
				int b;			//8 -> ��Ϊ����Ԫ�ض���int,ǰ���ĸ��ֽ��Ѿ���������,���Դ�4�ֽں󿪱��ڴ�
				char c;			//9 -> 1���ֽ�
				double d;		//24 -> ��Ϊ����Ԫ�ض���double,ǰ��9���ֽڶ���������,���Դ�18�ֽں󿪱��ڴ�
				short f;		//26 -> 2�ֽ�
			} data;

			/*
				26 % 8 != 0
				(26 + 6) % 8 == 0;
				26 + 6 = 32
			*/
			printf("d1 = %d\n",sizeof(data));		//32
		
			
	
----------------------------
�Ϸ��Ľṹ�嶨��������		|
----------------------------
	# ͬʱ����ṹ���Լ�����
		struct Book {
			int id;
			char name[50];
			char author[50];
			double price;
		} java,python;
		
	
	# �����ṹ��
		struct {
			int id;
			char name[50];
			char author[50];
			double price;
		} java,python;
	
	# ��������ṹ��
		struct Book {
			int id;
			char name[50];
			char author[50];
			double price;
		};

		* �����ýṹ��ı���
			struct Book t1, t2[20],*t3;
 
	# ��typedef����������
		typedef struct {
			int id;
			char name[50];
			char author[50];
			double price;
		} Book;

		* ���ڿ�����Book��Ϊ���������µĽṹ�����
			Book t1, t2[20],*t3;
	


----------------------------
λ��						|
----------------------------
	# ��Щ��Ϣ�ڴ洢ʱ,������Ҫռ��һ���������ֽ�,��ֻ��ռ������һ��������λ
	# �����ڴ��һ��������ʱ,ֻ�� 0 �� 1 ����״̬,�� 1 λ����λ����
	# Ϊ�˽�ʡ�洢�ռ�,��ʹ������,C �������ṩ��һ�����ݽṹ,��Ϊ"λ��"��"λ��"
	# �����븳ֵ
		struct Bits {
			int a :8;				//a����ռ��8bit
			unsigned int b :2;		//b����ռ��2bit
			int c :6;				//c����ռ��6bit
		} bits,*p;			

		bits.a = 2;			//��ʼ������ֵ

		p = &bits;			//��ȡ��ַ
	
		//ͨ������/ָ�����ֵ
		printf("%d %d\n",bits.a,p -> a);		//2 2
	

	# һ��λ�����洢��ͬһ���ֽ���,���ܿ������ֽ�
		* ��'һ���ֽ���ʣ�ռ䲻�������һλ��ʱ,Ӧ����һ��Ԫ���Ÿ�λ��',Ҳ��������ʹĳλ�����һ��Ԫ��ʼ
		struct Bits {
			unsigned a :4;	//һ�����ݴ洢����4bit
			unsigned   :4;	//ʣ�µ�4bit����
			unsigned b :4;	//����һ����Ԫ��ʼ���
			unsigned c :4;
		};
	
	# ����λ������������ֽ�,���λ��ĳ��Ȳ��ܴ���һ���ֽڵĳ���,Ҳ����˵���ܳ���8λ����λ
		* �����󳤶ȴ��ڼ�����������ֳ���һЩ���������ܻ���������ڴ��ص�
		* ����һЩ���������ܻ�Ѵ���һ����Ĳ��ִ洢����һ������

	# λ�����������λ��,��ʱ��ֻ�������������λ��,������λ���ǲ���ʹ�õ�
		struct k{
			int a:1;
			int  :2;    /* �� 2 λ����ʹ�� */
			int b:3;
			int c:2;
		};

		

	# bitλ������С�ڵ�������������
		struct Bits{
			int a:1;		//1С�ڵ���int��λ��,��������ǺϷ���
		};
	
	
	# ��ֵ�������λ��,���ܻᶪʧ����
		struct {
			unsigned int age :3;
		} Age;

		Age.age = 8; // �����Ʊ�ʾΪ 1000 ����4λ,����
		printf("Age.age : %d\n", Age.age);		//0