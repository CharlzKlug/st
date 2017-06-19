#include "GeometryFunctions.h"

double nf2(QPoint a, QPoint b, QPoint p)
{
    return (p.x()-a.x())*(b.y()-a.y()) - (b.x()-a.x())*(p.y()-a.y());
}

bool isForward(QPoint a, QPoint b, QPoint c)
{
    if ((c.x()-b.x())*(b.x()-a.x())+(c.y()-b.y())*(b.y()-a.y())>0)
        return true;
    return false;
}

bool isBackward(QPoint a, QPoint b, QPoint c)
{
    if ((c.x()-a.x())*(b.x()-a.x())+(c.y()-a.y())*(b.y()-a.y())<0)
        return true;
    return false;
}

QVector<QPoint> min_poly(QVector<QPoint> p)
{
    int m=0;
    int n=p.size();
    int start;
    for(int i=1; i<n; i++)
    {
        if (p[m]==p[i]) goto cicle_end;
        if (m==0) {start=n-1;}
        else {start=m-1;}
        if (nf2(p[start], p[m], p[i])==0) {p[m]=p[i];}
        else
        {
            m++;
            p[m]=p[i];
        }
        cicle_end:;
    }
    if (m>1 && nf2(p[m], p[m-1], p[0])==0)
    {
        p.remove(m, n-m);
        goto proc_end;
    }
    if (n-m>1)
    {
        p.remove(m+1, n-m-1);
    }
    proc_end:
    return p;
}

int oct_cor(QPoint q, QPoint p1, QPoint p2)
{
    int v1=oct(p1-q);
    int v2=oct(p2-q);
    int delta=v2-v1;
    if (delta>4) {delta=delta-8;}
    else {if (delta<-4) {delta=delta+8;}
    else {if (abs(delta)==4)
            {
                int f=nf2(p1,q,p2);
                if (f!=0) delta=4*sgn(f);
            }
        }
    }
    return delta;
}

int oct(QPoint v)
{
    int result;
    int x=v.x();
    int y=v.y();
    if (0<=y && y<x) result=1;
    if (0<x && x<=y) result=2;
    if (-y<x && x<=0) result=3;
    if (0<y && y<=-x) result=4;
    if (x<y && y<=0) result=5;
    if (y<=x && x<0) result=6;
    if (0<=x && x<-y) result=7;
    if (-x<=y && y<0) result=8;
    return result;
}

int sgn(int x)
{
    //int result;
    if (x>0) return 1;
    if (x<0) return -1;
    return 0;
    //return result;
}

int dir_test(QVector<QPoint> p)
{
    QPoint q=(p[0]+p[p.size()-1])/2;
    int result=0;
    for (int i=0; i<p.size()-2; i++)
        result=result+oct_cor(q, p[i], p[i+1]);
    result=sgn(result);
    return result;
}

int conv2(QVector<QPoint> p)
{
    int n=p.size();
    int c=nf2(p[n-1], p[0], p[1]);
    int result=1;
    int s;
    for (int i=1; i<n-1 && result==1; i++)
    {
        s=nf2(p[i-1], p[i], p[i+1]);
        if (c*s==0) result=-1;
        if (c*s<0) result=0;
    }
    return result;
}

QVector<QPoint> LCShift(QVector<QPoint> p)
{
    QPoint tmp=p[0];
    p.remove(0);
    p.append(tmp);
    return p;
}

int cross_segm(QPoint a, QPoint b, QPoint c, QPoint d, QPoint &q)
{
    int fa=nf2(c, d, a);
    int fb=nf2(c, d, b);
    int fc=nf2(a, b, c);
    int fd=nf2(a, b, d);
    if (fc==fd && (fa!=0 || fb!=0 || fc!=0 || fd!=0))
        return -1;
    double t;
    //double T= static_cast<double>(fc)/(fc-fd);
    if (fa-fb!=0)
    {
        t= static_cast<double>(fa)/(fa-fb);
        q=a+(b-a)*t;
    }
    if (fa*fb==0 && fc*fd==0)
    {
        if (inter_paral(a,b,c)<0 || inter_paral(a,b,d)<0 ||
                inter_paral(c,d,a)<0 || inter_paral(c,d,b)<0)
        return 2;
        else return 0;
    }
    if (fa*fb<=0 && fc*fd<=0) return 1;
    return 0;
}

void process_poly(QVector<QPoint> p)
{
    int n=p.size();
    for (int i=0; i<n; i++)
        std::cout << "(" << p[i].x() << "," << p[i].y() << ")\n";
    std::cout << "---\n";
}

QVector<QPoint> tri_poly(QVector<QPoint> p)
{
    p=min_poly(p);
    int n=p.size();
    if (n==3) return p;
    else
    {
        int d=dir_test(p);
        int k=2;
        if (conv2(p)==1) return split_poly(p,k);
        else
        {
            while (d*nf2(p[n-1], p[0], p[1])<0)
                p=LCShift(p);
            return find_poly_node(p,k,d,n);
        }
    }
}

QVector<QPoint> find_poly_node(QVector<QPoint> p, int k, int d, int n)
{
    if (k==n-2) return split_poly(p,k);
    else
    {
        if (d*nf2(p[0],p[1],p[k])>=0)
        {
            k++;
            return find_poly_node(p, k, d, n);
        }
        else
        {
            bool c = false;
            for (int i=k+1; i<n-1 && !c; i++)
            {
                c=isCrossed(p[0], p[k], p[i], p[i+1]);
                if (c) k=i;
            }
            if (c) return find_poly_node(p, k, d, n);
            else return split_poly(p, k);
        }
    }
}

QVector<QPoint> split_poly(QVector<QPoint> p, int k)
{
    QVector<QPoint> tmp=p;
    tmp.remove(1,k-1);
    QVector<QPoint> r1=tri_poly(tmp);
    tmp=p;
    tmp.remove(k+1, tmp.size()-k-1);
    QVector<QPoint> r2=tri_poly(tmp);
    return r1+r2;
}

bool isCrossed(QPoint a, QPoint b, QPoint c, QPoint d)
{
    QPoint tmp;
    int r = cross_segm(a, b, c, d, tmp);
    if (r==1 || r==2)
        return true;
    return false;
}

bool isCrossedPoly(QVector<QPoint> p)
{
    int end;
    int n=p.size();
    for (int i=0; i<n-1; i++)
        for (int j=i+2; j<n; j++)
        {
            if (j==n-1) end=0;
            else end=j+1;
            if (end!=i && isCrossed(p[i], p[i+1], p[j], p[end]))
                return true;
        }
    return false;
}

int inter_paral(QPoint a, QPoint b, QPoint c)
{
    QPoint v1=c-a;
    QPoint v2=c-b;
    return v1.x()*v2.x()+v1.y()*v2.y();
}
