
/***********************************************************************

Copyright 2017 quantOS-org

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at:

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

***********************************************************************/
/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company 
///@file CXML.h
///@brief��������XML�����йص���ӿ�
///@history 
///20051011            �������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CXML_H
#define CXML_H

//#include "CBaseObject.h"
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include "base/Logger.h"
using namespace std;
using namespace jzs;

///��ȫ���ַ���ָ����
class CStringPtr
{
private:
    const char *m_ptr;
public:
    CStringPtr(const char *ptr=NULL)
    {
        if (ptr!=NULL)
        {
            m_ptr=strdup(ptr);
        }
        else
        {
            m_ptr=NULL;
        }
    }
    CStringPtr(const CStringPtr &ptr)
    {
        if (ptr.m_ptr!=NULL)
        {
            m_ptr=strdup(ptr.m_ptr);
        }
        else
        {
            m_ptr=NULL;
        }
    }
    const CStringPtr & operator = (const CStringPtr &ptr)
    {
        if (m_ptr!=NULL)
        {
            free((void*)m_ptr);
        }
        if (ptr.m_ptr!=NULL)
        {
            m_ptr=strdup(ptr.m_ptr);
        }
        else
        {
            m_ptr=NULL;
        }
        return *this;
    }
    ~CStringPtr(void)
    {
        if (m_ptr!=NULL)
        {
            free((void*)m_ptr);
        }
    }
    const char *operator =(const char *ptr)
    {
        if (m_ptr!=NULL)
        {
            free((void*)m_ptr);
        }
        if (ptr==NULL)
        {
            m_ptr=NULL;
        }
        else
        {
            m_ptr=strdup(ptr);
        }
        return m_ptr;
    }
    operator const char *(void)
    {
        if (m_ptr==NULL)
        {
            return "";
        }
        return m_ptr;
    }
};

/////////////////////////////////////////////////////////////////////////
///CXMLProperty��һ��XML����е�һ�����ԣ������ƺ�ֵ��ɣ����ֻ�����ƣ�
///��valueΪNULL��������doctype�ȱ�ǣ���ʹ�õȺ����ָ�����ô�����ÿһ��
///��������Ϊ��һ��ֻ�����Ƶ����ԡ�δ������Ҫ����namespace�����
///@author    
///@version    2.0,20051011
/////////////////////////////////////////////////////////////////////////
class CXMLProperty//: public CBaseObject
{
public:
    ///���캯�������ó�ʼ�����ƺ�ֵ��������ڴ潫��ʹ���ⲿ������ڴ�
    ///@param    name    ����
    ///@param    value    ֵ
    CXMLProperty(const char *name=NULL, const char *value=NULL);
    
    ///�������������ͷ����ƺ�ֵ�Ŀռ�
    ~CXMLProperty(void);

    virtual int isA(const char *objectType);
    virtual const char *getType(void);
    //virtual void output(Logger *pLogger,int indent=0);
    
    ///����һ���Լ�
    ///@return    ���Ʋ������½ڵ�
    CXMLProperty *clone(void);

    ///��������
    ///@param    name    ����
    void setName(const char *name);
    
    ///����ֵ
    ///@param    value    ֵ
    void setValue(const char *value);
    
    ///�������
    ///@return    ����
    const char *getName(void);
    
    ///��û��ֵ
    ///@return    ֵ
    const char *getValue(void);
    
    ///������ļ��У����Զ����б�Ҫ���ַ�ת��
    ///@param    output    ָ�����ļ�
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int write(FILE *output);
    int write(char *output);
private:
    ///����
    CStringPtr m_name;
    
    ///ֵ
    CStringPtr m_value;
};

/////////////////////////////////////////////////////////////////////////
///CXMLPropertyList��һ�������б����ڴ洢һ��XML����е��������ԡ��ڱ�
///ʵ���У�û�м�������������⣬��Ϊ��������б��ͬʱӦ����DTD���������
///����У�������Щ�������У����������ǺϷ��ġ�δ����ʵ�ֿ���ͨ������
///���ֿ��ԺͲ����������������б�
///@author    
///@version    2.0,20051011
/////////////////////////////////////////////////////////////////////////
class CXMLPropertyList: public vector<CXMLProperty *>
{
public:
    ///���캯��������һ���յ������б�
    CXMLPropertyList(void);
    
    ///�����������ͷű���Ŀռ�Ͱ���������CXMLProperty
    virtual ~CXMLPropertyList(void);

    virtual int isA(const char *objectType);
    virtual const char *getType(void);
    //virtual void output(Logger *pLogger,int indent=0);

    ///����һ���Լ�
    ///@return    ���Ʋ������½ڵ�
    CXMLPropertyList *clone(void);

    ///����һ������
    ///@param    name    ����
    ///@param    value    ֵ
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int addProperty(const char *name, const char *value);
    
    ///����һ������
    ///@param    name    ����
    ///@param    value    ֵ
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int addProperty(const char *name, int value);

    ///�ҵ�ĳ�����Զ�Ӧ�ı�ţ�����ж�����Զ���������ƣ����ҵ���һ��
    ///@param    name    ��������
    ///@return    ��Ӧ�ı�ţ����û���ҵ����򷵻�-1
    int findID(const char *name);

    ///ɾ��һ��ָ�����Ƶ����ԣ�����ж�����Զ���������ƣ���ɾ����һ��
    ///@param    name    ����
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int removeProperty(const char *name);
    
    ///�滻һ��ָ�����Ƶ����Ե�ֵ������ж�����Զ���������ƣ����滻��һ��
    ///@param    name    ����
    ///@param    newValue    �µ�ֵ
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int replaceProperty(const char *name, const char *newValue);
    
    ///�������ƣ�Ѱ��һ�����ԣ�����ж�����Զ���������ƣ���ֻ�ҵ�һ��
    ///@param    name    ����
    ///@return    �ҵ�������
    CXMLProperty *findProperty(const char *name);
    
    ///�������ƣ�Ѱ��һ�����Ե�ֵ������ж�����Զ���������ƣ���ֻ�ҵ�һ��
    ///@param    name    ����
    ///@return    �ҵ�������ֵ��û�и����ԣ��򷵻�NULL�����������û��ֵ���򷵻�""
    const char *findValue(const char *name);
    
