2018/ 5 ��  visual studio 2017�� ���� �ۼ��� �Ͽ���. 

������ ���� �ڷᱸ�� å�� ���� C ���α׷����� ���� ������ �Ͽ���. 

1.foundation �� ��ü �ַ�� �����̴�. 

�� ������Ʈ���� ������ ���� 
	Interface ��			������� 
	Implementation ��		c����
	Application ��			c���� 
�� �����Ǿ�������, 
������Ʈ ���Ͼȿ� ����ߴ� �ҽ����ϵ��� ���� �־����. 

  �� �Ϻδ� ������ �Ͽ����Ƿ� �ּ��� �����ذ��� ������ �غ����Ѵ�.  
	����, �� ������Ʈ���� ���� ������ϰ� �ҽ������� ���� ��� �̸��� ���� �Լ��� ������ ������ �������� �����߹Ƿ� �����϶�! 

reference
 
	Main �ҽ����Ͽ��� �ַ� 
	#if 0 or 1
	#elif
	#else
	#endif
	��ó�� ������ Ȱ���Ͽ� �ۼ��Ͽ���.  

[GuildLIne �� arrangement for each project]


�� Visual studio 2017 �� ����ϱ� ������ ���� ������ �ڵ带 ����ϸ� �߻��ϴ� ���װ� �ִ�. strcpy ���� ������ �Ҷ� 
strcpy_s�� �̿��ؾ��Ѵ�. 

e.g)

Person * MakePersonData(int ssn, char * name, char * addr)
{
	Person * newP = (Person*)malloc(sizeof(Person));

	newP->ssn = ssn;
	strcpy_s(newP->name, strlen(name)+1, name);
	strcpy_s(newP->addr, strlen(addr)+1, addr);
	return newP;
}