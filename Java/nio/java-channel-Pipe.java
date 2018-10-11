------------------------
Pipe �ܵ�				|
------------------------
	# �ܵ���
		*  ������һͷ��д������,����һͷ��ȡ����
		* һ�����ڶ��̻߳�����,�е���������������Ϣ���ߵ�ģ��

	# �򿪹ܵ�
		Pipe pipe = Pipe.open();

	# �ӹܵ���ȡд��
		SinkChannel sinkChannel = pipe.sink();
	
	# �ӹܵ���ȡ����
		SourceChannel sourceChannel = pipe.source();
	
	# Demo
		import java.io.IOException;
		import java.nio.ByteBuffer;
		import java.nio.channels.Pipe;
		import java.nio.channels.Pipe.SinkChannel;
		import java.nio.channels.Pipe.SourceChannel;
		import java.nio.charset.StandardCharsets;
		import java.util.Scanner;

		public class Main {
			
			public static void main(String[] args) throws Exception {
				
				Pipe pipe = Pipe.open();
				
				SinkChannel sinkChannel = pipe.sink();
				
				SourceChannel sourceChannel = pipe.source();
				new Thread(() -> {
					try {
						ByteBuffer byteBuffer = ByteBuffer.allocate(1024);
						while(true) {
							sourceChannel.read(byteBuffer);
							byteBuffer.flip();
							byte bytes[] = new byte[byteBuffer.remaining()]; 
							byteBuffer.get(bytes);
							System.out.println(Thread.currentThread().getName() + "-�յ���Ϣ:" + new String(bytes,StandardCharsets.UTF_8));
							byteBuffer.clear();
						}
					} catch (IOException e) {
						e.printStackTrace();
					}
				}) .start();
			
				try(Scanner scanner = new Scanner(System.in)){
					ByteBuffer byteBuffer = ByteBuffer.allocate(1024);
					while(true) {
						String line = scanner.nextLine();
						System.out.println(Thread.currentThread().getName() + "-������Ϣ:" + line);
						byteBuffer.put(line.getBytes(StandardCharsets.UTF_8));
						byteBuffer.flip();
						sinkChannel.write(byteBuffer);
						byteBuffer.clear();
					}
				}
			}
		}