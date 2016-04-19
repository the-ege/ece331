<HTML>
<BODY>
<FORM action='index.php' method='post'>
Year: <input type='text' name='year'>
<input type='submit'>
</FORM>

<?php
if (!array_key_exists("year",$_POST)) {
	mkcal(2016);
} else {
	mkcal($_POST['year']);
}

function mkcal($year) {
	#Get current date
	$today=new DateTime('now');
	$curday=$today->format('j');
	$curmon=$today->format('F');
	$curyear=$today->format('Y');
	
	#Get start of year
	$k=new DateTime();
	$k->setDate($year,1,1);
	
	print "<TABLE Border=3 CELLPADDING=10 CELLSPACING=3><TD>";
	
	for ($i=1;$i<13;$i++) {
		$dom=$k->format('j'); #dom w/o leading zeros
		$month=$k->format('F'); #text of month
		$year=$k->format('Y'); #4 digit year
		$k->sub(new DateInterval('P' . $dom . 'D'));
		$wd=$k->format('w'); #gets weekday
		$k->sub(new DateInterval('P' . $wd . 'D'));
		
		print "<TABLE Border=1>";
		print "<TR><TH COLSPAN=7>$month $year</TR>";
		print "<TR><TH>SUN<TH>MON<TH>TUE<TH>WED<TH>THU<TH>FRI<TH>SAT</TR>";
		for ($j=0;$j<7*6;$j++) {
			$cdom=$k->format('j');
			if ($j%7==0) {
				print "<TR>";
			}
			if (($cdom==$curday) && ($month==$curmon) && ($year==$curyear)) {
				print "<TD ALIGN='CENTER' BGCOLOR='LightGreen'>$cdom";
			} else if ($j<7 && $cdom>7) { #make bg for previous month days, no bg if month starts on Sun
				print "<TD ALIGN='CENTER' BGCOLOR='Gray'>$cdom";
			} else if ($j>28 && $cdom<22) { #make bg for next month days
				print "<TD ALIGN='CENTER' BGCOLOR='Gray'>$cdom";
			} else {
				print "<TD ALIGN='CENTER'>$cdom";
			}
			if ($j%7==6) {
				print "</TR>";
			}
			$k->add(new DateInterval('P1D'));
		}
			
		print "</TABLE>";

		if ($i%3 == 0) { #make rows of three columns apiece
			print "</TD></TR><TR>";
		}
		if ($i != 12) {
			print "<TD>";
		}

		$k->setDate($year,$i+1,1);
	}
	print "</TABLE>";
}
?>
