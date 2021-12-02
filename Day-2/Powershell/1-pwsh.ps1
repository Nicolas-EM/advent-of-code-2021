$v = Get-Content -Path 'Day-2\1-input.txt'

$x = 0
$y = 0

foreach($c in $v){
    [int]$num = [convert]::ToInt32(($c[$c.Length-1]), 10)
    switch($c[0]){
        "f" { $x += $num }
        "d" { $y += $num }
        "u" { $y -= $num }
    }
}

Write-Host $($x * $y)
