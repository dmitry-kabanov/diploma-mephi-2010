#ifndef ELEMENTS_H
#define ELEMENTS_H

class Elements  
{
public:
    /**
     * ����������� ������.
     */
	Elements();
    /**
     * ���������� ������.
     */
	virtual ~Elements();
    /**
     * ������ ���������� ��������� (C, O, H, N).
     */
	char ElementsList[100];
    /**
     * ���-�� ����������.
     */
	int nBeta[100];
    /**
     * ���������� ���������� ���������.
     */
	int N;
};

#endif
