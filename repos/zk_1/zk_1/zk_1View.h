
// zk_1View.h: Czk1View 类的接口
//

#pragma once


class Czk1View : public CView
{
private: 
	bool bShiftdown, bShiftup, bShiftB;

protected: // 仅从序列化创建
	Czk1View() noexcept;
	DECLARE_DYNCREATE(Czk1View)

// 特性
public:
	Czk1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);				 // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Czk1View();
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
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnOffice200732771();
	afx_msg void On32772();
	afx_msg void Onworld();
	afx_msg void Onzk01();
};

#ifndef _DEBUG  // zk_1View.cpp 中的调试版本
inline Czk1Doc* Czk1View::GetDocument() const
   { return reinterpret_cast<Czk1Doc*>(m_pDocument); }
#endif

