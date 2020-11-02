using namespace std;

template <typename T>
class Interval
{
private:
    bool valid;
    T upperBound;
    T lowerBound;

public:
    Interval() : valid(false) {}

    Interval(T lower, T upper) : valid(true)
    {
        if (upper < lower)
        {
            upperBound = lower;
            lowerBound = upper;
        }
        else
        {
            upperBound = upper;
            lowerBound = lower;
        }
    }

    virtual ~Interval() {}

    virtual T getUpperBound()
    {
        return upperBound;
    }

    virtual void setUpperBound(T upper)
    {
        upperBound = upper;

        if (isValid())
        {
            valid = true;
        }
        else
        {
            valid = false;
        }
    }

    virtual T getLowerBound()
    {
        return lowerBound;
    }

    virtual void setLowerBound(T lower)
    {
        lowerBound = lower;

        if (isValid())
        {
            valid = true;
        }
        else
        {
            valid = false;
        }
    }

    virtual void setInterval(T lower, T upper)
    {
        if (upper < lower)
        {
            upperBound = lower;
            lowerBound = upper;
        }
        else
        {
            upperBound = upper;
            lowerBound = lower;
        }

        if (isValid())
        {
            valid = true;
        }
        else
        {
            valid = false;
        }
    }

    virtual T *getInterval()
    {
        T arr[2];

        arr[0] = lowerBound;
        arr[1] = upperBound;

        return arr;
    }

    virtual bool isValid()
    {
        return lowerBound <= upperBound;
    }

    virtual void print()
    {
        cout << "[" << lowerBound << "," << upperBound << "]" << endl;
    }

    virtual Interval operator+(Interval b)
    {
        Interval interval(lowerBound + b.lowerBound, upperBound + b.upperBound);
        return interval;
    }

    virtual Interval operator-(Interval b)
    {
        Interval interval(lowerBound - b.lowerBound, upperBound - b.upperBound);
        return interval;
    }

    virtual Interval operator*(Interval b)
    {
        Interval interval(lowerBound * b.lowerBound, upperBound * b.upperBound);
        return interval;
    }

    virtual Interval operator/(Interval b)
    {
        if (b.lowerBound != 0 || b.upperBound != 0)
        {
            Interval validInterval(lowerBound / b.lowerbound, upperBound / b.upperBound);
            return validInterval;
        }
        else
        {
            Interval invalidInterval();
            return invalidInterval;
        }
    }

    virtual Interval operator-()
    {
        Interval interval(-upperBound, -lowerBound);

        return interval;
    }
};

int main(int argc, char *argv[])
{
    Interval<int> i1(5, 10);
    // Interval i2(2, 3);

    // Interval i1i2 = i1 + i2;

    return 0;
}