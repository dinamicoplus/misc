m= Import["test.dat"];
a=ListLinePlot[m,PlotRange->{{0,First[Max /@ Transpose[m]]}}]
Export["Test.eps",a]
Exit[]
