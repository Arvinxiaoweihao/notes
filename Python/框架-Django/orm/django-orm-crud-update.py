------------------------------------
使用 save()							|
------------------------------------
	model = Model.objects.get(id=15)	# 根据PK检索出一条记录
	model.name = 'Litch'				# 修改ORM对象的属性
	model.save()						# 再次调用save()方法

	* 该方法会更新记录中的所有列,效率不高
	* 一次只能只能更新一条数据




------------------------------------
使用 update()						|
------------------------------------
	model = Model.objects.filter(id=15)	# 根据PK检索出记录
	model.update(name='Litch')			# 执行更新,update()参数为要更新的字段 & 值
	
	* 该方法仅仅只会更新需要更新的字段,效率较高
	* update() 是 QuerySet 对象的方法
	* 它可以一次性的批量更新多条数据(filter 可能返回多条数据)
