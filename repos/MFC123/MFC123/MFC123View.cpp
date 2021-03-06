
// MFC123View.cpp: CMFC123View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC123.h"
#endif

#include "MFC123Doc.h"
#include "MFC123View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC123View

IMPLEMENT_DYNCREATE(CMFC123View, CView)

BEGIN_MESSAGE_MAP(CMFC123View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC123View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_no1, &CMFC123View::OnNo1)
	ON_COMMAND(ID_no2, &CMFC123View::OnNo2)
	ON_COMMAND(ID_juhua, &CMFC123View::OnJuhua)
	ON_COMMAND(ID_xuehua, &CMFC123View::OnXuehua)
	ON_COMMAND(ID_shengdanshu, &CMFC123View::OnShengdanshu)
	ON_COMMAND(ID_test01, &CMFC123View::OnTest01)


END_MESSAGE_MAP()

// CMFC123View 构造/析构

CMFC123View::CMFC123View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC123View::~CMFC123View()
{
}

BOOL CMFC123View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC123View 绘图

void CMFC123View::OnDraw(CDC* /*pDC*/)
{
	CMFC123Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC123View 打印


void CMFC123View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC123View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC123View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC123View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFC123View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC123View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC123View 诊断

#ifdef _DEBUG
void CMFC123View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC123View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC123Doc* CMFC123View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC123Doc)));
	return (CMFC123Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC123View 消息处理程序





//树
void CMFC123View::OnNo1()
{
	// TODO: 在此添加命令处理程序代码
	int n = 100;
	for (int i = 0; i < n; i++)
		shu();
	

}
//树
void CMFC123View::shu()
{


	CClientDC ds(this);
	//CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	ds.SetMapMode(MM_ISOTROPIC);
	ds.SetViewportExt(rect.right, rect.bottom);
	ds.SetViewportOrg(100, -100);           //设置视口原点	
	ds.SetWindowOrg(0, 0);
	ds.SetWindowExt(800, 800);
	//dc.FillSolidRect(rect, RGB(0, 0, 0));

	double a[][8] = {                              //IFS码
		0,0.195,-0.488 ,0.344 ,0.433 ,0.4431 ,0.2452 ,0.25 ,
		0,0.462 ,0.414 ,-0.252 ,0.361 ,0.2511 ,0.5692 ,0.25,
		0,-0.058 ,-0.07 ,0.453 ,-0.111 ,0.5976 ,0.0969 ,0.25 ,
		0,-0.035 ,0.07 ,-0.469 ,-0.022 ,0.4884 ,0.5069 ,0.2,
		0,-0.637 ,0 ,0 ,0.501 ,0.8562 ,0.2513 ,0.05
	};
	double aa, bb;
	aa = a[0][1];
	double x = 900;
	srand((unsigned)time(NULL));
	double x0, y0;
	x0 = 0;
	y0 = 0;


	for (int k = 0; k < 10000; k++) {
		int r = rand() % 100;
		double x1, y1;
		if (r <= 25) {
			x1 = a[0][1] * x0 + a[0][2] * y0 + a[0][5];
			y1 = a[0][3] * x0 + a[0][4] * y0 + a[0][6];
		}
		else if (r <= 50) {
			x1 = a[1][1] * x0 + a[1][2] * y0 + a[1][5];
			y1 = a[1][3] * x0 + a[1][4] * y0 + a[1][6];
		}
		else if (r <= 75) {
			x1 = a[2][1] * x0 + a[2][2] * y0 + a[2][5];
			y1 = a[2][3] * x0 + a[2][4] * y0 + a[2][6];
		}
		else if (r <= 95) {
			x1 = a[3][1] * x0 + a[3][2] * y0 + a[3][5];
			y1 = a[3][3] * x0 + a[3][4] * y0 + a[3][6];
		}
		else {
			x1 = a[4][1] * x0 + a[4][2] * y0 + a[4][5];
			y1 = a[4][3] * x0 + a[4][4] * y0 + a[4][6];
		}
		x0 = x1;
		y0 = y1;

		ds.SetPixel(x1*x, 1000 - y1 * x, RGB(200, r * 6, 200));
	}
}



//树叶
void CMFC123View::OnNo2()
{
	// TODO: 在此添加命令处理程序代码
	//no2();

	int n = 100;
	for (int i = 0; i < n; i++)
		shuye();
	

}

//树叶
void CMFC123View::shuye()
{


	CClientDC ds(this);
	//CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	ds.SetMapMode(MM_ISOTROPIC);
	ds.SetViewportExt(rect.right, rect.bottom);
	ds.SetViewportOrg(500, 400);           //设置视口原点	
	ds.SetWindowOrg(0, 0);
	ds.SetWindowExt(6000, 6000);        //缩放（大） 放大

	//dc.FillSolidRect(rect, RGB(0, 0, 0));

	double a[][8] = {                              //IFS码
		0,0,0 ,0 ,0.25 ,0 ,-0.14 ,0.02 ,
		0,0.85 ,0.02 ,-0.02 ,0.83 ,0 ,1 ,0.84,
		0,0.09 ,-0.28 ,0.3 ,0.11 ,0 ,0.6 ,0.07 ,
		0,0.09 ,0.25 ,0.3 ,0.09 ,0 ,0.7 ,0.07,
	};
	double aa, bb;
	aa = a[0][1];
	double x = 900;
	srand((unsigned)time(NULL));
	double x0, y0;
	x0 = 0;
	y0 = 0;


	for (int k = 0; k < 10000; k++) {
		int r = rand() % 100;
		double x1, y1;
		if (r <= 2) {
			x1 = a[0][1] * x0 + a[0][2] * y0 + a[0][5];
			y1 = a[0][3] * x0 + a[0][4] * y0 + a[0][6];
		}
		else if (r <= 86) {
			x1 = a[1][1] * x0 + a[1][2] * y0 + a[1][5];
			y1 = a[1][3] * x0 + a[1][4] * y0 + a[1][6];
		}
		else if (r <= 93) {
			x1 = a[2][1] * x0 + a[2][2] * y0 + a[2][5];
			y1 = a[2][3] * x0 + a[2][4] * y0 + a[2][6];
		}
		else {
			x1 = a[3][1] * x0 + a[3][2] * y0 + a[3][5];
			y1 = a[3][3] * x0 + a[3][4] * y0 + a[3][6];
		}

		x0 = x1;
		y0 = y1;
		ds.SetPixel(x1*x, 1000 - y1 * x, RGB(200, r * 6, 200));
	}
}

//菊花
void CMFC123View::OnJuhua()
{

	// TODO: 在此添加命令处理程序代码
	int n = 100;
	for (int i = 0; i < n; i++)
		juhua();
}

//菊花
void CMFC123View::juhua()
{


	CClientDC ds(this);
	//CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	ds.SetMapMode(MM_ISOTROPIC);
	ds.SetViewportExt(rect.right, rect.bottom);
	ds.SetViewportOrg(500, 500);           //设置视口原点	
	ds.SetWindowOrg(0, 0);
	ds.SetWindowExt(8000, 8000);
	//dc.FillSolidRect(rect, RGB(0, 0, 0));

	double a[][8] = {                              //IFS码
		0,0.745455,-0.459091 ,0.406061 ,0.887121 ,1.460279 ,0.691072 ,0.912675 ,
		0,-0.424242 ,0.065152 ,-0.175758 ,-0.218182 ,3.809567 ,6.741476 ,0.087325,

	};
	double aa, bb;
	aa = a[0][1];
	double x = 900;
	srand((unsigned)time(NULL));
	double x0, y0;
	x0 = 0;
	y0 = 0;


	for (int k = 0; k < 10000; k++) {
		double r = rand() % 100;
		double x1, y1;
		if (r <= 91.2675) {
			x1 = a[0][1] * x0 + a[0][2] * y0 + a[0][5];
			y1 = a[0][3] * x0 + a[0][4] * y0 + a[0][6];
		}
		else {
			x1 = a[1][1] * x0 + a[1][2] * y0 + a[1][5];
			y1 = a[1][3] * x0 + a[1][4] * y0 + a[1][6];
		}
	
		x0 = x1;
		y0 = y1;
		ds.SetPixel(x1*x, 1000 - y1 * x, RGB(200, r * 6, 200));
	}
}

















void CMFC123View::no2()
{
	CClientDC ds(this);
	int K = 200;                       //逃逸时间
	int m = 500;                        //逃逸半径
	int Mx = 1000;                      //绘图范围
	int My = 500;



	double xs = -1.5;                  //窗口范围
	double xl = 1.5;
	double ys = -1.5;
	double yl = 1.5;
	double p = 0.32;               //复平面C 坐标
	double q = 0.043;
	double xb = (xl - xs) / Mx;
	double yb = (yl - ys) / My;
	double x0, y0, xk, yk, r;
	int k, H;
	for (int nx = 0; nx < Mx; nx++)
	{
		for (int ny = 0; ny < My; ny++)
		{
			x0 = xs + nx * xb;
			y0 = ys + ny * yb;
			k = 0;
			do
			{
				//Loop1:
				xk = 6  * x0*x0*x0*x0*y0 - 20 *x0*x0*y0*y0*y0 + 6 *y0*y0*y0*y0*y0 + p;
				yk = x0 * x0*x0*x0*x0 - y0 *y0 *y0 *y0 *y0 - 15 * x0*x0*x0*y0*y0 + 15 *y0*y0*y0*x0*x0 + q;
				k++;
				r = xk * xk + yk * yk;
				x0 = xk;
				y0 = yk;
				if (r > m)
				{
					H = k;
					ds.SetPixel(nx, ny, H * 1000);
					break;
				}
				if (k == K)
				{
					H = int(r * 10);
					ds.SetPixel(nx, ny, H * 1000);
					break;
				}
			} while (r <= m && k < K);
		}
	}

}


//雪花

void CMFC123View::OnXuehua()
{
	// TODO: 在此添加命令处理程序代码
	int n = 100;
	for (int i = 0; i < n; i++)
		xuehua();

}


//雪花
void CMFC123View::xuehua()
{


	CClientDC ds(this);
	//CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	ds.SetMapMode(MM_ISOTROPIC);
	ds.SetViewportExt(rect.right, rect.bottom);
	ds.SetViewportOrg(200, 0);           //设置视口原点	
	ds.SetWindowOrg(0, 0);
	ds.SetWindowExt(1200, 1200);
	//dc.FillSolidRect(rect, RGB(0, 0, 0));

	double a[][8] = {                              //IFS码
		0,0.382,0 ,0 ,0.382 ,0.3072 ,0.619 ,0.2 ,
		0,0.382,0 ,0 ,0.382 ,0.6033 ,0.4044 ,0.2,
		0,0.382,0 ,0 ,0.382 ,0.0139 ,0.4044 ,0.2,
		0,0.382,0 ,0 ,0.382 ,0.1253 ,0.0595 ,0.2,
		0,0.382,0 ,0 ,0.382 ,0.492 ,0.0595 ,0.2
	};
	double aa, bb;
	aa = a[0][1];
	double x = 900;
	srand((unsigned)time(NULL));
	double x0, y0;
	x0 = 0;
	y0 = 0;

	for (int k = 0; k < 10000; k++) {
		double r = rand() % 100;
		double x1, y1;
		if (r <= 20) {
			x1 = a[0][1] * x0 + a[0][2] * y0 + a[0][5];
			y1 = a[0][3] * x0 + a[0][4] * y0 + a[0][6];
		}
		else if (r <= 40) {
			x1 = a[1][1] * x0 + a[1][2] * y0 + a[1][5];
			y1 = a[1][3] * x0 + a[1][4] * y0 + a[1][6];
		}
		else if (r <= 60) {
			x1 = a[2][1] * x0 + a[2][2] * y0 + a[2][5];
			y1 = a[2][3] * x0 + a[2][4] * y0 + a[2][6];
		}
		else if (r <= 80) {
			x1 = a[3][1] * x0 + a[3][2] * y0 + a[3][5];
			y1 = a[3][3] * x0 + a[3][4] * y0 + a[3][6];
		}
		else {
			x1 = a[4][1] * x0 + a[4][2] * y0 + a[4][5];
			y1 = a[4][3] * x0 + a[4][4] * y0 + a[4][6];
		}

		x0 = x1;
		y0 = y1;
		ds.SetPixel(x1*x, 1000 - y1 * x, RGB(200, r * 6, 200));
	}
}

//圣诞树
void CMFC123View::OnShengdanshu()
{
	// TODO: 在此添加命令处理程序代码
	int n = 100;
	for (int i = 0; i < n; i++)
		shengdanshu();
}

//圣诞树
void CMFC123View::shengdanshu()
{


	CClientDC ds(this);
	//CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	ds.SetMapMode(MM_ISOTROPIC);
	ds.SetViewportExt(rect.right, rect.bottom);
	ds.SetViewportOrg(200, 0);           //设置视口原点	
	ds.SetWindowOrg(0, 0);
	ds.SetWindowExt(1200, 1200);
	//dc.FillSolidRect(rect, RGB(0, 0, 0));

	double a[][8] = {                              //IFS码
		0,0,-0.5,0.5 ,0 ,0.5 ,0 ,0.333 ,
		0,0,0.5,-0.5 ,0 ,0.5 ,0.5 ,0.333,
		0,0.5,0 ,0 ,0.5 ,0.25 ,0.5 ,0.334,
		
	};
	double aa, bb;
	aa = a[0][1];
	double x = 900;
	srand((unsigned)time(NULL));
	double x0, y0;
	x0 = 0;
	y0 = 0;

	for (int k = 0; k < 10000; k++) {
		double r = rand() % 100;
		double x1, y1;
		if (r <= 33.3) {
			x1 = a[0][1] * x0 + a[0][2] * y0 + a[0][5];
			y1 = a[0][3] * x0 + a[0][4] * y0 + a[0][6];
		}
		else if (r <= 66.6) {
			x1 = a[1][1] * x0 + a[1][2] * y0 + a[1][5];
			y1 = a[1][3] * x0 + a[1][4] * y0 + a[1][6];
		}
		else  {
			x1 = a[2][1] * x0 + a[2][2] * y0 + a[2][5];
			y1 = a[2][3] * x0 + a[2][4] * y0 + a[2][6];
		}
		

		x0 = x1;
		y0 = y1;
		ds.SetPixel(x1*x, 1000 - y1 * x, RGB(200, r * 6, 200));
	}
}



void CMFC123View::OnTest01()
{
	// TODO: 在此添加命令处理程序代码
	CPaintDC dc(this);
	dc.MoveTo(10, 10);
	dc.LineTo(200, 400);
}
