-------------------
stat				|
------------------

int stat (const char *path, struct stat *);
	* ��ȡ�ļ�������,�ɹ�����0,ʧ�ܷ���-1
	* path �ļ���·��,stat ����״̬�Ľṹ��
	* �ṹ��Ķ���
		{ _dev_t	st_dev; 	/* Equivalent to drive number 0=A 1=B ... */ 
		  _ino_t	st_ino; 	/* Always zero ? */			   
		  _mode_t	st_mode;	/* See above constants */		     
		   short 	st_nlink;	/* Number of links. */			     
		   short 	st_uid; 	/* User: Maybe significant on NT ? */	     
		   short 	st_gid; 	/* Group: Ditto */			    
		  _dev_t	st_rdev;	/* Seems useless (not even filled in) */    
		  __st_off_t	st_size;	/* File size in bytes */		    
		  __st_time_t	st_atime;	/* Access time (always 00:00 on FAT) */	    
		  __st_time_t	st_mtime;	/* Modified time */			    
		  __st_time_t	st_ctime;	/* Creation time */			    
		}
		

