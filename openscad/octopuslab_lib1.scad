include <./BOSL/constants.scad>
use <./BOSL/transforms.scad>
//https://github.com/revarbat/BOSL

//include <../octopuSCAD/boards.scad>
//include <octopus_modules.scad>
//include <totem.scad>

$fn = 60; //details


module distance(h = 5){
difference() {
    cylinder(d=6, h=h);
    translate([0,0,0]) {
      cylinder(r=1.7, h=100);
    }
  };
}


module distance2x(h1=5,h2=5) {
    distance(h = h1);
    xmove(2) ymove(-0.8) cube([3,1.6,5]);    
    xmove(7) distance(h = h2);    
}


//holder
module hold_90(tl=2.5){
    difference(){
        union(){
            ymove(-3.5) cube([10,7 ,tl]);
            cylinder(d=7, h = tl);
            }
        cylinder(d=3.2, h = tl*3);   
    }
}


//connector 90 |_
module conn_90(hs = 5) {
    distance(h = hs);
    xmove(2) ymove(-0.8) cube([3,1.6,5]);    
    xmove(7) distance(h = hs);
    xmove(-5) zmove(10) yrot(90) hold_90(); 
}



module plate2x2(tl = 2) {
    difference() {
        cube([a2,a2,tl]);
        translate([ 0, 0, -1 ]) holes2x2(tl);
    }
}



module part2x1_socket(tl=2) {
    difference() {
        cube([a1,a2,tl]);
        translate([ 0, 0, -1 ]) holes2x2(tl); //MODIFIK
    }
}



module box_0(a=58,b=28,tl=1.5,h=6){
    cube([a,b,h]);
}



tl_drazka = 1.6;
h_drazka = 6;

module box_1(a=58,b=28,tl=1.5,h=6){
   x0=3.5;
   if (a==wa1){ x0 = 4.5; }   
   
   
   difference(){
        
     cube([a,b,h]);
        
     union(){
        xmove(tl) ymove(tl) zmove(tl) cube([a-2*tl,b-2*tl,h]);
        //ymove(10) zmove(tl+2) cube([a*2,b-20,h]);
        
        xmove(10) ymove(0) zmove(h-h_drazka) cube([tl_drazka,50,h_drazka]);
        xmove(a-10-tl/2) ymove(0) zmove(h-h_drazka) cube([tl_drazka,50,h_drazka]);
        xmove(a/2-tl/2) ymove(0) zmove(h-h_drazka) cube([tl_drazka,50,h_drazka]); 
        if (a>wa1){
           xmove(wa1/2-tl/2) ymove(0) zmove(h-h_drazka) cube([tl_drazka,50,h_drazka]); 
           xmove(a-wa1/2-tl/2) ymove(0) zmove(h-h_drazka) cube([tl_drazka,50,h_drazka]); 
        }
      
   
        ///xmove(0) ymove(b/2-tl/2) zmove(h-h_drazka) cube([60,tl_drazka,h_drazka]);
        xmove(0) ymove(b/2-tl/2+5) zmove(h-h_drazka) cube([90,tl_drazka,h_drazka]);
        xmove(0) ymove(b/2-tl/2-5) zmove(h-h_drazka) cube([90,tl_drazka,h_drazka]);
   
           
        move([x0, 4,-h]) cylinder(r = d2/2, h = h*3);
        move([x0,24,-h]) cylinder(r = d2/2, h = h*3);
        //move([x0+10, 4,-h]) cylinder(r = d2/2, h = h*3);
        //move([x0+10,24,-h]) cylinder(r = d2/2, h = h*3);
        move([x0+20, 4,-h]) cylinder(r = d2/2, h = h*3);
        move([x0+20,24,-h]) cylinder(r = d2/2, h = h*3);
        move([x0+30-3, 4,-h]) cylinder(r = d2/2, h = h*3);
        move([x0+30-3,24,-h]) cylinder(r = d2/2, h = h*3);  
        //move([x0+40-3, 4,-h]) cylinder(r = d2/2, h = h*3);
        //move([x0+40-3,24,-h]) cylinder(r = d2/2, h = h*3); 
        move([x0+50-3, 4,-h]) cylinder(r = d2/2, h = h*3);
        move([x0+50-3,24,-h]) cylinder(r = d2/2, h = h*3);  
   
        //move([x0+60-6, 4,-h]) cylinder(r = d2/2, h = h*3);
        //move([x0+60-6,24,-h]) cylinder(r = d2/2, h = h*3); 
 
        move([x0+80-6, 4,-h]) cylinder(r = d2/2, h = h*3);
        move([x0+80-6,24,-h]) cylinder(r = d2/2, h = h*3);  
        
        move([a/2,b/2,-h]) cylinder(d = 6, h = h*3);
        
        if (a>wa1) {
           move([a/2-15,b/2,-h]) cylinder(d = 8, h = h*3);  
           move([a/2+15,b/2,-h]) cylinder(d = 8, h = h*3);
        }
        
        zrot(90) yrot(90) move([-5,-20,-h]) cylinder(d = 6, h = 60); 
        zrot(90) yrot(90) move([-5,-6.5,-h]) cylinder(d = 3.2, h = 60); 
        zrot(90) yrot(90) move([-5,-76.5,-h]) cylinder(d = 3.2, h = 60);            
        }
    }    
}



//dílek "Merkur"
module strip(a=10,n=5,tl=1.5,socket=true){
    difference()
    {
      cube([a,n*a,tl]);
      union() {
      for (i = [0:n-1]){
         xmove(a/2) ymove(a/2+i*a) cylinder(d=3.2, h = 5);}
        
          if (socket==true){            
             ymove(a-tl/2) cube([a/2,tl,tl*5]);
             ymove(a*(n-1)-tl/2) cube([a/2,tl,tl*5]);
          }
      }
  }
}


/*
distance(h=16);
difference() {
    cylinder(d=10, h=1.5);
    translate([0,0,0]) {
      cylinder(r=1.7, h=100);
    }
};
*/


//------------------------------------------
//distance(h);
//distance(h=3);
//distance(h=5);

//distance2x();
//distance2x(h2=10);

//conn_90();

 /*
 82/3=27
 27/2=54
 82
 */ 
//box_1(a=27,b=28,tl=1.5,h=10);
//box_1(a=54,b=28,tl=1.5,h=10);

//strip(n=5);
//strip(n=3,socket=false);