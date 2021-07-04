Peer funEsp;
json data;
json mdata;
void pressedP1();
void pressedP2();
void pressedP3();
void pressedP4();

// void releasedP1();
void releasedP2();
// void releasedP3();
// void releasedP4();

void pressedMotor();
// void releasedMotor();

class function
{
public:
    button *square, *cross, *triangle, *circle, *l1;
    String pneumatic1, pneumatic2, pneumatic3, pneumatic4, motor;
    int send_value1=0,send_value4=0,send_value3=0,send_valueM=0;

    function(button *square, button *cross, button *triangle, button *circle, button *l1)
    {
        this->square = square;
        this->cross = cross;
        this->triangle = triangle;
        this->circle = circle;
        this->l1 = l1;
        attachAll();
        storeObject();
    }

    void attachAll()
    {
        // triangle->attachAnalogChange(analogUp);

        cross->attachPress(pressedP1);
        triangle->attachPress(pressedP2);
        circle->attachPress(pressedP3);
        square->attachPress(pressedP4);
        l1->attachPress(pressedMotor);

        // cross->attachRelease(releasedP1);
        triangle->attachRelease(releasedP2);
        // circle->attachRelease(releasedP3);
        // square->attachRelease(releasedP4);
        // l1->attachRelease(releasedMotor);
    }
    void f_pressedP1()
    {
        if(send_value1==0){
            send_value1=1;
        }
        else if(send_value1==1)
        {
            send_value1=0;
        }
       sendSingleData("p1",send_value1);
    }
    void f_pressedP2()
    {
        sendSingleData("p2",1);
    }
    void f_pressedP3()
    {
        if(send_value3==0){
            send_value3=1;
        }
        else if(send_value3==1)
        {
            send_value3=0;
        }
        sendSingleData("p3",send_value3);
    }
    void f_pressedP4()
    {
        if(send_value4==0){
            send_value4=1;
        }
        else if(send_value4==1)
        {
            send_value4=0;
        }
        sendSingleData("p4",send_value4);
    }

    // void f_releasedP1()
    // {
    //     sendSingleData("p1",0);  
    // }
    void f_releasedP2()
    {
        sendSingleData("p2",0);
    }
    // void f_releasedP3()
    // {
    //     sendSingleData("p3",0);
    // }
    // void f_releasedP4()
    // {
    //     sendSingleData("p4",0);
    // }
    void f_pressedMotor()
    {
        if(send_valueM==0){
            send_valueM=1;
        }
        else if(send_valueM==1)
        {
            send_valueM=0;
        }
        sendSingleData("motor",send_valueM);
    }
    // void f_releasedMotor()
    // {
    //     sendSingleData("motor",0);
    // }
    void sendSingleData(String name,int value)
    {
        data.clear();
        data.addUnit(name,value);
        Serial.println("data" + String(data.getString()));
        funEsp.send(data);
        data.clear();
    }
    /*
    void sendData()
    {
        data.clear();
        // mdata.clear();
        data.addUnit("p1", pneumatic1);
        data.addUnit("type", "myfun");
        data.addUnit("p2", pneumatic2);
        data.addUnit("type", "myfun");
        data.addUnit("p3", pneumatic3);
        data.addUnit("type", "myfun");
        data.addUnit("p4", pneumatic4);
        data.addUnit("type", "myfun");
        // mdata.addUnit("motor", motor);
        // mdata.addUnit("type", "motorFun");
        Serial.println("Before data:  " + String(data.getString()));
        // Serial.println("Before mdata:  "+ String(mdata.getString()));
        funEsp.send(data);
        // funEsp.send(mdata);
        Serial.println("After data:  " + String(data.getString()));
        // Serial.println("After mdata:  "+ String(mdata.getString()));
        data.clear();
        // mdata.clear();
        Serial.println("Clear data :  " + String(data.getString()));
        // Serial.println("Clear mdata:  " + String(mdata.getString()));
        // Serial.println("p1" + String(pneumatic1) + "  p2" + String(pneumatic2) + "p3" + String(pneumatic3) + "p4" + String(pneumatic4));
    }
    */
    void storeObject();
};

function f(&square, &cross, &triangle, &circle, &l1);

function *functionObject;

void function::storeObject()
{
    functionObject = this;
}


void pressedP1()
{
    functionObject->f_pressedP1();
}
void pressedP2()
{
    functionObject->f_pressedP2();
}
void pressedP3()
{
    functionObject->f_pressedP3();
}
void pressedP4()
{
    functionObject->f_pressedP4();
}

// void releasedP1()
// {
//     functionObject->f_releasedP1();
// }
void releasedP2()
{
    functionObject->f_releasedP2();
}
// void releasedP3()
// {
//     functionObject->f_releasedP3();
// }
// void releasedP4()
// {
//     functionObject->f_releasedP4();
// }


void pressedMotor()
{
    functionObject->f_pressedMotor();
}
// void releasedMotor()
// {
//     functionObject->f_releasedMotor();
// }