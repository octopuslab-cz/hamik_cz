////include <../BOSL/constants.scad>
use <../BOSL/transforms.scad>
include <hexagone.scad>

$fn = 60; //details

x0 = 7;
bof = 27.5; //28
bofd = 3.99;
ox = 5;
o60 = 60;
o40 = 40;

module boff_holes3() {
    translate([x0,15,-1]) {
    cylinder(d=bofd,20);
    xmove(bof) cylinder(d=bofd,h=20);
    xmove(bof*2) cylinder(d=bofd,h=20);
    }
    translate([ox,5,0]) cylinder(d=3,h=5);
    translate([ox+o40,5,0]) cylinder(d=3,h=5);
    translate([ox+o60,5,0]) cylinder(d=3,h=5);   
}

module boff0() {
    difference(){
    union(){
        cube([70,20,0.9]);
        ymove(3.5) cube([70,3,1.5]);
        translate([ox,5,0]) cylinder(d=5,h=3);
        translate([ox+o40,5,0]) cylinder(d=5,h=3);
        translate([ox+o60,5,0]) cylinder(d=5,h=3);
    }        
    boff_holes3();
    }   
}
    
    
boff0();