    ///������ļ��У�ÿ������ǰ��һ���ո�
    ///@param    output    ָ�����ļ�
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int write(FILE *output);
    int write(char *output);
};

/////////////////////////////////////////////////////////////////////////
///XMLElementType��һ��XMLԪ�����͵�ö��ֵ����
///@author    
///@version    2.0,20051011
/////////////////////////////////////////////////////////////////////////
typedef enum
{
    XMLNotElement,            ///����XMLԪ��
    XMLStartElement,        ///��ʼԪ�أ�����<user ...>
    XMLEndElement,            ///����Ԫ�أ�����</user>
    XMLSingleElement,        ///����Ԫ�أ�����<user/>
    XMLTextElement,            ///����Ԫ�أ�����Hello world
    XMLCommentElement,        ///ע��Ԫ�أ�����<!-- This is comment -->
    XMLDocumentElement,        ///�ĵ�˵��Ԫ�أ�����<?xml ... ?>
    XMLPIElement,            ///��������Ԫ�أ�����<?mypi ... ?>
    XMLDTDElement            ///˵���ĵ����͵�Ԫ�أ�����<!DOCTYPE ...>
}    XMLElementType;

/////////////////////////////////////////////////////////////////////////
///CXMLElement��һ��XMLԪ�����ͣ������Ͷ�Ӧ��һ��XML�ĵ��еĿ�ʼԪ�ء�����
///Ԫ�ء�����Ԫ�ء�����Ԫ�ء�ע��Ԫ�صȣ���XML�ļ��е�һ���������֡�������
///�������ڶ�XML�ļ����ж�ȡʱ����Ϊ�м�Ԫ�ء������Ĳ���Ӧ��ʹ��CXMLNode
///@author    
///@version    2.0,20051011
/////////////////////////////////////////////////////////////////////////
class CXMLElement//: public CBaseObject
{
public:
    ///���캯��������һ���յ�XMLԪ��
    CXMLElement(void);

    ///�������������ͷ������б�ռ�    
    ~CXMLElement(void);

    ///ɾ�������б�ռ�
    void removePropertyList(void);
    
    virtual int isA(const char *objectType);
    virtual const char *getType(void);
    //virtual void output(Logger *pLogger,int indent=0);

    ///��ȡԪ������
    ///@return    Ԫ������
    XMLElementType getElementType(void);
    
    ///����Ԫ������
    ///@param    type    Ԫ������
    void setElementType(XMLElementType type);
    
    ///��ȡԪ�����ƣ��������֣������������ģ�����ע�ͣ�����ע������
    ///@return    Ԫ������
    const char *getName(void);
    
    ///����Ԫ������
    ///@param    name    Ԫ������
    void setName(const char *name);
    
    ///��������б�
    ///@return    �����б�
    CXMLPropertyList *getPropertyList(void);
    
    ///���������б�
    ///@param    propertyList    �����б�
    void setPropertyList(CXMLPropertyList *propertyList);
    
    ///��������
    ///@param    name    ��������
    ///@param    value    ����ֵ
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int addProperty(const char *name, const char *value);
    
    ///ɾ�����ԣ�����ж�����Զ���������ƣ���ɾ����һ��
    ///@param    name    ��������
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int removeProperty(const char *name);
    
    ///�滻���ԣ�����ж�����Զ���������ƣ����滻��һ��
    ///@param    name    ��������
    ///@param    newValue    �µ�����ֵ
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int replaceProperty(const char *name, const char *newValue);

    ///Ѱ�����ԣ�����ж�����Զ���������ƣ���ֻ�ҵ�һ��
    ///@param    name    ��������
    ///@return    �ҵ�������ֵ��û�и����ԣ��򷵻�NULL�����������û��ֵ���򷵻�""
    const char *findProperty(const char *name);

    ///������ļ��У����ݸ�Ԫ�صĹ涨��ʽд��
    ///@param    output    ָ�����ļ�
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int write(FILE *output);
    int write(char *output);
private:
    ///XMLԪ������
    XMLElementType m_type;
    
    ///Ԫ������
    CStringPtr m_name;
    
    ///�����б�
    CXMLPropertyList *m_propertyList;
};

/////////////////////////////////////////////////////////////////////////
///XMLNodeType��һ��XML���еĽڵ������ö��ֵ
///@author    
///@version    2.0,20051011
/////////////////////////////////////////////////////////////////////////
typedef enum 
{
    XMLNotNode,            ///����XML�ڵ�
    XMLTag,                ///XML�ı�ǣ��ӿ�ʼԪ�ص�����Ԫ�أ������ǵ���Ԫ��
    XMLText,            ///XML���֣���һ����������Ԫ��
    XMLComment            ///XMLע��
}    XMLNodeType;

class CXMLNode;

/////////////////////////////////////////////////////////////////////////
///CXMLNodeList��һ��XML�ڵ�����У����ڴ洢һ��XML�ڵ��µ������ӽڵ�
///@author    
///@version    2.0,20051011
/////////////////////////////////////////////////////////////////////////
class CXMLNodeList: public vector<CXMLNode *>
{
public:
    ///���캯��������һ���յ�����
    CXMLNodeList(void);
    
    ///��������
    virtual ~CXMLNodeList(void);

    virtual int isA(const char *objectType);
    virtual const char *getType(void);
    //virtual void output(Logger *pLogger,int indent=0);

    ///����һ���Լ�
    ///@return    ���Ʋ������½ڵ�
    CXMLNodeList *clone(void);

    ///Ѱ�ҵ�һ�����������Ľڵ�
    ///@param    type    ҪѰ�ҵı�����ͣ�XMLNotNode��ʾ��ȷ���������
    ///@param    tagName    ҪѰ�ҵı�����ƣ�NULL��ʾ��ȷ���ı������
    ///@param    propertyName    ҪѰ�ҵı�Ǳ���������������ƣ�NULL��ʾ����Ҫ���������
    ///@param    propertyValue    ҪѰ�ҵı�Ǳ������������ֵ��NULL��ʾ����Ҫ�������ֵ����propertyNameΪNULLʱ���˲���������
    ///@return    �ҵ��Ľڵ㣬�Ҳ����򷵻�NULL
    CXMLNode *findNode(XMLNodeType type, const char *tagName, const char *propertyName=NULL, const char *propertyValue=NULL);
    
