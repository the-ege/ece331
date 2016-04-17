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
	if ($ny>$year) {
		$x=$ny-$year;
		$d->sub(new DateInterval('P' . $x . 'Y'));
	} else {
		$x=$year-$ny;
		$d->add(new DateInterval('P' . $x . 'Y'));
	}
	$dom=$d->format('j');
	$month=$d->format('F');
	$year=$d->format('Y');
	$d->sub(new DateInterval('P' . $dom . 'D'));
	$wd=$d->format('w');
	$d->sub(new DateInterval('P' . $wd . 'D'));
	print "<TABLE Border=1>";
	print "<TR><TH COLSPAN=7>$month $year</TR>";
	print "<TR><TH>SUN<TH>MON<TH>TUE<TH>WED<TH>THU<TH>FRI<TH>SAT</TR>";
	for ($i=0;$i<7*5;$i++) {
		if ($i%7==0) {
			print "<TR>";
		}
		$cdom=$d->format('j');
		if ($dom==$cdom) {
			print "<TD ALIGN='CENTER' BGCOLOR='LightGreen'>$cdom";
		} else {
			print "<TD ALIGN='CENTER'>$cdom";
		}
		if ($i%7==6) {
			print "</TR>";
		}
		$d->add(new DateInterval('P1D'));
	}
	print "</TABLE>";
}
?>
