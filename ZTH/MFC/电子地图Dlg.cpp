// 电子地图Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "电子地图.h"
#include "电子地图Dlg.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_shunxulinkid = 0;
	m_Class = 0;
	m_branch = 0;
	m_name = _T("");
	m_fileip = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Text(pDX, IDC_EDIT1, m_shunxulinkid);
	DDX_Text(pDX, IDC_EDIT2, m_Class);
	DDX_Text(pDX, IDC_EDIT3, m_branch);
	DDX_Text(pDX, IDC_EDIT4, m_name);
	DDX_Text(pDX, IDC_EDIT5, m_fileip);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnFileopen)
	ON_BN_CLICKED(IDC_BUTTON7, Onshuchutxt)
	ON_BN_CLICKED(IDC_BUTTON15, Onshunxu_linkid)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeshunxulinkid)
	ON_BN_CLICKED(IDC_BUTTON8, Onzhebanlinkid)
	ON_BN_CLICKED(IDC_BUTTON6, OnFileupdate)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeClass)
	ON_BN_CLICKED(IDC_BUTTON22, OnshunxuClass)
	ON_BN_CLICKED(IDC_BUTTON9, OnzhebanClass)
	ON_EN_CHANGE(IDC_EDIT3, OnChangebranch)
	ON_BN_CLICKED(IDC_BUTTON23, Onshunxubranch)
	ON_BN_CLICKED(IDC_BUTTON10, Onzhebanbranch)
	ON_EN_CHANGE(IDC_EDIT4, OnChangename)
	ON_BN_CLICKED(IDC_BUTTON24, Onname)
	ON_BN_CLICKED(IDC_BUTTON11, Onzhebanname)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON12, Onxuanzelinkid)
	ON_BN_CLICKED(IDC_BUTTON13, Oncharulinkid)
	ON_BN_CLICKED(IDC_BUTTON14, Onkuaipailinkid)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON16, Onxuanzeclass)
	ON_BN_CLICKED(IDC_BUTTON17, Onxuanzebranch)
	ON_BN_CLICKED(IDC_BUTTON18, OnquicksortClass)
	ON_BN_CLICKED(IDC_BUTTON4, Onpaopaobranch)
	ON_BN_CLICKED(IDC_BUTTON19, Onxuanze_branch)
	ON_BN_CLICKED(IDC_BUTTON20, Oncharubranch)
	ON_BN_CLICKED(IDC_BUTTON21, Onquicksortbranch)
	ON_BN_CLICKED(IDC_BUTTON5, Onnamepaopao)
	ON_BN_CLICKED(IDC_BUTTON25, Onnamexuanze)
	ON_BN_CLICKED(IDC_BUTTON26, Oncharu)
	ON_BN_CLICKED(IDC_BUTTON27, Onkuaisu)
	ON_EN_CHANGE(IDC_EDIT5, OnChangeip)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
struct link{
	unsigned short size;
	unsigned int linkid;
	unsigned short size_name;
	unsigned int node;
	unsigned int Class;
	unsigned int branch;
	unsigned int Flag;
	char name[30];
};
link k,*a;
short reverse_short(short a)
{
	union {
		short i;
		char c[2];
	} u, r;	
	u.i = a;
	r.c[0] = u.c[1];
	r.c[1] = u.c[0];	
	return r.i;
}
int reverse_int(int a)
{
	union {
		int i;
		char c[4];
	} u, r;	
	u.i = a;
	r.c[0] = u.c[3];
	r.c[1] = u.c[2];
	r.c[2] = u.c[1];
	r.c[3] = u.c[0];
	return r.i;
}
int i=0;
int comp_name(link a,link b)
{
	return strcmp(a.name,b.name)==-1;
}		
void quicksort_name(link *a,int n)
{
	sort(a,a+n,comp_name);
}
int comp_linkid(link a,link b)
{
	return a.linkid<b.linkid;
}
void quicksort_linkid(link *a,int n)
{
     sort(a,a+n,comp_linkid);
}


