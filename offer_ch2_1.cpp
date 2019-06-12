#include <iostream>

using namespace std;

class CMyString
{
  public:
    CMyString(char *pData = nullptr);
    CMyString(const CMyString &str);
    ~CMyString(void);

    CMyString(char *pData)
    {
        if (pData == nullptr)
        {
            m_pData = new char[1];
            m_pData[0] = '\0';
        }
        else
        {
            m_pData = new char[strlen(pData) + 1];
            strcpy(m_pData, pData);
        }
    }
    CMyString(const CMyString &str)
    {
        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);
    }

    ~CMyString()
    {
        if (m_pData != nullptr)
            delete[] m_pData;
    }

    CMyString &operator=(const CMyString &str)
    {
        //普通版本
        if (this != &str)
        {
            delete[] m_pData;
            m_pData = nullptr;
            m_pData = new char[strlen(str.m_pData) + 1]; //strlen 不计入空字符
            strcpy(m_pData, str.m_pData);                //strcpy复制空字符
        }
        //异常安全版本
        if (this != nullptr)
        {
            CMyString tmp(str);       //复制构造函数
            char *pTmp = tmp.m_pData; //临时变量 指向str.pData
            tmp.m_pData = m_pData;    //自动析构局部变量同时释放原油m_pData空间
            m_pData = pTmp;           //指向str.pData
        }
        return *this;
    }

  private:
    char *m_pData;
};