
# �Ƚ����,����ȳ�
	* Lst In First Out(LIFO)


# Python

	# ����ʵ��
	class Stack():
		def __init__(self):
			self.__arr = []
		
		# ѹ��ջ��
		def push(self, item):
			self.__arr.insert(0, item);

		# ����ջ
		def pop(self):
			return self.__arr.pop(0)
		
		# ջ��Ԫ��
		def peek(self):
			return self.__arr[0] if len(self.__arr) > 0 else None
		
		@property
		def size(self):
			return len(self.__arr)
		
		@property
		def empty(self):
			return self.size == 0

