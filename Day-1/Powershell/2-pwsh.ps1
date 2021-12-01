$v = Get-Content -Path 'Day-1\2-input.txt'

$count = [int]$v[0] + [int]$v[1] + [int]$v[2]
$n = 0

for ($i = 3; $i -lt $v.Count; $i++){
    if($count -lt $count + [int]$v[$i] - [int]$v[$i-3]){ $n++ }
    $count += ($v[$i] - $v[$i - 3])
}

Write-Host $n