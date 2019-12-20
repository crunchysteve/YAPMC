show="display";

if(show=="chassis"){
    chassis();
}

if(show=="lid"){
    rotate([90,0,90]) lid();
}

if(show=="display"){
    chassis();
    lid();
}

module lid() color("SaddleBrown") difference(){
    union(){
        cube([127,100,66]);
         scale([1,1,0.5]) translate([0,15,0]) 
                rotate([0,90,0]) cylinder(d=10,h=5.5);
         scale([1,1,0.5]) translate([0,85,0]) 
                rotate([0,90,0]) cylinder(d=10,h=5.5);
         scale([1,1,0.5]) translate([121.5,15,0]) 
                rotate([0,90,0]) cylinder(d=10,h=5.5);
         scale([1,1,0.5]) translate([121.5,85,0]) 
                rotate([0,90,0]) cylinder(d=10,h=5.5);
    }
    translate([5.5,-1,-1]) cube([116,102,61.5]);
    translate([-1,18,7.5]) rotate([0,90,0]) cylinder(d=5,h=129);
    translate([-1,88,7.5]) rotate([0,90,0]) cylinder(d=5,h=129);
    for(i=[18:9:45]){
        translate([-1,30,i]) rotate([0,90,0]) hull(){
            cylinder(d=6,h=129);
            translate([0,50,0]) cylinder(d=4,h=129);
        }
    }
}

module chassis() color("Goldenrod") translate([6,8,0]){
    difference(){
        cube([115,90,60]);                      //  case
        translate([-1,3,3]) cube([117,84,60]);
    
                                                //  left
        translate([28,-1,30]) rotate([-90,0,0]) cylinder(d=46,h=5);
        translate([9.5,-1,11.5]) rotate([-90,0,0]) cylinder(d=4,h=5);
        translate([9.5,-1,48.5]) rotate([-90,0,0]) cylinder(d=4,h=5);
        translate([46.5,-1,11.5]) rotate([-90,0,0]) cylinder(d=4,h=5);
        translate([46.5,-1,48.5]) rotate([-90,0,0]) cylinder(d=4,h=5);
    
                                                //  buttons
        translate([57.5,-1,39.5]) rotate([-90,0,0]) cylinder(d=7,h=5);
        translate([57.5,-1,20.5]) rotate([-90,0,0]) cylinder(d=7,h=5);
    
                                                //  LED
        translate([57.5,-1,9.5]) rotate([-90,0,0]) cylinder(d=5,h=5);
        
                                                //  right
        translate([87,-1,30]) rotate([-90,0,0]) cylinder(d=46,h=5);
        translate([68.5,-1,11.5]) rotate([-90,0,0]) cylinder(d=4,h=5);
        translate([68.5,-1,48.5]) rotate([-90,0,0]) cylinder(d=4,h=5);
        translate([105.5,-1,11.5]) rotate([-90,0,0]) cylinder(d=4,h=5);
        translate([105.5,-1,48.5]) rotate([-90,0,0]) cylinder(d=4,h=5);
    }
    difference(){
        union(){
            cube([3,90,12]);
            translate([112,0,0]) cube([3,90,12]);
        }
        translate([-1,10,7.5]) rotate([0,90,0]) cylinder(d=3.5,h=117);
        translate([-1,80,7.5]) rotate([0,90,0]) cylinder(d=3.5,h=117);
    }
}