    ///Ѱ��һ��ָ���Ľڵ�
    ///@param    pNode    ҪѰ�ҵĽڵ�
    ///@return    �ýڵ���±�λ�ã��Ҳ����򷵻�-1
    int findNode(CXMLNode *pNode);

    ///������ļ��У��������еĽڵ�
    ///@param    output    ָ�����ļ�
    ///@param    indent    ������
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int write(FILE *output, int indent=0);
    int write(char *output, int indent=0);
};

///XML�����������Ͷ��壬0��ʾ��Ҫ��������������ֵ��ʾ��������
typedef int (* TXMLActionFunc)(CXMLNode * pNode, void * parameter);

///��XML������ֵ�������������Ͷ��壬0��ʾ��Ҫ��������������ֵ��ʾ��������
typedef int (* TXMLPropertyActionFunc)(const char *value, void *parameter);

/////////////////////////////////////////////////////////////////////////
///CXMLAction��һ��XML�����࣬��ʾ��һ��XML�ڵ�����ַ���Ӧ�����ú��ֲ���
///��ʽ������������ǹ�CXMLNode�е�XActionר�õġ�ʹ����Ӧ���̳�����࣬
///��д��Ҫ�ķ�����Ȼ������ΪXAction�Ĳ���
///@author    
///@version    2.0,20051226
/////////////////////////////////////////////////////////////////////////
class CXMLAction
{
public:
    ///��������
    virtual ~CXMLAction(void)
    {
    }
    
    ///�ڵ㴦�����
    ///@param    pNode    Ҫ����Ľڵ�
    ///@return    0��ʾ��Ҫ����������>0��ʾ��������
    virtual int nodeHandler(CXMLNode *pNode);

    ///�ַ����������
    ///@param    string    Ҫ������ַ���
    ///@return    0��ʾ��Ҫ����������>0��ʾ��������
    virtual int stringHandler(const char *string);
};

/*
��������չXPATH�Ķ��壬��չXPATH(���³�EXPATH)����ָ����XML�ļ���ָ���ڵ��µ�
�����ض�Ҫ���һ��ڵ㣬����һ���ַ���
���﷨���£����е�()[]*|+ΪԪ�ַ��������������յ���չXPATH�ϣ�����\Ϊת���ַ���
�����Ԫ�ַ�Ӧ�����Ϊԭ�����ַ���

EXPATH=(EXNODE)*[STRING_VALUE]
EXNODE=(/|/\(NUMBER\)|//)(TAG_NAME|\*)(,CONDITION)*
CONDITION=STRING_REF[=RESULT]
STRING_VALUE=/STRING_REF(,STRING_REF)*
STRING_REF=(@PROPERTY_NAME|?TEXT_TAG_NAME)

����EXPATH���������£�
1 EXPATH
EXPATH˵����Ҫָ��������Ŀ�꣬����ʹ�����ɸ�EXNODE���ֲ�ε�ָ����ĳЩ�ڵ��ϣ�
��ЩEXNODE���д���ģ������ȴ�ָ���ڵ㣬���յ�һ��EXNODE���ҳ����ɽڵ㣬�ٷֱ�
����Щ�ڵ�Ϊָ���ڵ㣬���յڶ���EXNODE���ҵ����ɽڵ㣬�Դ����ơ��������û��
PROPERTY_VALUE����TEXT_TAG_VALUE����EXPATH��Ӧ���ǰ���������ʽ�ҵ���һ��ڵ㡣
���������STRING_VALUE��������Ҫ�󣬽��ҵ�һ���ַ�����
2 EXNODE
EXNODE˵������δ�ָ���ڵ㰴��һ���������ҵ�һ��ڵ㡣�俪ͷΪ/��/(NUMBER)����//��
�����/��ʾ��ָ���ڵ�������ӽڵ���Ѱ�ң�/(NUMBER)��ʾ��NUMBER������ڵ���Ѱ�ң�
Ҳ����˵��/ʵ���Ͼ���/(1)�ļ���ʽ��//��ʾ��ָ���ڵ����������ڵ���Ѱ�ҡ������
˵��Ѱ�ҷ�Χ�ı�ʶ�����Ƕ�TagName��˵��������ֱ��ָ��һ��TAG_NAME��Ҳ������*��ʾ
�����TagName����������ɸ�����CONDITION��������󣩡�ͬʱ����ǰ����Ҫ�󣬲�����
����CONDITION�Ľڵ㣬�������������Ľڵ㡣ע�⣬���ʹ����//��ĳ�����������Ľڵ�
�������ӽڵ㽫��������Ѱ�ҷ�Χ�С�
3 CONDITION
CONDITION˵���˶Խڵ��һ��������˵�������ķ�ʽ�����֣�һ��������������һ�����ı�
������������������ʽ��@PROPERTY_NAME=RESULT����ָ������������Ӧ��ֵ��RESULT��Ҳ����
��ָ���������ôֻҪָ�����Դ��ڼ��ɡ���һ�����ı���������ʽΪ?TEXT_TAG_NAME=RESULT��
��ʾ�ýڵ���ָ���ӽڵ���ı�����ΪRESULT��Ҳ���Բ�ָ���������ôֻҪ��ָ���ӽڵ㼴�ɡ�
����ڵ��е��ı���ָĳ���ڵ㣬�����Ʒ���ָ��Ҫ�����ӽڵ�ֻ��һ����������һ��
XMLTEXT����ô�ı�ָ���ı�������
4 STRING_VALUE
STRING_VALUE����ָ��ĳ���ڵ��е�ָ���ַ����������ɶ��ŷָ�����ɸ�STRING_REF��ɣ�
ÿ��STRING_REF����ָ��ĳ���ַ��������ǰ��һ��û�ж��壬��ô��Ѱ�Һ���һ�������
ǰ��һ���ж����ˣ�����ľͲ����ˡ�����ӵ�һ���ҵ����һ�������е�STRING_REF��
û�ж��壬�򱨴�
5 STRING_REF
STRING_REF����ָ��ĳ���ڵ��һ���ַ�����ָ���ַ����ķ�ʽ�����֣�һ����@PROPERTY_NAME��
��ʾָ��������ֵ����һ����@TEXT_TAG_NAEM����ʾָ�����ӽڵ��ı����ݡ�

��������������ӣ�
1 /user,@gendar=male/@name
  �ҵ��������û�������
2 /user/address,?street/?street
  �ҵ������û��ĵ�ַ�п��ܴ��ڵĽֵ���
3 /(2)search/parameters/parameter/@name
  �������������м����Ĳ�����
4 // *,@type=boolean/@name,@originalName
  Ѱ����������ڵ�������Ϊboolean�Ľڵ����ƣ��������û�ж��壬��ʹ��origianlName����
  ��ע�⣺����//��*��Ӧ����û�пո�ģ�
*/

