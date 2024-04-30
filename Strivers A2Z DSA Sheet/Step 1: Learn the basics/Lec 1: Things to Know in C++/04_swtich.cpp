// https://www.naukri.com/code360/problems/switch-case-statement_8357244?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

double roundTo5Decimal(double value) {
    return round(value * 100000.0) / 100000.0;
}

double areaSwitchCase(int ch, vector<double> a) {
	// Write your code here
	double area = 0.0;
        switch (ch) {
        case 1:
          area = (3.14159265358979323846 * a[0] * a[0]);
          break;
        case 2:
          area = a[0] * a[1];
          break;
        }
        return roundTo5Decimal(area);

}
