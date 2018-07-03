
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
#include "Calendar.h"
#include "config/IniApi.h"
#include "config/SysConfig.h"
#include "csv-reader.h"
#include "Logger.h"
#include <chrono>
#include <ctime>
#include <ratio>

using namespace jzs;
using namespace std;
using std::chrono::system_clock;

Calendar* Calendar::getInst()
{
    static Calendar* g_instance;
    if (g_instance) return g_instance;
    return (g_instance = new Calendar());
}

Calendar::~Calendar()
{
}

Calendar::Calendar()
{
    // load calendar
    {
        int today = TimeUtil::date();
        string path = SysConfig::getEtcDir() + "/calendar.csv";
        CSVReader reader(path);
        reader.LoadFile();
        int i = 0;
        // skip first line 
        // "date"
        for (i = 1; i < reader.get_num_rows(); i++) {
            int dt = atoi(reader.rows[i][0].c_str());
            if (dt >= today) {
                break;
            }
        }
        m_tradedays.push_back(atoi(reader.rows[i-1][0].c_str()));
        m_tradedays.push_back(atoi(reader.rows[i][0].c_str()));
        m_tradedays.push_back(atoi(reader.rows[i+1][0].c_str()));
    }
}

// ���ݵ�ǰ���ں͸���ʱ���Ƴ�������
int Calendar::GetTradeDay(MillisTime time, int jzcode)
{
    int date = TimeUtil::date();
    return GetTradeDayFromActionDay(date, time, jzcode);    
}

int Calendar::GetDate()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    return (tm->tm_year + 1900) * 10000 + (tm->tm_mon + 1) * 100 + tm->tm_mday;
}



int Calendar::GetTradeDayFromActionDay(int date, MillisTime time, int jzcode)
{
    if (date < m_tradedays.front() || date > m_tradedays.back()) {
        LOG(ERROR) << "Error date! " << endl;
        return -1;
    }
    if (TimeUtil::isInNightTime(time)) {
        if (time < TimeUtil::day_begin_time_millis) {
            //�賿ҹ�̵Ľ�����Ϊ��һ�����ڣ�����������ڣ������գ��ɽ��յĽ�����
            for (auto it = m_tradedays.begin(); it != m_tradedays.end(); ++it) {
                if (*it >= date) {
                    return (*it);
                }
            }
        }
        else {
            //����ҹ�̵Ľ�����Ϊ��һ�����ڳɽ��յĽ�����
            for (auto it = m_tradedays.begin(); it != m_tradedays.end(); ++it) {
                if (*it > date) {
                    return(*it);
                }
            }
        }
    }
    else {
        //����: ��������³ɽ��ռ�Ϊ������.
        for (auto it = m_tradedays.begin(); it != m_tradedays.end(); ++it) {
            if (*it == date) {
                return(*it);
            }
        }
        //�������ĩ��������Ϊ��һ�����ڳɽ��յĽ����գ�������Ϊ������״̬
        LOG(INFO) << "Weekend startup time for qms!" << endl;
        for (auto it = m_tradedays.begin(); it != m_tradedays.end(); ++it) {
            if (*it > date) {
                return(*it);
            }
        }
    }
    LOG(ERROR) << "Wrong startup time for qms!" << endl;
    return -1;
}

int Calendar::GetActionDayFromTradeDay(int date, MillisTime time, int jzcode)
{
    if (date < m_tradedays.front() || date > m_tradedays.back()) {
        LOG(ERROR) << "Error date! " << endl;
        return -1;
    }
    if (time < TimeUtil::night_begin_time_millis && 
        time > TimeUtil::day_begin_time_millis) {
        return date;
    }
    else {
        int i = 0;
        for (; i < m_tradedays.size(); i++) {
            if (m_tradedays[i] == date) {
                break;
            }
        }
        if (i == 0 || i == m_tradedays.size()) {
            LOG(ERROR) << "Error date! " << endl;
            return -1;
        }

        if (time >= TimeUtil::night_begin_time_millis) {
            //����ʱ�� ǰһ������Ϊ�ɽ���
            return m_tradedays[i - 1];
        }
        if (time <= TimeUtil::day_begin_time_millis) {
            //�賿ʱ�� ǰһ�����յ���һ����Ȼ��
            return GetNextDay(m_tradedays[i - 1]);
        }
    }
    LOG(ERROR) << "Error date! " << endl;
    return -1;
}

