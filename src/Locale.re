[@bs.module "../../../public/strings/en.json"]
external en: array(Translation.t) = "default";
[@bs.module "../../../public/strings/ru.json"]
external ru: array(Translation.t) = "default";
[@bs.module "../../../public/strings/fr.json"]
external fr: array(Translation.t) = "default";

type t =
  | English
  | Russian
  | French;

let allLanguages = [|English, Russian, French|];

let toISOCode = t => {
  switch (t) {
  | English => "en"
  | Russian => "ru"
  | French => "fr"
  };
};

let isoCodeToLocale = t => {
  switch (t) {
  | "fr" => French
  | "ru" => Russian
  | "en"
  | _ => English
  };
};

let translations = t => {
  switch (t) {
  | English => en
  | Russian => ru
  | French => fr
  };
};

let toStringLanguage = t => {
  switch (t) {
  | English => "English"
  | Russian => "Russian"
  | French => "Fran\xe7ais"
  };
};

let currentLangFromUrl = url =>
  Js.String.split("/", url)->Belt.Array.sliceToEnd(1)[0]->isoCodeToLocale;
