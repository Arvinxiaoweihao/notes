-----------------------------
Spring boot ʹ�� fastjson	 |
-----------------------------
	# spring Ĭ�ϵ�json�������� jackson
	# fastjson �ǰ���Ͱ͵�һ��������json���л����
		<dependency>
			<groupId>com.alibaba</groupId>
			<artifactId>fastjson</artifactId>
			<version>1.2.24</version>
		</dependency>
	
-----------------------------
Spring boot ����һ			 |
-----------------------------
	1,ʵ�� WebMvcConfigurer
	2,���Ƿ��� configureMessageConverters

	# ����
		@Configuration
		public class WebMvcConfiguration implements WebMvcConfigurer {
			@Override
			public void configureMessageConverters(List<HttpMessageConverter<?>> converters) {
				WebMvcConfigurer.super.configureMessageConverters(converters);

				FastJsonConfig fastJsonConfig = new FastJsonConfig();
				fastJsonConfig.setDateFormat("yyyy-MM-dd HH:mm:ss");
				fastJsonConfig.setCharset(StandardCharsets.UTF_8);
				fastJsonConfig.setSerializerFeatures(SerializerFeature.DisableCircularReferenceDetect);

				FastJsonHttpMessageConverter fastJsonHttpMessageConverter = new FastJsonHttpMessageConverter();
				fastJsonHttpMessageConverter.setSupportedMediaTypes(Arrays.asList(MediaType.APPLICATION_JSON_UTF8));
				fastJsonHttpMessageConverter.setFastJsonConfig(fastJsonConfig);

				converters.add(fastJsonHttpMessageConverter);
			}
		}


-----------------------------
Spring boot ������			 |
-----------------------------
	# ���������ʽ�� fastjson ����Ϣת����.����IOC
	# ����
		/**
		 * Created by KevinBlandy on 2017/2/25 16:47
		 */
		@Configuration
		public class HttpMessageConverterConfiguration {
			/**
			 * FastJsonpHttpMessageConverter4
			 * @return
			 */
			@Bean
			public HttpMessageConverters httpMessageConverter(){
				FastJsonpHttpMessageConverter4 fastJsonpHttpMessageConverter4 = new FastJsonpHttpMessageConverter4();
				fastJsonpHttpMessageConverter4.setSupportedMediaTypes(Arrays.asList(MediaType.APPLICATION_JSON_UTF8));
				FastJsonConfig fastJsonConfig = new FastJsonConfig();
				fastJsonConfig.setCharset(StandardCharsets.UTF_8);
				fastJsonConfig.setSerializerFeatures(
						SerializerFeature.PrettyFormat,				//��ʽ��
						SerializerFeature.WriteMapNullValue,		//���null�ֶ�
						SerializerFeature.QuoteFieldNames,			//ʹ��˫����
						SerializerFeature.WriteNullListAsEmpty);	//��null����/�������Ϊ[]
				fastJsonConfig.setDateFormat("yyyy-MM-dd HH:mm:ss");
				fastJsonpHttpMessageConverter4.setFastJsonConfig(fastJsonConfig);
				return new HttpMessageConverters(fastJsonpHttpMessageConverter4);
			}
			
			/**
			 * ����֧��
			 * @return
			 */
			@Bean
			public FastJsonpResponseBodyAdvice fastJsonpResponseBodyAdvice(){
				FastJsonpResponseBodyAdvice fastJsonpResponseBodyAdvice = new FastJsonpResponseBodyAdvice("callback","jsonp");
				return fastJsonpResponseBodyAdvice;
			}
		}
		* �����߼���ʵ��������


		
	
