#ifdef _TINSPIRE
#include <os.h>
#include <libndls.h>
#else
#include "SDL/SDL.h"
#endif
#include "FlagInformation.h"
#include "Replacements.h"

#ifndef _WIN32
#include "Images/af.h"
#include "Images/al.h"
#include "Images/dz.h"
#include "Images/ad.h"
#include "Images/ao.h"
#include "Images/ag.h"
#include "Images/ar.h"
#include "Images/am.h"
#include "Images/au.h"
#include "Images/at.h"
#include "Images/az.h"
#include "Images/bs.h"
#include "Images/bh.h"
#include "Images/bd.h"
#include "Images/bb.h"
#include "Images/by.h"
#include "Images/be.h"
#include "Images/bz.h"
#include "Images/bj.h"
#include "Images/bt.h"
#include "Images/bo.h"
#include "Images/ba.h"
#include "Images/bw.h"
#include "Images/br.h"
#include "Images/bn.h"
#include "Images/bg.h"
#include "Images/bf.h"
#include "Images/bi.h"
#include "Images/kh.h"
#include "Images/cm.h"
#include "Images/ca.h"
#include "Images/cv.h"
#include "Images/cf.h"
#include "Images/td.h"
#include "Images/cl.h"
#include "Images/co.h"
#include "Images/km.h"
//#include "Images/ck.h"
#include "Images/cr.h"
#include "Images/ci.h"
#include "Images/hr.h"
#include "Images/cu.h"
#include "Images/cy.h"
#include "Images/cz.h"
#include "Images/cd.h"
#include "Images/dk.h"
#include "Images/dj.h"
#include "Images/dm.h"
#include "Images/dr.h"
#include "Images/tl.h"
#include "Images/ec.h"
#include "Images/eg.h"
#include "Images/sv.h"
#include "Images/gq.h"
#include "Images/er.h"
#include "Images/ee.h"
#include "Images/et.h"
#include "Images/fj.h"
#include "Images/fi.h"
#include "Images/fr.h"
#include "Images/ga.h"
#include "Images/gm.h"
#include "Images/ge.h"
#include "Images/de.h"
#include "Images/gh.h"
#include "Images/gr.h"
#include "Images/gd.h"
#include "Images/gt.h"
#include "Images/gn.h"
#include "Images/gw.h"
#include "Images/gy.h"
#include "Images/ht.h"
#include "Images/hn.h"
#include "Images/hu.h"
#include "Images/is.h"
#include "Images/in.h"
#include "Images/id.h"
#include "Images/ir.h"
#include "Images/iq.h"
#include "Images/ie.h"
#include "Images/il.h"
#include "Images/it.h"
#include "Images/jm.h"
#include "Images/jp.h"
#include "Images/jo.h"
#include "Images/kz.h"
#include "Images/ke.h"
#include "Images/ki.h"
#include "Images/ks.h"
#include "Images/kw.h"
#include "Images/kg.h"
#include "Images/la.h"
#include "Images/lv.h"
#include "Images/lb.h"
#include "Images/ls.h"
#include "Images/lr.h"
#include "Images/ly.h"
#include "Images/li.h"
#include "Images/lt.h"
#include "Images/lu.h"
#include "Images/mk.h"
#include "Images/mg.h"
#include "Images/mw.h"
#include "Images/my.h"
#include "Images/mv.h"
#include "Images/ml.h"
#include "Images/mt.h"
#include "Images/mh.h"
#include "Images/mr.h"
#include "Images/mu.h"
#include "Images/mx.h"
#include "Images/fm.h"
#include "Images/md.h"
#include "Images/mc.h"
#include "Images/mn.h"
#include "Images/me.h"
#include "Images/ma.h"
#include "Images/mz.h"
#include "Images/mm.h"
#include "Images/na.h"
#include "Images/nr.h"
#include "Images/np.h"
#include "Images/nl.h"
#include "Images/nz.h"
#include "Images/ni.h"
#include "Images/ne.h"
#include "Images/ng.h"
//#include "Images/nu.h"
#include "Images/kp.h"
#include "Images/no.h"
#include "Images/om.h"
#include "Images/pk.h"
#include "Images/pw.h"
#include "Images/pa.h"
#include "Images/pg.h"
#include "Images/py.h"
#include "Images/cn.h"
#include "Images/pe.h"
#include "Images/ph.h"
#include "Images/pl.h"
#include "Images/pt.h"
#include "Images/qa.h"
#include "Images/tw.h"
#include "Images/cg.h"
#include "Images/ro.h"
#include "Images/ru.h"
#include "Images/rw.h"
#include "Images/kn.h"
#include "Images/lc.h"
#include "Images/vc.h"
#include "Images/ws.h"
#include "Images/sm.h"
#include "Images/st.h"
#include "Images/sa.h"
#include "Images/sn.h"
#include "Images/rs.h"
#include "Images/sc.h"
#include "Images/sl.h"
#include "Images/sg.h"
#include "Images/sk.h"
#include "Images/si.h"
#include "Images/sb.h"
#include "Images/so.h"
#include "Images/za.h"
#include "Images/kr.h"
//#include "Images/ss.h"
#include "Images/es.h"
#include "Images/lk.h"
#include "Images/sd.h"
#include "Images/sr.h"
#include "Images/sz.h"
#include "Images/se.h"
#include "Images/ch.h"
#include "Images/sy.h"
#include "Images/tj.h"
#include "Images/tz.h"
#include "Images/th.h"
#include "Images/tg.h"
#include "Images/to.h"
#include "Images/tt.h"
#include "Images/tn.h"
#include "Images/tr.h"
#include "Images/tm.h"
#include "Images/tv.h"
#include "Images/ug.h"
#include "Images/ua.h"
#include "Images/ae.h"
#include "Images/gb.h"
#include "Images/us.h"
#include "Images/uy.h"
#include "Images/uz.h"
#include "Images/vu.h"
#include "Images/va.h"
#include "Images/ve.h"
#include "Images/vn.h"
#include "Images/eh.h"
#include "Images/ye.h"
#include "Images/zm.h"
#include "Images/zw.h"
#endif