int comp_Class(link a,link b)
{
	return a.Class<b.Class;
}
void quicksort_Class(link *a,int n)
{
	sort(a,a+n,comp_Class);
}


int comp_branch(link a,link b)
{
	return a.branch<b.branch;
}
void quicksort_branch(link *a,int n)
{
	sort(a,a+n,comp_branch);
}


char s[100]="E:\\GTBL.dat";
void CMyDlg::OnFileopen() 
{
	i=0;
	UpdateData();
	string ss=m_fileip;
	strcpy(s,ss.c_str());
	FILE *stream;
	if( (stream = fopen(s ,"rb+" )) == NULL )
	{
		exit( 0 );
	}
	UpdateData(FALSE);
	unsigned int trash;
	link b;
	int sum=1;
	while(fread(&b.size,sizeof(short),1,stream))
	{
		b.size=reverse_short(b.size);
		fseek(stream,b.size-2,SEEK_CUR);
		sum++;
	}
	a = (link *)malloc(sum*sizeof(link));
	rewind(stream);
	while(fread(&a[i].size,sizeof(short),1,stream))
	{
		a[i].size=reverse_short(a[i].size);
		fread(&a[i].linkid,sizeof(int),1,stream);
		a[i].linkid=reverse_int(a[i].linkid);
		fread(&a[i].size_name,sizeof(short),1,stream);
		a[i].size_name=reverse_short(a[i].size_name);
		fread(&trash,sizeof(int),1,stream);
		trash=reverse_int(trash);
		a[i].Flag=(trash>>7)&1;
		a[i].branch=(trash>>4)&7;
		a[i].Class=trash&15;
		if(a[i].size-12 !=0)
		{
			fread(a[i].name,sizeof(char),a[i].size-12,stream);	
		}else
		{
			strcpy(a[i].name,"no name");		
		}
		i++;	
	}
	fclose( stream );
	this->MessageBox("文件打开成功","文件打开",MB_OK);
}


void fprint(){
	FILE *fp;
	if( (fp = fopen( "C:\\text.txt", "w" )) == NULL )
	{
		exit( 0 );
	}
	int j=0;
	for(;j<i;j++)
	{
		fprintf(fp,"linkid: ");
		fprintf(fp,"%d;",a[j].linkid);
		fprintf(fp,"roadflag: ");
		fprintf(fp,"%d;",a[j].Flag);
		fprintf(fp,"Class: ");
		fprintf(fp,"%d;",a[j].Class);
		fprintf(fp,"branch: ");
		fprintf(fp,"%d;",a[j].branch);
		fprintf(fp,"roadname: ");
		fprintf(fp,"%s\n",a[j].name);
	}
	fclose(fp);
}

void CMyDlg::Onshuchutxt() 
{
	fprint();
	this->MessageBox("输出在C:\\text.txt成功","输出文件",MB_OK);
}
bool shunxu_linkid(link *a,int k_linkid,int n)
{
	bool ans;
	bool *p=(bool *)calloc(n,sizeof(bool));
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		if(a[i].linkid==k_linkid)
		{
			p[i]=1;
			sum++;
		}
	}	
	if(sum>0)	
	{
		ans=true;
		FILE *fp;
		if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
		{
			exit( 0 );
		}
		int j=0;
		for(;j<i;j++)
		if(p[j])
			{
				fprintf(fp,"linkid: ");
				fprintf(fp,"%d",a[j].linkid);
				fprintf(fp,"Class: ");
				fprintf(fp,"%d",a[j].Class);
				fprintf(fp,"branch: ");
				fprintf(fp,"%d",a[j].branch);
				fprintf(fp,"name: ");
				fprintf(fp,"%s\n",a[j].name);
			}
		fclose(fp);
	}
	else 
		ans=false;
	free(p);
	return ans;
}

void CMyDlg::Onshunxu_linkid() 
{
	UpdateData();
	if(shunxu_linkid(a,m_shunxulinkid,i))
		this->MessageBox("find it!","linkid检索",MB_OK);
	else
		this->MessageBox("sorry , not find!","linkid检索",MB_OK);
	UpdateData(FALSE);
}