class CEXPathNode;

/////////////////////////////////////////////////////////////////////////
///CXMLNode��һ��XML�ڵ��࣬һ��XML�ڵ���ָXML�ļ�ת��Ϊ���Ժ���м�ĳ��
///�ڵ㣬����ڵ�����Ǳ�ǣ�Ҳ���������Ļ���ע�͡�ÿ���ڵ㶼���Լ�������
///���ҿ��ܰ�����һ�����е��ӽڵ�
///@author    
///@version    2.0,20051011
/////////////////////////////////////////////////////////////////////////
class CXMLNode//: public CBaseObject
{
public:
    ///���캯��
    CXMLNode(void);
    
    ///������������ݹ��������е��ӽڵ㣬���������б�����ԣ����ǲ����ͷ��ַ����ռ�
    virtual ~CXMLNode(void);
    
    virtual int isA(const char *objectType);
    virtual const char *getType(void);
    //virtual void output(Logger *pLogger,int indent=0);

    ///����һ���Լ�
    ///@param    includeSon    �Ƿ�Ҫͬʱ�����ӽڵ�
    ///@return    ���Ʋ������½ڵ�
    CXMLNode *clone(bool includeSon=false);

    ///��ȡ�ڵ�����
    ///@return    �ڵ�����
    XMLNodeType getNodeType(void);
    
    ///���ýڵ�����
    ///@param    type    �ڵ�����
    void setNodeType(XMLNodeType type);
    
    ///��ȡ�ڵ����ƣ����ڱ�ǣ��Ǳ�ǵ����ƣ��������ĺ�ע�ͣ��������ĺ�ע�͵�ȫ��
    ///@return    �ڵ�����
    const char *getName(void);
    
    ///���ýڵ�����
    ///@param    name    �ڵ�����
    void setName(const char *name);
    
    ///��ȡ�����б�
    ///@return    �����б�
    CXMLPropertyList *getPropertyList(void);
    
    ///���������б�
    ///@param    propertyList    �����б�
    void setPropertyList(CXMLPropertyList *propertyList);
    
    ///����һ������
    ///@param    name    ����
    ///@param    value    ֵ
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int addProperty(const char *name, const char *value);
    
    ///����һ������
    ///@param    name    ����
    ///@param    value    ֵ
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int addProperty(const char *name, int value);

    ///ɾ��һ�����ԣ�����ж�����Զ���������ƣ���ɾ����һ��
    ///@param    name    ��������
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int removeProperty(const char *name);
    
    ///�滻һ�����ԣ�����ж�����Զ���������ƣ����滻��һ��
    ///@param    name    ��������
    ///@param    newValue    ����ֵ
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int replaceProperty(const char *name, const char *newValue);
    
    ///Ѱ��һ�����ԣ�����ж�����Զ���������ƣ���ֻ�ҵ�һ��
    ///@param    name    ��������
    ///@return    ����ֵ�����û�и����ԣ���ΪNULL�����û����������ֵ����Ϊ""
    const char *findProperty(const char *name);
    
    ///����һ�����ԣ����ԭ����������ԣ����滻������ԣ�����������������
    ///@param    name    ��������
    ///@param    value    ����ֵ
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int setProperty(const char *name, const char *value);
    
    ///��ȡ�ӽڵ�����
    ///@return    �ӽڵ�����
    CXMLNodeList *getNodeList(void);
    
    ///�����ӽڵ�����
    ///@param    nodeList    �ӽڵ�����
    void setNodeList(CXMLNodeList *nodeList);

    ///����һ���ӽڵ�
    ///@param    pNode    Ҫ���ӵ��ӽڵ�
    void addNode(CXMLNode *pNode);
    CXMLNode *addNode(const char *pNodeName,const char *pNodeValue);
    
    ///��ȡ���ڵ�
    ///@return    �õ��ĸ��ڵ㣬���û�и��ڵ㣬�򷵻�NULL
    CXMLNode *getFather(void);
    
    ///��ȡ�ӽڵ�
    ///@param    offset    ���λ�ã�>0��ʾ���<0��ʾ��ǰ��0��ʾ��ǰ
    ///@param    from    ��ʼѰ�ҵ�λ�ã�SEEK_END��ʾ���һ���ڵ㣬SEEK_SET��ʾ��һ���ڵ�
    ///@param    �õ����ӽڵ㣬���û������ӽڵ㣬�򷵻�NULL
    CXMLNode *getSon(int offset, int from=SEEK_SET);
    
    ///��ȡ�ֵܽڵ�
    ///@param    offset    ���λ�ã�>0��ʾ���<0��ʾ��ǰ��0��ʾ��ǰ
    ///@param    from    ��ʼѰ�ҵ�λ�ã�SEEK_CUR��ʾ��ǰ�ڵ㣬SEEK_END��ʾ���һ���ڵ㣬SEEK_SET��ʾ��һ���ڵ�
    ///@param    �õ����ֵܽڵ㣬���û������ֵܽڵ㣬�򷵻�NULL
    CXMLNode *getBrother(int offset=1, int from=SEEK_CUR);
    
    ///Ѱ�ҵ�һ�����������Ľڵ�
    ///@param    type    ҪѰ�ҵı�����ͣ�XMLNotNode��ʾ��ȷ���������
    ///@param    tagName    ҪѰ�ҵı�����ƣ�NULL��ʾ��ȷ���ı������
    ///@param    propertyName    ҪѰ�ҵı�Ǳ���������������ƣ�NULL��ʾ����Ҫ���������
    ///@param    propertyValue    ҪѰ�ҵı�Ǳ������������ֵ��NULL��ʾ����Ҫ�������ֵ����propertyNameΪNULLʱ���˲���������
    ///@return    �ҵ��Ľڵ㣬�Ҳ����򷵻�NULL
    CXMLNode *findNode(XMLNodeType type, const char *tagName, const char *propertyName=NULL, const char *propertyValue=NULL);

