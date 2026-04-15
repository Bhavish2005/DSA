class Robot {
public:
int w ;
int h;
int pos;
int perimeter;
bool moved;
    Robot(int width, int height) {
     w=width;
     h=height;
      perimeter=2*(w-1)+2*(h-1) ;
      pos=0; 
        moved=false;;
    }
    
    void step(int num) {
        moved=true;
        pos=(num+pos)%perimeter;
    }
    
    vector<int> getPos() {
        if(pos<=w-1)
        return {pos, 0};
        else if(pos<=w-1+h-1)
        return {w-1,pos-(w-1)};
        else if (pos <= 2 * (w - 1) + h - 1) {
           
            return {(w - 1) - (pos - (w + h - 2)), h - 1}; 
        }
        else {
           
            return {0, (h - 1) - (pos - (2 * w + h - 3))};
        }
    }
    
    string getDir() {
        if(!moved)
        return "East";
        if(pos==0)
        return "South";
        if(pos<=w-1)
        return "East";
        if (pos <= (w - 1) + (h - 1)) return "North";
        if (pos <= 2 * (w - 1) + (h - 1)) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
