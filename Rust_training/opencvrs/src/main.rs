extern crate opencv;
use opencv::{highgui, imgcodecs};

#[allow(dead_code)]
fn main() {
    let image = imgcodecs::imread("lena.jpg",imgcodecs::IMREAD_GRAYSCALE).unwrap();
    highgui::named_window("hello opencv!", 0).unwrap();
    highgui::imshow("hello opencv!", &image).unwrap();
    highgui::wait_key(10000).unwrap();

}
