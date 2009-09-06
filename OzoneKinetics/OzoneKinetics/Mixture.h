#ifndef MIXTURE_H
#define MIXTURE_H

#include <string>
#include "ThermDataVar.h"
#include "ReactionDataVar.h"
#include "Elements.h"

#define Rgas 8.31434
#define Rgas_ext 8314.34
#define Na 6.022045E23

class Mixture
{
public:
    char ErrorBuffer[250];
    /**
     * ������ ���� � ����������.
     * 
     * @param fileName ��� ����� � ����������
     */
	int readFileOfSubstances(const char *fileName);
    /**
     * ������ ���� � ���������.
     *
     * @param fileName ��� ����� � ���������
     */
	int readFileOfReactions(const char *fileName);
    /**
     * ����������� ������.
     */
	Mixture();
    /**
     * ���������� ������.
     */
	virtual ~Mixture();
    /**
     * ���������� ������� � �����.
     */
	int nSpecies;
    /**
     * ���������� �������.
     */
	int nReactions;
    /**
     * ����������������� ������ ��� ������� �� �������.
     */
	ThermDataVar *thermDatVar;
	double *Gibbs_Ef;
	double *MU;
	double *H0;
    /**
     * �������� �������.
     */
    std::string *namesOfSubstances;
	Elements *Atom;
	ReactionDataVar *reactionsDatVar;
    /**
     * ��� ����� ������.
     */
	char *nameOfFileOfErrors;
};

#endif