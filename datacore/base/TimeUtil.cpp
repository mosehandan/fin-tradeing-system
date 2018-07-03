
/***********************************************************************

Copyright 2017 quantOS-org

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at:

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

***********************************************************************/
#include "TimeUtil.h"
#include "config/IniApi.h"
#include "config/SysConfig.h"

using namespace std;
using namespace jzs;
// ��ҹ��ʱ��Ƚ�
// t1 < t2 => -1; t1 == t2 => 0; t1 > t2 => 1;
int TimeUtil::compare_time_new(const MillisTime& t1, const MillisTime& t2)
{
    if (t1 > night_begin_time_millis) {
        // t1 is night time
        if (t2 > night_begin_time_millis) {
            if (t1 > t2) {
                return 1;
            }
            else if (t1 == t2) {
                return 0;
            }
            else {
                return -1;
            }
        }
        else {
            // t2 is not night time;
            return -1;
        }
    }
    else {
        // t1 is not night time
        if (t2 < night_begin_time_millis) {
            //t2 is not night time
            if (t1 > t2) {
                return 1;
            }
            else if (t1 == t2) {
                return 0;
            }
            else {
                return -1;
            }
        }
        else {
            // t2 is night time;
            return 1;
        }
    }
}

// ��ҹ��ʱ��Ƚ�
// t1 < t2 => -1; t1 == t2 => 0; t1 > t2 => 1;
int TimeUtil::compare_time_night(const MillisTime& t1, const MillisTime& t2)
{
    //һ�������ʱ��Σ�˳��Ϊ���ϣ�18-24�� �賿�� 0-6�� ���죺6-18 
    if (t1 > night_begin_time_millis) {
        //t1 ������ʱ�֣�18-24
        if (t2 > night_begin_time_millis) {

            //t2Ҳ������ʱ��
            if (t1 > t2) {
                return 1;
            }
            else if (t1 == t2) {
                return 0;
            }
            else {
                return -1;
            }
        }
        else {
            //t2���賿�����: 0-18. t1 < t2
            return -1;
        }
    }
    else if (t1 < day_begin_time_millis){
        // t1�賿ʱ�� 0-6
        if (t2 > night_begin_time_millis) {
            // t2���� 18-24
            return 1;
        }
        else if (t2 < day_begin_time_millis) {
            //t2 �賿 0-6
            if (t1 > t2) {
                return 1;
            }
            else if (t1 == t2) {
                return 0;
            }
            else {
                return -1;
            }
        }
        else {
            // t2���죺 6-18. t1 < t2
            return -1;
        }
    }
    else {
        //t1 ����ʱ�� 6-18
        if (t2 < day_begin_time_millis || t2 > night_begin_time_millis) {
            //t2 ���ϻ� �賿 18-6. t1>t2
            return 1;
        }
        else {
            if (t1 > t2) {
                return 1;
            }
            else if (t1 == t2) {
                return 0;
            }
            else {
                return -1;
            }
        }
    }
}


