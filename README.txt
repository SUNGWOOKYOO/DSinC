2018/ 5 월  visual studio 2017을 통해 작성을 하였다. 

윤성우 열혈 자료구조 책에 대해 C 프로그래밍을 통한 구현을 하였다. 

1.foundation 이 전체 솔루션 파일이다. 

각 프로젝트마다 주제에 대해 
	Interface 부			헤더파일 
	Implementation 부		c파일
	Application 부			c파일 
로 구성되어있으며, 
프로젝트 파일안에 사용했던 소스파일들을 각각 넣어놨다. 

  ※ 일부는 변형을 하였으므로 주석을 변경해가며 컴파일 해봐야한다.  
	또한, 각 프로젝트에서 여러 헤더파일과 소스파일이 있을 경우 이름이 같은 함수나 변수가 있으면 컴파일이 에러뜨므로 주의하라! 

reference
 
	Main 소스파일에서 주로 
	#if 0 or 1
	#elif
	#else
	#endif
	전처리 구문을 활용하여 작성하였다.  

[GuildLIne 및 arrangement for each project]


※ Visual studio 2017 을 사용하기 때문에 이전 버전의 코드를 사용하면 발생하는 버그가 있다. strcpy 같은 연산을 할때 
strcpy_s를 이용해야한다. 

e.g)

Person * MakePersonData(int ssn, char * name, char * addr)
{
	Person * newP = (Person*)malloc(sizeof(Person));

	newP->ssn = ssn;
	strcpy_s(newP->name, strlen(name)+1, name);
	strcpy_s(newP->addr, strlen(addr)+1, addr);
	return newP;
}