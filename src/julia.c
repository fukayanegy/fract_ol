/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:46 by etakaham          #+#    #+#             */
/*   Updated: 2024/01/20 15:51:47 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

void	julia(void)
{
	return ;
}

/*----------------------------------*/
/*  マンデルブロ集合  図形描画      */
/*                                  */
/*  漸化式が発散するまでの計算回数  */
/*  によって、対応する画素の階調を  */
/*  を求め、画面に描画する          */
/*  画素は 0～255 のグレースケール  */
/*----------------------------------*/
/*
void  Display( )
{
	HDC     hdc;      // ﾃﾞﾊﾞｲｽｺﾝﾃｷｽﾄ ﾊﾝﾄﾞﾙ
	double  Cr,Ci,dCr,dCi;
	double  zr,zi,zrN,ziN;
	int     i,ix,iy,cl,nc;
	char    c[128];

    dCr=(Cr2-Cr1)/XMAX;                                 // 実部(横)刻み幅
    dCi=(Ci2-Ci1)/YMAX;                                 // 虚部(縦)刻み幅
    nc=imax/256; if ( nc<=0 ) nc=1;                     // 階調比率(256階調)

    hdc=GetDC(hWnd);                                    // ｳｨﾝﾄﾞｳのDC取得

    for( Ci=Ci1,iy=YMAX; Ci<=Ci2; Ci+=dCi,iy-- )        // 定数虚部(縦)
      {
        for( Cr=Cr1,ix=0; Cr<=Cr2; Cr+=dCr,ix++ )       // 定数実部(横)
          {
            zr=0.0; zi=0.0;

            //--収束検査--
            for( i=0; i<imax; i++ )                     // 漸化式計算
              {
                zrN=zr*zr-zi*zi+Cr;                     // 実部漸化式計算
                if ( zrN>E ) break;                     // 発散する
                ziN=2.0*zr*zi+Ci;                       // 虚部漸化式計算
                if ( ziN>E ) break;                     // 発散する

                zr=zrN; zi=ziN;
              }

            cl=i/nc;                                    // 階調計算
            if ( cl>255 ) cl=255;                       // 階調補正
            SetPixelV(hdc,ix,iy,RGB(cl,cl,cl));         // ｶﾗｰ値で点を描画
          }
      }

    sprintf(c,"Cr:%8.5lf,%8.5lf  Ci:%8.5lf,%8.5lf",Cr1,Cr2,Ci1,Ci2);
    TextOut(hdc,0,0,c,strlen(c));                       // 文字列描画

    ReleaseDC(hWnd,hdc);                                // ｳｨﾝﾄﾞｳのDC 解放
}
*/
