﻿#include "qtcommon.h"
#include "translatewrapper.h"
#include "network.h"

extern const wchar_t* TRANSLATION_ERROR;

const char* TRANSLATION_PROVIDER = "Google Translate";
const char* GET_API_KEY_FROM = "https://console.cloud.google.com/marketplace/product/google/translate.googleapis.com";
extern const QStringList languagesTo
{
   "Afrikaans",
   "Albanian",
   "Amharic",
   "Arabic",
   "Armenian",
   "Azerbaijani",
   "Basque",
   "Belarusian",
   "Bengali",
   "Bosnian",
   "Bulgarian",
   "Catalan",
   "Cebuano",
   "Chichewa",
   "Chinese (Simplified)",
   "Chinese (Traditional)",
   "Corsican",
   "Croatian",
   "Czech",
   "Danish",
   "Dutch",
   "English",
   "Esperanto",
   "Estonian",
   "Filipino",
   "Finnish",
   "French",
   "Frisian",
   "Galician",
   "Georgian",
   "German",
   "Greek",
   "Gujarati",
   "Haitian Creole",
   "Hausa",
   "Hawaiian",
   "Hebrew",
   "Hindi",
   "Hmong",
   "Hungarian",
   "Icelandic",
   "Igbo",
   "Indonesian",
   "Irish",
   "Italian",
   "Japanese",
   "Javanese",
   "Kannada",
   "Kazakh",
   "Khmer",
   "Kinyarwanda",
   "Korean",
   "Kurdish (Kurmanji)",
   "Kyrgyz",
   "Lao",
   "Latin",
   "Latvian",
   "Lithuanian",
   "Luxembourgish",
   "Macedonian",
   "Malagasy",
   "Malay",
   "Malayalam",
   "Maltese",
   "Maori",
   "Marathi",
   "Mongolian",
   "Myanmar (Burmese)",
   "Nepali",
   "Norwegian",
   "Odia (Oriya)",
   "Pashto",
   "Persian",
   "Polish",
   "Portuguese",
   "Punjabi",
   "Romanian",
   "Russian",
   "Samoan",
   "Scots Gaelic",
   "Serbian",
   "Sesotho",
   "Shona",
   "Sindhi",
   "Sinhala",
   "Slovak",
   "Slovenian",
   "Somali",
   "Spanish",
   "Sundanese",
   "Swahili",
   "Swedish",
   "Tajik",
   "Tamil",
   "Tatar",
   "Telugu",
   "Thai",
   "Turkish",
   "Turkmen",
   "Ukrainian",
   "Urdu",
   "Uyghur",
   "Uzbek",
   "Vietnamese",
   "Welsh",
   "Xhosa",
   "Yiddish",
   "Yoruba",
   "Zulu",
}, languagesFrom = languagesTo;
extern const std::unordered_map<std::wstring, std::wstring> codes
{
	{ { L"Afrikaans" }, { L"af" } },
	{ { L"Albanian" }, { L"sq" } },
	{ { L"Amharic" }, { L"am" } },
	{ { L"Arabic" }, { L"ar" } },
	{ { L"Armenian" }, { L"hy" } },
	{ { L"Azerbaijani" }, { L"az" } },
	{ { L"Basque" }, { L"eu" } },
	{ { L"Belarusian" }, { L"be" } },
	{ { L"Bengali" }, { L"bn" } },
	{ { L"Bosnian" }, { L"bs" } },
	{ { L"Bulgarian" }, { L"bg" } },
	{ { L"Catalan" }, { L"ca" } },
	{ { L"Cebuano" }, { L"ceb" } },
	{ { L"Chichewa" }, { L"ny" } },
	{ { L"Chinese (Simplified)" }, { L"zh-CN" } },
	{ { L"Chinese (Traditional)" }, { L"zh-TW" } },
	{ { L"Corsican" }, { L"co" } },
	{ { L"Croatian" }, { L"hr" } },
	{ { L"Czech" }, { L"cs" } },
	{ { L"Danish" }, { L"da" } },
	{ { L"Dutch" }, { L"nl" } },
	{ { L"English" }, { L"en" } },
	{ { L"Esperanto" }, { L"eo" } },
	{ { L"Estonian" }, { L"et" } },
	{ { L"Filipino" }, { L"tl" } },
	{ { L"Finnish" }, { L"fi" } },
	{ { L"French" }, { L"fr" } },
	{ { L"Frisian" }, { L"fy" } },
	{ { L"Galician" }, { L"gl" } },
	{ { L"Georgian" }, { L"ka" } },
	{ { L"German" }, { L"de" } },
	{ { L"Greek" }, { L"el" } },
	{ { L"Gujarati" }, { L"gu" } },
	{ { L"Haitian Creole" }, { L"ht" } },
	{ { L"Hausa" }, { L"ha" } },
	{ { L"Hawaiian" }, { L"haw" } },
	{ { L"Hebrew" }, { L"iw" } },
	{ { L"Hindi" }, { L"hi" } },
	{ { L"Hmong" }, { L"hmn" } },
	{ { L"Hungarian" }, { L"hu" } },
	{ { L"Icelandic" }, { L"is" } },
	{ { L"Igbo" }, { L"ig" } },
	{ { L"Indonesian" }, { L"id" } },
	{ { L"Irish" }, { L"ga" } },
	{ { L"Italian" }, { L"it" } },
	{ { L"Japanese" }, { L"ja" } },
	{ { L"Javanese" }, { L"jw" } },
	{ { L"Kannada" }, { L"kn" } },
	{ { L"Kazakh" }, { L"kk" } },
	{ { L"Khmer" }, { L"km" } },
	{ { L"Kinyarwanda" }, { L"rw" } },
	{ { L"Korean" }, { L"ko" } },
	{ { L"Kurdish (Kurmanji)" }, { L"ku" } },
	{ { L"Kyrgyz" }, { L"ky" } },
	{ { L"Lao" }, { L"lo" } },
	{ { L"Latin" }, { L"la" } },
	{ { L"Latvian" }, { L"lv" } },
	{ { L"Lithuanian" }, { L"lt" } },
	{ { L"Luxembourgish" }, { L"lb" } },
	{ { L"Macedonian" }, { L"mk" } },
	{ { L"Malagasy" }, { L"mg" } },
	{ { L"Malay" }, { L"ms" } },
	{ { L"Malayalam" }, { L"ml" } },
	{ { L"Maltese" }, { L"mt" } },
	{ { L"Maori" }, { L"mi" } },
	{ { L"Marathi" }, { L"mr" } },
	{ { L"Mongolian" }, { L"mn" } },
	{ { L"Myanmar (Burmese)" }, { L"my" } },
	{ { L"Nepali" }, { L"ne" } },
	{ { L"Norwegian" }, { L"no" } },
	{ { L"Odia (Oriya)" }, { L"or" } },
	{ { L"Pashto" }, { L"ps" } },
	{ { L"Persian" }, { L"fa" } },
	{ { L"Polish" }, { L"pl" } },
	{ { L"Portuguese" }, { L"pt" } },
	{ { L"Punjabi" }, { L"pa" } },
	{ { L"Romanian" }, { L"ro" } },
	{ { L"Russian" }, { L"ru" } },
	{ { L"Samoan" }, { L"sm" } },
	{ { L"Scots Gaelic" }, { L"gd" } },
	{ { L"Serbian" }, { L"sr" } },
	{ { L"Sesotho" }, { L"st" } },
	{ { L"Shona" }, { L"sn" } },
	{ { L"Sindhi" }, { L"sd" } },
	{ { L"Sinhala" }, { L"si" } },
	{ { L"Slovak" }, { L"sk" } },
	{ { L"Slovenian" }, { L"sl" } },
	{ { L"Somali" }, { L"so" } },
	{ { L"Spanish" }, { L"es" } },
	{ { L"Sundanese" }, { L"su" } },
	{ { L"Swahili" }, { L"sw" } },
	{ { L"Swedish" }, { L"sv" } },
	{ { L"Tajik" }, { L"tg" } },
	{ { L"Tamil" }, { L"ta" } },
	{ { L"Tatar" }, { L"tt" } },
	{ { L"Telugu" }, { L"te" } },
	{ { L"Thai" }, { L"th" } },
	{ { L"Turkish" }, { L"tr" } },
	{ { L"Turkmen" }, { L"tk" } },
	{ { L"Ukrainian" }, { L"uk" } },
	{ { L"Urdu" }, { L"ur" } },
	{ { L"Uyghur" }, { L"ug" } },
	{ { L"Uzbek" }, { L"uz" } },
	{ { L"Vietnamese" }, { L"vi" } },
	{ { L"Welsh" }, { L"cy" } },
	{ { L"Xhosa" }, { L"xh" } },
	{ { L"Yiddish" }, { L"yi" } },
	{ { L"Yoruba" }, { L"yo" } },
	{ { L"Zulu" }, { L"zu" } },
	{ { L"?" }, { L"auto" } }
};

bool translateSelectedOnly = false, useRateLimiter = true, rateLimitSelected = false, useCache = true, useFilter = true;
int tokenCount = 30, rateLimitTimespan = 60000, maxSentenceSize = 1000;

std::wstring ToRomaji(const std::wstring& text, TranslationParam tlp)
{
	try
	{
		if (HttpRequest httpRequest{
			L"Mozilla/5.0 Textractor",
			L"localhost",
			L"POST",
			L"/romanize",
			FormatString(R"({"text": "%s"})", JSON::Escape(WideStringToString(text))),
			L"Content-Type: application/json\r\nConnection: close",
			8080,
			NULL,
			WINHTTP_FLAG_ESCAPE_DISABLE,
		})
		{
			if (auto jsonResponse = JSON::Parse(httpRequest.response))
				if (auto translation = Copy(jsonResponse[L"romanized_text"].String()))
					return translation.value();
				else
					return FormatString(L"%s: %s", TRANSLATION_ERROR, httpRequest.response);
			else
				return L"[Romanization server error: Invalid response format]";
		}
		else
		{
			return L"[Romanization server unavailable]";
		}
	}
	catch (...)
	{
		return L"[Romanization error occurred]";
	}
}

bool IsJapanese(TranslationParam tlp)
{
	return tlp.translateFrom == L"Japanese";
}

