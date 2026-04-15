class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
         int x=0;
          int y=0;
          int max_dis=0;
          int n=commands.size();
          int curr_dir=0;
          set<pair<int ,int >>s;
          for(int i=0;i<obstacles.size();i++){
            s.insert({obstacles[i][0], obstacles[i][1]});
          }
          vector<int>x_dir={0,1,0,-1};
          vector<int>y_dir={1,0,-1,0};
          for(int i=0;i<n;i++){
            if(commands[i]==-1){
                curr_dir=(curr_dir+1)%4;
            }
            else if(commands[i]==-2)
            curr_dir=(curr_dir+3)%4;

            else{
                for(int j=0;j<commands[i];j++){
                    int next_x=x+x_dir[curr_dir];
                    int next_y=y+y_dir[curr_dir];
                    if(s.count({next_x, next_y}))
                    break;
                    x=next_x;
                    y=next_y;
                    max_dis=max(max_dis,x*x+y*y);
                }
            }
          }
          return max_dis;
    }
};