#ifndef _WIN32
#define C(e, n, cap, pop, km, img, path) { e, n, cap, km, pop, img, sizeof(img)}
#define P(s) "../../src/" s
#else
#define P(s) s
#define C(e, n, cap, pop, km, img, path) { e, n, cap, km, pop, path}
#endif

struct FlagInfo
{
   enum Flags eFlag;
   const char* pstrCountryName;
   const char* pstrCapital;
   int nSqKMs;
   int nPopulation;
#ifdef _WIN32
   const char* pstrImagePath;
#else
   unsigned char* pImg;
   int nImgSize;
#endif
} g_FlagInfo[] = {

        C( Afghanistan,"Afghanistan","Kabul",25500100,652090,af,P("Images/af.bmp") ),
        C( Albania,"Albania","Tirana",2821977,28748,al,P("Images/al.bmp") ),
        C( Algeria,"Algeria","Algiers",38700000,2381740,dz,P("Images/dz.bmp") ),
        C( Andorra,"Andorra","Andorra la Vella",76098,468,ad,P("Images/ad.bmp") ),
        C( Angola,"Angola","Luanda",20609294,1246700,ao,P("Images/ao.bmp") ),
        C( AntiguaandBarbuda,"Antigua and Barbuda","St. John's",86295,442,ag,P("Images/ag.bmp") ),
        C( Argentina,"Argentina","Buenos Aires",41660096,2780400,ar,P("Images/ar.bmp") ),
        C( Armenia,"Armenia","Yerevan",3017400,29800,am,P("Images/am.bmp") ),
        C( Australia,"Australia","Canberra",23414552,7741220,au,P("Images/au.bmp") ),
        C( Austria,"Austria","Vienna",8504850,83858,at,P("Images/at.bmp") ),
        C( Azerbaijan,"Azerbaijan","Baku",9477100,86600,az,P("Images/az.bmp") ),
        C( TheBahamas,"The Bahamas","Nassau",351461,13878,bs,P("Images/bs.bmp") ),
        C( Bahrain,"Bahrain","Manama",1234571,694,bh,P("Images/bh.bmp") ),
        C( Bangladesh,"Bangladesh","Dhaka",152518015,143998,bd,P("Images/bd.bmp") ),
        C( Barbados,"Barbados","Bridgetown",285000,430,bb,P("Images/bb.bmp") ),
        C( Belarus,"Belarus","Minsk",9468100,207600,by,P("Images/by.bmp") ),
        C( Belgium,"Belgium","Brussels",11132269,32545,be,P("Images/be.bmp") ),
        C( Belize,"Belize","Belmopan",349728,22966,bz,P("Images/bz.bmp") ),
        C( Benin,"Benin","Porto-Novo",10323000,112622,bj,P("Images/bj.bmp") ),
        C( Bhutan,"Bhutan","Thimphu",745200,47000,bt,P("Images/bt.bmp") ),
        C( Bolivia,"Bolivia","Sucre",10027254,1098580,bo,P("Images/bo.bmp") ),
        C( BosniaandHerzegovina,"Bosnia and Herzegovina","Sarajevo",3791622,51197,ba,P("Images/ba.bmp") ),
        C( Botswana,"Botswana","Gaborone",2024904,581730,bw,P("Images/bw.bmp") ),
        C( Brazil,"Brazil","Brasília",201032714,8514880,br,P("Images/br.bmp") ),
        C( Brunei,"Brunei","Bandar Seri Begawan",393162,5765,bn,P("Images/bn.bmp") ),
        C( Bulgaria,"Bulgaria","Sofia",7282041,110912,bg,P("Images/bg.bmp") ),
        C( BurkinaFaso,"Burkina Faso","Ouagadougou",17322796,274000,bf,P("Images/bf.bmp") ),
        C( Burundi,"Burundi","Bujumbura",10163000,27834,bi,P("Images/bi.bmp") ),
        C( Cambodia,"Cambodia","Phnom Penh",15135000,181035,kh,P("Images/kh.bmp") ),
        C( Cameroon,"Cameroon","Yaoundé",20386799,475442,cm,P("Images/cm.bmp") ),
        C( Canada,"Canada","Ottawa",35295770,9970610,ca,P("Images/ca.bmp") ),
        C( CapeVerde,"Cape Verde","Praia",491875,4033,cv,P("Images/cv.bmp") ),
        C( TheCentralAfricanRepublic,"The Central African Republic","Bangui",4616000,622984,cf,P("Images/cf.bmp") ),
        C( Chad,"Chad","N'Djamena",12825000,1284000,td,P("Images/td.bmp") ),
        C( Chile,"Chile","Santiago",16341929,756096,cl,P("Images/cl.bmp") ),
        C( Colombia,"Colombia","Bogotá",47506000,1138910,co,P("Images/co.bmp") ),
        C( TheComoros,"The Comoros","Moroni",743798,2235,km,P("Images/km.bmp") ),
        //C( CookIslands,"Cook Islands","Avarua",14974,240,ck,P("Images/ck.bmp") ),
        C( CostaRica,"Costa Rica","San José",4667096,51100,cr,P("Images/cr.bmp") ),
        C( CotedIvoire,"Cote d'Ivoire","Yamoussoukro",23202000,322463,ci,P("Images/ci.bmp") ),
        C( Croatia,"Croatia","Zagreb",4290612,56538,hr,P("Images/hr.bmp") ),
        C( Cuba,"Cuba","Havana",11167325,110861,cu,P("Images/cu.bmp") ),
        C( Cyprus,"Cyprus","Nicosia",865878,9251,cy,P("Images/cy.bmp") ),
        C( TheCzechRepublic,"The Czech Republic","Prague",10513800,78866,cz,P("Images/cz.bmp") ),
        C( TheDemocraticRepublicoftheCongo,"The Democratic Republic of the Congo","Kinshasa",67514000,2344860,cd,P("Images/cd.bmp") ),
        C( Denmark,"Denmark","Copenhagen",5627235,43094,dk,P("Images/dk.bmp") ),
        C( Djibouti,"Djibouti","Djibouti",873000,23200,dj,P("Images/dj.bmp") ),
        C( Dominica,"Dominica","Roseau",71293,751,dm,P("Images/dm.bmp") ),
        C( TheDominicanRepublic,"The Dominican Republic","Santo Domingo",9445281,48671,dr,P("Images/dr.bmp") ),
        C( EastTimor,"East Timor","Dili",1066409,14874,tl,P("Images/tl.bmp") ),
        C( Ecuador,"Ecuador","Quito",15699200,283561,ec,P("Images/ec.bmp") ),
        C( Egypt,"Egypt","Cairo",86127000,980869,eg,P("Images/eg.bmp") ),
        C( ElSalvador,"El Salvador","San Salvador",6340000,21041,sv,P("Images/sv.bmp") ),
        C( EquatorialGuinea,"Equatorial Guinea","Malabo",736296,28051,gq,P("Images/gq.bmp") ),
        C( Eritrea,"Eritrea","Asmara",6333000,117600,er,P("Images/er.bmp") ),
        C( Estonia,"Estonia","Tallinn",1311870,45100,ee,P("Images/ee.bmp") ),
        C( Ethiopia,"Ethiopia","Addis Ababa",86613986,1104300,et,P("Images/et.bmp") ),
        C( Fiji,"Fiji","Suva",858038,18274,fj,P("Images/fj.bmp") ),
        C( Finland,"Finland","Helsinki",5452821,338145,fi,P("Images/fi.bmp") ),
        C( France,"France","Paris",65844000,551500,fr,P("Images/fr.bmp") ),
        C( Gabon,"Gabon","Libreville",1672000,267668,ga,P("Images/ga.bmp") ),
        C( TheGambia,"The Gambia","Banjul",1849000,11295,gm,P("Images/gm.bmp") ),
        C( Georgia,"Georgia","Tbilisi",4483800,69700,ge,P("Images/ge.bmp") ),
        C( Germany,"Germany","Berlin",80619000,357022,de,P("Images/de.bmp") ),
        C( Ghana,"Ghana","Accra",24658823,238533,gh,P("Images/gh.bmp") ),
        C( Greece,"Greece","Athens",10815197,131957,gr,P("Images/gr.bmp") ),
        C( Grenada,"Grenada","St. George's",103328,344,gd,P("Images/gd.bmp") ),
        C( Guatemala,"Guatemala","Guatemala City",15806675,108889,gt,P("Images/gt.bmp") ),
        C( Guinea,"Guinea","Conakry",10824200,245857,gn,P("Images/gn.bmp") ),
        C( GuineaBissau,"Guinea-Bissau","Bissau",1704000,36125,gw,P("Images/gw.bmp") ),
        C( Guyana,"Guyana","Georgetown",784894,214969,gy,P("Images/gy.bmp") ),
        C( Haiti,"Haiti","Port-au-Prince",10413211,27750,ht,P("Images/ht.bmp") ),
        C( Honduras,"Honduras","Tegucigalpa",8555072,112088,hn,P("Images/hn.bmp") ),
        C( Hungary,"Hungary","Budapest",9906000,93032,hu,P("Images/hu.bmp") ),
        C( Iceland,"Iceland","Reykjavík",325671,103000,is,P("Images/is.bmp") ),
        C( India,"India","New Delhi",1241610000,3287260,in,P("Images/in.bmp") ),
        C( Indonesia,"Indonesia","Jakarta",249866000,1904570,id,P("Images/id.bmp") ),
        C( Iran,"Iran","Tehran",77288000,1648200,ir,P("Images/ir.bmp") ),
        C( Iraq,"Iraq","Baghdad",34035000,438317,iq,P("Images/iq.bmp") ),
        C( Ireland,"Ireland","Dublin",4593100,70273,ie,P("Images/ie.bmp") ),
        C( Israel,"Israel","Jerusalem",8146300,22145,il,P("Images/il.bmp") ),
        C( Italy,"Italy","Rome",59943933,301318,it,P("Images/it.bmp") ),
        C( Jamaica,"Jamaica","Kingston",2711476,10991,jm,P("Images/jm.bmp") ),
        C( Japan,"Japan","Tokyo",127180000,377873,jp,P("Images/jp.bmp") ),
        C( Jordan,"Jordan","Amman",6558900,89342,jo,P("Images/jo.bmp") ),
        C( Kazakhstan,"Kazakhstan","Astana",17186000,2724900,kz,P("Images/kz.bmp") ),
        C( Kenya,"Kenya","Nairobi",44354000,580367,ke,P("Images/ke.bmp") ),
        C( Kiribati,"Kiribati","South Tarawa",106461,726,ki,P("Images/ki.bmp") ),
        C( Kosovo,"Kosovo","Pristina",1815606,10887,ks,P("Images/ks.bmp") ),
        C( Kuwait,"Kuwait","Kuwait City",3065850,17818,kw,P("Images/kw.bmp") ),
        C( Kyrgyzstan,"Kyrgyzstan","Bishkek",5663133,199900,kg,P("Images/kg.bmp") ),
        C( Laos,"Laos","Vientiane",6580800,236800,la,P("Images/la.bmp") ),
        C( Latvia,"Latvia","Riga",2003900,64600,lv,P("Images/lv.bmp") ),
        C( Lebanon,"Lebanon","Beirut",4822000,10400,lb,P("Images/lb.bmp") ),
        C( Lesotho,"Lesotho","Maseru",2074000,30355,ls,P("Images/ls.bmp") ),
        C( Liberia,"Liberia","Monrovia",4294000,111369,lr,P("Images/lr.bmp") ),
        C( Libya,"Libya","Tripoli",6202000,1759540,ly,P("Images/ly.bmp") ),
        C( Liechtenstein,"Liechtenstein","Vaduz",37132,160,li,P("Images/li.bmp") ),
        C( Lithuania,"Lithuania","Vilnius",2941953,65300,lt,P("Images/lt.bmp") ),
        C( Luxembourg,"Luxembourg","Luxembourg City",537000,2586,lu,P("Images/lu.bmp") ),
        C( Macedonia,"Macedonia","Skopje",2062294,25713,mk,P("Images/mk.bmp") ),
        C( Madagascar,"Madagascar","Antananarivo",21263403,587041,mg,P("Images/mg.bmp") ),
        C( Malawi,"Malawi","Lilongwe",16363000,118484,mw,P("Images/mw.bmp") ),
        C( Malaysia,"Malaysia","Kuala Lumpur",30041000,329847,my,P("Images/my.bmp") ),
        C( Maldives,"Maldives","Malé",317280,298,mv,P("Images/mv.bmp") ),
        C( Mali,"Mali","Bamako",15302000,1240190,ml,P("Images/ml.bmp") ),
        C( Malta,"Malta","Valletta",416055,316,mt,P("Images/mt.bmp") ),
        C( TheMarshallIslands,"The Marshall Islands","Majuro",56086,181,mh,P("Images/mh.bmp") ),
        C( Mauritania,"Mauritania","Nouakchott",3461041,1025520,mr,P("Images/mr.bmp") ),
        C( Mauritius,"Mauritius","Port Louis",1257900,2040,mu,P("Images/mu.bmp") ),
        C( Mexico,"Mexico","Mexico City",119713203,1958200,mx,P("Images/mx.bmp") ),
        C( Micronesia,"Micronesia","Palikir",101351,702,fm,P("Images/fm.bmp") ),
        C( Moldova,"Moldova","Chisinau",3559500,33851,md,P("Images/md.bmp") ),
        C( Monaco,"Monaco","Monaco",36136,2,mc,P("Images/mc.bmp") ),
        C( Mongolia,"Mongolia","Ulaanbaatar",2931300,1564120,mn,P("Images/mn.bmp") ),
        C( Montenegro,"Montenegro","Podgorica",620029,13812,me,P("Images/me.bmp") ),
        C( Morocco,"Morocco","Rabat",33202300,446550,ma,P("Images/ma.bmp") ),
        C( Mozambique,"Mozambique","Maputo",23700715,801590,mz,P("Images/mz.bmp") ),
        C( Myanmar,"Myanmar","Naypyidaw",53259000,676578,mm,P("Images/mm.bmp") ),
        C( Namibia,"Namibia","Windhoek",2113077,824292,na,P("Images/na.bmp") ),
        C( Nauru,"Nauru","Yaren District",9945,21,nr,P("Images/nr.bmp") ),
        C( Nepal,"Nepal","Kathmandu",26494504,147181,np,P("Images/np.bmp") ),
        C( TheNetherlands,"The Netherlands","Amsterdam",16842200,41528,nl,P("Images/nl.bmp") ),
        C( NewZealand,"New Zealand","Wellington",4518330,270534,nz,P("Images/nz.bmp") ),
        C( Nicaragua,"Nicaragua","Managua",6071045,130000,ni,P("Images/ni.bmp") ),
        C( Niger,"Niger","Niamey",17129076,1267000,ne,P("Images/ne.bmp") ),
        C( Nigeria,"Nigeria","Abuja",173615000,923768,ng,P("Images/ng.bmp") ),
        //C( Niue,"Niue","Alofi",1611,260,nu,P("Images/nu.bmp") ),
        C( NorthKorea,"North Korea","Pyongyang",24895000,120538,kp,P("Images/kp.bmp") ),
        C( Norway,"Norway","Oslo",5109056,385155,no,P("Images/no.bmp") ),
        C( Oman,"Oman","Muscat",3957000,309500,om,P("Images/om.bmp") ),
        C( Pakistan,"Pakistan","Islamabad",185914000,796095,pk,P("Images/pk.bmp") ),
        C( Palau,"Palau","Ngerulmud",20901,459,pw,P("Images/pw.bmp") ),
        C( Panama,"Panama","Panama City",3405813,75517,pa,P("Images/pa.bmp") ),
        C( PapuaNewGuinea,"Papua New Guinea","Port Moresby",7398500,462840,pg,P("Images/pg.bmp") ),
        C( Paraguay,"Paraguay","Asunción",6783374,406752,py,P("Images/py.bmp") ),
        C( ThePeoplesRepublicofChina,"The People's Republic of China","Beijing",1363350000,9640820,cn,P("Images/cn.bmp") ),
        C( Peru,"Peru","Lima",30475144,1285220,pe,P("Images/pe.bmp") ),
        C( ThePhilippines,"The Philippines","Manila",99275100,300000,ph,P("Images/ph.bmp") ),
        C( Poland,"Poland","Warsaw",38502396,312685,pl,P("Images/pl.bmp") ),
        C( Portugal,"Portugal","Lisbon",10487289,91982,pt,P("Images/pt.bmp") ),
        C( Qatar,"Qatar","Doha",2045239,11000,qa,P("Images/qa.bmp") ),
        C( TheRepublicofChina,"The Republic of China","Taipei",23379129,36188,tw,P("Images/tw.bmp") ),
        C( TheRepublicoftheCongo,"The Republic of the Congo","Brazzaville",4448000,342000,cg,P("Images/cg.bmp") ),
        C( Romania,"Romania","Bucharest",20121641,238391,ro,P("Images/ro.bmp") ),
        C( Russia,"Russia","Moscow",143700000,17098200,ru,P("Images/ru.bmp") ),
        C( Rwanda,"Rwanda","Kigali",10537222,26338,rw,P("Images/rw.bmp") ),
        C( SaintKittsandNevis,"Saint Kitts and Nevis","Basseterre",54000,261,kn,P("Images/kn.bmp") ),
        C( SaintLucia,"Saint Lucia","Castries",180000,539,lc,P("Images/lc.bmp") ),
        C( SaintVincentandtheGrenadines,"Saint Vincent and the Grenadines","Kingstown",109000,388,vc,P("Images/vc.bmp") ),
        C( Samoa,"Samoa","Apia",187820,2831,ws,P("Images/ws.bmp") ),
        C( SanMarino,"San Marino","San Marino",33540,61,sm,P("Images/sm.bmp") ),
        C( SaoTomeandPrincipe,"Sao Tome and Principe","São Tomé",187356,964,st,P("Images/st.bmp") ),
        C( SaudiArabia,"Saudi Arabia","Riyadh",29994272,2149690,sa,P("Images/sa.bmp") ),
        C( Senegal,"Senegal","Dakar",13567338,196722,sn,P("Images/sn.bmp") ),
        C( Serbia,"Serbia","Belgrade",7181505,77474,rs,P("Images/rs.bmp") ),
        C( TheSeychelles,"The Seychelles","Victoria",90945,455,sc,P("Images/sc.bmp") ),
        C( SierraLeone,"Sierra Leone","Freetown",6190280,71740,sl,P("Images/sl.bmp") ),
        C( Singapore,"Singapore","Singapore",5399200,683,sg,P("Images/sg.bmp") ),
        C( Slovakia,"Slovakia","Bratislava",5415949,49033,sk,P("Images/sk.bmp") ),
        C( Slovenia,"Slovenia","Ljubljana",2061963,20256,si,P("Images/si.bmp") ),
        C( TheSolomonIslands,"The Solomon Islands","Honiara",581344,28896,sb,P("Images/sb.bmp") ),
        C( Somalia,"Somalia","Mogadishu",10496000,637657,so,P("Images/so.bmp") ),
        C( SouthAfrica,"South Africa","Pretoria",52981991,1221040,za,P("Images/za.bmp") ),
        C( SouthKorea,"South Korea","Seoul",50219669,99538,kr,P("Images/kr.bmp") ),
        //C( SouthSudan,"South Sudan","Juba",10625176,644329,ss,P("Images/ss.bmp") ),
        C( Spain,"Spain","Madrid",46609700,505992,es,P("Images/es.bmp") ),
        C( SriLanka,"Sri Lanka","Colombo",20277597,65610,lk,P("Images/lk.bmp") ),
        C( Sudan,"Sudan","Khartoum",37964000,2505810,sd,P("Images/sd.bmp") ),
        C( Suriname,"Suriname","Paramaribo",534189,163820,sr,P("Images/sr.bmp") ),
        C( Swaziland,"Swaziland","Mbabane",1250000,17364,sz,P("Images/sz.bmp") ),
        C( Sweden,"Sweden","Stockholm",9651531,449964,se,P("Images/se.bmp") ),
        C( Switzerland,"Switzerland","Bern",8112200,41284,ch,P("Images/ch.bmp") ),
        C( Syria,"Syria","Damascus",21898000,185180,sy,P("Images/sy.bmp") ),
        C( Tajikistan,"Tajikistan","Dushanbe",8160000,143100,tj,P("Images/tj.bmp") ),
        C( Tanzania,"Tanzania","Dodoma",44928923,945087,tz,P("Images/tz.bmp") ),
        C( Thailand,"Thailand","Bangkok",65926261,513115,th,P("Images/th.bmp") ),
        C( Togo,"Togo","Lomé",6191155,56785,tg,P("Images/tg.bmp") ),
        C( Tonga,"Tonga","Nuku'alofa",103036,747,to,P("Images/to.bmp") ),
        C( TrinidadandTobago,"Trinidad and Tobago","Port of Spain",1328019,5130,tt,P("Images/tt.bmp") ),
        C( Tunisia,"Tunisia","Tunis",10886500,163610,tn,P("Images/tn.bmp") ),
        C( Turkey,"Turkey","Ankara",76667864,783562,tr,P("Images/tr.bmp") ),
        C( Turkmenistan,"Turkmenistan","Ashgabat",5240000,488100,tm,P("Images/tm.bmp") ),
        C( Tuvalu,"Tuvalu","Funafuti",11323,26,tv,P("Images/tv.bmp") ),
        C( Uganda,"Uganda","Kampala",35357000,241038,ug,P("Images/ug.bmp") ),
        C( Ukraine,"Ukraine","Kiev (Kyiv)",45426200,603700,ua,P("Images/ua.bmp") ),
        C( TheUnitedArabEmirates,"The United Arab Emirates","Abu Dhabi",8264070,83600,ae,P("Images/ae.bmp") ),
        C( TheUnitedKingdom,"The United Kingdom","London",63705000,242900,gb,P("Images/gb.bmp") ),
        C( TheUnitedStates,"The United States","Washington, District of Columbia",317706000,9629090,us,P("Images/us.bmp") ),
        C( Uruguay,"Uruguay","Montevideo",3286314,175016,uy,P("Images/uy.bmp") ),
        C( Uzbekistan,"Uzbekistan","Tashkent",30183400,447400,uz,P("Images/uz.bmp") ),
        C( Vanuatu,"Vanuatu","Port Vila",264652,12189,vu,P("Images/vu.bmp") ),
        C( TheVaticanCity,"The Vatican City","Vatican City",839,0.44,va,P("Images/va.bmp") ),
        C( Venezuela,"Venezuela","Caracas",28946101,912050,ve,P("Images/ve.bmp") ),
        C( Vietnam,"Vietnam","Hanoi",89708900,331689,vn,P("Images/vn.bmp") ),
        C( WesternSahara,"Western Sahara","Laayoune",567000,266000,eh,P("Images/eh.bmp") ),
        C( Yemen,"Yemen","Sanaá",25235000,527968,ye,P("Images/ye.bmp") ),
        C( Zambia,"Zambia","Lusaka",14580290,752618,zm,P("Images/zm.bmp") ),
        C( Zimbabwe,"Zimbabwe","Harare",12973808,390757,zw,P("Images/zw.bmp") )
};

