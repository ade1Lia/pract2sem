#include <iostream>
#include <math.h>



class KinematicSolver
{
private:
    double m_alpha;
    double m_beta;

    double m_l1;
    double m_l2;
    double m_m[2] = { NULL };
public:

    void set()
    {
        std::cout<<"L1:"<< std::endl;
        std::cin >> m_l1;
        std::cout<<"L2:"<< std::endl;
        std::cin >> m_l2;
        std::cout<<"x and y:"<< std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::cin >> m_m[i];
        }
    }

    int check()
    {
        if ((m_l1 == NULL) ||  (m_l2 == NULL))
        {
            std::cout << "incorrect length" << std::endl;
            return 0;
        }
        if (m_m[0] == NULL || m_m[1] == NULL)
        {
            std::cout << "incorrect m(x,y)" << std::endl;
            return 0;
        }
        if (sqrt(m_m[0] * m_m[0] + m_m[1] * m_m[1])>m_l1+m_l2) {
            std::cout << "coordinate far" << std::endl;
            return 0;
        }
        return 1;

    }

    void Solve()
    {
        double l3 = sqrt(m_m[0] * m_m[0] + m_m[1] * m_m[1]);
        double a3 = acos((pow(m_l2,2)+pow(m_l1,2)-pow(l3,2))/(2*m_l1*m_l2));
        m_beta = 180-(a3*180)/3.141592653589793;
        double a2 = acos((pow(l3,2)+pow(m_l1,2)-pow(m_l2,2))/(2*m_l1*l3));
        double gamma = acos(m_m[0]/l3);
        m_alpha=(a2+gamma)*180/3.141592653589793;
        std::cout <<"alpha: "<< m_alpha << " beta: " << m_beta;
    }

};

int main()
{
    KinematicSolver a;
    a.set();
    if(a.check()==1)
        a.Solve();
    return 0;
}