    ///ȷ��һ���ڵ��Ƿ��������
    ///@param    type    Ҫȷ�ϵı�����ͣ�XMLNotNode��ʾ��ȷ���������
    ///@param    tagName    Ҫȷ�ϵı�����ƣ�NULL��ʾ��ȷ���ı������
    ///@param    propertyName    Ҫȷ�ϵı�Ǳ���������������ƣ�NULL��ʾ����Ҫ���������
    ///@param    propertyValue    Ҫȷ�ϵı�Ǳ������������ֵ��NULL��ʾ����Ҫ�������ֵ����propertyNameΪNULLʱ���˲���������
    ///@return    1��ʾ����,0��ʾ������
    int validNode(XMLNodeType type, const char *tagName, const char *propertyName=NULL, const char *propertyValue=NULL);
    
    ///������ļ��У������ýڵ��Լ����е��ӽڵ�
    ///@param    output    ָ�����ļ�
    ///@param    indent    ������
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int write(FILE *output, int indent=0);
    int write(char *output, int indent=0);

    ///�������ӽڵ����һ��ָ���Ĳ���
    ///@param    pFunc    ��������
    ///@param    parameter    ���������Ĳ���
    ///@param    type    ҪѰ�ҵı�����ͣ�XMLNotNode��ʾ��ȷ���������
    ///@param    tagName    ҪѰ�ҵı�����ƣ�NULL��ʾ��ȷ���ı������
    ///@param    propertyName    ҪѰ�ҵı�Ǳ���������������ƣ�NULL��ʾ����Ҫ���������
    ///@param    propertyValue    ҪѰ�ҵı�Ǳ������������ֵ��NULL��ʾ����Ҫ�������ֵ����propertyNameΪNULLʱ���˲���������
    ///@return    0��ʾ���������������жϣ�����ֵ��ʾ���һ�ν��ò�������ʱ�ķ���ֵ��-1��ʾû�пɲ����Ķ���
    int groupAction(TXMLActionFunc pFunc, void *parameter=NULL,
        XMLNodeType type=XMLTag, const char *tagName=NULL, 
        const char *propertyName=NULL, const char *propertyValue=NULL);

    ///�������ӽڵ��ָ�����Խ���һ��ָ���Ĳ���
    ///@param    usePropertyName    ָ����������
    ///@param    pFunc    ��������
    ///@param    parameter    ���������Ĳ���
    ///@param    type    ҪѰ�ҵı�����ͣ�XMLNotNode��ʾ��ȷ���������
    ///@param    tagName    ҪѰ�ҵı�����ƣ�NULL��ʾ��ȷ���ı������
    ///@param    propertyName    ҪѰ�ҵı�Ǳ���������������ƣ�NULL��ʾ����Ҫ���������
    ///@param    propertyValue    ҪѰ�ҵı�Ǳ������������ֵ��NULL��ʾ����Ҫ�������ֵ����propertyNameΪNULLʱ���˲���������
    ///@return    0��ʾ���������������жϣ�����ֵ��ʾ���һ�ν��ò�������ʱ�ķ���ֵ��-1��ʾû�пɲ����Ķ���
    int groupAction(const char *usePropertyName, TXMLPropertyActionFunc pFunc, void *parameter=NULL,
        XMLNodeType type=XMLTag, const char *tagName=NULL, 
        const char *propertyName=NULL, const char *propertyValue=NULL);

    ///������չXPATH�������нڵ������ָ�����ԣ�����ָ��������ض�����
    ///@param    EXPath    ָ������չXPATH�����﷨������������ϸ����
    ///@param    pAction    ����ָ�������Ķ���
    ///@return    0��ʾ�������жϣ�����ֵ��ʾ���һ�ν��ò�������ʱ�ķ���ֵ��-1��ʾû�пɲ����Ķ���,-2��ʾ�﷨����,-3��ʾ��ȡ��ֵû�ж���
    int XAction(const char *EXPath, CXMLAction *pAction);
    
protected:
    ///XML�ڵ�����
    XMLNodeType m_type;
    
    ///�ڵ�����
    CStringPtr m_name;
    
    ///�����б�
    CXMLPropertyList *m_propertyList;
    
    ///�ӽڵ�����
    CXMLNodeList *m_nodeList;
    
    ///���ڵ�
    CXMLNode *m_father;

    int EXNodeAction(CXMLNode *pEXNode, CXMLAction *pAction);


    ///���ַ������в�������XAction��ʹ�õ��ڲ�����
    ///@param    pPath    ָ������չXPathƬ�Σ�û��EXNODE���֣�ͷ�ϵ�/�Ѿ�ȥ��
    ///@param    pAction    ����ָ�������Ķ���
    ///@return    ���ؽ������XAction�Ķ���
    int stringRefAction(const char *pPath,CXMLAction *pAction);
    
    ///�Խڵ���м�飬��XAction��ʹ�õ��ڲ�����
    ///@param    pPath    ָ������չXPathƬ�Σ�ͷ�ϵķ�Χָ���Ѿ�ȥ��
    ///@param    pAction    ����ָ�������Ķ���
    ///@param    depth    Ҫ���Ľڵ����ȣ�0��ʾ����<0��ʾ��������ڵ�
    ///@return    ���ؽ������XAction�Ķ���
    int nodeCheck(const char *pPath,CXMLAction *pAction, int depth);

    ///��鱾�ڵ��Ƿ�����Ҫ����XAction��ʹ�õ��ڲ�����
    ///@param    pPath    ָ������չXPath��Ƭ�Σ�ͷ�ϵķ�Χָ���Ѿ�ȥ��
    ///@param    pathTail    ���ص�ָ�������XPath��һ���ַ���ֻ�е�����ֵΪ1����*pIsMatch=1ʱ�᷵��
    ///@param    pIsMatch    �����Ƿ���ϣ�1��ʾ���ϣ�0��ʾ�����ϣ�ֻ�е�����ֵΪ1ʱ�᷵��
    ///@return    ���ؽ������XAction�Ķ��壬1��ʾ��������
    int matchNode(const char *pPath, const char **pathTail, int *pIsMatch);
    