void CMyDlg::OnChangeshunxulinkid() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
int Search_linkid_left(link a[],int n,int b)//????b????
{
	if(n==0)
		return -1;
	int low = 0;
	int high = n-1;
	int last = -1;
	while (low<=high)
	{
		int mid = low +(high-low)/2;
		if (a[mid].linkid==b)
		{
			last = mid;
			high = mid -1;
		}
		else if(a[mid].linkid>b)
			high = mid -1;
		else
			low = mid +1;
	}
	
	return last;
	
}
int Search_linkid_right(link a[],int n,int b)//??b?????
{
	if(n<=0)
		return -1;
	int last = -1;
	int low = 0;
	int high = n-1;
	while (low<=high)
	{
		int mid = low +(high - low)/2;
		if(a[mid].linkid>b)
		{
			last = mid;
			high = mid -1;
		}
		else if (a[mid].linkid<=b)
		{
			low =mid +1;
		}
	}
	
	return last;
}

bool zheban_linkid(link *a,int k_linkid,int n)
{
	bool ans;
	quicksort_linkid(a,i);
	int left,right;
	left=Search_linkid_left(a,n,k_linkid);
	right=Search_linkid_right(a,n,k_linkid);
	if (left!=-1)
	{	
		if(right==-1)right=n;
		int sum=right-left;
		ans=true;
		FILE *fp;
		if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
		{
			exit( 0 );
		}
		for(i=left;i<right;i++)
		{
			fprintf(fp,"linkid: ");
			fprintf(fp,"%d",a[i].linkid);
			fprintf(fp,"Class: ");
			fprintf(fp,"%d",a[i].Class);
			fprintf(fp,"branch: ");
			fprintf(fp,"%d",a[i].branch);
			fprintf(fp,"name: ");
			fprintf(fp,"%s\n",a[i].name);
		}
		fclose(fp);		
	}
	else
		ans=false;
	return ans;
}


void CMyDlg::Onzhebanlinkid() 
{
	UpdateData();
	if(zheban_linkid(a,m_shunxulinkid,i))
		this->MessageBox("find it!","linkid检索",MB_OK);
	else
		this->MessageBox("sorry , not find!","linkid检索",MB_OK);
	UpdateData(FALSE);
}

void CMyDlg::OnFileupdate() 
{
	FILE *stream;
	if( (stream = fopen( "C:\\GTBL.dat", "wb+" )) == NULL )
	{
		exit( 0 );	
	}
	unsigned int trash;
	int j=0;
	while(j<i)
	{
		int size=a[j].size;
		a[j].size=reverse_short(a[j].size);
		fwrite(&a[j].size,sizeof(short),1,stream);
		a[j].linkid=reverse_int(a[j].linkid);
		fwrite(&a[j].linkid,sizeof(int),1,stream);
		a[j].size_name=reverse_short(a[j].size_name);
		fwrite(&a[j].size_name,sizeof(short),1,stream);
		trash=0;
		trash=trash|(a[j].Class&15);
		trash=trash|((a[j].branch&7)<<4);
		trash=trash|((a[j].Flag&1)<<7);
		trash=reverse_int(trash);
		fwrite(&trash,sizeof(int),1,stream);
		if(a[j].Flag)
		{
			fwrite(a[j].name,sizeof(char),size-12,stream);	
		}
		j++;
	}
	fclose( stream );
	this->MessageBox("文件更新成功","文件更新",MB_OK);	
}

