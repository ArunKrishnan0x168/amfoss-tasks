fn main()
{
    //Setting the url
    let url = "https://crypto.com/price";
    //getting the html content
    let http_response = reqwest::blocking::get(url).expect("Can't load the url");
    //converting the html body to a text format
    let html_body  = http_response.text().unwrap();
    //parsing html_body
    let document = scraper::Html::parse_document(&html_body);
    //getting titile element
    let crypto_title = scraper::Selector::parse("div.css-ttxvk0>p").unwrap();
    //gettitng price element
    let crypto_price = scraper::Selector::parse(".css-b1ilzc").unwrap();
    //getting 24h change element
    let crypto_24h_change = scraper::Selector::parse("td.css-1b7j986>p").unwrap();
    //getting 24h volume
    let crypto_24h_volume = scraper::Selector::parse(".css-1nh9lk8").unwrap();
    //gettting market cap
    let crypto_market_cap = scraper::Selector::parse(".css-1nh9lk8").unwrap();
    //instantiating writer
    let mut wrt = csv::Writer::from_path("crypto_info.csv").expect("Can't create file");
    //writing the columns
    wrt.write_record(&["NAME","PRICE","24H CHANGE","24H VOLUME","MARKET CAP"]).unwrap();
    //mapping innerhtml content to an iterator
    let crypto_main_name = document.select(&crypto_title).map(|x| x.inner_html());
    //mapping innerhtml content to an iterator
    let crypto_main_price = document.select(&crypto_price).map(|x| x.inner_html());
    //mapping innerhtml content to an iterator
    let crypto_main_24h_change = document.select(&crypto_24h_change).map(|x| x.inner_html());
    //mapping innerhtml content to an iterator
    let crypto_main_24h_volume = document.select(&crypto_24h_volume).map(|x| x.inner_html());
    //mapping innerhtml content to an iterator
    let crypto_main_market_cap = document.select(&crypto_market_cap).map(|x| x.inner_html());

    //Writing the iterators to a csv file
    wrt.write_record(crypto_main_name);

    wrt.write_record(crypto_main_price);
   
    wrt.write_record(crypto_main_24h_change);

    wrt.write_record(crypto_main_24h_volume);

    wrt.write_record(crypto_main_market_cap);

    //END
}