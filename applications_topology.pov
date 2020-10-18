// Visualing Topology
// Miguels Topology Master

#include "colors.inc" 
#include "textures.inc" 
#include "glass.inc" 
#include "golds.inc" 
#include "metals.inc" 

background { color Black } 

camera { 
  ultra_wide_angle 
  location <-200, 282.843, 200>   
  look_at <0, 0, 0>     right x*image_width/image_height
angle 1.5708
} 

light_source {
<10, 10, 10>   
color rgb <0.5, 0.5, 0.5>
} 

sphere {
<0, 0, 0>   0.25

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<1, 0, 0>   0.25

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<0, 1, 0>   0.25

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<0, 0, 1>   0.25

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-1, 0, 0>   0.25

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<0, -1, 0>   0.25

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<0, 0, -1>   0.25

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

polygon {
3
<1, 0, 0>   <0, 1, 0>   <0, 0, 1>   texture{ 
         pigment{ White_Marble }
         finish { phong 1 }
         scale 2.0
       }
}

polygon {
3
<0, 1, 0>   <-1, 0, 0>   <0, 0, 1>   texture{ 
         pigment{ White_Marble }
         finish { phong 1 }
         scale 2.0
       }
}

polygon {
3
<-1, 0, 0>   <0, -1, 0>   <0, 0, 1>   texture{ 
         pigment{ White_Marble }
         finish { phong 1 }
         scale 2.0
       }
}

polygon {
3
<0, -1, 0>   <1, 0, 0>   <0, 0, 1>   texture{ 
         pigment{ White_Marble }
         finish { phong 1 }
         scale 2.0
       }
}

cylinder {
<-0.5, 0.5, 2.5>   <0.5, 0.5, 2.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-0.5, -0.5, 2.5>   <-0.5, 0.5, 2.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<0.5, -0.5, 2.5>   <-0.5, -0.5, 2.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<0.5, 0.5, 2.5>   <0.5, -0.5, 2.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<0.5, -0.5, 1.5>   <0.5, 0.5, 1.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-0.5, -0.5, 1.5>   <0.5, -0.5, 1.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-0.5, 0.5, 1.5>   <-0.5, -0.5, 1.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<0.5, 0.5, 1.5>   <-0.5, 0.5, 1.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<0.5, 0.5, 1.5>   <0.5, 0.5, 2.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-0.5, 0.5, 1.5>   <-0.5, 0.5, 2.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-0.5, -0.5, 1.5>   <-0.5, -0.5, 2.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<0.5, -0.5, 1.5>   <0.5, -0.5, 2.5>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

sphere {
<0.5, 0.5, 2.5>   0.1

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-0.5, 0.5, 2.5>   0.1

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-0.5, -0.5, 2.5>   0.1

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<0.5, -0.5, 2.5>   0.1

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<0.5, 0.5, 1.5>   0.1

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-0.5, 0.5, 1.5>   0.1

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-0.5, -0.5, 1.5>   0.1

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<0.5, -0.5, 1.5>   0.1

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

cylinder {
<1, 1, 1>   <3, 1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<1, -1, 1>   <1, 1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<3, -1, 1>   <1, -1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<3, 1, 1>   <3, -1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<3, -1, -1>   <3, 1, -1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<1, -1, -1>   <3, -1, -1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<1, 1, -1>   <1, -1, -1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<3, 1, -1>   <1, 1, -1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<3, 1, -1>   <3, 1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<1, 1, -1>   <1, 1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<1, -1, -1>   <1, -1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<3, -1, -1>   <3, -1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

sphere {
<3, 1, 1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<1, 1, 1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<1, -1, 1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<3, -1, 1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<3, 1, -1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<1, 1, -1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<1, -1, -1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<3, -1, -1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

cylinder {
<-3, 1, 1>   <-1, 1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-3, -1, 1>   <-3, 1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-1, -1, 1>   <-3, -1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-1, 1, 1>   <-1, -1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-1, -1, -1>   <-1, 1, -1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-3, -1, -1>   <-1, -1, -1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-3, 1, -1>   <-3, -1, -1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-1, 1, -1>   <-3, 1, -1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-1, 1, -1>   <-1, 1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-3, 1, -1>   <-3, 1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-3, -1, -1>   <-3, -1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-1, -1, -1>   <-1, -1, 1>   0.1texture{ T_Gold_1A
         finish { phong 1 }
       }
}

sphere {
<-1, 1, 1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-3, 1, 1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-3, -1, 1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-1, -1, 1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-1, 1, -1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-3, 1, -1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-3, -1, -1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

sphere {
<-1, -1, -1>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

cylinder {
<0, 0, 0>   <0.57735, 0.57735, 0.57735>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<0.57735, 0.57735, 0.57735>   <0.696923, 0.696923, 1.56295>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<0.696923, 0.696923, 1.56295>   <0.492799, 0.492799, 1.9712>   0.025texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<0.492799, 0.492799, 1.9712>   <0.318568, 0.318568, 2.01347>   0.0125texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<0.318568, 0.318568, 2.01347>   <0.2464, 0.2464, 1.9413>   0.00625texture{ T_Gold_1A
         finish { phong 1 }
       }
}

sphere {
<0.210315, 0.210315, 1.90522>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

cylinder {
<0, 0, 0>   <-0.707107, 0.707107, 0>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-0.707107, 0.707107, 0>   <-0.707107, 1.70711, 0>   0.05texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-0.707107, 1.70711, 0>   <-0.353553, 2.06066, 0>   0.025texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-0.353553, 2.06066, 0>   <-0.103553, 2.06066, 0>   0.0125texture{ T_Gold_1A
         finish { phong 1 }
       }
}

cylinder {
<-0.103553, 2.06066, 0>   <-0.015165, 1.97227, 0>   0.00625texture{ T_Gold_1A
         finish { phong 1 }
       }
}

sphere {
<0.0290291, 1.92808, 0>   0.2

 texture{ T_Chrome_5A
         finish { phong 1 }
       }

rotate <0, 0, -clock*360>
}