void CMyDlg::OnChangeClass() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
bool shunxu_Class(link *a,int k_linkClass,int n)
{
	bool ans;
	bool *p=(bool *)calloc(n,sizeof(bool));
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		if(a[i].Class==k_linkClass)
		{
			p[i]=1;
			sum++;
		}
	}	
	if(sum>0)	
	{
		ans=true;
		FILE *fp;
		if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
		{
			exit( 0 );
		}
		int j=0;
		for(;j<i;j++)
			if(p[j])
			{
				fprintf(fp,"linkid: ");
				fprintf(fp,"%d",a[j].linkid);
				fprintf(fp,"Class: ");
				fprintf(fp,"%d",a[j].Class);
				fprintf(fp,"branch: ");
				fprintf(fp,"%d",a[j].branch);
				fprintf(fp,"name: ");
				fprintf(fp,"%s\n",a[j].name);
			}
		fclose(fp);
	}
	else 
		ans=false;
	free(p);
	return ans;
}
void CMyDlg::OnshunxuClass() 
{
	UpdateData();
	if(shunxu_Class(a,m_Class,i))
		this->MessageBox("find it!","Class检索",MB_OK);
	else
		this->MessageBox("sorry , not find!","Class检索",MB_OK);
	UpdateData(FALSE);
}
int Search_Class_left(link a[],int n,int b)//????b????
{
	if(n==0)
		return -1;
	int low = 0;
	int high = n-1;
	int last = -1;
	while (low<=high)
	{
		int mid = low +(high-low)/2;
		if (a[mid].Class==b)
		{
			last = mid;
			high = mid -1;
		}
		else if(a[mid].Class>b)
			high = mid -1;
		else
			low = mid +1;
	}
	
	return last;
	
}
int Search_Class_right(link a[],int n,int b)//??b?????
{
	if(n<=0)
		return -1;
	int last = -1;
	int low = 0;
	int high = n-1;
	while (low<=high)
	{
		int mid = low +(high - low)/2;
		if(a[mid].Class>b)
		{
			last = mid;
			high = mid -1;
		}
		else if (a[mid].Class<=b)
		{
			low =mid +1;
		}
	}
	
	return last;
}

bool zheban_Class(link *a,int k_linkid,int n)
{
	bool ans;
	quicksort_Class(a,i);
	int left,right;
	left=Search_Class_left(a,n,k_linkid);
	right=Search_Class_right(a,n,k_linkid);
	if (left!=-1)
	{	
		if(right==-1)right=n;
		int sum=right-left;
		ans=true;
		FILE *fp;
		if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
		{
			exit( 0 );
		}
		for(i=left;i<right;i++)
		{
			fprintf(fp,"linkid: ");
			fprintf(fp,"%d",a[i].linkid);
			fprintf(fp,"Class: ");
			fprintf(fp,"%d",a[i].Class);
			fprintf(fp,"branch: ");
			fprintf(fp,"%d",a[i].branch);
			fprintf(fp,"name: ");
			fprintf(fp,"%s\n",a[i].name);
		}
		fclose(fp);	
	}
	else
		ans=false;
	return ans;
}
void CMyDlg::OnzhebanClass() 
{
	UpdateData();
	if(zheban_Class(a,m_Class,i))
		this->MessageBox("find it!","Class检索",MB_OK);
	else
		this->MessageBox("sorry , not find!","Class检索",MB_OK);
	UpdateData(FALSE);	
}