    ///��ȡһ���ַ������õ�ֵ����XAction��ʹ�õ��ڲ�����
    ///@param    pPath    ָ������չXPath��Ƭ�Σ�Ӧ��ָ��һ��@����?
    ///@param    pathTail    ���ص�ָ�������XPath��һ���ַ���ֻ�е�����ֵΪ1ʱ�᷵��
    ///@param    pStringValue    ���ص��ַ���ֵ��NULL��ʾû��ȡ��ֵ��ֻ�е�����ֵΪ1ʱ�᷵��
    ///@return    ���ؽ������XAction�Ķ���(����-3)��1��ʾ��������
    int getStringValue(const char *pPath, const char **pathTail, const char **pStringValue);

    ///��ȡ��չXPATH�е�һ��token����XAction��ʹ�õ��ڲ�����
    ///@param    pPath    ָ������չXPathƬ�Σ�Ӧ��ָ��һ��token�Ŀ�ʼλ��
    ///@param    pathTail    ����ȡ������һ���ַ�
    ///@return    ����ȡ����token��������ռ䣬���÷������ͷ�
    const char *getToken(const char *pPath, const char **pathTail);
};

///XMLȺ���������һ���ڵ�������ӽڵ����һ��ָ���Ĳ���
///@param    pNode    ָ���Ľڵ�
///@param    pFunc    ��������
///@param    parameter    ���������Ĳ���
///@param    type    ҪѰ�ҵı�����ͣ�XMLNotNode��ʾ��ȷ���������
///@param    tagName    ҪѰ�ҵı�����ƣ�NULL��ʾ��ȷ���ı������
///@param    propertyName    ҪѰ�ҵı�Ǳ���������������ƣ�NULL��ʾ����Ҫ���������
///@param    propertyValue    ҪѰ�ҵı�Ǳ������������ֵ��NULL��ʾ����Ҫ�������ֵ����propertyNameΪNULLʱ���˲���������
///@return    0��ʾ���������������жϣ�����ֵ��ʾ���һ�ν��ò�������ʱ�ķ���ֵ��-1��ʾû�пɲ����Ķ���
int XMLGroupAction(CXMLNode *pNode, TXMLActionFunc pFunc, void *parameter=NULL,
    XMLNodeType type=XMLTag, const char *tagName=NULL, 
    const char *propertyName=NULL, const char *propertyValue=NULL);

///XMLȺ���������һ���ڵ����н���һ��ָ���Ĳ���
///@param    pNodeList    ָ���Ľڵ�����
///@param    pFunc    ��������
///@param    parameter    ���������Ĳ���
///@param    type    ҪѰ�ҵı�����ͣ�XMLNotNode��ʾ��ȷ���������
///@param    tagName    ҪѰ�ҵı�����ƣ�NULL��ʾ��ȷ���ı������
///@param    propertyName    ҪѰ�ҵı�Ǳ���������������ƣ�NULL��ʾ����Ҫ���������
///@param    propertyValue    ҪѰ�ҵı�Ǳ������������ֵ��NULL��ʾ����Ҫ�������ֵ����propertyNameΪNULLʱ���˲���������
///@return    0��ʾ���������������жϣ�����ֵ��ʾ���һ�ν��ò�������ʱ�ķ���ֵ��-1��ʾû�пɲ����Ķ���
int XMLGroupAction(CXMLNodeList *pNodeList, TXMLActionFunc pFunc, void *parameter=NULL,
    XMLNodeType type=XMLTag, const char *tagName=NULL, 
    const char *propertyName=NULL, const char *propertyValue=NULL);

///XMLȺ���������һ���ڵ�������ӽڵ��ָ�����Խ���һ��ָ���Ĳ���
///@param    pNode    ָ���Ľڵ�
///@param    usePropertyName    ָ����������
///@param    pFunc    ��������
///@param    parameter    ���������Ĳ���
///@param    type    ҪѰ�ҵı�����ͣ�XMLNotNode��ʾ��ȷ���������
///@param    tagName    ҪѰ�ҵı�����ƣ�NULL��ʾ��ȷ���ı������
///@param    propertyName    ҪѰ�ҵı�Ǳ���������������ƣ�NULL��ʾ����Ҫ���������
///@param    propertyValue    ҪѰ�ҵı�Ǳ������������ֵ��NULL��ʾ����Ҫ�������ֵ����propertyNameΪNULLʱ���˲���������
///@return    0��ʾ���������������жϣ�����ֵ��ʾ���һ�ν��ò�������ʱ�ķ���ֵ��-1��ʾû�пɲ����Ķ���
int XMLGroupAction(CXMLNode *pNode, const char *usePropertyName, TXMLPropertyActionFunc pFunc, void *parameter=NULL,
    XMLNodeType type=XMLTag, const char *tagName=NULL, 
    const char *propertyName=NULL, const char *propertyValue=NULL);

///XMLȺ���������һ���ڵ����е�ָ�����Խ���һ��ָ���Ĳ���
///@param    pNodeList    ָ���Ľڵ�����
///@param    usePropertyName    ָ����������
///@param    pFunc    ��������
///@param    parameter    ���������Ĳ���
///@param    type    ҪѰ�ҵı�����ͣ�XMLNotNode��ʾ��ȷ���������
///@param    tagName    ҪѰ�ҵı�����ƣ�NULL��ʾ��ȷ���ı������
///@param    propertyName    ҪѰ�ҵı�Ǳ���������������ƣ�NULL��ʾ����Ҫ���������
///@param    propertyValue    ҪѰ�ҵı�Ǳ������������ֵ��NULL��ʾ����Ҫ�������ֵ����propertyNameΪNULLʱ���˲���������
///@return    0��ʾ���������������жϣ�����ֵ��ʾ���һ�ν��ò�������ʱ�ķ���ֵ��-1��ʾû�пɲ����Ķ���
int XMLGroupAction(CXMLNodeList *pNodeList, const char *usePropertyName, TXMLPropertyActionFunc pFunc, void *parameter=NULL,
    XMLNodeType type=XMLTag, const char *tagName=NULL, 
    const char *propertyName=NULL, const char *propertyValue=NULL);

