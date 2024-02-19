import time
from selenium import webdriver

driver = webdriver.Edge(
    executable_path=r'C:\edgedriver_win64\msedgedriver.exe')
driver.get('https://www.riddler.nissan.hr/')


playButton = driver.find_element_by_xpath('//*[@id="riddler__button-start"]')
playButton.click()

pitanje = driver.find_element_by_xpath('//*[@id="riddler__input"]')
pitanje.send_keys('batmobile')
dalje = driver.find_element_by_xpath('//*[@id="riddler__form"]/button')
dalje.click()

pitanje.send_keys('catwoman')
dalje.click()

pitanje.send_keys('batman')
dalje.click()
