$fn = 90;

translate([23,0,0]) minutes();
translate([-23,0,0]) hours();

module hours(){
    translate([0,-15,0]){
        rotate([0,0,30]) translate([-1.1,26.8,0]) 
                text(text="1",size=2.5);
        rotate([0,0,24.7]) translate([-1.1,27.3,0]) 
                text(text="2",size=2.5);
        rotate([0,0,19]) translate([-1.1,27.7,0]) 
                text(text="3",size=2.5);
        rotate([0,0,14]) translate([-1.1,28.1,0]) 
                text(text="4",size=2.5);
        rotate([0,0,8.3]) translate([-1.1,28.4,0]) 
                text(text="5",size=2.5);
        rotate([0,0,2.5]) translate([-1.1,28.6,0]) 
                text(text="6",size=2.5);
        rotate([0,0,-3]) translate([-1.1,28.6,0]) 
                text(text="7",size=2.5);
        rotate([0,0,-8.5]) translate([-1.1,28.4,0]) 
                text(text="8",size=2.5);
        rotate([0,0,-14]) translate([-1.1,28.1,0]) 
                text(text="9",size=2.5);
        rotate([0,0,-18.7]) translate([-1.1,27.8,0]) 
                scale([0.6,1]) text(text="10",size=2.5);
        rotate([0,0,-24.7]) translate([-1.1,27.5,0]) 
                scale([0.6,1]) text(text="11",size=2.5);
        rotate([0,0,-29.3]) translate([-1.1,26.8,0]) 
                scale([0.6,1]) text(text="12",size=2.5);
    }

    translate([-2.5,3,0]) text(text="H",size=5);

    translate([0,-15,0]){
        for(i=[30:-5.45:-30]){
            rotate([0,0,i]) translate([-0.4,24.5,0]) square([0.8,2]);
        }
    }

    difference(){
        difference(){
            circle(20.5);
            face();
        }
        translate([0,-0.5,0]) scale(23/24) mech();
    }
}

module minutes(){
    translate([0,-15,0]){
        rotate([0,0,30]) translate([-1.1,27.3,0]) 
                text(text="0",size=2.5);
        rotate([0,0,17]) translate([-1.1,27.3,0]) 
                text(text="15",size=3);
        rotate([0,0,0.5]) translate([-1.1,27.3,0]) 
                text(text="30",size=3);
        rotate([0,0,-16.5]) translate([-1.1,27.3,0]) 
                text(text="45",size=2.8);
    }

    translate([-2.9,3,0]) text(text="M",size=5);

    translate([0,-15,0]){
        for(i=[30:-5.45:-30]){
            rotate([0,0,i]) translate([-0.4,24.5,0]) square([0.8,2]);
        }
    }

    difference(){
        difference(){
            circle(20.5);
            face();
        }
        translate([0,-0.5,0]) scale(23/24) mech();
    }
}

module face() difference(){
    circle(20);
    translate([-15,-3,0]) circle(1.5);
    translate([15,-3,0]) circle(1.5);
    mech();
    translate([0,-15,0]) dial();
}

module dial() difference(){
    circle(25);
    circle(24.34);
    rotate([0,0,-30]) translate([0,-30,0]) square([30,60]);
    rotate([0,0,30]) translate([-30,-30,0]) square([30,60]);
}

module mech(){
    translate([0,-8,0]) circle(8);
    hull(){
        translate([-7,-11,0]) circle(5);
        translate([7,-11,0]) circle(5);
        translate([-12,-21,0]) square([24,1]);
    }
}