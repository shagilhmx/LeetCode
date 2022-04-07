class ParkingSystem {
    int carTypeArray[3];
public:
    ParkingSystem(int big, int medium, int small) {
        carTypeArray[0] = big;
        carTypeArray[1] = medium;
        carTypeArray[2] = small;
    }
    
    bool addCar(int carType) {
        int top = carTypeArray[carType - 1];
        carTypeArray[carType - 1] = top - 1;
        return top > 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */