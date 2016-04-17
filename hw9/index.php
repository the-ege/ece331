<HTML>
<BODY>
<FORM action='index.php' method='post'>
Year: <input type='text' name='year'>
<input type='submit'>
</FORM>

<?php
if (array_key_exists("year",$_POST)) {
	mkcal($_POST['year']);
}

function mkcal($year) {
	$d=new DateTime('now');
	$ny=$d->format('Y');
	
	#Get start of year
	$k=new DateTime('first day of January' . date('Y'));
	$sdom=$k->format('j'); #starting dom
	$smonth=$d->format('F'); #text of starting month
	
	if ($ny>$year) {
		$x=$ny-$year;
		$d->sub(new DateInterval('P' . $x . 'Y'));
	} else {
		$x=$year-$ny;
		$d->add(new DateInterval('P' . $x . 'Y'));
	}
	for ($i=0;$i<12;$i++) {
		$dom=$k->format('j'); #dom w/o leading zeros
		$month=$k->format('F'); #text of month
		$year=$k->format('Y'); #4 digit year
		$k->sub(new DateInterval('P' . $dom . 'D'));
		$wd=$k->format('w'); #gets weekday?
		$k->sub(new DateInterval('P' . $wd . 'D'));
		print "<TABLE Border=1>";
		print "<TR><TH COLSPAN=7>$month $year</TR>";
		print "<TR><TH>SUN<TH>MON<TH>TUE<TH>WED<TH>THU<TH>FRI<TH>SAT</TR>";
		for ($j=0;$j<7*5;$j++) {
			if ($j%7==0) {
				print "<TR>";
			}
			$cdom=$k->format('j');
			$checkdom=$d->format('j');
			if ($dom==$checkdom) {
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
		if ($cdom>1) {
			$k->modify('first day of next month');
		}
		print "</TABLE>";
	}
}
?>
