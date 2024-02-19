# Preracunavac bodova za fiz dz

b = 10 + 6 + 5 + 8.80 + 7.40 + 10 + 7
#   ^---- Zbroj tvojih bodova ovdje
# Mozes utrpati u obliku x1 + x2 + x3 + ...

########## NE DIRATI ISPOD ##########
mb = 55
print("[Ako se dodaje 20%]")
if b >= mb / 1.2:
    print("   Bodovi: 10 / 10")
else:
    print("   Bodovi: " + str(round(b/mb * 1.2 * 10, 2)) + " / 10")
print("[Ako se NE dodaje 20%]")
print("   Bodovi: " + str(round(b/mb * 10, 2)) + " / 10")
