-----------------------------
dataclasses					 |
-----------------------------
	* 3.7����ģ��

-----------------------------
dataclasses-�Զ�����������   |
-----------------------------
	* ģ�麯��
		dataclass(_cls=None, *, init=True, repr=True, eq=True, order=False,unsafe_hash=False, frozen=False)

		- init ����__init__����
		- repr  ����__repr__����
			* ���ɵ�repr�ַ��������������Լ�ÿ���ֶε����ƺ�repr,�������������ж����˳��
			* ���Ϊ��repr���ų����ֶβ���������,����: InventoryItem(name ='widget', unit_price = 3.0,quantity_on_hand = 10)
			* ������Ѷ���__repr__,����Դ˲���
		- eq ����__eq__����
			* �˷�����˳��Ƚ���,�ͺ��������ֶε�Ԫ��һ��,�Ƚ��е�����ʵ����������ͬ������
			* ������Ѷ���__eq__,����Դ˲���
		- order ����__lt __,__ le __, __ gt__��__ge__����
			* Щ��˳����Ƚ�Ϊ�����ֶ�Ԫ��,�Ƚ��е�����ʵ����������ͬ������
			* ��� orderΪtrue��eqΪfalse.������ValueError��
			* ������Ѿ������κε�__lt__,__le__,__gt__,��__ge__,Ȼ��ValueError�쳣����(???)

		- unsafe_hash
		- frozen

	*  demo
		import dataclasses

		@dataclasses.dataclass
		class User():
			# �������������Լ����Ե�����
			id: int
			name: str
			# Ĭ��ֵ
			join: bool = True
			
			def __str__(self):
				return 'id=%d,name=%s,join=%s' % (self.id, self.name, self.join)

		print(User(1, 'KevinBlandy'))  # id=1,name=KevinBlandy,join=True
		print(User(1, 'KevinBlandy', False))  # id=1,name=KevinBlandy,join=False