void CMyDlg::OnChangebranch() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
bool shunxu_branch(link *a,int k_linkbranch,int n)
{
	bool ans;
	bool *p=(bool *)calloc(n,sizeof(bool));
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		if(a[i].branch==k_linkbranch)
		{
			p[i]=1;
			sum++;
		}
	}	
	if(sum>0)	
	{
		ans=true;
		FILE *fp;
		if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
		{
			exit( 0 );
		}
		int j=0;
		for(;j<i;j++)
			if(p[j])
			{
				fprintf(fp,"linkid: ");
				fprintf(fp,"%d",a[j].linkid);
				fprintf(fp,"Class: ");
				fprintf(fp,"%d",a[j].Class);
				fprintf(fp,"branch: ");
				fprintf(fp,"%d",a[j].branch);
				fprintf(fp,"name: ");
				fprintf(fp,"%s\n",a[j].name);
			}
		fclose(fp);	
	}
	else 
		ans=false;
	free(p);
	return ans;
}
void CMyDlg::Onshunxubranch() 
{
	UpdateData();
	if(shunxu_branch(a,m_branch,i))
		this->MessageBox("find it!","Class检索",MB_OK);
	else
		this->MessageBox("sorry , not find!","Class检索",MB_OK);
	UpdateData(FALSE);		
}
int Search_left_branch(link a[],int n,int b)//????b????
{
	if(n==0)
		return -1;
	int low = 0;
	int high = n-1;
	int last = -1;
	while (low<=high)
	{
		int mid = low +(high-low)/2;
		if (a[mid].branch==b)
		{
			last = mid;
			high = mid -1;
		}
		else if(a[mid].branch>b)
			high = mid -1;
		else
			low = mid +1;
	}
	
	return last;
}
int Search_right_branch(link a[],int n,int b)//??b?????
{
	if(n<=0)
		return -1;
	int last = -1;
	int low = 0;
	int high = n-1;
	while (low<=high)
	{
		int mid = low +(high - low)/2;
		if(a[mid].branch>b)
		{
			last = mid;
			high = mid -1;
		}
		else if (a[mid].branch<=b)
		{
			low =mid +1;
		}
	}
	
	return last;
}
bool zheban_branch(link *a,int k_linkbranch,int n)
{
	bool ans;
	quicksort_branch(a,i);
	int left,right;
	left=Search_left_branch(a,n,k_linkbranch);
	right=Search_right_branch(a,n,k_linkbranch);
	if (left!=-1)
	{	
		if(right==-1)right=n;
		int sum=right-left;
		ans=true;
		FILE *fp;
		if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
		{
			exit( 0 );
		}
		for(i=left;i<right;i++)
		{
			fprintf(fp,"linkid: ");
			fprintf(fp,"%d;",a[i].linkid);
			fprintf(fp,"Class: ");
			fprintf(fp,"%d;",a[i].Class);
			fprintf(fp,"branch: ");
			fprintf(fp,"%d;",a[i].branch);
			fprintf(fp,"name: ");
			fprintf(fp,"%s\n",a[i].name);
		}
		fclose(fp);	
	}
	else
		ans=false;
	return ans;
}
void CMyDlg::Onzhebanbranch() 
{
	UpdateData();
	if(zheban_branch(a,m_branch,i))
		this->MessageBox("find it!","Class检索",MB_OK);
	else
		this->MessageBox("sorry , not find!","Class检索",MB_OK);
	UpdateData(FALSE);	
}

void CMyDlg::OnChangename() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

bool shunxu_name(link *a,string k_name,int n)
{
	bool ans;
	bool *p=(bool *)calloc(n,sizeof(bool));
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		if (strcmp(a[i].name,k_name.c_str())==0)
		{
			p[i]=1;
			sum++;
		}
	}	
	if(sum>0)	
	{
		ans=true;
		FILE *fp;
		if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
		{
			exit( 0 );
		}
		int j=0;
		for(;j<i;j++)
			if(p[j])
			{
				fprintf(fp,"linkid: ");
				fprintf(fp,"%d",a[j].linkid);
				fprintf(fp,"Class: ");
				fprintf(fp,"%d",a[j].Class);
				fprintf(fp,"branch: ");
				fprintf(fp,"%d",a[j].branch);
				fprintf(fp,"name: ");
				fprintf(fp,"%s\n",a[j].name);
			}
		fclose(fp);
	}
	else 
		ans=false;
	free(p);
	return ans;
}
void CMyDlg::Onname() 
{
	UpdateData();
	char name[30];
	string s=m_name;
	strcpy(name,s.c_str());
	if(shunxu_name(a,name,i))
		this->MessageBox("find it!","name检索",MB_OK);
	else
		this->MessageBox("sorry , not find!","name检索",MB_OK);
	UpdateData(FALSE);	
}
int Search_name_left(link a[],int n,char *b)//????b????
{
	if(n==0)
		return -1;
	int low = 0;
	int high = n-1;
	int last = -1;
	while (low<=high)
	{
		int mid = low +(high-low)/2;
		if (strcmp(a[mid].name,b)==0)
		{
			last = mid;
			high = mid -1;
		}
		else if (strcmp(a[mid].name,b)==1)
			high = mid -1;
		else
			low = mid +1;
	}
	
	return last;
	
}
int Search_name_right(link a[],int n,char *b)//??b?????
{
	if(n<=0)
		return -1;
	int last = -1;
	int low = 0;
	int high = n-1;
	while (low<=high)
	{
		int mid = low +(high - low)/2;
		if(strcmp(a[mid].name,b)==1)
		{
			last = mid;
			high = mid -1;
		}
		else if (strcmp(a[mid].name,b)==-1||strcmp(a[mid].name,b)==0)
		{
			low =mid +1;
		}
	}
	
	return last;
}