/*
prepareEXPath�ǽ�����������EXPathת��Ϊһ��XML�ڵ㡣�ڽ�������ת��ʱ�����е�
EXPath�е���Ϣ����ΪCXMLNode�е���Ϣ��ת����Ľ���൱�ڰ�������DTD����ʽ��
<!ELEMENT EXPATH (EXNODE*,STRING_VALUE?)>
<!ELEMENT EXNODE (CONDITION*)>
<!ATTLIST EXNODE
    DEPTH CDATA #REQUIRED
    TAG_NAME CDATA #REQUIRED
>
<!ELEMENT CONDITION (STRING_REF)>
<!ATTLIST CONDITION
    RESULT CDATA #IMPLIED
>
<!ELEMENT STRING_REF EMPTY>
<!ATTLIST STRING_REF
    STRING_REF_TYPE CDATA #REQUIRED
    NAME CDATA #REQUIRED
>
<!ELEMENT STRING_VALUE (STRING_REF*)>    
*/
/////////////////////////////////////////////////////////////////////////
///CEXPathNode��һ����չXPATH��׼���࣬���ڽ�һ����չXPATHת��Ϊһ��XML
///�ڵ㣬ת���ķ�ʽ����
///@author    
///@version    1.0,20060101
/////////////////////////////////////////////////////////////////////////
class CEXPathNode: public CXMLNode
{
public:
    ///���캯��
    CEXPathNode(void);
    
    ///׼��һ����չXPATH
    ///@param    EXPath    Ҫ׼������չXPATH
    ///@return    1��ʾ�ɹ���-2��ʾ�﷨����
    int prepare(const char *EXPath);
    
    ///�ж��Ƿ��Ѿ������׼��
    ///@����    1��ʾ�Ѿ�׼����0��ʾû��׼��
    int isPrepared(void);
private:
    ///����һ��EXNODE��Ҳ���ܵõ�һ��STRING_VALUE
    ///@return    �õ��Ľڵ㣬����NULL��ʾʧ��
    CXMLNode *makeEXNode(void);

    ///����һ��STRING_VALUE
    ///@return    �õ��Ľڵ㣬����NULL��ʾʧ��
    CXMLNode *makeStringValue(void);

    ///����һ��STRING_REF
    ///@return    �õ��Ľڵ㣬����NULL��ʾʧ��
    CXMLNode *getStringRef(void);

    ///��ȡһ��token
    ///@return    �õ���token������NULL��ʾ��token�ǿյ�
    const char *getToken(void);

    const char *pPath;
    
    int prepared;
};

typedef void (*StartElement)(void *userData, const char *name, CXMLNode *node);

typedef void (*EndElement)(void *userData, const char *name);

typedef bool (*EndElement2)(void *userData, const char *name);

typedef struct _key {
    FILE *input;
    StartElement start;
    EndElement2 end;
    int ignoreText;
    int depth;
    bool shouldEnd;
} KEY;

/////////////////////////////////////////////////////////////////////////
///CXMLDoc��һ��XML�ĵ��࣬һ��XML�ĵ���ָ�е�һ���ڵ��Well Formed��XML
///�ĵ������ǣ����ڿ�ʼ��һЩָʾ�Ա�־������ʡ�ԡ�
///@author    
///@version    2.0,20051011
/////////////////////////////////////////////////////////////////////////
class CXMLDoc//: public CBaseObject
{
public:
    ///���캯��������һ���յ�XML�ĵ�
    CXMLDoc(void);
    
    ///�����������ͷű��ĵ������нڵ�
    ~CXMLDoc(void);
    
    virtual int isA(const char *objectType);
    virtual const char *getType(void);
    //virtual void output(Logger *pLogger,int indent=0);

    ///��ȡ���ڵ�
    ///@return    ���ڵ�
    CXMLNode *getRootNode(void);
    
    ///���ø��ڵ�
    ///@param    rootNode    ���ڵ�
    void setRootNode(CXMLNode *rootNode);
    
    ///��ȡ���뷽ʽ
    ///@return    ���뷽ʽ
    const char *getEncoding(void);
    
    ///���ñ��뷽ʽ
    ///@param    encoding    ���뷽ʽ
    void setEncoding(const char *encoding);
    
    ///��ȡ�汾
    ///@return    �汾
    const char *getVersion(void);
    
    ///���ð汾
    ///@param    version    �汾
    void setVersion(const char *version);
    
    ///��ȡ���ڵ����ƣ���DOCTYPE��ָ����
    ///@return    ���ڵ�����
    const char *getRoot(void);
    
    ///���ø��ڵ�����
    ///@param    root    ���ڵ�����
    void setRoot(const char *root);
    
    ///��ȡDOCTYPEָ����DTD�ļ���Ŀǰֻ֧��ָ���ⲿ�ļ������������ֱ����XML��Ƕ��DTD����
    ///@return    DTD�ļ���
    const char *getDoctype(void);
    
    ///����DTD�ļ�
    ///@param    doctype    DTD�ļ�
    void setDoctype(const char *doctype);
    
    ///���ļ��ж�ȡXML�ļ�
    ///@param    filename    �ļ���
    ///@param    ignoreText    1��ʾ�������е����ģ�0��ʾ����������
    ///@param    ignoreComment    ��ʾ�Ƿ����ע��
    ///@exception    ��������﷨�������׳�CParseError
    void read(const char *filename,int ignoreText=0, bool ignoreComment=true);


    ///���ļ��ж�ȡXML�ļ�
    ///@param    input    �ļ�
    ///@param    ignoreText    1��ʾ�������е����ģ�0��ʾ����������
    ///@param    ignoreComment    ��ʾ�Ƿ����ע��
    ///@exception    ��������﷨�������׳�CParseError
    void read(FILE *input,int ignoreText=0, bool ignoreComment=true);


    // Sax mode parse function, added by �½�, 2006.06.12
    void setUserData(void *data);

    void readSax(FILE *input, StartElement start, EndElement end, int ignoreText=0);

    // ������
    void readSax2(KEY *pKey);

    ///���ַ����ж�ȡXML
    ///@param    string    Ҫ������ַ���
    ///@param    ignoreText    1��ʾ�������е����ģ�0��ʾ����������
    ///@exception    ��������﷨�������׳�CParseError
    void readString(const char *string, int ignoreText=0);

    ///��XMLд���ļ�
    ///@param    filename    �ļ���
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int write(const char *filename);
    
