def asteroid():
    # Masa je gustoca * volumen
    # volumen je 4/3 * r^3 * pi
    
    
    pi=3.14159265358980 # NE DIRAJ!!!
    gustoca=3 # g/cm^3, mijenjaj po potrebi
    promjer= 1300 # m, mijenjaj po potrebi
    brzina=26.0 # km/s, mijenjaj po potrebi
    
    prava_brzina=brzina*1000 # m/s
    polumjer=promjer/2 # m
    prava_gustoca=gustoca*1000 # kg/m^3
    
    volumen=4/3 * polumjer**3 * pi
    
    
    masa=prava_gustoca*volumen
    energija=1/2*masa*(prava_brzina*prava_brzina)
    rezultat=energija/(4.184*(10**15)) # u megatone TNT-a
    print(rezultat)


asteroid()