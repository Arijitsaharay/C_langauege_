#include<stdio.h>
#include <math.h>
int  main()
{
    int i,j,k,m;
    int num_cls, mode_f,delta_1,delta_2,center,lower_md_cls_tot_frq;
    float arr_f_mark_mark_tot, mean, f_tot, f_mul_mrk_tot, std, variance,a,b, mode_cls_lower_bd,c,mode,median_cls_lower_bd,median;
    printf("enter number of classes : ");
    scanf("%d",&num_cls);
    float arr_cls[num_cls][2];
    int arr_f[num_cls];
    int arr_cf[num_cls];
    float arr_cls_mrk[num_cls];
    float arr_f_mul_mark[num_cls];
    float arr_f_mark_mark[num_cls];

    for (i=0 ; i<num_cls ; i++)
    {
        for(j=0 ; j<1 ; j++)
        {
            printf("enter class interval(ex: 100-110) : ");
            scanf("%f-%f",&arr_cls[i][j],&arr_cls[i][j+1]);
        }

    }

    for(i=0 ; i<num_cls ; i++)
    {
        printf("enter frequance : ");
        scanf("%d",&arr_f[i]);
        f_tot+= arr_f[i];

    }

     for(i=0 ; i<num_cls ; i++)
    {
       arr_cf[i]=arr_f[i]+arr_cf[i-1];
    }

    for(i=0 ; i<num_cls ; i++)
    {
        for(j=0 ; j<1 ; j++)
        {
           arr_cls_mrk[i]=(arr_cls[i][j]+arr_cls[i][j+1]) / 2;
        }
    }

    for(i=0 ; i<num_cls ; i++)
    {
        arr_f_mul_mark[i]=arr_f[i] * arr_cls_mrk[i];
        f_mul_mrk_tot+= arr_f_mul_mark[i];
    }

    for(i=0 ; i<num_cls ; i++)
    {
        arr_f_mark_mark[i]=arr_f_mul_mark[i] * arr_cls_mrk[i];
        arr_f_mark_mark_tot+= arr_f_mark_mark[i];
    }

    mean=f_mul_mrk_tot / f_tot;
    a= (f_tot*arr_f_mark_mark_tot)-(f_mul_mrk_tot*f_mul_mrk_tot) ;
    b= (f_tot)*(f_tot-1) ;
    variance=a/b;
    std= sqrt(variance);

    /*printf("a & b = %.2f  %.2f\n",a,b);*/
    /*printf("f*mark*mark = %2f%\n",arr_f_mark_mark_tot);
    printf("f*mark = %2f%\n\n",f_mul_mrk_tot); */

    mode_f=arr_f[0];
    for(i=0 ; i<num_cls ; i++)
    {
        if(mode_f<arr_f[i])
        {
            mode_f=arr_f[i];
            mode_cls_lower_bd=arr_cls[i][0]-0.5;
            k=i;
        }
    }

    c=arr_cls[0][1]-arr_cls[0][0]+1;
    delta_1=mode_f-arr_f[k-1];
    delta_2=mode_f-arr_f[k+1];
    mode= mode_cls_lower_bd +((delta_1*c) / (delta_1+delta_2));

    printf("\ntotal of frequnce = %.2f\n",f_tot);
    printf("frequance of mode class interval= %d\n",mode_f);
    printf("size of the model class interval = %.2f\n",c);
    printf("lower boundary of the modal class = %.2f\n",mode_cls_lower_bd);

    /*printf("delta1=%d delta2=%d \n",delta_1,delta_2);*/
    int cpy_num_cls=num_cls;
    for(i=0; i<cpy_num_cls ;i++)
    {
        center=f_tot/2;
        arr_cf[i]=arr_f[i]+arr_cf[i-1];
        if(arr_cf[i]>=center)
        {
            median_cls_lower_bd=arr_cls[i][0]-0.5;
            printf("lower boundary of the median class = %.2f\n",median_cls_lower_bd);
            printf("frequnce of median class interval = %d\n",arr_f[i]);
            m=i;
            cpy_num_cls=-1;
        }

    }
    for(i=0 ; i<m ; i++)
    {
        lower_md_cls_tot_frq+=arr_f[i];
    }
    printf("sum of the all frequance lower than median boundary = %d\n",lower_md_cls_tot_frq);

    median=median_cls_lower_bd + (((f_tot/2)-lower_md_cls_tot_frq)/arr_f[m]) *c;



     printf("\nMean = %.2f\n",mean);
     printf("Median = %.2f\n",median);
     printf("Mode = %.2f\n",mode);
     printf("Variance = %.2f\n",variance);
     printf("Standard deviation = %.2f\n",std);




}