    ///��XMLд���ļ�
    ///@param    output    �ļ�
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int write(FILE *output);

    ///��XML�ļ���ͷд���ļ�
    ///@param    output    �ļ�
    ///@return    1��ʾ�ɹ���0��ʾʧ��
    int writeHead(FILE *output);

    ///��XML�ļ���ͷд�뻺����
    ///@param    void
    ///@return    д��ĳ���
    int writeStringHead(void);


    int writeString(char *lpString);

private:
    ///���ڵ�
    CXMLNode *m_rootNode;

    ///���뷽ʽ
    CStringPtr m_encoding;
    
    ///�汾
    CStringPtr m_version;
    
    ///���ڵ�����
    CStringPtr m_root;

    ///DTD�ļ���
    CStringPtr m_doctype;

    ///��ȡXML�ļ�ʱ�ĵ�ǰ�ڵ�
    CXMLElement m_curElement;
    
    ///��ǰ���к�
    int m_lineNo;
    
    ///ǰһ������ַ���EOF��ʾ�޷�����ǰһ��ȡ�ַ�
    int m_lastChar;

    ///�ڴ��ַ�������ʱʹ�õ��ַ�������
    const char *m_inputString;

    // Sax mode parse function, added by �½�, 2006.06.12
    void *m_userdata;

    ///��XML�ļ��л�ȡ��һ���ڵ�
    ///@param    input    XML�ļ�
    ///@param    ignoreText    1��ʾ�������е����ģ�0��ʾ����������
    ///@param    ignoreComment    ��ʾ�Ƿ����ע��
    ///@return    ��ȡ�Ľڵ㣬Ӧ������m_curElement������Ѿ����ļ��������򷵻�NULL
    ///@exception    ��������﷨�������׳�CParseError
    CXMLElement *getNextElement(FILE *input, int ignoreText, bool ignoreComment=true);

    ///��XML�ļ��л�ȡ��һ���ڵ�
    ///@param    input    XML�ļ�
    ///@return    ��ȡ�Ľڵ㣬Ӧ������m_curElement������Ѿ����ļ��������򷵻�NULL
    ///@exception    ��������﷨�������׳�CParseError
    CXMLElement *getPureNextElement(FILE *input);

    ///��ȡ��һ���ַ�����������m_lastChar�����Զ�����m_lineNo;
    ///@param    input    �����ļ�
    ///@param    allowEOF    �Ƿ���Խ���EOF��1��ʾ���Խ��ܣ�0��ʾ�����Խ��ܣ�����յ�EOF�����׳��쳣
    ///@return    �õ����ַ�
    ///@exception    ���allowEOFΪ0������һ��EOF�����׳�CParseError
    int getNextChar(FILE *input,int allowEOF=0);
    
    ///��ȡ��һ���ǿհ��ַ�����������m_lastChar
    ///@param    input    �����ļ�
    ///@param    allowEOF    �Ƿ���Խ���EOF��1��ʾ���Խ��ܣ�0��ʾ�����Խ��ܣ�����յ�EOF�����׳��쳣
    ///@return    �õ����ַ�
    ///@exception    ���allowEOFΪ0������һ��EOF�����׳�CParseError
    int ignoreSpace(FILE *input,int allowEOF=0);

    ///�˻�һ���Ѿ�������ַ�����������˻أ������
    ///@param    input    �����ļ�
    void ungetLastChar(FILE *input);

    ///����ĳ���ַ���������ǣ����׳��쳣
    ///@param    ch    �������ַ�
    ///@param    expectingChar    �������ַ�
    ///@exception    ��������������ַ������׳�CParseError
    void expectChar(int ch,int expectingChar);

    ///��ȡ��һ������
    ///@param    input    �����ļ�
    ///@param    allowValue    �Ƿ�������ֵ����ʽ���������ƣ�ָ�������е����
    ///@return    �õ������ƣ�����������ƣ��򷵻�NULL
    ///@exception    �����﷨���󣬽��׳�CParseError
    const char *getNextName(FILE *input,int allowValue=0);
    
    ///����һ���ַ�������ָ����endStringΪֹ��endString�������������ǲ����ڷ��ؽ���У����Զ���entity��ת��
    ///@param    input    �����ļ�
    ///@param    endString    �����ַ���
    ///@return    �õ����ַ���
    ///@exception    �����﷨���󣬽��׳�CParseError
    const char *getString(FILE *input,const char *endString);

    ///����һ�������б�����������һ�������б�
    ///@param    input    �����ļ�
    ///@return    �õ��������б�
    ///@exception    �����﷨���󣬽��׳�CParseError
    CXMLPropertyList *getNextPropertyList(FILE *input);

    ///�ַ����ռ�
    char *m_stringBuffer;
    
    ///�Ѿ��洢���ַ�������
    int m_curLength;
    
    ///�Ѿ�������ַ����ռ䳤��
    int m_curBufferLength;

    ///����һ���µĿ��ַ���
    void makeNewString(void);
    
    ///�����е��ַ���������һ���ַ�
    ///@param    ch    Ҫ���ӵ��ַ�
    void appendChar(int ch);

    ///��ȡ��ǰ���ַ���
    ///@return    ��ǰ���ַ���
    const char *getString(void);
    
    ///��ȡ��ǰ���ַ�������entityת������ַ���
    ///@return    ���ص��ַ���
    const char *getTransferedString(void);
};

/////////////////////////////////////////////////////////////////////////
///CParseError��һ���﷨���������쳣
///@author    
///@version    2.0,20051011
/////////////////////////////////////////////////////////////////////////
class CParseError//: public CBaseObject
{
public:
    ///���캯��
    ///@param    msg    ������Ϣ���ⲿ���ر������ڴ�ռ�
    ///@param    lineNo    ������к�
    CParseError(const char *msg, int lineNo);
    
    ///��������
    ~CParseError(void);

    virtual int isA(const char *objectType);
    virtual const char *getType(void);
    //virtual void output(Logger *pLogger,int indent=0);

    ///��ȡ������Ϣ
    ///@return    ������Ϣ
    const char *getMsg(void);
    
    ///��ȡ�����к�
    ///@return    �����к�
    int getLineNo(void);
private:
    ///�洢������Ϣ
    const char *m_msg;
    
    ///�洢�����к�
    int m_lineNo;
};



#endif