#undef C
#undef P

void CreateFlagInformation(struct FlagInformation** ppFlagInformation)
{
   *ppFlagInformation = malloc(sizeof(struct FlagInformation));
   struct FlagInformation* pFlagInformation = (*ppFlagInformation);

   //Initialize stuff here
   UNUSED(pFlagInformation);
}

void FreeFlagInformation(struct FlagInformation** ppFlagInformation)
{
   struct FlagInformation* pFlagInformation = (*ppFlagInformation);
   UNUSED(pFlagInformation);

   free(*ppFlagInformation);
   *ppFlagInformation = NULL;
}

int GetNumberOfFlags(struct FlagInformation* pFlagInformation)
{
   UNUSED(pFlagInformation);
   return (int)( sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0]) );
}

const char* GetCountryName(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   UNUSED(pFlagInformation);
   for (int i = 0; i < (int)(sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0])); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].pstrCountryName;
   return "";
}

const char* GetCapital(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   UNUSED(pFlagInformation);
   for (int i = 0; i < (int)(sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0])); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].pstrCapital;
   return "";
}

int GetCountryAreaSqKM(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   UNUSED(pFlagInformation);
   for (int i = 0; i < (int)(sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0])); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].nSqKMs;
   return -1;
}

int GetCountryPopulation(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   UNUSED(pFlagInformation);
   for (int i = 0; i < (int)(sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0])); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].nPopulation;
   return -1;
}

#ifdef _WIN32
const char* GetPathForFlag(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   (pFlagInformation);
   for (int i = 0; i < sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0]); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].pstrImagePath;
   return "";
}
#else
unsigned char* GetImgDataForFlag(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   UNUSED(pFlagInformation);
   for (int i = 0; i < (int)(sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0])); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].pImg;
   return NULL;
}

int GetImgDataSizeForFlag(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   UNUSED(pFlagInformation);
   for (int i = 0; i < (int)(sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0])); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].nImgSize;
   return -1;
}
#endif
