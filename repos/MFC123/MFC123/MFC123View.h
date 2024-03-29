
// MFC123View.h: CMFC123View 类的接口
//

#pragma once


class CMFC123View : public CView
{
protected: // 仅从序列化创建
	CMFC123View() noexcept;
	DECLARE_DYNCREATE(CMFC123View)

// 特性
public:
	CMFC123Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFC123View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	//没用的地毯
	void no2();
	//书
	afx_msg void OnNo1();
	void shu();
	//树叶
	afx_msg void OnNo2();
	void shuye();
	//菊花
	afx_msg void OnJuhua();
	void juhua();
	//雪花
	afx_msg void OnXuehua();
	void xuehua();
	//圣诞树
	afx_msg void OnShengdanshu();
	void shengdanshu();

	//========================================
	afx_msg void Ontest01();

};

#ifndef _DEBUG  // MFC123View.cpp 中的调试版本
inline CMFC123Doc* CMFC123View::GetDocument() const
   { return reinterpret_cast<CMFC123Doc*>(m_pDocument); }
#endif

