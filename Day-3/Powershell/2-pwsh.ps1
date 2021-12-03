$v = Get-Content -Path 'Day-3\input.txt'

$f = ''
$b = ''

for($c = 0; $c -lt $v[0].length; $c++){
    $num_0 = 0
    $num_1 = 0
    for($w = 0; $w -lt $v.length; $w++){
        if($v[$w][$c] -eq '0'){ $num_0++ }
        else{ $num_1++ }
    }

    if($num_0 -lt $num_1){
        $f += '1'
        $b += '0'
    }
    else{
        $f += '0'
        $b += '1'
    }
}

Write-Host $([Convert]::ToInt32($f,2) * [Convert]::ToInt32($b,2))