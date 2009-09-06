#ifndef THERM_DATA_VAR_H
#define THERM_DATA_VAR_H

class ThermDataVar  
{
public:
	/**
     * �������� ������ � ���� ��� ������� �����������.
     *
     * @return ������ ���������� ����.
     */
    int AllocateMemoryForTemperatureRange();
    /**
     * ����������� ������.
     */
	ThermDataVar();
    /**
     * ���������� ������.
     */
	virtual ~ThermDataVar();
	/**
     * ���������� ������������� ����������.
     */
    int n;
    /**
     * ������ ������ �����������.
     */
	double *Tlow;
    /**
     * ������� ������ �����������.
     */
	double *Tup;
    /**
     * ����� ������������� ��� ������� ��������.
     */
	double **a;
};

#endif
