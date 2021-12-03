$v = Get-Content -Path 'Day-1\input.txt'

$count = [int]$v[0]
$n = 0

foreach ($num in $v){
    if([int]$count -lt [int]$num){ $n++ }
    $count = [int]$num
}

Write-Host $n