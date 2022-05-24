//#include "Hotel.h"
//#include "BedAndBreakfast.h"
//#include "Room.h"
//#include "Inspector.h"
//#include <iostream>
//
//using namespace std;
//
//int main2() {
//
//    cout << "Testing Hotel Methods\n" << endl;
//    Hotel h1 = Hotel();
//    Hotel h2 = Hotel();
//    h1.setAll(true);
//    h2.setAll(true);
//
//    Room r1 = Room();
//    r1.setAll(true);
//
//    cout << "printHotel method\n" << endl;
//    h1.printHotel();
//    cout << endl;
//    h1.setStaff("Bad");
//    h1.setHasConcierge(false);
//    h1.setHasRestaurant(false);
//    h1.printHotel();
//
//    h1.setAll(true);
//
//    if(!(h1.getHasConcierge() && h1.getHasGym() && h1.getHasRestaurant() && h1.getHasSpa() && h1.getStaff() == "Excellent")){
//        cout << "FAILED setAll testcase" << endl;
//    }
//    h1.setAll(false);
//    if(h1.getHasConcierge() || h1.getHasGym() || h1.getHasRestaurant() || h1.getHasSpa() || h1.getStaff() != "Bad"){
//        cout << "FAILED setAll testcase 2" << endl;
//    }
//    if(h1 == h2){
//       cout << "FAILED == testcase" << endl;
//    }
//    h1.setAll(true);
//    if(!(h1 == h2)){
//        cout << "FAILED == testcase 2" << endl;
//    }
//
//    cout << "\nTesting BedAndBreakfast Methods\n" << endl;
//    BedAndBreakfast b1 = BedAndBreakfast();
//    BedAndBreakfast b2 = BedAndBreakfast();
//    b1.setAll(true);
//    b2.setAll(true);
//
//    if(!(b1 == b2)){
//        cout << "FAILED == testcase" << endl;
//    }
//    b2.setIsAffordable(false);
//    b2.setIsAntique(false);
//    b2.setIsRomantic(false);
//    if(b1 == b2){
//        cout << "FAILED == testcase 2" << endl;
//    }
//    cout << "printBedAndBreakfast method\n" << endl;
//    b1.printBedAndBreakfast(r1);
//    cout << endl;
//    b1.setAll(false);
//    b1.setHasRestaurant(true);
//    b1.setIsRomantic(true);
//    b1.setIsAffordable(true);
//    b1.setStaff("Good");
//    b1.printBedAndBreakfast(r1);
//
//    cout << "\nTesting Inspect Class" << endl;
//
//    //setALl true should produce 5 stars
//    Inspector::inspect(h1, r1);
//    Inspector::inspect(b1, r1);
//    //setAll false should produce 1 star
//    h1.setAll(false);
//    b1.setAll(false);
//    r1.setAll(false);
//    Inspector::inspect(h1, r1);
//    Inspector::inspect(b1, r1);
//    h1.printHotel(r1);
//
//    return 0;
//}