<?php
error_reporting(E_ALL);
@ini_set('display_errors','on');
header('Content-Type: text/html; charset=utf-8');

$x=5; 						// eni
$y=5;						//uzunlugu
$t=@$_GET['t'];				//istiqamet
if($t==''){$t='N';}
$binalar='7343435436354285427459537';

//setri bolub massive yaziriq
$sira=0;
for($x1=1; $x1<=$x; $x1++){
	for($y1=1; $y1<=$y; $y1++){
		$bina[$x1][$y1]=substr($binalar,$sira,1);
		$sira++;
	}
}

//istiqamete uygun ceviririk
if($t=='S'){
	for($y2=0; $y2<$y; $y2++){
		$bina2[$y2+1]=$bina[$y-$y2];
	}
} elseif($t=='N'){
	$bina2=$bina;
} elseif($t=='W'){
	for($x2=0; $x2<$x; $x2++){
		for($y2=0; $y2<$y; $y2++){
			$bina2[$x2+1][$y2+1]=$bina[$y-$y2][$x2+1];
		}
	}
} elseif($t=='E'){
	for($x2=0; $x2<$x; $x2++){
		for($y2=0; $y2<$y; $y2++){
			$bina2[$x2+1][$y2+1]=$bina[$y2+1][$x-$x2];
		}
	}
}

function cek($bina,$x,$y){
	for($x3=1; $x3<=$x; $x3++){
		for($y3=1; $y3<=$y; $y3++){
			echo $bina[$x3][$y3];
		}
		echo '<br>';
	}
}
	$enyuksek=0;
	for($y3=1; $y3<=$y; $y3++){
		$yukseyi[$y3]=0;
		for($x3=1; $x3<=$x; $x3++){
			$hazirki=$bina2[$x3][$y3];
			if($hazirki>$enyuksek){
				$enyuksek=$hazirki;
			}
			if($hazirki>$yukseyi[$y3]){
				$yukseyi[$y3]=$hazirki;
				$netice[$y3][]=$hazirki;
			}
		}
	}
	//print_r($netice);
	echo '<table border=0>';
	for($x4=$enyuksek; $x4>0; $x4--){
		echo '<tr>';
		for($y4=1; $y4<=$y; $y4++){
			echo '<td>';
			if($x4>$yukseyi[$y4]){
				echo ' ';
			} elseif(in_array($x4, $netice[$y4])){
				echo '^';
			} else {
				echo '#';
			}
			echo '</td>';
		}
		echo '</tr>';
	}
	echo '</table>';
?>
<form action="?">
	T:<input type="text" size="2" name="t" value="<?php echo $t; ?>" /><br>
	<input type="submit" />
</form>
<?php
echo 'Verilen:<br>';
cek($bina,$x,$y);

echo '<br>alinan:<br>';
cek($bina2,$x,$y);
?>