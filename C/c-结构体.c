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
			return EXIT_SUCCESS;
		}

	
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
		* ��һ���ֽ���ʣ�ռ䲻�������һλ��ʱ,Ӧ����һ��Ԫ���Ÿ�λ��,Ҳ��������ʹĳλ�����һ��Ԫ��ʼ
		struct Bits {
			unsigned a :4; /* ռbit			*/
			unsigned   :4; /* ����ʹ��	*/
			unsigned b :4; /* ����һ�ֽڿ�ʼ��� */
			unsigned c :4;
		};
	
