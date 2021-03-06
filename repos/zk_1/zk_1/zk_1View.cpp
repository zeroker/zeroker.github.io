
// zk_1View.cpp: Czk1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "zk_1.h"
#endif

#include "zk_1Doc.h"
#include "zk_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Czk1View

IMPLEMENT_DYNCREATE(Czk1View, CView)

BEGIN_MESSAGE_MAP(Czk1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Czk1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYUP()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_OFFICE2007_32771, &Czk1View::OnOffice200732771)

	ON_COMMAND(line_zk_01, &Czk1View::Onzk01)
END_MESSAGE_MAP()

// Czk1View 构造/析构

Czk1View::Czk1View() noexcept
{
	bShiftdown = bShiftup = bShiftB = false;
	// TODO: 在此处添加构造代码

}

Czk1View::~Czk1View()
{
}

BOOL Czk1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Czk1View 绘图
void Czk1View::OnDraw(CDC* pDC)
{

	//Czk1Doc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	//CRect rect;
	//GetClientRect(&rect);
	//pDC->SetMapMode(MM_ANISOTROPIC);
	//pDC->SetViewportOrg(0, 0);
	//pDC->SetViewportExt(rect.right, rect.bottom);
	//pDC->SetWindowOrg(0, 0);
	//pDC->SetWindowExt(1000, 1000);
	////画图
	//pDC->MoveTo(50, 50);
	//pDC->LineTo(50, 950);
	//pDC->LineTo(950, 950);
	//pDC->LineTo(50, 50);


	if (bShiftdown)//按下了Shift键
	{
		//pDC->TextOut(20, 20, "用户按下了Shift键!");
		pDC->Ellipse(10, 30, 20, 20);
	}
	if (bShiftup)//释放了Shift键
	{
		//pDC->TextOut(20, 20, "用户释放了Shift键!");
		pDC->Ellipse(20, 10, 20, 20);
	}
	if (bShiftB)//同时按下了Shift键和B键
	{
		//pDC->TextOut(20, 20, "用户同时按下Shift键和B键!");
		//pDC->Ellipse(10, 10, 20, 20);
		
		
		//bShiftB = false;
	}


	// TODO: 在此处为本机数据添加绘制代码
}


// Czk1View 打印


void Czk1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Czk1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Czk1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Czk1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void Czk1View::OnRButtonUp(UINT  nFlags , CPoint point)
{
	CDC* pDC = GetDC();
	if (nFlags == MK_LBUTTON)
	{
		pDC->LineTo(point.x, point.y);
	}

	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Czk1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Czk1View 诊断

#ifdef _DEBUG
void Czk1View::AssertValid() const
{
	CView::AssertValid();
}

void Czk1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Czk1Doc* Czk1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Czk1Doc)));
	return (Czk1Doc*)m_pDocument;
}
#endif //_DEBUG


// Czk1View 消息处理程序


void Czk1View::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == VK_SHIFT)//判断Shift键是否被释放
	{
		bShiftup = true;
		bShiftdown = false;
		Invalidate(true);//显示信息
	}

	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}


void Czk1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == VK_SHIFT)//判断Shift键是否被按下
	{
		bShiftdown = true;
		bShiftup = false;
		Invalidate(true);  //显示信息
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void Czk1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// 判断是否同时敲击了字符键B键和Shift键
		if ((nChar == 'b') | (nChar == 'B'))     //if((nChar==66)|(nChar==98))
		{
			if (bShiftdown)
			{
				bShiftB = true;
				bShiftdown = false;
				Invalidate(true);
			}
		}

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void Czk1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//pen = GetStockObject(WHITE_PEN);
	/*
	
	
	CDC* pDC = GetDC(); // 获取DC
	pDC->SelectObject(&pen); // 选入笔 
	pDC->Rectangle(&rect); // 绘制矩形
	ReleaseDC(pDC); // 释放DC
	*/
	CView::OnLButtonUp(nFlags, point);
}


void Czk1View::OnOffice200732771()
{
	// TODO: 在此添加命令处理程序代码
	

	
}





void Czk1View::Onzk01()                        //生成直线代码    （有菜单）
{

	CDC *pDC = GetDC();
	pDC->MoveTo(100, 100);
	pDC->LineTo(300, 300);
	// TODO: 在此添加命令处理程序代码
}