int Calendar::GetNextDay(int today)
{
    tm td;
    td.tm_sec = td.tm_min = td.tm_hour = 10;
    td.tm_year = today / 10000;
    td.tm_mon = today % 10000 / 100;
    td.tm_mday = today % 100;   
    td.tm_year -= 1900;
    td.tm_mon -= 1;
    tm tm = td;
    GetNextDay(td, tm);
    return ((tm.tm_year + 1900) * 10000 + (tm.tm_mon + 1) * 100 + tm.tm_mday);
}
int Calendar::GetPreDay(int today)
{
    tm td;
    td.tm_sec = td.tm_min = td.tm_hour = 10;
    td.tm_year = today / 10000;
    td.tm_mon = today % 10000 / 100;
    td.tm_mday = today % 100;   
    td.tm_year -= 1900;
    td.tm_mon -= 1;
    tm tm = td;
    GetPreDay(td, tm);
    return ((tm.tm_year + 1900) * 10000 + (tm.tm_mon + 1) * 100 + tm.tm_mday);
}

void Calendar::GetNextDay(struct tm& td, struct tm& tm)
{
    GetNextTime(td, tm, TimeUtil::millis_per_day / 1000);
}
void Calendar::GetPreDay(struct tm& td, struct tm& tm)
{
    GetPreTime(td, tm, TimeUtil::millis_per_day / 1000);
}

void Calendar::GetPreTime(struct tm& today, struct tm& tommrow, long seconds)
{
    std::time_t td = mktime(&today);
    system_clock::time_point td_point = system_clock::from_time_t(td);    
    std::time_t now_c = std::chrono::system_clock::to_time_t(td_point - std::chrono::seconds(seconds));
    tm* tm = localtime(&now_c);
    tommrow = *tm;
}
void Calendar::GetNextTime(struct tm& today, struct tm& tommrow, long seconds)
{
    std::time_t td = mktime(&today);
    system_clock::time_point td_point = system_clock::from_time_t(td);   
    std::time_t now_c = std::chrono::system_clock::to_time_t(td_point + std::chrono::seconds(seconds));
    tm* tm = localtime(&now_c);
    tommrow = *tm; 
}
/*
void Calendar::GetNextDay(const struct tm& td, struct tm& tm)
{
    int m[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (td.tm_year % 4 == 0 && td.tm_year % 100 != 0 || td.tm_year % 400 == 0)
        m[1]++;
    tm.tm_year = td.tm_year;
    if (td.tm_mon == 12 && td.tm_mday == 31) {
        tm.tm_year = td.tm_year + 1;  
        tm.tm_mon = 1;
    }
    else {
        tm.tm_mon = (td.tm_mon + td.tm_mday / m[td.tm_mon - 1]);
    }
    tm.tm_mday = td.tm_mday % m[td.tm_mon - 1] + 1;    
    tm.tm_wday += 1;
    tm.tm_wday %= 7;
    tm.tm_yday += 1;
    if (m[1] == 29)
        tm.tm_yday %= 366;
    else
        tm.tm_yday %= 365;
}
*/
//��һ�� �������Ϊ��׼������ e. 2015-10-01
/*
void Calendar::GetPreDay(const struct tm& td, struct tm& tm)
{
    int m[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    tm.tm_mday = td.tm_mday;
    tm.tm_mon = td.tm_mon;
    tm.tm_year = td.tm_year;
    tm.tm_wday = td.tm_wday;
    tm.tm_mday -= 1;
    if (tm.tm_mday == 0) {
        tm.tm_mon -= 1;
        if (tm.tm_mon == 0) {
            tm.tm_year -= 1;
            tm.tm_mon = 12;
        }
        if (td.tm_year % 4 == 0 && td.tm_year % 100 != 0 || td.tm_year % 400 == 0)
            m[1]++;
        tm.tm_mday = m[tm.tm_mon - 1];
    }
    if (tm.tm_wday == 0) {
        tm.tm_wday = 6;
    }
    else {
        tm.tm_wday -= 1;
    }
}
*/
//�õ����ڼ������ò��չ�ʽ
int Calendar::GetWeekDay(int yymmdd)
{
    unsigned int iYear = yymmdd / 10000;
    unsigned int iMonth = (yymmdd / 100) % 100;
    unsigned int iDay = (yymmdd % 100);
    int iWeek = 0;
    unsigned int y = 0, c = 0, m = 0, d = 0;

    if (iMonth == 1 || iMonth == 2)
    {
        c = (iYear - 1) / 100;
        y = (iYear - 1) % 100;
        m = iMonth + 12;
        d = iDay;
    }
    else
    {
        c = iYear / 100;
        y = iYear % 100;
        m = iMonth;
        d = iDay;
    }

    iWeek = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;    //���չ�ʽ
    iWeek = iWeek >= 0 ? (iWeek % 7) : (iWeek % 7 + 7);    //iWeekΪ��ʱȡģ

    return iWeek;
}



