$fn = 60; //details

x0 = 7;
ox = 2.5;
o60 = 60;
o40 = 40;

module boff_holes3() {
    translate([x0,15,-1]) {
    cylinder(d=3.9,20);
    translate([28,0,0]) cylinder(d=3.9,h=20);
    translate([28+28,0,0]) cylinder(d=3.9,h=20);
    }
    translate([ox+5,5,0]) cylinder(d=3,h=5);
    translate([ox+o40,5,0]) cylinder(d=3,h=5);
    translate([ox+o60,5,0]) cylinder(d=3,h=5);

    
}

module boff0() {
    difference(){
    union(){
         cube([70,20,0.9]);
         translate([ox+5,5,0]) cylinder(d=5,h=3);
        translate([ox+o40,5,0]) cylinder(d=5,h=3);
         translate([ox+o60,5,0]) cylinder(d=5,h=3);
    }
        
    boff_holes3();
    }   
}
    
    
boff0();