[Rainmeter]
Update=1000

[Variables]
@include=#@#WeatherVariables.inc
Condition=Mostly cloudy
Temperature=56
DayOrNight=Day
Icon=Mostly cloudy
WeatherFinishAction=[!WriteKeyValue Variables Condition "[MeasureCurrentCondition]" "#@#Weather\WeatherParser.inc"][!WriteKeyValue Variables Icon "[MeasureCurrentIcon]" "#@#Weather\WeatherParser.inc"][!WriteKeyValue Variables Temperature "[MeasureCurrentTemperature]" "#@#Weather\WeatherParser.inc"][!WriteKeyValue Variables Icon "[MeasureCurrentIcon]" "#@#Weather\WeatherParser.inc"][!WriteKeyValue Variables DayOrNight "[MeasureDayOrNight]" "#@#Weather\WeatherParser.inc"][!SetVariable Condition "[MeasureCurrentCondition]" "Windows 11 Start Menu\TaskBar"][!SetVariable Temperature "[MeasureCurrentTemperature]" "Windows 11 Start Menu\TaskBar"][!SetVariable Icon "[MeasureCurrentIcon]" "Windows 11 Start Menu\TaskBar"][!SetVariable DayOrNight "[MeasureDayOrNight]" "Windows 11 Start Menu\TaskBar"][!UpdateMeter * "Windows 11 Start Menu\TaskBar"][!Redraw "Windows 11 Start Menu\TaskBar"]

[MeasureSiteWeather]
Measure=WebParser
URL=https://api.msn.com/weather/overview/user?apikey=j5i4gDqHL6nGYwx5wi5kRhXjtf2c5qgFX9fzfk0TOo&units=#Unit#
RegExp=(?siU)"cap":"(.*)",.*"temp":(.*).0,
UpdateRate=600
FinishAction=#WeatherFinishAction#
OnChangeAction=#WeatherFinishAction#
;OnDownloadErrorAction=[!SetOption MeterCurrentCondition MeasureName MeasureCurrentConditionCache][!SetOption MeterCurrentTemperature MeasureName MeasureCurrentTemperatureCache][!SetOption MeterDayOrNight MeasureName MeasuredayOrNightCache]

[MeasureSiteWeather2]
Measure=WebParser
URL=https://api.msn.com/weather/overview/user?apikey=j5i4gDqHL6nGYwx5wi5kRhXjtf2c5qgFX9fzfk0TOo&units=#Unit#
RegExp=(?siU)"daytime":"(.*)",
FinishAction=#WeatherFinishAction#
OnChangeAction=#WeatherFinishAction#
UpdateRate=600

______________Cache_________________

[MeasureCurrentConditionCache]
Measure=String
String=#Condition#

[MeasureCurrentIconCache]
Measure=String
String=#Icon#

[MeasureCurrentTemperatureCache]
Measure=String
String=#Temperature#

[MeasureDayOrNightCache]
Measure=String
String=#DayOrNight#

____________________________________

[MeasureCurrentCondition]
Measure=WebParser
URL=[MeasureSiteWeather]
StringIndex=1

[MeasureCurrentIcon]
Measure=WebParser
URL=[MeasureSiteWeather]
StringIndex=1
Subsitute="Moderate rain":"Rain",

[MeasureCurrentTemperature]
Measure=WebParser
URL=[MeasureSiteWeather]
StringIndex=2

[MeasureDayOrNight]
Measure=WebParser
URL=[MeasureSiteWeather2]
StringIndex=1
Substitute="d":"Day","n":"Night"
