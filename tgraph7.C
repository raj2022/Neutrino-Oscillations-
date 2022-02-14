#include <iostream>
#include <cmath>
using namespace std;

//take b=500
void tgraph7()
{
  double  i;
  double j;
  double a,b,sum=0;
  double x,y;
  double sig=0.4;
  double mu=5;
  double pi=3.1415;

  cout<<"enter the upper limit"<<endl;
  cin>>b;
  TH1F *h1= new TH1F("h1","first histogram",1000,-10,30);

   TGraph *g=new TGraph();
   TGraph *gr=new TGraph();                                                                                                                                                                                                                                                                                    


   for (int i=0;i<5000;i++) {
     gr->SetPoint(i,i*0.01,0.0001*pow(i*0.01,2)*(1-(2*i*0.01/(3*52.8))));

   }


   for (i=0;i<b;i++) {
     for(j=0.0001;j<0.8;j+=0.0001)
       {

         y=0.0026*sin(1.27*0.024*i/j)*pow(j,2)*(1-2*j/(3*52.8));
         sum+=(y*0.0001);
   
  }
     g->SetPoint(i,i,sum);

   }
  TCanvas *c1= new TCanvas("c1","bin size",700,1500);
  c1-> Divide(2,1);
   c1->cd(1);
   gr->Draw();
auto *legend =new TLegend(0.1,0.7,0.48,0.8);                               \
    legend->SetHeader("","");                                                  \
    //legend->AddEntry(g,"L1","l");
    legend->AddEntry(gr,"f(E)= E^{2} #left(1- #frac{2E}{3E_{max}}#right)","");
legend->AddEntry(gr,"E_{max}=52.8 MeV","");
    //legend->AddEntry(gr,"E3","l");
    legend->Draw();
   gr->GetXaxis()->SetTitle("E(MeV)");
   gr->GetYaxis()->SetTitle("f(E) ");
   gr->GetXaxis()->CenterTitle();
   gr->GetYaxis()->CenterTitle();
   gr->SetLineColor(kPink-8);
   gr->SetLineWidth(2);
   gr->SetMarkerColor(kPink-8);
   g->SetLineColor(kBlue);
   g->SetLineWidth(3);
   g->GetXaxis()->SetTitle("distance L(m)");
   g->GetYaxis()->SetTitle("P( #nu_{#alpha}#rightarrow#nu_{#beta})");
   g->GetXaxis()->CenterTitle();
   g->GetYaxis()->CenterTitle();

  

  c1->cd(2);
  g->Draw("AC");
}