std::pair<bool, std::wstring> Translate(const std::wstring& text, TranslationParam tlp)
{
	if (!tlp.authKey.empty())
	{
		std::wstring translateFromComponent = tlp.translateFrom == L"?" ? L"" : L"&source=" + codes.at(tlp.translateFrom);
		if (HttpRequest httpRequest{
			L"Mozilla/5.0 Textractor",
			L"translation.googleapis.com",
			L"POST",
			FormatString(L"/language/translate/v2?format=text&target=%s&key=%s%s", codes.at(tlp.translateTo), tlp.authKey, translateFromComponent).c_str(),
			FormatString(R"({"q":["%s"]})", JSON::Escape(WideStringToString(text)))
		})
		{
			std::wstring romanizedText;
			if (auto jsonResponse = JSON::Parse(httpRequest.response))
			{
				if (auto translation = Copy(JSON::Parse(httpRequest.response)[L"data"][L"translations"][0][L"translatedText"].String()))
				{
					if (IsJapanese(tlp))
						romanizedText = ToRomaji(text, tlp);
					else
						romanizedText = L"";
					
					std::wstring result = FormatString(L"%s\n%s", translation.value(), romanizedText);

					return { true, result };
				}
				else return { false, FormatString(L"%s: %s", TRANSLATION_ERROR, httpRequest.response) };
			}
			else return { false, FormatString(L"%s: %s", TRANSLATION_ERROR, httpRequest.errorCode) };

			// Original implementation commented out
			// if (auto translation = Copy(JSON::Parse(httpRequest.response)[L"data"][L"translations"][0][L"translatedText"].String())) return { true, translation.value() };
			// else return { false, FormatString(L"%s: %s", TRANSLATION_ERROR, httpRequest.response) };
		}
		else return { false, FormatString(L"%s (code=%u)", TRANSLATION_ERROR, httpRequest.errorCode) };
	}

	if (HttpRequest httpRequest{
		L"Mozilla/5.0 Textractor",
		L"translate.google.com",
		L"GET",
		FormatString(L"/m?sl=%s&tl=%s&q=%s", codes.at(tlp.translateFrom), codes.at(tlp.translateTo), Escape(text)).c_str()
	})
	{
		auto start = httpRequest.response.find(L"result-container\">"), end = httpRequest.response.find(L'<', start);
		// if (end != std::string::npos) return { true, HTML::Unescape(httpRequest.response.substr(start + 18, end - start - 18)) };
		// return { false, FormatString(L"%s: %s", TRANSLATION_ERROR, httpRequest.response) };

		if (end != std::string::npos)
		{
			std::wstring translation = HTML::Unescape(httpRequest.response.substr(start + 18, end - start - 18));
			if (IsJapanese(tlp))
				translation += L"\n" + ToRomaji(text, tlp);
			return { true, translation };
		}
		else return { false, FormatString(L"%s: %s", TRANSLATION_ERROR, httpRequest.response) };
	}
	else return { false, FormatString(L"%s (code=%u)", TRANSLATION_ERROR, httpRequest.errorCode) };
}
