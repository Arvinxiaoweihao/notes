------------------------------------
Redis-���ϵ�����					|
------------------------------------
	# ʹ��lettuce
	# ����
		<dependency>
	        <groupId>org.springframework.boot</groupId>
	        <artifactId>spring-boot-starter-data-redis</artifactId>
    	</dependency>
		<dependency>
		    <groupId>io.lettuce</groupId>
		    <artifactId>lettuce-core</artifactId>
		</dependency>
		<dependency>
		    <groupId>org.apache.commons</groupId>
		    <artifactId>commons-pool2</artifactId>
		</dependency>
	
	# �����ļ�
		# Redis���ݿ�������Ĭ��Ϊ0��
		spring.redis.database=0  
		# Redis��������ַ
		spring.redis.host=192.168.0.58
		# Redis���������Ӷ˿�
		spring.redis.port=6379  
		# Redis��������������(Ĭ��Ϊ��)
		spring.redis.password=  
		# ���ӳ����������(ʹ�ø�ֵ��ʾû������)
		spring.redis.lettuce.pool.max-active=8  
		# ���ӳ���������ȴ�ʱ��(ʹ�ø�ֵ��ʾû������)
		spring.redis.lettuce.pool.max-wait=-1  
		# ���ӳ��е�����������
		spring.redis.lettuce.pool.max-idle=8  
		# ���ӳ��е���С��������
		spring.redis.lettuce.pool.min-idle=0  
		# ���ӳ�ʱʱ��(����)
		spring.redis.timeout=2000

	# ʹ��
		* StringRedisTemplate
			* ��RedisTemplate������
			* һ����������ʹ����
		* ���jedis�ͻ����д���api�����˹����װ,��ͬһ���Ͳ�����װΪoperation�ӿ�
			ValueOperations	��K-V����
			SetOperations	set�������ݲ���
			ZSetOperations	zset�������ݲ���
			HashOperations	���map���͵����ݲ���
			ListOperations	���list���͵����ݲ���
		* demo
			@Autowired
			private StringRedisTemplate stringRedisTemplate;

			stringRedisTemplate.opsForValue();		//��ȡ������k-v��api
			stringRedisTemplate.opsForSet();		//��ȡ����set��api
	
		
			
------------------------------------
Redis-���ϼ�Ⱥ						|
------------------------------------	
	
	

------------------------------------
Redis- scan ���� keys *				|
------------------------------------
	public void scan(String pattern, Consumer<byte[]> consumer) {
		this.stringRedisTemplate.execute((RedisConnection connection) -> {
			try (Cursor<byte[]> cursor = connection.scan(ScanOptions.scanOptions().count(Long.MAX_VALUE).match(pattern).build())) {
				cursor.forEachRemaining(consumer);
				return null;
			} catch (IOException e) {
				e.printStackTrace();
				throw new RuntimeException(e);
			}
		});
	}