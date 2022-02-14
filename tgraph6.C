#include <iostream>
#include <cmath>
using namespace std;

//take b=100,m=2,s=1
void tgraph6()
{
  double  i;
  double j;
  double a,b,sum=0;
  double x,y;
  double sig;
  double mu;
  double pi=3.1415;
  
  cout<<"enter the upper limit"<<endl;
  cin>>b;
  cout<<"enter the value of mean"<<endl;
  cin>>mu;
  cout<<"enter the value of sigma"<<endl;
  cin>>sig;

  TH1F *h1= new TH1F("h1","first histogram",1000,-10,30);

   TGraph *g=new TGraph();
   TGraph *gr=new TGraph();

   
   for (int i=0;i<10000;i++) {
     double x=gRandom->Gaus(mu,sig);
     //h1->Fill(x);

   }
for (int k=0;k<100;k++){
gr->SetPoint(k,k*0.1,1/sqrt(2*pi*pow(sig,2))*exp(-pow(((k*0.1)-mu)/(2*sig),2)));

}
   for (i=0;i<b;i++) {
     for(j=1;j<mu;j+=0.0001)
       {

	 y=0.0026*sin(1.27*.24*i/j)*1/sqrt(2*pi*pow(sig,2))*exp(-pow((j-mu)/(2*sig),2));
	 sum+=(y*0.0001);

  }
     g->SetPoint(i,i,sum);

   }
  TCanvas *c1= new TCanvas("c1","bin size",700,800);
   c1-> Divide(2,1);
   c1->cd(1);
   //h1->Draw();
gr->GetXaxis()->SetTitle("E(GeV)");
   gr->GetYaxis()->SetTitle(" f(E)");
   gr->GetXaxis()->CenterTitle();
   gr->GetYaxis()->CenterTitle();

   gr->Draw("AC");
auto *legend =new TLegend(0.1,0.7,0.48,0.8);                               \
    legend->SetHeader("","");                                                  \
    //legend->AddEntry(g,"L1","l");
    legend->AddEntry(gr,"f(E)=#frac{1}{#sqrt{2#pi#sigma^{2}}} exp#left(- #frac{(E-#mu)^{2}}{2#sigma^{2}}#right)","");
legend->AddEntry(gr,"#mu=5,#sigma=0.01","");
    //legend->AddEntry(gr,"E3","l");
    legend->Draw();
gr->SetLineColor(kPink-8);
   gr->SetLineWidth(3);

   h1->SetLineColor(kRed-4);
   h1->SetLineWidth(2);
   h1->SetTitle(";E(GeV);f(E) = #frac{1}{#sqrt{2#pi#sigma^{2}}} exp#left(- #frac{(E-#mu)^{2}}{2#sigma^{2}}#right)");
   h1->GetXaxis()->CenterTitle();
   h1->GetYaxis()->CenterTitle();


   g->SetLineColor(kBlue);
   g->SetLineWidth(3);
   g->GetXaxis()->SetTitle("distance L(m)");
   g->GetYaxis()->SetTitle("P( #nu_{#alpha}#rightarrow#nu_{#beta})");
   g->GetXaxis()->CenterTitle();
   g->GetYaxis()->CenterTitle();

  //  cout<<"result="<<sum<<endl;

  c1->cd(2);
  g->Draw("AC");


}









