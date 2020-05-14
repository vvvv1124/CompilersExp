#pragma once
#include "Scanner.h"
#include "token.h"

static struct
{
	string str;
	LexType tok;
} reservedWords[21]
= { {"program",PROGRAM},{"type",TYPE},{"var",VAR},{"procedure",PROCEDURE}
   ,{"begin",BEGIN},{"end",END},{"array",ARRAY},{"of",OF},{"record",RECORD}
   ,{"if",IF},{"then",THEN},{"else",ELSE},{"fi",FI},{"while",WHILE}
   ,{"do",DO},{"endwh",ENDWH},{"read",READ},{"write",WRITE},{"return",RETURN}
   ,{"integer",INTEGER},{"char",CHAR} };


typedef enum
{
	START, INASSIGN, INRANGE, INCOMMENT, INNUM, INID, INCHAR, DONE
}
StateType;


class TokenScanner :
	public Scanner
{
public:
	Token* Scan(FILE* f);
	LexType ReservedLookup(string str);			//�ж����Ƿ�Ϊ������
	//void AddIdentifier(string str);//�������û�н��ñ�ʶ���������
	//void AddConstant(string str);
	//bool Isother(char a);//�ж��Ƿ�Ϊ��ĸ����������������
	//bool Isletter(char a);
	//bool Isnumber(char a);

	int Line = 1;
	//��ʶ�����ͳ����������ڱ���һ����������б�ʶ���ͳ���
	vector<string> identifier;
	vector<string> constant;
	bool Error = false;
};