bool zheban_name(link *a,char *k_name,int n)
{
	bool ans;
	quicksort_name(a,i);
	int left,right;
	left=Search_name_left(a,n,k_name);
	right=Search_name_right(a,n,k_name);
	if (left!=-1)
	{	
		if(right==-1)right=n;
		int sum=right-left;
		ans=true;
		FILE *fp;
		if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
		{
			exit( 0 );
		}
		for(i=left;i<right;i++)
		{
			fprintf(fp,"linkid: ");
			fprintf(fp,"%d",a[i].linkid);
			fprintf(fp,"Class: ");
			fprintf(fp,"%d",a[i].Class);
			fprintf(fp,"branch: ");
			fprintf(fp,"%d",a[i].branch);
			fprintf(fp,"name: ");
			fprintf(fp,"%s\n",a[i].name);
		}
		fclose(fp);	
	}
	else
		ans=false;
	return ans;
}
void CMyDlg::Onzhebanname() 
{
	UpdateData();
	char name[30];
	string s=m_name;
	strcpy(name,s.c_str());
	if(zheban_name(a,name,i))
		this->MessageBox("find it!","name检索",MB_OK);
	else
		this->MessageBox("sorry , not find!","name检索",MB_OK);
	UpdateData(FALSE);		
}
void paopao_linkid(link *a, int n)
{ 
	link t;
	int i, j;
	bool flag=true;
	for(i=0;i<n&&flag;i++)
	{
		flag=false;
		for(j=0;j<n-i-1;j++)
			if(a[j].linkid>a[j+1].linkid)
			{   
				memcpy(&t, &a[j], sizeof(link)); 
				memcpy(&a[j], &a[j+1], sizeof(link)); 
				memcpy(&a[j+1], &t, sizeof(link));
				flag=true;
			}
	}
}
void CMyDlg::OnButton2() 
{
	this->MessageBox("排序时间较长，请耐心等待!","linkid排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	paopao_linkid(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"linkid排序",MB_OK);
	this->MessageBox("按linkid排序成功!","linkid排序",MB_OK);
}
void xuanze_linkid(link *a,int n)
{
	int i,j,m;
	link t;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
		if(a[j].linkid<a[m].linkid)
			m=j;
			memcpy(&t,&a[i],sizeof(link));
			memcpy(&a[i],&a[m],sizeof(link));
			memcpy(&a[m],&t,sizeof(link));
	}
}
void CMyDlg::Onxuanzelinkid() 
{
	this->MessageBox("排序时间较长，请耐心等待!","linkid排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	xuanze_linkid(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"linkid排序",MB_OK);
	this->MessageBox("按linkid排序成功!","linkid排序",MB_OK);
}
void charu_linkid(link *a,int n)
{
	int i,j;
	link temp;
	for(i=1;i<n;i++)
	{
		memcpy(&temp,&a[i],sizeof(link));
		j=i-1;
		while(j>=0&&temp.linkid<a[j].linkid)
		{
			memcpy(&a[j+1],&a[j],sizeof(link));
			j--;
		}
		memcpy(&a[j+1],&temp,sizeof(link));
	}
}	
void CMyDlg::Oncharulinkid() 
{
	this->MessageBox("排序时间较长，请耐心等待!","linkid排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	charu_linkid(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"linkid排序",MB_OK);
	this->MessageBox("按linkid排序成功!","linkid排序",MB_OK);
}

void CMyDlg::Onkuaipailinkid() 
{
	int time_start,time_end;
	time_start=time(NULL);
	quicksort_linkid(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"linkid排序",MB_OK);
	this->MessageBox("按linkid排序成功!","linkid排序",MB_OK);
}

void paopao_class(link *a, int n)
{
	link t;
	int i, j;
	bool flag=true;
	for(i=0;i<n&&flag;i++)
	{
		flag=false;
		for(j=0;j<n-i-1;j++)
			if(a[j].Class>a[j+1].Class)
			{   
				memcpy(&t, &a[j], sizeof(link)); 
				memcpy(&a[j], &a[j+1], sizeof(link)); 
				memcpy(&a[j+1], &t, sizeof(link));
				flag=true;
			}
	}
}

void CMyDlg::OnButton3() 
{
	this->MessageBox("排序时间较长，请耐心等待!","Class番号排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	paopao_linkid(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"Class番号排序",MB_OK);
	this->MessageBox("按Class番号排序成功!","Class番号排序",MB_OK);
}

void xuanze_Class(link *a,int n)
{
	int i,j,m;
	link t;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
			if(a[j].Class<a[m].Class)
				m=j;
			memcpy(&t,&a[i],sizeof(link));
			memcpy(&a[i],&a[m],sizeof(link));
			memcpy(&a[m],&t,sizeof(link));
	}
}

void CMyDlg::Onxuanzeclass() 
{
	this->MessageBox("排序时间较长，请耐心等待!","Class番号排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	xuanze_linkid(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"Class番号排序",MB_OK);
	this->MessageBox("按Class番号排序成功!","Class番号排序",MB_OK);
}
void charu_Class(link *a,int n)
{
	int i,j;
	link temp;
	for(i=1;i<n;i++)
	{
		memcpy(&temp,&a[i],sizeof(link));
		j=i-1;
		while(j>=0&&temp.Class<a[j].Class)
		{
			memcpy(&a[j+1],&a[j],sizeof(link));
			j--;
		}
		memcpy(&a[j+1],&temp,sizeof(link));
	}
}


void CMyDlg::Onxuanzebranch() 
{

	this->MessageBox("排序时间较长，请耐心等待!","Class番号排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	charu_Class(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"Class番号排序",MB_OK);
	this->MessageBox("按Class番号排序成功!","Class番号排序",MB_OK);


	
}


void CMyDlg::OnquicksortClass() 
{

	int time_start,time_end;
	time_start=time(NULL);
	quicksort_Class(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"Class番号排序",MB_OK);
	this->MessageBox("按Class番号排序成功!","Class番号排序",MB_OK);

	
}

void paopao_branch(link *a, int n)
{
	link t;
	int i, j;
	bool flag=true;
	for(i=0;i<n&&flag;i++)
	{
		flag=false;
		for(j=0;j<n-i-1;j++)
			if(a[j].branch>a[j+1].branch)
			{   
				memcpy(&t, &a[j], sizeof(link)); 
				memcpy(&a[j], &a[j+1], sizeof(link)); 
				memcpy(&a[j+1], &t, sizeof(link));
				flag=true;
			}	
	}
}


void CMyDlg::Onpaopaobranch() 
{
	this->MessageBox("排序时间较长，请耐心等待!","branch排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	paopao_branch(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"branch排序",MB_OK);
	this->MessageBox("按branch排序成功!","branch排序",MB_OK);
	
}

void xuanze_branch(link *a,int n)
{
	int i,j,m;
	link t;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
			if(a[j].branch<a[m].branch)
				m=j;
			memcpy(&t,&a[i],sizeof(link));
			memcpy(&a[i],&a[m],sizeof(link));
			memcpy(&a[m],&t,sizeof(link));
	}
}

void CMyDlg::Onxuanze_branch() 
{
	this->MessageBox("排序时间较长，请耐心等待!","branch排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	xuanze_branch(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"branch排序",MB_OK);
	this->MessageBox("按branch排序成功!","branch排序",MB_OK);
}

void charu_branch(link *a,int n)
{
	int i,j;
	link temp;
	for(i=1;i<n;i++)
	{
		memcpy(&temp,&a[i],sizeof(link));
		j=i-1;
		while(j>=0&&temp.branch<a[j].branch)
		{
			memcpy(&a[j+1],&a[j],sizeof(link));
			j--;
		}
		memcpy(&a[j+1],&temp,sizeof(link));
	}
}

void CMyDlg::Oncharubranch() 
{
	this->MessageBox("排序时间较长，请耐心等待!","branch排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	charu_branch(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"branch排序",MB_OK);
	this->MessageBox("按branch排序成功!","branch排序",MB_OK);
}

void CMyDlg::Onquicksortbranch() 
{
	int time_start,time_end;
	time_start=time(NULL);
	quicksort_branch(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"branch排序",MB_OK);
	this->MessageBox("按branch排序成功!","branch排序",MB_OK);	
}
void paopao_name(link *a, int n)
{ 
	
	
	link t;
	int i, j;
	bool flag=true;
	for(i=0;i<n&&flag;i++)
	{
		flag=false;
		for(j=0;j<n-i-1;j++)
			if(strcmp(a[j].name,a[j+1].name)==1)
			{   
				memcpy(&t, &a[j], sizeof(link)); 
				memcpy(&a[j], &a[j+1], sizeof(link)); 
				memcpy(&a[j+1], &t, sizeof(link));
				flag=true;
			}
	}
			
}
void CMyDlg::Onnamepaopao() 
{
	this->MessageBox("排序时间较长，请耐心等待!","roadname排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	paopao_name(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"roadname排序",MB_OK);
	this->MessageBox("按roadname排序成功!","roadname排序",MB_OK);
}
void xuanze_name(link *a,int n)
{
	int i,j,m;
	link t;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
			if(strcmp(a[j].name,a[m].name)==-1)
				m=j;
			memcpy(&t,&a[i],sizeof(link));
			memcpy(&a[i],&a[m],sizeof(link));
			memcpy(&a[m],&t,sizeof(link));
	}
}
void CMyDlg::Onnamexuanze() 
{
	this->MessageBox("排序时间较长，请耐心等待!","roadname排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	xuanze_name(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"roadname排序",MB_OK);
	this->MessageBox("按roadname排序成功!","roadname排序",MB_OK);
}
void charu_name(link *a,int n)
{
	int i,j;
	link temp;
	for(i=1;i<n;i++)
	{
		memcpy(&temp,&a[i],sizeof(link));
		j=i-1;
		while(j>=0&&(strcmp(temp.name,a[j].name)==-1))
		{
			memcpy(&a[j+1],&a[j],sizeof(link));
			j--;
		}
		memcpy(&a[j+1],&temp,sizeof(link));
	}
}	
void CMyDlg::Oncharu() 
{
	this->MessageBox("排序时间较长，请耐心等待!","roadname排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	charu_name(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"roadname排序",MB_OK);
	this->MessageBox("按roadname排序成功!","roadname排序",MB_OK);
}

void CMyDlg::Onkuaisu() 
{
	this->MessageBox("排序时间较长，请耐心等待!","roadname排序",MB_OK);
	int time_start,time_end;
	time_start=time(NULL);
	quicksort_name(a,i);
	time_end=time(NULL);
	int time=time_end-time_start;
	char s[20];
	_itoa(time,s,10);
	char s1[]="本次排序共用时";
	strcat(s1,s);
	char s2[]="秒";
	strcat(s1,s2);
	this->MessageBox(s1,"roadname排序",MB_OK);
	this->MessageBox("按roadname排序成功!","roadname排序",MB_OK);	
}

void CMyDlg::OnChangeip() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CMyDlg::OnOK() 
{
	// TODO: Add extra validation here
	this->MessageBox("欢迎再次使用！","电子地图",MB_OK);
	free(a);
	CDialog::OnOK();
}

void CMyDlg::OnCancel() 
{
	this->MessageBox("欢迎再次使用！","电子地图",MB_OK);
	free(a);	
	CDialog::OnCancel();
}
